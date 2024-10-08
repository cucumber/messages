<?php

declare(strict_types=1);

/**
 * This code was auto-generated by {this script}[https://github.com/cucumber/messages/blob/main/codegen/codegen.rb]
 */

namespace Cucumber\Messages;

use JsonSerializable;
use Cucumber\Messages\DecodingException\SchemaViolationException;

/**
 * Represents the ParseError message in Cucumber's message protocol
 * @see https://github.com/cucumber/messages
 *
 */
final class ParseError implements JsonSerializable
{
    use JsonEncodingTrait;

    /**
     * Construct the ParseError with all properties
     *
     */
    public function __construct(
        public readonly SourceReference $source = new SourceReference(),
        public readonly string $message = '',
    ) {
    }

    /**
     * @throws SchemaViolationException
     *
     * @internal
     */
    public static function fromArray(array $arr): self
    {
        self::ensureSource($arr);
        self::ensureMessage($arr);

        return new self(
            SourceReference::fromArray($arr['source']),
            (string) $arr['message'],
        );
    }

    /**
     * @psalm-assert array{source: array} $arr
     */
    private static function ensureSource(array $arr): void
    {
        if (!array_key_exists('source', $arr)) {
            throw new SchemaViolationException('Property \'source\' is required but was not found');
        }
        if (array_key_exists('source', $arr) && !is_array($arr['source'])) {
            throw new SchemaViolationException('Property \'source\' was not array');
        }
    }

    /**
     * @psalm-assert array{message: string|int|bool} $arr
     */
    private static function ensureMessage(array $arr): void
    {
        if (!array_key_exists('message', $arr)) {
            throw new SchemaViolationException('Property \'message\' is required but was not found');
        }
        if (array_key_exists('message', $arr) && is_array($arr['message'])) {
            throw new SchemaViolationException('Property \'message\' was array');
        }
    }
}
