// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class StepMatchArgument {
  final Group group;
  final String? parameterTypeName;

  const StepMatchArgument({
    required this.group,
    this.parameterTypeName,
  });

  factory StepMatchArgument.fromJson(Map<String, Object?> json) {
    return StepMatchArgument(
      group: Group.fromJson(
              _requireJsonObject(json, 'group'),
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

