// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// The test phase signalled by the keyword: Context definition (Given), Action performance (When), Outcome assertion (Then). Other keywords signal Continuation (And and But) from a prior keyword. Please note that all translations which a dialect maps to multiple keywords (`*` is in this category for all dialects), map to 'Unknown'.
enum StepKeywordType {
  /// The `Unknown` value.
  unknown('Unknown'),
  /// The `Context` value.
  context('Context'),
  /// The `Action` value.
  action('Action'),
  /// The `Outcome` value.
  outcome('Outcome'),
  /// The `Conjunction` value.
  conjunction('Conjunction'),
  ;

  /// Creates an instance of [StepKeywordType] from its wire [value].
  const StepKeywordType(this.value);

  /// The wire value used in message JSON.
  final String value;

  /// Returns the [StepKeywordType] matching [value].
  static StepKeywordType fromValue(String value) => values.firstWhere((v) => v.value == value);
}

/// Represents the Step message in [Cucumber's message protocol](https://github.com/cucumber/messages).
///
/// A step
class Step {
  /// The location of the steps' `keyword`
  final Location location;
  /// The actual keyword as it appeared in the source.
  final String keyword;
  /// The test phase signalled by the keyword: Context definition (Given), Action performance (When), Outcome assertion (Then). Other keywords signal Continuation (And and But) from a prior keyword. Please note that all translations which a dialect maps to multiple keywords (`*` is in this category for all dialects), map to 'Unknown'.
  final StepKeywordType? keywordType;
  /// The `text` property.
  final String text;
  /// The `docString` property.
  final DocString? docString;
  /// The `dataTable` property.
  final DataTable? dataTable;
  /// Unique ID to be able to reference the Step from PickleStep
  final String id;

  /// Creates an instance of [Step].
  const Step({
    required this.location,
    required this.keyword,
    this.keywordType,
    required this.text,
    this.docString,
    this.dataTable,
    required this.id,
  });

  /// Creates an instance of [Step] from a JSON object.
  factory Step.fromJson(Map<String, Object?> json) {
    return Step(
      location: Location.fromJson(
              _requireJsonObject(json, 'location'),
            ),
      keyword: _requireJsonString(json, 'keyword'),
      keywordType: json['keywordType'] == null
          ? null
          : StepKeywordType.fromValue(
              json['keywordType'] as String,
            ),
      text: _requireJsonString(json, 'text'),
      docString: json['docString'] == null
          ? null
          : DocString.fromJson(
              json['docString'] as Map<String, Object?>,
            ),
      dataTable: json['dataTable'] == null
          ? null
          : DataTable.fromJson(
              json['dataTable'] as Map<String, Object?>,
            ),
      id: _requireJsonString(json, 'id'),
    );
  }

  /// Converts this [Step] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['location'] = location.toJson();
    json['keyword'] = keyword;
    if (keywordType != null) {
      json['keywordType'] = keywordType!.value;
    }
    json['text'] = text;
    if (docString != null) {
      json['docString'] = docString!.toJson();
    }
    if (dataTable != null) {
      json['dataTable'] = dataTable!.toJson();
    }
    json['id'] = id;
    return json;
  }
}

