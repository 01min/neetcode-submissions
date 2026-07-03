class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        int max_freq = 0;
        for (char task : tasks) {
            count[task - 'A']++;
            max_freq = max(max_freq, count[task - 'A']);
        }
        int max_freq_count = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] == max_freq) {
                max_freq_count++;
            }
        }
        int ans = (max_freq - 1) * (n + 1) + max_freq_count;
        return max(ans, (int)tasks.size());
    }
};