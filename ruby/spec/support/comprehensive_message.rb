require_relative 'simple_message'

module Cucumber
  module Messages
    class ComprehensiveMessage < Message
      attr_reader :simple_message, :message_array, :is_enum

      def initialize(simple_message: SimpleMessage.new, message_array: [SimpleMessage.new, SimpleMessage.new], is_enum: EnumMessage::ENUM)
        @simple_message = simple_message
        @message_array = message_array
        @is_enum = is_enum
        super()
      end

      def self.message_array_from_h(hash)
        SimpleMessage.from_h(hash)
      end
    end
  end
end
