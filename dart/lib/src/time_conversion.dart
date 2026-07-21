import 'package:cucumber_messages/src/generated/messages.g.dart' as messages;

const _nanosPerSecond = 1000000000;

/// Converts a Cucumber [messages.Duration] to a Dart [Duration].
///
/// Cucumber durations are nanosecond-precision; Dart durations are
/// microsecond-precision. Any sub-microsecond remainder is truncated.
///
/// The [duration] value is interpreted as whole seconds plus nanoseconds.
Duration durationMessageToDuration(messages.Duration duration) {
  _validateDurationNanos(duration.nanos);
  return Duration(
    seconds: duration.seconds,
    microseconds: duration.nanos ~/ 1000,
  );
}

/// Converts a Dart [Duration] to a Cucumber [messages.Duration].
///
/// The [duration] value is exported as whole seconds plus nanoseconds.
messages.Duration durationToDurationMessage(Duration duration) {
  final micros = duration.inMicroseconds;
  final seconds = micros ~/ Duration.microsecondsPerSecond;
  final nanos = micros.remainder(Duration.microsecondsPerSecond) * 1000;
  return messages.Duration(seconds: seconds, nanos: nanos);
}

/// Converts a Cucumber [messages.Timestamp] to a UTC [DateTime].
///
/// Cucumber timestamps are nanosecond-precision; Dart `DateTime` is
/// microsecond-precision. Any sub-microsecond remainder is truncated.
///
/// The [timestamp] is interpreted as seconds and nanoseconds since Unix epoch.
DateTime timestampToDateTime(messages.Timestamp timestamp) {
  _validateTimestampNanos(timestamp.nanos);
  final micros =
      (timestamp.seconds * Duration.microsecondsPerSecond) +
      (timestamp.nanos ~/ 1000);
  return DateTime.fromMicrosecondsSinceEpoch(micros, isUtc: true);
}

/// Converts [dateTime] to a Cucumber [messages.Timestamp] in UTC.
///
/// The [dateTime] is normalized to UTC before conversion.
messages.Timestamp dateTimeToTimestamp(DateTime dateTime) {
  final utc = dateTime.toUtc();
  final micros = utc.microsecondsSinceEpoch;
  final seconds = micros ~/ Duration.microsecondsPerSecond;
  final nanos = (micros % Duration.microsecondsPerSecond) * 1000;
  return messages.Timestamp(seconds: seconds, nanos: nanos);
}

void _validateDurationNanos(int nanos) {
  if (nanos <= -_nanosPerSecond || nanos >= _nanosPerSecond) {
    throw RangeError.range(
      nanos,
      -_nanosPerSecond + 1,
      _nanosPerSecond - 1,
      'Duration.nanos',
      'must be in (-1e9, 1e9)',
    );
  }
}

void _validateTimestampNanos(int nanos) {
  if (nanos < 0 || nanos >= _nanosPerSecond) {
    throw RangeError.range(
      nanos,
      0,
      _nanosPerSecond - 1,
      'Timestamp.nanos',
      'must be in [0, 1e9)',
    );
  }
}
