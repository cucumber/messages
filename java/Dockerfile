#syntax=docker/dockerfile:1.7

# Base image
ARG JAVA_VERSION=17
FROM maven:3.8.6-eclipse-temurin-${JAVA_VERSION} AS java
WORKDIR /cucumber

# Dummy stage for generated code, overriden in main build
FROM scratch AS schema-codegen


FROM java AS with-dependencies

COPY --link pom.xml .
# verify loads additional dependencies without running the tests (they aren't copied in yet)
RUN mvn dependency:go-offline verify


FROM java AS tested

COPY --link . .
COPY --link --from=with-dependencies /root/.m2 /root/.m2
COPY --link --from=schema-codegen / src/generated/java/io/cucumber/messages/types

RUN mvn verify javadoc:jar
