#syntax=docker/dockerfile:1.4

FROM php:8.1-alpine AS php

COPY --link composer.json .
COPY --link --from=composer:2 /usr/bin/composer /usr/bin/composer
RUN composer install --dev

COPY --link . .
COPY --from=schema-codegen /*.php src-generated
RUN vendor/bin/php-cs-fixer --dry-run --diff fix
RUN vendor/bin/psalm --no-cache
RUN vendor/bin/phpunit
