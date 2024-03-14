#syntax=docker/dockerfile:1.7

# Base image
ARG JAVASCRIPT_VERSION=18
FROM node:${JAVASCRIPT_VERSION}-alpine AS javascript
WORKDIR /cucumber


# Dummy stage for generated code, overriden in main build
FROM scratch AS schema-codegen


FROM javascript AS with-dependencies

RUN apk add jq

COPY --link package.json package-lock.json .
# stop the 'prepare' script from trying to trigger code generation
RUN jq 'del(.scripts.prepare)' < package.json > package.json.new && mv package.json.new package.json
RUN --mount=type=cache,target=/root/.npm \
    npm ci


FROM javascript AS tested

COPY --link . .
COPY --link --from=with-dependencies /cucumber/node_modules node_modules
COPY --link --from=schema-codegen / src
RUN npm test
