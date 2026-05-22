// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.

part of 'messages.dart';

class ExternalAttachment {
  final String url;
  final String mediaType;
  final String? testCaseStartedId;
  final String? testStepId;
  final String? testRunHookStartedId;
  final Timestamp? timestamp;

  const ExternalAttachment({
    this.url = '',
    this.mediaType = '',
    this.testCaseStartedId,
    this.testStepId,
    this.testRunHookStartedId,
    this.timestamp,
  });

  factory ExternalAttachment.fromJson(Map<String, Object?> json) {
    return ExternalAttachment(
      url: json['url'] as String? ?? '',
      mediaType: json['mediaType'] as String? ?? '',
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
}

