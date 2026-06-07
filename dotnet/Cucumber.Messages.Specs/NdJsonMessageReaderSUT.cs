using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cucumber.Messages.Specs
{
    internal class NdjsonMessageReaderSUT : NdjsonMessageReader
    {
        public NdjsonMessageReaderSUT(Stream inputStream) : base(inputStream, (string line) => NdjsonSerializer.Deserialize(line)) 
        {
        }
    }
}
