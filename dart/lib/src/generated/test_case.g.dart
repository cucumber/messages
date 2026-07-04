// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [TestCase message](https://github.com/cucumber/messages/blob/main/jsonschema/src/TestCase.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// A `TestCase` contains a sequence of `TestStep`s.
class TestCase {
  /// The `id` property.
  final String id;
  /// The ID of the `Pickle` this `TestCase` is derived from.
  final String pickleId;
  /// The `testSteps` property.
  final List<TestStep> testSteps;
  /// Identifier for the test run that this test case belongs to
  final String? testRunStartedId;

  /// Creates an instance of [TestCase].
  const TestCase({
    required this.id,
    required this.pickleId,
    required this.testSteps,
    this.testRunStartedId,
  });

  /// Creates an instance of [TestCase] from a JSON object.
  factory TestCase.fromJson(Map<String, Object?> json) {
    return TestCase(
      id: _requireJsonString(json, 'id'),
      pickleId: _requireJsonString(json, 'pickleId'),
      testSteps: _requireJsonList(json, 'testSteps')
              .map(
                (item) => TestStep.fromJson(
                  item as Map<String, Object?>,
                ),
              )
              .toList(),
      testRunStartedId: json['testRunStartedId'] as String?,
    );
  }

  /// Converts this [TestCase] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['id'] = id;
    json['pickleId'] = pickleId;
    json['testSteps'] = testSteps.map((item) => item.toJson()).toList();
    if (testRunStartedId != null) {
      json['testRunStartedId'] = testRunStartedId;
    }
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is TestCase &&
          runtimeType == other.runtimeType &&
          id == other.id &&
          pickleId == other.pickleId &&
          _listEquals(testSteps, other.testSteps) &&
          testRunStartedId == other.testRunStartedId;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        id,
        pickleId,
        (testSteps == null ? null : Object.hashAll(testSteps!)),
        testRunStartedId,
      ]);

  @override
  String toString() =>
      'TestCase{id: ${id}, pickleId: ${pickleId}, testSteps: ${testSteps}, testRunStartedId: ${testRunStartedId}}';

  /// Creates a copy of this [TestCase] with the given fields
  /// replaced by the given values. Fields left unspecified keep their current
  /// value.
  TestCase copyWith({
    String? id,
    String? pickleId,
    List<TestStep>? testSteps,
    String? testRunStartedId,
  }) {
    return TestCase(
      id: id ?? this.id,
      pickleId: pickleId ?? this.pickleId,
      testSteps: testSteps ?? this.testSteps,
      testRunStartedId: testRunStartedId ?? this.testRunStartedId,
    );
  }
}

