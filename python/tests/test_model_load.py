import json
import re
from pathlib import Path

from git import Repo
from packaging import version
from pytest import fixture

from cucumber_messages import Envelope, message_converter


# Analog of "ruby/spec/cucumber/messages/acceptance_spec.rb" test
def test_simple_load_model(compatibility_kit_repo):
    for ast_path in (/".." / "testdata" ).rglob("*.ndjson"):
        print(f"Checking ${ast_path}")
        with ast_path.open(mode="r") as ast_file:
            for ast_line in ast_file:
                model_datum = json.loads(ast_line)
                model = message_converter.from_dict(model_datum, Envelope)

                assert isinstance(model, Envelope)

                dumped_ast_datum = message_converter.to_dict(model)

                assert model_datum == dumped_ast_datum
