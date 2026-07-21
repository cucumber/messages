# Cucumber Messages for Dart

[![pub package](https://img.shields.io/pub/v/cucumber_messages.svg)](https://pub.dev/packages/cucumber_messages)

[Cucumber Messages](https://github.com/cucumber/messages) is a message protocol for
representing results and other information from Cucumber. Messages are defined by
[JSON Schema](https://github.com/cucumber/messages/tree/main/jsonschema) and encoded
as [NDJSON](https://github.com/cucumber/messages#encoding) in message streams.

This package provides generated Dart types for every message, plus helpers for NDJSON
read/write, timestamps, and durations.

See the [example](https://github.com/cucumber/messages/blob/main/dart/example/main.dart)
for reading and writing message streams.

For general information about Cucumber Messages and the other language implementations, see the repository root [README](https://github.com/cucumber/messages/blob/main//README.md).
