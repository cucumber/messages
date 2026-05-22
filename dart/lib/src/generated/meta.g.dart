// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class Meta {
  final String protocolVersion;
  final Product implementation;
  final Product runtime;
  final Product os;
  final Product cpu;
  final Ci? ci;

  const Meta({
    required this.protocolVersion,
    required this.implementation,
    required this.runtime,
    required this.os,
    required this.cpu,
    this.ci,
  });

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
}

