#include<iostream>
using namespace std;
 
void DFS(int *G, int visited[], int s, int d)
{
    if(d==0)
    return;
 
    cout << s << " ";
    visited[s] = 1;
 
    for(int i=0;i<13;i++)
    {
        if((*((G + s*13) + i))==1 && visited[i]==0)
            DFS(G, visited, i, d-1);
    }
}
 
int main()
{
    int G[13][13], s;
 
    for(int i=0;i<13;i++)
    {
        for(int j=0;j<13;j++)
        {
            cin >> G[i][j];
        }
    }
 
 
    cout << "Enter starting node: ";
    cin >> s;
   
    for(int d=1;d<=3;d++)
    {
        int visited[13] = {0};
        cout << "For depth = " << d << endl;
        DFS((int *)G, visited, s, d);
        cout << "\n\n";
    }
 
    return 0;
}