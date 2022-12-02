#syntax=docker/dockerfile:1.4

# Base image
ARG MAVEN_VERSION=3.8
ARG JAVA_VERSION=16
FROM maven:${MAVEN_VERSION}-eclipse-temurin-${JAVA_VERSION} AS java


# Dummy stage for generated code, overriden in main build
FROM scratch AS schema-codegen


FROM java AS with-dependencies

COPY --link pom.xml maven-versions-rules.xml .
RUN mvn install


FROM java AS tested

COPY --link . .
COPY --link --from=with-dependencies /root/.m2 /root/.m2
COPY --link --from=schema-codegen / src/generated/java/io/cucumber/messages/types

RUN mvn test
