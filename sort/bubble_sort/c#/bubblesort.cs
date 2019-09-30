public class BubbleSort
    {	
        private int[] _array;

	public BubbleSort() 
	{
		_array = new int[20];
		Random randNum = new Random();

          	for (int i = 0; i < _array.Length; i++)
         	{
            	  _array[i] = (int)(randNum.Next(0, 100));
         	}
	}
		
		public void BubbleSort()
		{
		    for (int i = 0; i < _used; i++)
		    {
			for (int j = 0; j < _used - 1; j++)
			{
			    if (_array[j].CompareTo(_array[j + 1]) == 1)
			    {
				//Swap item left with item right
				_array.Swap(j, j+1);
			    }
			}
		    }
		}
		
		public void BubbleSortInverted()
		{
		    for (int i = _used; i >= 0 ; i--)
		    {
			for (int j = _used - 1; j >= 0 ; j--)
			{
			    if (_array[j].CompareTo(_array[j - 1]) == -1)
			    {
				//Swap item right with item left
				_array.Swap(j, j - 1);
			    }
			}
		    }
		}
	}
