require 'cucumber/messages/message'

# The code was auto-generated by {this script}[https://github.com/cucumber/messages/blob/main/jsonschema/scripts/codegen.rb]
module Cucumber
  module Messages
    ##
    # Represents the Ci message in Cucumber's {message protocol}[https://github.com/cucumber/messages].
    #
    # CI environment
    ##
    class Ci < Message
      ##
      # Name of the CI product, e.g. "Jenkins", "CircleCI" etc.
      ##
      attr_reader :name

      ##
      # Link to the build
      ##
      attr_reader :url

      ##
      # The build number. Some CI servers use non-numeric build numbers, which is why this is a string
      ##
      attr_reader :build_number

      attr_reader :git

      def initialize(
        name: '',
        url: nil,
        build_number: nil,
        git: nil
      )
        @name = name
        @url = url
        @build_number = build_number
        @git = git
        super()
      end

      ##
      # Returns a new Ci from the given hash.
      # If the hash keys are camelCased, they are properly assigned to the
      # corresponding snake_cased attributes.
      #
      #   Cucumber::Messages::Ci.from_h(some_hash) # => #<Cucumber::Messages::Ci:0x... ...>
      ##
      def self.from_h(hash)
        return nil if hash.nil?

        new(
          name: hash[:name],
          url: hash[:url],
          build_number: hash[:buildNumber],
          git: Git.from_h(hash[:git]),
        )
      end
    end
  end
end