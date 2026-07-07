class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        
        map<int, int> countMap;
        for (int card : hand) {
            countMap[card]++;
        }
        for (auto it = countMap.begin(); it != countMap.end(); ++it) {
            int card = it->first;
            int count = it->second;
            if (count == 0) continue;
            for (int i = 0; i < groupSize; ++i) {
                int nextCard = card + i;
                
                if (countMap[nextCard] < count) {
                    return false;
                }
                countMap[nextCard] -= count;
            }
        }
        
        return true;
    }
};