#include <stdio.h>
#include <stdlib.h>

#include "resource.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* result=NULL;
    struct ListNode* prev_node;
    int a=0;
    int b=0;
    int next_num=0;

    while(l1 != NULL || l2 != NULL || next_num == 1)
    {
        if(l1 == NULL)
            a = 0;
        else{
            a = l1->val;
            l1 = l1->next;
        }

        if(l2 == NULL)
            b = 0;
        else{
            b = l2->val;
            l2 = l2->next;
        }

        struct ListNode* currentNode;
        currentNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        
        int temp = a+b+next_num;
        if(temp > 9)
        {
            temp -= 10;
            next_num = 1;
        }else
            next_num = 0;
        
        currentNode->val = temp;
        currentNode->next = NULL;
        
        // add new node to the prev_node->next, then move prev_node to current node
        if(!result)
            result = currentNode;
        else
            prev_node->next = currentNode;
        
        prev_node = currentNode;
    }
    
    return result;
}

int main(int argc, char* argv[]){
	struct ListNode* i_a=NULL;
	struct ListNode* i_b=NULL;
    struct ListNode* prev_a;
    struct ListNode* prev_b;
    struct ListNode* result;

    int a[3] = {2,4,5};
    int b[3] = {5,6,4};
	for(int i=0; i<3; i++)
	{
		struct ListNode* currentNode_a;
		struct ListNode* currentNode_b;
        currentNode_a = (struct ListNode*)malloc(sizeof(struct ListNode));
        currentNode_b = (struct ListNode*)malloc(sizeof(struct ListNode));

		currentNode_a->val = a[i];
		currentNode_a->next = NULL;
        currentNode_b->val = b[i];
        currentNode_b->next = NULL;

        if(!i_a)
            i_a = currentNode_a;
        else
            prev_a->next = currentNode_a;
        prev_a = currentNode_a;

        if(!i_b)
            i_b = currentNode_b;
        else
            prev_b->next = currentNode_b;
        prev_b = currentNode_b;
	}

    result = addTwoNumbers(i_a, i_b);

    while(result != NULL)
    {
        printf("%d\n", result->val);
        result = result->next;
    }
}
