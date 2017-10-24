/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8*/

/************************     answer  code      ***************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
**/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode* head = NULL;
    struct ListNode* cur = NULL;
    
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    cur = head;
    cur->next = NULL;
    
    int carry = 0;
    int val1 = l1->val;
    int val2 = l2->val;
    
    bool end1 = false;
    bool end2 = false;
    
    while (1)
    {
        if (end1==false || end2==false || carry!=0)
        {
            cur->val = val1 + val2 + carry;
            carry = cur->val / 10;
            cur->val = cur->val % 10;
        }
        else
        {
            break;
        }
        
        if (l1->next == NULL)
        {
            val1 = 0;
            end1 = true;
        }
        else
        {
            l1 = l1->next;
            val1 = l1->val;
        }
        
        if (l2->next == NULL)
        {
            val2 = 0;
            end2 = true;
        }
        else
        {
            l2 = l2->next;
            val2 = l2->val;
        }
        
        if (end1==false || end2==false || carry!=0)
        {
            cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            cur = cur->next;
            cur->next = NULL;
        }
    }
    
    return head;
}
