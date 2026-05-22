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
    this.name = '',
    this.regularExpressions = const [],
    this.preferForRegularExpressionMatch = false,
    this.useForSnippets = false,
    this.id = '',
    this.sourceReference,
  });

  factory ParameterType.fromJson(Map<String, Object?> json) {
    return ParameterType(
      name: json['name'] as String? ?? '',
      regularExpressions: (json['regularExpressions'] as List<Object?>?)?.map((item) => item as String).toList() ?? const [],
      preferForRegularExpressionMatch: json['preferForRegularExpressionMatch'] as bool? ?? false,
      useForSnippets: json['useForSnippets'] as bool? ?? false,
      id: json['id'] as String? ?? '',
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

