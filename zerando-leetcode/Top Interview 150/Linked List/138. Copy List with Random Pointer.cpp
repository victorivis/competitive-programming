/*
https://leetcode.com/problems/copy-list-with-random-pointer/description/?envType=study-plan-v2&envId=top-interview-150
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, int> randomToPos;
        vector<Node*> posToRandom;

        vector<Node*> copiedListPos;

        if(head==NULL) return NULL;

        Node* temp = head;

        Node* newList = (Node*) malloc(sizeof(Node));
        newList->next=NULL;

        Node* copiedTemp = newList;
        
        int cont=0;
        while(temp!=NULL){
            //cout << (temp->val) << " " << newList << " ";

            if(cont==0){
                copiedTemp->val=temp->val;
            }
            else{
                Node* newNode = (Node*) malloc(sizeof(Node));
                newNode->val=temp->val;
                newNode->next=NULL;

                copiedTemp->next = newNode;
                copiedTemp=newNode;                
            }

            randomToPos[temp]=cont;
            posToRandom.push_back(temp->random);

            copiedListPos.push_back(copiedTemp);

            temp=temp->next;
            cont++;
        }

        for(int i=0; i<cont; i++){
            Node* currRandom = posToRandom[i];
            if(currRandom!=NULL){
                int equivalentPos = randomToPos[currRandom];
                copiedListPos[i]->random = copiedListPos[equivalentPos];
            }
            else{
                copiedListPos[i]->random = NULL;
            }            
        }

        return newList;
    }
};