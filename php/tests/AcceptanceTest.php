<?php


use Cucumber\Messages\DecodingException;
use Cucumber\Messages\Envelope;
use Cucumber\Messages\Streams\NdJson\NdJsonStreamReader;
use Cucumber\Messages\Streams\NdJson\NdJsonStreamWriter;
use PHPUnit\Framework\TestCase;

class AcceptanceTest extends TestCase
{
    /** @dataProvider provideJsonLines
     * @throws DecodingException
     * @throws JsonException
     */
    public function testAllNdJsonSurvivesDecodingThenEncoding(string $json): void
    {
        self::assertNotEmpty($json);

        $envelope = Envelope::fromJson($json);
        $newJson = $envelope->asJson();

        self::assertJsonStringEqualsJsonString($json, $newJson);
    }

    /** @dataProvider provideNdJsonFilenames */
    public function testAllFileStreamsSurviveDecodingThenEncoding(string $filename): void
    {
        $sourceHandle = fopen($filename, 'r');
        $destHandle = fopen('php://memory', 'w');

        $reader = NdJsonStreamReader::fromFileHandle($sourceHandle);
        $writer = NdJsonStreamWriter::fromFileHandle($destHandle);

        $writer->writeEnvelopes($reader->envelopes());

        rewind($sourceHandle);
        rewind($destHandle);

        while (!feof($sourceHandle)) {
            $sourceLine = fgets($sourceHandle);
            $destLine = fgets($destHandle);

            if (empty($sourceLine) || empty($destLine)) {
                self::fail("Blank line in " . $filename);
            }

            self::assertJsonStringEqualsJsonString($sourceLine, $destLine);
        }

        // we exhausted source so dest should also be at end
        self::assertTrue(feof($destHandle));
    }

    /**
     * @return Generator<string, array{0: string}>
     */
    public static function provideJsonLines(): Generator
    {
        foreach (AcceptanceTest::getSampleFiles() as $filename) {
            foreach (file($filename) ?: [] as $lineNumber => $line) {
                // key is provided for better error messages
                $key = realpath($filename) . ':' . $lineNumber;
                yield $key => [$line];
            }
        }
    }

    /**
     * @return Generator<string, array{0: string}>
     */
    public static function provideNdJsonFilenames(): Generator
    {
        foreach (AcceptanceTest::getSampleFiles() as $filename) {
            yield $filename => [$filename];
        }
    }

    /**
     * @return array<string>
     */
    private static function getSampleFiles(): array
    {
        // Note: This test setup is not ideal. The minimal.feature.ndjson
        // will break whenever the schema for a feature file is updated.
        //
        // It would be better to specifically target known problems.
        // However there are currently no known problems (because these
        // tests originally tested against the CCK but that caused
        // circular dependencies).
        return glob(__DIR__ . '/Samples/*.ndjson') ?: [];
    }
}
