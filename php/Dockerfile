#syntax=docker/dockerfile:1.4

ARG PHP_VERSION=8.1

# Dummy stage for generated code, overriden in main build
FROM scratch AS schema-codegen


FROM php:${PHP_VERSION}-alpine

COPY --link composer.json .
COPY --link --from=composer:2 /usr/bin/composer /usr/bin/composer
ARG COMPOSER_EXTRA_FLAGS=
RUN --mount=type=cache,target=/root/.composer \
    composer update --dev ${COMPOSER_EXTRA_FLAGS}

COPY --link . .
COPY --from=schema-codegen / src-generated
RUN vendor/bin/php-cs-fixer --dry-run --diff fix
RUN vendor/bin/psalm --no-cache
RUN vendor/bin/phpunit
