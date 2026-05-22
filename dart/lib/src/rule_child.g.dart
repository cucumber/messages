// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class RuleChild {
  final Background? background;
  final Scenario? scenario;

  const RuleChild({
    this.background,
    this.scenario,
  });

  factory RuleChild.fromJson(Map<String, Object?> json) {
    return RuleChild(
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
    if (background != null) {
      json['background'] = background!.toJson();
    }
    if (scenario != null) {
      json['scenario'] = scenario!.toJson();
    }
    return json;
  }
}

