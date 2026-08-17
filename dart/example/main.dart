import 'package:cucumber_messages/cucumber_messages.dart';

Future<void> main() async {
  final envelope = Envelope(
    attachment: Attachment(
      body: 'Hello, world!',
      contentEncoding: AttachmentContentEncoding.identity,
      mediaType: 'text/plain',
    ),
  );

  final lines = encodeNdjsonEnvelopes(Stream.value(envelope));

  await for (final decoded in decodeNdjsonEnvelopes(lines)) {
    print(decoded.attachment?.body);
  }
}
