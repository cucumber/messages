// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

enum SourceMediaType {
  textXCucumberGherkinPlain('text/x.cucumber.gherkin+plain'),
  textXCucumberGherkinMarkdown('text/x.cucumber.gherkin+markdown'),
  ;

  const SourceMediaType(this.value);
  final String value;

  static SourceMediaType fromValue(String value) => values.firstWhere((v) => v.value == value);
}

class Source {
  final String uri;
  final String data;
  final SourceMediaType mediaType;

  const Source({
    required this.uri,
    required this.data,
    required this.mediaType,
  });

  factory Source.fromJson(Map<String, Object?> json) {
    return Source(
      uri: _requireJsonString(json, 'uri'),
      data: _requireJsonString(json, 'data'),
      mediaType: SourceMediaType.fromValue(
              _requireJsonString(json, 'mediaType'),
            ),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['uri'] = uri;
    json['data'] = data;
    json['mediaType'] = mediaType.value;
    return json;
  }
}

