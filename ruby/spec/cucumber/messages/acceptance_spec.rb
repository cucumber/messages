require 'json'
require 'cucumber-compatibility-kit'

module Cucumber
  module Messages
    describe 'messages acceptance tests' do
      CCK::Examples.gherkin.each do |example_name|
        context "with the '#{example_name}' example" do
          let(:ndjson_filepath) { "#{CCK::Examples.feature_code_for(example_name)}/#{example_name}.feature.ndjson" }

          it 'has a ndjson reference filepath' do
            expect(File).to exist(ndjson_filepath)
          end

          it 'deserializes and serializes messages in the ndjson file' do
            File.open(ndjson_filepath, 'r:utf-8') do |file|
              file.each_line do |message|
                parsed_actual_message = JSON.parse(message)
                generated_message = Envelope.from_json(message).to_json
                parsed_regenerated_message = JSON.parse(generated_message)

                expect(parsed_regenerated_message).to eq(parsed_actual_message)
              end
            end
          end
        end
      end
    end
  end
end
