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
  });

  group('readNdjsonLines', () {
    test('parses every non-empty line', () async {
      final lines = <String>[
        envelopeToJson(
          const Envelope(attachment: Attachment(body: 'A', mediaType: 'a/b')),
        ),
        '',
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
