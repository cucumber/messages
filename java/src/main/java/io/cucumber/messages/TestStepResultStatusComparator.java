package io.cucumber.messages;

import io.cucumber.messages.types.TestStepResultStatus;

import java.util.Comparator;

/**
 * Orders test step results from least to most severe.
 */
@SuppressWarnings("EnumOrdinal")
public final class TestStepResultStatusComparator implements Comparator<TestStepResultStatus> {
    @Override
    public int compare(TestStepResultStatus a, TestStepResultStatus b) {
        return Integer.compare(a.ordinal(), b.ordinal());
    }
}
