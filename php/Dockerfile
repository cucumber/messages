#syntax=docker/dockerfile:1.7

# Base image
ARG PHP_VERSION=8.1
FROM php:${PHP_VERSION}-alpine AS php
WORKDIR /cucumber

# Dummy stage for generated code, overriden in main build
FROM scratch AS schema-codegen


FROM php AS with-dependencies

COPY --link composer.json .
COPY --link --from=composer:2 /usr/bin/composer /usr/bin/composer
ARG COMPOSER_EXTRA_FLAGS=
RUN --mount=type=cache,target=/root/.composer \
    composer update --dev ${COMPOSER_EXTRA_FLAGS}


FROM php AS tested

COPY --link . .
COPY --link --from=with-dependencies /cucumber/vendor vendor
COPY --link --from=schema-codegen / src-generated
RUN vendor/bin/php-cs-fixer --dry-run --diff fix
RUN vendor/bin/psalm --no-cache
RUN vendor/bin/phpunit
