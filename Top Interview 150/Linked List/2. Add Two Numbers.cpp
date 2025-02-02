/*
https://leetcode.com/problems/add-two-numbers/?envType=study-plan-v2&envId=top-interview-150
*/

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
    Solution(){}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int temp=0;
        bool finalL1 = l1==nullptr ? true: false, finalL2 = l2 ==nullptr ? true: false;

        ListNode* resultado = new ListNode();
        ListNode* inicioResultado = resultado;

        while((l1 != nullptr || l2 != nullptr) || temp!=0){
            if(finalL1==false){
                temp += l1->val;

                l1 = l1->next;
                if(l1 == nullptr){
                    finalL1 = true;
                }
            }

            if(finalL2==false){
                temp += l2->val;

                l2 = l2->next;
                if(l2 == nullptr){
                    finalL2 = true;
                }
            }

            resultado->val = temp%10;
            temp = temp/10;
            
            if( (finalL1==false || finalL2==false) || temp!=0){
                resultado->next = new ListNode();
                resultado = resultado->next;
            }
        }

        return inicioResultado;
    }
};