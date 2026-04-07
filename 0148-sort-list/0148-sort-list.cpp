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
    ListNode * sortList(ListNode * head){
        if(head==nullptr || head->next==nullptr) return head;

        //找中點
        ListNode * slow=head;
        ListNode * fast=head->next;//讓中點偏左
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        //中點
        ListNode * mid=slow->next;
        slow->next=nullptr;
        
        //對兩半進行遞迴排序
        ListNode * left=sortList(head);
        ListNode * right=sortList(mid);
        //合併
        return merge(left,right);
    }
private:
    ListNode * merge(ListNode * l1, ListNode * l2){
        ListNode dummy(0);
        ListNode * tail=& dummy;

        while(l1!=nullptr && l2!=nullptr){
            if(l1->val < l2->val){
                tail->next=l1;
                l1=l1->next;
            }
            else{
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        //剩下節點直接接上去不用一一更新next
        //只需接一次所以是if
        if(l1!=nullptr) tail->next=l1;
        if(l2!=nullptr) tail->next=l2;

        return dummy.next;
    }
};