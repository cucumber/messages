package io.cucumber.messages;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;


class ProtocolVersionTest {

    @Test
    void should_have_a_resource_bundle_version() {
        String version = ProtocolVersion.getVersion();
        assertThat(version).matches("\\d+\\.\\d+\\.\\d+(-SNAPSHOT)?");
    }

}
