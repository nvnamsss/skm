#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void product(vector<int>& arr) {
        vector<int> ans = vector<int>(arr.size());
        int dp = 1;
        ans[0] = 1;
        for (int i = 0; i < arr.size(); i++)
        {
            ans[i] = dp;
            dp *= arr[i];
        }

        dp = 1;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            ans[i] *= dp;
            dp *= arr[i];
        }
                
        for (int i = 0; i < arr.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Solution s;
    vector<int> arr = {2, 1, 3, 4, 5};
    s.product(arr);

    return 0;
}