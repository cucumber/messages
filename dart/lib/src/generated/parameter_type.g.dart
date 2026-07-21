// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [ParameterType message](https://github.com/cucumber/messages/blob/main/jsonschema/src/ParameterType.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class ParameterType {
  /// The name is unique, so we don't need an id.
  final String name;
  /// The `regularExpressions` property.
  final List<String> regularExpressions;
  /// The `preferForRegularExpressionMatch` property.
  final bool preferForRegularExpressionMatch;
  /// The `useForSnippets` property.
  final bool useForSnippets;
  /// The `id` property.
  final String id;
  /// The `sourceReference` property.
  final SourceReference? sourceReference;

  /// Creates an instance of [ParameterType].
  const ParameterType({
    required this.name,
    required this.regularExpressions,
    required this.preferForRegularExpressionMatch,
    required this.useForSnippets,
    required this.id,
    this.sourceReference,
  });

  /// Creates an instance of [ParameterType] from a JSON object.
  factory ParameterType.fromJson(Map<String, Object?> json) {
    return ParameterType(
      name: _requireJsonString(json, 'name'),
      regularExpressions: _requireJsonList(json, 'regularExpressions')
              .map((item) => item as String)
              .toList(),
      preferForRegularExpressionMatch: _requireJsonBool(json, 'preferForRegularExpressionMatch'),
      useForSnippets: _requireJsonBool(json, 'useForSnippets'),
      id: _requireJsonString(json, 'id'),
      sourceReference: json['sourceReference'] == null
          ? null
          : SourceReference.fromJson(
              json['sourceReference'] as Map<String, Object?>,
            ),
    );
  }

  /// Converts this [ParameterType] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['name'] = name;
    json['regularExpressions'] = regularExpressions;
    json['preferForRegularExpressionMatch'] = preferForRegularExpressionMatch;
    json['useForSnippets'] = useForSnippets;
    json['id'] = id;
    if (sourceReference != null) {
      json['sourceReference'] = sourceReference!.toJson();
    }
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is ParameterType &&
          runtimeType == other.runtimeType &&
          name == other.name &&
          _listEquals(regularExpressions, other.regularExpressions) &&
          preferForRegularExpressionMatch == other.preferForRegularExpressionMatch &&
          useForSnippets == other.useForSnippets &&
          id == other.id &&
          sourceReference == other.sourceReference;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        name,
        Object.hashAll(regularExpressions),
        preferForRegularExpressionMatch,
        useForSnippets,
        id,
        sourceReference,
      ]);

  @override
  String toString() =>
      'ParameterType{name: $name, regularExpressions: $regularExpressions, preferForRegularExpressionMatch: $preferForRegularExpressionMatch, useForSnippets: $useForSnippets, id: $id, sourceReference: $sourceReference}';
}

