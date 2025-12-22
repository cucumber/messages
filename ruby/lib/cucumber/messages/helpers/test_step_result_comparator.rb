# frozen_string_literal: true

module Cucumber
  module Messages
    module Helpers
      module TestStepResultComparator
        def worse_result(result_a, result_b)
          ranking[result_a] > ranking[result_b] ? result_a : result_b
        end

        def better_result(result_a, result_b)
          ranking[result_a] < ranking[result_b] ? result_a : result_b
        end

        private

        def ranking
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
