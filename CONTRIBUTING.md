# Contributing

If you want to make changes to the schema, start in the `jsonschema` directory where you can edit the JSON files.

Some guidelines for making schema changes:

- Use the most appropriate data type
- Follow existing naming conventions (camelCase)
- Add new fields last to minimise impact on consuming code
- Don't add a new field as `required` - this will make the new code unable to read existing messages
- Ideally add a description to any new fields

If you need some advice, drop into the `#committers` channel on the [Cucumber Discord](https://cucumber.io/docs/community/get-in-touch#discord) and ask.

## Generating code

The code for various languages is generated from the JSON files. You can clean and regenerate the code with:

```shell
make clean-all generate-all
```

Or you can alternative clean and generate code for just one language by cd'ing into that languages directory
and then running the following commands

```shell
cd ruby # Or another alternative
make clean generate
```

This requires various tooling to be installed on your computer, including Ruby and Node.js.

### New files

If you're adding a new file to the `jsonschema` directory, you'll need to add a reference to it near the top of the `Makefile`
at the root in order for it to be included in the code generation.

## Tests

Some of the language-specific directories contain some smoke tests to ensure (de)serialization, validation etc
are working right. If you happen to change one of the messages that's constructed by these tests, you may
need to update them. If you're not sure, raise a draft PR and see what happens in CI.
