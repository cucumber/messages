# Cucumber Messages for Dart

[Cucumber Messages](https://github.com/cucumber/messages) is a message protocol for
representing results and other information from Cucumber. Messages are defined by
[JSON Schema](https://github.com/cucumber/messages/tree/main/jsonschema) and encoded
as [NDJSON](https://github.com/cucumber/messages#encoding) in message streams.

This package provides generated Dart types for every message, plus helpers for NDJSON
read/write, timestamps, and durations.

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
  cucumber_messages: ^<published-version>
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

See the unit tests under [test/](test/) for more examples.

## Development

From the `dart/` directory:

```sh
make generate   # requires Ruby; regenerates lib/src/generated/ from JSON schemas
dart pub get
dart format .
dart analyze
dart test
dart pub publish --dry-run
```

## Acceptance Test Suite

Acceptance tests under `test/acceptance/` read fixtures from `../testdata/` in the
monorepo and are excluded from the published package.

For the full multi-language workflow, see the repository root [README](../README.md).
