using Io.Cucumber.Messages.Types;
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Cucumber.Messages
{
    /// <summary>
    ///  The NdjsonMessageWriter class provides a stream based interface for writing Cucumber messages in ndjson format 
    /// 
    /// The actual serialization is delegated to a Action&lt;StreamWriter, Envelope&gt;. This is done to avoid tying this library to any specific JSON library or library version.
    /// </summary>
    public class MessageToNdjsonWriter : IDisposable
    {
        private readonly StreamWriter _streamWriter;
        private readonly Action<StreamWriter, Envelope> _serializer;

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
            _streamWriter.Close();
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
