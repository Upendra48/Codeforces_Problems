/*

Cactus lady loves her cactuses very much. Especially she likes a small cactus named Cing. 
Cing can be seen as a connected undirected graph in which every vertex lies on at most one simple cycle. 
Intuitively, a cactus is a generalization of a tree where some cycles are allowed. 
Multiedges (multiple edges between a pair of vertices) and loops (edges that connect a vertex to itself) are not allowed.

She bought a special grid for her special little cactus Cing. This grid can be represented as a graph consisting of two paths of length 400000
, u(0,−200000)−u(0,−199999)−…−u(0,200000)
 and u(1,−200000)−u(1,−199999)−…−u(1,200000)
, connected together by 400001
 edges (u(0,i),u(1,i))
 for each i
. In other words, a grid can be seen as a ladder.


Cactus lady wants to know whether she can embed Cing into this grid, i.e., map each vertex of the cactus onto a separate vertex of the grid while each edge of the cactus will be mapped onto some edge of the grid.

Input
The first line contains an integer t
 — the number of test cases.

Each test case begins with a line containing two integers n
 and m
 — the number of vertices and the number of edges in a given cactus, respectively (1≤n≤200000
; 0≤m≤250000
).

Each of the following m
 lines contains two integers v
 and u
, describing the edges of the cactus (1≤v,u≤n,u≠v
).

The total sum of all n
 in the input doesn't exceed 200000
.

Output
Print an answer for each test case in the same order the cases appear in the input.

For each test case print "No" in the first line, if no layout exists.

Otherwise print "Yes" in the first line, and the following n
 lines describing the layout. The i
-th of these n
 lines should contain two integers xi
 and yi
, the location of the i
-th vertex (0≤xi≤1
; −200000≤yi≤200000
).

*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int> adj[n+1];
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if(m!=n-1)
        {
            cout<<"No"<<endl;
            continue;
        }

        int vis[n+1];
        memset(vis,0,sizeof(vis));
        queue<int> q;
        q.push(1);
        vis[1]=1;
        int flag=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(vis[it]==0)
                {
                    vis[it]=vis[node]+1;
                    q.push(it);
                }
                else if(vis[it]==vis[node])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                break;
            }
        }

        if(flag==1)
        {
            cout<<"No"<<endl;
            continue;
        }

        cout<<"Yes"<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<vis[i]%2<<" "<<vis[i]<<endl;
        }
    }
    
    return 0;
}