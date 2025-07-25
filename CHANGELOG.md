# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/)
and this project adheres to [Semantic Versioning](http://semver.org/).

## [Unreleased]

## [28.1.0] - 2025-07-21
### Added
- [java] Add comparators for comparable objects ([#312](https://github.com/cucumber/messages/pull/312))

## [28.0.0] - 2025-07-07
### Changed
- Add `Attachment.testRunHookStartedId` for traceability of attachments to test run hooks ([#301](https://github.com/cucumber/messages/pull/301))
- Add `Attachment.timestamp` ([#305](https://github.com/cucumber/messages/pull/305))

### Fixed
- [python] Add a LICENSE file for Python ([#278](https://github.com/cucumber/messages/pull/278))
- [.NET] Fix NuGet package generation

### Removed
- [JavaScript] BREAKING CHANGE: Remove Node.js 18 support ([#299](https://github.com/cucumber/messages/pull/299))

## [27.2.0] - 2025-01-31
### Added
- [python] Added Python implementation ([#165](https://github.com/cucumber/messages/pull/165))

## [27.1.0] - 2025-01-28
### Added
- [cpp] use VERSION file to version ABI and shared libraries [#268](https://github.com/cucumber/messages/pull/268)

### Changed
- [JavaScript] Expand tested Node.js versions ([#274](https://github.com/cucumber/messages/pull/274))

## [27.0.2] - 2024-11-15
### Fixed
- [Elixir] Fix release process

## [27.0.1] - 2024-11-15
### Fixed
- [Elixir] Restored test and release process

## [27.0.0] - 2024-10-26
### Added
- Add new `TestRunHookStarted` and `TestRunHookFinished` messages ([#102](https://github.com/cucumber/messages/pull/102))

### Changed
- BREAKING CHANGE: Add `id` property to `TestRunStarted`, optionally reference in `TestCase`, `Attachment` and `TestRunFinished` ([#102](https://github.com/cucumber/messages/pull/102))
- BREAKING CHANGE: Add `type` property to `Hook` ([#102](https://github.com/cucumber/messages/pull/102))

## [26.0.1] - 2024-09-22
### Changed
- [Go] Switch to Google's UUID module ([#251](https://github.com/cucumber/messages/pull/251))

### Fixed
- [Dotnet] Fixed code generation for types that accept List as parameters. Constructors were not properly handling null input. ([#249](https://github.com/cucumber/messages/pull/249) [clrudolphi](https://github.com/clrudolphi)))
- Moved contents of the description of the StepDefinitionIds field from the StepMatchArgumentsList field where it had been mistakenly placed. ([#252](https://github.com/cucumber/messages/pull/252) [clrudolphi](https://github.com/clrudolphi)))

## [26.0.0] - 2024-08-15
### Added
- [Dotnet] Added support classes aligned with what is provided for the Java implementation ([#233](https://github.com/cucumber/messages/pull/233) [clrudolphi](https://github.com/clrudolphi))

### Changed
- **Internal breaking change** The code generation has undergone a large refactor (No visible changes expected). All new code
generation logic is now contained in [/codegen](./codegen) ([#228](https://github.com/cucumber/messages/pull/228) [luke-hill](https://github.com/luke-hill))
- [Dotnet] Rewritten to align with the code generation techniques used for the other languages (https://github.com/cucumber/messages/pull/233 [clrudolphi](https://github.com/clrudolphi))
- [Dotnet] Upgraded from .NET 5 to .NET 8. Dropped .NET Framework 4.x as a target while retaining .NET Standard 2.0 as the primary target framework (https://github.com/cucumber/messages/pull/233 [clrudolphi](https://github.com/clrudolphi))

## [25.0.1] - 2024-06-13
### Fixed
- [Php] Fixed a workflow issue with publishing the package

## [25.0.0] - 2024-06-13
### Changed
- [Ruby] Messages are now altered to be 1 message class per file ([#225](https://github.com/cucumber/messages/pull/225) [luke-hill](https://github.com/luke-hill))
- [Ruby] Updated minimum Ruby version to 3.0 ([#216](https://github.com/cucumber/messages/pull/216) [luke-hill](https://github.com/luke-hill))
- [Ruby] Use latest CCK conformance for signing off message releases ([#216](https://github.com/cucumber/messages/pull/216) [luke-hill](https://github.com/luke-hill))
- [Ruby] Tidied up all remaining rubocop offenses (This included 2 minor alterations to the generator code) ([#217](https://github.com/cucumber/messages/pull/217) [#225](https://github.com/cucumber/messages/pull/225) [luke-hill](https://github.com/luke-hill))
- [Php] Permit both PHPUnit 10 and PHPUnit 11 ([#200](https://github.com/cucumber/messages/pull/200) [ciaranmcnulty](https://github.com/ciaranmcnulty))

### Fixed
- [cpp] Don't rely on GitHub API for latest versions and implement a simple download retry loop

## [24.1.0] - 2024-03-23
### Added
- [Java] Include stacktrace in Convertor.toMessage(Throwable) ([#213](https://github.com/cucumber/messages/pull/213))

## [24.0.1] - 2023-12-21
### Fixed
- Update repo URLs ([#190](https://github.com/cucumber/messages/pull/190))

## [24.0.0] - 2023-11-24
### Added
- Add `stackTrace` prop to `Exception` message ([#182](https://github.com/cucumber/messages/pull/182))

## [23.0.0] - 2023-11-01
### Added
- Added C++ implementation ([#152](https://github.com/cucumber/messages/pull/152))

### Changed
- [Ruby] Updated minimum Ruby version to 2.5 ([#177](https://github.com/cucumber/messages/pull/177) [luke-hill](https://github.com/luke-hill))

## [22.0.0] - 2023-04-06
### Added
- Added source reference to parameter type ([#45](https://github.com/cucumber/messages/pull/145))

### Fixed
- Corrected Java and PHP generators to allow running using Docker on Windows ([#146](https://github.com/cucumber/messages/issues/146))

## [21.0.1] - 2022-12-17
### Fixed
- [Java] Suppress warnings for missing javadoc ([#128](https://github.com/cucumber/messages/pull/128))

## [21.0.0] - 2022-12-17
### Added
- [Java] Add javadoc to messages ([#124](https://github.com/cucumber/messages/pull/124))

### Changed
- Add exception to TestStepFinished TestRunFinished ([#122](https://github.com/cucumber/messages/pull/122))

## [20.0.0] - 2022-11-14
### Changed
- Add `workerId` field to TestCaseStarted message ([#34](https://github.com/cucumber/messages/pull/34))
- [Java] Enabled reproducible builds

### Fixed
- Change Go module name to match repo  ([#101](https://github.com/cucumber/messages/pull/101))

## [19.1.4] - 2022-09-22
### Changed
- Update dependencies

## [19.1.3] - 2022-09-20
### Fixed
- Add `name` field to `package.cjs.json` ([#36](https://github.com/cucumber/messages/pull/36))

## [19.1.2] - 2022-06-22
### Fixed
- [Javascript] Schema was still missing in 19.1.1 due to how npm manages the files attribute in package.json
([#2020](https://github.com/cucumber/common/pull/2020))

## [19.1.1] - 2022-06-22
### Fixed
- [Javascript] Schema are actually missing from 19.1.0
([#2016](https://github.com/cucumber/common/pull/2016))

## [19.1.0] - 2022-06-20
### Added
- [Javascript] Adding the json schemas of the messages to the NPM package
([#2010](https://github.com/cucumber/common/pull/2010))

## [19.0.0] - 2022-05-31
### Added
- Expand the messages protocol with keyword types ([#1966](https://github.com/cucumber/common/pull/1966))

### Changed
- [Java] the `PickleStep` constructor has changed - it now needs an extra `PickleStepType` argument.
- [Java] the `Step` constructor has changed - it now needs an extra `StepKeywordType` argument.

## [18.0.0] - 2022-03-24
### Added
- Support for EcmaScript modules (aka ESM)
([#1756](https://github.com/cucumber/common/pull/1756))
- New optional `name` property on the Hook schema ([#1914](https://github.com/cucumber/common/pull/1914))

### Changed
- JSON Schema: some `array` fields now have `"minItems": 1`.
- Generate Java code that uses `Optional` in getters.
- Setters are removed.
- Classes without required fields have public empty constructors, and static `of` methods for each field.
([#1858](https://github.com/cucumber/common/pull/1858) [aslakhellesoy](https://github.com/aslakhellesoy))
- Java: Make this library more null safe.

## [17.1.1] - 2021-09-17
### Fixed
- Perl: incorrectly included `null` values & guaranteed field order
([#1727](https://github.com/cucumber/common/pull/1727) [ehuelsmann](https://github.com/ehuelsmann))

## [17.1.0] - 2021-09-01
### Added
- Initial Perl implementation
([#1670](https://github.com/cucumber/common/pull/1670) [ehuelsmann](https://github.com/ehuelsmann))

## [17.0.1] - 2021-07-19
### Fixed
- [Ruby] `seconds_to_duration` convert nanos to an integer to match the json schema
([#1655](https://github.com/cucumber/common/pull/1655))

## [17.0.0] - 2021-07-08
### Added
- Added `Ci#buildNumber` field
([#1632](https://github.com/cucumber/common/pull/1632)
[#1606](https://github.com/cucumber/common/issues/1606)
[aslakhellesoy](https://github.com/aslakhellesoy))
- [Ruby] Generate DTOs from the json schemas to avoid usage of plain ruby hashes
([#1574](https://github.com/cucumber/common/issues/1574)
[#1605](https://github.com/cucumber/common/pull/1605))
- [Java] Added various overloads to `JSON` to work with streams efficiently

### Changed
- **BREAKING** Move `willBeRetried` field from `TestStepResult` to `TestCaseFinished`
([#902](https://github.com/cucumber/common/issues/902) [#1631](https://github.com/cucumber/common/pull/1631))
- [Go] Move module paths to point to monorepo
([#1550](https://github.com/cucumber/common/issues/1550))
- [Java] Removed implicit utility class constructors and made classes final

## [16.0.1] - 2021-05-24
### Fixed
- [JavaScript] `addDurations` works with legacy messages that represent `seconds` as a `string`.

## [16.0.0] - 2021-05-15
### Added
- [Ruby] The generated code is added to Git.
([#1461](https://github.com/cucumber/cucumber/pull/1461)
[aslakhellesoy](https://github.com/aslakhellesoy))
- [JavaScript] Added `getWorstTestStepResult` function (moved from `@cucumber/query`)

### Changed
- Empty `string` properties are set to `""` rather than being omitted.
- Empty `Array` properties are set to `[]` rather than being omitted.
- The `seconds` property on `Timestamp` and `Diration` is now a `number` rather than a `string`.
- [Go, Java, JavaScript, Ruby] The library no longer depends on protocol buffers. The message classes are generated from [JSON Schemas](https://github.com/cucumber/common/tree/v16.0.0/messages).
([#1414](https://github.com/cucumber/cucumber/pull/1414)
[aslakhellesoy](https://github.com/aslakhellesoy))
- [JavaScript]: Import with `import * as messages from '@cucumber/messages'`
- [Ruby] Messages are now plain ruby hashes with camelCase symbol keys instead of objects with snake_case properties.
- [Go, Java, JavaScript, Ruby] Packages and structs have changed:

## [15.0.0] - 2021-03-23
### Added
- [All] Added tags to Rule node
([#1356](https://github.com/cucumber/cucumber/pull/1356) [sebrose], [gasparnagy], [brasmusson](https://github.com/brasmusson), [WannesFransen1994])

### Fixed
- [Elixir] Make sure messages.proto is updated with ../messages.proto
- [Elixir] Generated new message modules based on the new messages.proto file

### Removed
- [JavaScript] moved code that depends on Node.js stream APIs to `@cucumber/message-streams`

## [14.1.2] - 2021-03-23
### Fixed
- [JavaScript] revert breaking changes in 14.1.1
([#1437](https://github.com/cucumber/cucumber/issues/1437))

## [14.1.1] - 2021-03-22
### Fixed
- The 14.1.0 release failed half way through due to build script problems.

## [14.1.0] - 2021-03-22
### Added
- [All] Added tags to Rule node
([#1356](https://github.com/cucumber/cucumber/pull/1356) [sebrose], [gasparnagy], [brasmusson](https://github.com/brasmusson), [WannesFransen1994])

### Fixed
- [Elixir] Make sure messages.proto is updated with ../messages.proto
- [Elixir] Generated new message modules based on the new messages.proto file

## [14.0.1] - 2021-02-08
### Fixed
- [JavaScript] Remove `Long` from function signatures in `TimeConversion`

## [14.0.0] - 2021-02-05
### Changed
- [JavaScript] The stream classes have to be imported separately:
`import { MessageToBinaryStream, MessageToNdjsonStream, BinaryToMessageStream, NdjsonToMessageStream} from '@cucumber/dist/src/stream'`
([#1331](https://github.com/cucumber/cucumber/issues/1331))
- In JavaScript, Int64 fields are now typed as `number`, rather than `number|Long`

### Fixed
- [JavaScript] removed circular dependencies.
([#1292](https://github.com/cucumber/cucumber/pull/1292)
[davidjgoss](https://github.com/aslakhellesoy))

## [13.2.1] - 2020-11-19
### Fixed
- In case a line cannot be parsed as JSON, throw an error
with the offending line in the exception message.

## [13.2.0] - 2020-11-12
### Added
- Elixir implementation
([#1175](https://github.com/cucumber/cucumber/pull/1175)
[WannesFransen1994])

## [13.1.0] - 2020-09-14
### Added
- Add `Attachment#url`. This makes it possible to "detach" attachments so the main stream
gets smaller and the attachments can be processed/downloaded separately with more ease.
([#1183](https://github.com/cucumber/cucumber/pull/1183)
[aslakhellesoy](https://github.com/aslakhellesoy))

### Fixed
- Ignore empty lines rather than throwing an error.

## [13.0.1] - 2020-08-07
### Fixed
- Release again since the 13.0.0 release didn't fully sync to subrepos

## [13.0.0] - 2020-08-07
### Changed
- Move `JavaMethod` and `JavaStackTraceElement` to be children of `SourceReference`

## [12.4.0] - 2020-07-31
### Added
- Suggested file name to the Attachment messages ([#1128](https://github.com/cucumber/cucumber/pull/1128))
- Added ProtocolVersion to access messages version reliably ([#1127](https://github.com/cucumber/cucumber/pull/1127) [mpkorstanje](https://github.com/mpkorstanje))

## [12.3.2] - 2020-07-29
### Fixed
- Release process for 12.3.1 failed

## [12.3.1] - 2020-07-29
### Fixed
- Release process for 12.3.0 failed

## [12.3.0] - 2020-07-29
### Added
- Add `JavaMethod` and `JavaStackTraceElement` as `SourceReference` ([#1120](https://github.com/cucumber/cucumber/pull/1120))

### Fixed
- [Ruby] Fix computing of Timestamp (see [cucumber-ruby#1438](https://github.com/cucumber/cucumber-ruby/issues/1438))

## [12.2.0] - 2020-06-26
### Added
- Added field `ci` to `Meta` message.

## [12.1.1] - 2020-04-21
### Fixed
- [Ruby] Add `VERSION` file to gem, so `Messages::Envelope::VERSION` works

## [12.1.0] - 2020-04-21
### Added
- Java: `io.cucumber.messages.Messages.Envelope.class.getPackage().getImplementationVersion()`
- Ruby: `Messages::Envelope::VERSION`
- JavaScript: `import { version } from '@cucumber/messages'`
- Expose the library version through the API
- Add `Meta` message
([#976](https://github.com/cucumber/cucumber/pull/976)
[aslakhellesoy](https://github.com/aslakhellesoy))
- [Java] Upgrade to `cucumber-parent:2.1.0` (needed to expose library version)
([#976](https://github.com/cucumber/cucumber/pull/976)
[aslakhellesoy](https://github.com/aslakhellesoy))

## [12.0.0] - 2020-04-14
### Added
- Add `id` field to `Background`, `Rule` and `Examples`. Needed for search engine indexing.

### Changed
- Some messages have been nested under other messages (removal of other messages)
made it possible to scope them more locally

### Fixed
- Ignore unknown fields when parsing JSON. This is to ensure forward and backward
compatibility when using JSON encoding (NDJSON).
([#959](https://github.com/cucumber/cucumber/pull/959)
[#957](https://github.com/cucumber/cucumber/pull/957)
[aslakhellesoy](https://github.com/mpkorstanje))

### Removed
- Several messages that weren't used have been removed
([#962](https://github.com/cucumber/cucumber/pull/962)
[#951](https://github.com/cucumber/cucumber/issues/951)
[aslakhellesoy](https://github.com/aslakhellesoy))

## [11.1.1] - 2020-03-30
### Fixed
- The [#932](https://github.com/cucumber/cucumber/pull/932) pull request wasn't actually
included in 11.1.0

## [11.1.0] - 2020-03-30
### Added
- [JavaScript] Add `#addDurations` function to `TimeConversion`
([#932](https://github.com/cucumber/cucumber/pull/932)
[charlierudolph](https://github.com/charlierudolph))

## [11.0.1] - 2020-03-30
### Fixed
- Release process

## [11.0.0] - 2020-03-30
### Changed
- `Attachment#text` and `Attachment#binary` have been replaced with `Attachment#body`,
and `Attachment#content_encoding` has been added.
([#947](https://github.com/cucumber/cucumber/pull/947)
[aslakhellesoy](https://github.com/aslakhellesoy))

## [10.0.3] - 2020-03-05
### Fixed
- 10.0.2 release process failed.

## [10.0.2] - 2020-03-02
### Fixed
- [JavaScript] make stream readable/writable object modes explicit. Better buffer handling.
- [Ruby] Don't depend on the `json` gem, since it only installs on Windows with
a C compiler toolchain. The `json` gem is part of the Ruby stdlib.
- [Go] Increase max size of a JSON message to 10Mb
([#901](https://github.com/cucumber/cucumber/issues/901)
[#903](https://github.com/cucumber/cucumber/pull/903)
[aslakhellesoy](https://github.com/aslakhellesoy))

## [10.0.1] - 2020-02-13
### Fixed
- The 10.0.0 release failed.

## [10.0.0] - 2020-02-13
### Added
- Add `UndefinedParameterType`
([#890](https://github.com/cucumber/cucumber/pull/890)
[aslakhellesoy](https://github.com/aslakhellesoy))
- Add `TestCaseFinished#message`
([#890](https://github.com/cucumber/cucumber/pull/890)
[aslakhellesoy](https://github.com/aslakhellesoy))

### Changed
- Rename `TestResult` to `TestStepResult`
([#890](https://github.com/cucumber/cucumber/pull/890)
[aslakhellesoy](https://github.com/aslakhellesoy))

### Fixed
- Ruby: Fixed rounding errors in `TimeConversion`

## [9.0.3] - 2020-01-10
### Fixed
- Ruby: Fix inclusion of generated lib/messages.pb.rb

## [9.0.2] - 2020-01-10

## [9.0.1] - 2020-01-09
### Fixed
- Fixed release scripts for Go and JavaScript

## 9.0.0 - 2020-01-09
### Added
- Added `ParameterType` as an envelope message

### Changed
- Renamed module name from `cucumber-messages` to `messsages`
([#850](https://github.com/cucumber/cucumber/pull/850)
[aslakhellesoy](https://github.com/aslakhellesoy))
- Use pure Ruby protobuf in order to avoid problems with Ruby 2.7.0 and JRuby.
([#813](https://github.com/cucumber/cucumber/pull/813)
[#843](https://github.com/cucumber/cucumber/issues/843)
[mvz](https://github.com/aslakhellesoy))
- A `TestCase` now has a list of `StepMatchArgumentsList` rather than a list of `StepMatchArgument`.
This allows a `TestCase` to hold matches from more than one `StepDefinition`, which is possible
in the case of ambiguous matches.
- Renamed `content_type` fields to `media_type`
- Removed the `Media` message
- Attachments can have one of `string text` and `bytes binary` as the `body`

### Removed
- Removed `TestCase#test_result`. Aggregate results will be computed by `cucumber-query` instead

## 8.0.0 - 2019-12-10
### Added
- Added `testStepId` and `testCaseStartedId` to `Attachment`
([#814](https://github.com/cucumber/cucumber/pull/814)
[charlierudolph](https://github.com/charlierudolph))
- Added new classes for working with NDJSON streams
- Added new `TimeConversion` utilities for converting between protobuf `Timestamp/Duration` and the
platform's representation of timestamps (clock time) and duration (monotonic time)

### Changed
- Renamed some of the classes for dealing with streams

## 7.0.0 - 2019-11-14
### Added
- Support retry
([#722](https://github.com/cucumber/cucumber/pull/722)
[charlierudolph](https://github.com/charlierudolph))

### Changed
- Added more reference ids and removed deprecated/reserved fields
([#790](https://github.com/cucumber/cucumber/pull/790)
[#794](https://github.com/cucumber/cucumber/pull/794)
[vincent-psarga](https://github.com/aslakhellesoy))

## 6.0.2 - 2019-10-16

## 6.0.1 - 2019-10-03
### Fixed
- [Go] Release 6.0.0 is unusable.

## 6.0.0 - 2019-10-02
### Added
- New `TestStepMatched` message
- `Duration` message to express duration in a seconds + nano format
- field `duration` in `TestResult` message

### Changed
- Renamed `PatternMatch` to `StepMatchArgument`
- Renamed `CommandRunTestStep#patternMatches` to `CommandRunTestStep#stepMatchArguments`
- Replace Google's Timestamp by our own message

### Removed
- `durationNanoSeconds` field in `TestResult` message

## 5.0.1 - 2019-08-23
### Fixed
- [Go] Fix module version (5.0.0 left it at v4)

## 5.0.0 - 2019-08-23
### Changed
- The ordinal numbers of the `Status` enum have changed, to easier compute an
aggregated status.

### Fixed
- [JavaScript] Don't swallow exceptions happening in `ProtobufMessageStream`

## 4.0.0 - 2019-08-14

## 3.0.5 - 2019-08-14
### Fixed
- [Go] Tag the cucumber/go subrepo (again)

## 3.0.4 - 2019-08-14
### Fixed
- [Go] Tag the cucumber/go subrepo (again)

## 3.0.3 - 2019-08-14
### Fixed
- [Go] Tag the cucumber/go subrepo

## 3.0.2 - 2019-08-01
### Added
- Add Timestamp property and comments to TestRunFinished message
([#665](https://github.com/cucumber/cucumber/pull/665)
[SabotageAndi](https://github.com/SabotageAndi)

## 3.0.1 - 2019-07-15
### Added
- [.NET] Publish NuGet package
([#635](https://github.com/cucumber/cucumber/pull/635)
[SabotageAndi](https://github.com/aslakhellesoy)
[vincent-psarga](https://github.com/vincent-psarga))

## 3.0.0 - 2019-06-05
### Added
- Added `TestRunStarted#timestamp` field
([#615](https://github.com/cucumber/cucumber/pull/615)
[david1995](https://github.com/david1995))
- Added `TestCaseStarted#platform` field
([#626](https://github.com/cucumber/cucumber/pull/626)
[#616](https://github.com/cucumber/cucumber/pull/616)
[david1995](https://github.com/david1995))

### Changed
- Use an enum for the `encoding` field.
- Misc changes for `cucumber-engine`
([#549](https://github.com/cucumber/cucumber/pull/549))

### Deprecated

### Fixed

### Removed

## 2.1.2 - 2019-03-29
### Fixed
- Fix Project struggling to build across JRuby and Ruby 2.6
([#578](https://github.com/cucumber/cucumber/pull/578)
[luke-hill](https://github.com/luke-hill))

## 2.1.1 - 2018-11-02
### Fixed
- Release process improvements

## 2.1.0 - 2018-11-01
### Added
- Add testResult to the TestCaseFinished message
([#488](https://github.com/cucumber/cucumber/pull/488)
[brasmusson](https://github.com/brasmusson))

## 2.0.0 - 2018-10-14
### Added
- Several messages to support [cucumber-engine]()
([#502](https://github.com/cucumber/cucumber/pull/502)
[charlierudolph](https://github.com/charlierudolph))

## 1.1.2 - 2018-10-01
### Added
- Added `TestHookStarted` and `TestHookFinished` to distinguish between messages about Gherkin steps and hooks
([aslakhellesoy](https://github.com/aslakhellesoy))

## 1.0.0 - 2018-09-15
### Added
- Protobuf messages for Go, Java, JavaScript, TypeScript and Ruby

[Unreleased]: https://github.com/cucumber/messages/compare/v28.1.0...HEAD
[28.1.0]: https://github.com/cucumber/messages/compare/v28.0.0...v28.1.0
[28.0.0]: https://github.com/cucumber/messages/compare/v27.2.0...v28.0.0
[27.2.0]: https://github.com/cucumber/messages/compare/v27.1.0...v27.2.0
[27.1.0]: https://github.com/cucumber/messages/compare/v27.0.2...v27.1.0
[27.0.2]: https://github.com/cucumber/messages/compare/v27.0.1...v27.0.2
[27.0.1]: https://github.com/cucumber/messages/compare/v27.0.0...v27.0.1
[27.0.0]: https://github.com/cucumber/messages/compare/v26.0.1...v27.0.0
[26.0.1]: https://github.com/cucumber/messages/compare/v26.0.0...v26.0.1
[26.0.0]: https://github.com/cucumber/messages/compare/v25.0.1...v26.0.0
[25.0.1]: https://github.com/cucumber/messages/compare/v25.0.0...v25.0.1
[25.0.0]: https://github.com/cucumber/messages/compare/v24.1.0...v25.0.0
[24.1.0]: https://github.com/cucumber/messages/compare/v24.0.1...v24.1.0
[24.0.1]: https://github.com/cucumber/messages/compare/v24.0.0...v24.0.1
[24.0.0]: https://github.com/cucumber/messages/compare/v23.0.0...v24.0.0
[23.0.0]: https://github.com/cucumber/messages/compare/v22.0.0...v23.0.0
[22.0.0]: https://github.com/cucumber/messages/compare/v21.0.1...v22.0.0
[21.0.1]: https://github.com/cucumber/messages/compare/v21.0.0...v21.0.1
[21.0.0]: https://github.com/cucumber/messages/compare/v20.0.0...v21.0.0
[20.0.0]: https://github.com/cucumber/messages/compare/v19.1.4...v20.0.0
[19.1.4]: https://github.com/cucumber/messages/compare/v19.1.3...v19.1.4
[19.1.3]: https://github.com/cucumber/messages/compare/v19.1.2...v19.1.3
[19.1.2]: https://github.com/cucumber/messages/compare/v19.1.1...v19.1.2
[19.1.1]: https://github.com/cucumber/messages/compare/v19.1.0...v19.1.1
[19.1.0]: https://github.com/cucumber/messages/compare/v19.0.0...v19.1.0
[19.0.0]: https://github.com/cucumber/messages/compare/v18.0.0...v19.0.0
[18.0.0]: https://github.com/cucumber/messages/compare/v17.1.1...v18.0.0
[17.1.1]: https://github.com/cucumber/messages/compare/v17.1.0...v17.1.1
[17.1.0]: https://github.com/cucumber/messages/compare/v17.0.1...v17.1.0
[17.0.1]: https://github.com/cucumber/messages/compare/v17.0.0...v17.0.1
[17.0.0]: https://github.com/cucumber/messages/compare/v16.0.1...v17.0.0
[16.0.1]: https://github.com/cucumber/messages/compare/v16.0.0...v16.0.1
[16.0.0]: https://github.com/cucumber/messages/compare/v15.0.0...v16.0.0
[15.0.0]: https://github.com/cucumber/messages/compare/v14.1.2...v15.0.0
[14.1.2]: https://github.com/cucumber/messages/compare/v14.0.1...v14.1.2
[14.1.1]: https://github.com/cucumber/messages/compare/v14.1.0...v14.1.1
[14.1.0]: https://github.com/cucumber/messages/compare/v14.0.1...v14.1.0
[14.0.1]: https://github.com/cucumber/messages/compare/v14.0.0...v14.0.1
[14.0.0]: https://github.com/cucumber/messages/compare/v13.2.1...v14.0.0
[13.2.1]: https://github.com/cucumber/messages/compare/v13.2.0...v13.2.1
[13.2.0]: https://github.com/cucumber/messages/compare/v13.1.0...v13.2.0
[13.1.0]: https://github.com/cucumber/messages/compare/v13.0.1...v13.1.0
[13.0.1]: https://github.com/cucumber/messages/compare/v13.0.0...v13.0.1
[13.0.0]: https://github.com/cucumber/messages/compare/v12.4.0...v13.0.0
[12.4.0]: https://github.com/cucumber/messages/compare/v12.3.2...v12.4.0
[12.3.2]: https://github.com/cucumber/messages/compare/v12.3.1...v12.3.2
[12.3.1]: https://github.com/cucumber/messages/compare/v12.3.0...v12.3.1
[12.3.0]: https://github.com/cucumber/messages/compare/v12.2.0...v12.3.0
[12.2.0]: https://github.com/cucumber/messages/compare/v12.1.1...v12.2.0
[12.1.1]: https://github.com/cucumber/messages/compare/v12.1.0...v12.1.1
[12.1.0]: https://github.com/cucumber/messages/compare/v12.0.0...v12.1.0
[12.0.0]: https://github.com/cucumber/messages/compare/v11.1.1...v12.0.0
[11.1.1]: https://github.com/cucumber/messages/compare/v11.1.0...v11.1.1
[11.1.0]: https://github.com/cucumber/messages/compare/v11.0.1...v11.1.0
[11.0.1]: https://github.com/cucumber/messages/compare/v11.0.0...v11.0.1
[11.0.0]: https://github.com/cucumber/messages/compare/v10.0.3...v11.0.0
[10.0.3]: https://github.com/cucumber/messages/compare/v10.0.2...v10.0.3
[10.0.2]: https://github.com/cucumber/messages/compare/v10.0.1...v10.0.2
[10.0.1]: https://github.com/cucumber/messages/compare/v10.0.0...v10.0.1
[10.0.0]: https://github.com/cucumber/messages/compare/v9.0.3...v10.0.0
[9.0.3]: https://github.com/cucumber/messages/compare/v9.0.2...v9.0.3
[9.0.2]: https://github.com/cucumber/messages/compare/v9.0.1...v9.0.2
[9.0.1]: https://github.com/cucumber/messages/compare/v9.0.0...v9.0.1
