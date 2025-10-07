class Solution {
public:
    void f(int n,int out[],int r,vector<vector<string>>&ans){
  //base case
  if(r==n){
    vector<string>t;
    for(int i=0;i<n;i++){
    string temp;
      for(int j=0;j<n;j++){
        if(out[i]==j){
            temp += "Q";
        }
        else{
            temp += ".";
        }
      }
      t.push_back(temp);
    }
    ans.push_back(t);
    return;
  }
  //recursive case
  for(int j=0;j<n;j++){
    bool flag = true;
    for(int i=0;i<=r-1;i++){
      if(out[i]==j || out[i]== j+(r-i) || out[i] == j-(r-i)){
        flag = false;
        break;
      }
    }
    if(flag){
      out[r] =j;
      f(n,out,r+1,ans);
    }
  }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        int out[9];
        f(n,out,0,ans);
        return ans;
    }
};
