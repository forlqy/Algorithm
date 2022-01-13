#pragma warning(disable:4996)

#include<iostream>
using namespace std;

typedef struct polynomial
{
    int coeficient;//ϵ��
    int exp;//ָ��
    struct polynomial* next;
}*Link, Node;

void inputPoly(Link head);//���ڴӿ���̨��������ĺ���
void print(Link head);//��ӡ�����õĺ���
bool insert(Link head, double coeficient, int exp);//���������һ��Ԫ�صĺ���
void AddList(Link heada, Link headb, Link headab);//�����������
void SubtractList(Link heada, Link headb, Link headab);
void MultiplyList(Link heada, Link headb, Link headab);
void DivisionList(Link heada, Link headb, Link headab);
void Division(Link heada, Link headb, Link headab);

/*
//����
Link Dele(Link f)
{
    Link pa,s;
    pa=f->next;
    s=f;
    while(pa)
    {
        if(!pa->coeficient)
        {
            s->next=pa->next;
        }
        else
            s=pa;
        pa=pa->next;
    }
    return f;
}
Link Completion(Link f,int m)
{
    Link pa,s,w;
    int d,e;
    pa=f->next;
    s=f;
    while(pa)
    {
        if(m>1)
        {
            if(pa->next){
                s=pa;
                pa=pa->next;
                d=s->exp-1-pa->exp;
                for(int j=0;j<d;j++)
                {
                    w=(Link)malloc(sizeof(Node));
                    w->coeficient=0;
                    w->exp=s->exp-1;
                    s->next=w;
                    w->next=pa;
                    s=w;
                }
            }
        }
        if(!pa->next)
        {
            e=pa->exp-0;
            for(int j=0;j<e;j++)
            {
                w=(Link)malloc(sizeof(Node));
                w->coeficient=0;
                w->exp=pa->exp-1;
                pa->next=w;
                w->next=NULL;
                pa=w;
            }
            return f;
        }
    }
    return f;
}
int Num(Link f)
{
    Link pa;
    int i=0;
    pa=f->next;
    while(pa)
    {
        pa=pa->next;
        i++;
    }
    return i;
}
void Division(Link A,Link B)
{
    Link pa,pb,pc,C,w;
    float a,b;
    int A_num,B_num,m,n;
    pa=A->next;
    pb=B->next;
    if(pa->coeficient==0)
    {
        printf("��Ϊ��0");
    }
    if(pa->exp<pb->exp)
    {
        printf("���ܱ���������ʽΪ��");
        print(A);
    }
    else
    {
        A_num=Num(A);
        B_num=Num(B);
        A=Completion(A,A_num);
        B=Completion(B,B_num);
        if(pa->exp==pb->exp)
        {
            a=pa->coeficient;
            b=pb->coeficient;
            while(pb&&pa)
            {

                pa->coeficient=pa->coeficient-(a*pb->coeficient)/b;
                pa=pa->next;
                pb=pb->next;
            }
            printf("��Ϊ��");
            printf("%.2f\n",a/b);
            A=Dele(A);
            printf("��ʽΪ��");
            print(A);
        }
        else if(pa->exp>pb->exp)
        {
            m=pa->exp;
            n=pb->exp;
            C=(Link)malloc(sizeof(Node));
            C->next=NULL;
            pc=C;
            for(int i=0;i<m-n+1;i++)
            {
                pa=A->next;
                pb=B->next;
                a=pa->coeficient;
                b=pb->coeficient;
                while(pb)
                {
                    pa->coeficient=pa->coeficient-(a*pb->coeficient)/b;
                    pa=pa->next;
                    pb=pb->next;
                }
                w=(Link)malloc(sizeof(Node));
                w->coeficient=a/b;
                w->exp=m-n-i;
                w->next=NULL;
                pc->next=w;
                pc=w;
                pa=A->next;
                A->next=pa->next;
            }
            A=Dele(A);
            C=Dele(C);
            printf("��Ϊ��");
            print(C);
            printf("��ʽΪ��");
            print(A);
        }
    }
}
//����
*/

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
    cout << "��һ��:";
    print(headA);
    cout << "������ڶ�������ʽ��ϵ����ָ������(0 0)������" << endl;
    inputPoly(headB);
    cout << "�ڶ���:";
    print(headB);
    cout << "��ѡ��Ҫ���е��������:(+:1  -:2  *:3  /:4):";
    int i;
    cin >> i;
    if (i == 1)
    {
        AddList(headA, headB, headAB);
    }
    if (i == 2)
    {
        SubtractList(headA, headB, headAB);
    }
    if (i == 3)
    {
        MultiplyList(headA, headB, headAB);
    }
    if (i == 4)
    {
        DivisionList(headA, headB, headAB);
    }
    cout << "�ϲ���:";
    print(headAB);
    //cout << "�Ƿ�Ըö���ʽ���и�ֵ����Y(y) or N(n):";
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
    double coeficient;
    int exp;//ϵ����ָ��
    cout << "������ϵ����ָ��(�磺\"2 3\"��ʾ2x^3)��";
    cin >> coeficient >> exp;
    while (coeficient != 0 || exp != 0)//����������ϵ����ָ��
    {
        insert(head, coeficient, exp);//�������������ʽ
        cout << "������ϵ����ָ����";
        cin >> coeficient >> exp;
    }
}

