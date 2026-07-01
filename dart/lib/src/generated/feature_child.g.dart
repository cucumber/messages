// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [FeatureChild message](https://github.com/cucumber/messages/blob/main/jsonschema/src/FeatureChild.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// A child node of a `Feature` node
class FeatureChild {
  /// The `rule` property.
  final Rule? rule;
  /// The `background` property.
  final Background? background;
  /// The `scenario` property.
  final Scenario? scenario;

  /// Creates an instance of [FeatureChild].
  const FeatureChild({
    this.rule,
    this.background,
    this.scenario,
  });

  /// Creates an instance of [FeatureChild] from a JSON object.
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

  /// Converts this [FeatureChild] to a JSON object.
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

