/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

     int Helper(ListNode* temp) {

        if (temp == NULL) {
            return 0;
        }

        int carry = Helper(temp->next);

        int sum = temp->val * 2 + carry;

        temp->val = sum % 10;

        return sum / 10;
    }
    
    ListNode* doubleIt(ListNode* head) {
         int carry = Helper(head);

        if (carry > 0) {
            ListNode* newNode = new ListNode(carry);

            newNode->next = head;

            head = newNode;
        }

        return head;
    }
};