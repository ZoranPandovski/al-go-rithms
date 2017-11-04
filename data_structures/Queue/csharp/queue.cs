using System;
using System.Collections.Generic; // namepace for queue
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/// <summary>
/// 
/// QUEUE IMPLEMENTATION IN CSHARP
/// 
/// </summary>
namespace queue
{
    class Program
    {
        /// <summary>
        /// main function
        /// </summary>
        /// <param name="args"></param>
        static void Main(string[] args)
        {
            // declaring a new object of class Queue in System.Collections.Generic; namespace
            Queue<int> queue = new Queue<int>();  // queue will hold elements of int

            /*
             * adding 4 elements for demo
             * Enqueue is used to add element add the end
             * */
            Console.WriteLine("adding data");
            queue.Enqueue(10);
            queue.Enqueue(20);
            queue.Enqueue(30);
            queue.Enqueue(40);

            // printing data
            Console.Write("Queue (then) : ");
            foreach(int item in queue)
            {
                Console.Write("{0}\t", item);
            }


            /*
             * deleting 1 element for demo
             * Dequeue is used to delete element from the starting
             * */
            int val = queue.Dequeue();  // it will return the popped value
            Console.WriteLine("\n\ndeleting value");
            Console.WriteLine("deleted {0}", val);

            // printing the queue again
            Console.Write("Queue (now) : ");
            foreach (int item in queue)
            {
                Console.Write("{0}\t", item);
            }

            // pausing console
            Console.ReadKey();
        }
    }
}
