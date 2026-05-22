// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

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

  static HookType fromValue(String value) => values.firstWhere((v) => v.value == value);
}

class Hook {
  final String id;
  final String? name;
  final SourceReference sourceReference;
  final String? tagExpression;
  final HookType? type;

  const Hook({
    required this.id,
    this.name,
    required this.sourceReference,
    this.tagExpression,
    this.type,
  });

  factory Hook.fromJson(Map<String, Object?> json) {
    return Hook(
      id: _requireJsonString(json, 'id'),
      name: json['name'] as String?,
      sourceReference: SourceReference.fromJson(
              _requireJsonObject(json, 'sourceReference'),
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

