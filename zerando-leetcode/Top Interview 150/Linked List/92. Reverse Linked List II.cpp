/*
https://leetcode.com/problems/reverse-linked-list-ii/description/?envType=study-plan-v2&envId=top-interview-150
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int cont=2;

        ListNode* backupCabeca=head;
        while(cont++<left){
            head = head->next;
        }

        ListNode t = ListNode(0, head);

        vector<ListNode*> sequencia;
        if(left!=1) sequencia.push_back(head);
        else{
            //cout << "aqui";            
            sequencia.push_back(&t);
            sequencia.push_back(head);

            //cout << (t.next->val) << "\n";
        }

        for(int i=left; i<=right; i++){
            head = head->next;
            sequencia.push_back(head);            
        }

        int tam = right - left + 1;
        for(int i=1; i<=tam/2; i++){
            int reverso = tam-i+1;

            if(i+1!=reverso){
                //printf("{%d, %d}\n", i, reverso);
                //printf("{%d, %d}\n\n", sequencia[i]->val, sequencia[reverso]->val);
                //
                //printf("{%d, %d}\n", sequencia[i-1]->val, sequencia[reverso-1]->val);
                //printf("{%d, %d}\n", sequencia[i-1]->next->val, sequencia[reverso-1]->next->val);

                sequencia[i-1]->next = sequencia[reverso];
                sequencia[reverso-1]->next = sequencia[i];

                //printf("{%d, %d}\n", sequencia[i-1]->val, sequencia[reverso-1]->val);
                //printf("{%d, %d}\n", sequencia[i-1]->next->val, sequencia[reverso-1]->next->val);
                swap(sequencia[i]->next, sequencia[reverso]->next);
                swap(sequencia[i], sequencia[reverso]);
            }
            else{
                sequencia[i-1]->next = sequencia[reverso];

                ListNode* temp = sequencia[reverso]->next;
                sequencia[reverso]->next = sequencia[i];
                sequencia[i]->next=temp;

                swap(sequencia[i], sequencia[reverso]);
            }
        }

        
        if(left==1){
            return sequencia[1];
        }
        else{
            return backupCabeca;
        }
    }
};