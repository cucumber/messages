group "default" {
  targets = [
    "codegen",
    "test",
  ]
}

group "codegen" {
  targets = [
    "go-codegen",
    "java-codegen",
    "javascript-codegen",
    "perl-codegen",
    "php-codegen",
    "ruby-codegen",
  ]
}

group "test" {
  targets = [
    "go-test",
    "java-test",
    "javascript-test",
    "php-test",
    "ruby-test",
  ]
}

target "elixir-test" {
  context = "elixir"
  target = "tested"
}

target "cpp-codegen" {
  context = "jsonschema"
  target = "output"
  args = {
    LANGUAGE = "cpp",
  }
  output = ["cpp/"]
}

target "cpp-test" {
  context = "cpp"
  target = "tested"
  contexts = {
    schema-codegen = "target:cpp-codegen",
  }
}

target "go-codegen" {
  context = "jsonschema"
  target = "output"
  args = {
    LANGUAGE = "go",
  }
  output = ["go"]
}

target "go-test" {
  context = "go"
  target = "tested"
  contexts = {
    schema-codegen = "target:go-codegen",
  }
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
  target = "tested"
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
  target = "tested"
  contexts = {
    schema-codegen = "target:javascript-codegen",
  }
}

target "perl-codegen" {
  context = "jsonschema"
  target = "output"
  args = {
    LANGUAGE = "perl",
  }
  output = ["perl/lib/Cucumber/"]
}

target "perl-test" {
  context = "perl"
  target = "tested"
  contexts = {
    schema-codegen = "target:perl-codegen",
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
  target = "tested"
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
  target = "tested"
  contexts = {
     schema-codegen = "target:ruby-codegen",
  }
}
