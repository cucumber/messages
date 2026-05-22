// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.

part of 'messages.dart';

class Ci {
  final String name;
  final String? url;
  final String? buildNumber;
  final Git? git;

  const Ci({
    this.name = '',
    this.url,
    this.buildNumber,
    this.git,
  });

  factory Ci.fromJson(Map<String, Object?> json) {
    return Ci(
      name: json['name'] as String? ?? '',
      url: json['url'] as String?,
      buildNumber: json['buildNumber'] as String?,
      git: json['git'] == null
          ? null
          : Git.fromJson(
              json['git'] as Map<String, Object?>,
            ),
    );
  }

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
}

