#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

/* Create a new node */
struct Node* createNode(int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

/* 1. Insert at beginning */
void insertBeginning(int value)
{
    struct Node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

/* 2. Insert at end */
void insertEnd(int value)
{
    struct Node *newNode = createNode(value);
    struct Node *temp;

    if (head == NULL) {
        head = newNode;
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

/* 3. Insert after a given value */
void insertAfter(int key, int value)
{
    struct Node *temp = head;
    struct Node *newNode;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    newNode = createNode(value);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

/* 4. Insert before a given value */
void insertBefore(int key, int value)
{
    struct Node *temp = head;
    struct Node *newNode;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    newNode = createNode(value);

    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newNode;
    else
        head = newNode;

    temp->prev = newNode;
}

/* 5. Delete beginning */
void deleteBeginning()
{
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

/* 6. Delete end */
void deleteEnd()
{
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
}

/* 7. Delete node containing given value */
void deleteValue(int key)
{
    struct Node *temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

/* 8. Delete node after given value */
void deleteAfter(int key)
{
    struct Node *temp = head;
    struct Node *del;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("No node exists after %d\n", key);
        return;
    }

    del = temp->next;

    temp->next = del->next;

    if (del->next != NULL)
        del->next->prev = temp;

    free(del);
}

/* 9. Delete node before given value */
void deleteBefore(int key)
{
    struct Node *temp = head;
    struct Node *del;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL || temp->prev == NULL) {
        printf("No node exists before %d\n", key);
        return;
    }

    del = temp->prev;

    if (del->prev != NULL)
        del->prev->next = temp;
    else
        head = temp;

    temp->prev = del->prev;

    free(del);
}

/* 10. Forward traversal */
void displayForward()
{
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Forward: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

/* Reverse traversal */
void displayReverse()
{
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Reverse: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    printf("\n");
}

int main()
{
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    displayForward();
    displayReverse();

    insertBeginning(5);
    insertAfter(20, 25);
    insertBefore(30, 27);

    displayForward();
    displayReverse();

    deleteBeginning();
    deleteEnd();
    deleteValue(20);
    deleteAfter(10);
    deleteBefore(30);

    displayForward();
    displayReverse();

    return 0;
}