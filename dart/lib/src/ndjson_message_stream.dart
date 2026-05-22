import 'dart:convert';

import 'package:cucumber_messages/src/messages.dart';

/// Parses a single JSON object into an [Envelope].
///
/// The [json] argument must contain a JSON object that matches the Envelope
/// schema.
///
/// The optional [lineNumber] is used only to improve parse error context.
Envelope parseEnvelope(String json, {int? lineNumber}) {
  try {
    final decoded = jsonDecode(json);
    if (decoded is! Map<String, Object?>) {
      throw FormatException(
        _errorMessage(
          'Expected a JSON object for Envelope but got ${decoded.runtimeType}',
          lineNumber,
          json,
        ),
      );
    }
    return Envelope.fromJson(decoded);
  } on FormatException catch (error) {
    throw FormatException(
      _errorMessage(error.message, lineNumber, json),
      error.source,
      error.offset,
    );
  }
}

/// Serializes [envelope] to a JSON string without a trailing newline.
String envelopeToJson(Envelope envelope) {
  return jsonEncode(envelope.toJson());
}

/// Reads a stream of NDJSON lines and yields a parsed [Envelope] for each
/// non-empty line.
///
/// Each line must contain a single JSON object representing an [Envelope].
///
/// The [lines] stream is consumed in order; whitespace-only lines are ignored.
Stream<Envelope> readNdjsonLines(Stream<String> lines) async* {
  var lineNumber = 0;
  await for (final line in lines) {
    lineNumber++;
    if (line.trim().isEmpty) {
      continue;
    }
    yield parseEnvelope(line, lineNumber: lineNumber);
  }
}

/// Writes a stream of [Envelope]s as NDJSON lines.
///
/// Each yielded string is a JSON object followed by a newline character.
///
/// The [envelopes] stream is serialized in order.
Stream<String> writeNdjsonLines(Stream<Envelope> envelopes) async* {
  await for (final envelope in envelopes) {
    yield '${envelopeToJson(envelope)}\n';
  }
}

String _errorMessage(String message, int? lineNumber, String line) {
  final lineSuffix = lineNumber == null ? '' : ' on line $lineNumber';
  return 'Failed to parse Envelope$lineSuffix: $message. '
      'Line content: "${_snippet(line)}"';
}

String _snippet(String line) {
  const maxLength = 120;
  if (line.length <= maxLength) {
    return line;
  }
  return '${line.substring(0, maxLength)}...';
}
