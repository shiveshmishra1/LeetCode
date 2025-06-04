

class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();
        string res = "";
        if(numFriends == 1) return word;
        int len = n - numFriends + 1;
        for(int i = 0; i < n; i++){
            res = max(res, word.substr(i, len));
        }
        return res;
    }
};
