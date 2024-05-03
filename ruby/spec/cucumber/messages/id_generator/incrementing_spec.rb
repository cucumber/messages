describe Cucumber::Messages::IdGenerator::Incrementing do
  subject(:generator) { described_class.new }

  describe '#new_id' do
    it 'returns 0 the first time' do
      expect(generator.new_id).to eq('0')
    end

    it 'increments on every call' do
      expect(generator.new_id).to eq('0')
      expect(generator.new_id).to eq('1')
      expect(generator.new_id).to eq('2')
    end
  end
end
