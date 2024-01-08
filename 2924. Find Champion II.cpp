class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        set<int>s;
        for(int i=0;i<edges.size();i++)
            s.insert(edges[i][1]);
        if(s.size()!=n-1)return -1;
        for(int i=0;i<edges.size();i++)
            if(s.find(edges[i][0])==s.end())
                return edges[i][0];
        return -1;
    }
};