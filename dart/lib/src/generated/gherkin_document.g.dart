// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.g.dart';

/// Generated Dart representation of the [GherkinDocument message](https://github.com/cucumber/messages/blob/main/jsonschema/src/GherkinDocument.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// The [AST](https://en.wikipedia.org/wiki/Abstract_syntax_tree) of a Gherkin document.
/// Cucumber implementations should *not* depend on `GherkinDocument` or any of its
/// children for execution - use [Pickle](#io.cucumber.messages.Pickle) instead.
///
/// The only consumers of `GherkinDocument` should only be formatters that produce
/// "rich" output, resembling the original Gherkin document.
class GherkinDocument {
  /// The [URI](https://en.wikipedia.org/wiki/Uniform_Resource_Identifier)
  /// of the source, typically a file path relative to the root directory
  final String? uri;
  /// The `feature` property.
  final Feature? feature;
  /// All the comments in the Gherkin document
  final List<Comment> comments;

  /// Creates an instance of [GherkinDocument].
  const GherkinDocument({
    this.uri,
    this.feature,
    required this.comments,
  });

  /// Creates an instance of [GherkinDocument] from a JSON object.
  factory GherkinDocument.fromJson(Map<String, Object?> json) {
    return GherkinDocument(
      uri: json['uri'] as String?,
      feature: json['feature'] == null
          ? null
          : Feature.fromJson(
              json['feature'] as Map<String, Object?>,
            ),
      comments: _requireJsonList(json, 'comments')
              .map(
                (item) => Comment.fromJson(
                  item as Map<String, Object?>,
                ),
              )
              .toList(),
    );
  }

  /// Converts this [GherkinDocument] to a JSON object.
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

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is GherkinDocument &&
          runtimeType == other.runtimeType &&
          uri == other.uri &&
          feature == other.feature &&
          _listEquals(comments, other.comments);

  @override
  int get hashCode => Object.hashAll(<Object?>[
        uri,
        feature,
        Object.hashAll(comments),
      ]);

  @override
  String toString() =>
      'GherkinDocument{uri: $uri, feature: $feature, comments: $comments}';
}

