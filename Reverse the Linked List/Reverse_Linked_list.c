#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} SLL;

SLL *insert(SLL *head, int val)
{
    if(head == NULL)
    {
        head = (SLL*) malloc(sizeof(SLL*));
        head->data = val;
        head->next = NULL;
    }
    else
	{
        SLL *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        SLL *new = (SLL*) malloc(sizeof(SLL*));
        new->data = val;
        new->next = NULL;
        temp->next = new;
    }
    return head;
}

void printList(SLL *head)
{
    SLL*temp = head;
    while(temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

SLL *reverseList(SLL *head)
{
    SLL *prev = head;
    SLL *curr = head->next;     // prev->next
    SLL *next = head->next->next;       // curr->next

    // removing the link between 1st and 2nd node
    head->next = NULL;

    while(next != NULL)
    {
        // reversed the link in betweeen current and next node
        curr->next = prev;

        // iterating the pointers
        // prev = prev->next; wrong method
        prev = curr;
        curr = next;
        next = next->next;
    }

    // to make the link between last node and last second node
    curr->next = prev;
    head = curr;
    return head;
}

int main()
{
	// creating the list
    SLL *head = NULL;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);
    head = insert(head, 6);
    head = insert(head, 7);
    head = insert(head, 8);
    head = insert(head, 9);
    head = insert(head, 10);
    
	// printing the list
    printf("Original List : ");
    printList(head);

    head = reverseList(head);

    printf("Reversed List : ");
    printList(head);

    return 0;
}