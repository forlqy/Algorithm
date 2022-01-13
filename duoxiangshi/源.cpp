#pragma warning(disable:4996)
#include<iostream>
#include <cstdio> 
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>

using namespace std;

typedef struct polynomial
{
    int coefficient;//ϵ��
    int exp;//ָ��
    struct polynomial* next;
}*Link, Node;

void inputPoly(Link head);//���ڴӿ���̨��������ĺ���
void print(Link head);//��ӡ�����õĺ���
bool insert(Link head, int coefficient, int exp);//���������һ��Ԫ�صĺ���
void AddList(Link heada, Link headb, Link headab);//�����������
void MultiplyList(Link heada, Link headb, Link headab);

int main()
{
    Link headA, headB;//��������ʽ��ͷָ��
    Link headAB;//�ϲ���Ķ���ʽ��ͷָ��

    /*����ĳ�ʼ��*/
    headA = (Link)malloc(sizeof(Node));
    headA->next = NULL;
    headB = (Link)malloc(sizeof(Node));
    headB->next = NULL;
    headAB = (Link)malloc(sizeof(Node));
    headAB->next = NULL;
     
    cout << "�������һ������ʽ��ϵ����ָ������(0 0)������" << endl;
    inputPoly(headA);
    cout << "��һ��";
    print(headA);
    cout << "������ڶ�������ʽ��ϵ����ָ������(0 0)������" << endl;
    inputPoly(headB);
    cout << "�ڶ���";
    print(headB);
    MultiplyList(headA, headB, headAB);
    cout << "�ϲ���";
    print(headAB);
    free(headA);
    free(headB);
    free(headAB);
    return 0;
}

/**�������ʽ���ݵĺ���*/
/*������������������ʽ�����û����ʵ���ʾ�������û������ϵ����ָ����
���ú���insert�����û�����Ķ���ʽ��һ����뵽������ȥ��*/
void inputPoly(Link head)
{
    int coefficient, exp;//ϵ����ָ��
    cout << "������ϵ����ָ��(�磺\"2 3\"��ʾ2x^3)��";
    cin >> coefficient >> exp;
    while (coefficient != 0 || exp != 0)//����������ϵ����ָ��
    {
        insert(head, coefficient, exp);//�������������ʽ
        cout << "������ϵ����ָ����";
        cin >> coefficient >> exp;
    }
}

/**�����ʽ�����в���Ԫ�صĺ���
int coefficient һ������ʽ���ϵ��
int exp һ������ʽ�����
*/


/**
��ӡ����ʽ����ĺ���
*/
/*
�١�ͨ��ָ���������
�ڡ������������Ƕ��
�ۡ�����ת��Ϊ�ַ�������itoa
�ܡ���־�Ƿ�Ϊ��һ���ڵ��flag������
�ݡ��ַ������Ӻ���strcat
�ޡ��ַ�����պ���memset��memset(item,0,20);��ճ�20���ַ���item
�벹�����ʵ�֡�
*/
void print(Link head)
{
    Link p; //ָ������Ҫ����Ľ��
    //p = (Link)malloc(sizeof(Node));
    printf("����ʽ���£�\n");
    p = head;

    if (p == NULL)
    {
        printf("����ʽΪ��\n");
        return;
    }
    // ���ǿձ�
    char item[20] = "";//Ҫ��ӡ�ĵ�ǰ����ʽ��һ��
    char number[7] = "";//��ʱ���ϵ��ת���ɵ��ַ���

    bool isFirstItem = true;//��־�Ƿ�Ϊ��һ���ڵ��flag
    //��ӡ�ڵ�
    do {
        memset(item, 0, 20);//����ַ���item
        //����ǵ�һ���Ҫ��+��
        //������ǵ�һ���ϵ��Ϊ������Ҫ��Ӻ�
        if (isFirstItem == true) {
            if (p->coefficient == 1) {
                strcat(item, "X^");
                sprintf(number, "%d", p->exp);
                strcat(item, number);
            }
            else if ((p->coefficient != 0) && (p->coefficient != -1)) {

                sprintf(number, "%d", p->coefficient);
                strcat(item, number);
                sprintf(number, "%d", p->exp);


                strcat(item, "X^");
                strcat(item, number);
            }
            else {
                strcat(item, "-X^");
                sprintf(number, "%d", p->exp);
                strcat(item, number);
            }
        }
        else {
            if (p->exp != 0) {
                if (p->coefficient == 1) {
                    strcat(item, "+X^");
                    sprintf(number, "%d", p->exp);
                    strcat(item, number);
                }
                else if ((p->coefficient != 0) && (p->coefficient != -1)) {
                    sprintf(number, "%d", p->coefficient);
                    strcat(item, "+");
                    strcat(item, number);
                    sprintf(number, "%d", p->exp);

                    strcat(item, "X^");
                    strcat(item, number);
                }
                else {
                    strcat(item, "-X^");
                    sprintf(number, "%d", p->exp);
                    strcat(item, number);
                }
            }
            else {
                sprintf(number, "%d", p->coefficient);
                strcat(item, "+");
                strcat(item, number);
            }

        }


        //���ϵ��Ϊ������ϵ��������з���

        //���ϵ��Ϊ1�����ô�ϵ��
        //ϵ��Ϊ-1��ӡ����

        //���ϵ����Ϊ1��-1����ӡϵ��


        //���ָ��Ϊ0��ֱ�Ӵ�ϵ�����ô�x^��ָ��
        //���ϵ����-1��1����Ҫ��1����������ֻ�����

        //ָ����Ϊ0
        //��ӡx
        //���ָ��Ϊ1������ָ���������ָ��

        printf("%s", item);//��ӡ��ǰ�ڵ�������
        p = p->next;//ָ���¸����
        isFirstItem = false;//flag��־���ǵ�һ����
    } while (p != NULL);
    printf("\n");
    
}

