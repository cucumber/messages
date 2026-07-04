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

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is Git &&
          runtimeType == other.runtimeType &&
          remote == other.remote &&
          revision == other.revision &&
          branch == other.branch &&
          tag == other.tag;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        remote,
        revision,
        branch,
        tag,
      ]);

  @override
  String toString() =>
      'Git{remote: ${remote}, revision: ${revision}, branch: ${branch}, tag: ${tag}}';

  /// Creates a copy of this [Git] with the given fields
  /// replaced by the given values. Fields left unspecified keep their current
  /// value.
  Git copyWith({
    String? remote,
    String? revision,
    String? branch,
    String? tag,
  }) {
    return Git(
      remote: remote ?? this.remote,
      revision: revision ?? this.revision,
      branch: branch ?? this.branch,
      tag: tag ?? this.tag,
    );
  }
}

