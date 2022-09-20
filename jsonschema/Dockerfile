#syntax=docker/dockerfile:1.4

FROM ruby:3.1.2-alpine AS ruby

WORKDIR /cucumber


FROM ruby AS ruby-codegen

COPY --link . .
# TODO: factor this stuff out into a bash script we can delegate to
RUN mkdir -p /build \
  && ruby scripts/codegen.rb Ruby . ruby.rb.erb > /build/messages.dtos.rb \
  && ruby scripts/codegen.rb Ruby . ruby.enum.rb.erb >> /build/messages.dtos.rb


FROM scratch AS ruby-codegen-output

COPY --from=ruby-codegen /build/*.rb /


FROM ruby AS php-codegen

RUN apk add coreutils

COPY --link . .
# TODO: factor this stuff out into a bash script we can delegate to
RUN mkdir -p /build \
  && ruby scripts/codegen.rb Php . php.php.erb > /build/messages.php \
  && ruby scripts/codegen.rb Php . php.enum.php.erb >> /build/messages.php \
  && csplit --quiet --prefix=/build/Generated --suffix-format=%02d.php.tmp --elide-empty-files /build/messages.php /^.*[.]php$$/ {*}
#     	rm -rf src-generated/*
#     	for file in build/Generated**; do mkdir -p src-generated/$$(head -n 1 $$file | sed 's/[^/]*.php$$//'); done
#     	for file in build/Generated**; do tail -n +2 $$file > src-generated/$$(head -n 1 $$file); rm $$file; done
#     	vendor/bin/php-cs-fixer --diff fix src-generated


FROM scratch AS php-codegen-output

COPY --from=php-codegen /build/*.php /