require 'json'
require 'cucumber/messages'
require 'cucumber-compatibility-kit'

module Cucumber
  module Messages
    describe 'messages acceptance tests' do
      ndjson_dirs = CCK::Examples.gherkin.flat_map { |example| Dir["#{CCK::Examples.feature_code_for(example)}/**/*.ndjson"] }
      ndjson_files = Dir["#{CCK::Examples.send(:features_folder_location)}/**/*.ndjson"]

      CCK::Examples.gherkin.each do |example_name|
        context "with the '#{example_name}' example" do
          let(:example) { example_name }
          let(:ndjson_file) { Dir["#{CCK::Examples.feature_code_for(example)}/**/*.ndjson"].first }

          it 'has a ndjson reference filepath' do
            expect(ndjson_file).not_to be_empty
          end

          it "deserialises and serialises messages in the ndjson file" do
            File.open(ndjson_file, 'r:utf-8') do |io|
              io.each_line do |json|
                check(json)
              end
            end
          end
        end
      end

      # it 'must have ndjson_files as reference messages' do
      #   expect(ndjson_dirs).not_to be_empty
      # end
      #
      # ndjson_files.each do |ndjson_file|
      #   it "deserialises and serialises messages in #{ndjson_file}" do
      #     File.open(ndjson_file, 'r:utf-8') do |io|
      #       io.each_line do |json|
      #         check(json)
      #       end
      #     end
      #   end
      # end

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
