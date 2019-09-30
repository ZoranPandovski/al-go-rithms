class clsBubbleSort
    {
        private int[] a;

        public clsBubbleSort()
        {
            a = new int[20];
            Random randNum = new Random();

            for (int i = 0; i < a.Length; i++)
            {
                a[i] = (int)(randNum.Next(0, 100));
            }
        }

        public void fnBubbleSort()
        {
            int t;
            Console.WriteLine("The Array is : ");

            for (int i = 0; i < a.Length; i++)
            {
                Console.WriteLine(a[i]);
            }

            for (int j = 0; j <= a.Length - 2; j++)
            {
                for (int i = 0; i <= a.Length - 2; i++)
                {
                    if (a[i] > a[i + 1])
                    {
                        t = a[i + 1];
                        a[i + 1] = a[i];
                        a[i] = t;
                    }
                }
            }

            Console.WriteLine("\nThe Sorted Array :");

            foreach (int aray in a)
                Console.Write(aray + " ");

            Console.ReadLine();
        }
    }
