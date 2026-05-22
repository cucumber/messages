import 'package:cucumber_messages/cucumber_messages.dart' hide Duration;
import 'package:test/test.dart';

void main() {
  test('exports core public API from package root', () async {
    final timestamp = dateTimeToTimestamp(
      DateTime.fromMicrosecondsSinceEpoch(0, isUtc: true),
    );
    final duration = durationToDurationMessage(const Duration(seconds: 1));
    final envelope = parseEnvelopeJson(
      '{"attachment":{"body":"x","contentEncoding":"IDENTITY","mediaType":"text/plain"}}',
    );
    final ndjsonLines =
        await encodeNdjsonEnvelopes(Stream.value(envelope)).toList();
    final parsed =
        await decodeNdjsonEnvelopes(
          Stream.value(envelopeToJsonString(envelope)),
        ).toList();

    expect(IdGenerator, isA<Type>());
    expect(timestampToDateTime(timestamp).isUtc, isTrue);
    expect(durationMessageToDuration(duration), const Duration(seconds: 1));
    expect(envelopeToJsonString(envelope), contains('attachment'));
    expect(parsed.single.attachment?.body, 'x');
    expect(ndjsonLines.single, endsWith('\n'));
  });
}
