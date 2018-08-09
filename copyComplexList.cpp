/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
//*next和random都是新链表之间的相对关系
 /*
        1、复制每个节点，如：复制节点A得到A1，将A1插入节点A后面
        2、遍历链表，A1->random = A->random->next;
        3、将链表拆分成原链表和复制后的链表
    */
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return NULL;
        RandomListNode* currNode = pHead;
        while(currNode) {
            RandomListNode* node = new RandomListNode(currNode->label);
            node->next = currNode->next;
            currNode->next = node;
            currNode = node->next;
        }
        currNode = pHead;
        while(currNode) {
            RandomListNode* node = currNode->next;
            if(currNode->random) {
                node->random = currNode->random->next;
            }
            currNode = node->next;
        }
        
        RandomListNode* rec = pHead->next;
        currNode = pHead;
        RandomListNode* temp;
        //RandomListNode* nextNew;
        while(currNode->next) {
             
            temp = currNode->next;
            
            currNode->next = temp->next;
            currNode = temp;
            
            //temp->next = nextNew;
        }
        return rec;
    }
};
