class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        
        int maxi = 0;
        for(int i=size-1; i>0; i--){
            prices[i] = prices[i]-prices[i-1];
            if(prices[i]>0)
                maxi += prices[i];
        }
        return maxi;
    }
};