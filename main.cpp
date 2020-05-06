

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
void L_del(list *L, int i) { // удалить i-й элемент
    for( int j=0; j<i; j++) {
        if( (L = L->next)==NULL) return;  // ошибка
    }
    L_del1(L);
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
void menu(){
}
//------------------------------------------------------
int main()
{
    //int x,y,i;
     L_start(&L,rand()%4);
            for(int i=0;i<=10;i++){
                L_pop_front(&L, (i^10-i^19-i)%31-i^(3)-i);
            }
    L_print(&L);
    int action;
    do {
        printf("\n0: Exit\n"
               "1: Insert 3 at the begin\n"
               "2: Insert 4 at the end\n"
               "3: Insert 5 before the 3rd elem.\n"
               "4: Delete first element\n"
               "5: Delete 3rd element\n"
               "6: ....individual\n>");
        cin>>action;
        if(action==0) break;
        if(action==1) {
            L_pop_front(&L, 3);
            L_print(&L);
            continue;
        }
        if(action==2) {
            L_popE(&L, 4);
            L_print(&L);
            continue;
        }
        if(action==3) {
            L_pop(&L, 3, 5);
            L_print(&L);
            continue;
        }
        if(action==4) {
            L_del1(&L);
            L_print(&L);
            continue;
        }
        if(action==5) {
            L_del(&L, 3);
            L_print(&L);
            continue;
        }
        if(action==6) {


            L_print(&L);
            L_start(&M1,1000);
            L_start(&M2,-1000);
            Change(&L,&M1,&M2);
            L_print(&M1);
            L_print(&M2);
            continue;
        }

    } while(1);




   

return 0;
}
