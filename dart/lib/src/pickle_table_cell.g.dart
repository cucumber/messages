// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class PickleTableCell {
  final String value;

  const PickleTableCell({this.value = ''});

  factory PickleTableCell.fromJson(Map<String, Object?> json) {
    return PickleTableCell(value: json['value'] as String? ?? '');
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['value'] = value;
    return json;
  }
}
