// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.

part of 'messages.dart';

class Suggestion {
  final String id;
  final String pickleStepId;
  final List<Snippet> snippets;

  const Suggestion({
    this.id = '',
    this.pickleStepId = '',
    this.snippets = const [],
  });

  factory Suggestion.fromJson(Map<String, Object?> json) {
    return Suggestion(
      id: json['id'] as String? ?? '',
      pickleStepId: json['pickleStepId'] as String? ?? '',
      snippets: (json['snippets'] as List<Object?>?)
              ?.map(
                (item) => Snippet.fromJson(
                  item as Map<String, Object?>,
                ),
              )
              .toList() ??
          const [],
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['id'] = id;
    json['pickleStepId'] = pickleStepId;
    json['snippets'] = snippets.map((item) => item.toJson()).toList();
    return json;
  }
}

