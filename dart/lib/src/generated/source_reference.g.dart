// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [SourceReference message](https://github.com/cucumber/messages/blob/main/jsonschema/src/SourceReference.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// Points to a [Source](#io.cucumber.messages.Source) identified by `uri` and a
/// [Location](#io.cucumber.messages.Location) within that file.
class SourceReference {
  /// The `uri` property.
  final String? uri;
  /// The `javaMethod` property.
  final JavaMethod? javaMethod;
  /// The `javaStackTraceElement` property.
  final JavaStackTraceElement? javaStackTraceElement;
  /// The `location` property.
  final Location? location;

  /// Creates an instance of [SourceReference].
  const SourceReference({
    this.uri,
    this.javaMethod,
    this.javaStackTraceElement,
    this.location,
  });

  /// Creates an instance of [SourceReference] from a JSON object.
  factory SourceReference.fromJson(Map<String, Object?> json) {
    return SourceReference(
      uri: json['uri'] as String?,
      javaMethod: json['javaMethod'] == null
          ? null
          : JavaMethod.fromJson(
              json['javaMethod'] as Map<String, Object?>,
            ),
      javaStackTraceElement: json['javaStackTraceElement'] == null
          ? null
          : JavaStackTraceElement.fromJson(
              json['javaStackTraceElement'] as Map<String, Object?>,
            ),
      location: json['location'] == null
          ? null
          : Location.fromJson(
              json['location'] as Map<String, Object?>,
            ),
    );
  }

  /// Converts this [SourceReference] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    if (uri != null) {
      json['uri'] = uri;
    }
    if (javaMethod != null) {
      json['javaMethod'] = javaMethod!.toJson();
    }
    if (javaStackTraceElement != null) {
      json['javaStackTraceElement'] = javaStackTraceElement!.toJson();
    }
    if (location != null) {
      json['location'] = location!.toJson();
    }
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is SourceReference &&
          runtimeType == other.runtimeType &&
          uri == other.uri &&
          javaMethod == other.javaMethod &&
          javaStackTraceElement == other.javaStackTraceElement &&
          location == other.location;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        uri,
        javaMethod,
        javaStackTraceElement,
        location,
      ]);

  @override
  String toString() =>
      'SourceReference{uri: ${uri}, javaMethod: ${javaMethod}, javaStackTraceElement: ${javaStackTraceElement}, location: ${location}}';
}

