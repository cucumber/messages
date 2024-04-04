import json
from itertools import chain
from pathlib import Path

from importlib_resources import files
from pytest import mark, param

from messages import Envelope


@mark.parametrize(
    "ast_path",
    map(
        lambda file: param(file, id=file.name),  # type: ignore[no-any-return]
        chain.from_iterable(map(lambda p: p.glob("*.ndjson"), files("messages.samples").iterdir())),
    ),
)
def test_simple_load_model(ast_path: Path):
    with ast_path.open(mode="r") as ast_file:
        for ast_line in ast_file:
            model_datum = json.loads(ast_line)
            model = Envelope.model_validate(model_datum)  # type: ignore[attr-defined]

            assert isinstance(model, Envelope)

            dumped_ast_datum = json.loads(model.model_dump_json(by_alias=True, exclude_none=True))  # type: ignore[attr-defined] # migration to pydantic2

            assert model_datum == dumped_ast_datum
