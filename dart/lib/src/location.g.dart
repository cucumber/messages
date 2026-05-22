// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class Location {
  final int line;
  final int? column;

  const Location({
    this.line = 0,
    this.column,
  });

  factory Location.fromJson(Map<String, Object?> json) {
    return Location(
      line: (json['line'] as num?)?.toInt() ?? 0,
      column: (json['column'] as num?)?.toInt(),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['line'] = line;
    if (column != null) {
      json['column'] = column;
    }
    return json;
  }
}

