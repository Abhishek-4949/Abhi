/*
Develop a menu driven Program in C for the following operations on Doubly Linked List 
(DLL) of Employee Data with the fields: SSN, Name, Dept, Designation, 
Sal, PhNo 
a. Create a DLL of N Employees Data by using end insertion.
b. Display the status of DLL and count the number of nodes in it
c. Perform Insertion and Deletion at End of DLL
d. Perform Insertion and Deletion at Front of DLL
e. Demonstrate how this DLL can be used as Double Ended Queue.
f. Exit
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int usn;
    char name[30], dept[4], desig[30], ph[11];
    int sal;
    struct node *plink;
    struct node *nlink;
};
typedef struct node* NODE;

NODE getn(void);
void freen(NODE);
NODE insrear(NODE);
NODE delfront(NODE);
NODE insfront(NODE);
NODE delrear(NODE);
void disp(NODE);

int main()
{
    NODE first = NULL;
    int ch, num, i;
    printf("\nEnter the number of Employees N : "); scanf("%d", &num);
    for(i=0;i<num;i++)
    {
        printf("Enter Data for Node %d :", i+1);
        first = insrear(first);
    }
    for(;;)
    {
        printf("\nDLL OPERATIONS");
        printf("====================");
        printf("\n1.Insert Rear\n2.Delete Front\n3.Insert Front\n4.Delete Rear\n5.Display\n6.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: first = insrear(first);
            break;
            case 2: first = delfront(first);
            break;
            case 3: first = insfront(first);
            break;
            case 4: first = delrear(first);
            break;
            case 5: disp(first);
            break;
            case 6: exit(0);
        }
    }
    return 0;
}
NODE getn()
{
    NODE newborn;
    newborn = (NODE)malloc(sizeof(struct node));
    if(newborn == NULL)
    {
        printf("\nMemory Overflow");
        exit(0);
    }
    printf("\nEnter SSN : ");
    scanf("%d",&newborn->usn);
    printf("Enter name : ");
    scanf("%s",newborn->name);
    printf("Enter Department : ");
    scanf("%s", newborn->dept);
    printf("Enter Designation : ");
    scanf("%s", newborn->desig);
    printf("Enter Salary : ");
    scanf("%d",&newborn->sal);
    printf("Enter Phone no : ");
    scanf("%s",newborn->ph);
    return newborn;
}
void freen(NODE x)
{
    free(x);
}
NODE insrear(NODE first)
{
    NODE temp,cur;
    temp = getn();
    temp->plink = temp->nlink = NULL;
    if(first == NULL)
        return temp;
    cur = first;
    while(cur->nlink != NULL)
    {
        cur = cur->nlink;
    }
    cur->nlink = temp;
    temp->plink = cur;
    return first;
}
NODE insfront(NODE first)
{
    NODE temp;
    temp = getn();
    temp->plink = temp->nlink = NULL;
    temp->nlink = first;
    first = temp;
    return first;
}
NODE delrear(NODE first)
{
    NODE cur, prev;
    if(first == NULL)
    {
        printf("DLL is empty");
        return first;
    }
    cur = first;
    if(cur->nlink == NULL)
    {
        printf("Node deleted for %s : ",cur->name);
        freen(cur);
        return NULL;
    }
    while(cur->nlink != NULL)
    {
        cur = cur->nlink;
    }
    prev = cur->plink;
    prev->nlink = NULL;
    printf("Node deleted for %s : ",cur->name);
    freen(cur);
    return first;
}
NODE delfront(NODE first)
{
    NODE temp;
    if(first == NULL)
    {
        printf("DLL is empty");
        return first;
    }
    if(first->nlink == NULL)
    {
        printf("Node deleted for %s : ",first->name);
        freen(first);
        return NULL;
    }
    temp = first;
    first = first->nlink;
    first->plink = NULL;
    printf("Node deleted for %s : ",temp->name);
    freen(temp);
    return first;
}
void disp(NODE first)
{
    NODE curr;
    int count = 0;
    if(first == NULL)
    {
        printf("DLL is empty");
        return;
    }
    printf("The contents of DLL are : ");
    curr = first;
    printf("\nSSN\tName\tDept\tDesignation\tSalary\t\tPhone No");
    while(curr != NULL)
    {
        printf("\n%-5d\t%s\t%s\t%s\t\t%-7d\t\t%-11s",curr->usn, curr->name, curr->dept, curr->desig, 
        curr->sal, curr->ph);
        curr = curr->nlink;
        count++;
    }
    printf("DLL has %d nodes : ", count);
}