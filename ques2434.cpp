class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        unordered_map<char, int> cnt;
        for(char c: s) cnt[c]++;
        string res = "";
        char minCh = 'a';
        stack<char> st;
        for(char c: s){
            st.push(c);
            cnt[c]--;
            while(minCh != 'z' && cnt[minCh] == 0) minCh++;
            while(!st.empty() && st.top() <= minCh){
                res += st.top();
                st.pop();
            }
        }
        return res;
    }
};
