// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class Meta {
  final String protocolVersion;
  final Product implementation;
  final Product runtime;
  final Product os;
  final Product cpu;
  final Ci? ci;

  const Meta({
    this.protocolVersion = '',
    this.implementation = const Product(),
    this.runtime = const Product(),
    this.os = const Product(),
    this.cpu = const Product(),
    this.ci,
  });

  factory Meta.fromJson(Map<String, Object?> json) {
    return Meta(
      protocolVersion: json['protocolVersion'] as String? ?? '',
      implementation: json['implementation'] == null
          ? const Product()
          : Product.fromJson(json['implementation'] as Map<String, Object?>),
      runtime: json['runtime'] == null
          ? const Product()
          : Product.fromJson(json['runtime'] as Map<String, Object?>),
      os: json['os'] == null
          ? const Product()
          : Product.fromJson(json['os'] as Map<String, Object?>),
      cpu: json['cpu'] == null
          ? const Product()
          : Product.fromJson(json['cpu'] as Map<String, Object?>),
      ci: json['ci'] == null
          ? null
          : Ci.fromJson(json['ci'] as Map<String, Object?>),
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
