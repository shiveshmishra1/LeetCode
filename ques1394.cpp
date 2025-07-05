class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) mp[arr[i]]++;
        int luckyInt = -1;
        for(auto [val, freq]: mp){
            if(val == freq) luckyInt = max(luckyInt, val);
        }
        return luckyInt;
    }
};
