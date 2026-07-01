// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Whether to interpret `body` "as-is" (IDENTITY) or if it needs to be Base64-decoded (BASE64).
///
/// Content encoding is *not* determined by the media type, but rather by the type
/// of the object being attached:
///
/// - string: IDENTITY
/// - byte array: BASE64
/// - stream: BASE64
enum AttachmentContentEncoding {
  /// The `IDENTITY` value.
  identity('IDENTITY'),
  /// The `BASE64` value.
  base64('BASE64'),
  ;

  /// Creates an instance of [AttachmentContentEncoding] from its wire [value].
  const AttachmentContentEncoding(this.value);

  /// The wire value used in message JSON.
  final String value;

  /// Returns the [AttachmentContentEncoding] matching [value].
  static AttachmentContentEncoding fromValue(String value) => values.firstWhere((v) => v.value == value);
}

/// Generated Dart representation of the [Attachment message](https://github.com/cucumber/messages/blob/main/jsonschema/src/Attachment.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// Attachments (parse errors, execution errors, screenshots, links...)
///
/// An attachment represents any kind of data associated with a line in a
/// [Source](#io.cucumber.messages.Source) file. It can be used for:
///
/// * Syntax errors during parse time
/// * Screenshots captured and attached during execution
/// * Logs captured and attached during execution
///
/// It is not to be used for runtime errors raised/thrown during execution. This
/// is captured in `TestResult`.
class Attachment {
  /// The body of the attachment. If `contentEncoding` is `IDENTITY`, the attachment
  /// is simply the string. If it's `BASE64`, the string should be Base64 decoded to
  /// obtain the attachment.
  final String body;
  /// Whether to interpret `body` "as-is" (IDENTITY) or if it needs to be Base64-decoded (BASE64).
  ///
  /// Content encoding is *not* determined by the media type, but rather by the type
  /// of the object being attached:
  ///
  /// - string: IDENTITY
  /// - byte array: BASE64
  /// - stream: BASE64
  final AttachmentContentEncoding contentEncoding;
  /// Suggested file name of the attachment. (Provided by the user as an argument to `attach`)
  final String? fileName;
  /// The media type of the data. This can be any valid
  /// [IANA Media Type](https://www.iana.org/assignments/media-types/media-types.xhtml)
  /// as well as Cucumber-specific media types such as `text/x.cucumber.gherkin+plain`
  /// and `text/x.cucumber.stacktrace+plain`
  final String mediaType;
  /// The `source` property.
  final Source? source;
  /// The identifier of the test case attempt if the attachment was created during the execution of a test step
  final String? testCaseStartedId;
  /// The identifier of the test step if the attachment was created during the execution of a test step
  final String? testStepId;
  /// A URL where the attachment can be retrieved. This field should not be set by Cucumber.
  /// It should be set by a program that reads a message stream and does the following for
  /// each Attachment message:
  ///
  /// - Writes the body (after base64 decoding if necessary) to a new file.
  /// - Sets `body` and `contentEncoding` to `null`
  /// - Writes out the new attachment message
  ///
  /// This will result in a smaller message stream, which can improve performance and
  /// reduce bandwidth of message consumers. It also makes it easier to process and download attachments
  /// separately from reports.
  ///
  /// Deprecated; use ExternalAttachment instead.
  final String? url;
  /// Not used; implementers should instead populate `testRunHookStartedId` if an attachment was created during the execution of a test run hook
  final String? testRunStartedId;
  /// The identifier of the test run hook execution if the attachment was created during the execution of a test run hook
  final String? testRunHookStartedId;
  /// When the attachment was created
  final Timestamp? timestamp;

  /// Creates an instance of [Attachment].
  const Attachment({
    required this.body,
    required this.contentEncoding,
    this.fileName,
    required this.mediaType,
    this.source,
    this.testCaseStartedId,
    this.testStepId,
    this.url,
    this.testRunStartedId,
    this.testRunHookStartedId,
    this.timestamp,
  });

  /// Creates an instance of [Attachment] from a JSON object.
  factory Attachment.fromJson(Map<String, Object?> json) {
    return Attachment(
      body: _requireJsonString(json, 'body'),
      contentEncoding: AttachmentContentEncoding.fromValue(
              _requireJsonString(json, 'contentEncoding'),
            ),
      fileName: json['fileName'] as String?,
      mediaType: _requireJsonString(json, 'mediaType'),
      source: json['source'] == null
          ? null
          : Source.fromJson(
              json['source'] as Map<String, Object?>,
            ),
      testCaseStartedId: json['testCaseStartedId'] as String?,
      testStepId: json['testStepId'] as String?,
      url: json['url'] as String?,
      testRunStartedId: json['testRunStartedId'] as String?,
      testRunHookStartedId: json['testRunHookStartedId'] as String?,
      timestamp: json['timestamp'] == null
          ? null
          : Timestamp.fromJson(
              json['timestamp'] as Map<String, Object?>,
            ),
    );
  }

  /// Converts this [Attachment] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['body'] = body;
    json['contentEncoding'] = contentEncoding.value;
    if (fileName != null) {
      json['fileName'] = fileName;
    }
    json['mediaType'] = mediaType;
    if (source != null) {
      json['source'] = source!.toJson();
    }
    if (testCaseStartedId != null) {
      json['testCaseStartedId'] = testCaseStartedId;
    }
    if (testStepId != null) {
      json['testStepId'] = testStepId;
    }
    if (url != null) {
      json['url'] = url;
    }
    if (testRunStartedId != null) {
      json['testRunStartedId'] = testRunStartedId;
    }
    if (testRunHookStartedId != null) {
      json['testRunHookStartedId'] = testRunHookStartedId;
    }
    if (timestamp != null) {
      json['timestamp'] = timestamp!.toJson();
    }
    return json;
  }
}

