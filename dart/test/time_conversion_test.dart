import 'package:cucumber_messages/cucumber_messages.dart';
import 'package:test/test.dart';

void main() {
  test('converts to and from wall clock time', () {
    final now = DateTime.fromMicrosecondsSinceEpoch(1000000 + 234, isUtc: true);
    final timestamp = dartTimeToTimestamp(now);
    final again = timestampToDartTime(timestamp);
    expect(again, now);
  });

  test('converts to and from duration', () {
    const duration = Duration(milliseconds: 1234);
    final message = dartDurationToDuration(duration);
    final again = durationToDartDuration(message);
    expect(again, duration);
  });
}
