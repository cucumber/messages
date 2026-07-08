# Contributing

If you want to make changes to the C++ codegen then it's preferred to use the supplied devcontainer. If you wish to not use a devcontainer you'll have to have recent (C++17 compatible) compiler, cmake and preferably Ninja.

To generate files you will need to install Ruby in the container or in your development environment.

If you need some advice, drop into the `#committers-cpp` channel on the [Cucumber Discord](https://cucumber.io/docs/community/get-in-touch#discord) and ask.

## Generating code

```shell
make clean generate
```

## Building

Building can be done by using the host workflow.

```cmake
cmake --workflow host
```

## Tests

Tests are automatically generated from the `/testdata` folder. Building and running tests can be done using the `test` workflow:

```cmake
cmake --workflow test
```


This requires various tooling to be installed on your computer, including Ruby and Node.js.

## Codestyle, rules and recommendations

Follow the supplied `.clang-tidy` and `.clang-format` rules. Prefer to use an environment with clangd. Clangd is setup to follow Include What You Use.

As for IWYU there is an exception: `nlohmann/json.hpp` should _not_ be included in any public header. This avoids unnecessary long compilation times. (`json.hpp` is very large). For headers use `nlohmann/json_fwd.hpp` instead.
