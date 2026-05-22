import 'dart:math';

/// Generates a new unique identifier string.
typedef IdGenerator = String Function();

/// Returns an [IdGenerator] that produces incrementing decimal strings
/// (`"0"`, `"1"`, …).
///
/// Intended for tests; not safe for production use across processes.
IdGenerator incrementingIdGenerator() {
  var next = 0;
  return () => '${next++}';
}

/// Returns an [IdGenerator] that produces random RFC 4122 version 4 UUIDs.
IdGenerator uuidV4IdGenerator() {
  final random = Random.secure();
  return () {
    final bytes = List<int>.generate(16, (_) => random.nextInt(256));
    bytes[6] = (bytes[6] & 0x0f) | 0x40;
    bytes[8] = (bytes[8] & 0x3f) | 0x80;
    final hex = bytes.map((b) => b.toRadixString(16).padLeft(2, '0')).join();
    return '${hex.substring(0, 8)}-'
        '${hex.substring(8, 12)}-'
        '${hex.substring(12, 16)}-'
        '${hex.substring(16, 20)}-'
        '${hex.substring(20)}';
  };
}

/// Standard ID generator factories.
final class IdGenerators {
  const IdGenerators._();

  /// Returns an incrementing decimal string generator.
  static IdGenerator incrementing() => incrementingIdGenerator();

  /// Returns an RFC 4122 version 4 UUID generator.
  static IdGenerator uuidV4() => uuidV4IdGenerator();
}
