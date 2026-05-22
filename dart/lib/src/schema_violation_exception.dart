/// Thrown when JSON does not satisfy the Cucumber message schema.
class SchemaViolationException implements Exception {
  /// Creates a [SchemaViolationException] with the given [message].
  SchemaViolationException(this.message);

  /// A description of the schema violation.
  final String message;

  @override
  String toString() => message;
}
