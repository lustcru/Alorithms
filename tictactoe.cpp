#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Function to know the result of the game
string whoIsTheWinner(char matrix[3][3]){
    int pointsX, pointsO;
    bool gameUnfinished = false;
    //horizontal win
    for(int y = 0; y < 3; y++){
        pointsX = 0;
        pointsO = 0;
        for(int x = 0; x < 3; x++){
            if(matrix[y][x] == 'X')
                pointsX++;
            if(matrix[y][x] == 'O')
                pointsO++;
            //pending Game
            if(matrix[y][x] == '\0')
                gameUnfinished = true;
        }
        if(pointsX == 3)
            return "A";
        if(pointsO == 3)
            return "B";
    }
    //vertical win
    for(int x = 0; x < 3; x++){
        pointsX = 0;
        pointsO = 0;
        for(int y = 0; y < 3; y++){
            if(matrix[y][x] == 'X')
                pointsX++;
            if(matrix[y][x] == 'O')
                pointsO++;
        }
        if(pointsX == 3)
            return "A";
        if(pointsO == 3)
            return "B";
    }
    //diagonal win
    pointsX = 0;
    pointsO = 0;
    for(int x = 0; x < 3; x++){
            if(matrix[x][x] == 'X')
                pointsX++;
            if(matrix[x][x] == 'O')
                pointsO++;
    }
    if(pointsX == 3)
        return "A";
    if(pointsO == 3)
        return "B";
    pointsX = 0;
    pointsO = 0;
    for(int x = 2; x >= 0; x--){
            if(matrix[2-x][x] == 'X')
                pointsX++;
            if(matrix[2-x][x] == 'O')
                pointsO++;
    }
    if(pointsX == 3)
        return "A";
    if(pointsO == 3)
        return "B";
    //no one win
    if(gameUnfinished)
        return "Pending";
    //if no one win and there is no pending moves, its a draw
    return "Draw";
}


int main(){
    char matrix[3][3] = {{'X','X','O'},{'O','O','X'},{'X','O','\0'}};
    //test cases
    /*
    {{'X','\0','\0'},{'\0','X','\0'},{'O','O','X'}}; A win
    {{'X','X','O'},{'X','O','\0'},{'O','\0','\0'}}; B win
    {{'X','X','O'},{'O','O','X'},{'X','O','X'}}; Draw
    {{'X','X','O'},{'O','O','X'},{'X','O','\0'}}; Pending
    Important: To test just replace the 3x3 array for the matrix variable.
    */

    string winner = whoIsTheWinner(matrix);
    
    cout << winner << endl;
    return 0;
}
