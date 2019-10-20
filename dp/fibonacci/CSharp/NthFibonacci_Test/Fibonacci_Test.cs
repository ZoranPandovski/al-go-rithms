using System.Collections;
using System.Collections.Generic;
using System.Numerics;
using NthFibonacci;
using Xunit;

namespace NthFibonacci_Test
{
    public class Fibonacci_Test
    {
        public static IEnumerable<object[]> Data => new List<object[]>
        {
            new object[] { (BigInteger)17, (BigInteger)1597 },
            new object[] { (BigInteger)25, (BigInteger)75025 },
            new object[] { (BigInteger)31, (BigInteger)1346269 },
        };
        
        [Theory]
        [MemberData(nameof(Data))]
        public void Should_Return_Correct_Number(BigInteger nth, BigInteger expected)
        {
            Assert.Equal(Fibonacci.NthFib(nth), expected);
        }
    }
}