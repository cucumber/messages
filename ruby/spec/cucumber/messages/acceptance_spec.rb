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
            File.open(ndjson_filepath, 'r:utf-8') do |io|
              io.each_line do |json|
                check(json)
              end
            end
          end
        end
      end

      def check(json)
        hash = JSON.parse(json)
        envelope = Envelope.from_json(json)
        new_json = envelope.to_json
        new_hash = JSON.parse(new_json)

        expect(new_hash).to eq(hash)
      end
    end
  end
end
