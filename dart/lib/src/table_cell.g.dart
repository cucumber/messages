// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class TableCell {
  final Location location;
  final String value;

  const TableCell({
    this.location = const Location(),
    this.value = '',
  });

  factory TableCell.fromJson(Map<String, Object?> json) {
    return TableCell(
      location: json['location'] == null
          ? const Location()
          : Location.fromJson(
              json['location'] as Map<String, Object?>,
            ),
      value: json['value'] as String? ?? '',
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['location'] = location.toJson();
    json['value'] = value;
    return json;
  }
}
