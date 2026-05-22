// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

enum PickleStepType {
  unknown('Unknown'),
  context('Context'),
  action('Action'),
  outcome('Outcome');

  const PickleStepType(this.value);
  final String value;

  static PickleStepType fromValue(String value) =>
      values.firstWhere((v) => v.value == value);
}

class PickleStep {
  final PickleStepArgument? argument;
  final List<String> astNodeIds;
  final String id;
  final PickleStepType? type;
  final String text;

  const PickleStep({
    this.argument,
    this.astNodeIds = const [],
    this.id = '',
    this.type,
    this.text = '',
  });

  factory PickleStep.fromJson(Map<String, Object?> json) {
    return PickleStep(
      argument: json['argument'] == null
          ? null
          : PickleStepArgument.fromJson(
              json['argument'] as Map<String, Object?>,
            ),
      astNodeIds: (json['astNodeIds'] as List<Object?>?)
              ?.map((item) => item as String)
              .toList() ??
          const [],
      id: json['id'] as String? ?? '',
      type: json['type'] == null
          ? null
          : PickleStepType.fromValue(json['type'] as String),
      text: json['text'] as String? ?? '',
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    if (argument != null) {
      json['argument'] = argument!.toJson();
    }
    json['astNodeIds'] = astNodeIds;
    json['id'] = id;
    if (type != null) {
      json['type'] = type!.value;
    }
    json['text'] = text;
    return json;
  }
}
