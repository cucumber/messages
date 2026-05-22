// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class StepDefinition {
  final String id;
  final StepDefinitionPattern pattern;
  final SourceReference sourceReference;

  const StepDefinition({
    required this.id,
    required this.pattern,
    required this.sourceReference,
  });

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

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['id'] = id;
    json['pattern'] = pattern.toJson();
    json['sourceReference'] = sourceReference.toJson();
    return json;
  }
}

