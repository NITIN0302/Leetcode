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
    
    ListNode* solve(ListNode* ans,ListNode* l1, ListNode* l2,int carry)
    {
        if(!l1 && !l2)
        {
            if(carry != 0)
            {
                return new ListNode(carry);
            }
            return NULL;
        }
        
        int sum = 0;
        if(l1)
        {
            sum += l1->val;
        }
        if(l2)
        {
            sum += l2->val;
        }
        sum += carry;
        carry = sum/10;
        ans = new ListNode(sum%10);
        
        
        if(!l1 && l2)
        {
            ans->next = solve(ans->next,l1,l2->next,carry); 
        }
        else if(l1 && !l2)
        {
            ans->next = solve(ans->next,l1->next,l2,carry);
        }
        else
        {
            ans->next = solve(ans->next,l1->next,l2->next,carry);
        }
        return ans;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
       ListNode* ans;
       ans = solve(ans,l1,l2,0);
       return ans; 
    }
};