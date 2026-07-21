// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [Location message](https://github.com/cucumber/messages/blob/main/jsonschema/src/Location.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// Points to a line and a column in a text file
class Location {
  /// The `line` property.
  final int line;
  /// The `column` property.
  final int? column;

  /// Creates an instance of [Location].
  const Location({
    required this.line,
    this.column,
  });

  /// Creates an instance of [Location] from a JSON object.
  factory Location.fromJson(Map<String, Object?> json) {
    return Location(
      line: (_requireJsonNumber(json, 'line') as num).toInt(),
      column: (json['column'] as num?)?.toInt(),
    );
  }

  /// Converts this [Location] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['line'] = line;
    if (column != null) {
      json['column'] = column;
    }
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is Location &&
          runtimeType == other.runtimeType &&
          line == other.line &&
          column == other.column;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        line,
        column,
      ]);

  @override
  String toString() =>
      'Location{line: $line, column: $column}';
}

