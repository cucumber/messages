<?php

declare(strict_types=1);

/**
 * This code was auto-generated by {this script}[https://github.com/cucumber/messages/blob/main/codegen/codegen.rb]
 */

namespace Cucumber\Messages;

use JsonSerializable;
use Cucumber\Messages\DecodingException\SchemaViolationException;

/**
 * Represents the TestRunHookFinished message in Cucumber's message protocol
 * @see https://github.com/cucumber/messages
 *
 */
final class TestRunHookFinished implements JsonSerializable
{
    use JsonEncodingTrait;

    /**
     * Construct the TestRunHookFinished with all properties
     *
     */
    public function __construct(

        /**
         * Identifier for the hook execution that has finished
         */
        public readonly string $testRunHookStartedId = '',
        public readonly TestStepResult $result = new TestStepResult(),
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
        self::ensureTestRunHookStartedId($arr);
        self::ensureResult($arr);
        self::ensureTimestamp($arr);

        return new self(
            (string) $arr['testRunHookStartedId'],
            TestStepResult::fromArray($arr['result']),
            Timestamp::fromArray($arr['timestamp']),
        );
    }

    /**
     * @psalm-assert array{testRunHookStartedId: string|int|bool} $arr
     */
    private static function ensureTestRunHookStartedId(array $arr): void
    {
        if (!array_key_exists('testRunHookStartedId', $arr)) {
            throw new SchemaViolationException('Property \'testRunHookStartedId\' is required but was not found');
        }
        if (array_key_exists('testRunHookStartedId', $arr) && is_array($arr['testRunHookStartedId'])) {
            throw new SchemaViolationException('Property \'testRunHookStartedId\' was array');
        }
    }

    /**
     * @psalm-assert array{result: array} $arr
     */
    private static function ensureResult(array $arr): void
    {
        if (!array_key_exists('result', $arr)) {
            throw new SchemaViolationException('Property \'result\' is required but was not found');
        }
        if (array_key_exists('result', $arr) && !is_array($arr['result'])) {
            throw new SchemaViolationException('Property \'result\' was not array');
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
