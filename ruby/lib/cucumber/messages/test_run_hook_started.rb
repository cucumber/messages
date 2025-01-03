# frozen_string_literal: true

# The code was auto-generated by {this script}[https://github.com/cucumber/messages/blob/main/codegen/codegen.rb]
module Cucumber
  module Messages
    ##
    # Represents the TestRunHookStarted message in Cucumber's {message protocol}[https://github.com/cucumber/messages].
    ##
    ##
    class TestRunHookStarted < Message
      ##
      # Unique identifier for this hook execution
      ##
      attr_reader :id

      ##
      # Identifier for the test run that this hook execution belongs to
      ##
      attr_reader :test_run_started_id

      ##
      # Identifier for the hook that will be executed
      ##
      attr_reader :hook_id

      attr_reader :timestamp

      def initialize(
        id: '',
        test_run_started_id: '',
        hook_id: '',
        timestamp: Timestamp.new
      )
        @id = id
        @test_run_started_id = test_run_started_id
        @hook_id = hook_id
        @timestamp = timestamp
        super()
      end

      ##
      # Returns a new TestRunHookStarted from the given hash.
      # If the hash keys are camelCased, they are properly assigned to the
      # corresponding snake_cased attributes.
      #
      #   Cucumber::Messages::TestRunHookStarted.from_h(some_hash) # => #<Cucumber::Messages::TestRunHookStarted:0x... ...>
      ##
      def self.from_h(hash)
        return nil if hash.nil?

        new(
          id: hash[:id],
          test_run_started_id: hash[:testRunStartedId],
          hook_id: hash[:hookId],
          timestamp: Timestamp.from_h(hash[:timestamp])
        )
      end
    end
  end
end
