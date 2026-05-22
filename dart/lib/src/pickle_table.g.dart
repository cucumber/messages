// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class PickleTable {
  final List<PickleTableRow> rows;

  const PickleTable({this.rows = const []});

  factory PickleTable.fromJson(Map<String, Object?> json) {
    return PickleTable(
      rows:
          (json['rows'] as List<Object?>?)
              ?.map(
                (item) => PickleTableRow.fromJson(item as Map<String, Object?>),
              )
              .toList() ??
          const [],
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['rows'] = rows.map((item) => item.toJson()).toList();
    return json;
  }
}
