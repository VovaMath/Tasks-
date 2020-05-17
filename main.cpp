/* �������� ���������: ��������� ������ L, �������� � ������ - push(������, �������),
����� �� ������, ������� �� ��������� ��������, ������� ����� ��������� ��������,
������� � �����,  ������� ������ ������� (������� = pop(������) ),
������� ��������� �������, ������� �������� ������� + �������������� �������.

2020-05-10

1.+��� ������ ��������� ���������� ������� main,
2.+�� ��� ��������� � ������ ������ � ����������,
3.+������� ��/����� ��������� �������� � ��������, ������� ���� ��
   ���� id (������ ��� ��������� � ��/����� ����)
   ��� ������� ������ - �������!
4.+����������� ��� ������������ � ���� �� ��� �������(��������  � ������/�����;
   ������� �� ������/�����; ������� ��/����� ���������; ������� ��������+��������������)
5.+��� ����� �� �������� ���� for() �� ���� ��������, ������ �� ������ ���� while  �� NULL
   ������ ���!

�������. �������:
   �� ������ L ��������� ��� ������: L1 - �� ������������� ��������� � L2 � �� �������������.


*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct link {
    int id;
    struct link *next;
  } list;

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
void L_del(list *L, int i) { // ������� i-� �������
    for( int j=0; j<i; j++) {
        if( (L = L->next)==NULL) return;  // ������
    }
    L_del1(L);
}
// �������������� �������: �� ������ L ��������� ������ M1 � M2 �� �����. � �����. ���������
void Indi(list *L,list *M1,list *M2) {
    int x;
    bool fM1=true, fM2=true;    // ������ ������?
    while( L->next != NULL)
    {
        x=L->id;
        if (x>0 )
        {
            if( fM1) {
                L_start(M1, x);
                fM1=false;
            } else
            L_popE(M1,x);
        }
        if ((x )<0 )
        {
            if( fM2) {
                L_start(M2,x);
                fM2 = false;
            } else
            L_popE(M2,x);
        }
        L = L->next;
    }
}
//------------------------------------------------------
int main()
{
    list L, M1, M2;
    int k, r;
    /*
    L_start(&L, 11);
    L_popE(&L, -22);
    L_popE(&L, 33);
    L_popE(&L, 44);
    L_popE(&L, -55);
    L_popE(&L, 66);
    */


    bool first = true;
    do {
        printf("Value (0 - break):");
        int r = scanf("%d", &k);
        //printf("r=%d, k=%d\n", r, k);
        if(r !=1) break;
        if(first) {
            L_start(&L, k);
            first = false;
        } else {
            L_popE(&L, k);
        }
    } while(k != 0);

    L_print(&L);
    int action;
    do {
        printf("\n0: Exit\n"
               "1: Insert at the begin\n"
               "2: Insert at the end\n"
               "3: Insert before the elem.\n"
               "4: Insert after the elem.\n"
               "5: Delete first element\n"
               "6: Delete element\n"
               "7: indiv: L-> (L+), (L-) \n>");
        cin>>action;
        if(action==0) break;
        if(action==1) {
            printf("Enter number");
            scanf("%d",&k);
            L_pop_front(&L, k);
            L_print(&L);
            continue;
        }
        if(action==2) {
            printf("Enter number");
            scanf("%d",&k);
            L_popE(&L, k);
            L_print(&L);
            continue;
        }
        if(action==3) {
            printf("Enter index");
            scanf("%d",&r);
            printf("Enter number");
            scanf("%d",&k);
            L_pop(&L, r, k);
            L_print(&L);
            continue;
        }
        if(action==4) {
            printf("Enter index");
            scanf("%d",&r);
            printf("Enter number");
            scanf("%d",&k);
            L_pop(&L, r+1, k);
            L_print(&L);
            continue;
        }
        if(action==5) {
            L_del1(&L);
            L_print(&L);
            continue;
        }
        if(action==6) {
            printf("Enter index");
            scanf("%d",&r);
            L_del(&L, r);
            L_print(&L);
            continue;
        }
        if(action==7) {
            printf("L :"); L_print(&L);
            Indi(&L, &M1, &M2);
            printf(">0:"); L_print(&M1);
            printf("<0:"); L_print(&M2);
            continue;
        }

    } while(1);


return 0;
}
