import json
from pathlib import Path

from pytest import mark

from cucumber_messages import (
    Ci,
    Duration,
    Envelope,
    ExpressionType,
    Feature,
    FeatureChild,
    GherkinDocument,
    Git,
    Group,
    KeywordType,
    Location,
    MediaType,
    Meta,
    Pickle,
    PickleStep,
    Product,
    Scenario,
    Source,
    SourceReference,
    Status,
    Step,
    StepDefinition,
    StepDefinitionPattern,
    StepMatchArgument,
    StepMatchArgumentsList,
    TestCase,
    TestCaseFinished,
    TestCaseStarted,
    TestRunFinished,
    TestRunStarted,
    TestStep,
    TestStepFinished,
    TestStepResult,
    TestStepStarted,
    Timestamp,
    Type,
)

resource_path = Path(__file__).parent.absolute() / "data"

with (resource_path / "message_samples/minimal/minimal.feature.ndjson").open(mode="r") as ast_file:
    model_data = [*map(json.loads, ast_file)]
oracle_models = [
    Envelope(
        meta=Meta(
            protocol_version="22.0.0",
            implementation=Product(name="fake-cucumber", version="16.3.0"),
            runtime=Product(name="node.js", version="19.7.0"),
            os=Product(name="darwin", version="22.4.0"),
            cpu=Product(name="x64", version=None),
            ci=Ci(
                name="GitHub Actions",
                url="https://github.com/cucumber-ltd/shouty.rb/actions/runs/154666429",
                build_number="154666429",
                git=Git(
                    remote="https://github.com/cucumber-ltd/shouty.rb.git",
                    revision="99684bcacf01d95875834d87903dcb072306c9ad",
                    tag=None,
                ),
            ),
        ),
        undefined_parameter_type=None,
    ),
    Envelope(
        source=Source(
            uri="samples/minimal/minimal.feature",
            data="Feature: minimal\n  \n  Cucumber doesn't execute this markdown, but @cucumber/react renders it\n  \n  * This is\n  * a bullet\n  * list\n  \n  Scenario: cukes\n    Given I have 42 cukes in my belly\n",
            media_type=MediaType.text_x_cucumber_gherkin_plain,
        ),
        undefined_parameter_type=None,
    ),
    Envelope(
        gherkin_document=GherkinDocument(
            uri="samples/minimal/minimal.feature",
            feature=Feature(
                location=Location(line=1, column=1),
                tags=[],
                language="en",
                keyword="Feature",
                name="minimal",
                description="  Cucumber doesn't execute this markdown, but @cucumber/react renders it\n  \n  * This is\n  * a bullet\n  * list",
                children=[
                    FeatureChild(
                        scenario=Scenario(
                            location=Location(line=9, column=3),
                            tags=[],
                            keyword="Scenario",
                            name="cukes",
                            description="",
                            steps=[
                                Step(
                                    location=Location(line=10, column=5),
                                    keyword="Given ",
                                    keyword_type=KeywordType.context,
                                    text="I have 42 cukes in my belly",
                                    id="1",
                                )
                            ],
                            examples=[],
                            id="2",
                        )
                    )
                ],
            ),
            comments=[],
        ),
        undefined_parameter_type=None,
    ),
    Envelope(
        pickle=Pickle(
            id="4",
            uri="samples/minimal/minimal.feature",
            name="cukes",
            language="en",
            steps=[PickleStep(ast_node_ids=["1"], id="3", type=Type.context, text="I have 42 cukes in my belly")],
            tags=[],
            ast_node_ids=["2"],
        ),
        undefined_parameter_type=None,
    ),
    Envelope(
        step_definition=StepDefinition(
            id="0",
            pattern=StepDefinitionPattern(
                source="I have {int} cukes in my belly", type=ExpressionType.cucumber_expression
            ),
            source_reference=SourceReference(
                uri="samples/minimal/minimal.feature.ts", location=Location(line=4, column=None)
            ),
        ),
        undefined_parameter_type=None,
    ),
    Envelope(test_run_started=TestRunStarted(timestamp=Timestamp(seconds=0, nanos=0)), undefined_parameter_type=None),
    Envelope(
        test_case=TestCase(
            id="6",
            pickle_id="4",
            test_steps=[
                TestStep(
                    id="5",
                    pickle_step_id="3",
                    step_definition_ids=["0"],
                    step_match_arguments_lists=[
                        StepMatchArgumentsList(
                            step_match_arguments=[
                                StepMatchArgument(
                                    group=Group(children=[], start=7, value="42"), parameter_type_name="int"
                                )
                            ]
                        )
                    ],
                )
            ],
        ),
        undefined_parameter_type=None,
    ),
    Envelope(
        test_case_started=TestCaseStarted(
            attempt=0, id="7", test_case_id="6", timestamp=Timestamp(seconds=0, nanos=1000000)
        ),
        undefined_parameter_type=None,
    ),
    Envelope(
        test_step_started=TestStepStarted(
            test_case_started_id="7", test_step_id="5", timestamp=Timestamp(seconds=0, nanos=2000000)
        ),
        undefined_parameter_type=None,
    ),
    Envelope(
        test_step_finished=TestStepFinished(
            test_case_started_id="7",
            test_step_id="5",
            test_step_result=TestStepResult(
                duration=Duration(seconds=0, nanos=1000000), status=Status.passed, exception=None
            ),
            timestamp=Timestamp(seconds=0, nanos=3000000),
        ),
        undefined_parameter_type=None,
    ),
    Envelope(
        test_case_finished=TestCaseFinished(
            test_case_started_id="7", timestamp=Timestamp(seconds=0, nanos=4000000), will_be_retried=False
        ),
        undefined_parameter_type=None,
    ),
    Envelope(
        test_run_finished=TestRunFinished(success=True, timestamp=Timestamp(seconds=0, nanos=5000000), exception=None),
        undefined_parameter_type=None,
    ),
]


@mark.parametrize("model_datum, oracle_model", zip(model_data, oracle_models))
def test_simple_load_model(model_datum, oracle_model):
    model = Envelope.model_validate(model_datum)  # type: ignore[attr-defined]

    assert isinstance(model, Envelope)
    assert oracle_model == model

    dumped_ast_datum = json.loads(oracle_model.model_dump_json(by_alias=True, exclude_none=True))

    assert model_datum == dumped_ast_datum
