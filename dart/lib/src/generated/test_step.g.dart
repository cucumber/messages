// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [TestStep message](https://github.com/cucumber/messages/blob/main/jsonschema/src/TestStep.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// A `TestStep` is derived from either a `PickleStep` combined with a `StepDefinition`, or from a `Hook`.
///
/// When derived from a PickleStep:
///  * For `UNDEFINED` steps `stepDefinitionIds` and `stepMatchArgumentsLists` will be empty.
///  * For `AMBIGUOUS` steps, there will be multiple entries in `stepDefinitionIds` and `stepMatchArgumentsLists`. The first entry in the stepMatchArgumentsLists holds the list of arguments for the first matching step definition, the second entry for the second, etc
class TestStep {
  /// Pointer to the `Hook` (if derived from a Hook)
  final String? hookId;
  /// The `id` property.
  final String id;
  /// Pointer to the `PickleStep` (if derived from a `PickleStep`)
  final String? pickleStepId;
  /// Pointer to all the matching `StepDefinition`s (if derived from a `PickleStep`).
  ///
  /// Each element represents a matching step definition.
  final List<String>? stepDefinitionIds;
  /// A list of list of StepMatchArgument (if derived from a `PickleStep`).
  ///
  /// Each element represents the arguments for a matching step definition.
  final List<StepMatchArgumentsList>? stepMatchArgumentsLists;

  /// Creates an instance of [TestStep].
  const TestStep({
    this.hookId,
    required this.id,
    this.pickleStepId,
    this.stepDefinitionIds,
    this.stepMatchArgumentsLists,
  });

  /// Creates an instance of [TestStep] from a JSON object.
  factory TestStep.fromJson(Map<String, Object?> json) {
    return TestStep(
      hookId: json['hookId'] as String?,
      id: _requireJsonString(json, 'id'),
      pickleStepId: json['pickleStepId'] as String?,
      stepDefinitionIds: (json['stepDefinitionIds'] as List<Object?>?)
              ?.map((item) => item as String)
              .toList(),
      stepMatchArgumentsLists: (json['stepMatchArgumentsLists'] as List<Object?>?)
              ?.map(
                (item) => StepMatchArgumentsList.fromJson(
                  item as Map<String, Object?>,
                ),
              )
              .toList(),
    );
  }

  /// Converts this [TestStep] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    if (hookId != null) {
      json['hookId'] = hookId;
    }
    json['id'] = id;
    if (pickleStepId != null) {
      json['pickleStepId'] = pickleStepId;
    }
    if (stepDefinitionIds != null) {
      json['stepDefinitionIds'] = stepDefinitionIds;
    }
    if (stepMatchArgumentsLists != null) {
      json['stepMatchArgumentsLists'] = stepMatchArgumentsLists!.map((item) => item.toJson()).toList();
    }
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is TestStep &&
          runtimeType == other.runtimeType &&
          hookId == other.hookId &&
          id == other.id &&
          pickleStepId == other.pickleStepId &&
          _listEquals(stepDefinitionIds, other.stepDefinitionIds) &&
          _listEquals(stepMatchArgumentsLists, other.stepMatchArgumentsLists);

  @override
  int get hashCode => Object.hashAll(<Object?>[
        hookId,
        id,
        pickleStepId,
        (stepDefinitionIds == null ? null : Object.hashAll(stepDefinitionIds!)),
        (stepMatchArgumentsLists == null ? null : Object.hashAll(stepMatchArgumentsLists!)),
      ]);

  @override
  String toString() =>
      'TestStep{hookId: ${hookId}, id: ${id}, pickleStepId: ${pickleStepId}, stepDefinitionIds: ${stepDefinitionIds}, stepMatchArgumentsLists: ${stepMatchArgumentsLists}}';

  /// Creates a copy of this [TestStep] with the given fields
  /// replaced by the given values. Fields left unspecified keep their current
  /// value.
  TestStep copyWith({
    String? hookId,
    String? id,
    String? pickleStepId,
    List<String>? stepDefinitionIds,
    List<StepMatchArgumentsList>? stepMatchArgumentsLists,
  }) {
    return TestStep(
      hookId: hookId ?? this.hookId,
      id: id ?? this.id,
      pickleStepId: pickleStepId ?? this.pickleStepId,
      stepDefinitionIds: stepDefinitionIds ?? this.stepDefinitionIds,
      stepMatchArgumentsLists: stepMatchArgumentsLists ?? this.stepMatchArgumentsLists,
    );
  }
}

