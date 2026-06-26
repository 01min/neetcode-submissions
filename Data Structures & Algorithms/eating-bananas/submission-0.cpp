class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int maxnum=0;
        for(int &p:piles){
            maxnum=max(maxnum,p);
        }
        int left=1,right=maxnum;
        int ans=right;
        while(left<=right){
            int mid=left+(right-left)/2;
            int hourneed=0;
            for(int &p:piles){
                hourneed+=p/mid;
                if(p%mid!=0)hourneed+=1;
            }
            if(hourneed<=h){right=mid-1;ans=mid;}
            else {left=mid+1;}
        }
        return ans;
        
    }
};
