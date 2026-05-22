import 'package:cucumber_messages/cucumber_messages.dart';
import 'package:test/test.dart';

void main() {
  group('incrementingIdGenerator', () {
    test('starts at zero and increments by one', () {
      final generator = incrementingIdGenerator();
      expect(generator(), '0');
      expect(generator(), '1');
      expect(generator(), '2');
    });

    test('creates independent counters', () {
      final first = incrementingIdGenerator();
      final second = incrementingIdGenerator();

      expect(first(), '0');
      expect(first(), '1');
      expect(second(), '0');
    });
  });
}
