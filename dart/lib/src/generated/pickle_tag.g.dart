// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class PickleTag {
  final String name;
  final String astNodeId;

  const PickleTag({
    required this.name,
    required this.astNodeId,
  });

  factory PickleTag.fromJson(Map<String, Object?> json) {
    return PickleTag(
      name: _requireJsonString(json, 'name'),
      astNodeId: _requireJsonString(json, 'astNodeId'),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['name'] = name;
    json['astNodeId'] = astNodeId;
    return json;
  }
}

