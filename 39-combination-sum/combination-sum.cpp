class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int i=0;
        vector<int> ds;
        vector<vector<int>> ans;

        magic(candidates,target,i,ds,ans);

        return ans;
    }
private:
    void magic(vector<int>& candidates, int target, int i, vector<int>& ds, vector<vector<int>>& ans)
    {
        if(i>=candidates.size())
        {
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }

        if(target==0){
            ans.push_back(ds);
            return;
        }

        if(target - candidates[i] >=0){
            ds.push_back(candidates[i]);
            magic(candidates,target-candidates[i],i,ds,ans);

            ds.pop_back();

        }
            magic(candidates,target,i+1,ds,ans);
        

    }
};