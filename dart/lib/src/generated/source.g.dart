// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// The media type of the file. Can be used to specify custom types, such as
/// text/x.cucumber.gherkin+plain
enum SourceMediaType {
  /// The `text/x.cucumber.gherkin+plain` value.
  textXCucumberGherkinPlain('text/x.cucumber.gherkin+plain'),
  /// The `text/x.cucumber.gherkin+markdown` value.
  textXCucumberGherkinMarkdown('text/x.cucumber.gherkin+markdown'),
  ;

  /// Creates an instance of [SourceMediaType] from its wire [value].
  const SourceMediaType(this.value);

  /// The wire value used in message JSON.
  final String value;

  /// Returns the [SourceMediaType] matching [value].
  static SourceMediaType fromValue(String value) => values.firstWhere((v) => v.value == value);
}

/// Generated Dart representation of the [Source message](https://github.com/cucumber/messages/blob/main/jsonschema/src/Source.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// A source file, typically a Gherkin document or Java/Ruby/JavaScript source code
class Source {
  /// The [URI](https://en.wikipedia.org/wiki/Uniform_Resource_Identifier)
  /// of the source, typically a file path relative to the root directory
  final String uri;
  /// The contents of the file
  final String data;
  /// The media type of the file. Can be used to specify custom types, such as
  /// text/x.cucumber.gherkin+plain
  final SourceMediaType mediaType;

  /// Creates an instance of [Source].
  const Source({
    required this.uri,
    required this.data,
    required this.mediaType,
  });

  /// Creates an instance of [Source] from a JSON object.
  factory Source.fromJson(Map<String, Object?> json) {
    return Source(
      uri: _requireJsonString(json, 'uri'),
      data: _requireJsonString(json, 'data'),
      mediaType: SourceMediaType.fromValue(
              _requireJsonString(json, 'mediaType'),
            ),
    );
  }

  /// Converts this [Source] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['uri'] = uri;
    json['data'] = data;
    json['mediaType'] = mediaType.value;
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is Source &&
          runtimeType == other.runtimeType &&
          uri == other.uri &&
          data == other.data &&
          mediaType == other.mediaType;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        uri,
        data,
        mediaType,
      ]);

  @override
  String toString() =>
      'Source{uri: ${uri}, data: ${data}, mediaType: ${mediaType}}';
}

