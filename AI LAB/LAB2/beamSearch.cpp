#include<iostream>
#include<queue>
using namespace std;
 
void QueueBeamSearch(int *G,int visited[],int s,int w,int n)
{
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        cout << t << " ";
        for(int i=0;i<n;i++)
        {
            if((*((G + t*n) + i))==1 && visited[i]==0 && q.size()<w)
            {
                q.push(i);
                visited[i] = 1;
            }
            if(q.size()==w)
            break;
        }
    }
}
 
void OperatorBeamSearch(int *G,int visited[],int s,int w,int n)
{
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        int l = w;
        cout << t << " ";
        for(int i=0;i<n;i++)
        {
            if((*((G + t*n) + i))==1 && visited[i]==0 && l>0)
            {
                q.push(i);
                visited[i] = 1;
                l--;
            }
            if(l==0)
            break;
        }
    }
}
 
int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
 
    int G[n][n];
    cout << "Enter Edge Adjacency Matrix of graph: \n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin >> G[i][j];
    }
 
    int s;
    cout << "Enter the starting node: ";
    cin >> s;
 
    int w;
    cout << "Enter value of w: ";
    cin >> w;
 
    int visited[n];
    for(int i=0;i<n;i++)
    visited[i] = 0;
 
    cout << "Queue length method:\n";
    QueueBeamSearch((int *)G,visited,s,w,n);
 
    for(int i=0;i<n;i++)
    visited[i] = 0;
 
    cout << "\nOperator method:\n";
    OperatorBeamSearch((int *)G,visited,s,w,n);
 
    return 0;
}