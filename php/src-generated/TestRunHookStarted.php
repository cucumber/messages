<?php

declare(strict_types=1);

/**
 * This code was auto-generated by {this script}[https://github.com/cucumber/messages/blob/main/codegen/codegen.rb]
 */

namespace Cucumber\Messages;

use JsonSerializable;
use Cucumber\Messages\DecodingException\SchemaViolationException;

/**
 * Represents the TestRunHookStarted message in Cucumber's message protocol
 * @see https://github.com/cucumber/messages
 *
 */
final class TestRunHookStarted implements JsonSerializable
{
    use JsonEncodingTrait;

    /**
     * Construct the TestRunHookStarted with all properties
     *
     */
    public function __construct(

        /**
         * Unique identifier for this hook execution
         */
        public readonly string $id = '',

        /**
         * Identifier for the test run that this hook execution belongs to
         */
        public readonly string $testRunStartedId = '',

        /**
         * Identifier for the hook that will be executed
         */
        public readonly string $hookId = '',
        public readonly Timestamp $timestamp = new Timestamp(),
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
        self::ensureTestRunStartedId($arr);
        self::ensureHookId($arr);
        self::ensureTimestamp($arr);

        return new self(
            (string) $arr['id'],
            (string) $arr['testRunStartedId'],
            (string) $arr['hookId'],
            Timestamp::fromArray($arr['timestamp']),
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
     * @psalm-assert array{testRunStartedId: string|int|bool} $arr
     */
    private static function ensureTestRunStartedId(array $arr): void
    {
        if (!array_key_exists('testRunStartedId', $arr)) {
            throw new SchemaViolationException('Property \'testRunStartedId\' is required but was not found');
        }
        if (array_key_exists('testRunStartedId', $arr) && is_array($arr['testRunStartedId'])) {
            throw new SchemaViolationException('Property \'testRunStartedId\' was array');
        }
    }

    /**
     * @psalm-assert array{hookId: string|int|bool} $arr
     */
    private static function ensureHookId(array $arr): void
    {
        if (!array_key_exists('hookId', $arr)) {
            throw new SchemaViolationException('Property \'hookId\' is required but was not found');
        }
        if (array_key_exists('hookId', $arr) && is_array($arr['hookId'])) {
            throw new SchemaViolationException('Property \'hookId\' was array');
        }
    }

    /**
     * @psalm-assert array{timestamp: array} $arr
     */
    private static function ensureTimestamp(array $arr): void
    {
        if (!array_key_exists('timestamp', $arr)) {
            throw new SchemaViolationException('Property \'timestamp\' is required but was not found');
        }
        if (array_key_exists('timestamp', $arr) && !is_array($arr['timestamp'])) {
            throw new SchemaViolationException('Property \'timestamp\' was not array');
        }
    }
}
