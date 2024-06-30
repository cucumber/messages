using System;
using System.Collections.Generic;
using System.Reflection;
using System.Text;

namespace Cucumber.Messages
{
    public class ProtocolVersion
    {
        public static string Version
        {
            get
            {
                return Assembly.GetExecutingAssembly().GetName().Version.ToString();
            }
        }
    }
}
