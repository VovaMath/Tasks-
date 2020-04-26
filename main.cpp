/* Написать программу: построить список L, вставить в начало - push(список, элемент),
вывод на печать, вставка до заданного элемента, вставка после заданного элемента,
вставка в хвост,  удалить первый элемент (элемент = pop(список) ),
удалить последний элемент, удалить заданный элемент + индивидуальное задание.



*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct link {
    int id;
    struct link *next;
  } list;
list L;
list M1;
list M2;

void L_print(list *L) { // вывод на экран
    printf("List:[");
    for(;;) {
        printf("%d ", L->id);
        if( L->next==NULL) break;
        L = L->next;
    }
    printf("]\n");
}
void L_start(list *L, int v) { // L:=список из одного элемента v
    L->id = v;
    L->next = NULL;
}
void L_pop_front(list *L, int v) { // вставить число v в начало списка L
    link *L1 = new link;
    L1->id = L->id;
    L1->next = L->next;
    L->id = v;
    L->next = L1;
}
void L_pop(list *L, int i, int v) { // вставить число v перед номером i в списке L
    for( int j=0; j<i; j++) {
        if( (L = L->next)==NULL) return;  // ошибка
    }
    L_pop_front(L, v);
}
void L_popA(list *L, int i, int v) { // вставить число v ПОСЛЕ номера i в списке L
    for( int j=0; j<=i; j++) {
        if( (L = L->next)==NULL) return;  // ошибка
    }
    L_pop_front(L, v);
}
void L_popE(list *L, int v) { // вставить число v в хвост списка L
    while( L->next != NULL) L = L->next;
    link *L1 = new link;
    L->next = L1;
    L1->id = v;
    L1->next = NULL;
}
void L_del1(list *L) { // удалить первый элемент
    link *L1 = L->next;
    L->id = L1->id;
    L->next = L1->next;
    delete L1;
}
void Change(list *L,list *M1,list *M2) {
    int x;
    while( L->next != NULL)
    {
        x=L->id;
        if (x>0 )
    {
        L_popE(M1,x);
    }
    if ((x )<0 )
    {
        L_popE(M2,x);
    }
        L = L->next;
    }

    L_del1(M1);
    L_del1(M2);

}
int main()
{
L_start(&L,rand()%4);
for(int i=0;i<=20;i++)
{
L_pop_front(&L, (i^10-i^19-i)%31-i^(3)-i);
}

L_print(&L);
L_start(&M1,1000);
L_start(&M2,-1000);
Change(&L,&M1,&M2);
L_print(&M1);
L_print(&M2);
return 0;
}
