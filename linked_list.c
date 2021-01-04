#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct student
{
    char stdName[30];
    int TC;
    char stdAddress[20];
    char stdEmail[30];
    char stdMobile[12];
    char stdDepartment[2]; /* CE=Computer Engineering, E=English */
};

struct student givenArr[SIZE] = {
    {"Ahmet Osman", 12005310, "Gaziantep", "Ahmet@mail.com", "05531001020", "CE"},
    {"Sevgi Mert", 12005311, "Konya", "Sevgi@mail.com", "05531141990", "E"},
    {"Osman Kemal", 12005312, "Istanbul", "Osman@mail.com", "05531331023", "CE"},
    {"Mert Osman", 12005323, "Antalya", "Mert@mail.com", "05531041424", "CE"},
    {"Ayse Omer", 12005314, "Ankara", "Ayse@mail.com", "05531087412", "E"},
    {"Kemal ali", 12005315, "Izmir", "Kemal@mail.com", "05535471028", "CE"},
    {"Lale Can", 12005316, "Trabzon", "Lale@mail.com", "05534712036", "E"},
    {"Sefer Mert", 12005317, "Mardin", "Sefer@mail.com", "05531078621", "CE"},
    {"Meral Jemal", 12005348, "Bursa", "Meral@mail.com", "05531003578", "E"},
    {"Demet  Kemal", 12005339, "Ankara", "Demet@mail.com", "05531841220", "E"},
};


struct node{
	struct student data; //Student details
	struct node *next; //Next node
};
typedef struct student std;
typedef struct node *NODEPTR;

NODEPTR getnode()
{
	NODEPTR q = (NODEPTR) malloc(sizeof(struct node));
	return(q);
}

NODEPTR list1,list2;

void freenode(NODEPTR p){
	free(p);
};

//Order datas by TC and then create list1
void orderTc(NODEPTR *head,std *data);

//Order datas by Name and then create list2
void orderName(NODEPTR *head,std *data);

//print to screen
void printtoscreen(NODEPTR *head);


//Add new student to head of list
void AddtoB(NODEPTR *head,std *data);

//Add new student to second node of a list
void AddtoS(NODEPTR *head,std *data);

//Delete first student from  list
void DeleteFirst(NODEPTR *head);

//Delete nth student from  list
void DeleteNth(NODEPTR *head, int x);
void concate(NODEPTR *list1,NODEPTR *list2);
void BeforeNth(NODEPTR *head,std *data, int x);
//Create new student data
void newStd(std *data);

void freeAll(NODEPTR *head);
int main() {
	int i = -1;

	list1 = getnode(), list2 = getnode();
	list1->next = NULL;
	list2->next = NULL;
	
	int operand;
	while(i != 1){
		
		printf("\n[1] - Create a list of student information, sorted by student TC.");
		printf("\n[2] - Create a list of student information, sorted by student Name.");
		printf("\n[3] - Append a new student to begging of any list.");
		printf("\n[4] - Append a new student to of any list as second item.");
		printf("\n[5] - Delete the first student from any list.");
		printf("\n[6] - Delete the nth student from any list.");
		printf("\n[7] - Create a list of student information, sorted by student TC.");
		printf("\n[8] - Create a list of student information, sorted by student TC.");
		printf("\n[9] - Create a list of student information, sorted by student TC.");
		printf("\n[10] - Create a list of student information, sorted by student TC.");
		
		scanf("%d", &operand);

		switch(operand){
			case 1:
				orderTc(&list1,givenArr);
				break;
			case 2:
				orderName(&list2,givenArr);
				break;
			case 3:
				loop:
					
				printf("Which list do you want to add to?\n[1] - List with ordered TC.\n[2] - List with ordered TC.\n");
				scanf("%d",&operand);
				
				if(operand == 1 || operand == 2){
					
					//Create new temp array
					struct student newArr[1];
					//Get new student informations from user
					newStd(newArr);
					
					//List 1 or 2
					(operand == 1) ? AddtoB(&list1,newArr) : AddtoB(&list2,newArr);
					
				}
				else{
					goto loop;
				}
				
				break;
			case 4:
				loop1:
					
				printf("Which list do you want to add to?\n[1] - List with ordered TC.\n[2] - List with ordered TC.\n");
				scanf("%d",&operand);
				
				if(operand == 1 || operand == 2){
					
					//Create new temp array
					struct student newArr[1];
					//Get new student informations from user
					newStd(newArr);
					
					//List 1 or 2
					(operand == 1) ? AddtoS(&list1,newArr) : AddtoS(&list2,newArr);
					
				}
				else{
					goto loop1;
				}
				break;
			case 5:
				loop2:
					
				printf("In which list should the first student be deleted??\n[1] - List with ordered TC.\n[2] - List with ordered TC.\n");
				scanf("%d",&operand);
				
				if(operand == 1 || operand == 2){
					//List 1 or 2
					(operand == 1) ? DeleteFirst(&list1) : DeleteFirst(&list2);
				}
				else{
					goto loop2;
				}
				break;
			case 6:
				DeleteNth(&list1, 1);
				break;
			case 7:
				{
				struct student newArr[1];
				newStd(newArr);
				
				BeforeNth(&list1,newArr,12);
				break;	
				}

			case 8:
				freeAll(&list1);
				break;
			case 9:
				concate(&list1,&list2);
				break;
			case 10:
				printtoscreen(&list1);
				break;
		}
	}

};

