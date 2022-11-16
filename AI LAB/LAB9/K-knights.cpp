#include <iostream>
#include <vector>
using namespace std;

int m = 0,n = 0;

void attack(vector<vector <int>>& board, int i, int j)
{
    if(i-1>=0 && j-2>=0)
    board[i-1][j-2] = -1;

    if(i-2>=0 && j-1>=0)
    board[i-2][j-1] = -1;

    if(i+1<m && j-2>=0)
    board[i+1][j-2] = -1;

    if(i+2<m && j-1>=0)
    board[i+2][j-1] = -1;

    if(i-2>=0 && j+1<n)
    board[i-2][j+1] = -1;

    if(i-1>=0 && j+2<n)
    board[i-1][j+2] = -1;

    if(i+1<m && j+2<n)
    board[i+1][j+2] = -1;

    if(i+2<m && j+1<n)
    board[i+2][j+1] = -1;
}

vector<vector<int>> place(vector<vector <int>>& board, int i, int j)
{
    vector<vector <int>> newBoard;

    for(int k=0;k<m;k++)
    {
        vector<int> v;
        for (int l=0;l<n;l++)
        v.push_back(board[k][l]);

        newBoard.push_back(v);
    }

    newBoard[i][j] = 1;

    attack(newBoard, i, j);

    return newBoard;
}

int canPlace(vector<vector <int>>& board, int i, int j)
{
    if(board[i][j]==0)
    return 1;
    else 
    return 0;
}

void display(vector<vector <int>>& board)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]==1)
            cout << "K";
            else 
            cout << " ";
            if(j!=n-1)
            cout << " | ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}


void k_Knights(vector<vector <int>>& board, int k, int st_i, int st_j)
{
    //if(k > ((m-st_i)*(n-st_j))/2)
    //return;
    if(k==0)
    display(board);
    else
    {
        for(int i=st_i;i<m;i++)
        {
            for(int j=st_j;j<n;j++)
            {
                if(canPlace(board, i, j))
                {
                    vector<vector<int>> newBoard;
                    newBoard = place(board, i, j);
                    k_Knights(newBoard, k-1, i, j);
                }
            }
            st_j = 0;
        }
    }
}



int main()
{
    int k;
    cout << "Enter size of the board: ";
    cin >> m >> n;

    cout << "Enter number of knights: ";
    cin >> k;

    vector<vector <int>> board;

    for(int i=0;i<m;i++)
    {
        vector<int> v;
        for(int j=0;j<n;j++)
        v.push_back(0);
        
        board.push_back(v);
    }

    k_Knights(board, k, 0, 0);

    return 0;
}