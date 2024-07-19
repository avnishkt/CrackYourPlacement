class Solution {
public:
    bool canJump(vector<int>& nums) {
        int move=0;
        for(int i=0;i<nums.size();i++){
            move--;
            if((nums[i]>move))move=nums[i];
            if((move==0)&&(i!=nums.size()-1))return false;
        }
        return true;
        
    }
};