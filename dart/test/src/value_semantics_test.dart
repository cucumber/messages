import 'package:cucumber_messages/cucumber_messages.dart';
import 'package:test/test.dart';

void main() {
  group('value semantics', () {
    // Build via a non-const path so instances are not canonicalized and are
    // genuinely distinct objects in memory.
    Duration duration(int seconds, int nanos) =>
        Duration.fromJson({'seconds': seconds, 'nanos': nanos});

    test('== is structural for simple messages', () {
      final a = duration(1, 2);
      final b = duration(1, 2);
      final c = duration(1, 3);

      expect(identical(a, b), isFalse);
      expect(a, equals(b));
      expect(a == b, isTrue);
      expect(a == c, isFalse);
    });

    test('hashCode is equal for equal messages and usable as Set keys', () {
      final a = duration(1, 2);
      final b = duration(1, 2);
      final c = duration(1, 3);

      expect(a.hashCode, equals(b.hashCode));

      final set = {a, b, c};
      expect(set, hasLength(2));
    });

    test('toString is readable', () {
      const duration = Duration(seconds: 1, nanos: 2);
      expect(duration.toString(), 'Duration{seconds: 1, nanos: 2}');
    });

    test('copyWith replaces only the given fields', () {
      const original = Duration(seconds: 1, nanos: 2);
      final copy = original.copyWith(nanos: 42);

      expect(copy.seconds, 1);
      expect(copy.nanos, 42);
      expect(copy, equals(const Duration(seconds: 1, nanos: 42)));
      // Original is untouched.
      expect(original, equals(const Duration(seconds: 1, nanos: 2)));
    });

    test('copyWith with no arguments returns an equal value', () {
      const original = Duration(seconds: 5, nanos: 6);
      expect(original.copyWith(), equals(original));
    });

    test('== performs deep comparison of list properties', () {
      final a = PickleTableRow(
        cells: [
          const PickleTableCell(value: 'x'),
          const PickleTableCell(value: 'y'),
        ],
      );
      final b = PickleTableRow(
        cells: [
          const PickleTableCell(value: 'x'),
          const PickleTableCell(value: 'y'),
        ],
      );
      final c = PickleTableRow(
        cells: [
          const PickleTableCell(value: 'x'),
          const PickleTableCell(value: 'z'),
        ],
      );

      expect(a, equals(b));
      expect(a.hashCode, equals(b.hashCode));
      expect(a, isNot(equals(c)));
    });

    test('== distinguishes empty from populated list properties', () {
      final empty1 = PickleTableRow(cells: []);
      final empty2 = PickleTableRow(cells: []);
      final populated = PickleTableRow(
        cells: [const PickleTableCell(value: 'x')],
      );

      expect(empty1, equals(empty2));
      expect(empty1, isNot(equals(populated)));
    });

    test('nested messages compare structurally', () {
      const a = Location(line: 1, column: 2);
      const b = Location(line: 1, column: 2);
      final ta = TableRow(id: '1', location: a, cells: const []);
      final tb = TableRow(id: '1', location: b, cells: const []);

      expect(ta, equals(tb));
      expect(ta.hashCode, equals(tb.hashCode));
    });
  });
}
