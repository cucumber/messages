// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [Git message](https://github.com/cucumber/messages/blob/main/jsonschema/src/Git.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// Information about Git, provided by the Build/CI server as environment
/// variables.
class Git {
  /// The `remote` property.
  final String remote;
  /// The `revision` property.
  final String revision;
  /// The `branch` property.
  final String? branch;
  /// The `tag` property.
  final String? tag;

  /// Creates an instance of [Git].
  const Git({
    required this.remote,
    required this.revision,
    this.branch,
    this.tag,
  });

  /// Creates an instance of [Git] from a JSON object.
  factory Git.fromJson(Map<String, Object?> json) {
    return Git(
      remote: _requireJsonString(json, 'remote'),
      revision: _requireJsonString(json, 'revision'),
      branch: json['branch'] as String?,
      tag: json['tag'] as String?,
    );
  }

  /// Converts this [Git] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['remote'] = remote;
    json['revision'] = revision;
    if (branch != null) {
      json['branch'] = branch;
    }
    if (tag != null) {
      json['tag'] = tag;
    }
    return json;
  }
}

