# frozen_string_literal: true

describe Cucumber::Messages::Helpers::IdGenerator::Incrementing do
  subject(:generator) { described_class.new }

  describe '#new_id' do
    it 'returns 0 the first time' do
      expect(generator.new_id).to eq('0')
    end

    it 'increments on every call' do
      rand(2..5).times do |value|
        expect(generator.new_id).to eq(value.to_s)
      end
    end
  end
end
