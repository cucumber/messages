import json
from pathlib import Path

from pytest import mark, param

from cucumber_messages import Envelope

resource_path = Path(__file__).parent.absolute()


@mark.parametrize(
    "ast_path",
    map(
        lambda file: param(file, id=file.name),  # type: ignore[no-any-return]
        resource_path.rglob("*.ndjson"),
    ),
)
def test_simple_load_model(ast_path: Path):
    with ast_path.open(mode="r") as ast_file:
        for ast_line in ast_file:
            model_datum = json.loads(ast_line)
            model = Envelope.model_validate(model_datum)  # type: ignore[attr-defined]

            assert isinstance(model, Envelope)

            dumped_ast_datum = json.loads(model.model_dump_json(by_alias=True, exclude_none=True))

            assert model_datum == dumped_ast_datum
