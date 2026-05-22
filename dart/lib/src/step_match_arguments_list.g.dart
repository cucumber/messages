// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.

part of 'messages.dart';

class StepMatchArgumentsList {
  final List<StepMatchArgument> stepMatchArguments;

  const StepMatchArgumentsList({
    this.stepMatchArguments = const [],
  });

  factory StepMatchArgumentsList.fromJson(Map<String, Object?> json) {
    return StepMatchArgumentsList(
      stepMatchArguments: (json['stepMatchArguments'] as List<Object?>?)
              ?.map(
                (item) => StepMatchArgument.fromJson(
                  item as Map<String, Object?>,
                ),
              )
              .toList() ??
          const [],
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['stepMatchArguments'] = stepMatchArguments.map((item) => item.toJson()).toList();
    return json;
  }
}

