#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
}*front,*rear,*temp,*front1;
 
int frontele();
void enqueue(int data);
void dequeue();
void display();
void create();
 
int count = 0;
 
void main()
{
    int no, ch, ele;
    printf("\n 1 - Enter Enque");
    printf("\n 2 - Enter Deque");
    printf("\n 3 -Enter  Front ele");
    printf("\n 4 - Display Queue");
    create();
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
case 1:
       printf("Enter data : ");
       scanf("%d", &no);
       enqueue(no);
       break;
case 2:
       dequeue();
       break;
 case 3:
        ele = frontele();
        if (ele != 0)
         printf("Front element : %d", ele);
         else
         printf("\n No front element in Queue ");
          break;
     
case 4:
       display();
       break;
        default:
         printf("Wrong, Please enter correct choice  ");
         break;
        }
    }
}
void create()
{
 front = rear = NULL;
}

void enqueue(int data)
{
  if (rear == NULL)
    {
     rear = (struct node *)malloc(1*sizeof(struct node));
     rear->ptr = NULL;
     rear->info = data;
     front = rear;
    }
    else
    {
    temp=(struct node *)malloc(1*sizeof(struct node));
    rear->ptr = temp;
    temp->info = data;
    temp->ptr = NULL;
    rear = temp;
    }
    count++;
}
void display()
{
    front1 = front;
 if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        printf("%d ", front1->info);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d", front1->info);
}
void dequeue()
{
    front1 = front;
 
    if (front1 == NULL)
    {
        printf("\n Error: display error:");
        return;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            printf("\n Dequed value : %d", front->info);
            free(front);
            front = front1;
        }
        else
        {
            printf("\n Dequed value : %d", front->info);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
} 
int frontele()
{
    if ((front != NULL) && (rear != NULL))
        return(front->info);
    else
        return 0;
}
 

void empty()
{
     if ((front == NULL) && (rear == NULL))
        printf("\n Queue empty");
    else
       printf("Queue not empty");
}
