using Io.Cucumber.Messages.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xunit;

namespace Cucumber.Messages.Specs
{
    public class MessagesTest
    {

        [Fact]
        public void ThrowsWhenRequiredFieldsAreMissing()
        {
            Assert.Throws<ArgumentNullException>(() => new Background(null, null, null, null, null, null));
        }

        [Fact]
        public void IsValidWhenNoRequiredFieldsAreMissing()
        {
            // This should succeed as no constructor arguments to an Envelope are required.
            var env = new Envelope(null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null);
        }
    }
}
