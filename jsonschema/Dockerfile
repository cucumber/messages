#syntax=docker/dockerfile:1.6
ARG LANGUAGE=ruby

FROM ruby:3.2.2-alpine AS ruby

RUN apk add coreutils

WORKDIR /cucumber
RUN mkdir --parents /build

COPY --link . .


FROM ruby AS go-unformatted

RUN <<-EOF
      ruby scripts/codegen.rb Go . go.go.erb > /build/messages.go
      ruby scripts/codegen.rb Go . go.enum.go.erb >> /build/messages.go
EOF


# Todo: can we eliminate this stage with smarter ERB templates?
FROM golang:1.21.4-alpine AS go-codegen

WORKDIR /build
COPY --link --from=go-unformatted /build/ .
RUN go fmt *.go


FROM ruby AS java-codegen

RUN <<-EOF
      mkdir --parents /tmp/build
      ruby scripts/codegen.rb Java . java.java.erb > /tmp/build/Generated.java.tmp
      ruby scripts/codegen.rb Java . java.enum.java.erb >> /tmp/build/Generated.java.tmp
  	  csplit --prefix=/tmp/build/Generated --suffix-format=%02d.java.tmp --elide-empty-files /tmp/build/Generated.java.tmp "/^.*[.]java\$/" {*}
      for file in /tmp/build/Generated**; do tail -n +2 $file > /build/$(head -n 1 $file); done
EOF


FROM ruby AS javascript-codegen

RUN <<-EOF
      ruby scripts/codegen.rb TypeScript . typescript.ts.erb > /build/messages.ts
      ruby scripts/codegen.rb TypeScript . typescript.enum.ts.erb >> /build/messages.ts
EOF


FROM ruby AS perl-codegen

RUN <<-EOF
      ruby scripts/codegen.rb Perl . perl.pm.erb > /build/Messages.pm
EOF


FROM ruby AS php-codegen

RUN <<-EOF
      mkdir --parents /tmp/build
      ruby scripts/codegen.rb Php . php.php.erb > /tmp/build/messages.php
      ruby scripts/codegen.rb Php . php.enum.php.erb >> /tmp/build/messages.php
      csplit --prefix=/tmp/build/Generated --suffix-format=%02d.tmp.php --elide-empty-files /tmp/build/messages.php "/^.*[.]php\$/" {*}
      for file in /tmp/build/Generated**; do mkdir -p /build/$(head -n 1 $file | sed 's/[^/]*.php$//'); done
      for file in /tmp/build/Generated**; do tail -n +2 $file > /build/$(head -n 1 $file); done
EOF


FROM ruby AS ruby-codegen

RUN <<-EOF
      ruby scripts/codegen.rb Ruby . ruby.rb.erb > /build/messages.dtos.rb
      ruby scripts/codegen.rb Ruby . ruby.enum.rb.erb >> /build/messages.dtos.rb
      ruby scripts/codegen.rb Ruby . ruby_deserializers.rb.erb > /build/messages.deserializers.rb
EOF


# Stages used to output build folder(s) to disk
FROM ${LANGUAGE}-codegen AS codegen

FROM scratch AS output
COPY --link --from=codegen /build /
