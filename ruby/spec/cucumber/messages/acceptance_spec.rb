require 'json'
require 'cucumber/messages'
require 'cucumber-compatibility-kit'

module Cucumber
  module Messages
    describe 'messages acceptance tests' do
      values = Dir["#{CCK::Examples.send(:features_folder_location)}/**/*.ndjson"]
      other_values = CCK::Examples.gherkin
      ndjson_dirs = other_values.flat_map { |example| Dir["#{CCK::Examples.feature_code_for(example)}/**/*.ndjson"] }
      ndjson_files = Dir["#{ndjson_dirs}/*.ndjson"]
      # old code
      # ndjson_files = Dir["#{Cucumber::CompatibilityKit::examples_path}/**/*.ndjson"]

      it 'must have ndjson_files as reference messages' do
        p values
        p ndjson_dirs
        p ndjson_files
        expect(ndjson_dirs).not_to be_empty
      end

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
