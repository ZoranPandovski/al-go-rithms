//Is graph bipartite?
//Note-> A disconnected graph can also be bipartite as defination says-
//A Bipartite Graph is a graph whose vertices can be divided into two independent sets such that every edge connects the vertices from 
//one set to another set.

//Using dfs we can check this-
class Solution {
public:
 bool dfs(int v,int c,vector<int> &colour,vector<vector<int>> &graph)
    {
        colour[v]=c;
        for(int i=0;i<graph[v].size();i++)
        {
            if(colour[graph[v][i]]==-1)
            {
                if(!dfs(graph[v][i],c^1,colour,graph))
                    return false;
            }
            else if(colour[v]==colour[graph[v][i]])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
            cout<<n<<endl;
        vector<int>colour(n,-1);
        int c=0;
        ///To check for disconnected graphs also else
        //we can directly run bfs from src(0);
        for(int i=0;i<n;i++)
        {
            if(colour[i]==-1)
            {
                if(dfs(i,0,colour,graph)==false)
                    return false;
            }
        }
        return true;
    }
};


//Using Breadth First Search
class Solution {
public:
    bool istrue(vector<vector<int>>& graph,int src,vector<int> &colour) {
        queue<int>q;
        q.push(src);
        colour[src]=1;  //This will make colour to be 1 even in the case of isolated vertex 
        while(!q.empty())
        {
            int v=q.front();
            q.pop();
            for(int i=0;i<graph[v].size();i++)
            {
                if(colour[graph[v][i]]==-1)   //if not coloured yet
                {
                    colour[graph[v][i]]=1-colour[v];
                    q.push(graph[v][i]);
                }
                else if(colour[graph[v][i]]==colour[v]) //If coloured then it should have different colour.
                    return false;
            }
        }
        return true;
        
    }
  //This is added to if the graph is disconnected;
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n=graph.size();
        vector<int>colour(n,-1);
        for(int i=0;i<n;i++)
        {
            if(colour[i]==-1) //If vertex is not coloured yet
            {
                if(!istrue(graph,i,colour))
                    return false;
            }
        }
        return true;
        
    }
        
};
//TESTs
//Sample
/*Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
....for disconnected graph
Input:[[],[2,4,6],[1,4,8,9],[7,8],[1,2,8,9],[6,9],[1,5,7,8,9],[3,6,9],[2,3,4,6,9],[2,4,5,6,7,8]]
Output:true
