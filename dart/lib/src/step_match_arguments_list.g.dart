// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class StepMatchArgumentsList {
  final List<StepMatchArgument> stepMatchArguments;

  const StepMatchArgumentsList({
    required this.stepMatchArguments,
  });

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

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['stepMatchArguments'] = stepMatchArguments.map((item) => item.toJson()).toList();
    return json;
  }
}

