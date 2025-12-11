class Solution {
public:
    vector<int>ans;
    void f(int x , int n){
        if(x>n) return;
        if(x!=0) ans.push_back(x);
        for(int j = 0 ; j<=9 ; j++){
            if(x==0 && j==0) continue;
            f(10*x + j , n);
        }
    }
    vector<int> lexicalOrder(int n) {
        ans.clear();
        f(0,n);
        return ans;
    }
};