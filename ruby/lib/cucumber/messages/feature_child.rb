# frozen_string_literal: true

# The code was auto-generated by {this script}[https://github.com/cucumber/messages/blob/main/codegen/codegen.rb]
module Cucumber
  module Messages
    ##
    # Represents the FeatureChild message in Cucumber's {message protocol}[https://github.com/cucumber/messages].
    ##
    #
    # A child node of a `Feature` node
    ##
    class FeatureChild < Message
      attr_reader :rule

      attr_reader :background

      attr_reader :scenario

      def initialize(
        rule: nil,
        background: nil,
        scenario: nil
      )
        @rule = rule
        @background = background
        @scenario = scenario
        super()
      end

      ##
      # Returns a new FeatureChild from the given hash.
      # If the hash keys are camelCased, they are properly assigned to the
      # corresponding snake_cased attributes.
      #
      #   Cucumber::Messages::FeatureChild.from_h(some_hash) # => #<Cucumber::Messages::FeatureChild:0x... ...>
      ##
      def self.from_h(hash)
        return nil if hash.nil?

        new(
          rule: Rule.from_h(hash[:rule]),
          background: Background.from_h(hash[:background]),
          scenario: Scenario.from_h(hash[:scenario])
        )
      end
    end
  end
end
