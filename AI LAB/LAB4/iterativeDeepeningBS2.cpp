#include<iostream>
#include<queue>
using namespace std;
 
void iterativeDeepeningBS(int *G, int visited[], int s, int d)
{
    queue<int> q, level, width;
    int tLevel, tWidth;
 
    level.push(1);
    width.push(1);
 
    q.push(s);
    visited[s] = 1;
 
    while(!q.empty())
    {
        int t = q.front();
        cout << t << " ";
        q.pop();
 
        tLevel = level.front() + 1;
        level.pop();
 
        tWidth = width.front() + 1;
        width.pop();
 
        int l = tWidth;
 
        if(tLevel<=d)
        {
            for(int i=0;i<13;i++)
            {
                if((*((G + t*13) + i))==1 && visited[i]==0 && l>0)
                {
                    q.push(i);
                    level.push(tLevel);
                    width.push(tWidth);
                    l--;
                    visited[i] = 1;
                }
            }
        }
    }
}
 
int main()
{
    int G[13][13], s;
 
    cout << "Enter Edge Adjacency Matrix:\n";
    for(int i=0;i<13;i++)
    {
        for(int j=0;j<13;j++)
        cin >> G[i][j];
    }
 
    cout << "Enter starting node: ";
    cin >> s;
 
    for(int d=1;d<=3;d++)
    {
        int visited[13] = {0};
        cout << "\n\nDepth " << d << ":\n";
        iterativeDeepeningBS((int *)G, visited, s, d);
    }
 
    return 0;
}