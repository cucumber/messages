package io.cucumber.messages;

import io.cucumber.messages.types.Timestamp;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class TimestampComparatorTest {
    
    final TimestampComparator comparator = new TimestampComparator();
    
    @Test
    void isEqual(){
        Timestamp a = new Timestamp(3L, 14);
        Timestamp b = new Timestamp(3L, 14);
        assertThat(comparator.compare(a, b)).isZero();
    }
    
    @Test
    void isSmallerOnSeconds(){
        Timestamp a = new Timestamp(2L, 14);
        Timestamp b = new Timestamp(3L, 14);
        assertThat(comparator.compare(a, b)).isNegative();
    }
    
    @Test
    void isSmallerOnNanos(){
        Timestamp a = new Timestamp(3L, 13);
        Timestamp b = new Timestamp(3L, 14);
        assertThat(comparator.compare(a, b)).isNegative();
    }
    
    @Test
    void isLargerOnSeconds(){
        Timestamp a = new Timestamp(4L, 14);
        Timestamp b = new Timestamp(3L, 14);
        assertThat(comparator.compare(a, b)).isPositive();
    }
    
    @Test
    void isLargerOnNanos(){
        Timestamp a = new Timestamp(3L, 15);
        Timestamp b = new Timestamp(3L, 14);
        assertThat(comparator.compare(a, b)).isPositive();
    }
}
