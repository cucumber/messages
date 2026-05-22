/// Generates a new unique identifier string.
///
/// Implement this in your application (for example by delegating to a
/// UUID library you already depend on).
// ignore: one_member_abstracts
abstract interface class IdGenerator {
  /// Returns a new unique identifier string.
  String newId();
}
