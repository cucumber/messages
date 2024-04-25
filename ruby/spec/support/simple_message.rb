module Cucumber
  module Messages
    class SimpleMessage < Message
      attr_reader :is_nil, :is_string, :is_array, :is_number

      def initialize(is_nil: nil, is_string: '', is_array: [], is_number: 0)
        @is_nil = is_nil
        @is_string = is_string
        @is_array = is_array
        @is_number = is_number
      end
    end
  end
end
