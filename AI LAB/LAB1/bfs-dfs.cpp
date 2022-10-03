#include<iostream>
#include<queue>
using namespace std;
 
void BFS(int *G,int visited[],int c, int n)
{
    queue<int> q;
    q.push(c);
    visited[c] = 1;
 
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        cout << t << " ";
        for(int i=0;i<n;i++)
        {
            if((*((G + t*n) + i))==1 && visited[i]==0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
   
}
 
void DFS(int *G,int visited[],int c, int n)
{
    cout << c << endl;
    visited[c] = 1;
    for(int i=0;i<n;i++)
    {
        if((*((G + c*n) + i))==1 && visited[i]==0)
            DFS(G,visited,i,n);
    }
}
 
int main()
{
    int n;
    cout << "Enter number of nodes ";
    cin >> n;
   
    int G[n][n];
    cout << "Enter the Edge Adjacency matrix of graph : \n";
 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin >> G[i][j];
    }
 
    int visited[n];
    for(int i=0;i<n;i++)
    visited[i] = 0;
 
    int start;
    cout << "Enter the starting node: ";
    cin >> start;
 
    int algo;
    cout << "Enter 0 for DFS and 1 BFS: ";
    cin >> algo;
 
   
    if(algo)
        BFS((int *)G,visited,start,n);
    else
        DFS((int *)G,visited,start,n);
 
    return 0;
}