#syntax=docker/dockerfile:1.4

ARG RUBY_VERSION=3.1

# Dummy stage for generated code, overriden in main build
FROM scratch AS schema-codegen


FROM ruby:${RUBY_VERSION}-alpine

COPY --link *.gemspec Gemfile VERSION .
RUN --mount=type=cache,target=/root/.bundle \
    bundle install

COPY --link . .
COPY --from=schema-codegen / lib/cucumber
RUN bundle exec rake
