import 'package:cucumber_messages/src/messages.dart';

const _nanosPerSecond = 1000000000;

/// Converts a Cucumber [DurationMessage] to a Dart `Duration`.
///
/// Cucumber durations are nanosecond-precision; Dart durations are
/// microsecond-precision. Any sub-microsecond remainder is truncated.
///
/// The [duration] value is interpreted as whole seconds plus nanoseconds.
Duration durationToDartDuration(DurationMessage duration) {
  _validateDurationNanos(duration.nanos);
  return Duration(
    seconds: duration.seconds,
    microseconds: duration.nanos ~/ 1000,
  );
}

/// Converts a Dart `Duration` to a Cucumber [DurationMessage].
///
/// The [duration] value is exported as whole seconds plus nanoseconds.
DurationMessage dartDurationToDuration(Duration duration) {
  final micros = duration.inMicroseconds;
  final seconds = micros ~/ Duration.microsecondsPerSecond;
  final nanos = (micros % Duration.microsecondsPerSecond) * 1000;
  return DurationMessage(seconds: seconds, nanos: nanos);
}

/// Converts a Cucumber [Timestamp] to a UTC [DateTime].
///
/// Cucumber timestamps are nanosecond-precision; Dart `DateTime` is
/// microsecond-precision. Any sub-microsecond remainder is truncated.
///
/// The [timestamp] is interpreted as seconds and nanoseconds since Unix epoch.
DateTime timestampToDartTime(Timestamp timestamp) {
  _validateTimestampNanos(timestamp.nanos);
  final micros = (timestamp.seconds * Duration.microsecondsPerSecond) +
      (timestamp.nanos ~/ 1000);
  return DateTime.fromMicrosecondsSinceEpoch(micros, isUtc: true);
}

/// Converts [dateTime] to a Cucumber [Timestamp] in UTC.
///
/// The [dateTime] is normalized to UTC before conversion.
Timestamp dartTimeToTimestamp(DateTime dateTime) {
  final utc = dateTime.toUtc();
  final micros = utc.microsecondsSinceEpoch;
  final seconds = micros ~/ Duration.microsecondsPerSecond;
  final nanos = (micros % Duration.microsecondsPerSecond) * 1000;
  return Timestamp(seconds: seconds, nanos: nanos);
}

void _validateDurationNanos(int nanos) {
  if (nanos <= -_nanosPerSecond || nanos >= _nanosPerSecond) {
    throw RangeError.range(
      nanos,
      -_nanosPerSecond + 1,
      _nanosPerSecond - 1,
      'DurationMessage.nanos',
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
