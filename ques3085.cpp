class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.length();
        unordered_map<char, int> freq;
        for(int i = 0; i < n; i++) freq[word[i]]++;
        int res = INT_MAX;
        for(auto [ch, f1]: freq){
            int deletions = 0;
            for(auto [ch, f2]: freq){
                int diff = f2 - f1;
                if(f2 < f1) deletions += f2;
                else if(diff > k) deletions += (f2 - f1 - k);
            }
            res = min(res, deletions);
        }
        return res;
    }
};
