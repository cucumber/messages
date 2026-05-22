import 'package:cucumber_messages/cucumber_messages.dart';
import 'package:test/test.dart';

void main() {
  test('throws when deserializing JSON with missing required fields', () {
    const json = '''
{
  "gherkinDocument": {
    "feature": {
      "children": [
        {
          "scenario": {
            "id": "1",
            "keyword": "Scenario",
            "location": {"column": 3, "line": 3},
            "name": "minimalistic",
            "steps": [
              {
                "id": "0",
                "keyword": "Given ",
                "keywordType": "Context",
                "location": {"column": 5, "line": 4},
                "text": "the minimalism"
              }
            ]
          }
        }
      ],
      "keyword": "Feature",
      "language": "en",
      "location": {"column": 1, "line": 1},
      "name": "Minimal"
    },
    "uri": "testdata/good/minimal.feature"
  }
}
''';

    expect(
      () => parseEnvelopeJson(json),
      throwsA(
        isA<SchemaViolationException>().having(
          (error) => error.message,
          'message',
          contains("Property 'tags' is required but was not found"),
        ),
      ),
    );
  });
}
