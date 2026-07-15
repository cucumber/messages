// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [PickleTableCell message](https://github.com/cucumber/messages/blob/main/jsonschema/src/PickleTableCell.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class PickleTableCell {
  /// The `value` property.
  final String value;

  /// Creates an instance of [PickleTableCell].
  const PickleTableCell({
    required this.value,
  });

  /// Creates an instance of [PickleTableCell] from a JSON object.
  factory PickleTableCell.fromJson(Map<String, Object?> json) {
    return PickleTableCell(
      value: _requireJsonString(json, 'value'),
    );
  }

  /// Converts this [PickleTableCell] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['value'] = value;
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is PickleTableCell &&
          runtimeType == other.runtimeType &&
          value == other.value;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        value,
      ]);

  @override
  String toString() =>
      'PickleTableCell{value: ${value}}';
}

