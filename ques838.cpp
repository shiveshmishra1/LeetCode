class Solution {
    public:
        string pushDominoes(string dominoes) {
            int n = dominoes.size();
            vector<int> forces(n, 0);
            
            // Calculate forces from left to right
            int force = 0;
            for (int i = 0; i < n; i++) {
                if (dominoes[i] == 'R') {
                    force = n; // Set a large enough force
                } else if (dominoes[i] == 'L') {
                    force = 0; // Reset force
                } else {
                    force = max(0, force - 1); // Decrease force by 1
                }
                forces[i] += force;
            }
            
            // Calculate forces from right to left
            force = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (dominoes[i] == 'L') {
                    force = n; // Set a large enough force
                } else if (dominoes[i] == 'R') {
                    force = 0; // Reset force
                } else {
                    force = max(0, force - 1); // Decrease force by 1
                }
                forces[i] -= force; // Subtract because left force is negative
            }
            
            // Convert forces to final state
            string result = "";
            for (int i = 0; i < n; i++) {
                if (forces[i] > 0) {
                    result += 'R';
                } else if (forces[i] < 0) {
                    result += 'L';
                } else {
                    result += '.';
                }
            }
            
            return result;
        }
    };