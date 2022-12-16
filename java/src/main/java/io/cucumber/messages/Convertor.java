package io.cucumber.messages;

import io.cucumber.messages.types.Duration;
import io.cucumber.messages.types.Exception;
import io.cucumber.messages.types.Timestamp;

public final class Convertor {

    private Convertor(){

    }

    public static Exception toMessage(Throwable t) {
        return new Exception(t.getClass().getName(), t.getMessage());
    }

    public static Timestamp toMessage(java.time.Instant instant) {
        return new Timestamp(instant.getEpochSecond(), (long) instant.getNano());
    }

    public static Duration toMessage(java.time.Duration duration) {
        return new Duration(duration.getSeconds(), (long) duration.getNano());
    }

    public static java.time.Instant toInstant(Timestamp timestamp) {
        return java.time.Instant.ofEpochSecond(timestamp.getSeconds(), timestamp.getNanos());
    }

    public static java.time.Duration toDuration(Duration duration) {
        return java.time.Duration.ofSeconds(duration.getSeconds(), duration.getNanos());
    }


}
