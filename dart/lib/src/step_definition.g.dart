// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

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
