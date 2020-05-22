/* Написать программу: построить список L, вставить в начало - push(список, элемент),
вывод на печать, вставка до заданного элемента, вставка после заданного элемента,
вставка в хвост,  удалить первый элемент (элемент = pop(список) ),
удалить последний элемент, удалить заданный элемент + индивидуальное задание.

2020-05-10

1.+Все списки локальные переменные функции main,
2.+Всё что вставляем в список вводим с клавиатуры,
3.+Вставка до/после заданного элемента и удаление, элемент ищем по
   полю id (запрос что вставляем и до/после чего)
   Что удалось понять - сделано!
4.+Реализованы или представлены в меню не все функции(вставить  в начало/конец;
   удалить из начала/конца; вставка до/после заданного; удалить заданный+индивидуальное)
5.+Мне очень не нравятся твои for() во всех функциях, обычно по списку идут while  до NULL
   Хорошо идём!


Уже лучше:
*+Функцию L_pop_front можно упростить, выкинуть if, разберись почему будет работать.
* L_pop, L_popA, L_del -элемент ищем по id
  (в список, после элемента с ид = 5, вставить элемент с ид = 8 и т.д.)

* L_del1 чем тебе такой вариант плох : L1=L; L=L->next; delete L1;?
* А если у тебя не только поле id, а к нему прилагается еще 100 полей, ты их все будешь копировать?
  Эта функция должна возвращать поле id в качестве результата.

* Нет функции удалить последний элемент списка.



Индивид. задание:
   По списку L построить два списка: L1 - из положительных элементов и L2 – из отрицательных.


*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct link {
    int id;
    struct link *next;
  } list;

void L_print(list *L) { // вывод на экран
    if(L==NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List:[");
    for(;;) {
        printf("%d ", L->id);
        if( L->next==NULL) break;
        L = L->next;
    }
    printf("]\n");
}

int L_find(list *L, int v) { // номер числа v в списке L, или -1
    int i = 0;
    while(L!=NULL) {
        if(L->id==v) return i;
        L = L->next;
        i++;
    }
    return -1;
}

void L_pop_front(list *&L, int v) { // вставить число v в начало списка L
    link *L1 = new link;
    L1->id = v;
    L1->next = L;
    L = L1;
}

// Прежняя версия:
void L_pop0(list *&L, int i, int v) { // вставить число v перед номером i в списке L
    if( L==NULL) {
        L = new link;
        L->id = v;
        L->next = NULL;
        return;
    }
    if(i==0) {
        L_pop_front(L, v);
        return;
    }
    link *L0=L, *L1;
    for( int j=0; j<i; j++) {
        L1 = L0;
        if( (L0 = L0->next)==NULL) break;  // дошли до конца
    }
    L_pop_front(L0, v);
    L1->next = L0;
}

void L_pop(list *&L, int v0, int v1) { // вставить число v1 перед числом v0 в списке L
    int i = L_find(L, v0);
    if( i>=0) L_pop0(L, i, v1);
}

void L_popA0(list *&L, int i, int v) { // вставить число v ПОСЛЕ номера i в списке L
    if( L==NULL) {
        L = new link;
        L->id = v;
        L->next = NULL;
        return;
    }
    link *L0=L, *L1;
    for( int j=0; j<=i; j++) {
        L1 = L0;
        if( (L0 = L0->next)==NULL) break;  // дошли до конца
    }
    L_pop_front(L0, v);
    L1->next = L0;
}
void L_popA(list *&L, int v0, int v1) { // вставить число v1 ПОСЛЕ числа v0 в списке L
    int i = L_find(L, v0);
    if( i>=0) L_popA0(L, i, v1);
}
void L_popE(list *&L, int v) { // вставить число v в хвост списка L
    if( L==NULL) {
        L = new link;
        L->id = v;
        L->next = NULL;
        return;
    }
    list *L0 = L;
    while( L0->next != NULL) L0 = L0->next;
    link *L1 = new link;
    L0->next = L1;
    L1->id = v;
    L1->next = NULL;
}
void L_del1(list *&L) { // удалить первый элемент
    link *L1 = L->next;
    L->id = L1->id;
    L->next = L1->next;
    delete L1;
}
void L_del_last(list *&L) { // удалить последний элемент
    if( L->next==NULL) {
        delete L;
        L = NULL;
        return;
    }
    link *L0 = L;
    link *L1 = L0->next;
    while(L1->next != NULL) {
        L0 = L1;
        L1 = L1->next;
    }
    L0->next = NULL;
    delete L1;
}
void L_del(list *L, int i) { // удалить i-й элемент
    for( int j=0; j<i; j++) {
        if( (L = L->next)==NULL) return;  // ошибка
    }
    L_del1(L);
}
// Индивидуальное задание: из списка L построить списки M1 и M2 из отриц. и полож. элементов
void Indi(list *L,list *&M1,list *&M2) {
    int x;
    M1 = M2 = NULL;
    while( L != NULL)
    {
        x=L->id;
        if (x>0 ) L_popE(M1,x);
        if (x<0 ) L_popE(M2,x);
        L = L->next;
    }
}
//------------------------------------------------------
int main()
{
    list *L=NULL, *M1=NULL, *M2=NULL;
    for (int i=0;i<10;i++){
        L_popE(L,rand()%10-5);
    }
    L_print(L);
    int k, r, action;
    do {
        printf("\n0: Exit\n"
               "1: Insert at the begin\n"
               "2: Insert at the end\n"
               "3: Insert before the elem.\n"
               "4: Insert after the elem.\n"
               "5: Delete first element\n"
               "6: Delete last element\n"
               "7: Delete element\n"
               "8: indiv: L-> (L+), (L-) \n>");
        cin>>action;
        if(action==0) break;
        if(action==1) {
            printf("Enter number");
            scanf("%d",&k);
            L_pop_front(L, k);
            L_print(L);
            continue;
        }
        if(action==2) {
            printf("Enter number");
            scanf("%d",&k);
            L_popE(L, k);
            L_print(L);
            continue;
        }
        if(action==3) {
            printf("Enter index");
            scanf("%d",&r);
            printf("Enter number");
            scanf("%d",&k);
            L_pop(L, r, k);
            L_print(L);
            continue;
        }
        if(action==4) {
            printf("Enter index");
            scanf("%d",&r);
            printf("Enter number");
            scanf("%d",&k);
            L_pop(L, r+1, k);
            L_print(L);
            continue;
        }
        if(action==5) {
            L_del1(L);
            L_print(L);
            continue;
        }
        if(action==6) {
            L_del_last(L);
            L_print(L);
            continue;
        }
        if(action==7) {
            printf("Enter index");
            scanf("%d",&r);
            L_del(L, r);
            L_print(L);
            continue;
        }
        if(action==8) {
            printf("L :"); L_print(L);
            Indi(L, M1, M2);
            printf(">0:"); L_print(M1);
            printf("<0:"); L_print(M2);
            continue;
        }

    } while(1);

return 0;
}
