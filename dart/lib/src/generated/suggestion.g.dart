// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class Suggestion {
  final String id;
  final String pickleStepId;
  final List<Snippet> snippets;

  const Suggestion({
    required this.id,
    required this.pickleStepId,
    required this.snippets,
  });

  factory Suggestion.fromJson(Map<String, Object?> json) {
    return Suggestion(
      id: _requireJsonString(json, 'id'),
      pickleStepId: _requireJsonString(json, 'pickleStepId'),
      snippets: _requireJsonList(json, 'snippets')
              .map(
                (item) => Snippet.fromJson(
                  item as Map<String, Object?>,
                ),
              )
              .toList(),
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

