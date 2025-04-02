class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            if (digits.empty()) return {};
            
            unordered_map<char, string> phone = {
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}
            };
            
            vector<string> result;
            string current;
            backtrack(digits, 0, phone, current, result);
            return result;
        }
        
    private:
        void backtrack(const string& digits, int index, const unordered_map<char, string>& phone, 
                      string& current, vector<string>& result) {
            if (index == digits.size()) {
                result.push_back(current);
                return;
            }
            
            string letters = phone.at(digits[index]);
            for (char c : letters) {
                current.push_back(c);
                backtrack(digits, index + 1, phone, current, result);
                current.pop_back();
            }
        }
    };