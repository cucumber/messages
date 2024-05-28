# frozen_string_literal: true

describe Cucumber::Messages::Helpers::IdGenerator::UUID do
  subject(:generator) { described_class.new }

  describe '#new_id' do
    it 'generates a new UUID' do
      expect(SecureRandom).to receive(:uuid)

      generator.new_id
    end
  end
end
