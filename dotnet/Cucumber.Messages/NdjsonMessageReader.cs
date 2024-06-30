using Io.Cucumber.Messages.Types;
using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Cucumber.Messages
{
    public class NdjsonMessageReader : IDisposable, System.Collections.Generic.IEnumerable<Envelope>
    {
        private StreamReader _inputStreamReader;
        private Func<string, Envelope> _deserializer;

        public NdjsonMessageReader(Stream inputStream) : this( inputStream, (string line) => NdjsonSerializer.Deserialize<Envelope>(line)) { }
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
                catch (System.Text.Json.JsonException e)
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
