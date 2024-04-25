
describe Cucumber::Messages::IdGenerator::Incrementing do
  subject { described_class.new }

  describe '#new_id' do
    it 'returns 0 the first time' do
      expect(subject.new_id).to eq('0')
    end

    it 'increments on every call' do
      expect(subject.new_id).to eq('0')
      expect(subject.new_id).to eq('1')
      expect(subject.new_id).to eq('2')
    end
  end
end

describe Cucumber::Messages::IdGenerator::UUID do
  subject { described_class.new }

  describe '#new_id' do
    it 'generates a UUID' do
      allowed_characters = '[0-9a-fA-F]'
      expect(subject.new_id).to match(/#{allowed_characters}{8}-#{allowed_characters}{4}-#{allowed_characters}{4}-#{allowed_characters}{4}-#{allowed_characters}{12}/)
    end
  end
end
