// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

enum StepDefinitionPatternType {
  cucumberExpression('CUCUMBER_EXPRESSION'),
  regularExpression('REGULAR_EXPRESSION'),
  ;

  const StepDefinitionPatternType(this.value);
  final String value;

  static StepDefinitionPatternType fromValue(String value) => values.firstWhere((v) => v.value == value);
}

class StepDefinitionPattern {
  final String source;
  final StepDefinitionPatternType type;

  const StepDefinitionPattern({
    this.source = '',
    this.type = StepDefinitionPatternType.cucumberExpression,
  });

  factory StepDefinitionPattern.fromJson(Map<String, Object?> json) {
    return StepDefinitionPattern(
      source: json['source'] as String? ?? '',
      type: json['type'] == null
          ? StepDefinitionPatternType.cucumberExpression
          : StepDefinitionPatternType.fromValue(
              json['type'] as String,
            ),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['source'] = source;
    json['type'] = type.value;
    return json;
  }
}

