#syntax=docker/dockerfile:1.4

# Base image
FROM debian:bullseye-slim AS cpp

RUN <<EOF
# Install/update tools. Don't forget to clean cache
apt-get update
apt-get install -y \
    bash \
    curl \
    unzip \
    build-essential \
    cmake
rm -rf /var/lib/apt/lists/*
EOF


WORKDIR /cucumber

# Dummy stage for generated code, overriden in main build
FROM scratch AS schema-codegen

FROM cpp AS with-dependencies

COPY --link cmake cmake
COPY --link scripts scripts
COPY --link Makefile deps.txt .

# verify loads additional dependencies without running the tests (they aren't copied in yet)
RUN make install-deps

FROM cpp AS tested

COPY --link . .
COPY --link --from=with-dependencies build/root build/root
#COPY --link --from=schema-codegen / src/generated/java/io/cucumber/messages/types

