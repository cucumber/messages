# frozen_string_literal: true

require 'cucumber/messages/helpers/id_generator'
require 'cucumber/messages/helpers/ndjson_to_message_enumerator'
require 'cucumber/messages/helpers/test_step_result_comparator'
require 'cucumber/messages/helpers/time_conversion'

require 'cucumber/messages/message'

Dir["#{File.dirname(__FILE__)}/messages/*.rb"].each { |file| require file }

module Cucumber
  module Messages
    VERSION = File.read(File.expand_path('../../VERSION', __dir__)).strip
  end
end
