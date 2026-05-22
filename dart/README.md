# Cucumber Messages for Dart

[Cucumber Messages](https://github.com/cucumber/messages) is a message protocol for
representing results and other information from Cucumber. Messages are defined by
[JSON Schema](https://github.com/cucumber/messages/tree/main/jsonschema) and encoded
as [NDJSON](https://github.com/cucumber/messages#encoding) in message streams.

This package provides generated Dart types for every message, plus helpers for NDJSON
read/write, timestamps, durations, and ID generation.

## Requirements

* Dart SDK `>=3.5.0 <4.0.0`

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

await for (final envelope in readNdjsonLines(lines)) {
  // Do something with envelope
}
```

You can also parse a single JSON string:

```dart
final envelope = parseEnvelope(json);
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

final jsonLine = envelopeToJson(envelope);

await for (final line in writeNdjsonLines(Stream.value(envelope))) {
  // Write line to a file or stdout
}
```

See [example/lib/main.dart](example/lib/main.dart) and the unit tests for more examples.

## Versioning

Package versions follow the [messages protocol version](https://github.com/cucumber/messages/releases)
used across language bindings in this repository (for example, Go module `v32` and Python
`32.x`). The Dart binding is currently at `0.0.1` as its initial release; future versions
will align with the shared protocol version when the Dart package joins the polyglot release
process.

See [CHANGELOG.md](CHANGELOG.md) for release notes.

## Development

From the `dart/` directory:

```sh
make generate   # requires Ruby; regenerates lib/src/*.g.dart from JSON schemas
dart pub get
dart format .
dart analyze
dart test
dart pub publish --dry-run
```

Acceptance tests under `test/acceptance/` read fixtures from `../testdata/` in the
monorepo and are excluded from the published package.

For the full multi-language workflow, see the repository root [README](../README.md).
