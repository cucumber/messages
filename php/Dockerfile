#syntax=docker/dockerfile:1.4

ARG PHP_VERSION=8.1

FROM php:${PHP_VERSION}-alpine AS php

COPY --link composer.json .
COPY --link --from=composer:2 /usr/bin/composer /usr/bin/composer
ARG COMPOSER_EXTRA_FLAGS=
RUN composer update --dev ${COMPOSER_EXTRA_FLAGS}

COPY --link . .
COPY --from=schema-codegen /*.php src-generated
RUN vendor/bin/php-cs-fixer --dry-run --diff fix
RUN vendor/bin/psalm --no-cache
RUN vendor/bin/phpunit
