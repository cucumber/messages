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
    (_) => envelopeToJsonString(sample),
    growable: false,
  );

  final parseSingleMicros = _measureSyncMicros(() {
    jsonLines.forEach(parseEnvelopeJson);
  });

  final readStreamMicros = await _measureAsyncMicros(() async {
    await decodeNdjsonEnvelopes(
      Stream<String>.fromIterable(jsonLines),
    ).drain<void>();
  });

  final writeStreamMicros = await _measureAsyncMicros(() async {
    await encodeNdjsonEnvelopes(
      Stream<Envelope>.fromIterable(
        List<Envelope>.filled(messageCount, sample),
      ),
    ).drain<void>();
  });

  _printResult('parseEnvelopeJson', messageCount, parseSingleMicros);
  _printResult('decodeNdjsonEnvelopes', messageCount, readStreamMicros);
  _printResult('encodeNdjsonEnvelopes', messageCount, writeStreamMicros);
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
