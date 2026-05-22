// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class PickleTag {
  final String name;
  final String astNodeId;

  const PickleTag({
    this.name = '',
    this.astNodeId = '',
  });

  factory PickleTag.fromJson(Map<String, Object?> json) {
    return PickleTag(
      name: json['name'] as String? ?? '',
      astNodeId: json['astNodeId'] as String? ?? '',
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['name'] = name;
    json['astNodeId'] = astNodeId;
    return json;
  }
}

