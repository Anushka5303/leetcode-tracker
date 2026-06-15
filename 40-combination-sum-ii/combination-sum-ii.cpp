class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {  
        sort(candidates.begin(), candidates.end());

        int i=0;
        vector<int> ds;
        vector<vector<int>> ans;

        magic(candidates, target, i, ds, ans);

        return ans;
        
    }
private:
    void magic(vector<int>& candidates, int target, int i, vector<int> ds, vector<vector<int>>& ans)
    {   

        if(target==0)
        {
            ans.push_back(ds);
            return;
        }

        for(int j=i; j<candidates.size(); j++)
        {
            if(j>i && candidates[j]==candidates[j-1]) continue;

            if (candidates[j] > target) break;

            if(candidates[j] <= target){
                ds.push_back(candidates[j]);
                magic(candidates,target-candidates[j],j+1,ds,ans);
                ds.pop_back();
            }
            
        }
    }
};