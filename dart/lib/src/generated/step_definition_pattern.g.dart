// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Values for the `type` property.
enum StepDefinitionPatternType {
  /// The `CUCUMBER_EXPRESSION` value.
  cucumberExpression('CUCUMBER_EXPRESSION'),
  /// The `REGULAR_EXPRESSION` value.
  regularExpression('REGULAR_EXPRESSION'),
  ;

  /// Creates an instance of [StepDefinitionPatternType] from its wire [value].
  const StepDefinitionPatternType(this.value);

  /// The wire value used in message JSON.
  final String value;

  /// Returns the [StepDefinitionPatternType] matching [value].
  static StepDefinitionPatternType fromValue(String value) => values.firstWhere((v) => v.value == value);
}

/// Generated Dart representation of the [StepDefinitionPattern message](https://github.com/cucumber/messages/blob/main/jsonschema/src/StepDefinitionPattern.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class StepDefinitionPattern {
  /// The `source` property.
  final String source;
  /// The `type` property.
  final StepDefinitionPatternType type;

  /// Creates an instance of [StepDefinitionPattern].
  const StepDefinitionPattern({
    required this.source,
    required this.type,
  });

  /// Creates an instance of [StepDefinitionPattern] from a JSON object.
  factory StepDefinitionPattern.fromJson(Map<String, Object?> json) {
    return StepDefinitionPattern(
      source: _requireJsonString(json, 'source'),
      type: StepDefinitionPatternType.fromValue(
              _requireJsonString(json, 'type'),
            ),
    );
  }

  /// Converts this [StepDefinitionPattern] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['source'] = source;
    json['type'] = type.value;
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is StepDefinitionPattern &&
          runtimeType == other.runtimeType &&
          source == other.source &&
          type == other.type;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        source,
        type,
      ]);

  @override
  String toString() =>
      'StepDefinitionPattern{source: ${source}, type: ${type}}';

  /// Creates a copy of this [StepDefinitionPattern] with the given fields
  /// replaced by the given values. Fields left unspecified keep their current
  /// value.
  StepDefinitionPattern copyWith({
    String? source,
    StepDefinitionPatternType? type,
  }) {
    return StepDefinitionPattern(
      source: source ?? this.source,
      type: type ?? this.type,
    );
  }
}

