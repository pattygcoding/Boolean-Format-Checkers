using System;
using System.Linq;

class Program
{
    static void Main()
    {
        var testRuns = 500;
        
        bool allTrue = true;
        var random = new Random();

        for (int i = 0; i < testRuns; i++)
        {
            if (!GenerateExpression(random))
            {
                allTrue = false;
                break;
            }
        }

        Console.WriteLine(allTrue);
    }

    static bool GetRandomBoolean(Random random)
    {
        return random.NextDouble() < 0.5;
    }

    static bool GenerateExpression(Random random)
    {
        bool[] x = Enumerable.Range(0, 5).Select(_ => GetRandomBoolean(random)).ToArray();

        bool ex1 = (x[0] && x[1] && x[2]) || (x[3] && x[4]);
        bool ex2 = x[0] && x[1] && x[2] || x[3] && x[4];

        return ex1 == ex2;
    }
}
