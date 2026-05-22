import 'dart:convert';

import 'package:cucumber_messages/cucumber_messages.dart';

Future<void> main() async {
  const original = Envelope(
    attachment: Attachment(
      body: 'hello',
      mediaType: 'text/plain',
    ),
  );

  final line = envelopeToJson(original);
  final parsed = parseEnvelope(line);

  final lines = Stream<String>.value(line).transform(const LineSplitter());
  await for (final envelope in readNdjsonLines(lines)) {
    final ndjsonLine =
        await writeNdjsonLines(Stream<Envelope>.value(envelope)).first;
    assert(
      ndjsonLine.trimRight() == envelopeToJson(parsed),
      'NDJSON line should serialize back to the same envelope JSON.',
    );
  }
}
