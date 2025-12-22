# frozen_string_literal: true

module Cucumber
  module Messages
    module Helpers
      module TestStepResultComparator
        def test_step_result_rankings
          {
            TestStepResultStatus::UNKNOWN => 0,
            TestStepResultStatus::PASSED => 1,
            TestStepResultStatus::SKIPPED => 2,
            TestStepResultStatus::PENDING => 3,
            TestStepResultStatus::UNDEFINED => 4,
            TestStepResultStatus::AMBIGUOUS => 5,
            TestStepResultStatus::FAILED => 6
          }
        end
      end
    end
  end
end
