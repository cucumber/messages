<?php

namespace Cucumber\Messages;

use Cucumber\Messages\DecodingException\MalformedJsonException;
use Cucumber\Messages\DecodingException\SchemaViolationException;
use Cucumber\Messages\DecodingException\UnexpectedDecodingException;
use JsonSerializable;
use PHPUnit\Framework\TestCase;
use RuntimeException;

class JsonDecodingTraitTest extends TestCase
{
    public function testItCanDecodeSomeJsonToAnObject(): void
    {
        JsonDecodingTraitTestImpl::fromJson('[]');

        self::expectNotToPerformAssertions();
    }

    public function testItThrowsIfGivenInvalidJson(): void
    {
        $this->expectException(MalformedJsonException::class);

        JsonDecodingTraitTestImpl::fromJson('{');
    }

    public function testItThrowsIfGivenValidJsonThatIsNotArray(): void
    {
        $this->expectException(SchemaViolationException::class);

        JsonDecodingTraitTestImpl::fromJson('true');
    }

    public function testItRethrowsUnexpectedErrors(): void
    {
        $this->expectException(UnexpectedDecodingException::class);

        // 'oops' is hardcoded in BrokenJsonDecodingTraitTestImpl
        $this->expectExceptionMessage('Unexpected decoding error: "oops"');

        BrokenJsonDecodingTraitTestImpl::fromJson('[]');
    }
}

class JsonDecodingTraitTestImpl implements JsonSerializable
{
    use JsonEncodingTrait;

    public static function fromArray(array $arr): self
    {
        return new self();
    }
}

class BrokenJsonDecodingTraitTestImpl implements JsonSerializable
{
    use JsonEncodingTrait;

    public static function fromArray(array $arr): self
    {
        throw new RuntimeException('oops');
    }
}
