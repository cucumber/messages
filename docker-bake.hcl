group "default" {
  targets = [
    "php",
    "ruby",
  ]
}

group "php" {
  targets = [
    "php-codegen-output",
  ]
}

target "php-codegen-output" {
  context = "jsonschema"
  target = "php-codegen-output"
  output = ["php-temp-build"]
}

group "ruby" {
  targets = [
    "ruby-codegen-output",
    "ruby-test",
  ]
}

target "ruby-codegen-output" {
  context = "jsonschema"
  target = "ruby-codegen-output"
  output = ["ruby/lib/cucumber"]
}

target "ruby-test" {
  context = "ruby"
  contexts = {
     schema-codegen = "target:ruby-codegen-output",
  }
}