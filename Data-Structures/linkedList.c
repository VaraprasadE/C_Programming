#include <stdio.h>
#include <stdlib.h>
 
struct Cup
{
    int number;
    struct Cup *next;
};
 
// Create cups
struct Cup* createCups(int count)
{
    struct Cup *head = NULL;
    struct Cup *temp = NULL;
 
    for (int i = 1; i <= count; i++)
    {
        struct Cup *newCup = malloc(sizeof(struct Cup));
 
        newCup->number = i;
        newCup->next = NULL;
 
        if (head == NULL)
        {
            head = newCup;
        }
        else
        {
            temp->next = newCup;
        }
 
        temp = newCup;
    }
 
    return head;
}
 
// Display cups
void displayCups(struct Cup *head)
{
    struct Cup *temp = head;
 
    while (temp != NULL)
    {
        printf("Cup %d  ", temp->number);
        temp = temp->next;
    }
 
    printf("NULL\n");
}
 
// Delete particular cup
struct Cup* deleteCup(struct Cup *head, int number)
{
    struct Cup *temp = head;
 
    // Delete first cup
    if (head != NULL && head->number == number)
    {
        head = head->next;
        free(temp);
        return head;
    }
 
    // Find the cup
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->next->number == number)
        {
            struct Cup *deleteNode = temp->next;
            temp->next = deleteNode->next;
            free(deleteNode);
            return head;
        }
 
        temp = temp->next;
    }
 
    printf("Cup %d not found!\n", number);
 
    return head;
}
 
int main()
{
    struct Cup *head;
    int count;
    int deleteNumber;
    for(;;){
        // Ask how many cups
        printf("How many cups do you want? ");
        scanf("%d", &count);
        // Create cups
        head = createCups(count);
        printf("\nCups are:\n");
        displayCups(head);
        // Ask which cup to delete
        printf("\nWhich cup do you want to delete? ");
        scanf("%d", &deleteNumber);
        // Delete cup
        head = deleteCup(head, deleteNumber);
        printf("\nAfter deletion:\n");
        displayCups(head);

    }
    return 0;
}
