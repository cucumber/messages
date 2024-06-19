# frozen_string_literal: true

require_relative 'generators/base'

require_relative 'generators/cpp'
require_relative 'generators/go'
require_relative 'generators/java'
require_relative 'generators/markdown'
require_relative 'generators/perl'
require_relative 'generators/php'
require_relative 'generators/ruby'
require_relative 'generators/typescript'

clazz = Object.const_get(ARGV[0])
path = ARGV[1]
paths = File.file?(path) ? [path] : Dir["#{path}/*.json"]
codegen = clazz.new(paths)
template_name = ARGV[2]
codegen.generate(template_name)