/**�����ʽ�����в���Ԫ�صĺ���
int coeficient һ������ʽ���ϵ��
int exp һ������ʽ�����
*/
bool insert(Link head, double coeficient, int exp)
{
    Link node;  //nodeָ��ָ���´����Ľڵ�
    Link q, p;   //q,p�����ڵ�һǰһ��
    q = head;
    p = head->next;

    //����һ���½��
    node = (Link)malloc(sizeof(Node));
    node->next = NULL;
    node->coeficient = coeficient;
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
                p->coeficient = p->coeficient + node->coeficient;
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
    printf("����ʽ���£�\n");
    p = head->next;

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
        if (isFirstItem == true) {
            if (p->coeficient == 1) {//���ϵ��Ϊ1 ����ӡϵ��
                strcat(item, "X^");
                sprintf(number, "%d", p->exp);
                strcat(item, number);
            }
            else if ((p->coeficient != 0) && (p->coeficient != -1)) {//���ϵ����Ϊ0��-1��ӡϵ��

                sprintf(number, "%d", p->coeficient);
                strcat(item, number);//��number�����ϵ������item
                sprintf(number, "%d", p->exp);//number�����ָ��


                strcat(item, "X^");//��ʱitem��ϵ����ƴ��x^
                strcat(item, number);//�����ٴ�ƴ��number��ָ��
            }
            else {//���ϵ��Ϊ-1
                strcat(item, "-X^");
                sprintf(number, "%d", p->exp);
                strcat(item, number);
            }
        }
        else//������ǵ�һ���ϵ��Ϊ������Ҫ��Ӻ�
        {
            if (p->exp != 0) {
                if (p->coeficient == 1) {
                    strcat(item, "+X^");
                    sprintf(number, "%d", p->exp);
                    strcat(item, number);
                }
                else if ((p->coeficient != 0) && (p->coeficient != -1)) {
                    sprintf(number, "%d", p->coeficient);
                    strcat(item, "+");
                    strcat(item, number);
                    sprintf(number, "%d", p->exp);

                    strcat(item, "X^");
                    strcat(item, number);
                }
                else {//���ϵ��Ϊ-1
                    strcat(item, "-X^");
                    sprintf(number, "%d", p->exp);
                    strcat(item, number);
                }
            }
            else {//���ָ��Ϊ0ֱ�Ӵ�ӡϵ������ӡָ��
                sprintf(number, "%d", p->coeficient);
                strcat(item, "+");
                strcat(item, number);
            }
        }
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
    Link pa, pb, p, temp, temp2;//ָ��a��b�����ab��ָ��
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
            temp = pa->next;


            pa = temp;
            p = p->next;
        }
        else if (pa->exp < pb->exp) {
            p->next = pb;
            temp = pb->next;


            pb = temp;
            p = p->next;
        }
        else
        {
            pa->coeficient = pa->coeficient + pb->coeficient;
            temp2 = pb->next;
            free(pb);
            pb = temp2;

            p->next = pa;
            temp = pa->next;

            pa = temp;
            p = p->next;
        }
    }
    //���a��b������β�ͣ������ӵ�ab�������

    while (pa != NULL)
    {
        p->next = pa;
        pa = pa->next;
    }
    while (pb != NULL)
    {
        p->next = pb;
        pb = pb->next;
    }


}

