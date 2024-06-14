# frozen_string_literal: true

require_relative 'codegen/base'

require_relative 'codegen/cpp'
require_relative 'codegen/go'
require_relative 'codegen/java'
require_relative 'codegen/markdown'
require_relative 'codegen/perl'
require_relative 'codegen/php'
require_relative 'codegen/ruby'
require_relative 'codegen/typescript'

clazz = Object.const_get(ARGV[0])
path = ARGV[1]
paths = File.file?(path) ? [path] : Dir["#{path}/*.json"]
codegen = clazz.new(paths)
template_name = ARGV[2]
codegen.generate(template_name)
