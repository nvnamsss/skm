#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> rs = vector<vector<int>>(n, vector<int>(n, 0));
        int layers = (n + 1) / 2;
        int count = 1;
        for (int i = 0; i < layers; i++)
        {
            // left -> right
            for (int j = i; j < n - i; j++)
            {
                int val = i * n + j + 1;
                cout << val << " ";
                rs[i][j] = count;
                count++;
            }

            // top -> bottom
            for (int j = i + 1; j < n - i; j++)
            {
                int val = j * n + (n - i - 1) + 1;
                cout << val << " ";
                rs[j][n - i - 1] = count;
                count++;
            }

            // right -> left
            for (int j = n - i - 2; j >= i; j--)
            {
                int val = (n - i - 1) * n +  j + 1;
                cout << val << " ";
                rs[n - i - 1][j] = count;
                count++;
            }

            // bottom -> top
            for (int j = n - i - 2; j >= i + 1; j--)
            {
                int val = j * n + i + 1;
                cout << val << " ";
                rs[j][i] = count;
                count++;
            }
        }

        return rs;
    }
public:
    void spiralMatrix(int n)
    {
        
        int layers = (n + 1) / 2;
        for (int i = 0; i < layers; i++)
        {
            // left -> right
            for (int j = i; j < n - i; j++)
            {
                int val = i * n + j + 1;    
                cout << val << " ";
            }

            // top -> bottom
            for (int j = i + 1; j < n - i; j++)
            {
                int val = j * n + (n - i - 1) + 1;
                cout << val << " ";
            }

            // right -> left
            for (int j = n - i - 2; j >= i; j--)
            {
                int val = (n - i - 1) * n +  j + 1;
                cout << val << " ";
            }

            // bottom -> top
            for (int j = n - i - 2; j >= i + 1; j--)
            {
                int val = j * n + i + 1;
                cout << val << " ";
            }
        }

        cout << endl;
    }
};

int main()
{
    Solution s;
    s.spiralMatrix(3);
    s.spiralMatrix(4);
    s.spiralMatrix(5);
    s.spiralMatrix(6);
    return 0;
}