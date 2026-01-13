# frozen_string_literal: true

module Cucumber
  module Messages
    module Helpers
      module TimeConversion
        NANOSECONDS_PER_SECOND = 1_000_000_000

        def time_to_timestamp(time)
          Cucumber::Messages::Timestamp.new(seconds: time.to_i, nanos: time.nsec)
        end

        def timestamp_to_time(timestamp)
          Time.at(timestamp.seconds, timestamp.nanos, :nanosecond)
        end
      end
    end
  end
end
