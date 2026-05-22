import 'package:cucumber_messages/cucumber_messages.dart';
import 'package:test/test.dart';

void main() {
  group('incrementing', () {
    test('starts at zero and increments by one', () {
      final generator = incrementing();
      expect(generator(), '0');
      expect(generator(), '1');
      expect(generator(), '2');
    });

    test('creates independent counters', () {
      final first = incrementing();
      final second = incrementing();

      expect(first(), '0');
      expect(first(), '1');
      expect(second(), '0');
    });
  });

  group('uuid', () {
    final uuidRegex = RegExp(
      r'^[0-9a-f]{8}-[0-9a-f]{4}-4[0-9a-f]{3}-[89ab][0-9a-f]{3}-[0-9a-f]{12}$',
    );

    test('returns RFC 4122 v4 format', () {
      final generator = uuid();
      final id = generator();
      expect(id, matches(uuidRegex));
    });

    test('returns unique values across many calls', () {
      final generator = uuid();
      final ids = <String>{};

      for (var index = 0; index < 100; index++) {
        ids.add(generator());
      }

      expect(ids.length, 100);
    });
  });
}
