#include<iostream>
using namespace std;


int rating(int board[], int v, int b)
{
    if (b==1)
    {
        if((board[2]==v && board[3]==v) || (board[4]==v && board[7]==v) || (board[5]==v && board[9]==v))
        return 10;
        else if(board[2]==v || board[3]==v || board[4]==v || board[7]==v || board[5]==v || board[9]==v)
        return 5;
        else
        return 2;
    }
    else if(b==2)
    {
        if((board[1]==v && board[3]==v) || (board[5]==v && board[8]==v))
        return 10;
        else if(board[1]==v || board[3]==v || board[5]==v || board[8]==v)
        return 5;
        else
        return 2;
    }
    else if (b==3)
    {
        if((board[2]==v && board[1]==v) || (board[5]==v && board[7]==v) || (board[6]==v && board[9]==v))
        return 10;
        else if(board[2]==v || board[1]==v || board[5]==v || board[7]==v || board[6]==v || board[9]==v)
        return 5;
        else
        return 2;
    }
    else if(b==4)
    {
        if((board[1]==v && board[7]==v) || (board[5]==v && board[6]==v))
        return 10;
        else if(board[1]==v || board[7]==v || board[5]==v || board[6]==v)
        return 5;
        else
        return 2;
    }
    else if(b==5)
    {
        if((board[1]==v && board[9]==v) || (board[2]==v && board[8]==v) || (board[3]==v && board[7]==v) || (board[4]==v && board[6]==v))
        return 10;
        else if(board[1]==v || board[9]==v || board[2]==v || board[8]==v || board[3]==v || board[7]==v || board[4]==v || board[6]==v)
        return 5;
        else
        return 2;
    }
    else if(b==6)
    {
        if((board[4]==v && board[5]==v) || (board[3]==v && board[9]==v))
        return 10;
        else if(board[4]==v || board[5]==v || board[3]==v || board[9]==v)
        return 5;
        else
        return 2;
    }
    else if (b==7)
    {
        if((board[1]==v && board[4]==v) || (board[5]==v && board[3]==v) || (board[8]==v && board[9]==v))
        return 10;
        else if(board[1]==v || board[4]==v || board[5]==v || board[3]==v || board[8]==v || board[9]==v)
        return 5;
        else
        return 2;
    }
    else if(b==8)
    {
        if((board[2]==v && board[5]==v) || (board[7]==v && board[9]==v))
        return 10;
        else if(board[2]==v || board[5]==v || board[7]==v || board[9]==v)
        return 5;
        else
        return 2;
    }
    else
    {
        if((board[5]==v && board[1]==v) || (board[8]==v && board[7]==v) || (board[6]==v && board[3]==v))
        return 10;
        else if(board[5]==v || board[1]==v || board[8]==v || board[7]==v || board[6]==v || board[3]==v)
        return 5;
        else
        return 2;
    }
}


void user_move(int board[], int v)
{
    int s;
    while(1)
    {
        cout << "Enter square: ";
        cin >> s;

        if(board[s]==2)
        {
            board[s] = v;
            break;;
        }
        else
        cout << "Square already filled.\n";
    }
}


int Go(int board[], int n, int turn)
{
    if(turn%2 == 1)
    board[n] = 3;
    else
    board[n] = 5;

    return turn+1;
}


int blank(int board[])
{
    int i=1;
    for(;i<=9;i++)
    {
        if(board[i]==2)
        break;
    }

    return i;
}


bool Checkwin(int board[], int v)
{
    for(int i=1;i<9;i=i+3)
    {
        if(board[i]==3 && board[i+1]==3 && board[i+2]==3 && v==3)
        return true;
        else if(board[i]==5 && board[i+1]==5 && board[i+2]==5 && v==5)
        return true;
    }

    for(int i=1;i<4;i++)
    {
        if(board[i]==3 && board[i+3]==3 && board[i+6]==3 && v==3)
        return true;
        else if(board[i]==5 && board[i+3]==5 && board[i+6]==5 && v==5)
        return true;
    }

    if(board[1]==3 && board[5]==3 && board[9]==3 && v==3)
    return true;
    else if(board[1]==5 && board[5]==5 && board[9]==5 && v==5)
    return true;
    
    if(board[3]==3 && board[5]==3 && board[7]==3 && v==3)
    return true;
    else if(board[3]==5 && board[5]==5 && board[7]==5 && v==5)
    return true;


    return false;

}


