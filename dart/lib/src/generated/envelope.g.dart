// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [Envelope message](https://github.com/cucumber/messages/blob/main/jsonschema/src/Envelope.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class Envelope {
  /// The `attachment` property.
  final Attachment? attachment;
  /// The `externalAttachment` property.
  final ExternalAttachment? externalAttachment;
  /// The `gherkinDocument` property.
  final GherkinDocument? gherkinDocument;
  /// The `hook` property.
  final Hook? hook;
  /// The `meta` property.
  final Meta? meta;
  /// The `parameterType` property.
  final ParameterType? parameterType;
  /// The `parseError` property.
  final ParseError? parseError;
  /// The `pickle` property.
  final Pickle? pickle;
  /// The `suggestion` property.
  final Suggestion? suggestion;
  /// The `source` property.
  final Source? source;
  /// The `stepDefinition` property.
  final StepDefinition? stepDefinition;
  /// The `testCase` property.
  final TestCase? testCase;
  /// The `testCaseFinished` property.
  final TestCaseFinished? testCaseFinished;
  /// The `testCaseStarted` property.
  final TestCaseStarted? testCaseStarted;
  /// The `testRunFinished` property.
  final TestRunFinished? testRunFinished;
  /// The `testRunStarted` property.
  final TestRunStarted? testRunStarted;
  /// The `testStepFinished` property.
  final TestStepFinished? testStepFinished;
  /// The `testStepStarted` property.
  final TestStepStarted? testStepStarted;
  /// The `testRunHookStarted` property.
  final TestRunHookStarted? testRunHookStarted;
  /// The `testRunHookFinished` property.
  final TestRunHookFinished? testRunHookFinished;
  /// The `undefinedParameterType` property.
  final UndefinedParameterType? undefinedParameterType;

  /// Creates an instance of [Envelope].
  const Envelope({
    this.attachment,
    this.externalAttachment,
    this.gherkinDocument,
    this.hook,
    this.meta,
    this.parameterType,
    this.parseError,
    this.pickle,
    this.suggestion,
    this.source,
    this.stepDefinition,
    this.testCase,
    this.testCaseFinished,
    this.testCaseStarted,
    this.testRunFinished,
    this.testRunStarted,
    this.testStepFinished,
    this.testStepStarted,
    this.testRunHookStarted,
    this.testRunHookFinished,
    this.undefinedParameterType,
  });

  /// Creates an instance of [Envelope] from a JSON object.
  factory Envelope.fromJson(Map<String, Object?> json) {
    return Envelope(
      attachment: json['attachment'] == null
          ? null
          : Attachment.fromJson(
              json['attachment'] as Map<String, Object?>,
            ),
      externalAttachment: json['externalAttachment'] == null
          ? null
          : ExternalAttachment.fromJson(
              json['externalAttachment'] as Map<String, Object?>,
            ),
      gherkinDocument: json['gherkinDocument'] == null
          ? null
          : GherkinDocument.fromJson(
              json['gherkinDocument'] as Map<String, Object?>,
            ),
      hook: json['hook'] == null
          ? null
          : Hook.fromJson(
              json['hook'] as Map<String, Object?>,
            ),
      meta: json['meta'] == null
          ? null
          : Meta.fromJson(
              json['meta'] as Map<String, Object?>,
            ),
      parameterType: json['parameterType'] == null
          ? null
          : ParameterType.fromJson(
              json['parameterType'] as Map<String, Object?>,
            ),
      parseError: json['parseError'] == null
          ? null
          : ParseError.fromJson(
              json['parseError'] as Map<String, Object?>,
            ),
      pickle: json['pickle'] == null
          ? null
          : Pickle.fromJson(
              json['pickle'] as Map<String, Object?>,
            ),
      suggestion: json['suggestion'] == null
          ? null
          : Suggestion.fromJson(
              json['suggestion'] as Map<String, Object?>,
            ),
      source: json['source'] == null
          ? null
          : Source.fromJson(
              json['source'] as Map<String, Object?>,
            ),
      stepDefinition: json['stepDefinition'] == null
          ? null
          : StepDefinition.fromJson(
              json['stepDefinition'] as Map<String, Object?>,
            ),
      testCase: json['testCase'] == null
          ? null
          : TestCase.fromJson(
              json['testCase'] as Map<String, Object?>,
            ),
      testCaseFinished: json['testCaseFinished'] == null
          ? null
          : TestCaseFinished.fromJson(
              json['testCaseFinished'] as Map<String, Object?>,
            ),
      testCaseStarted: json['testCaseStarted'] == null
          ? null
          : TestCaseStarted.fromJson(
              json['testCaseStarted'] as Map<String, Object?>,
            ),
      testRunFinished: json['testRunFinished'] == null
          ? null
          : TestRunFinished.fromJson(
              json['testRunFinished'] as Map<String, Object?>,
            ),
      testRunStarted: json['testRunStarted'] == null
          ? null
          : TestRunStarted.fromJson(
              json['testRunStarted'] as Map<String, Object?>,
            ),
      testStepFinished: json['testStepFinished'] == null
          ? null
          : TestStepFinished.fromJson(
              json['testStepFinished'] as Map<String, Object?>,
            ),
      testStepStarted: json['testStepStarted'] == null
          ? null
          : TestStepStarted.fromJson(
              json['testStepStarted'] as Map<String, Object?>,
            ),
      testRunHookStarted: json['testRunHookStarted'] == null
          ? null
          : TestRunHookStarted.fromJson(
              json['testRunHookStarted'] as Map<String, Object?>,
            ),
      testRunHookFinished: json['testRunHookFinished'] == null
          ? null
          : TestRunHookFinished.fromJson(
              json['testRunHookFinished'] as Map<String, Object?>,
            ),
      undefinedParameterType: json['undefinedParameterType'] == null
          ? null
          : UndefinedParameterType.fromJson(
              json['undefinedParameterType'] as Map<String, Object?>,
            ),
    );
  }

  /// Converts this [Envelope] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    if (attachment != null) {
      json['attachment'] = attachment!.toJson();
    }
    if (externalAttachment != null) {
      json['externalAttachment'] = externalAttachment!.toJson();
    }
    if (gherkinDocument != null) {
      json['gherkinDocument'] = gherkinDocument!.toJson();
    }
    if (hook != null) {
      json['hook'] = hook!.toJson();
    }
    if (meta != null) {
      json['meta'] = meta!.toJson();
    }
    if (parameterType != null) {
      json['parameterType'] = parameterType!.toJson();
    }
    if (parseError != null) {
      json['parseError'] = parseError!.toJson();
    }
    if (pickle != null) {
      json['pickle'] = pickle!.toJson();
    }
    if (suggestion != null) {
      json['suggestion'] = suggestion!.toJson();
    }
    if (source != null) {
      json['source'] = source!.toJson();
    }
    if (stepDefinition != null) {
      json['stepDefinition'] = stepDefinition!.toJson();
    }
    if (testCase != null) {
      json['testCase'] = testCase!.toJson();
    }
    if (testCaseFinished != null) {
      json['testCaseFinished'] = testCaseFinished!.toJson();
    }
    if (testCaseStarted != null) {
      json['testCaseStarted'] = testCaseStarted!.toJson();
    }
    if (testRunFinished != null) {
      json['testRunFinished'] = testRunFinished!.toJson();
    }
    if (testRunStarted != null) {
      json['testRunStarted'] = testRunStarted!.toJson();
    }
    if (testStepFinished != null) {
      json['testStepFinished'] = testStepFinished!.toJson();
    }
    if (testStepStarted != null) {
      json['testStepStarted'] = testStepStarted!.toJson();
    }
    if (testRunHookStarted != null) {
      json['testRunHookStarted'] = testRunHookStarted!.toJson();
    }
    if (testRunHookFinished != null) {
      json['testRunHookFinished'] = testRunHookFinished!.toJson();
    }
    if (undefinedParameterType != null) {
      json['undefinedParameterType'] = undefinedParameterType!.toJson();
    }
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is Envelope &&
          runtimeType == other.runtimeType &&
          attachment == other.attachment &&
          externalAttachment == other.externalAttachment &&
          gherkinDocument == other.gherkinDocument &&
          hook == other.hook &&
          meta == other.meta &&
          parameterType == other.parameterType &&
          parseError == other.parseError &&
          pickle == other.pickle &&
          suggestion == other.suggestion &&
          source == other.source &&
          stepDefinition == other.stepDefinition &&
          testCase == other.testCase &&
          testCaseFinished == other.testCaseFinished &&
          testCaseStarted == other.testCaseStarted &&
          testRunFinished == other.testRunFinished &&
          testRunStarted == other.testRunStarted &&
          testStepFinished == other.testStepFinished &&
          testStepStarted == other.testStepStarted &&
          testRunHookStarted == other.testRunHookStarted &&
          testRunHookFinished == other.testRunHookFinished &&
          undefinedParameterType == other.undefinedParameterType;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        attachment,
        externalAttachment,
        gherkinDocument,
        hook,
        meta,
        parameterType,
        parseError,
        pickle,
        suggestion,
        source,
        stepDefinition,
        testCase,
        testCaseFinished,
        testCaseStarted,
        testRunFinished,
        testRunStarted,
        testStepFinished,
        testStepStarted,
        testRunHookStarted,
        testRunHookFinished,
        undefinedParameterType,
      ]);

  @override
  String toString() =>
      'Envelope{attachment: ${attachment}, externalAttachment: ${externalAttachment}, gherkinDocument: ${gherkinDocument}, hook: ${hook}, meta: ${meta}, parameterType: ${parameterType}, parseError: ${parseError}, pickle: ${pickle}, suggestion: ${suggestion}, source: ${source}, stepDefinition: ${stepDefinition}, testCase: ${testCase}, testCaseFinished: ${testCaseFinished}, testCaseStarted: ${testCaseStarted}, testRunFinished: ${testRunFinished}, testRunStarted: ${testRunStarted}, testStepFinished: ${testStepFinished}, testStepStarted: ${testStepStarted}, testRunHookStarted: ${testRunHookStarted}, testRunHookFinished: ${testRunHookFinished}, undefinedParameterType: ${undefinedParameterType}}';

  /// Creates a copy of this [Envelope] with the given fields
  /// replaced by the given values. Fields left unspecified keep their current
  /// value.
  Envelope copyWith({
    Attachment? attachment,
    ExternalAttachment? externalAttachment,
    GherkinDocument? gherkinDocument,
    Hook? hook,
    Meta? meta,
    ParameterType? parameterType,
    ParseError? parseError,
    Pickle? pickle,
    Suggestion? suggestion,
    Source? source,
    StepDefinition? stepDefinition,
    TestCase? testCase,
    TestCaseFinished? testCaseFinished,
    TestCaseStarted? testCaseStarted,
    TestRunFinished? testRunFinished,
    TestRunStarted? testRunStarted,
    TestStepFinished? testStepFinished,
    TestStepStarted? testStepStarted,
    TestRunHookStarted? testRunHookStarted,
    TestRunHookFinished? testRunHookFinished,
    UndefinedParameterType? undefinedParameterType,
  }) {
    return Envelope(
      attachment: attachment ?? this.attachment,
      externalAttachment: externalAttachment ?? this.externalAttachment,
      gherkinDocument: gherkinDocument ?? this.gherkinDocument,
      hook: hook ?? this.hook,
      meta: meta ?? this.meta,
      parameterType: parameterType ?? this.parameterType,
      parseError: parseError ?? this.parseError,
      pickle: pickle ?? this.pickle,
      suggestion: suggestion ?? this.suggestion,
      source: source ?? this.source,
      stepDefinition: stepDefinition ?? this.stepDefinition,
      testCase: testCase ?? this.testCase,
      testCaseFinished: testCaseFinished ?? this.testCaseFinished,
      testCaseStarted: testCaseStarted ?? this.testCaseStarted,
      testRunFinished: testRunFinished ?? this.testRunFinished,
      testRunStarted: testRunStarted ?? this.testRunStarted,
      testStepFinished: testStepFinished ?? this.testStepFinished,
      testStepStarted: testStepStarted ?? this.testStepStarted,
      testRunHookStarted: testRunHookStarted ?? this.testRunHookStarted,
      testRunHookFinished: testRunHookFinished ?? this.testRunHookFinished,
      undefinedParameterType: undefinedParameterType ?? this.undefinedParameterType,
    );
  }
}

