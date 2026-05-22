// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class StepMatchArgument {
  final Group group;
  final String? parameterTypeName;

  const StepMatchArgument({
    this.group = const Group(),
    this.parameterTypeName,
  });

  factory StepMatchArgument.fromJson(Map<String, Object?> json) {
    return StepMatchArgument(
      group: json['group'] == null
          ? const Group()
          : Group.fromJson(
              json['group'] as Map<String, Object?>,
            ),
      parameterTypeName: json['parameterTypeName'] as String?,
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['group'] = group.toJson();
    if (parameterTypeName != null) {
      json['parameterTypeName'] = parameterTypeName;
    }
    return json;
  }
}
