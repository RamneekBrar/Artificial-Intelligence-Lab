#include<iostream>
#include<queue>
using namespace std;
 
void iterativeDeepeningBS(int *G, int n, int visited[], int s, int d, int w)
{
    queue<int> q, level;
    int p;
    level.push(1);
    q.push(s);
    visited[s] = 1;
    while(!q.empty())
    {
        int t = q.front();
        cout << t << " ";
        q.pop();
 
        p = level.front() + 1;
        level.pop();
 
        int l = w;
 
        if(p<=d)
        {
            for(int i=0;i<n;i++)
            {
                if((*((G + t*n) + i))==1 && visited[i]==0 && l>0)
                {
                    q.push(i);
                    level.push(p);
                    l--;
                    visited[i] = 1;
                }
            }
        }
    }
}
 
int main()
{
    int s, n;
 
    cout << "Enter number of nodes: ";
    cin >> n;
 
    int G[n][n];
 
    cout << "Enter Edge Adjacency Matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin >> G[i][j];
    }
 
    cout << "Enter starting node: ";
    cin >> s;
 
    for(int d=1;d<=3;d++)
    {
        cout << "\n\nDepth " << d << ":";
        for(int w=1;w<=3;w++)
        {
            int visited[n] = {0};
            cout << "\nWidth = " << w << "    -------->    ";
            iterativeDeepeningBS((int *)G, n, visited, s, d, w);
        }
    }
 
    return 0;
}