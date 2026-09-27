class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;

        stack<ListNode*> st;

        ListNode* curr = head;

        while (curr != nullptr) {
            st.push(curr);
            curr = curr->next;
        }

        int n = st.size();

        curr = head;

        for (int i = 0; i < n / 2; i++) {

            ListNode* last = st.top();
            st.pop();

            ListNode* next = curr->next;

            curr->next = last;
            last->next = next;

            curr = next;
        }

        curr->next = nullptr;
    }
};