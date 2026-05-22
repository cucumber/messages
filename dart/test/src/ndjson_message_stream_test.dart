import 'dart:convert';

import 'package:cucumber_messages/cucumber_messages.dart';
import 'package:test/test.dart';

void main() {
  group('parseEnvelope and envelopeToJson', () {
    test('round-trips a single envelope', () {
      const envelope = Envelope(
        attachment: Attachment(body: 'Hello', mediaType: 'text/plain'),
      );

      final jsonLine = envelopeToJson(envelope);
      final decoded = parseEnvelope(jsonLine);

      expect(decoded.attachment?.body, 'Hello');
      expect(decoded.attachment?.mediaType, 'text/plain');
    });

    test('throws helpful error for invalid JSON', () {
      expect(
        () => parseEnvelope('{"attachment":'),
        throwsA(
          isA<FormatException>().having(
            (error) => error.message,
            'message',
            contains('Failed to parse Envelope'),
          ),
        ),
      );
    });

    test('throws helpful error for non-object JSON', () {
      expect(
        () => parseEnvelope('[1,2,3]'),
        throwsA(
          isA<FormatException>().having(
            (error) => error.message,
            'message',
            contains('Expected a JSON object for Envelope'),
          ),
        ),
      );
    });
  });

  group('readNdjsonLines', () {
    test('parses every non-empty line', () async {
      final lines = <String>[
        envelopeToJson(
          const Envelope(attachment: Attachment(body: 'A', mediaType: 'a/b')),
        ),
        '',
        '   ',
        envelopeToJson(
          const Envelope(attachment: Attachment(body: 'B', mediaType: 'c/d')),
        ),
      ];

      final values =
          await readNdjsonLines(Stream<String>.fromIterable(lines)).toList();

      expect(values.length, 2);
      expect(values.first.attachment?.body, 'A');
      expect(values.last.attachment?.body, 'B');
    });

    test('includes line number when stream line fails parsing', () async {
      final lines = <String>[
        envelopeToJson(
          const Envelope(attachment: Attachment(body: 'A', mediaType: 'a/b')),
        ),
        '{"attachment":',
      ];

      await expectLater(
        readNdjsonLines(Stream<String>.fromIterable(lines)).drain<void>(),
        throwsA(
          isA<FormatException>().having(
            (error) => error.message,
            'message',
            contains('line 2'),
          ),
        ),
      );
    });

    test(
      'propagates malformed UTF-8 decode errors from input stream',
      () async {
        final malformedBytes = Stream<List<int>>.fromIterable([
          <int>[0xc3, 0x28, 0x0a],
        ]);
        final lines = malformedBytes
            .transform(utf8.decoder)
            .transform(const LineSplitter());

        await expectLater(
          readNdjsonLines(lines).drain<void>(),
          throwsA(isA<FormatException>()),
        );
      },
    );
  });

  group('writeNdjsonLines', () {
    test('adds exactly one trailing newline to each envelope', () async {
      final envelopes = Stream<Envelope>.fromIterable([
        const Envelope(attachment: Attachment(body: 'X', mediaType: 'x/y')),
        const Envelope(attachment: Attachment(body: 'Y', mediaType: 'y/z')),
      ]);

      final output = await writeNdjsonLines(envelopes).toList();

      expect(output.length, 2);
      expect(output[0].endsWith('\n'), isTrue);
      expect(output[1].endsWith('\n'), isTrue);
      expect(
        output[0].substring(0, output[0].length - 1).endsWith('\n'),
        isFalse,
      );
    });
  });
}
