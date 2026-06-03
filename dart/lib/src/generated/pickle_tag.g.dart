// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [PickleTag message](https://github.com/cucumber/messages/blob/main/jsonschema/src/PickleTag.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// A tag
class PickleTag {
  /// The `name` property.
  final String name;
  /// Points to the AST node this was created from
  final String astNodeId;

  /// Creates an instance of [PickleTag].
  const PickleTag({
    required this.name,
    required this.astNodeId,
  });

  /// Creates an instance of [PickleTag] from a JSON object.
  factory PickleTag.fromJson(Map<String, Object?> json) {
    return PickleTag(
      name: _requireJsonString(json, 'name'),
      astNodeId: _requireJsonString(json, 'astNodeId'),
    );
  }

  /// Converts this [PickleTag] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['name'] = name;
    json['astNodeId'] = astNodeId;
    return json;
  }
}

