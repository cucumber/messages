require 'cucumber/messages/message/deserialization'
require 'cucumber/messages/message/serialization'

module Cucumber
  module Messages
    class Message
      extend Cucumber::Messages::Message::Deserialization
      include Cucumber::Messages::Message::Serialization
    end
  end
end
