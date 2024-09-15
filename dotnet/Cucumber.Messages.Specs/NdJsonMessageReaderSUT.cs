namespace Cucumber.Messages.Specs;

internal class NdjsonMessageReaderSUT : NdjsonMessageReader
{
    public NdjsonMessageReaderSUT(Stream inputStream) : base(inputStream, (string line) => NdjsonSerializer.Deserialize(line))
    {
    }
}
