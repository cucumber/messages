#syntax=docker/dockerfile:1.7

# Base image
ARG PERL_VERSION=5.39
FROM perl:${PERL_VERSION} AS perl
WORKDIR /cucumber


# Dummy stage for generated code, overriden in main build
FROM scratch AS schema-codegen


# Install the JS CCK
FROM node:alpine AS cck-installer

WORKDIR /build
COPY --link t/compatibility-kit .
RUN --mount=type=cache,target=/root/.npm \
    npm ci


FROM perl AS with-dependencies

RUN apt update && apt install -y cpanminus

COPY --link cpanfile dist.ini .
RUN --mount=type=cache,target=/root/.cpanm \
    cpanm --installdeps .


FROM perl AS tested

COPY --link . .
COPY --link --from=with-dependencies /usr/local/lib/perl5 /usr/local/lib/perl5
COPY --link --from=cck-installer /build/node_modules t/compatibility-kit/node_modules
RUN prove -l \
    && AUTHOR_TESTS=1 prove -l
