# frozen_string_literal: true

require 'json'
require 'cucumber-compatibility-kit'

module Cucumber
  module Messages
    describe 'messages acceptance tests' do
      Dir.entries('../testdata').filter { |file| File.extname(file) == ".ndjson" }.each do |example| 
        context "with the '#{example}'" do
          it 'deserializes and serializes messages in the ndjson file' do
            File.open("../testdata/#{example}", 'r:utf-8') do |file|
              file.each_line do |message|
                # Check that the Envelope re-generated message equals the originally parsed message
                expect(JSON.parse(Envelope.from_json(message).to_json)).to eq(JSON.parse(message))
              end
            end
          end
        end
      end
    end
  end
end
