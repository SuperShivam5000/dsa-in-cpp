class Solution {
    public:
        int numTrees(int n) { //solution using catalan number
            long long C=1;
            for(int i=0;i<n;i++){
                C=C*(2*n-i)/(i+1);
            }
            return C/(n+1);
        }
    };