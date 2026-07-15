// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [StepMatchArgumentsList message](https://github.com/cucumber/messages/blob/main/jsonschema/src/StepMatchArgumentsList.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class StepMatchArgumentsList {
  /// The `stepMatchArguments` property.
  final List<StepMatchArgument> stepMatchArguments;

  /// Creates an instance of [StepMatchArgumentsList].
  const StepMatchArgumentsList({
    required this.stepMatchArguments,
  });

  /// Creates an instance of [StepMatchArgumentsList] from a JSON object.
  factory StepMatchArgumentsList.fromJson(Map<String, Object?> json) {
    return StepMatchArgumentsList(
      stepMatchArguments: _requireJsonList(json, 'stepMatchArguments')
              .map(
                (item) => StepMatchArgument.fromJson(
                  item as Map<String, Object?>,
                ),
              )
              .toList(),
    );
  }

  /// Converts this [StepMatchArgumentsList] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['stepMatchArguments'] = stepMatchArguments.map((item) => item.toJson()).toList();
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is StepMatchArgumentsList &&
          runtimeType == other.runtimeType &&
          _listEquals(stepMatchArguments, other.stepMatchArguments);

  @override
  int get hashCode => Object.hashAll(<Object?>[
        (stepMatchArguments == null ? null : Object.hashAll(stepMatchArguments!)),
      ]);

  @override
  String toString() =>
      'StepMatchArgumentsList{stepMatchArguments: ${stepMatchArguments}}';
}

