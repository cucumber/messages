// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

enum HookType {
  beforeTestRun('BEFORE_TEST_RUN'),
  afterTestRun('AFTER_TEST_RUN'),
  beforeTestCase('BEFORE_TEST_CASE'),
  afterTestCase('AFTER_TEST_CASE'),
  beforeTestStep('BEFORE_TEST_STEP'),
  afterTestStep('AFTER_TEST_STEP'),
  ;

  const HookType(this.value);
  final String value;

  static HookType fromValue(String value) =>
      values.firstWhere((v) => v.value == value);
}

class Hook {
  final String id;
  final String? name;
  final SourceReference sourceReference;
  final String? tagExpression;
  final HookType? type;

  const Hook({
    this.id = '',
    this.name,
    this.sourceReference = const SourceReference(),
    this.tagExpression,
    this.type,
  });

  factory Hook.fromJson(Map<String, Object?> json) {
    return Hook(
      id: json['id'] as String? ?? '',
      name: json['name'] as String?,
      sourceReference: json['sourceReference'] == null
          ? const SourceReference()
          : SourceReference.fromJson(
              json['sourceReference'] as Map<String, Object?>,
            ),
      tagExpression: json['tagExpression'] as String?,
      type: json['type'] == null
          ? null
          : HookType.fromValue(
              json['type'] as String,
            ),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['id'] = id;
    if (name != null) {
      json['name'] = name;
    }
    json['sourceReference'] = sourceReference.toJson();
    if (tagExpression != null) {
      json['tagExpression'] = tagExpression;
    }
    if (type != null) {
      json['type'] = type!.value;
    }
    return json;
  }
}
