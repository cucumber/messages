// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [RuleChild message](https://github.com/cucumber/messages/blob/main/jsonschema/src/RuleChild.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// A child node of a `Rule` node
class RuleChild {
  /// The `background` property.
  final Background? background;
  /// The `scenario` property.
  final Scenario? scenario;

  /// Creates an instance of [RuleChild].
  const RuleChild({
    this.background,
    this.scenario,
  });

  /// Creates an instance of [RuleChild] from a JSON object.
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

  /// Converts this [RuleChild] to a JSON object.
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

