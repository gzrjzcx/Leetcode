#Singly-linked list
The most remarkable part in this problem is that how to add elements to a linked list.

## Define
```c
struct ListNode
{
	// One value, one pointer
	int val;
	struct ListNode *next;
};
```
## Initialization
There are two ways to initialize the singly-linked list:
![initialization](/add_two_numbers/res/linkedlist.pdf)
**Typically head node is intended to normalized various operations like `add`, `delete` instead of storing data**  
- `Head node is not the necessary for singly-linked list.`
- `Root pointer is the essential requirement for singly-linked list`
##### With head node
- define a **head node** and assignment to root pointer:
```c
/* define a root point */
struct ListNode *root;
/* create a node and return the pointer to assignment to root pointer */
root = (struct ListNode *)malloc(sizeof(struct ListNode));
root->next = NULL;
```
##### Without head node
- define the root pointer and link it to data node directly:
```c
/* define a root point */
struct ListNode *root = NULL;
```
## Add elements to end
Here assuming that we have initialized a linked list **without** head node, and then we need add the elements to the end in order. For example, we want to store `6,7,8` to the list in order:
```c
/* define the root node */
struct ListNode *root = NULL;
/* define prev_node to add node, because we can not operate root node,
   root node means the first address of this list */
struct ListNode *prev_node;

int a[3]={6,7,8};
for(int i=0; i<3; i++)
{
	struct ListNode *current_node;
	current_node = (struct ListNode *)malloc(sizeof(struct ListNode));

	current_node->val = a[i];
	current_node->next = NULL;

	if(!root)
		/* firstly, need to assign the current node to root pointer */
		root = current_node;
	else
		/* must assign prev_node->next firstly otherwise prev_node->next will lose */
		prev_node->next = current_node;
	prev_node = current_node;
}
```
The idea here is that firstly assigning current node to the root node(in the first time, then root node should not be modified), and assignment prev_node to the current node. After then each time assigning prev_node->next to the current node and then assigning current node to the prev_node.  
**Must assigning prev_node before assigning current node to prev_node, otherwise will lose the connection in the link.**  
The process can be illustrated by the graph below:
![add node](/add_two_numbers/res/addnode.pdf)