import 'package:cucumber_messages/src/messages.dart';

/// Converts a Cucumber [DurationMessage] to a Dart `Duration`.
///
/// Cucumber durations are nanosecond-precision; Dart durations are
/// microsecond-precision. Any sub-microsecond remainder is truncated.
///
/// The [duration] value is interpreted as whole seconds plus nanoseconds.
Duration durationToDartDuration(DurationMessage duration) {
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
