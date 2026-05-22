// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class TestCase {
  final String id;
  final String pickleId;
  final List<TestStep> testSteps;
  final String? testRunStartedId;

  const TestCase({
    this.id = '',
    this.pickleId = '',
    this.testSteps = const [],
    this.testRunStartedId,
  });

  factory TestCase.fromJson(Map<String, Object?> json) {
    return TestCase(
      id: json['id'] as String? ?? '',
      pickleId: json['pickleId'] as String? ?? '',
      testSteps: (json['testSteps'] as List<Object?>?)
              ?.map((item) => TestStep.fromJson(item as Map<String, Object?>))
              .toList() ??
          const [],
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
