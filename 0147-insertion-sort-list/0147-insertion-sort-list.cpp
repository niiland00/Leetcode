//Definition for singly-linked list. 
/*struct ListNode { 
    int val; 
    ListNode *next; 
    ListNode() : val(0), next(nullptr) {} 
    ListNode(int x) : val(x), next(nullptr) {} 
    ListNode(int x, ListNode *next) : val(x), next(next) {} 
};*/

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *cur;
        //宣告一個新的Node以及它的pointer
        ListNode* dummy=new ListNode(0);

        cur=head;

        while(cur!=nullptr){
            //prev要在迴圈裡重宣告
            ListNode *prev=dummy;

            while(prev->next!=nullptr && prev->next->val<cur->val){
                prev=prev->next;
            }

            //因為cur->next要改了先存起來
            ListNode *next=cur->next;
            //先接後再接前
            cur->next=prev->next;
            prev->next=cur;
            //next使cur前進
            cur=next;
        }
        //不是return head因為head會變
        return dummy->next;
    }
};