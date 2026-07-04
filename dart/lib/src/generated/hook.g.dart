// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Values for the `type` property.
enum HookType {
  /// The `BEFORE_TEST_RUN` value.
  beforeTestRun('BEFORE_TEST_RUN'),
  /// The `AFTER_TEST_RUN` value.
  afterTestRun('AFTER_TEST_RUN'),
  /// The `BEFORE_TEST_CASE` value.
  beforeTestCase('BEFORE_TEST_CASE'),
  /// The `AFTER_TEST_CASE` value.
  afterTestCase('AFTER_TEST_CASE'),
  /// The `BEFORE_TEST_STEP` value.
  beforeTestStep('BEFORE_TEST_STEP'),
  /// The `AFTER_TEST_STEP` value.
  afterTestStep('AFTER_TEST_STEP'),
  ;

  /// Creates an instance of [HookType] from its wire [value].
  const HookType(this.value);

  /// The wire value used in message JSON.
  final String value;

  /// Returns the [HookType] matching [value].
  static HookType fromValue(String value) => values.firstWhere((v) => v.value == value);
}

/// Generated Dart representation of the [Hook message](https://github.com/cucumber/messages/blob/main/jsonschema/src/Hook.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class Hook {
  /// The `id` property.
  final String id;
  /// The `name` property.
  final String? name;
  /// The `sourceReference` property.
  final SourceReference sourceReference;
  /// The `tagExpression` property.
  final String? tagExpression;
  /// The `type` property.
  final HookType? type;

  /// Creates an instance of [Hook].
  const Hook({
    required this.id,
    this.name,
    required this.sourceReference,
    this.tagExpression,
    this.type,
  });

  /// Creates an instance of [Hook] from a JSON object.
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

  /// Converts this [Hook] to a JSON object.
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

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is Hook &&
          runtimeType == other.runtimeType &&
          id == other.id &&
          name == other.name &&
          sourceReference == other.sourceReference &&
          tagExpression == other.tagExpression &&
          type == other.type;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        id,
        name,
        sourceReference,
        tagExpression,
        type,
      ]);

  @override
  String toString() =>
      'Hook{id: ${id}, name: ${name}, sourceReference: ${sourceReference}, tagExpression: ${tagExpression}, type: ${type}}';

  /// Creates a copy of this [Hook] with the given fields
  /// replaced by the given values. Fields left unspecified keep their current
  /// value.
  Hook copyWith({
    String? id,
    String? name,
    SourceReference? sourceReference,
    String? tagExpression,
    HookType? type,
  }) {
    return Hook(
      id: id ?? this.id,
      name: name ?? this.name,
      sourceReference: sourceReference ?? this.sourceReference,
      tagExpression: tagExpression ?? this.tagExpression,
      type: type ?? this.type,
    );
  }
}

