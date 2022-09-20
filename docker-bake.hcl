group "default" {
  targets = [
    "ruby-codegen",
    "ruby-test",
  ]
}

target "ruby-codegen" {
  target = "ruby-codegen-output"
  output = ["ruby/lib/cucumber"]
}

target "ruby-test" {
  target = "ruby-test"
}