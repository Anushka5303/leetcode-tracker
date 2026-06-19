class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;

        for(int i=0; i<operations.size(); i++){
            if(operations[i]=="C"){
                if(ans.size()>=1) ans.pop_back();
            }else if(operations[i] == "+"){
                    int a = ans[ans.size()-1];
                    int b = ans[ans.size()-2];
                    ans.push_back(a+b);
            }else if(operations[i] == "D"){
                    int a = ans[ans.size()-1] * 2;
                    ans.push_back(a);
            }else{
                    ans.push_back(stoi(operations[i]));
            }
        }
        

        int op = 0;

        while(!ans.empty()){
            
                op += ans.back();
                ans.pop_back();

        }

        return op;
    }
};