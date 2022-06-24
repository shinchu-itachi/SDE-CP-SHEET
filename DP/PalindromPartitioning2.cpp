// problem link : https://leetcode.com/problems/palindrome-partitioning-ii/
class Solution {
  public:
    bool isPalindrome ( int i , int j , string &s) {
        while ( i < j ) {
            if ( s.at(i ++) != s.at(j --)) return false;
        }

        return 1;
    }
    int find ( int i , string &s , vector<int> &dp) {
        if ( i == s.size()) return 0;
        if ( dp[i] != -1) return dp[i];
        int mn = INT_MAX;
        for ( int j = i ; j < s.size() ; j ++) {
            if ( isPalindrome ( i , j , s)) {
                int cost = 1 + find( j + 1 , s, dp);
                mn = min ( mn , cost );
            }
        }

        return dp[i] = mn;
    }
    int minCut(string s) {
        // so this is a variant problem of dp on partition
        // here we have to select the cuts ffrom 1 to s.sz() and find min option
        // answer always exist since n -1 substrings can always be get

        int ans = 0 ;
        int n = s.size();
        vector<int> dp ( n + 1 , 0 );
        dp[n] = 0 ;

        for ( int i = n - 1 ; i >= 0 ; i --) {
            int mn = INT_MAX;
            for ( int j = i ; j < s.size() ; j ++) {
                if ( isPalindrome ( i , j , s)) {
                    int cost = 1 + dp[j + 1];
                    mn = min ( mn , cost );
                }
            }
            dp[i] = mn ;
        }
        // ans = find( 0 , s , dp);

        return dp[0] - 1;
    }
};