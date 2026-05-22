// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

enum AttachmentContentEncoding {
  identity('IDENTITY'),
  base64('BASE64'),
  ;

  const AttachmentContentEncoding(this.value);
  final String value;

  static AttachmentContentEncoding fromValue(String value) => values.firstWhere((v) => v.value == value);
}

class Attachment {
  final String body;
  final AttachmentContentEncoding contentEncoding;
  final String? fileName;
  final String mediaType;
  final Source? source;
  final String? testCaseStartedId;
  final String? testStepId;
  final String? url;
  final String? testRunStartedId;
  final String? testRunHookStartedId;
  final Timestamp? timestamp;

  const Attachment({
    this.body = '',
    this.contentEncoding = AttachmentContentEncoding.identity,
    this.fileName,
    this.mediaType = '',
    this.source,
    this.testCaseStartedId,
    this.testStepId,
    this.url,
    this.testRunStartedId,
    this.testRunHookStartedId,
    this.timestamp,
  });

  factory Attachment.fromJson(Map<String, Object?> json) {
    return Attachment(
      body: json['body'] as String? ?? '',
      contentEncoding: json['contentEncoding'] == null
          ? AttachmentContentEncoding.identity
          : AttachmentContentEncoding.fromValue(
              json['contentEncoding'] as String,
            ),
      fileName: json['fileName'] as String?,
      mediaType: json['mediaType'] as String? ?? '',
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

