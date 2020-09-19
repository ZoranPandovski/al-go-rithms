void GraphDFS(int start, int end)
{

	stack int s;	 Create a stack of ints
	bool visited = new bool[n];	 Boolean array to represent which vertices we've visited
	for (int i = 0; i  n; ++i)	 Initialize all elements of visited to false
	{
		visited[i] = false;
		lengths[i] = 0;
	}
	s.push(start);	 Push the vertex onto the stack
	visited[start] = true;	 Mark this node as visited
	if (start == end)	 End the function if we're at our destination
	{
		return;
	}

	cout  Depth-first search starting from point   start  endl;

	while (!s.empty())	 While the stack is not empty
	{
		int k = s.top();	 Save the top element before popping it off
		s.pop();

		if (k == end)	 Break out of the loop if we've reached our destination
		{
			break;
		}
		cout  k   ;
		for (int i = 0; i  n; i++)	 For all adjacent vertices
		{
			if (isConnected(k, i) && !visited[i])	 If they're connected and we haven't visited it yet
			{
				s.push(i);	 Add it to our stack, and mark that we've visited it
				visited[i] = true;

			}
		}
	}
	cout  end  endl;
	cout  lengths[end]  endl;
	delete[] visited;	 De-allocate the visited array								
}
