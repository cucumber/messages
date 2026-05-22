import 'package:cucumber_messages/src/messages.dart';

/// Converts a Cucumber [DurationMessage] to a Dart `Duration`.
Duration durationToDartDuration(DurationMessage duration) {
  return Duration(
    seconds: duration.seconds,
    microseconds: duration.nanos ~/ 1000,
  );
}

/// Converts a Dart `Duration` to a Cucumber [DurationMessage].
DurationMessage dartDurationToDuration(Duration duration) {
  final micros = duration.inMicroseconds;
  final seconds = micros ~/ Duration.microsecondsPerSecond;
  final nanos = (micros % Duration.microsecondsPerSecond) * 1000;
  return DurationMessage(seconds: seconds, nanos: nanos);
}

/// Converts a Cucumber [Timestamp] to a UTC [DateTime].
DateTime timestampToDartTime(Timestamp timestamp) {
  final micros = (timestamp.seconds * Duration.microsecondsPerSecond) +
      (timestamp.nanos ~/ 1000);
  return DateTime.fromMicrosecondsSinceEpoch(micros, isUtc: true);
}

/// Converts [dateTime] to a Cucumber [Timestamp] in UTC.
Timestamp dartTimeToTimestamp(DateTime dateTime) {
  final utc = dateTime.toUtc();
  final micros = utc.microsecondsSinceEpoch;
  final seconds = micros ~/ Duration.microsecondsPerSecond;
  final nanos = (micros % Duration.microsecondsPerSecond) * 1000;
  return Timestamp(seconds: seconds, nanos: nanos);
}
