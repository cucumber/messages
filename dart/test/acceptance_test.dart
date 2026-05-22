import 'dart:convert';
import 'dart:io';

import 'package:cucumber_messages/cucumber_messages.dart';
import 'package:test/test.dart';

void main() {
  final testdataDir = Directory('../testdata/src');

  group('messages acceptance tests', () {
    for (final file in _ndjsonFiles(testdataDir)) {
      final name = file.uri.pathSegments.last;

      group("with '$name'", () {
        test('deserializes and serializes each ndjson line', () {
          var lineNumber = 0;
          for (final line in file.readAsLinesSync()) {
            if (line.isEmpty) {
              continue;
            }
            lineNumber++;

            final original = jsonDecode(line);
            final envelope = parseEnvelope(line);
            final roundTripped = jsonDecode(envelopeToJson(envelope));

            expect(roundTripped, original, reason: '$name:$lineNumber');
          }
        });

        test('survives ndjson stream round trip', () async {
          final inputLines = file
              .readAsLinesSync()
              .where((line) => line.isNotEmpty)
              .toList(growable: false);

          final envelopes = await readNdjsonLines(
            Stream<String>.fromIterable(inputLines),
          ).toList();
          final outputLines = await writeNdjsonLines(
            Stream<Envelope>.fromIterable(envelopes),
          ).toList();

          expect(outputLines.length, inputLines.length);

          for (var index = 0; index < inputLines.length; index++) {
            final original = jsonDecode(inputLines[index]);
            final roundTripped = jsonDecode(outputLines[index].trimRight());

            expect(roundTripped, original, reason: '$name:${index + 1}');
          }
        });
      });
    }
  });
}

List<File> _ndjsonFiles(Directory testdataDir) {
  if (!testdataDir.existsSync()) {
    throw StateError('Missing testdata directory: ${testdataDir.path}');
  }

  final files = testdataDir
      .listSync()
      .whereType<File>()
      .where((file) => file.path.endsWith('.ndjson'))
      .toList()
    ..sort((a, b) => a.path.compareTo(b.path));

  if (files.isEmpty) {
    throw StateError('No ndjson files found in ${testdataDir.path}');
  }

  return files;
}
