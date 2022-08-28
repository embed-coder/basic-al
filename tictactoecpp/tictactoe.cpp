// Example program
#include <iostream>
#include <string>

using namespace std;

// char table[3][3] =  {{'*', '*', '*'},
//                     {'*', '*', '*'},
//                     {'*', '*', '*'}};
char table[3][3] =  {{'X', 'X', 'X'},
                    {'*', '*', '*'},
                    {'*', '*', '*'}};

int xPos[] = {0, 0};
int oPos[] = {0, 0};

void showTable(char tbl[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tbl[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int vertical_check(char tbl[][3], int x = 0, int y = 0, char chk = ' ', int count = 0) {
    cout << "Debug: x: " << x << ", y: " << y << ", chk: " << chk << ", count: " << count << endl;
    if (chk == tbl[x][y]) {
        count++;
        if (x > 0) {
            count = vertical_check(tbl, x - 1, y, chk, count);
        }
        if (x < 3) {
            count = vertical_check(tbl, x + 1, y, chk, count);
        }
    }
    return count;
}

bool horizontal_check(char tbl[][3], int x = 0, int y = 0, char chk = ' ', int count = 0) {
}

bool cross_check(char tbl[][3], int x = 0, int y = 0, char chk = ' ', int count = 0) {
}

bool checkTable(char tbl[][3], int x = 0, int y = 0, char chk = ' ', int count = 0) {
    if (chk == tbl[x][y]) {
        count++;
    }
    cout << "Debug: x: " << x << ", y: " << y << ", chk: " << chk << ", count: " << count << endl;
    if (x < 3 && y < 3) {
        if (!checkTable(tbl, x, y + 1, chk, count)) {
            if (!checkTable(tbl, x + 1, y + 1, chk, count)) {
                checkTable(tbl, x + 1, y, chk, count);
            }
        }
    }
    
    return (count == 3) ? true : false;
}

int main()
{
    int x, y;
    while (true) {
        showTable(table);

        // cout << "Player X x:";
        // cin >> x;
        // cout << "Player X y:";
        // cin >> y;
        // table[x][y] = 'X';
        showTable(table);

        if (checkTable(table, x, y, 'X')) {
            cout << "Player X won" << endl;
            return 0;
        }
        return 0;

        // cout << "Player O x:";
        // cin >> x;
        // cout << "Player O y:";
        // cin >> y;
        // table[x][y] = 'O';

        // if (checkTable(table, x, y, 'O')) {
        //     cout << "Player O won" << endl;
        //     return 0;
        // }
    }
    
    return 0;
}