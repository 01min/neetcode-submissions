class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        while(left<right){
            int mid=(left+right)/2;
            long long h_n=0;
            for(int &i:piles){
                h_n+=i/mid + (i%mid>0 ? 1:0);
            }
            if(h_n<=h){
                right=mid;
            }
            else if(h_n>h){left=mid+1;}
            

        }
        return left;
        
    }
};
