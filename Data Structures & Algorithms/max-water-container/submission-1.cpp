class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int maxans=0;
        int i=0;
        int right=heights.size()-1;
        while(i<right){
            int minh=min(heights[i],heights[right]);
            maxans=max(maxans,(right-i)*minh);
            if(heights[i]<heights[right])i++;
            else right--;
        }

        return maxans;
    }
};
