// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class PickleTableCell {
  final String value;

  const PickleTableCell({
    required this.value,
  });

  factory PickleTableCell.fromJson(Map<String, Object?> json) {
    return PickleTableCell(
      value: _requireJsonString(json, 'value'),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['value'] = value;
    return json;
  }
}

