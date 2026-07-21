// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [Snippet message](https://github.com/cucumber/messages/blob/main/jsonschema/src/Snippet.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class Snippet {
  /// The programming language of the code.
  ///
  /// This must be formatted as an all lowercase identifier such that syntax highlighters like [Prism](https://prismjs.com/#supported-languages) or [Highlight.js](https://github.com/highlightjs/highlight.js/blob/main/SUPPORTED_LANGUAGES.md) can recognize it.
  /// For example: `cpp`, `cs`, `go`, `java`, `javascript`, `php`, `python`, `ruby`, `scala`.
  final String language;
  /// A snippet of code
  final String code;

  /// Creates an instance of [Snippet].
  const Snippet({
    required this.language,
    required this.code,
  });

  /// Creates an instance of [Snippet] from a JSON object.
  factory Snippet.fromJson(Map<String, Object?> json) {
    return Snippet(
      language: _requireJsonString(json, 'language'),
      code: _requireJsonString(json, 'code'),
    );
  }

  /// Converts this [Snippet] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['language'] = language;
    json['code'] = code;
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is Snippet &&
          runtimeType == other.runtimeType &&
          language == other.language &&
          code == other.code;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        language,
        code,
      ]);

  @override
  String toString() =>
      'Snippet{language: $language, code: $code}';
}

