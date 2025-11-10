package io.cucumber.messages;

import io.cucumber.messages.types.Duration;
import io.cucumber.messages.types.Exception;
import io.cucumber.messages.types.Timestamp;

import java.io.PrintWriter;
import java.io.StringWriter;
import java.time.Instant;

import static java.util.Objects.requireNonNull;

public final class Convertor {

    private Convertor(){

    }

    public static Exception toMessage(Throwable throwable) {
        requireNonNull(throwable, "throwable may not be null");
        return new Exception(throwable.getClass().getName(), throwable.getMessage(), extractStackTrace(throwable));
    }

    private static String extractStackTrace(Throwable throwable) {
        StringWriter stringWriter = new StringWriter();
        try (PrintWriter printWriter = new PrintWriter(stringWriter)) {
            throwable.printStackTrace(printWriter);
        }
        return stringWriter.toString();
    }

    public static Timestamp toMessage(java.time.Instant instant) {
        requireNonNull(instant, "instant may not be null");
        return new Timestamp(instant.getEpochSecond(), instant.getNano());
    }

    public static Duration toMessage(java.time.Duration duration) {
        requireNonNull(duration, "duration may not be null");
        return new Duration(duration.getSeconds(), duration.getNano());
    }

    public static java.time.Instant toInstant(Timestamp timestamp) {
        requireNonNull(timestamp, "timestamp may not be null");
        return java.time.Instant.ofEpochSecond(timestamp.getSeconds(), timestamp.getNanos());
    }

    public static java.time.Duration toDuration(Duration duration) {
        requireNonNull(duration, "duration may not be null");
        return java.time.Duration.ofSeconds(duration.getSeconds(), duration.getNanos());
    }


}
