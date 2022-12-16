package io.cucumber.messages;

import io.cucumber.messages.types.Duration;
import io.cucumber.messages.types.Timestamp;

@Deprecated
@SuppressWarnings("unused")
public final class TimeConversion {

    private TimeConversion(){

    }

    public static Timestamp javaInstantToTimestamp(java.time.Instant instant) {
        return Convertor.toMessage(instant);
    }

    public static Duration javaDurationToDuration(java.time.Duration duration) {
        return Convertor.toMessage(duration);
    }

    public static java.time.Instant timestampToJavaInstant(Timestamp timestamp) {
        return Convertor.toInstant(timestamp);
    }

    public static java.time.Duration durationToJavaDuration(Duration duration) {
        return Convertor.toDuration(duration);
    }
}
