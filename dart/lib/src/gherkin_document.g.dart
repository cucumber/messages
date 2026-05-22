// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class GherkinDocument {
  final String? uri;
  final Feature? feature;
  final List<Comment> comments;

  const GherkinDocument({this.uri, this.feature, this.comments = const []});

  factory GherkinDocument.fromJson(Map<String, Object?> json) {
    return GherkinDocument(
      uri: json['uri'] as String?,
      feature: json['feature'] == null
          ? null
          : Feature.fromJson(json['feature'] as Map<String, Object?>),
      comments:
          (json['comments'] as List<Object?>?)
              ?.map((item) => Comment.fromJson(item as Map<String, Object?>))
              .toList() ??
          const [],
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    if (uri != null) {
      json['uri'] = uri;
    }
    if (feature != null) {
      json['feature'] = feature!.toJson();
    }
    json['comments'] = comments.map((item) => item.toJson()).toList();
    return json;
  }
}
