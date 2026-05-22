import 'dart:async';
import 'dart:io';

import 'package:cucumber_messages/cucumber_messages.dart';

Future<void> main() async {
  const messageCount = 20000;

  const sample = Envelope(
    attachment: Attachment(
      body: 'benchmark',
      mediaType: 'text/plain',
    ),
  );

  final jsonLines = List<String>.generate(
    messageCount,
    (_) => envelopeToJson(sample),
    growable: false,
  );

  final parseSingleMicros = _measureSyncMicros(() {
    jsonLines.forEach(parseEnvelope);
  });

  final readStreamMicros = await _measureAsyncMicros(() async {
    await readNdjsonLines(Stream<String>.fromIterable(jsonLines)).drain<void>();
  });

  final writeStreamMicros = await _measureAsyncMicros(() async {
    await writeNdjsonLines(
      Stream<Envelope>.fromIterable(
        List<Envelope>.filled(messageCount, sample),
      ),
    ).drain<void>();
  });

  _printResult('parseEnvelope', messageCount, parseSingleMicros);
  _printResult('readNdjsonLines', messageCount, readStreamMicros);
  _printResult('writeNdjsonLines', messageCount, writeStreamMicros);
}

int _measureSyncMicros(void Function() action) {
  final stopwatch = Stopwatch()..start();
  action();
  stopwatch.stop();
  return stopwatch.elapsedMicroseconds;
}

Future<int> _measureAsyncMicros(Future<void> Function() action) async {
  final stopwatch = Stopwatch()..start();
  await action();
  stopwatch.stop();
  return stopwatch.elapsedMicroseconds;
}

void _printResult(String name, int count, int elapsedMicros) {
  final perMessageMicros = elapsedMicros / count;
  final messagesPerSecond = (count * 1000000) / elapsedMicros;
  stdout.writeln(
    '$name: $count messages in ${elapsedMicros}us | '
    '${perMessageMicros.toStringAsFixed(2)}us/msg | '
    '${messagesPerSecond.toStringAsFixed(0)} msg/s',
  );
}
