# frozen_string_literal: true

# The code was auto-generated by {this script}[https://github.com/cucumber/messages/blob/main/codegen/codegen.rb]
module Cucumber
  module Messages
    ##
    # Represents the UndefinedParameterType message in Cucumber's {message protocol}[https://github.com/cucumber/messages].
    ##
    ##
    class UndefinedParameterType < Message
      attr_reader :expression

      attr_reader :name

      def initialize(
        expression: '',
        name: ''
      )
        @expression = expression
        @name = name
        super()
      end

      ##
      # Returns a new UndefinedParameterType from the given hash.
      # If the hash keys are camelCased, they are properly assigned to the
      # corresponding snake_cased attributes.
      #
      #   Cucumber::Messages::UndefinedParameterType.from_h(some_hash) # => #<Cucumber::Messages::UndefinedParameterType:0x... ...>
      ##
      def self.from_h(hash)
        return nil if hash.nil?

        new(
          expression: hash[:expression],
          name: hash[:name]
        )
      end
    end
  end
end
