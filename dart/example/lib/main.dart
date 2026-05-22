import 'dart:convert';

import 'package:cucumber_messages/cucumber_messages.dart';

Future<void> main() async {
  const original = Envelope(
    attachment: Attachment(
      body: 'hello',
      contentEncoding: AttachmentContentEncoding.identity,
      mediaType: 'text/plain',
    ),
  );

  final line = envelopeToJsonString(original);
  final parsed = parseEnvelopeJson(line);

  final lines = Stream<String>.value(line).transform(const LineSplitter());
  await for (final envelope in decodeNdjsonEnvelopes(lines)) {
    final ndjsonLine = await encodeNdjsonEnvelopes(
      Stream<Envelope>.value(envelope),
    ).first;
    assert(
      ndjsonLine.trimRight() == envelopeToJsonString(parsed),
      'NDJSON line should serialize back to the same envelope JSON.',
    );
  }
}
