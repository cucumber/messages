// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class StepMatchArgumentsList {
  final List<StepMatchArgument> stepMatchArguments;

  const StepMatchArgumentsList({this.stepMatchArguments = const []});

  factory StepMatchArgumentsList.fromJson(Map<String, Object?> json) {
    return StepMatchArgumentsList(
      stepMatchArguments: (json['stepMatchArguments'] as List<Object?>?)
              ?.map(
                (item) =>
                    StepMatchArgument.fromJson(item as Map<String, Object?>),
              )
              .toList() ??
          const [],
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['stepMatchArguments'] =
        stepMatchArguments.map((item) => item.toJson()).toList();
    return json;
  }
}
