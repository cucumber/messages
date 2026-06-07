using Io.Cucumber.Messages.Types;
using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Cucumber.Messages
{
    /// <summary>
    /// The NdjsonMessageReader class provides a stream based interface for reading Cucumber messages in ndjson format and produces Cucumber messages (Envelope)
    /// 
    /// The actual deserialization is delegated to a Func&lt;string, Envelope&gt;. This is done to avoid tying this library to any specific JSON library or library version.
    /// </summary>
    public class NdjsonMessageReader : IDisposable, System.Collections.Generic.IEnumerable<Envelope>
    {
        private readonly StreamReader _inputStreamReader;
        private readonly Func<string, Envelope> _deserializer;

        public NdjsonMessageReader(Stream inputStream, Func<string, Envelope> deserializer)
        {
            if (inputStream == null)
                throw new ArgumentNullException(nameof(inputStream));
            if (deserializer == null)
                throw new ArgumentNullException(nameof(deserializer));

            _inputStreamReader = new StreamReader(inputStream);
            _deserializer = deserializer;
        }

        public void Dispose()
        {
            _inputStreamReader.Close();
            _inputStreamReader.Dispose();
        }

        public System.Collections.Generic.IEnumerator<Envelope> GetEnumerator()
        {
            while(!_inputStreamReader.EndOfStream)
            {
                var line = _inputStreamReader.ReadLine();
                if (String.IsNullOrEmpty(line)) continue;
                Envelope envelope;
                try
                {
                    envelope = _deserializer(line);
                }
                catch (System.Exception e)
                {
                    throw new InvalidOperationException($"Could not parse JSON: {line}", e);
                }
                yield return envelope;
            }
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }
    }
}
