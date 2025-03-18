/*
https://leetcode.com/problems/merge-two-sorted-lists/description/?envType=study-plan-v2&envId=top-interview-150
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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode resposta;
        
        if(list2 == null){
            return list1;
        }
        else if(list1 == null){
            return list2;
        }
        else{
            if(list1.val < list2.val){
                resposta = list1;
            }
            else{
                resposta = list2;
            }
        }
        
        while(list1!=null && list2!=null){
            if(list1.val >= list2.val){
                ListNode temp = list1;
                list1 = list2;
                list2 = temp;
            }
            
            if(list1.next == null){
                list1.next = list2;
                break;
            }
            else{
                if(list1.next.val < list2.val){
                    list1 = list1.next;
                }
                else{
                    ListNode temp = list1.next;
                    list1.next = list2;
                    list1 = temp;
                }
            }
        }
        
        return resposta;
    }
}