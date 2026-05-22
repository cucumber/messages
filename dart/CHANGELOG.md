# 0.0.1

- Initial release of `cucumber_messages` for Dart.
- Generated message types from the Cucumber JSON schema (protocol v32).
- NDJSON read/write helpers (`parseEnvelope`, `envelopeToJson`, `readNdjsonLines`, `writeNdjsonLines`).
- Time conversion utilities between Cucumber `Timestamp`/`DurationMessage` and Dart `DateTime`/`Duration`.
- ID generators (`uuid`, `incrementing`).
