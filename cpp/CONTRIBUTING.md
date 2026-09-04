# Contributing

If you want to make changes to the C++ codegen then it's preferred to use the supplied devcontainer. If you wish to not use a devcontainer you'll have to have recent (C++17 compatible) compiler, cmake and preferably Ninja.

To generate files you will need to install Ruby in the container or in your development environment.

If you need some advice, drop into the `#committers-cpp` channel on the [Cucumber Discord](https://cucumber.io/docs/community/get-in-touch#discord) and ask.

## Generating code

```shell
make clean generate
```

## Building

Install dependencies with Conan, then build using the host workflow.

```shell
conan profile detect --force
conan install . --output-folder=build/host-conan --build=missing -s build_type=Release
cmake --workflow --preset host-conan
```

## Tests

Tests are automatically generated from the `/testdata` folder. Install dependencies and run the test workflow:

```shell
conan profile detect --force
conan install . --output-folder=build/test --build=missing -s build_type=Debug
cmake --workflow --preset test
```

## Local development (automatic Conan)

For local development you can use the `dev` preset, which wires in the
[cmake-conan](https://github.com/conan-io/cmake-conan) dependency provider so
CMake runs `conan install` automatically at configure time. No separate Conan
step is required:

```shell
conan profile detect --force
cmake --workflow --preset dev
```

The `host-conan` and `test` presets deliberately do **not** use the provider; CI
runs an explicit `conan install` for reproducible, profile-pinned builds.

## Building without Conan

If Conan is not available but the C++ dependencies are already installed on the
system, use the `host-system` preset to build and install:

```shell
cmake --workflow --preset host-system
cmake --install build/host-system --config Release
```

## Codestyle, rules and recommendations

Follow the supplied `.clang-tidy` and `.clang-format` rules. Prefer to use an environment with clangd. Clangd is setup to follow Include What You Use.

As for IWYU there is an exception: `nlohmann/json.hpp` should _not_ be included in any public header. This avoids unnecessary long compilation times. (`json.hpp` is very large). For headers use `nlohmann/json_fwd.hpp` instead.
