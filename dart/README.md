# Cucumber Messages for Dart

[Cucumber Messages](https://github.com/cucumber/messages) is a message protocol for
representing results and other information from Cucumber. Messages are defined by
[JSON Schema](https://github.com/cucumber/messages/tree/main/jsonschema) and encoded
as [NDJSON](https://github.com/cucumber/messages#encoding) in message streams.

This package provides generated Dart types for every message, plus helpers for NDJSON
read/write, timestamps, durations, and an `IdGenerator` interface for callers.

## Requirements

* Dart SDK `>=3.7.0 <4.0.0`

## Installation

From the Git repository (monorepo subdirectory):

```yaml
dependencies:
  cucumber_messages:
    git:
      url: https://github.com/cucumber/messages.git
      path: dart
```

When published to [pub.dev](https://pub.dev/packages/cucumber_messages), add:

```yaml
dependencies:
  cucumber_messages: ^0.0.1
```

Import the public API from the package root:

```dart
import 'package:cucumber_messages/cucumber_messages.dart';
```

Do not import from `package:cucumber_messages/src/...`; files under `lib/src/` are
implementation details and may change without notice.

### Name collisions with `dart:core`

This package exports Cucumber message types named `Duration` and `Exception`, which
shadow the same names from `dart:core`. If you use both in the same library, hide the
message types or use a prefix import:

```dart
import 'package:cucumber_messages/cucumber_messages.dart' hide Duration, Exception;
```

```dart
import 'package:cucumber_messages/cucumber_messages.dart' as messages;

final duration = messages.Duration(seconds: 1, nanos: 0);
```

The time conversion helpers (`durationToDurationMessage`, `durationMessageToDuration`,
and so on) accept and return Cucumber message types; use a prefix import or `hide
Duration` when you also need Dart's core `Duration`.

## Reading

```dart
import 'dart:convert';
import 'dart:io';

import 'package:cucumber_messages/cucumber_messages.dart';

final file = File('messages.ndjson');
final lines = file
    .openRead()
    .transform(utf8.decoder)
    .transform(const LineSplitter());

await for (final envelope in decodeNdjsonEnvelopes(lines)) {
  // Do something with envelope
}
```

You can also parse a single JSON string:

```dart
final envelope = parseEnvelopeJson(json);
```

## Writing

```dart
import 'package:cucumber_messages/cucumber_messages.dart';

final envelope = Envelope(
  attachment: Attachment(
    body: 'Hello',
    contentEncoding: AttachmentContentEncoding.identity,
    mediaType: 'text/plain',
  ),
);

final jsonLine = envelopeToJsonString(envelope);

await for (final line in encodeNdjsonEnvelopes(Stream.value(envelope))) {
  // Write line to a file or stdout
}
```

See [example/lib/main.dart](example/lib/main.dart) and the unit tests for more examples.

## Versioning

Package versions track the [messages protocol version](https://github.com/cucumber/messages/releases)
used across language bindings in this repository (for example, Go module `v32` and Python
`32.x`).

Current policy:

- While the Dart package is pre-`1.0.0`, releases may use bridge versions to keep
  compatibility while release automation is being finalized.
- Once the Dart package is included in the polyglot release process, the published
  package version will align with the shared protocol major.
- Any version bump must include a matching entry in the repository root [CHANGELOG.md](../CHANGELOG.md).

See the repository root [CHANGELOG.md](../CHANGELOG.md) for release notes.

## Development

From the `dart/` directory:

```sh
make generate   # requires Ruby; regenerates lib/src/generated/ from JSON schemas
dart pub get
dart format .
dart analyze
dart test
dart pub publish --dry-run
dart run benchmark/ndjson_benchmark.dart
```

## Performance

Run a quick local throughput benchmark for envelope parsing and NDJSON read/write:

```sh
dart run benchmark/ndjson_benchmark.dart
```

This benchmark is intended for regression checks across commits, not cross-machine
comparisons.

Acceptance tests under `test/acceptance/` read fixtures from `../testdata/` in the
monorepo and are excluded from the published package.

For the full multi-language workflow, see the repository root [README](../README.md).
