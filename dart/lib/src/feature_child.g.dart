// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.

part of 'messages.dart';

class FeatureChild {
  final Rule? rule;
  final Background? background;
  final Scenario? scenario;

  const FeatureChild({
    this.rule,
    this.background,
    this.scenario,
  });

  factory FeatureChild.fromJson(Map<String, Object?> json) {
    return FeatureChild(
      rule: json['rule'] == null
          ? null
          : Rule.fromJson(
              json['rule'] as Map<String, Object?>,
            ),
      background: json['background'] == null
          ? null
          : Background.fromJson(
              json['background'] as Map<String, Object?>,
            ),
      scenario: json['scenario'] == null
          ? null
          : Scenario.fromJson(
              json['scenario'] as Map<String, Object?>,
            ),
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

