// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [JavaStackTraceElement message](https://github.com/cucumber/messages/blob/main/jsonschema/src/JavaStackTraceElement.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class JavaStackTraceElement {
  /// The `className` property.
  final String className;
  /// The `fileName` property.
  final String fileName;
  /// The `methodName` property.
  final String methodName;

  /// Creates an instance of [JavaStackTraceElement].
  const JavaStackTraceElement({
    required this.className,
    required this.fileName,
    required this.methodName,
  });

  /// Creates an instance of [JavaStackTraceElement] from a JSON object.
  factory JavaStackTraceElement.fromJson(Map<String, Object?> json) {
    return JavaStackTraceElement(
      className: _requireJsonString(json, 'className'),
      fileName: _requireJsonString(json, 'fileName'),
      methodName: _requireJsonString(json, 'methodName'),
    );
  }

  /// Converts this [JavaStackTraceElement] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['className'] = className;
    json['fileName'] = fileName;
    json['methodName'] = methodName;
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is JavaStackTraceElement &&
          runtimeType == other.runtimeType &&
          className == other.className &&
          fileName == other.fileName &&
          methodName == other.methodName;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        className,
        fileName,
        methodName,
      ]);

  @override
  String toString() =>
      'JavaStackTraceElement{className: ${className}, fileName: ${fileName}, methodName: ${methodName}}';

  /// Creates a copy of this [JavaStackTraceElement] with the given fields
  /// replaced by the given values. Fields left unspecified keep their current
  /// value.
  JavaStackTraceElement copyWith({
    String? className,
    String? fileName,
    String? methodName,
  }) {
    return JavaStackTraceElement(
      className: className ?? this.className,
      fileName: fileName ?? this.fileName,
      methodName: methodName ?? this.methodName,
    );
  }
}

