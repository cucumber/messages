#syntax=docker/dockerfile:1.4

FROM ruby:3.1.2-alpine

COPY --link *.gemspec Gemfile VERSION .
RUN bundle install

COPY --link . .
COPY --from=schema-codegen /*.rb lib/cucumber
RUN bundle exec rake