<?php

declare(strict_types=1);

namespace Cucumber\Messages\Id;

final class UuidIdGenerator implements IdGenerator
{
    /**
     * Generates a v4 (random based) UUID
     *
     * @see https://datatracker.ietf.org/doc/html/rfc4122
     */
    #[\Override]
    public function newId(): string
    {
        $bytes = random_bytes(16);

        /**
         * set MSBs of octet 8 to 10xxxxxx. to indicate rfc4122 compliance
         *
         * @see https://datatracker.ietf.org/doc/html/rfc4122#section-4.1.1
         */
        $bytes[8] = $bytes[8]
            & "\x3F" // 0 the first 2 bits
            | "\x80" // raise 1st bit to 1
        ;

        /**
         * set MSBs of octet 6 to 0100xxxx. to indicate v4
         *
         * @see https://datatracker.ietf.org/doc/html/rfc4122#section-4.1.3
         */
        $bytes[6] = $bytes[6]
            & "\x0F" // 0 the first 4 bits
            | "\x40" // raise 2nd bit to 1
        ;

        $hex = bin2hex($bytes);
        return sprintf(
            '%s-%s-%s-%s-%s',
            substr($hex, 0, 8),
            substr($hex, 8, 4),
            substr($hex, 12, 4),
            substr($hex, 16, 4),
            substr($hex, 20, 12),
        );
    }
}
