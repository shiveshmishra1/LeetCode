class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int n = s.length();
        char digit1 = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != '9'){
                digit1 = s[i];
                break;
            }
        }
        string Max = "";
        for(int i = 0; i < n; i++){
            if(s[i] == digit1){
                Max += '9';
            } else Max += s[i];
        }
        char digit2 = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != '0'){
                digit2 = s[i];
                break;
            }
        }
        string Min = "";
        for(int i = 0; i < n; i++){
            if(s[i] == digit2){
                Min += '0';
            } else Min += s[i];
        }
        int minNum = stoi(Min), maxNum = stoi(Max);
        return maxNum - minNum;
    }
};
