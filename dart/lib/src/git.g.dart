// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class Git {
  final String remote;
  final String revision;
  final String? branch;
  final String? tag;

  const Git({
    required this.remote,
    required this.revision,
    this.branch,
    this.tag,
  });

  factory Git.fromJson(Map<String, Object?> json) {
    return Git(
      remote: _requireJsonString(json, 'remote'),
      revision: _requireJsonString(json, 'revision'),
      branch: json['branch'] as String?,
      tag: json['tag'] as String?,
    );
  }

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

