package io.cucumber.messages;

import io.cucumber.messages.types.Location;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class LocationComparatorTest {
    
    final LocationComparator comparator = new LocationComparator();
    
    @Test
    void isEqual(){
        Location a = new Location(3, 14);
        Location b = new Location(3, 14);
        assertThat(comparator.compare(a, b)).isZero();
    }
    
    @Test
    void isSmallerOnLine(){
        Location a = new Location(2, 14);
        Location b = new Location(3, 14);
        assertThat(comparator.compare(a, b)).isNegative();
    }
    
    @Test
    void isSmallerOnColum(){
        Location a = new Location(3, 13);
        Location b = new Location(3, 14);
        assertThat(comparator.compare(a, b)).isNegative();
    }
    @Test
    void isSmallerAbsentColumn(){
        Location a = new Location(3, null);
        Location b = new Location(3, 14);
        assertThat(comparator.compare(a, b)).isNegative();
    }
    
    @Test
    void isLargerOnLine(){
        Location a = new Location(4, 14);
        Location b = new Location(3, 14);
        assertThat(comparator.compare(a, b)).isPositive();
    }
    
    @Test
    void isLargerOnColumn(){
        Location a = new Location(3, 15);
        Location b = new Location(3, 14);
        assertThat(comparator.compare(a, b)).isPositive();
    }
    
    @Test
    void isLargerAbsentColumn(){
        Location a = new Location(3, 15);
        Location b = new Location(3, null);
        assertThat(comparator.compare(a, b)).isPositive();
    }
}
