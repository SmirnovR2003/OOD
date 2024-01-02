using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _10Sharp.Model
{
    public class RandomStringGenerator
    {
        
        private static readonly string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" +
            "abcdefghijklmnopqrstuvwxyz" +
            "0123456789";

        public string GenerateId(int length)
        {
            Random random = new Random();
            StringBuilder builder = new StringBuilder(length);

            for (int i = 0; i < length; ++i)
            {
                int index = random.Next(ALPHABET.Length);
                builder.Append(ALPHABET[index]);
            }
            return builder.ToString();
        }
    }
}
