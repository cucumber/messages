// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class Group {
  final List<Group>? children;
  final int? start;
  final String? value;

  const Group({this.children, this.start, this.value});

  factory Group.fromJson(Map<String, Object?> json) {
    return Group(
      children:
          (json['children'] as List<Object?>?)
              ?.map((item) => Group.fromJson(item as Map<String, Object?>))
              .toList() ??
          null,
      start: (json['start'] as num?)?.toInt(),
      value: json['value'] as String?,
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    if (children != null) {
      json['children'] = children!.map((item) => item.toJson()).toList();
    }
    if (start != null) {
      json['start'] = start;
    }
    if (value != null) {
      json['value'] = value;
    }
    return json;
  }
}
