#syntax=docker/dockerfile:1.4
ARG LANGUAGE=ruby

FROM ruby:3.1.2-alpine AS ruby

WORKDIR /cucumber
RUN mkdir -p /build


FROM ruby AS javascript-codegen

COPY --link . .
RUN <<-EOF
      ruby scripts/codegen.rb TypeScript . typescript.ts.erb > /build/messages.ts
      ruby scripts/codegen.rb TypeScript . typescript.enum.ts.erb >> /build/messages.ts
EOF


FROM ruby AS php-codegen

RUN apk add bash coreutils

COPY --link . .
RUN <<-EOF
      mkdir -p /tmp/build
      ruby scripts/codegen.rb Php . php.php.erb > /tmp/build/messages.php
      ruby scripts/codegen.rb Php . php.enum.php.erb >> /tmp/build/messages.php
      csplit --prefix=/tmp/build/Generated --suffix-format=%02d.tmp.php --elide-empty-files /tmp/build/messages.php "/^.*[.]php\$/" {*}
      for file in /tmp/build/Generated**; do mkdir -p /build/$(head -n 1 $file | sed 's/[^/]*.php$//'); done
      for file in /tmp/build/Generated**; do tail -n +2 $file > /build/$(head -n 1 $file); rm $file; done
EOF


FROM ruby AS ruby-codegen

COPY --link . .
# TODO: factor this stuff out into a bash script we can delegate to?
RUN <<-EOF
      ruby scripts/codegen.rb Ruby . ruby.rb.erb > /build/messages.dtos.rb
      ruby scripts/codegen.rb Ruby . ruby.enum.rb.erb >> /build/messages.dtos.rb
      ruby scripts/codegen.rb Ruby . ruby_deserializers.rb.erb > /build/messages.deserializers.rb
EOF



# Stages used to output build folder(s) to disk
FROM ${LANGUAGE}-codegen AS codegen

FROM scratch AS output
COPY --from=codegen /build /
