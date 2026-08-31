class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        ListNode* current = head->next;
        ListNode* pre = head;

        int pos = 2;

        int first = -1;
        int prev = -1;

        int mini = INT_MAX;
        int maxi = -1;

        while (current->next) {

            // Check if current is a critical point
            if ((current->val > pre->val && 
                 current->val > current->next->val) ||
                
                (current->val < pre->val && 
                 current->val < current->next->val)) {

                // First critical point
                if (first == -1) {
                    first = pos;
                }

                // We already have a previous critical point
                if (prev != -1) {
                    mini = min(mini, pos - prev);
                }

                // Current critical point becomes previous
                prev = pos;
            }

            pre = current;
            current = current->next;
            pos++;
        }

        // Fewer than 2 critical points
        if (first == -1 || prev == first) {
            return {-1, -1};
        }

        // Distance between first and last critical point
        maxi = prev - first;

        return {mini, maxi};
    }
};