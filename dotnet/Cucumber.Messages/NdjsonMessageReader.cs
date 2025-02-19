using Io.Cucumber.Messages.Types;
using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;

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

                    // This checks for lines that might be valid json but not a valid Message
                    // It does allow an empty json node, eg "{}" to pass, creating an empty Envelope
                    if (EnvelopeIsEmpty(envelope) && !Regex.IsMatch(line, @"^\s*\{\s*\}\s*$"))
                        throw new InvalidOperationException($"JSON is not a valid Envelope");
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

        private static bool EnvelopeIsEmpty(Envelope message)
        {
            return (message.Attachment == null &&
                message.GherkinDocument == null &&
                message.Hook == null &&
                message.Meta == null &&
                message.ParameterType == null &&
                message.Pickle == null &&
                message.Source == null &&
                message.StepDefinition == null &&
                message.TestCase == null &&
                message.TestCaseFinished == null &&
                message.TestCaseStarted == null &&
                message.TestRunFinished == null &&
                message.TestRunHookFinished == null &&
                message.TestRunHookStarted == null &&
                message.TestRunStarted == null &&
                message.TestStepFinished == null &&
                message.TestStepStarted == null &&
                message.UndefinedParameterType == null &&
                message.ParseError == null);
        }
    }
}
