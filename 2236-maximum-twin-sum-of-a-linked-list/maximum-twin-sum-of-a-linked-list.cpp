class Solution {
public:
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode* h = magic(head, n);

        n = n / 2;

        int ans = INT_MIN;

        ListNode* h1 = head;
        ListNode* h2 = h;

        while(h1 && h2 && n > 0)
        {
            ans = max(ans, h1->val + h2->val);

            h1 = h1->next;
            h2 = h2->next;
            n--;
        }

        return ans;
    }

private:

    ListNode* magic(ListNode* head, int& n)
    {
        ListNode* prev = NULL;

        while(head)
        {
            // copy node banao
            ListNode* node = new ListNode(head->val);

            node->next = prev;
            prev = node;

            head = head->next;
            n++;
        }

        return prev;
    }
};