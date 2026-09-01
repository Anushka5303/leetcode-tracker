class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> v(n), c(n);

        int i=0,j=n-1;

        while(i<n){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }

            v[i] = st.empty()? -1:st.top();
            st.push(i);
            i++;
        }
        while(!st.empty()) {
    st.pop();
}
        while(j>=0){
            while(!st.empty() && heights[st.top()]>=heights[j]){
                st.pop();
            }

            c[j] = st.empty()? n:st.top();
            st.push(j);
            j--;
        }
        int area = INT_MIN;
        for(int ind = 0; ind<n; ind++){
            int width = c[ind] - v[ind] - 1;
            area = max(area , heights[ind]*width);
        }
        
        return area;


    }
};