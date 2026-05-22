import 'dart:convert';

import 'messages.dart';

Envelope parseEnvelope(String json) {
  return Envelope.fromJson(jsonDecode(json) as Map<String, Object?>);
}

String envelopeToJson(Envelope envelope) {
  return jsonEncode(envelope.toJson());
}

Stream<Envelope> readNdjsonLines(Stream<String> lines) async* {
  await for (final line in lines) {
    if (line.isEmpty) {
      continue;
    }
    yield parseEnvelope(line);
  }
}

Stream<String> writeNdjsonLines(Stream<Envelope> envelopes) async* {
  await for (final envelope in envelopes) {
    yield '${envelopeToJson(envelope)}\n';
  }
}
