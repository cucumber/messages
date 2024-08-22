# frozen_string_literal: true

require_relative 'generators/text_helpers'

require_relative 'generators/base'

require_relative 'generators/cpp'
require_relative 'generators/dotnet'
require_relative 'generators/go'
require_relative 'generators/java'
require_relative 'generators/markdown'
require_relative 'generators/perl'
require_relative 'generators/php'
require_relative 'generators/ruby'
require_relative 'generators/typescript'

clazz = Object.const_get(ARGV[0])
template_name = ARGV[1]
clazz.new.generate(template_name)
