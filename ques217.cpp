class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_set<int> seen;
            
            for (int num : nums) {
                // If we've seen this number before, return true
                if (seen.find(num) != seen.end()) {
                    return true;
                }
                
                // Otherwise, add it to our set of seen numbers
                seen.insert(num);
            }
            
            // If we made it through the entire array without finding a duplicate
            return false;
        }
    };