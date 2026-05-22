// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

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

