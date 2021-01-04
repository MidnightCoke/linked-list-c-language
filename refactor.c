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

struct node
{
    struct student data; //Student details
    struct node *next;   //Next node
};
typedef struct student std;
typedef struct node *NODEPTR;

int main()
{
}