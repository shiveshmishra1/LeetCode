class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            int n = tops.size();
            
            // Try to make all tops equal to tops[0]
            int rotations1 = checkRotations(tops[0], tops, bottoms, n);
            
            // Try to make all tops equal to bottoms[0]
            int rotations2 = checkRotations(bottoms[0], tops, bottoms, n);
            
            // Return the minimum valid rotations, or -1 if impossible
            int result = min(rotations1, rotations2);
            return result == INT_MAX ? -1 : result;
        }
        
    private:
        int checkRotations(int target, vector<int>& tops, vector<int>& bottoms, int n) {
            // Count rotations needed to make all tops = target
            int rotationsTop = 0;
            // Count rotations needed to make all bottoms = target
            int rotationsBottom = 0;
            
            for (int i = 0; i < n; i++) {
                // If neither top nor bottom matches target, we can't achieve the goal
                if (tops[i] != target && bottoms[i] != target) {
                    return INT_MAX;
                }
                
                // If top doesn't match target, we need a rotation for top approach
                if (tops[i] != target) {
                    rotationsTop++;
                }
                
                // If bottom doesn't match target, we need a rotation for bottom approach
                if (bottoms[i] != target) {
                    rotationsBottom++;
                }
            }
            
            // Return the minimum rotations between making all tops or all bottoms equal to target
            return min(rotationsTop, rotationsBottom);
        }
    };