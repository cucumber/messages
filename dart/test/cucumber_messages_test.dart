import 'package:cucumber_messages/cucumber_messages.dart';
import 'package:test/test.dart';

void main() {
  test('exports core public API from package root', () async {
    final generateUuid = uuid();
    final generateIncrementing = incrementing();
    final timestamp = dartTimeToTimestamp(
      DateTime.fromMicrosecondsSinceEpoch(0, isUtc: true),
    );
    final duration = dartDurationToDuration(const Duration(seconds: 1));
    final envelope =
        parseEnvelope('{"attachment":{"body":"x","mediaType":"text/plain"}}');
    final ndjsonLines = await writeNdjsonLines(Stream.value(envelope)).toList();
    final parsed = await readNdjsonLines(
      Stream.value(envelopeToJson(envelope)),
    ).toList();

    expect(generateUuid(), isNotEmpty);
    expect(generateIncrementing(), '0');
    expect(timestampToDartTime(timestamp).isUtc, isTrue);
    expect(durationToDartDuration(duration), const Duration(seconds: 1));
    expect(envelopeToJson(envelope), contains('attachment'));
    expect(parsed.single.attachment?.body, 'x');
    expect(ndjsonLines.single, endsWith('\n'));
  });
}
