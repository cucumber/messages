import json
import re
from pathlib import Path

from git import Repo
from packaging import version
from pytest import fixture

from cucumber_messages import Envelope, message_converter


@fixture
def compatibility_kit_repo(tmpdir):
    repo_path = Path(tmpdir) / "compatibility-kit"
    repo = Repo.clone_from(
        "https://github.com/cucumber/compatibility-kit.git",
        str(repo_path),
        branch="main",
    )
    repo_tags = [getattr(tag.tag, "tag", None) for tag in repo.tags if getattr(tag.tag, "tag", None) is not None]

    version_pattern = re.compile(r"((.*/)?)v(\d+\.\d+\.\d+)")
    last_version = sorted(
        [
            version.parse(match.groups()[-1])
            for tag in repo_tags
            if (match := re.match(version_pattern, tag)) is not None
        ],
    )[-1]

    last_version_tag = next(filter(lambda tag: re.search(re.escape(str(last_version)), tag), repo_tags))

    repo.git.checkout(last_version_tag)

    return repo_path


# Analog of "ruby/spec/cucumber/messages/acceptance_spec.rb" test
def test_simple_load_model(compatibility_kit_repo):
    for ast_path in (compatibility_kit_repo / "devkit" / "samples").rglob("*.ndjson"):
        print(f"Checking ${ast_path}")
        with ast_path.open(mode="r") as ast_file:
            for ast_line in ast_file:
                model_datum = json.loads(ast_line)
                model = message_converter.from_dict(model_datum, Envelope)

                assert isinstance(model, Envelope)

                dumped_ast_datum = message_converter.to_dict(model)

                assert model_datum == dumped_ast_datum
