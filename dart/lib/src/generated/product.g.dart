// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Represents the Product message in [Cucumber's message protocol](https://github.com/cucumber/messages).
///
/// Used to describe various properties of Meta
class Product {
  /// The product name
  final String name;
  /// The product version
  final String? version;

  /// Creates an instance of [Product].
  const Product({
    required this.name,
    this.version,
  });

  /// Creates an instance of [Product] from a JSON object.
  factory Product.fromJson(Map<String, Object?> json) {
    return Product(
      name: _requireJsonString(json, 'name'),
      version: json['version'] as String?,
    );
  }

  /// Converts this [Product] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['name'] = name;
    if (version != null) {
      json['version'] = version;
    }
    return json;
  }
}

