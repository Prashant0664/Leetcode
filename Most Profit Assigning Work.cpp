class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& pro, vector<int>& wor) {
        vector<pair<int,int>>v;
        for(int i=0;i<diff.size();i++)
            v.push_back({diff[i],pro[i]});
        sort(v.begin(),v.end());
        for(int i=1;i<diff.size();i++)
            v[i].second=max(v[i-1].second,v[i].second);
        int ans=0;
        for(int i=0;i<wor.size();i++){
            int start=0,end=diff.size()-1,index=-1;
            while(start<=end){
                int mid=(start+end)>>1;
                if(v[mid].first>wor[i])
                    end=mid-1;
                else{
                    index=mid;
                    start=mid+1;
                }
            }
            if(index!=-1)
                ans+=v[index].second;
        }
        return ans;
    }
};