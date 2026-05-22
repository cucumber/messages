// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class TableCell {
  final Location location;
  final String value;

  const TableCell({
    required this.location,
    required this.value,
  });

  factory TableCell.fromJson(Map<String, Object?> json) {
    return TableCell(
      location: Location.fromJson(
              _requireJsonObject(json, 'location'),
            ),
      value: _requireJsonString(json, 'value'),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['location'] = location.toJson();
    json['value'] = value;
    return json;
  }
}

