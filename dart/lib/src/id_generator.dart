/// Generates a new unique identifier string.
///
/// Implement this typedef in your application (for example by delegating to a
/// UUID library you already depend on). The package only ships
/// [incrementingIdGenerator] for tests.
typedef IdGenerator = String Function();

/// Returns an [IdGenerator] that produces incrementing decimal strings
/// (`"0"`, `"1"`, …).
///
/// Intended for tests; not safe for production use across processes.
IdGenerator incrementingIdGenerator() {
  var next = 0;
  return () => '${next++}';
}
