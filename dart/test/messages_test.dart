import 'package:cucumber_messages/cucumber_messages.dart';
import 'package:test/test.dart';

void main() {
  test('defaults missing fields when deserializing from JSON', () {
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

    final envelope = parseEnvelope(json);
    expect(envelope.gherkinDocument?.comments, isEmpty);
    expect(envelope.gherkinDocument?.feature?.description, '');
    expect(envelope.gherkinDocument?.feature?.tags, isEmpty);
    expect(
      envelope.gherkinDocument?.feature?.children.first.scenario?.examples,
      isEmpty,
    );
    expect(
      envelope.gherkinDocument?.feature?.children.first.scenario?.description,
      '',
    );
    expect(
      envelope.gherkinDocument?.feature?.children.first.scenario?.tags,
      isEmpty,
    );
  });
}
