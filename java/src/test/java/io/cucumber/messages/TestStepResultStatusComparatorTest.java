package io.cucumber.messages;

import io.cucumber.messages.types.TestStepResultStatus;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static io.cucumber.messages.types.TestStepResultStatus.AMBIGUOUS;
import static io.cucumber.messages.types.TestStepResultStatus.FAILED;
import static io.cucumber.messages.types.TestStepResultStatus.PASSED;
import static io.cucumber.messages.types.TestStepResultStatus.PENDING;
import static io.cucumber.messages.types.TestStepResultStatus.SKIPPED;
import static io.cucumber.messages.types.TestStepResultStatus.UNDEFINED;
import static io.cucumber.messages.types.TestStepResultStatus.UNKNOWN;
import static org.assertj.core.api.Assertions.assertThat;

class TestStepResultStatusComparatorTest {

    final TestStepResultStatusComparator comparator = new TestStepResultStatusComparator();
    
    @Test
    void test(){
        List<TestStepResultStatus> values = Arrays.asList(TestStepResultStatus.values());
        Collections.shuffle(values);
        values.sort(comparator);
        assertThat(values).containsExactly(
                UNKNOWN,
                PASSED,
                SKIPPED,
                PENDING,
                UNDEFINED,
                AMBIGUOUS,
                FAILED
        );
    }
}
