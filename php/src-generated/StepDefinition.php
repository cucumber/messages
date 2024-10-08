<?php

declare(strict_types=1);

/**
 * This code was auto-generated by {this script}[https://github.com/cucumber/messages/blob/main/codegen/codegen.rb]
 */

namespace Cucumber\Messages;

use JsonSerializable;
use Cucumber\Messages\DecodingException\SchemaViolationException;

/**
 * Represents the StepDefinition message in Cucumber's message protocol
 * @see https://github.com/cucumber/messages
 *
 */
final class StepDefinition implements JsonSerializable
{
    use JsonEncodingTrait;

    /**
     * Construct the StepDefinition with all properties
     *
     */
    public function __construct(
        public readonly string $id = '',
        public readonly StepDefinitionPattern $pattern = new StepDefinitionPattern(),
        public readonly SourceReference $sourceReference = new SourceReference(),
    ) {
    }

    /**
     * @throws SchemaViolationException
     *
     * @internal
     */
    public static function fromArray(array $arr): self
    {
        self::ensureId($arr);
        self::ensurePattern($arr);
        self::ensureSourceReference($arr);

        return new self(
            (string) $arr['id'],
            StepDefinitionPattern::fromArray($arr['pattern']),
            SourceReference::fromArray($arr['sourceReference']),
        );
    }

    /**
     * @psalm-assert array{id: string|int|bool} $arr
     */
    private static function ensureId(array $arr): void
    {
        if (!array_key_exists('id', $arr)) {
            throw new SchemaViolationException('Property \'id\' is required but was not found');
        }
        if (array_key_exists('id', $arr) && is_array($arr['id'])) {
            throw new SchemaViolationException('Property \'id\' was array');
        }
    }

    /**
     * @psalm-assert array{pattern: array} $arr
     */
    private static function ensurePattern(array $arr): void
    {
        if (!array_key_exists('pattern', $arr)) {
            throw new SchemaViolationException('Property \'pattern\' is required but was not found');
        }
        if (array_key_exists('pattern', $arr) && !is_array($arr['pattern'])) {
            throw new SchemaViolationException('Property \'pattern\' was not array');
        }
    }

    /**
     * @psalm-assert array{sourceReference: array} $arr
     */
    private static function ensureSourceReference(array $arr): void
    {
        if (!array_key_exists('sourceReference', $arr)) {
            throw new SchemaViolationException('Property \'sourceReference\' is required but was not found');
        }
        if (array_key_exists('sourceReference', $arr) && !is_array($arr['sourceReference'])) {
            throw new SchemaViolationException('Property \'sourceReference\' was not array');
        }
    }
}
