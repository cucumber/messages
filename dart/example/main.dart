import 'dart:io';

import 'package:cucumber_messages/cucumber_messages.dart';

Future<void> main() async {
  const envelope = Envelope(
    attachment: Attachment(
      body: 'Hello, world!',
      contentEncoding: AttachmentContentEncoding.identity,
      mediaType: 'text/plain',
    ),
  );

  final lines = encodeNdjsonEnvelopes(Stream.value(envelope));

  await for (final decoded in decodeNdjsonEnvelopes(lines)) {
    stdout.writeln(decoded.attachment?.body);
  }
}
