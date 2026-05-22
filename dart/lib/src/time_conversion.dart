import 'messages.dart';

Duration durationToDartDuration(DurationMessage duration) {
  return Duration(
    seconds: duration.seconds,
    microseconds: duration.nanos ~/ 1000,
  );
}

DurationMessage dartDurationToDuration(Duration duration) {
  final micros = duration.inMicroseconds;
  final seconds = micros ~/ Duration.microsecondsPerSecond;
  final nanos = (micros % Duration.microsecondsPerSecond) * 1000;
  return DurationMessage(seconds: seconds, nanos: nanos);
}

DateTime timestampToDartTime(Timestamp timestamp) {
  final micros =
      (timestamp.seconds * Duration.microsecondsPerSecond) +
      (timestamp.nanos ~/ 1000);
  return DateTime.fromMicrosecondsSinceEpoch(micros, isUtc: true);
}

Timestamp dartTimeToTimestamp(DateTime dateTime) {
  final utc = dateTime.toUtc();
  final micros = utc.microsecondsSinceEpoch;
  final seconds = micros ~/ Duration.microsecondsPerSecond;
  final nanos = (micros % Duration.microsecondsPerSecond) * 1000;
  return Timestamp(seconds: seconds, nanos: nanos);
}
