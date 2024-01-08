class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0; i < 32; ++i){
            int count = 0;
            for(int j = 0; j < nums.size(); ++j)
                if(nums[j] & (1 << i)) count++;
            if(k & (1 << i))
                if(count%2 == 0) ans++;
            }else{
                if(count%2 == 1) ans++;
            }
        }
        return ans;
    }
};