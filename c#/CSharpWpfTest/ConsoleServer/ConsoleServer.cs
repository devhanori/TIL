using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Sockets;
using System.Net;

// 동기 Console 서버 연습

namespace ConsoleServer
{
    public class ConsoleServer
    {
        static void Main(string[] args)
        {
            TcpListener server = new TcpListener(IPAddress.Any, 9999);

            server.Start();

            // Client 기다림, Blocking
            TcpClient client = server.AcceptTcpClient();
            Console.WriteLine("클라이언트가 접속");

            while(true)
            {
                byte[] bytes = new byte[1024];

                client.GetStream().Read(bytes, 0, bytes.Length);

                string strData = Encoding.Default.GetString(bytes);

                Console.WriteLine(strData);

                // 공백 문자열 제거
                int endPoint = strData.IndexOf('\0');
                string parsedMessage = strData.Substring(0, endPoint + 1);

                Console.WriteLine(parsedMessage);
            }
        }
    }
}
