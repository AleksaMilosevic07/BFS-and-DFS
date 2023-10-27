#include <bits/stdc++.h>
using namespace std;

char matrix[1005][1005]; //The matrix we will play in
int N, M; //Size of the matrix (N*M)
int x, y;
char DrB; //Stands for "DFS or BFS", we will use this to check which of the two algorithms user wants to use

//Simple function that will cout-out the matrix at it's current state, we will call this function so you can see the matrix update in real time
void write()
{
    for(int i = 1; i<=N; i++)
    {
        for(int j = 1; j<=M; j++)
        {
            cout<<matrix[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    system("pause"); //This will wait for user input before updating the matrix
}

//This is our DFS function
void DFS(int i, int j)
{
    matrix[i][j] = '#'; //We mark the current square as visited
    if (matrix[i][j + 1] == '.')
    {
        write();
        DFS(i, j + 1);
    }
    if (matrix[i + 1][j] == '.')
    {
        write();
        DFS(i + 1, j);
    }
    if (matrix[i][j - 1] == '.')
    {
        write();
        DFS(i, j - 1);
    }
    if (matrix[i - 1][j] == '.')
    {
        write();
        DFS(i - 1, j);
    }
}
//This is our BFS function
void BFS(int R, int C)
{
    queue <int> QR, QC; //We are creating two Queues, one for storing X coordinates and other for storing Y cordinates
    QR.push(R); //We are putting initial values into the Queue for X
    QC.push(C); //We are putting initial values into the Queue for Y
    matrix[R][C] = '#'; //We are marking the square as "visited"

    while(QR.size())
    {
        R = QR.front(); //We are setting R to be the value of the first item in the QR queue
        C = QC.front(); //We are setting C to be the value of the first item in the QC queue
        if (matrix[R][C + 1] == '.')
        {
            QR.push(R); //We are pushing the values of R into QR queue and values of C into QC queue
            QC.push(C+1);
            matrix[R][C + 1] = '#'; //We are marking the square as visited
        }
        if (matrix[R + 1][C] == '.')
        {
            QR.push(R+1);
            QC.push(C);
            matrix[R + 1][C] = '#';
        }
        if (matrix[R][C - 1] == '.')
        {
            QR.push(R);
            QC.push(C-1);
            matrix[R][C - 1];

        }
        if (matrix[R - 1][C] == '.')
        {
            QR.push(R-1);
            QC.push(C);
            matrix[R - 1][C] = '#';
        }
        write(); //We are calling the write function so we can see our progress in real time
        QR.pop();   //We are removing the first value of our queue QR
        QC.pop();   //We are removing the first value of our queue QC
    }
}


int main()
{
    memset(matrix, '#', sizeof(matrix)); //This function will set the entire matrix to '#'. This way we have some kind of "barrier" outside of our workspace. We will only display the matrix from 1,1 to N*M

    scanf("%d %d", &N, &M); //Input of sides of the matrix (N*M)
    for(int i = 1; i<= N; i++)
    {
        for(int j = 1; j<=M; j++)
        {
            matrix[i][j] = '.'; //We are setting all squares to dots inside N*M part of matrix
        }
    }
    cout<<"From which square you want to start?"<<endl;
    scanf("%d %d", &x, &y); //Coordinates of the starting square
    cout<<"DFS or BFS? D - DFS, B-BFS"<<endl;
    cin>>DrB;
    if(DrB == 'D') DFS(x, y);
    else if(DrB =='B') BFS(x, y);
    return 0;
}



//Also I want to mention this is obviously not the best way to do DFS or BFS, there are much more cleaner ways out there.
//Purpose of this project is to show how both of these algorithms fill out matrix.
//If you want to learn the best way to do DFS or BFS, check out some tutorials on the Internet, sorry to dissapoint you but I do not know everything, I am only 15.
//I might come back one day and make this code more efficient, but for now I hope this helps you get the grasp of both these algorithms and how they work.
//Thank you for checking out my code, it means a lot to me. If you got any further questions or you want to contact me, you can do it over my email: 007milosevicaleksa@gmail.com
