#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 0; i <= m; ++i) dp[i][0] = i; 
        for (int j = 0; j <= n; ++j) dp[0][j] = j; 
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int replace_op = dp[i - 1][j - 1];
                    int delete_op  = dp[i - 1][j];
                    int insert_op  = dp[i][j - 1];
                    
                    dp[i][j] = min({replace_op, delete_op, insert_op}) + 1;
                }
            }
        }
        
        return dp[m][n];
    }
};