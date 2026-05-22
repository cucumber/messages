# 0.0.1

- Initial release of `cucumber_messages` for Dart.
- Generated message types from the Cucumber JSON schema (protocol v32).
- NDJSON read/write helpers (`parseEnvelopeJson`, `envelopeToJsonString`, `decodeNdjsonEnvelopes`, `encodeNdjsonEnvelopes`).
- Time conversion utilities between Cucumber `Timestamp`/`DurationMessage` and Dart `DateTime`/`Duration`.
- ID generators (`uuidV4IdGenerator`, `incrementingIdGenerator`, and `IdGenerators`).
