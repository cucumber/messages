// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [Group message](https://github.com/cucumber/messages/blob/main/jsonschema/src/Group.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class Group {
  /// The nested capture groups of an argument.
  /// Absent if the group has no nested capture groups.
  final List<Group>? children;
  /// The `start` property.
  final int? start;
  /// The `value` property.
  final String? value;

  /// Creates an instance of [Group].
  const Group({
    this.children,
    this.start,
    this.value,
  });

  /// Creates an instance of [Group] from a JSON object.
  factory Group.fromJson(Map<String, Object?> json) {
    return Group(
      children: (json['children'] as List<Object?>?)
              ?.map(
                (item) => Group.fromJson(
                  item as Map<String, Object?>,
                ),
              )
              .toList(),
      start: (json['start'] as num?)?.toInt(),
      value: json['value'] as String?,
    );
  }

  /// Converts this [Group] to a JSON object.
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

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is Group &&
          runtimeType == other.runtimeType &&
          _listEquals(children, other.children) &&
          start == other.start &&
          value == other.value;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        (children == null ? null : Object.hashAll(children!)),
        start,
        value,
      ]);

  @override
  String toString() =>
      'Group{children: $children, start: $start, value: $value}';
}

