// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.g.dart';

/// Generated Dart representation of the [PickleStepArgument message](https://github.com/cucumber/messages/blob/main/jsonschema/src/PickleStepArgument.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// Optional arguments. Either a PickleDocString, PickleTable or both
class PickleStepArgument {
  /// The `docString` property.
  final PickleDocString? docString;
  /// The `dataTable` property.
  final PickleTable? dataTable;

  /// Creates an instance of [PickleStepArgument].
  const PickleStepArgument({
    this.docString,
    this.dataTable,
  });

  /// Creates an instance of [PickleStepArgument] from a JSON object.
  factory PickleStepArgument.fromJson(Map<String, Object?> json) {
    return PickleStepArgument(
      docString: json['docString'] == null
          ? null
          : PickleDocString.fromJson(
              json['docString'] as Map<String, Object?>,
            ),
      dataTable: json['dataTable'] == null
          ? null
          : PickleTable.fromJson(
              json['dataTable'] as Map<String, Object?>,
            ),
    );
  }

  /// Converts this [PickleStepArgument] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    if (docString != null) {
      json['docString'] = docString!.toJson();
    }
    if (dataTable != null) {
      json['dataTable'] = dataTable!.toJson();
    }
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is PickleStepArgument &&
          runtimeType == other.runtimeType &&
          docString == other.docString &&
          dataTable == other.dataTable;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        docString,
        dataTable,
      ]);

  @override
  String toString() =>
      'PickleStepArgument{docString: $docString, dataTable: $dataTable}';
}

