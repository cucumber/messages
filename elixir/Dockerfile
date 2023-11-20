#syntax=docker/dockerfile:1.6

ARG ELIXIR_VERSION=1.10

FROM elixir:${ELIXIR_VERSION}-alpine AS elixir
WORKDIR /cucumber


FROM elixir AS with-dependencies

COPY --link mix.exs mix.lock .
RUN mix local.hex --force && mix deps.get


FROM elixir AS protobuf-codegen

RUN apk add protoc
COPY --link mix.exs mix.lock messages.proto .
COPY --link --from=with-dependencies /cucumber/deps deps
COPY --link --from=with-dependencies /root/.mix /root/.mix
RUN mkdir /build
RUN MIX_ENV=prod mix protox.generate --multiple-files --output-path=/build messages.proto


FROM with-dependencies AS tested

COPY --link . .
COPY --link --from=protobuf-codegen /build lib/cucumber_messages/generated
RUN mix test
