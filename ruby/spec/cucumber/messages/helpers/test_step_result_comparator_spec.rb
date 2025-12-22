# frozen_string_literal: true

describe Cucumber::Messages::Helpers::TestStepResultComparator do
  subject(:instance) { klass.new }

  let(:klass) do
    Class.new do
      include Cucumber::Messages::Helpers::TestStepResultComparator
    end
  end
  let(:passing_1) { Cucumber::Messages::TestStepResultStatus::PASSED }
  let(:skipped_2) { Cucumber::Messages::TestStepResultStatus::SKIPPED }
  let(:ambiguous_5) { Cucumber::Messages::TestStepResultStatus::AMBIGUOUS }
  let(:failing_6) { Cucumber::Messages::TestStepResultStatus::FAILED }

  describe '#weaker_result' do
    it 'will determine if the first step is a weaker result than the second step' do
      expect(instance.weaker_result(failing_6, passing_1)).to eq(failing_6)
    end

    it 'will determine if the second step is a weaker result than the first step' do
      expect(instance.weaker_result(skipped_2, ambiguous_5)).to eq(ambiguous_5)
    end
  end

  describe '#stronger_result' do
    it 'will determine if the first step is a stronger result than the second step' do
      expect(instance.stronger_result(skipped_2, ambiguous_5)).to eq(skipped_2)
    end

    it 'will determine if the second step is a stronger result than the first step' do
      expect(instance.stronger_result(skipped_2, passing_1)).to eq(passing_1)
    end
  end
end
