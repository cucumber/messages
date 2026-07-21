// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.g.dart';

/// Generated Dart representation of the [Ci message](https://github.com/cucumber/messages/blob/main/jsonschema/src/Ci.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// CI environment
class Ci {
  /// Name of the CI product, e.g. "Jenkins", "CircleCI" etc.
  final String name;
  /// Link to the build
  final String? url;
  /// The build number. Some CI servers use non-numeric build numbers, which is why this is a string
  final String? buildNumber;
  /// The `git` property.
  final Git? git;

  /// Creates an instance of [Ci].
  const Ci({
    required this.name,
    this.url,
    this.buildNumber,
    this.git,
  });

  /// Creates an instance of [Ci] from a JSON object.
  factory Ci.fromJson(Map<String, Object?> json) {
    return Ci(
      name: _requireJsonString(json, 'name'),
      url: json['url'] as String?,
      buildNumber: json['buildNumber'] as String?,
      git: json['git'] == null
          ? null
          : Git.fromJson(
              json['git'] as Map<String, Object?>,
            ),
    );
  }

  /// Converts this [Ci] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['name'] = name;
    if (url != null) {
      json['url'] = url;
    }
    if (buildNumber != null) {
      json['buildNumber'] = buildNumber;
    }
    if (git != null) {
      json['git'] = git!.toJson();
    }
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is Ci &&
          runtimeType == other.runtimeType &&
          name == other.name &&
          url == other.url &&
          buildNumber == other.buildNumber &&
          git == other.git;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        name,
        url,
        buildNumber,
        git,
      ]);

  @override
  String toString() =>
      'Ci{name: $name, url: $url, buildNumber: $buildNumber, git: $git}';
}

