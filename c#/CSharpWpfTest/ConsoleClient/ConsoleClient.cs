using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ConsoleClient
{
    public class ConsoleClient
    {
        private TcpClient client { get; set; } = null;
        public void Main(string[] args)
        {
            Run();
        }

        void Run()
        {
            Thread StartThread = new Thread(Start);
            StartThread.Start();
        }

        private void Start()
        {
            TcpClient client = null;
            while (true)
            {
                if (client == null)
                {
                    Connect();
                }
                Thread.Sleep(1000);
            }
        }

        public void Connect()
        {
            client = new TcpClient();
            client.Connect("127.0.0.1", 9999);
            byte[] buffer = Encoding.Default.GetBytes("Hello");
            client.GetStream().Write(buffer, 0, buffer.Length);
        }
    }
}
