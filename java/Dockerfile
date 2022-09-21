#syntax=docker/dockerfile:1.4

ARG MAVEN_VERSION=3.8
ARG JAVA_VERSION=16

# Dummy stage for generated code, overriden in main build
FROM scratch AS schema-codegen


FROM maven:${MAVEN_VERSION}-eclipse-temurin-${JAVA_VERSION}

COPY --link pom.xml .
RUN --mount=type=cache,target=/root/.m2 \
    mvn install

COPY --link . .
COPY --from=schema-codegen / src/generated/java/io/cucumber/messages/types
RUN --mount=type=cache,target=/root/.m2 \
    mvn test
RUN scripts/check-jar.sh
