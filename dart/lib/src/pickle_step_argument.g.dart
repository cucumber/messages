// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.

part of 'messages.dart';

class PickleStepArgument {
  final PickleDocString? docString;
  final PickleTable? dataTable;

  const PickleStepArgument({
    this.docString,
    this.dataTable,
  });

  factory PickleStepArgument.fromJson(Map<String, Object?> json) {
    return PickleStepArgument(
      docString: json['docString'] == null
          ? null
          : PickleDocString.fromJson(
              json['docString'] as Map<String, Object?>,
            ),
      dataTable: json['dataTable'] == null
          ? null
          : PickleTable.fromJson(
              json['dataTable'] as Map<String, Object?>,
            ),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    if (docString != null) {
      json['docString'] = docString!.toJson();
    }
    if (dataTable != null) {
      json['dataTable'] = dataTable!.toJson();
    }
    return json;
  }
}

