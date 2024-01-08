#include<bits/stdc++.h>
using namespace std;
int maxProfitAssignment(vector<int>& diff, vector<int>& pro, vector<int>& wor) {
        vector<pair<int,int>>v;
        for(int i=0;i<diff.size();i++){
            v.push_back({diff[i],pro[i]});
        }
        int maxi=0;
        for(int i=0;i<diff.size();i++){
            v[i].second=max(maxi,v[i].second);
            maxi=max(v[i].second,maxi);
        }
        int ans=0;
        for(int i=0;i<wor.size();i++){
            int start=0;
            int end=diff.size()-1;
            int index=-1;
            while(start<=end){
                int mid=(start+end)/2;
                if(v[mid].first>wor[i]){
                    end=mid-1;
                }
                else{
                    index=mid;
                    start=mid+1;
                }
                cout<<index<<endl;
            }
            if(index==-1){
                continue;
            }
            ans+=v[index].second;
        }
        return ans;
    }
int main(){
    // string s="012";
    // int m=stoi(s);
    // cout<<m;
    // cout<<((10)>>2);
    // vector<int>v={1,2,3};
    // maxProfitAssignment(v,v,v);
    // vector<int>arr={1,2,4,5};
    // auto t=lower_bound(arr.begin(),arr.end(),3);
    // cout<<*t<<endl;
}