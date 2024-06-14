# frozen_string_literal: true

require 'json'
require 'erb'
require 'set'

clazz = Object.const_get(ARGV[0])
path = ARGV[1]
paths = File.file?(path) ? [path] : Dir["#{path}/*.json"]
codegen = clazz.new(paths)
template_name = ARGV[2]
codegen.generate(template_name)
