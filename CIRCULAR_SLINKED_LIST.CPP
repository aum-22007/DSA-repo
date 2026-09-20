#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Create node */
struct Node* createNode(int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

/* 1. Insert at beginning */
void insertBeginning(int value)
{
    struct Node *newNode = createNode(value);
    struct Node *temp;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    temp = head;

    while (temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

/* 2. Insert at end */
void insertEnd(int value)
{
    struct Node *newNode = createNode(value);
    struct Node *temp;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    temp = head;

    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

/* 3. Insert after given value */
void insertAfter(int key, int value)
{
    struct Node *temp = head;
    struct Node *newNode;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    do {
        if (temp->data == key)
            break;

        temp = temp->next;
    } while (temp != head);

    if (temp->data != key) {
        printf("Value not found\n");
        return;
    }

    newNode = createNode(value);

    newNode->next = temp->next;
    temp->next = newNode;
}

/* 4. Insert before given value */
void insertBefore(int key, int value)
{
    struct Node *temp;
    struct Node *prev;
    struct Node *newNode;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    prev = NULL;

    do {
        if (temp->data == key)
            break;

        prev = temp;
        temp = temp->next;
    } while (temp != head);

    if (temp->data != key) {
        printf("Value not found\n");
        return;
    }

    newNode = createNode(value);

    /* key is at head */
    if (temp == head) {
        struct Node *last = head;

        while (last->next != head)
            last = last->next;

        newNode->next = head;
        last->next = newNode;
        head = newNode;
    }
    else {
        newNode->next = temp;
        prev->next = newNode;
    }
}

/* 5. Delete beginning */
void deleteBeginning()
{
    struct Node *temp;
    struct Node *last;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    /* Only one node */
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    last = head;

    while (last->next != head)
        last = last->next;

    temp = head;
    head = head->next;
    last->next = head;

    free(temp);
}

/* 6. Delete end */
void deleteEnd()
{
    struct Node *temp;
    struct Node *prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    /* Only one node */
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    prev = NULL;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
}

/* 7. Delete node containing given value */
void deleteValue(int key)
{
    struct Node *temp;
    struct Node *prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    /* Delete head */
    if (head->data == key) {
        deleteBeginning();
        return;
    }

    prev = head;
    temp = head->next;

    while (temp != head) {

        if (temp->data == key) {
            prev->next = temp->next;
            free(temp);
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Value not found\n");
}

/* 8. Delete node after given value */
void deleteAfter(int key)
{
    struct Node *temp;
    struct Node *del;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    do {
        if (temp->data == key)
            break;

        temp = temp->next;
    } while (temp != head);

    if (temp->data != key) {
        printf("Value not found\n");
        return;
    }

    del = temp->next;

    /* Only one node */
    if (del == temp) {
        free(del);
        head = NULL;
        return;
    }

    /* Deleting head */
    if (del == head)
        head = head->next;

    temp->next = del->next;

    free(del);
}

/* 9. Delete node before given value */
void deleteBefore(int key)
{
    struct Node *temp;
    struct Node *prev;
    struct Node *prevPrev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    /* If key is head, delete last node */
    if (head->data == key) {
        deleteEnd();
        return;
    }

    prevPrev = NULL;
    prev = head;
    temp = head->next;

    do {
        if (temp->data == key)
            break;

        prevPrev = prev;
        prev = temp;
        temp = temp->next;

    } while (temp != head);

    if (temp->data != key) {
        printf("Value not found\n");
        return;
    }

    /* prev is the node before key */

    if (prev == head) {
        deleteBeginning();
        return;
    }

    prevPrev->next = temp;
    free(prev);
}

/* 10. Display circular list */
void display()
{
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    printf("Circular List: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

/* Count nodes */
int countNodes()
{
    struct Node *temp;
    int count = 0;

    if (head == NULL)
        return 0;

    temp = head;

    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

int main()
{
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    display();

    insertBeginning(5);
    insertAfter(10, 15);
    insertBefore(30, 25);

    display();

    printf("Number of nodes = %d\n", countNodes());

    deleteBeginning();
    deleteEnd();
    deleteValue(20);
    deleteAfter(10);
    deleteBefore(30);

    display();

    printf("Number of nodes = %d\n", countNodes());

    return 0;
}