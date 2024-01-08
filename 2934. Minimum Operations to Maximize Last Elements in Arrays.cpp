class Solution {
public:
    int sol(vector<int>nums1, vector<int>nums2){
        int h1=nums1[nums1.size()-1];
        int h2=nums2[nums1.size()-1];
        int ans=0;
        for(int i=0;i<nums1.size()-1;i++){
            if(nums1[i]>h1){
                if(nums2[i]>h1)return -1;
                else{ swap(nums1[i],nums2[i]);ans++;}
            }
            if(nums2[i]>h2){
                if(nums1[i]>h2)return -1;
                else{ swap(nums2[i],nums1[i]);ans++;}
            }
            if(nums1[i]>h1 || nums2[i]>h2)return -1;
        }

        return ans;
    }
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int ans1=sol(nums1,nums2);
        swap(nums1[nums1.size()-1],nums2[nums1.size()-1]);
        int ans2=sol(nums1,nums2);
        if(ans1==ans2)return ans1;
        else if(ans1==-1)return ans2+1;
        else if(ans2==-1)return ans1;
        else return min(ans1,ans2+1);
    }
};