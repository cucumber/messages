// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class PickleTag {
  final String name;
  final String astNodeId;

  const PickleTag({this.name = '', this.astNodeId = ''});

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
