// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.

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
    this.location = const Location(),
    this.keyword = '',
    this.keywordType,
    this.text = '',
    this.docString,
    this.dataTable,
    this.id = '',
  });

  factory Step.fromJson(Map<String, Object?> json) {
    return Step(
      location: json['location'] == null
          ? const Location()
          : Location.fromJson(
              json['location'] as Map<String, Object?>,
            ),
      keyword: json['keyword'] as String? ?? '',
      keywordType: json['keywordType'] == null
          ? null
          : StepKeywordType.fromValue(
              json['keywordType'] as String,
            ),
      text: json['text'] as String? ?? '',
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
      id: json['id'] as String? ?? '',
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

