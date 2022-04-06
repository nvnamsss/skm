#include <bits/stdc++.h>
using namespace std;

class Solution {
    void modifyRow(vector<vector<int>>& matrix, int row) {
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[row][i] != 1) {
                matrix[row][i] = -1;
            }
        }
    }

    void modifyColumn(vector<vector<int>>& matrix, int column) {
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][column] != 1) {
                matrix[i][column] = -1;
            }
        }
    }

public:
    void modify(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1) {
                    modifyRow(matrix, i);
                    modifyColumn(matrix, j);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 1;
                }
            }
        }
                
    }
};

void print(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
        
}

int main() {
    Solution s;
    vector<vector<int>> matrix = {
        {0,1,2,3},
        {3,1,2,4},
        {1,0,2,3},
        {5,9,2,5},
    };
    s.modify(matrix);
    print(matrix);
    return 0;
}