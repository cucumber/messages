# frozen_string_literal: true

require 'json'

module Cucumber
  module Messages
    describe 'messages acceptance tests' do
      CCK::Examples.gherkin.each do |example_name|
        context "with the '#{example_name}' example" do
          let(:ndjson_filepath) { "??.ndjson" }

          it 'has a ndjson reference filepath' do
            expect(File).to exist(ndjson_filepath)
          end

          it 'deserializes and serializes messages in the ndjson file' do
            File.open(ndjson_filepath, 'r:utf-8') do |file|
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
