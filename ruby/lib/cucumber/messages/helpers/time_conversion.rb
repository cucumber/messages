# frozen_string_literal: true

module Cucumber
  module Messages
    module Helpers
      module TimeConversion
        NANOSECONDS_PER_SECOND = 1_000_000_000

        def seconds_to_duration(seconds_float)
          seconds, decimal = seconds_float.to_s.split('.')
          nanos = decimal.to_s.ljust(9, '0').to_i
          { 'seconds' => seconds.to_i, 'nanos' => nanos }
        end

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
