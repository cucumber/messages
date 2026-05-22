import 'package:cucumber_messages/cucumber_messages.dart';
import 'package:test/test.dart';

void main() {
  test('generates uuids', () {
    final generator = uuid();
    final id = generator();
    expect(id.length, 36);
  });

  test('increments ids', () {
    final generator = incrementing();
    expect(generator(), '0');
    expect(generator(), '1');
    expect(generator(), '2');
  });
}
