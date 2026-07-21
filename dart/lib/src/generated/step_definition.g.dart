// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [StepDefinition message](https://github.com/cucumber/messages/blob/main/jsonschema/src/StepDefinition.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class StepDefinition {
  /// The `id` property.
  final String id;
  /// The `pattern` property.
  final StepDefinitionPattern pattern;
  /// The `sourceReference` property.
  final SourceReference sourceReference;

  /// Creates an instance of [StepDefinition].
  const StepDefinition({
    required this.id,
    required this.pattern,
    required this.sourceReference,
  });

  /// Creates an instance of [StepDefinition] from a JSON object.
  factory StepDefinition.fromJson(Map<String, Object?> json) {
    return StepDefinition(
      id: _requireJsonString(json, 'id'),
      pattern: StepDefinitionPattern.fromJson(
              _requireJsonObject(json, 'pattern'),
            ),
      sourceReference: SourceReference.fromJson(
              _requireJsonObject(json, 'sourceReference'),
            ),
    );
  }

  /// Converts this [StepDefinition] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['id'] = id;
    json['pattern'] = pattern.toJson();
    json['sourceReference'] = sourceReference.toJson();
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is StepDefinition &&
          runtimeType == other.runtimeType &&
          id == other.id &&
          pattern == other.pattern &&
          sourceReference == other.sourceReference;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        id,
        pattern,
        sourceReference,
      ]);

  @override
  String toString() =>
      'StepDefinition{id: $id, pattern: $pattern, sourceReference: $sourceReference}';
}

