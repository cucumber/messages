describe Cucumber::Messages::IdGenerator::UUID do
  subject(:generator) { described_class.new }

  describe '#new_id' do
    it 'generates a UUID' do
      allowed_characters = '[0-9a-fA-F]'
      expect(generator.new_id).to match(/#{allowed_characters}{8}-#{allowed_characters}{4}-#{allowed_characters}{4}-#{allowed_characters}{4}-#{allowed_characters}{12}/)
    end
  end
end
