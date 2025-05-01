class Solution {
    public:
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            // Sort tasks and workers in ascending order
            sort(tasks.begin(), tasks.end());
            sort(workers.begin(), workers.end());
            
            int n = tasks.size();
            int m = workers.size();
            
            // Binary search for the maximum number of tasks that can be completed
            int left = 0, right = min(n, m);
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                
                // Check if it's possible to complete mid tasks
                if (canAssignTasks(tasks, workers, pills, strength, mid)) {
                    left = mid + 1; // Try to complete more tasks
                } else {
                    right = mid - 1; // Try to complete fewer tasks
                }
            }
            
            return right; // Return the maximum number of tasks that can be completed
        }
        
    private:
        // Check if it's possible to complete k tasks
        bool canAssignTasks(vector<int>& tasks, vector<int>& workers, int pills, int strength, int k) {
            // Consider only the k easiest tasks (with lowest strength requirements)
            vector<int> selectedTasks(tasks.begin(), tasks.begin() + k);
            
            // Consider only the k strongest workers
            vector<int> selectedWorkers(workers.end() - k, workers.end());
            
            // Use a multiset to keep track of available workers
            multiset<int> availableWorkers(selectedWorkers.begin(), selectedWorkers.end());
            
            // Try to assign workers to tasks, starting from the hardest task
            for (int i = k - 1; i >= 0; i--) {
                int task = selectedTasks[i];
                
                // Try to find a worker who can complete the task without a pill
                auto it = availableWorkers.lower_bound(task);
                
                if (it != availableWorkers.end()) {
                    // Found a worker who can complete the task without a pill
                    availableWorkers.erase(it);
                } else if (pills > 0) {
                    // Try to find a worker who can complete the task with a pill
                    auto it = availableWorkers.lower_bound(task - strength);
                    
                    if (it != availableWorkers.end()) {
                        // Found a worker who can complete the task with a pill
                        availableWorkers.erase(it);
                        pills--;
                    } else {
                        // Cannot complete this task
                        return false;
                    }
                } else {
                    // Cannot complete this task
                    return false;
                }
            }
            
            return true;
        }
    };