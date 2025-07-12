class Solution {
public:
    int mx = INT_MIN, mn = INT_MAX;
    int N = 0, f = 0, s = 0;
    int dp[27][27][27];
    void calc(int mask,int round,int i,int j,int l,int m,int r){
        if(i>=j){
            calc(mask,round+1,0,N,l,m,r); // increment round and reset pointers
        }
        else if((mask&(1<<i)) == 0){
            calc(mask,round,i+1,j,l,m,r); 
        }
        else if((mask&(1<<j)) == 0){
            calc(mask,round,i,j-1,l,m,r);
        }
        else if(i==f && j==s){ // best players comes head to head
            mx = max(mx,round);
            mn = min(mn,round); 
        }
        else if(dp[l][m][r]==-1){ // do not enter if state is visited
            dp[l][m][r] = 1; // this state is visited 
            if(i!=f && i!=s){ 
                calc(mask^(1<<i),round,i+1,j-1,l-(i<f),m-((i>f)&&(i<s)), r - (i>s));
            }
            if(j!=f && j!=s){
                calc(mask^(1<<j),round,i+1,j-1,l-(j<f),m-((j>f)&&(j<s)), r - (j>s)); 
            }
        }
    }
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        N = n-1; f = firstPlayer - 1; s = secondPlayer -1;
        memset(dp,-1,sizeof(dp));
        calc((1<<n)-1,1,0,n-1,f,s-f-1,N-s);
        return {mn,mx};
    }
};
