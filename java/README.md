[![Maven Central](https://img.shields.io/maven-central/v/io.cucumber/messages.svg?label=Maven%20Central)](https://search.maven.org/search?q=g:%22io.cucumber%22%20AND%20a:%22messages%22)

# Cucumber Messages for Java (JSON schema)

## Reading

```java
Path path = ...
NdjsonToMessageReader.Deserializer deserializer = ... 
try (NdjsonToMessageReader reader = new NdjsonToMessageReader(newInputStream(path), deserializer)) {
    return reader.lines()
    // Do something with messages
    .collect(Collectors.toList());
}
```

## Writing

```java
Path path = ...
MessageToNdjsonWriter.Serializer serializer = ...
try(MessageToNdjsonWriter writer = new MessageToNdjsonWriter(newOutputStream(path), serializer)){
    for(Envelope envelope : messages){
        writer.write(envelope);
    }
}
```

See Unit tests for more examples.
