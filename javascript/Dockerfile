#syntax=docker/dockerfile:1.4

ARG JAVASCRIPT_VERSION=18

# Dummy stage for generated code, overriden in main build
FROM scratch AS schema-codegen


FROM node:${JAVASCRIPT_VERSION}-alpine

RUN apk add jq

COPY --link package.json package-lock.json .
# stop the 'prepare' script from trying to trigger code generation
RUN jq 'del(.scripts.prepare)' < package.json > package.json.new && mv package.json.new package.json
RUN --mount=type=cache,target=/root/.npm \
    npm ci

COPY --link . .
COPY --link --from=schema-codegen / src
RUN npm test