void SubtractList(Link heada, Link headb, Link headab)
{
    Link pa, pb, p, temp, temp2;//ָ��a��b�����ab��ָ��
    pa = heada->next;
    pb = headb->next;
    p = headab;
    while (pb)
    {
        pb->coeficient = -pb->coeficient;
        pb = pb->next;
    }
    pb = headb->next;
    while (pa != NULL && pb != NULL)//a,b����û��û�з������
    {
        //���ָ��a>ָ��b��a�ڵ����ab����aָ�����
        //���ָ��a<ָ��b��b�ڵ����ab����bָ�����
        //���ָ��a==ָ��b��a��bϵ����ӣ�����ab����a��bָ�����
        if (pa->exp > pb->exp) {
            p->next = pa;
            temp = pa->next;
            pa->next = NULL;

            pa = temp;
            p = p->next;
        }
        else if (pa->exp < pb->exp) {
            p->next = pb;
            temp = pb->next;
            pb->next = NULL;

            pb = temp;
            p = p->next;
        }
        else {
            pa->coeficient = pa->coeficient + pb->coeficient;
            temp2 = pb->next;
            free(pb);
            pb = temp2;
            p->next = pa;
            temp = pa->next;
            pa->next = NULL;
            pa = temp;
            p = p->next;
        }

    }
    //���a��b������β�ͣ������ӵ�ab�������

    while (pa != NULL)
    {
        p->next = pa;
        pa = pa->next;
    }
    while (pb != NULL)
    {
        p->next = pb;
        pb = pb->next;
    }

}

void MultiplyList(Link heada, Link headb, Link headab)
{
    Link pa, pb, p;
    pa = heada->next;
    pb = headb->next;
    p = headab;

    while (pa)
    {
        while (pb)
        {
            insert(p, pa->coeficient * pb->coeficient, pa->exp + pb->exp);
            pb = pb->next;
        }
        pb = headb->next;
        pa = pa->next;
        //pb=pb->next;
    }
}

void DivisionList(Link heada, Link headb, Link headab)
{
    Link pa, pb, p;
    pa = heada->next;
    pb = headb->next;
    p = headab;

    while (pa)
    {
        while (pb)
        {
            insert(p, double(pa->coeficient) / pb->coeficient, pa->exp - pb->exp);
            pb = pb->next;
        }
        pb = headb->next;
        pa = pa->next;
    }
}

void Division(Link heada, Link headb, Link headab)
{
    Link pa, pb, p, t, ta, tb;
    int count = 0;
    p = headab;
    pa = heada->next;
    pb = headb->next;
    while (pb != NULL)
    {
        ++count;
        pb = pb->next;
    }
    if (count == 1)
    {
        while (pa)
        {
            while (pb)
            {
                insert(p, double(pa->coeficient) / pb->coeficient, pa->exp - pb->exp);
                pb = pb->next;
            }
            pb = headb->next;
            pa = pa->next;
        }
    }
    else
    {
        while (pb != NULL)
        {
            pb = pb->next;
            if (pb->next == NULL)
                tb = pb;
        }
        while (pa != NULL)
        {
            pa = pa->next;
            if (pa->next == NULL)
                ta = pa;
        }
        tb = (Link)malloc(sizeof(Node));
        ta = (Link)malloc(sizeof(Node));
        if (tb->exp <= ta->exp)
        {
            t = tb;
        }
        else
        {
            t = ta;
        }
        while (pa != NULL)
        {
            pa->exp = pa->exp - t->exp;
            pa = pa->next;
        }
        while (pb != NULL)
        {
            pb->exp = pb->exp - t->exp;
            pb = pb->next;
        }

    }
}