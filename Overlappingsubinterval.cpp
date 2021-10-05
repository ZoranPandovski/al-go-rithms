vector<vector<int>> merge(vector<vector<int>> &intervals)
{
  vector<vecor<int>> Merge_i;
  if(intervals.size == 0)
  {
    return Merge_i;
  }
  sort(intervals.begin(),intervals.end());
  vecor<int> tempint = intervals[0];
  for(auto it:intervals)
  {
    if(it[0] <=tempint[1])
    {
      tempint[1] = max(it[1],tempint[1]);
    }
    else
    {
      Merge_i.push_back(tempint);
      tempint = it;
    }
  }
  Merge_i.push_back(tempint);
  return Merge_i;
}

      
