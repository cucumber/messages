#syntax=docker/dockerfile:1.7

# Base image
ARG RUBY_VERSION=3.1
FROM ruby:${RUBY_VERSION}-alpine AS ruby
WORKDIR /cucumber


# Dummy stage for generated code, overriden in main build
FROM scratch AS schema-codegen


FROM ruby AS with-dependencies

COPY --link *.gemspec Gemfile VERSION .
RUN --mount=type=cache,target=/root/.bundle \
    bundle install


FROM ruby AS tested

COPY --link . .
COPY --link --from=with-dependencies /usr/local/bundle /usr/local/bundle
COPY --link --from=schema-codegen / lib/cucumber
RUN bundle exec rake
