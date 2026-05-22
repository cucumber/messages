// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class FeatureChild {
  final Rule? rule;
  final Background? background;
  final Scenario? scenario;

  const FeatureChild({this.rule, this.background, this.scenario});

  factory FeatureChild.fromJson(Map<String, Object?> json) {
    return FeatureChild(
      rule: json['rule'] == null
          ? null
          : Rule.fromJson(json['rule'] as Map<String, Object?>),
      background: json['background'] == null
          ? null
          : Background.fromJson(json['background'] as Map<String, Object?>),
      scenario: json['scenario'] == null
          ? null
          : Scenario.fromJson(json['scenario'] as Map<String, Object?>),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    if (rule != null) {
      json['rule'] = rule!.toJson();
    }
    if (background != null) {
      json['background'] = background!.toJson();
    }
    if (scenario != null) {
      json['scenario'] = scenario!.toJson();
    }
    return json;
  }
}
