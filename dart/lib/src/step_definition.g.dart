// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class StepDefinition {
  final String id;
  final StepDefinitionPattern pattern;
  final SourceReference sourceReference;

  const StepDefinition({
    this.id = '',
    this.pattern = const StepDefinitionPattern(),
    this.sourceReference = const SourceReference(),
  });

  factory StepDefinition.fromJson(Map<String, Object?> json) {
    return StepDefinition(
      id: json['id'] as String? ?? '',
      pattern: json['pattern'] == null
          ? const StepDefinitionPattern()
          : StepDefinitionPattern.fromJson(
              json['pattern'] as Map<String, Object?>,
            ),
      sourceReference: json['sourceReference'] == null
          ? const SourceReference()
          : SourceReference.fromJson(
              json['sourceReference'] as Map<String, Object?>,
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

