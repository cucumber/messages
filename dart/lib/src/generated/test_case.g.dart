// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class TestCase {
  final String id;
  final String pickleId;
  final List<TestStep> testSteps;
  final String? testRunStartedId;

  const TestCase({
    required this.id,
    required this.pickleId,
    required this.testSteps,
    this.testRunStartedId,
  });

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
}

