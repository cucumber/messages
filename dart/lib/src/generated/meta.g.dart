// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.g.dart';

/// Generated Dart representation of the [Meta message](https://github.com/cucumber/messages/blob/main/jsonschema/src/Meta.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// This message contains meta information about the environment. Consumers can use
/// this for various purposes.
class Meta {
  /// The [SEMVER](https://semver.org/) version number of the protocol
  final String protocolVersion;
  /// SpecFlow, Cucumber-JVM, Cucumber.js, Cucumber-Ruby, Behat etc.
  final Product implementation;
  /// Java, Ruby, Node.js etc
  final Product runtime;
  /// Windows, Linux, MacOS etc
  final Product os;
  /// 386, arm, amd64 etc
  final Product cpu;
  /// The `ci` property.
  final Ci? ci;

  /// Creates an instance of [Meta].
  const Meta({
    required this.protocolVersion,
    required this.implementation,
    required this.runtime,
    required this.os,
    required this.cpu,
    this.ci,
  });

  /// Creates an instance of [Meta] from a JSON object.
  factory Meta.fromJson(Map<String, Object?> json) {
    return Meta(
      protocolVersion: _requireJsonString(json, 'protocolVersion'),
      implementation: Product.fromJson(
              _requireJsonObject(json, 'implementation'),
            ),
      runtime: Product.fromJson(
              _requireJsonObject(json, 'runtime'),
            ),
      os: Product.fromJson(
              _requireJsonObject(json, 'os'),
            ),
      cpu: Product.fromJson(
              _requireJsonObject(json, 'cpu'),
            ),
      ci: json['ci'] == null
          ? null
          : Ci.fromJson(
              json['ci'] as Map<String, Object?>,
            ),
    );
  }

  /// Converts this [Meta] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['protocolVersion'] = protocolVersion;
    json['implementation'] = implementation.toJson();
    json['runtime'] = runtime.toJson();
    json['os'] = os.toJson();
    json['cpu'] = cpu.toJson();
    if (ci != null) {
      json['ci'] = ci!.toJson();
    }
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is Meta &&
          runtimeType == other.runtimeType &&
          protocolVersion == other.protocolVersion &&
          implementation == other.implementation &&
          runtime == other.runtime &&
          os == other.os &&
          cpu == other.cpu &&
          ci == other.ci;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        protocolVersion,
        implementation,
        runtime,
        os,
        cpu,
        ci,
      ]);

  @override
  String toString() =>
      'Meta{protocolVersion: $protocolVersion, implementation: $implementation, runtime: $runtime, os: $os, cpu: $cpu, ci: $ci}';
}

