/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0; // 记录进位    
        int sum = 0; // 记录该位数和

        ListNode* newHead = new ListNode(0, nullptr);
        ListNode* nowNode = newHead;

        while (l1 || l2 || carry) //l1，l2都为空且无进位时退出循环
        {
            sum = (l1?l1->val:0) + (l2?l2->val:0) + carry; //该位数和等于链表对应位置之和加上一位的进位
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10, nullptr);

            nowNode -> next = node;
            nowNode = nowNode -> next;

            l1 = l1?l1->next:l1;
            l2 = l2?l2->next:l2; // 将新节点加入结果链表中

        }
        
        return newHead->next;

    }
};