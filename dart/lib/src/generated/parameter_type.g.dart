// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class ParameterType {
  final String name;
  final List<String> regularExpressions;
  final bool preferForRegularExpressionMatch;
  final bool useForSnippets;
  final String id;
  final SourceReference? sourceReference;

  const ParameterType({
    required this.name,
    required this.regularExpressions,
    required this.preferForRegularExpressionMatch,
    required this.useForSnippets,
    required this.id,
    this.sourceReference,
  });

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
}

