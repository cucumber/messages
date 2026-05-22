// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class SourceReference {
  final String? uri;
  final JavaMethod? javaMethod;
  final JavaStackTraceElement? javaStackTraceElement;
  final Location? location;

  const SourceReference({
    this.uri,
    this.javaMethod,
    this.javaStackTraceElement,
    this.location,
  });

  factory SourceReference.fromJson(Map<String, Object?> json) {
    return SourceReference(
      uri: json['uri'] as String?,
      javaMethod: json['javaMethod'] == null
          ? null
          : JavaMethod.fromJson(json['javaMethod'] as Map<String, Object?>),
      javaStackTraceElement: json['javaStackTraceElement'] == null
          ? null
          : JavaStackTraceElement.fromJson(
              json['javaStackTraceElement'] as Map<String, Object?>,
            ),
      location: json['location'] == null
          ? null
          : Location.fromJson(json['location'] as Map<String, Object?>),
    );
  }

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
}
