using System;

namespace DoublyLinkedList
{
    class Program
    {
        static void Main(string[] args)
        {
            RunLinkedList();
        }

        static void RunLinkedList()
        {
            System.Console.WriteLine("Running the DoublyLinkedList class");
            System.Console.WriteLine("----------------------------");

            var myDoublyLinkedList = new DoublyLinkedList<int>();
            
            for (int i = 0; i < 100; i++)
            {
                myDoublyLinkedList.AddHead(i);
            }

            System.Console.WriteLine("Count = " + myDoublyLinkedList.Count);
            System.Console.WriteLine("Is Empty = " + myDoublyLinkedList.IsEmpty);
            PrintList<int>(myDoublyLinkedList);
        }

        static void PrintList<T>(DoublyLinkedList<T> myList)
        {
            if (myList.Head == null || myList.Tail == null) return;

            var listText = "DoublyLinkedList[";
            for (int i = 0; i < myList.Count; i++)
            {
                listText += myList[i];
                if (i < myList.Count - 1)
                {
                    listText += "<";
                    listText += "---";
                    listText += ">";
                }
            }
            listText += "]";

            System.Console.WriteLine(listText);
            System.Console.WriteLine("Found Data = 66 -> " + myList.Find((T)(object)66));
            System.Console.WriteLine("Found Data = 3 -> " + myList.Find((T)(object)3));
        }
    }
}
