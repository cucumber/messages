// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

enum PickleStepType {
  unknown('Unknown'),
  context('Context'),
  action('Action'),
  outcome('Outcome'),
  ;

  const PickleStepType(this.value);
  final String value;

  static PickleStepType fromValue(String value) => values.firstWhere((v) => v.value == value);
}

class PickleStep {
  final PickleStepArgument? argument;
  final List<String> astNodeIds;
  final String id;
  final PickleStepType? type;
  final String text;

  const PickleStep({
    this.argument,
    required this.astNodeIds,
    required this.id,
    this.type,
    required this.text,
  });

  factory PickleStep.fromJson(Map<String, Object?> json) {
    return PickleStep(
      argument: json['argument'] == null
          ? null
          : PickleStepArgument.fromJson(
              json['argument'] as Map<String, Object?>,
            ),
      astNodeIds: _requireJsonList(json, 'astNodeIds')
              .map((item) => item as String)
              .toList(),
      id: _requireJsonString(json, 'id'),
      type: json['type'] == null
          ? null
          : PickleStepType.fromValue(
              json['type'] as String,
            ),
      text: _requireJsonString(json, 'text'),
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

