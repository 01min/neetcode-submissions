class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0); // DP 表，同時也是我們要回傳的答案，預設為 0
        
        // 倒著算回來！最後一天的答案一定是 0，所以從倒數第二天 (n-2) 開始
        for (int i = n - 2; i >= 0; i--) {
            int j = i + 1; // 先看隔壁天
            
            // 如果隔壁天比我冷，而且隔壁天後面還有可能變熱的日子，我們就發動「傳送」
            while (temperatures[j] <= temperatures[i] && ans[j] != 0) {
                j += ans[j]; // 核心：利用已知的 ans[j] 直接大步跳躍！
            }
            
            // 跳完之後，檢查最後落腳的那一天有沒有比我熱
            if (temperatures[j] > temperatures[i]) {
                ans[i] = j - i; // 算出了天數差
            }
            // 如果 temperatures[j] <= temperatures[i] 且 ans[j] == 0 
            // 代表後面不可能有比第 i 天更熱的日子了，ans[i] 保持預設的 0
        }
        
        return ans;
    }
};