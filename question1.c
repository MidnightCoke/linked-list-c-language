#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE
#define INITIALSIZE 10
#define SIZE 11

struct Student
{
    char Student_name[30];
    int TC;
    char address[20];
    char email[30];
    char mobile[12];
    char department[1]; /* C=Computer Engineering, E=English */
};

struct queue
{
    struct Student std[20];
    int front, rear;
};

void recursiveSetStudent(struct queue *, struct queue *, struct queue *);
void insertDepartments(struct queue *, struct queue *, struct queue *, struct Student);
void printQueue(struct queue);
int main(void)
{
    struct Student s;
    struct queue HKU;
    struct queue COMPUTER_ENG_QUEUE;
    struct queue ENGLISH_QUEUE;

    HKU.front = HKU.rear = COMPUTER_ENG_QUEUE.front = COMPUTER_ENG_QUEUE.rear = ENGLISH_QUEUE.front = ENGLISH_QUEUE.rear = -1;
    
    recursiveSetStudent(&HKU, &COMPUTER_ENG_QUEUE, &ENGLISH_QUEUE);
    printQueue(COMPUTER_ENG_QUEUE);
    printQueue(ENGLISH_QUEUE);
}

void QueueInsert(struct queue *q, struct Student s)
{
    if (q->front == 0 && q->rear == SIZE - 1 || q->front == q->rear + 1)
    {
        printf("Queue is overflow.");
        exit(1);
    }
    if (q->rear == -1)
        q->rear = q->front = 0;
    else if (q->rear == SIZE - 1)
        q->rear = 0;
    else
        q->rear++;
    q->std[q->rear] = s;
}

void recursiveSetStudent(struct queue *come, struct queue *ce, struct queue *e)
{
    struct Student givenArr[INITIALSIZE] = {
        {"Ahmet Osman", 12005310, "Gaziantep", "Ahmet@mail.com", "05531001020", "C"},
        {"Sevgi Mert", 12005311, "Konya", "Sevgi@mail.com", "05531141990", "E"},
        {"Osman Kemal", 12005312, "Istanbul", "Osman@mail.com", "05531331023", "C"},
        {"Mert Osman", 12005313, "Antalya", "Mert@mail.com", "05531041424", "C"},
        {"Ayse Omer", 12005314, "Ankara", "Ayse@mail.com", "05531087412", "E"},
        {"Kemal ali", 12005315, "Izmir", "Kemal@mail.com", "05535471028", "C"},
        {"Lale Can", 12005316, "Trabzon", "Lale@mail.com", "05534712036", "E"},
        {"Sefer Mert", 12005317, "Mardin", "Sefer@mail.com", "05531078621", "C"},
        {"Meral Jemal", 12005318, "Bursa", "Meral@mail.com", "05531003578", "E"},
        {"Demet  Kemal", 12005319, "Ankara", "Demet@mail.com", "05531841220", "E"}};

    int i;
    for (i = 0; i < INITIALSIZE; i++)
    {
        insertDepartments(come, ce, e, givenArr[i]);
    }
}

void insertDepartments(struct queue *come, struct queue *ce, struct queue *e, struct Student s)
{
    QueueInsert(come, s);

    if (come->std[come->rear].department[0] == 'C')
        QueueInsert(ce, come->std[come->rear]);
    else if (come->std[come->rear].department[0] == 'E')
        QueueInsert(e, come->std[come->rear]);
}

void printQueue(struct queue q)
{
    int i;
    if (q.std->department[0] == 'C')
    {
        printf("\n***** - COMPUTER ENGINEERING STUDENTS - *****\n");
        for (i = q.front; i <= q.rear && q.rear != -1; i++)
        {
            printf("\nSTUDENT NAME : %s\n", q.std[i].Student_name);
            printf("STUDENT ID : %d\n", q.std[i].TC);
            printf("STUDENT ADDRESS: %s\n", q.std[i].address);
            printf("STUDENT EMAIL : %s\n", q.std[i].email);
            printf("STUDENT MOBILE : %s\n", q.std[i].mobile);
            printf("STUDENT DEPRATMENT : %s\n", q.std[i].department);
        }
        printf("\n***** - COMPUTER ENGINEERING STUDENTS END - *****\n");
    }
    else if (q.std->department[0] == 'E')
    {
        printf("\n***** - ENGLISH STUDENTS - *****\n");
        for (i = q.front; i <= q.rear && q.rear != -1; i++)
        {
            printf("\nSTUDENT NAME : %s\n", q.std[i].Student_name);
            printf("STUDENT ID : %d\n", q.std[i].TC);
            printf("STUDENT ADDRESS: %s\n", q.std[i].address);
            printf("STUDENT EMAIL : %s\n", q.std[i].email);
            printf("STUDENT MOBILE : %s\n", q.std[i].mobile);
            printf("STUDENT DEPRATMENT : %s\n", q.std[i].department);
        }
        printf("\n***** - ENGLISH STUDENTS END - *****\n");
    }
}
