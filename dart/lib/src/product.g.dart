// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class Product {
  final String name;
  final String? version;

  const Product({this.name = '', this.version});

  factory Product.fromJson(Map<String, Object?> json) {
    return Product(
      name: json['name'] as String? ?? '',
      version: json['version'] as String?,
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['name'] = name;
    if (version != null) {
      json['version'] = version;
    }
    return json;
  }
}
