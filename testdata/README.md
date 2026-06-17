Test Data
=========

This folder contains (one) interesting samples to test serialization and
deserialization. It covers attribute casing, enum representation, optional
values and numbers.

This sample set is intentionally not exhaustive. As the message implementations
are generated we are only interested in structural problems. A more exhaustive
set of test data can be found in the [compatibility-kit](https://github.com/cucumber/compatibility-kit).

Notes: 

1. because the compatibility-kit depends on messages, we can't use it
to test itself. 
2. To simplify testing the keys in the sample have been sorted with
   `cat minimal.ndjson  | jq --sort-keys --compact-output`. This should allow
   for a simple round-trip tests.
