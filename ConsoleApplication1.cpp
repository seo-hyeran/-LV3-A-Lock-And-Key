#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotation(vector<vector<int>>a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> result(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[j][n - i - 1] = a[i][j];
        }
    }

    return result;
}
bool check(vector<vector<int>> newlock) {
    int ls = newlock.size() / 3;

    for (int i = ls; i < ls * 2; i++) {
        for (int j = ls; j < ls * 2; j++) {
            if (newlock[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int n = lock.size();
    int m = key.size();

    vector<vector<int>> newlock(n * 3, vector<int>(n * 3));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            newlock[n + i][n + j] = lock[i][j];
        }
    }

    for (int rs = 0; rs < 4; rs++) {
        key = rotation(key);

        for (int i = 0; i < n * 2; i++) {
            for (int j = 0; j < n * 2; j++) {

                for (int x = 0; x < m; x++) {
                    for (int y = 0; y < m; y++) {
                        newlock[i + x][j + y] += key[x][y];
                    }
                }
                if (check(newlock))return true;

                for (int x = 0; x < m; x++) {
                    for (int y = 0; y < m; y++) {
                        newlock[i + x][j + y] -= key[x][y];
                    }
                }
            }
        }
    }

    return false;
}