group "default" {
  targets = [
    "test",
  ]
}

group "codegen" {
  targets = [
    "java-codegen",
    "javascript-codegen",
    "php-codegen",
    "ruby-codegen",
  ]
}

group "test" {
  targets = [
    "java-test",
    "javascript-test",
    "php-test",
    "ruby-test",
  ]
}

target "java-codegen" {
  context = "jsonschema"
  target = "output"
  args = {
    LANGUAGE = "java",
  }
  output = ["java/src/generated/java/io/cucumber/messages/types"]
}

target "java-test" {
  context = "java"
  contexts = {
    schema-codegen = "target:java-codegen",
  }
}

target "javascript-codegen" {
  context = "jsonschema"
  target = "output"
  args = {
    LANGUAGE = "javascript",
  }
  output = ["javascript/src"]
}

target "javascript-test" {
  context = "javascript"
  contexts = {
    schema-codegen = "target:javascript-codegen",
  }
}

target "php-codegen" {
  context = "jsonschema"
  target = "output"
  args = {
    LANGUAGE = "php",
  }
  output = ["php/src-generated"]
}

target "php-test" {
  context = "php"
  contexts = {
    schema-codegen = "target:php-codegen",
  }
}

target "ruby-codegen" {
  context = "jsonschema"
  target = "output"
  args = {
    LANGUAGE = "ruby",
  }
  output = ["ruby/lib/cucumber"]
}

target "ruby-test" {
  context = "ruby"
  contexts = {
     schema-codegen = "target:ruby-codegen",
  }
}
