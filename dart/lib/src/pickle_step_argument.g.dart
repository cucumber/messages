// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class PickleStepArgument {
  final PickleDocString? docString;
  final PickleTable? dataTable;

  const PickleStepArgument({this.docString, this.dataTable});

  factory PickleStepArgument.fromJson(Map<String, Object?> json) {
    return PickleStepArgument(
      docString: json['docString'] == null
          ? null
          : PickleDocString.fromJson(json['docString'] as Map<String, Object?>),
      dataTable: json['dataTable'] == null
          ? null
          : PickleTable.fromJson(json['dataTable'] as Map<String, Object?>),
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
