/*
Satisfiability of Equality Equations

You are given an array of strings equations that represent relationships between 
variables where each string equations[i] is of length 4 and takes one of 
two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters 
(not necessarily different) that represent one-letter variable names.

Return true if it is possible to assign integers to variable names so as 
to satisfy all the given equations, or false otherwise.

Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.

Input: equations = ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.

Input: equations = ["a==b","b==c","a==c"]
Output: true

Input: equations = ["a==b","b!=c","c==a"]
Output: false

Input: equations = ["c==c","b==d","x!=z"]
Output: true

Constraints:
    1 <= equations.length <= 500
    equations[i].length == 4
    equations[i][0] is a lowercase letter.
    equations[i][1] is either '=' or '!'.
    equations[i][2] is '='.
    equations[i][3] is a lowercase letter.

*/

/*
Idea: 
Since only atmost 2 variables are involved in an equation and the equation can only
be == or !=, the only possible scenerio where unsatisfiability takes place is when
two variables which were declared directly or indirectly equal is declared unequal.

So we will first process all the equalities first. for every equality we will indicate it
by an edge and any two variables directly/indirectly connected by edge means they are equal
this can by captured using union operation because if 2 nodes have indirect/direct connection
they will yield the same parent/component when doing find.

Now we will process the inequalities. Here we will just check if find is same then return false
because same component variables are equal but now contradiction is happening and hence unsatisfiable.

If no contradiction after processing everything, then return true

Time Complexity: O(N) where N is equations.length
Space Complexity: O(26) = O(1)
*/


class Solution {
public:
    vector<int> p,sz;
    int find(int a){
        if(p[a]!=a)p[a]=find(p[a]);
        return p[a];
    }
    void unite(int a ,int b){
        a=find(a);
        b=find(b);
        p[a]=p[b];

    }
    bool equationsPossible(vector<string>& equations) {
        p.resize(26),sz.resize(26,1);
        for(int i=0;i<26;i++)p[i]=i;
        for(auto &s: equations){
            if(s[1]=='=')unite(s[0]-'a',s[3]-'a');
        }
        for(auto &s: equations){
            if(s[1]!='='){
                if(find(s[0]-'a')==find(s[3]-'a'))return false; 
            }
        }
        return true;
    }
};