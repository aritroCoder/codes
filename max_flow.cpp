#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

const int vertices = 6;

bool bfs(int rGraph[][vertices], int start, int end, int parent[])
{
    int visited[vertices];
    memset(visited, 0, sizeof(int) * vertices);
    queue<int> q;

    parent[start] = -1;
    // visited[start] = 1;
    q.push(start);
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for (int v = 0; v < vertices; v++)
        {
            if (visited[v] == false && rGraph[u][v] > 0)
            {
                if (v == end)
                {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

int ford_fulkerson(int graph[][vertices], int start, int end)
{
    int max_flow = 0;
    int rGraph[vertices][vertices];
    for(int i = 0; i<vertices; i++) {
        for(int j = 0; j<vertices; j++) {
            rGraph[i][j] = graph[i][j]; 
        }
    }

    int parent[vertices];

    // doing bfs
    while (bfs(rGraph, start, end, parent))
    {
        int min_flow = INT_MAX;
        // calculate the min flow from a path
        for(int i=end; i>0; i = parent[i]){
            min_flow = min(min_flow, rGraph[parent[i]][i]);
        }

        // update rGraph
        for(int i=end; i>0; i=parent[i]){
            rGraph[parent[i]][i] -= min_flow;
            rGraph[i][parent[i]] += min_flow;
        }

        max_flow += min_flow;
    }

    // Return the overall flow
    return max_flow;
}

int main()
{
    int graph[][6]={
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };  // residual graph
    cout<<ford_fulkerson(graph, 0, 5)<< endl;
    return 0;
}