/**
�ϲ�������������a��b������ab
heada.headb,headab�ֱ�Ϊ����a,b,ab��ͷָ��
*/
void AddList(Link heada, Link headb, Link headab)
{
    Link pa, pb, p;//ָ��a��b�����ab��ָ��
    pa = heada->next;
    pb = headb->next;
    p = headab;

    while (pa != NULL && pb != NULL)//a,b����û��û�з������
    {
        //���ָ��a>ָ��b��a�ڵ����ab����aָ�����
        //���ָ��a<ָ��b��b�ڵ����ab����bָ�����
        //���ָ��a==ָ��b��a��bϵ����ӣ�����ab����a��bָ�����
        if (pa->exp > pb->exp) {
            p->next = pa;
            pa = pa->next;
            p = p->next;
        }
        else if (pa->exp < pb->exp) {
            p->next = pb;
            pb = pb->next;
            p = p->next;
        }
        else {
            pa->coefficient = pa->coefficient + pb->coefficient;
            p->next = pa;
            pa = pa->next;
            pb = pb->next;
            p = p->next;
        }

    }
    //���a��b������β�ͣ������ӵ�ab�������
    while (pa != NULL)
    {
        p->next = pa;
    }
    while (pb != NULL)
    {
        p->next = pb;
    }

}

void Attach(int c, int e, Link* pRear)//*pRear��ָ���ָ�� 
{
    Link P;
    P = (Link)malloc(sizeof(Node));
    P->coefficient = c;//���½�㸳ֵ 
    P->exp = e;
    P->next = NULL;
    (*pRear)->next = P;
    *pRear = P;//�޸�pRear��ֵ 
}

void MultiplyList(Link heada, Link headb, Link headab)
{
    Link pa, pb, t, rear;
    //pa = heada->next;
    //pb = headb->next;
   // p = headab->next;

    int c, e;
    if (!heada || !headb) return;
    pa = heada; pb = headb;
    headab->next = NULL;
    rear = headab;

    while (pb) {//����P1�ĵ�һ�����P2���õ�P 
        Attach(pa->coefficient * pb->coefficient, pa->exp + pb->exp, &rear);
        pb = pb->next;
    }
    pa = pa->next;
    while (pa) {
        pb = headb; rear = headab;
        while (pb) {
            e = pa->exp + pb->exp;
            c = pa->coefficient * pb->coefficient;
            while (rear->next && rear->next->exp > e)
                rear = rear->next;
            if (rear->next && rear->next->exp == e) {
                if (rear->next->coefficient + c)
                    rear->next->coefficient += c;
                else {
                    t = rear->next;
                    rear->next = t->next;
                    free(t);
                }
            }
            else {
                t = (Link)malloc(sizeof(Node));
                t->coefficient = c; t->exp = e;
                t->next = rear->next;
                rear->next = t; rear = rear->next;
            }
            pb = pb->next;
        }
        pa = pa->next;
    }
    pb = headab; headab = headab->next; free(pb);
}


bool insert(Link head, int coefficient, int exp)
{
    Link node;  //nodeָ��ָ���´����Ľڵ�
    Link q, p;   //q,p�����ڵ�һǰһ��
    q = head;
    p = head->next;

    //����һ���½��
    node = (Link)malloc(sizeof(Node));
    node->next = NULL;
    node->coefficient = coefficient;
    node->exp = exp;

    if (head->next == NULL)//�ձ�,���1��
    {
        head->next = node;
    }
    else
    {
        while (p != NULL) { //ѭ�����������е����нڵ�

            //���node�ڵ��ָ����p�ڵ��ָ���������p��ǰ�棬��ɲ������ǰ�˳�
            //���node�ڵ��ָ����p�ڵ��ָ����ȣ���ϲ��������ʽ�ڵ㣬��ǰ�˳�
            //���node�ڵ��ָ����p�ڵ��ָ��С����������ƶ�ָ�루��Ȼ����p��qһǰһ��
            if (node->exp > p->exp) {
                q->next = node;
                node->next = p;
                return true;
            }
            else if (node->exp == p->exp) {
                p->coefficient = p->coefficient + node->coefficient;
                return true;
            }
            else {
                q = p;
                p = p->next;
            }
        }
        //����˳�ѭ���ǵ�ǰָ��p�ƶ��������β����˵��֮ǰû�в��룬��ô��ǰnode�ڵ��ָ��ֵ�����ֵ����ʱ��������������
        q->next = node;
    }
    //free(node);
    return true;
}