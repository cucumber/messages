using Io.Cucumber.Messages.Types;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cucumber.Messages.Specs
{
    internal class MessageToNdjsonWriterSUT : MessageToNdjsonWriter
    {
        public MessageToNdjsonWriterSUT(Stream stream) : base(stream, (StreamWriter streamWriter, Envelope envelope) => streamWriter.Write(NdjsonSerializer.Serialize(envelope)))
        {
        }
    }
}
