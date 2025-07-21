package io.cucumber.messages;

import io.cucumber.messages.types.Location;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class LocationComparatorTest {
    
    final LocationComparator comparator = new LocationComparator();
    
    @Test
    void isEqual(){
        Location a = new Location(3L, 14L);
        Location b = new Location(3L, 14L);
        assertThat(comparator.compare(a, b)).isZero();
    }
    
    @Test
    void isSmallerOnLine(){
        Location a = new Location(2L, 14L);
        Location b = new Location(3L, 14L);
        assertThat(comparator.compare(a, b)).isNegative();
    }
    
    @Test
    void isSmallerOnColum(){
        Location a = new Location(3L, 13L);
        Location b = new Location(3L, 14L);
        assertThat(comparator.compare(a, b)).isNegative();
    }
    @Test
    void isSmallerAbsentColumn(){
        Location a = new Location(3L, null);
        Location b = new Location(3L, 14L);
        assertThat(comparator.compare(a, b)).isNegative();
    }
    
    @Test
    void isLargerOnLine(){
        Location a = new Location(4L, 14L);
        Location b = new Location(3L, 14L);
        assertThat(comparator.compare(a, b)).isPositive();
    }
    
    @Test
    void isLargerOnColumn(){
        Location a = new Location(3L, 15L);
        Location b = new Location(3L, 14L);
        assertThat(comparator.compare(a, b)).isPositive();
    }
    
    @Test
    void isLargerAbsentColumn(){
        Location a = new Location(3L, 15L);
        Location b = new Location(3L, null);
        assertThat(comparator.compare(a, b)).isPositive();
    }
}
