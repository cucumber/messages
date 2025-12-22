# frozen_string_literal: true

describe Cucumber::Messages::Helpers::TestStepResultComparator do
  subject(:instance) { klass.new }

  let(:klass) do
    Class.new do
      include Cucumber::Messages::Helpers::TestStepResultComparator
    end
  end

  describe '#ranking' do
    it 'will rank the test step result statuses correctly' do
      expect(instance.ranking)
        .to eq(
          {
            Cucumber::Messages::TestStepResultStatus::UNKNOWN => 0,
            Cucumber::Messages::TestStepResultStatus::PASSED => 1,
            Cucumber::Messages::TestStepResultStatus::SKIPPED => 2,
            Cucumber::Messages::TestStepResultStatus::PENDING => 3,
            Cucumber::Messages::TestStepResultStatus::UNDEFINED => 4,
            Cucumber::Messages::TestStepResultStatus::AMBIGUOUS => 5,
            Cucumber::Messages::TestStepResultStatus::FAILED => 6
          }
        )
    end
  end
end
