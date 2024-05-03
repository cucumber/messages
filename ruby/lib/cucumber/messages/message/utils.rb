module Cucumber
  module Messages
    class Message
      module Utils
        def self.included(other)
          other.extend(ClassMethods)
        end

        module ClassMethods
          ##
          # Converts strings to UpperCamelCase.
          #
          #   camelize('gherkin_document')                # => "GherkinDocument"
          #
          # This is a simplified version of the Ruby on Rails implementation
          # https://github.com/rails/rails/blob/v6.1.3.2/activesupport/lib/active_support/inflector/methods.rb#L69
          ##
          def camelize(term)
            camelized = term.to_s
            camelized.gsub!(/(?:_|(\/))([a-z\d]*)/i) { "#{Regexp.last_match(1)}#{Regexp.last_match(2).capitalize}" }
            camelized
          end
        end
      end
    end
  end
end
