#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int randomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generateMaze(int N, int M) {
    vector<vector<char>> maze(N, vector<char>(M, '.')); 

    int startX = randomInt(0, N - 1);
    int startY = randomInt(0, M - 1);
    int endX = randomInt(0, N - 1);
    int endY = randomInt(0, M - 1);

    maze[startX][startY] = 'S';
    maze[endX][endY] = 'E';

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (maze[i][j] != 'S' && maze[i][j] != 'E') {
                if (randomInt(0, 4) == 0) { 
                    maze[i][j] = '#';
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }
}

void generateMagicalValues(int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << randomInt(1, 30) << " "; 
        }
        cout << endl;
    }
}

int main() {
    srand(time(0)); 

    int N = randomInt(1, 50);
    int M = randomInt(1, 50);

    cout << N << " " << M << endl;

    generateMaze(N, M);
    generateMagicalValues(N, M);

    return 0;
}
