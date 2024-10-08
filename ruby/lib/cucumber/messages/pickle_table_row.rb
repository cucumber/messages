# frozen_string_literal: true

# The code was auto-generated by {this script}[https://github.com/cucumber/messages/blob/main/codegen/codegen.rb]
module Cucumber
  module Messages
    ##
    # Represents the PickleTableRow message in Cucumber's {message protocol}[https://github.com/cucumber/messages].
    ##
    ##
    class PickleTableRow < Message
      attr_reader :cells

      def initialize(
        cells: []
      )
        @cells = cells
        super()
      end

      ##
      # Returns a new PickleTableRow from the given hash.
      # If the hash keys are camelCased, they are properly assigned to the
      # corresponding snake_cased attributes.
      #
      #   Cucumber::Messages::PickleTableRow.from_h(some_hash) # => #<Cucumber::Messages::PickleTableRow:0x... ...>
      ##
      def self.from_h(hash)
        return nil if hash.nil?

        new(
          cells: hash[:cells]&.map { |item| PickleTableCell.from_h(item) }
        )
      end
    end
  end
end
