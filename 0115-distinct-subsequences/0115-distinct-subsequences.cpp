const int MOD = 1e9 + 7;
class Solution {
    int solve(int i, int j,string &s, string &t, vector <vector<int>> &dp ){
        if (j<0) return 1;
        if (i<0) return 0;
         
        if (dp[i][j]!=-1) return dp[i][j];
        int m1=0,m2=0,nm=0;
        if (s[i]==t[j]){
            m1= solve(i-1,j-1,s,t,dp);
            m2= solve(i-1,j,s,t,dp);
        }
        else {
            nm=solve(i-1,j,s,t,dp);
        }
        return dp[i][j]=m1+m2+nm;
    }
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();

        vector <vector <int>> dp(n+1, vector <int> (m+1));

        for (int i=0; i<=n; i++){
            dp[i][0]=1;
        }
        for (int j=1; j<=m; j++){
            dp[0][j]=0;
        }

        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                int m1=0,m2=0,nm=0;
                if (s[i-1]==t[j-1]){
                m1= dp[i-1][j-1];
                m2= dp[i-1][j];
                }
                else {
                nm=dp[i-1][j];
                }
             dp[i][j]=(m1+m2+nm)%MOD;
            }
        }


        return dp[n][m];
    }
};