import 'dart:convert';

import 'package:cucumber_messages/src/generated/messages.dart';

/// Parses a single JSON object into an [Envelope].
///
/// The [json] argument must contain a JSON object that matches the Envelope
/// schema.
///
/// The optional [lineNumber] is used only to improve parse error context.
///
/// When [includeLineInErrors] is false, parse errors do not include input
/// line content.
Envelope parseEnvelopeJson(
  String json, {
  int? lineNumber,
  bool includeLineInErrors = false,
}) {
  try {
    final decoded = jsonDecode(json);
    if (decoded is! Map<String, Object?>) {
      throw FormatException(
        _errorMessage(
          'Expected a JSON object for Envelope but got ${decoded.runtimeType}',
          lineNumber,
          json,
          includeLineInErrors,
        ),
      );
    }
    return Envelope.fromJson(decoded);
  } on FormatException catch (error) {
    throw FormatException(
      _errorMessage(error.message, lineNumber, json, includeLineInErrors),
      error.source,
      error.offset,
    );
  }
}

/// Serializes [envelope] to a JSON string without a trailing newline.
String envelopeToJsonString(Envelope envelope) {
  return jsonEncode(envelope.toJson());
}

/// Reads a stream of NDJSON lines and yields a parsed [Envelope] for each
/// non-empty line.
///
/// Each line must contain a single JSON object representing an [Envelope].
///
/// The [lines] stream is consumed in order; whitespace-only lines are ignored.
///
/// When [includeLineInErrors] is false, parse errors do not include input
/// line content.
Stream<Envelope> decodeNdjsonEnvelopes(
  Stream<String> lines, {
  bool includeLineInErrors = false,
}) async* {
  var lineNumber = 0;
  await for (final line in lines) {
    lineNumber++;
    if (line.trim().isEmpty) {
      continue;
    }
    yield parseEnvelopeJson(
      line,
      lineNumber: lineNumber,
      includeLineInErrors: includeLineInErrors,
    );
  }
}

/// Writes a stream of [Envelope]s as NDJSON lines.
///
/// Each yielded string is a JSON object followed by a newline character.
///
/// The [envelopes] stream is serialized in order.
Stream<String> encodeNdjsonEnvelopes(Stream<Envelope> envelopes) async* {
  await for (final envelope in envelopes) {
    yield '${envelopeToJsonString(envelope)}\n';
  }
}

String _errorMessage(
  String message,
  int? lineNumber,
  String line,
  bool includeLineInErrors,
) {
  final lineSuffix = lineNumber == null ? '' : ' on line $lineNumber';
  final lineDetails =
      includeLineInErrors ? ' Line content: "${_snippet(line)}"' : '';
  return 'Failed to parse Envelope$lineSuffix: $message.$lineDetails';
}

String _snippet(String line) {
  const maxLength = 120;
  if (line.length <= maxLength) {
    return line;
  }
  return '${line.substring(0, maxLength)}...';
}
