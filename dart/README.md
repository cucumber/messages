# Cucumber Messages for Dart (JSON schema)

See main [README](../README.md)

## Requirements

* Dart SDK `>=3.5.0 <4.0.0`

## Installation

Add the dependency from the Git repository:

```yaml
dependencies:
  cucumber_messages:
    git:
      url: https://github.com/cucumber/messages.git
      path: dart
```

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

See unit tests for more examples.
