class Solution {
  public:
    int minimumDays(int S, int N, int M) {
        int buyingdays = S-(S/7);
        int totalfood = S*M;
        
        int ans;
        if(totalfood%N==0) ans=totalfood/N;
        else ans=(totalfood/N) + 1;
        
        if(ans<=buyingdays) return ans;
        else return -1;
    }
};