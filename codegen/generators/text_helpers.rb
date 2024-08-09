# frozen_string_literal: true

module Generator
  # Generator::TextHelpers
  # A few handy text helpers for converting text strings into different formats
  module TextHelpers
    private

    def capitalize(string)
      string.sub(/./, &:upcase)
    end

    # Adapted from rails -> https://github.com/rails/rails/blob/v6.1.3.2/activesupport/lib/active_support/inflector/methods.rb#L92
    def underscore(camel_cased_word)
      return camel_cased_word unless /[A-Z-]/.match?(camel_cased_word)

      camel_cased_word.gsub(/([A-Z\d]+)([A-Z][a-z])/, '\1_\2')
                      .gsub(/([a-z\d])([A-Z])/, '\1_\2')
                      .tr('-', '_')
                      .downcase
    end
  end
end
