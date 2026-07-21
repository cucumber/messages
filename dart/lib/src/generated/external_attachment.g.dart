// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.g.dart';

/// Generated Dart representation of the [ExternalAttachment message](https://github.com/cucumber/messages/blob/main/jsonschema/src/ExternalAttachment.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// Represents an attachment that is stored externally rather than embedded in the message stream.
///
/// This message type is used for large attachments (e.g., video files) that are already
/// on the filesystem and should not be loaded into memory. Instead of embedding the content,
/// only a URL reference is stored.
///
/// A formatter or other consumer of messages may replace an Attachment with an ExternalAttachment if it makes sense to do so.
class ExternalAttachment {
  /// A URL where the attachment can be retrieved. This could be a file:// URL for
  /// local filesystem paths, or an http(s):// URL for remote resources.
  final String url;
  /// The media type of the data. This can be any valid
  /// [IANA Media Type](https://www.iana.org/assignments/media-types/media-types.xhtml)
  /// as well as Cucumber-specific media types such as `text/x.cucumber.gherkin+plain`
  /// and `text/x.cucumber.stacktrace+plain`
  final String mediaType;
  /// The identifier of the test case attempt if the attachment was created during the execution of a test step
  final String? testCaseStartedId;
  /// The identifier of the test step if the attachment was created during the execution of a test step
  final String? testStepId;
  /// The identifier of the test run hook execution if the attachment was created during the execution of a test run hook
  final String? testRunHookStartedId;
  /// When the attachment was created
  final Timestamp? timestamp;

  /// Creates an instance of [ExternalAttachment].
  const ExternalAttachment({
    required this.url,
    required this.mediaType,
    this.testCaseStartedId,
    this.testStepId,
    this.testRunHookStartedId,
    this.timestamp,
  });

  /// Creates an instance of [ExternalAttachment] from a JSON object.
  factory ExternalAttachment.fromJson(Map<String, Object?> json) {
    return ExternalAttachment(
      url: _requireJsonString(json, 'url'),
      mediaType: _requireJsonString(json, 'mediaType'),
      testCaseStartedId: json['testCaseStartedId'] as String?,
      testStepId: json['testStepId'] as String?,
      testRunHookStartedId: json['testRunHookStartedId'] as String?,
      timestamp: json['timestamp'] == null
          ? null
          : Timestamp.fromJson(
              json['timestamp'] as Map<String, Object?>,
            ),
    );
  }

  /// Converts this [ExternalAttachment] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['url'] = url;
    json['mediaType'] = mediaType;
    if (testCaseStartedId != null) {
      json['testCaseStartedId'] = testCaseStartedId;
    }
    if (testStepId != null) {
      json['testStepId'] = testStepId;
    }
    if (testRunHookStartedId != null) {
      json['testRunHookStartedId'] = testRunHookStartedId;
    }
    if (timestamp != null) {
      json['timestamp'] = timestamp!.toJson();
    }
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is ExternalAttachment &&
          runtimeType == other.runtimeType &&
          url == other.url &&
          mediaType == other.mediaType &&
          testCaseStartedId == other.testCaseStartedId &&
          testStepId == other.testStepId &&
          testRunHookStartedId == other.testRunHookStartedId &&
          timestamp == other.timestamp;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        url,
        mediaType,
        testCaseStartedId,
        testStepId,
        testRunHookStartedId,
        timestamp,
      ]);

  @override
  String toString() =>
      'ExternalAttachment{url: $url, mediaType: $mediaType, testCaseStartedId: $testCaseStartedId, testStepId: $testStepId, testRunHookStartedId: $testRunHookStartedId, timestamp: $timestamp}';
}

