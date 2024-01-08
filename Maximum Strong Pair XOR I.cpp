struct Node {
    Node* links[2];
    int frequency; 
    Node() : frequency(0) {
        links[0] = links[1] = NULL;
    }

    bool containsKey(int bit) {
        return (links[bit] != NULL);
    }

    Node* get(int bit) {
        return links[bit];
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
            node->frequency++;
        }
    }

    int getMax(int num) {
        Node* node = root;
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit) && node->get(1 - bit)->frequency > 0) {
                res = res | (1 << i);
                node = node->get(1 - bit);
            } else {
                if(node->containsKey(bit) && node->get(bit)->frequency > 0) node = node->get(bit);
                else return 0;
            }
        }
        return res;
    }

    void deleteKey(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(bit)) {
                node = node->get(bit);
                node->frequency--;
            } else {
                break;
            }
        }
    }
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int maxi=0;
        int j=0;
        Trie t;
        t.insert(nums[0]);
        for(int i=1;i<n;i++) {
            while(j<i && nums[i]-nums[j]>min(nums[i],nums[j])) {
                t.deleteKey(nums[j]);
                ++j;
            }
            maxi=max(maxi,t.getMax(nums[i]));
            t.insert(nums[i]);
        }
        return maxi;
    }
};