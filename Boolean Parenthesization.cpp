/*Boolean Parenthesization

Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Note: The answer can be large, so return it with modulo 1003

 

Example 1:

Input: N = 7
S = T|T&F^T
Output: 4
Explaination: The expression evaluates 
to true in 4 ways ((T|T)&(F^T)), 
(T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).
Example 2:

Input: N = 5
S = T^F|F
Output: 2
Explaination: ((T^F)|F) and (T^(F|F)) are the 
only ways.
 

Your Task:
You do not need to read input or print anything. Your task is to complete the function countWays() which takes N and S as input parameters and returns number of possible ways modulo 1003.

 

Expected Time Complexity: O(N3)
Expected Auxiliary Space: O(N2)

 

Constraints:
1 ≤ N ≤ 200
*/


// User function Template for C++
class Solution{
    public:
    int solve(string &S,int i,int j,int istrue,unordered_map<string, int>&dp){
        if(i>j){
            return 0;
        }if(i==j){
            if(istrue==1){
                return S[i]=='T';
            }else{
                return S[i]=='F';
            }
        }
        string temp=to_string(i)+"-"+to_string(j)+"-"+to_string(istrue);
        if(dp.find(temp)!=dp.end()){
            return dp[temp];
        }
        int ans=0;
        int modulo=1003;
        for(int k=i+1;k<=j;k=k+2,dp){
            int lt=solve(S,i,k-1,1,dp)%modulo;
            int lf=solve(S,i,k-1,0,dp)%modulo;
            int rt=solve(S,k+1,j,1,dp)%modulo;
            int rf=solve(S,k+1,j,0,dp)%modulo;
            
            if(S[k]=='&'){
                if(istrue==1){
                    ans+=lt*rt;
                }else{
                    ans+=lf*rt+lt*rf+lf*rf;
                }
            }else if(S[k]=='|'){
                if(istrue==1){
                    ans+=lf*rt+lt*rf+lt*rt;
                }else{
                    ans+=lf*rf;
                }
            }else if(S[k]=='^'){
                if(istrue==1){
                    ans+=lf*rt+lt*rf;
                }else{
                    ans+=lt*rt+lf*rf;
                }
            }
        }
        return dp[temp]=ans%modulo;
    }
    int countWays(int N, string S){
        // code here
        unordered_map<string, int> dp;
        dp.clear();
        return  solve(S,0,N-1,1,dp);
    }
};
