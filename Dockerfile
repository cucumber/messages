#syntax=docker/dockerfile:1.4

FROM ruby:3.1.2-alpine AS ruby

FROM ruby AS ruby-codegen

WORKDIR /cucumber

COPY --link jsonschema jsonschema
RUN mkdir -p ruby/lib/cucumber \
  && ruby jsonschema/scripts/codegen.rb Ruby jsonschema ruby.rb.erb > ruby/lib/cucumber/messages.dtos.rb \
  && ruby jsonschema/scripts/codegen.rb Ruby jsonschema ruby.enum.rb.erb >> ruby/lib/cucumber/messages.dtos.rb


FROM scratch AS ruby-codegen-output

COPY --from=ruby-codegen /cucumber/ruby/lib/cucumber/*.rb /


FROM ruby AS ruby-test

WORKDIR /cucumber/ruby

COPY --link ruby/*.gemspec ruby/Gemfile ruby/VERSION .
RUN bundle install

COPY --link ruby/lib lib
COPY --from=ruby-codegen /cucumber/ruby/lib/cucumber ruby/lib/cucumber
COPY --link ruby/spec spec
COPY --link ruby/.rspec ruby/Rakefile .
CMD bundle exec rake