class Solution {
    int catalon_number(int n){
        int catalon[n+1];
        catalon[0]=catalon[1]=1;
        for(int i=2;i<=n;i++){
            catalon[i]=0;
            for(int j=0;j<i;j++){
              catalon[i]+=catalon[j]*catalon[i-j-1];
            }
            
        }
        return catalon[n];
    }
public:
    int numTrees(int n) {
        return catalon_number(n);
        
    }
};
