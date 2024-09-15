using Io.Cucumber.Messages.Types;

namespace Cucumber.Messages.Specs;

internal class MessageToNdjsonWriterSUT : MessageToNdjsonWriter
{
    public MessageToNdjsonWriterSUT(Stream stream) : base(stream, (StreamWriter streamWriter, Envelope envelope) => streamWriter.Write(NdjsonSerializer.Serialize(envelope)))
    {
    }
}
