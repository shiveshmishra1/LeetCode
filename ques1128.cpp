#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        // Map to store the count of each normalized domino
        unordered_map<int, int> dominoCount;
        int result = 0;
        
        for (const auto& domino : dominoes) {
            // Normalize the domino by ensuring the smaller number is first
            // This way, [1,2] and [2,1] will have the same key
            int key = min(domino[0], domino[1]) * 10 + max(domino[0], domino[1]);
            
            // For each occurrence of this normalized domino that we've seen before,
            // we can form a new pair with the current domino
            result += dominoCount[key];
            
            // Increment the count for this normalized domino
            dominoCount[key]++;
        }
        
        return result;
    }
};