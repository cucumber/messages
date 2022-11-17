#! /bin/bash

rm -rf ./test/testdata/*

curl -s -H "Accept: application/vnd.github+json" https://api.github.com/repos/cucumber/compatibility-kit/contents/devkit/samples | grep "\"name\"" | awk '{print $2}' | sed 's/"//g' | sed 's/,//g' | while read -r subfolder ; do

  curl -s -H "Accept: application/vnd.github+json" "https://api.github.com/repos/cucumber/compatibility-kit/contents/devkit/samples/$subfolder" | grep "\"name\"" | grep ".feature.ndjson" | awk '{print $2}' | sed 's/"//g' | sed 's/,//g' | while read -r filename; do
    curl -s -H "Accept: application/vnd.github+json" "https://api.github.com/repos/cucumber/compatibility-kit/contents/devkit/samples/$subfolder/$filename" | jq -r '.content' | base64 -d > "./test/testdata/$filename"
  done
done