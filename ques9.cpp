class Solution {
    public:
        bool isPalindrome(int x) {
            std::string s = std::to_string(x);
            return s == std::string(s.rbegin(), s.rend());
        }
    };
    