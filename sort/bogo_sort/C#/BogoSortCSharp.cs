//FYI: Commenting out lines 21 and 22 will allow this to run MUCH faster at the expense of the running commentary.
//(Writing to console is a very slow task)

namespace BogoSort
{
    internal class Program
    {
        static IList<int> inputList = new List<int> { 25, 1, 3, 4, 8, 2 }; //<-- Change this list to modify the test case.
        static Random rng = new Random();

        static void Main(string[] args)
        {
            IList<int> ourList = Load_List(inputList);
            Console.WriteLine("Here is the input list:");
            Print_List(ourList);

            int numberOfRandomisations = 0;
            while (!Check_If_Sorted(ourList))
            {
                ourList = Randomise_List(ourList);
                Console.WriteLine("Bogo Sort has failed to sort the list in this pass. The list has now been randomised:");
                Print_List(ourList); //Comment out this line and the line above for performance increase.
                numberOfRandomisations++;
            }
            Console.WriteLine("Bogo Sort has (somehow) sorted the list! Total number of passes: " + numberOfRandomisations);
        }

        static void Print_List(IList<int> list)
        {
            foreach (int element in list) Console.Write(element + " ");
            Console.Write("\n");
        }

        static IList<int> Load_List(IList<int> list)
        {
            IList<int> outputList = new List<int>();
            for (int i=0; i<list.Count; i++) outputList.Add(list[i]);
            return outputList;
        }

        static bool Check_If_Sorted(IList<int> list)
        {
            for (int i = 0; i < list.Count - 1; i++)
                if (list[i + 1] < list[i]) return false;
            return true;
        }

        static IList<int> Randomise_List(IList<int> list)
        {
            IList<int> randomisedList = list.OrderBy(a => rng.Next()).ToList();
            return randomisedList;
        }

    }
}