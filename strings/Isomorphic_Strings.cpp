#include<bits/stdc++.h>
using namespace std;
    
    bool isIsomorphic(string s, string t) {
         map<char,char> umap;
         set<char> s1;
         int n=s.size();
         for(int i=0;i<n;i++)
         {
             if(umap.count(s[i])==0 && s1.count(t[i])==0)
             {   
                 umap[s[i]]=t[i];
                 s1.insert(t[i]);
             }
              else if(umap.count(s[i])==0 && s1.count(t[i]))
                  return false;
             else if(umap[s[i]]!=t[i])
                 return false;
             
             
         }
        return true;
    }
    int main()
    {
        string s,t;
        cout<<"Enter String 1=";
        cin>>s;
        cout<<"Enter String 2=";
        cin>>t;
        bool ans=isIsomorphic(s,t);
        if(ans==1)
          cout<<"Strings are Isomorphic";
        else
          cout<<"Stirngs are Not Isomorphic";
    }
