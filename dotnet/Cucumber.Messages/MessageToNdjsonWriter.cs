using Io.Cucumber.Messages.Types;
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Cucumber.Messages
{
    public class MessageToNdjsonWriter : IDisposable
    {
        private StreamWriter _streamWriter;
        private Action<StreamWriter, Envelope> _serializer;

        public MessageToNdjsonWriter(Stream stream) : this(stream, (StreamWriter streamWriter, Envelope envelope) => streamWriter.Write(NdjsonSerializer.Serialize(envelope)))
        {
        }
        public MessageToNdjsonWriter(Stream stream, Action<StreamWriter, Envelope> serializer)
        {
            if (stream == null)
                throw new ArgumentNullException(nameof(stream));
            if (serializer == null)
                throw new ArgumentNullException(nameof(serializer));
            _streamWriter = new StreamWriter(stream);
            _serializer = serializer;
        }

        public void Dispose()
        {
            _streamWriter.Dispose();
        }

        public void Write(Envelope message)
        {
            if (message == null)
                throw new ArgumentNullException(nameof(message));
            _serializer(_streamWriter, message);
            _streamWriter.WriteLine();
            _streamWriter.Flush();
        }
    }
}