void display(int board[])
{
    for(int i=1;i<=9;i++)
    {
        if(i==3 || i==6)
        {
            if(board[i]==2)
            cout << " \n";
            else if(board[i]==3)
            cout << "x\n";
            else
            cout << "o\n";

            cout << "---------\n";
        }
        else if(i==9)
        {
            if(board[i]==2)
            cout << " \n";
            else if(board[i]==3)
            cout << "x\n";
            else
            cout << "o\n";
        }
        else
        {
            if(board[i]==2)
            cout << "  | ";
            else if(board[i]==3)
            cout << "x | ";
            else
            cout << "o | ";
        }
    }
}

int minmax(int virtualBoard[], int depth, int v, int *move)
{
    int bestMove = -10;
    if(depth==1)
    {
        for(int i=1;i<=9;i++)
        {
            if(virtualBoard[i]==2)
            {
                int currentRating = rating(virtualBoard, v, i);
                if(currentRating > bestMove)
                {
                    bestMove = currentRating;
                    *move = i;
                }
            }
        }
        return bestMove;
    }
    else
    {
        for(int i=1;i<=9;i++)
        {
            if(virtualBoard[i]==2)
            {
                if(v==3)
                {
                    virtualBoard[i] = 3;
                    int currentRating = minmax(virtualBoard, depth-1, 5, move);
                    if(currentRating > bestMove)
                    {
                        bestMove = currentRating;
                        *move = i;
                    }
                }
                else
                {
                    virtualBoard[i] = 5;
                    int currentRating = minmax(virtualBoard, depth-1, 3, move);
                    if(currentRating > bestMove)
                    {
                        bestMove = currentRating;
                        *move = i;
                    }
                }
            }
        }
        return bestMove;
    }
}

void comp_move(int board[], int virtualBoard[], int depth, int turn, int v)
{
    if(turn == 1)
    turn = Go(board, 1, turn);

    else if(turn == 2)
    {
        if(board[5]==2)
        turn = Go(board, 5, turn);
        else
        turn = Go(board, 1, turn);
    }

    else if(turn == 3)
    {
        if(board[9]==2)
        turn = Go(board, 9, turn);
        else
        turn = Go(board, 3, turn);
    }
    else 
    {
        int move = 0;
        minmax(virtualBoard, depth, v, &move);
        turn = Go(board, move, turn);
        virtualBoard = board;
    }
}


int main()
{
    int board[10] = {2,2,2,2,2,2,2,2,2,2}, virtualBoard[10] = {2,2,2,2,2,2,2,2,2,2}, turn = 1, depth = 1, flag=0;
    char firstMove;

    cout << "Do you want to play first(y/n): ";
    cin >> firstMove;

    if(firstMove == 'y')
    {
        while(turn<=9)
        {
            user_move(board, 3);
            turn++;
            for(int i=1;i<10;i++)
            virtualBoard[i] = board[i];
            display(board);
            if(Checkwin(board, 3))
            {
                cout << "User wins!!!\n";
                flag = 1;
                break;
            }

            comp_move(board, virtualBoard, depth, turn, 5);
            for(int i=1;i<10;i++)
            virtualBoard[i] = board[i];
            turn++;
            display(board);
            if(Checkwin(board, 5))
            {
                cout << "Computer wins!!!\n";
                flag = 1;
                break;
            }
        }

        if(!flag)
        cout << "Draw!!!\n";
    }
    else
    {
        while(turn<9)
        {
            comp_move(board, virtualBoard, depth, turn, 3);
            turn++;
            display(board);
            if(Checkwin(board, 3))
            {
                cout << "Computer wins!!!\n";
                flag = 1;
                break;
            }

            user_move(board, 5);
            turn++;
            display(board);
            if(Checkwin(board, 5))
            {
                cout << "User wins!!!\n";
                flag = 1;
                break;
            }
        }

        if(!flag)
        {
            Go(board, blank(board), 9);
            display(board);
            cout << "Draw!!!\n";
        }
    }

    return 0;
}