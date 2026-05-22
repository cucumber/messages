// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.

part of 'messages.dart';

class TestStep {
  final String? hookId;
  final String id;
  final String? pickleStepId;
  final List<String>? stepDefinitionIds;
  final List<StepMatchArgumentsList>? stepMatchArgumentsLists;

  const TestStep({
    this.hookId,
    this.id = '',
    this.pickleStepId,
    this.stepDefinitionIds,
    this.stepMatchArgumentsLists,
  });

  factory TestStep.fromJson(Map<String, Object?> json) {
    return TestStep(
      hookId: json['hookId'] as String?,
      id: json['id'] as String? ?? '',
      pickleStepId: json['pickleStepId'] as String?,
      stepDefinitionIds: (json['stepDefinitionIds'] as List<Object?>?)?.map((item) => item as String).toList() ?? null,
      stepMatchArgumentsLists: (json['stepMatchArgumentsLists'] as List<Object?>?)
              ?.map(
                (item) => StepMatchArgumentsList.fromJson(
                  item as Map<String, Object?>,
                ),
              )
              .toList() ??
          null,
    );
  }

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
}