//Sorting data list with stdTC
void orderTc(NODEPTR *head,std *data){
	NODEPTR p,q;
	p = *head;
	
	int i,j;
	
	for(i = 0;i < SIZE;i++){
		
		//Sorting by TC
		for(j = 0; j < SIZE - i - 1; j++){
			
			if(data[j].TC > data[j+1].TC){
				struct student temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
			
		}
		
		//linked list
		p->data = data[i];
		q = getnode();
		
		p->next = q;
		q->next = NULL;
		p = q;
		
	}
	
	list1 = *head;
	
}

//Sorting data list with stdNames
void orderName(NODEPTR *head,std *data){
	NODEPTR p,q;
	p = *head;
	int i,j;
	
	for(i = 0;i < SIZE;i++){
		
		//Sorting by TC
		for(j = 0; j < SIZE - i - 1; j++){
			
			if( strcmp(data[j].stdName,data[j+1].stdName) > 0 ){
				struct student temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
			
		}
		
		//linked list
		p->data = data[i];
		q = getnode();
		
		p->next = q;
		q->next = NULL;
		p = q;
		
	}
}

void newStd(std *data){
	printf("Enter student Name: ");
	scanf("\n%s",data->stdName);
	
	printf("Enter student TC: ");
	scanf("\n%d",data->TC);
	
	printf("Enter student Address: ");
	scanf("\n%s",data->stdAddress);
	
	printf("Enter student Mobile: ");
	scanf("\n%s",data->stdMobile);
	
	printf("Enter student Department: ");
	scanf("\n%s",data->stdDepartment);
	
}

void AddtoB(NODEPTR *head,std *data){
	NODEPTR p,q;
	p = *head;
	
	if(p->next == NULL){
		printf("List is empty, run 1 or 2 first.");
		return;
	}
	
	q = getnode();
	q->data = *data;
	q->next = p;
	*head = q;	
	
	printf("%s, added to as 1. element of list.",data[0].stdName);
}

void AddtoS(NODEPTR *head,std *data){
	
	NODEPTR p,q;
	p = *head;
	
	if(p->next == NULL){
		printf("List is empty, run 1 or 2 first.");
		return;
	}
	
	
	q = getnode();
	q->next = p->next;
	p->next = q;
	q->data = *data;
	
	printf("%s, added to as 2. element of list.",data[0].stdName);
}

void DeleteFirst(NODEPTR *head){
	NODEPTR p,q;
	p = *head;
	
	if(p->next == NULL){
		printf("List is empty, run 1 or 2 first.");
		return;
	}
	
	q = p->next;
	*head = q;
	freenode(p);
}

void DeleteNth(NODEPTR *head, int x){
	
	//Delete first one
	if(x == 1){
		DeleteFirst(head);
		return;
	}
	
	NODEPTR p,q,save;
	save = *head;
	int i;
	for(p = *head,i = 0;p->next != NULL && i <= x;i++,p = p->next){
		if(i == x-1){
			q = p->next;
			save->next = q;
			freenode(p);
			return;
		}
		
		save = p;
	}
	
	printf("Cant delete %d. element",x);
	
}

void BeforeNth(NODEPTR *head,std *data, int x){
	NODEPTR p,q,save;
	if( x == 0) return;
	
	if( x == 1) AddtoS(head,data);
	
	save = *head;
	
	int i;
	
	for(p = *head,i=0;p != NULL && i < x;i++,p = p->next){
		if(i == x-1){
			q = getnode();
			save->next = q;
			q->next = p;
			q->data = *data;
			return;
		}
		save = p;
	}

}

void freeAll(NODEPTR *head){
	NODEPTR p,q;
	p = *head;
	int i ;
	while(p != NULL){
		q = getnode();
		q = p;
		p = p->next;
		free(q);
	}
		
}

void concate(NODEPTR *list1,NODEPTR *list2){
	
	NODEPTR p,q;
	p = *list1;
	q = *list2;
	do{
		if(p->next == NULL){
			p->next = q;
			return;
		}
		else{
			p = p->next;
		}
		
	}while(1 == 1);
	
}
void printtoscreen(NODEPTR *head){
	NODEPTR p;
	for(p = *head;p->next != NULL;p = p->next)
		printf("%s\n",p->data.stdName);
}