class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int>s;
        for(auto t:nums){
            s.insert(t);
        }
        int sum = nums[0];
        for(int i = 1;i<nums.size();i++){
            if(nums[i]-1==nums[i-1]){
                sum+=nums[i];
            }
            else break;
        }
        for(int i = sum;;i++){
            if(s.find(i)==s.end())
                return i;
        }
        return -1;
    }
};