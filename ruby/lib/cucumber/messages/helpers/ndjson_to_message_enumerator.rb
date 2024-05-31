# frozen_string_literal: true

require 'cucumber/messages'

module Cucumber
  module Messages
    module Helpers
      class NdjsonToMessageEnumerator < Enumerator
        def initialize(io)
          super() do |yielder|
            io.each_line do |line|
              next if line.strip.empty?

              begin
                m = Envelope.from_json(line)
              rescue StandardError
                raise "Not JSON: #{line.strip}"
              end
              yielder.yield(m)
            end
          end
        end
      end
    end
  end
end
