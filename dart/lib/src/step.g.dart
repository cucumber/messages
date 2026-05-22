// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

enum StepKeywordType {
  unknown('Unknown'),
  context('Context'),
  action('Action'),
  outcome('Outcome'),
  conjunction('Conjunction'),
  ;

  const StepKeywordType(this.value);
  final String value;

  static StepKeywordType fromValue(String value) => values.firstWhere((v) => v.value == value);
}

class Step {
  final Location location;
  final String keyword;
  final StepKeywordType? keywordType;
  final String text;
  final DocString? docString;
  final DataTable? dataTable;
  final String id;

  const Step({
    required this.location,
    required this.keyword,
    this.keywordType,
    required this.text,
    this.docString,
    this.dataTable,
    required this.id,
  });

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

