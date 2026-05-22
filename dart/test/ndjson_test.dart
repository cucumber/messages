import 'package:cucumber_messages/cucumber_messages.dart';
import 'package:test/test.dart';

void main() {
  test('reads and writes ndjson envelope', () async {
    final envelope = Envelope(
      attachment: Attachment(
        body: 'Hello',
        contentEncoding: AttachmentContentEncoding.identity,
        mediaType: 'text/plain',
      ),
    );
    final jsonLine = envelopeToJson(envelope);
    final decoded = parseEnvelope(jsonLine);
    expect(decoded.attachment?.body, 'Hello');

    final lines = Stream<String>.fromIterable([jsonLine]);
    final values = await readNdjsonLines(lines).toList();
    expect(values.single.attachment?.mediaType, 'text/plain');

    final output = await writeNdjsonLines(Stream.value(values.single)).toList();
    expect(output.single.endsWith('\n'), isTrue);
  });
}
