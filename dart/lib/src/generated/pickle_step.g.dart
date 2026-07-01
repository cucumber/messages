// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// The context in which the step was specified: context (Given), action (When) or outcome (Then).
///
/// Note that the keywords `But` and `And` inherit their meaning from prior steps and the `*` 'keyword' doesn't have specific meaning (hence Unknown)
enum PickleStepType {
  /// The `Unknown` value.
  unknown('Unknown'),
  /// The `Context` value.
  context('Context'),
  /// The `Action` value.
  action('Action'),
  /// The `Outcome` value.
  outcome('Outcome'),
  ;

  /// Creates an instance of [PickleStepType] from its wire [value].
  const PickleStepType(this.value);

  /// The wire value used in message JSON.
  final String value;

  /// Returns the [PickleStepType] matching [value].
  static PickleStepType fromValue(String value) => values.firstWhere((v) => v.value == value);
}

/// Generated Dart representation of the [PickleStep message](https://github.com/cucumber/messages/blob/main/jsonschema/src/PickleStep.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// An executable step
class PickleStep {
  /// The first argument for this step, if any
  final PickleStepArgument? argument;
  /// References the IDs of the source of the step. For Gherkin, this can be
  /// the ID of a Step, and possibly also the ID of a TableRow
  final List<String> astNodeIds;
  /// A unique ID for the PickleStep
  final String id;
  /// The context in which the step was specified: context (Given), action (When) or outcome (Then).
  ///
  /// Note that the keywords `But` and `And` inherit their meaning from prior steps and the `*` 'keyword' doesn't have specific meaning (hence Unknown)
  final PickleStepType? type;
  /// The `text` property.
  final String text;

  /// Creates an instance of [PickleStep].
  const PickleStep({
    this.argument,
    required this.astNodeIds,
    required this.id,
    this.type,
    required this.text,
  });

  /// Creates an instance of [PickleStep] from a JSON object.
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

  /// Converts this [PickleStep] to a JSON object.
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

