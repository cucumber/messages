# frozen_string_literal: true

# The code was auto-generated by {this script}[https://github.com/cucumber/messages/blob/main/codegen/codegen.rb]
module Cucumber
  module Messages
    ##
    # Represents the PickleStep message in Cucumber's {message protocol}[https://github.com/cucumber/messages].
    ##
    #
    # An executable step
    ##
    class PickleStep < Message
      attr_reader :argument

      ##
      # References the IDs of the source of the step. For Gherkin, this can be
      # the ID of a Step, and possibly also the ID of a TableRow
      ##
      attr_reader :ast_node_ids

      ##
      # A unique ID for the PickleStep
      ##
      attr_reader :id

      ##
      # The context in which the step was specified: context (Given), action (When) or outcome (Then).
      #
      # Note that the keywords `But` and `And` inherit their meaning from prior steps and the `*` 'keyword' doesn't have specific meaning (hence Unknown)
      ##
      attr_reader :type

      attr_reader :text

      def initialize(
        argument: nil,
        ast_node_ids: [],
        id: '',
        type: nil,
        text: ''
      )
        @argument = argument
        @ast_node_ids = ast_node_ids
        @id = id
        @type = type
        @text = text
        super()
      end

      ##
      # Returns a new PickleStep from the given hash.
      # If the hash keys are camelCased, they are properly assigned to the
      # corresponding snake_cased attributes.
      #
      #   Cucumber::Messages::PickleStep.from_h(some_hash) # => #<Cucumber::Messages::PickleStep:0x... ...>
      ##
      def self.from_h(hash)
        return nil if hash.nil?

        new(
          argument: PickleStepArgument.from_h(hash[:argument]),
          ast_node_ids: hash[:astNodeIds],
          id: hash[:id],
          type: hash[:type],
          text: hash[:text]
        )
      end
    end
  end
end
