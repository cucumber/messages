// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

enum SourceMediaType {
  textXCucumberGherkinPlain('text/x.cucumber.gherkin+plain'),
  textXCucumberGherkinMarkdown('text/x.cucumber.gherkin+markdown');

  const SourceMediaType(this.value);
  final String value;

  static SourceMediaType fromValue(String value) =>
      values.firstWhere((v) => v.value == value);
}

class Source {
  final String uri;
  final String data;
  final SourceMediaType mediaType;

  const Source({
    this.uri = '',
    this.data = '',
    this.mediaType = SourceMediaType.textXCucumberGherkinPlain,
  });

  factory Source.fromJson(Map<String, Object?> json) {
    return Source(
      uri: json['uri'] as String? ?? '',
      data: json['data'] as String? ?? '',
      mediaType: json['mediaType'] == null
          ? SourceMediaType.textXCucumberGherkinPlain
          : SourceMediaType.fromValue(json['mediaType'] as String),
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
