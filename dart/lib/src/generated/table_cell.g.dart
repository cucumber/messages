// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [TableCell message](https://github.com/cucumber/messages/blob/main/jsonschema/src/TableCell.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// A cell in a `TableRow`
class TableCell {
  /// The location of the cell
  final Location location;
  /// The value of the cell
  final String value;

  /// Creates an instance of [TableCell].
  const TableCell({
    required this.location,
    required this.value,
  });

  /// Creates an instance of [TableCell] from a JSON object.
  factory TableCell.fromJson(Map<String, Object?> json) {
    return TableCell(
      location: Location.fromJson(
              _requireJsonObject(json, 'location'),
            ),
      value: _requireJsonString(json, 'value'),
    );
  }

  /// Converts this [TableCell] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['location'] = location.toJson();
    json['value'] = value;
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is TableCell &&
          runtimeType == other.runtimeType &&
          location == other.location &&
          value == other.value;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        location,
        value,
      ]);

  @override
  String toString() =>
      'TableCell{location: ${location}, value: ${value}}';

  /// Creates a copy of this [TableCell] with the given fields
  /// replaced by the given values. Fields left unspecified keep their current
  /// value.
  TableCell copyWith({
    Location? location,
    String? value,
  }) {
    return TableCell(
      location: location ?? this.location,
      value: value ?? this.value,
    );
  }
}

