class FindSumPairs {
    vector<int> n1,n2;
    unordered_map<int,int> umap;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for(int i:n2){
            umap[i]++;
        }
    }
    
    void add(int index, int val) {
        umap[n2[index]]--;
        n2[index] += val;
        umap[n2[index]]++;
    }
    
    int count(int tot) {
        int c = 0;
        for(int i:n1){
            c += umap[tot-i];
        }
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */