import 'package:cucumber_messages/cucumber_messages.dart' hide Duration;
import 'package:cucumber_messages/src/messages.dart' as messages;
import 'package:test/test.dart';

void main() {
  group('timestamp conversion', () {
    test('converts to and from wall clock time', () {
      final now = DateTime.fromMicrosecondsSinceEpoch(
        1000000 + 234,
        isUtc: true,
      );

      final timestamp = dateTimeToTimestamp(now);
      final again = timestampToDateTime(timestamp);

      expect(again, now);
    });

    test('normalizes local DateTime values to UTC', () {
      final local = DateTime(2024, 3, 4, 5, 6, 7, 8, 9);

      final timestamp = dateTimeToTimestamp(local);
      final again = timestampToDateTime(timestamp);

      expect(again.isUtc, isTrue);
      expect(
        again.microsecondsSinceEpoch,
        local.toUtc().microsecondsSinceEpoch,
      );
    });

    test(
      'truncates sub-microsecond precision when converting from timestamp',
      () {
        const timestamp = messages.Timestamp(seconds: 1, nanos: 1234);

        final converted = timestampToDateTime(timestamp);

        expect(converted.microsecondsSinceEpoch, 1000001);
      },
    );

    test('throws when nanos are out of range', () {
      const timestamp = Timestamp(seconds: 1, nanos: 1000000000);

      expect(
        () => timestampToDateTime(timestamp),
        throwsA(isA<RangeError>()),
      );
    });

    test('throws when nanos are negative', () {
      const timestamp = Timestamp(seconds: -1, nanos: -1);

      expect(
        () => timestampToDateTime(timestamp),
        throwsA(isA<RangeError>()),
      );
    });

    test('converts far negative epoch timestamps', () {
      const timestamp = Timestamp(seconds: -2208988800);

      final converted = timestampToDateTime(timestamp);

      expect(converted.isUtc, isTrue);
      expect(converted.year, 1900);
    });
  });

  group('duration conversion', () {
    test('converts to and from duration', () {
      const duration = Duration(milliseconds: 1234);

      final message = durationToDurationMessage(duration);
      final again = durationMessageToDuration(message);

      expect(again, duration);
    });

    test('converts negative duration messages to Dart Duration', () {
      const message = messages.Duration(seconds: -1, nanos: 500000000);

      final duration = durationMessageToDuration(message);

      expect(duration, const Duration(milliseconds: -500));
    });

    test(
      'truncates sub-microsecond precision when converting from message',
      () {
        const message = messages.Duration(nanos: 1234);

        final duration = durationMessageToDuration(message);

        expect(duration, const Duration(microseconds: 1));
      },
    );

    test('throws when nanos are out of range', () {
      const message = messages.Duration(nanos: -1000000000);

      expect(
        () => durationMessageToDuration(message),
        throwsA(isA<RangeError>()),
      );
    });

    test('allows mixed-sign duration components', () {
      const message = messages.Duration(seconds: 1, nanos: -1);

      final duration = durationMessageToDuration(message);

      expect(duration, const Duration(seconds: 1));
    });

    test('round-trips large negative durations', () {
      const duration = Duration(days: -1000, microseconds: -999);

      final message = durationToDurationMessage(duration);
      final again = durationMessageToDuration(message);

      expect(again, duration);
    });
  });
}
