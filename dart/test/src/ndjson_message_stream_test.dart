import 'dart:convert';

import 'package:cucumber_messages/cucumber_messages.dart';
import 'package:test/test.dart';

void main() {
  group('parseEnvelopeJson and envelopeToJsonString', () {
    test('round-trips a single envelope', () {
      const envelope = Envelope(
        attachment: Attachment(body: 'Hello', mediaType: 'text/plain'),
      );

      final jsonLine = envelopeToJsonString(envelope);
      final decoded = parseEnvelopeJson(jsonLine);

      expect(decoded.attachment?.body, 'Hello');
      expect(decoded.attachment?.mediaType, 'text/plain');
    });

    test('throws helpful error for invalid JSON', () {
      expect(
        () => parseEnvelopeJson('{"attachment":'),
        throwsA(
          isA<FormatException>().having(
            (error) => error.message,
            'message',
            contains('Failed to parse Envelope'),
          ),
        ),
      );
    });

    test('can omit line content from parse errors', () {
      expect(
        () => parseEnvelopeJson('{"attachment":', includeLineInErrors: false),
        throwsA(
          isA<FormatException>().having(
            (error) => error.message,
            'message',
            isNot(contains('Line content:')),
          ),
        ),
      );
    });

    test('throws helpful error for non-object JSON', () {
      expect(
        () => parseEnvelopeJson('[1,2,3]'),
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

  group('decodeNdjsonEnvelopes', () {
    test('parses every non-empty line', () async {
      final lines = <String>[
        envelopeToJsonString(
          const Envelope(attachment: Attachment(body: 'A', mediaType: 'a/b')),
        ),
        '',
        '   ',
        envelopeToJsonString(
          const Envelope(attachment: Attachment(body: 'B', mediaType: 'c/d')),
        ),
      ];

      final values =
          await decodeNdjsonEnvelopes(Stream<String>.fromIterable(lines))
              .toList();

      expect(values.length, 2);
      expect(values.first.attachment?.body, 'A');
      expect(values.last.attachment?.body, 'B');
    });

    test('includes line number when stream line fails parsing', () async {
      final lines = <String>[
        envelopeToJsonString(
          const Envelope(attachment: Attachment(body: 'A', mediaType: 'a/b')),
        ),
        '{"attachment":',
      ];

      await expectLater(
        decodeNdjsonEnvelopes(Stream<String>.fromIterable(lines)).drain<void>(),
        throwsA(
          isA<FormatException>().having(
            (error) => error.message,
            'message',
            contains('line 2'),
          ),
        ),
      );
    });

    test('can omit line content from stream parse errors', () async {
      final lines = <String>['{"attachment":'];

      await expectLater(
        decodeNdjsonEnvelopes(
          Stream<String>.fromIterable(lines),
          includeLineInErrors: false,
        ).drain<void>(),
        throwsA(
          isA<FormatException>().having(
            (error) => error.message,
            'message',
            isNot(contains('Line content:')),
          ),
        ),
      );
    });

    test('truncates line content snippet in parse errors', () {
      final longInvalidLine = '{"x":"${'a' * 200}';

      expect(
        () => parseEnvelopeJson(longInvalidLine),
        throwsA(
          isA<FormatException>().having(
            (error) => error.message,
            'message',
            contains('..."'),
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
          decodeNdjsonEnvelopes(lines).drain<void>(),
          throwsA(isA<FormatException>()),
        );
      },
    );
  });

  group('encodeNdjsonEnvelopes', () {
    test('adds exactly one trailing newline to each envelope', () async {
      final envelopes = Stream<Envelope>.fromIterable([
        const Envelope(attachment: Attachment(body: 'X', mediaType: 'x/y')),
        const Envelope(attachment: Attachment(body: 'Y', mediaType: 'y/z')),
      ]);

      final output = await encodeNdjsonEnvelopes(envelopes).toList();

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
