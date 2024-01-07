class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1,s2,s3;
        int common=0,c=0;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            s1.insert(nums1[i]);
            s2.insert(nums2[i]);
        }
        for(auto i:s1)
            if(s2.find(i)!=s2.end())common++;
        for(int i=0;i<n;i++)
            if(s1.find(nums2[i])==s1.end() && c<n/2 && s3.find(nums2[i])==s3.end()){
                s3.insert(nums2[i]);
                c++;
            }
        c=0;
        for(int i=0;i<n;i++)
            if(s2.find(nums1[i])!=s2.end() && c<n/2 && s3.find(nums1[i])==s3.end()){
                s3.insert(nums1[i]);
                c++;
            }
        return s3.size()+common<=n?s3.size()+common:n;
    }
};