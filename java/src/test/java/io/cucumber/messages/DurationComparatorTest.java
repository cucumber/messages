package io.cucumber.messages;

import io.cucumber.messages.types.Duration;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class DurationComparatorTest {
    
    final DurationComparator comparator = new DurationComparator();
    
    @Test
    void isEqual(){
        Duration a = new Duration(3L, 14L);
        Duration b = new Duration(3L, 14L);
        assertThat(comparator.compare(a, b)).isZero();
    }
    
    @Test
    void isSmallerOnSeconds(){
        Duration a = new Duration(2L, 14L);
        Duration b = new Duration(3L, 14L);
        assertThat(comparator.compare(a, b)).isNegative();
    }
    
    @Test
    void isSmallerOnNanos(){
        Duration a = new Duration(3L, 13L);
        Duration b = new Duration(3L, 14L);
        assertThat(comparator.compare(a, b)).isNegative();
    }
    
    @Test
    void isLargerOnSeconds(){
        Duration a = new Duration(4L, 14L);
        Duration b = new Duration(3L, 14L);
        assertThat(comparator.compare(a, b)).isPositive();
    }
    
    @Test
    void isLargerOnNanos(){
        Duration a = new Duration(3L, 15L);
        Duration b = new Duration(3L, 14L);
        assertThat(comparator.compare(a, b)).isPositive();
    }
}
