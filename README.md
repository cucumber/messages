# Cucumber Messages

*Cucumber Messages* is a message protocol for representing results and other information
from Cucumber. The protocol aims to decouple various components of the Cucumber platform, with the following advantages:

* Each component only needs to know about a subset of messages
* Gherkin is decoupled from the Cucumber execution component
* Enables the future support other formats such as Markdown and Excel

## Message Overview

![messages.png](messages.png)

Note: Markdown and Excel formats are currently not supported and mentioned here as potential future alternative languages to express BDD scenarios.

## JSON Schema

The [jsonschema](jsonschema) directory contains [JSON Schema](https://json-schema.org/)
definitions for each message type.

See [messages.md](messages.md) for a detailed description of each message type.

## Encoding

When Cucumber Messages are stored in a file or sent over a network, they are
encoded as NDJSON. We call this a *message stream*.

Each message in a message stream is of type [Envelope](messages.md#envelope).

## Language implementations

Each subdirectory defines language-specific implementations of these messages,
generated from the JSON schemas. The current implementations are:
- C++
- .NET
- Go
- Java
- Javascript
- Perl
- PHP
- Ruby

There is also 1 subdirectory for Elixir which contains the legacy implementation which was largely
driven by protobuf. This is currently not implemented or tested / integrated into our CI and will
require the process of porting over to the JSON schema protocol.

- Elixir

## Message emitters
Cucumber Messages are currently sent by the following versions of Cucumber (using the `message` formatter):

* Cucumber-JVM `6.0.0` and later
* Cucumber-Ruby `4.0.0` and later
* Cucumber.js `7.0.0` and later

Messages emitters for the other Cucumber languages (e.g. Perl) are not yet implemented. 

## Why Cucumber Messages

Cucumber needs to produce results in a machine-readable format so that other tools can generate reports.

![messages-stream.svg](messages-stream.svg)

Historically, Cucumber did this with the `json` and `junit` formatters.
These formats however, have several shortcomings that are now addressed by using Cucumber Messages.

The `json` formatter is now in maintenance mode for these implementations, and Messages is the preferred standard.
See [utilities](#utilities) for a list of tools that may help with backward and forward compatibility
with the `json` format.

### High memory footprint

JSON and XML production/consumption is done by serialising/deserialising an object graph. For "big" Cucumber
runs this graph may consume a considerable amount of RAM, in particular if several large attachments
(screenshots) are attached.

This can cause out of memory errors, aborting Cucumber runs or reporting jobs. It also means that no results can be
consumed by downstream processors until the last scenario has finished.

With Cucumber Messages, several messages containing smaller pieces of information are emitted
continuously to a *stream* (NDJSON, see above), avoiding high memory consumption and enabling real-time processing
of results.

### Lack of a schema

The JSON reporter does not have a formal schema. This has led to slightly inconsistent implementations
of the JSON formatter in various Cucumber implementations. Consumers of the JSON format have
to anticipate and detect these inconsistencies and try to cope with them.

### Limited information

The `junit` XML format can only contain very limited information such as test case name and status.
While there isn't an official schema for JUnit XML, there are a few defacto ones around which are very limited.

The `json` format represents the following information:

* Gherkin source (as a rough and lossy representation of a Gherkin document's abstract syntax tree)
* Attachments (formerly called `embeddings`)
* Path and line for step definitions
* Results for hooks

However, it does not contain the following information (but Cucumber Messages does):

* Original source code of the Gherkin document
* Gherkin document abstract syntax tree
* Step definitions
* Parameter types

This kind of information is required to produce rich reports and analytics, and is
used in [@cucumber/react-components](https://github.com/cucumber/react-components) and [Cucumber Reports](https://reports.cucumber.io/).

## Examples

You will find examples of Cucumber Messages in the [compatibility-kit](https://github.com/cucumber/compatibility-kit/) project.

## Utilities

* [@cucumber/react](https://github.com/cucumber/cucumber-react) - React component that renders Cucumber Messages nicely
  * Used internally by [Cucumber Reports](https://reports.cucumber.io/).
