/* �������� ���������: ��������� ������ L, �������� � ������ - push(������, �������),
����� �� ������, ������� �� ��������� ��������, ������� ����� ��������� ��������,
������� � �����,  ������� ������ ������� (������� = pop(������) ),
������� ��������� �������, ������� �������� ������� + �������������� �������.



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

void L_print(list *L) { // ����� �� �����
    printf("List:[");
    for(;;) {
        printf("%d ", L->id);
        if( L->next==NULL) break;
        L = L->next;
    }
    printf("]\n");
}
void L_start(list *L, int v) { // L:=������ �� ������ �������� v
    L->id = v;
    L->next = NULL;
}
void L_pop_front(list *L, int v) { // �������� ����� v � ������ ������ L
    link *L1 = new link;
    L1->id = L->id;
    L1->next = L->next;
    L->id = v;
    L->next = L1;
}
void L_pop(list *L, int i, int v) { // �������� ����� v ����� ������� i � ������ L
    for( int j=0; j<i; j++) {
        if( (L = L->next)==NULL) return;  // ������
    }
    L_pop_front(L, v);
}
void L_popA(list *L, int i, int v) { // �������� ����� v ����� ������ i � ������ L
    for( int j=0; j<=i; j++) {
        if( (L = L->next)==NULL) return;  // ������
    }
    L_pop_front(L, v);
}
void L_popE(list *L, int v) { // �������� ����� v � ����� ������ L
    while( L->next != NULL) L = L->next;
    link *L1 = new link;
    L->next = L1;
    L1->id = v;
    L1->next = NULL;
}
void L_del1(list *L) { // ������� ������ �������
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
