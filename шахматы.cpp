#include <iostream>
#include <vector>
using namespace std;
void Rook(vector<vector<int>>& moves, int x, int y) {
      moves[x][y]=2;
    for (int i = 1; i < 8; i++) {
        
        if (x + i < 8) moves[x + i][y] = 1;
        if (x - i >= 0) moves[x - i][y] = 1;
        if (y + i < 8) moves[x][y + i] = 1;
        if (y - i >= 0) moves[x][y - i] = 1;
    }
}
void Pawn(vector<vector<int>>& moves, int x, int y) {
    if(x > 0) moves[x-1][y] = 1;
    if(x < 7) moves[x+1][y] = 1;

}
void addMove(vector<vector<int>>& moves, int x, int y) {
    if (x >= 0 && x < 8 && y >= 0 && y < 8) {
        moves[x][y] = 1;
    }
}
void Bishop(vector<vector<int>>& moves, int x, int y) {
    moves[x][y]=2;
    for (int i = 1; i < 8; i++) {
        addMove(moves, x + i, y + i);
        addMove(moves, x + i, y - i);
        addMove(moves, x - i, y + i);
        addMove(moves, x - i, y - i);
    }
}


void Queen(vector<vector<int>>& moves, int x, int y) {
    for (int i = 0; i < 8; i++) {
        if (i != y) {
            moves[x][i] = 1;
        }
    }
    
    for (int i = 0; i < 8; i++) {
        if (i != x) {
            moves[i][y] = 1;
        }
    }
    
    
    int r = x;
    int c = y;
    while (r >= 0 && c >= 0) {
        moves[r][c] = 1;
        r--;
        c--;
    }
    
    r = x;
    c = y;
    while (r < 8 && c < 8) {
        moves[r][c] = 1;
        r++;
        c++;
    }
    
    r = x;
    c = y;
    while (r >= 0 && c < 8) {
        moves[r][c] = 1;
        r--;
        c++;
    }
    
    r = x;
    c = y;
    while (r < 8 && c >= 0) {
        moves[r][c] = 1;
        r++;
        c--;
    }
}
void king(vector<vector<int>>& moves, int x, int y) {

    if(x > 0 && y > 0) moves[x-1][y-1] = 1;
    if(x > 0) moves[x-1][y] = 1;
    if(x > 0 && y < 7) moves[x-1][y+1] = 1;
    if(y > 0) moves[x][y-1] = 1;
    if(y < 7) moves[x][y+1] = 1;
    if(x < 7 && y > 0) moves[x+1][y-1] = 1;
    if(x < 7) moves[x+1][y] = 1;
    if(x < 7 && y < 7) moves[x+1][y+1] = 1;

 
}
void knight(vector<vector<int>>& moves, int x, int y) {
    if (x - 2 >= 0 && y - 1 >= 0) {
        moves[x - 2][y - 1] = 1;
    }
    if (x - 2 >= 0 && y + 1 < 8) {
        moves[x - 2][y + 1] = 1;
    }
    if (x + 2 < 8 && y - 1 >= 0) {
        moves[x + 2][y - 1] = 1;
    }
    if (x + 2 < 8 && y + 1 < 8) {
        moves[x + 2][y + 1] = 1;
    }
    if (x - 1 >= 0 && y - 2 >= 0) {
        moves[x - 1][y - 2] = 1;
    }
    if (x - 1 >= 0 && y + 2 < 8) {
        moves[x - 1][y + 2] = 1;
    }
    if (x + 1 < 8 && y - 2 >= 0) {
        moves[x + 1][y - 2] = 1;
    }
    if (x + 1 < 8 && y + 2 < 8) {
        moves[x + 1][y + 2] = 1;
    }
}


void print(vector<vector<int>>& moves, int x, int y, std::string piece) {
    if (piece == "Rook") {
        Rook(moves, x, y);
    }else if(piece=="pawn"){
        Pawn(moves, x, y);
    }else if(piece=="bishop"){
                Bishop(moves, x, y);

    }else if(piece=="king"){
        king(moves, x, y);
    }else if(piece=="knight"){
        knight(moves, x, y);
    }else if(piece=="queen"){
        Queen(moves, x, y);
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << moves[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> moves(8, vector<int>(8, 0));
    
moves[5][4]=2;
    print(moves, 5, 4, "king");

    return 0;
}
