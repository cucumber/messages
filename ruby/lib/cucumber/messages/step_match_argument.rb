require 'cucumber/messages/message'

# The code was auto-generated by {this script}[https://github.com/cucumber/messages/blob/main/jsonschema/scripts/codegen.rb]
module Cucumber
  module Messages
    ##
    # Represents the StepMatchArgument message in Cucumber's {message protocol}[https://github.com/cucumber/messages].
    #
    # *
    #  Represents a single argument extracted from a step match and passed to a step definition.
    #  This is used for the following purposes:
    #  - Construct an argument to pass to a step definition (possibly through a parameter type transform)
    #  - Highlight the matched parameter in rich formatters such as the HTML formatter
    #
    #  This message closely matches the `Argument` class in the `cucumber-expressions` library.
    ##
    class StepMatchArgument < Message
      ##
      # *
      #  Represents the outermost capture group of an argument. This message closely matches the
      #  `Group` class in the `cucumber-expressions` library.
      ##
      attr_reader :group

      attr_reader :parameter_type_name

      def initialize(
        group: Group.new,
        parameter_type_name: nil
      )
        @group = group
        @parameter_type_name = parameter_type_name
        super()
      end

      ##
      # Returns a new StepMatchArgument from the given hash.
      # If the hash keys are camelCased, they are properly assigned to the
      # corresponding snake_cased attributes.
      #
      #   Cucumber::Messages::StepMatchArgument.from_h(some_hash) # => #<Cucumber::Messages::StepMatchArgument:0x... ...>
      ##
      def self.from_h(hash)
        return nil if hash.nil?

        new(
          group: Group.from_h(hash[:group]),
          parameter_type_name: hash[:parameterTypeName],
        )
      end
    end
  end
end