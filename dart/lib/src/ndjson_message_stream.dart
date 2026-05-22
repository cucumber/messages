import 'dart:convert';

import 'package:cucumber_messages/src/messages.dart';

/// Parses a single JSON object into an [Envelope].
Envelope parseEnvelope(String json) {
  return Envelope.fromJson(jsonDecode(json) as Map<String, Object?>);
}

/// Serializes [envelope] to a JSON string without a trailing newline.
String envelopeToJson(Envelope envelope) {
  return jsonEncode(envelope.toJson());
}

/// Reads a stream of NDJSON lines and yields a parsed [Envelope] for each
/// non-empty line.
///
/// Each line must contain a single JSON object representing an [Envelope].
Stream<Envelope> readNdjsonLines(Stream<String> lines) async* {
  await for (final line in lines) {
    if (line.isEmpty) {
      continue;
    }
    yield parseEnvelope(line);
  }
}

/// Writes a stream of [Envelope]s as NDJSON lines.
///
/// Each yielded string is a JSON object followed by a newline character.
Stream<String> writeNdjsonLines(Stream<Envelope> envelopes) async* {
  await for (final envelope in envelopes) {
    yield '${envelopeToJson(envelope)}\n';
  }
}
