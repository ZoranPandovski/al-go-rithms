	public int FindBinary(NAW item)
        {
            int min = 0, max = _used;

            if (item != null || _array[0] != null)
            {
                while(min < max) // Zolang er nog ruimte tussen min en max zit.
                {
                    int half = (min + max) / 2;
                    if (_array[half] == item)
                    {
                        //Stoppen want dit item is het!
                        return half;
                    }
                    int temp = _array[half].CompareTo(item);
                    switch (temp)
                    {
                        case 1:
                            //change max
                            max = half;
                            break;
                        case -1:
                            //change min
                            min = half;
                            break;
                        default:
                            break;
                    }
                }
            }
            return -1;
        }