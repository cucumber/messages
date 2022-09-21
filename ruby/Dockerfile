#syntax=docker/dockerfile:1.4

ARG RUBY_VERSION=3.1

FROM ruby:${RUBY_VERSION}-alpine

COPY --link *.gemspec Gemfile VERSION .
RUN bundle install

COPY --link . .
COPY --from=schema-codegen /*.rb lib/cucumber
RUN bundle exec rake
