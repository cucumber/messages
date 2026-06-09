package io.cucumber.messages;

import com.fasterxml.jackson.core.JsonGenerator;
import com.fasterxml.jackson.databind.DeserializationFeature;
import com.fasterxml.jackson.databind.MapperFeature;
import com.fasterxml.jackson.databind.SerializationFeature;
import com.fasterxml.jackson.databind.cfg.ConstructorDetector;
import com.fasterxml.jackson.databind.introspect.AnnotatedMember;
import com.fasterxml.jackson.databind.introspect.NopAnnotationIntrospector;
import com.fasterxml.jackson.databind.json.JsonMapper;
import com.fasterxml.jackson.databind.module.SimpleModule;
import com.fasterxml.jackson.datatype.jdk8.Jdk8Module;
import org.jspecify.annotations.Nullable;

import java.io.Serial;

import static com.fasterxml.jackson.annotation.JsonInclude.Value;
import static com.fasterxml.jackson.annotation.JsonInclude.Include.NON_ABSENT;

final class Jackson {
    static final JsonMapper OBJECT_MAPPER = JsonMapper.builder()
            .addModule(new Jdk8Module())
            .addModule(new CucumberParameterNamesModule())
            .defaultPropertyInclusion(Value.construct(NON_ABSENT, NON_ABSENT))
            .constructorDetector(ConstructorDetector.USE_PROPERTIES_BASED)
            .enable(SerializationFeature.WRITE_ENUMS_USING_TO_STRING)
            .enable(DeserializationFeature.READ_ENUMS_USING_TO_STRING)
            .enable(DeserializationFeature.USE_LONG_FOR_INTS)
            .disable(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES)
            .disable(JsonGenerator.Feature.AUTO_CLOSE_TARGET)
            .disable(MapperFeature.CAN_OVERRIDE_ACCESS_MODIFIERS)
            .build();

    private Jackson() {
        /* no-op */
    }

    static final class CucumberParameterNamesModule extends SimpleModule {
        @Serial
        private static final long serialVersionUID = 1L;

        CucumberParameterNamesModule() {
            super("CucumberParameterNamesModule");
        }

        @Override
        public void setupModule(SetupContext context) {
            super.setupModule(context);
            context.insertAnnotationIntrospector(new PropertyNameAnnotationIntrospector());
        }

        @Override
        public int hashCode() {
            return getClass().hashCode();
        }

        @Override
        public boolean equals(Object o) {
            return this == o;
        }

        static final class PropertyNameAnnotationIntrospector extends NopAnnotationIntrospector {
            @Serial
            private static final long serialVersionUID = 1L;

            @Override
            public @Nullable String findImplicitPropertyName(AnnotatedMember m) {
                Property annotation = m.getAnnotation(Property.class);
                if (annotation == null) {
                    return null;
                }
                return annotation.value();
            }
        }

    }
}
