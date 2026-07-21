// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [Suggestion message](https://github.com/cucumber/messages/blob/main/jsonschema/src/Suggestion.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// A suggested fragment of code to implement an undefined step
class Suggestion {
  /// A unique id for this suggestion
  final String id;
  /// The ID of the `PickleStep` this `Suggestion` was created for.
  final String pickleStepId;
  /// A collection of code snippets that could implement the undefined step
  final List<Snippet> snippets;

  /// Creates an instance of [Suggestion].
  const Suggestion({
    required this.id,
    required this.pickleStepId,
    required this.snippets,
  });

  /// Creates an instance of [Suggestion] from a JSON object.
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

  /// Converts this [Suggestion] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['id'] = id;
    json['pickleStepId'] = pickleStepId;
    json['snippets'] = snippets.map((item) => item.toJson()).toList();
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is Suggestion &&
          runtimeType == other.runtimeType &&
          id == other.id &&
          pickleStepId == other.pickleStepId &&
          _listEquals(snippets, other.snippets);

  @override
  int get hashCode => Object.hashAll(<Object?>[
        id,
        pickleStepId,
        Object.hashAll(snippets),
      ]);

  @override
  String toString() =>
      'Suggestion{id: $id, pickleStepId: $pickleStepId, snippets: $snippets}';
}

