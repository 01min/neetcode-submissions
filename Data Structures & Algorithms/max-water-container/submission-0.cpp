class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int maxans=0;
        for(int i=0;i<heights.size();i++){
        int right=heights.size()-1;
        while(i<right){
            int minh=min(heights[i],heights[right]);
            maxans=max(maxans,(right-i)*minh);
            right--;
        }
        }
        return maxans;
    }
};
