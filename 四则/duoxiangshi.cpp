#pragma warning(disable:4996)

#include<iostream>
using namespace std;

typedef struct polynomial
{
    int coeficient;//系数
    int exp;//指数
    struct polynomial* next;
}*Link, Node;

void inputPoly(Link head);//用于从控制台读入链表的函数
void print(Link head);//打印链表用的函数
bool insert(Link head, double coeficient, int exp);//向链表插入一个元素的函数
void AddList(Link heada, Link headb, Link headab);//相加两个链表
void SubtractList(Link heada, Link headb, Link headab);
void MultiplyList(Link heada, Link headb, Link headab);
void DivisionList(Link heada, Link headb, Link headab);
void Division(Link heada, Link headb, Link headab);

/*
//除法
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
        printf("商为：0");
    }
    if(pa->exp<pb->exp)
    {
        printf("不能被整除，余式为：");
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
            printf("商为：");
            printf("%.2f\n",a/b);
            A=Dele(A);
            printf("余式为：");
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
            printf("商为：");
            print(C);
            printf("余式为：");
            print(A);
        }
    }
}
//除法
*/

int main()
{
    Link headA, headB;//两个多项式的头指针
    Link headAB;//合并后的多项式的头指针

    /*链表的初始化*/
    headA = (Link)malloc(sizeof(Node));
    headA->next = NULL;
    headB = (Link)malloc(sizeof(Node));
    headB->next = NULL;
    headAB = (Link)malloc(sizeof(Node));
    headAB->next = NULL;

    cout << "请输入第一个多项式的系数和指数，以(0 0)结束：" << endl;
    inputPoly(headA);
    cout << "第一个:";
    print(headA);
    cout << "请输入第二个多项式的系数和指数，以(0 0)结束：" << endl;
    inputPoly(headB);
    cout << "第二个:";
    print(headB);
    cout << "请选择要进行的运算规则:(+:1  -:2  *:3  /:4):";
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
    cout << "合并后:";
    print(headAB);
    //cout << "是否对该多项式进行赋值运算Y(y) or N(n):";
    free(headA);
    free(headB);
    free(headAB);
    return 0;
}

/**输入二项式数据的函数*/
/*这个函数用来输入二项式，给用户合适的提示，读入用户输入的系数和指数。
调用函数insert，将用户输入的二项式的一项插入到链表中去。*/
void inputPoly(Link head)
{
    double coeficient;
    int exp;//系数和指数
    cout << "请输入系数和指数(如：\"2 3\"表示2x^3)：";
    cin >> coeficient >> exp;
    while (coeficient != 0 || exp != 0)//连续输入多个系数和指数
    {
        insert(head, coeficient, exp);//调函数输入多项式
        cout << "请输入系数和指数：";
        cin >> coeficient >> exp;
    }
}

/**向多项式链表中插入元素的函数
int coeficient 一个多项式项的系数
int exp 一个多项式项的幂
*/
bool insert(Link head, double coeficient, int exp)
{
    Link node;  //node指针指向新创建的节点
    Link q, p;   //q,p两个节点一前一后
    q = head;
    p = head->next;

    //创建一个新结点
    node = (Link)malloc(sizeof(Node));
    node->next = NULL;
    node->coeficient = coeficient;
    node->exp = exp;

    if (head->next == NULL)//空表,插第1个
    {
        head->next = node;
    }
    else
    {
        while (p != NULL) { //循环访问链表中的所有节点

            //如果node节点的指数比p节点的指数大，则插在p的前面，完成插入后，提前退出
            //如果node节点的指数和p节点的指数相等，则合并这个多项式节点，提前退出
            //如果node节点的指数比p节点的指数小，继续向后移动指针（依然保持p，q一前一后）
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
        //如果退出循环是当前指针p移动到链表结尾，则说明之前没有插入，那么当前node节点的指数值是最大值，此时插在链表的最后面
        q->next = node;
    }
    //free(node);
    return true;
}

/**
打印多项式链表的函数
*/
/*
①　通过指针访问链表
②　多重条件语句嵌套
③　数字转换为字符串函数itoa
④　标志是否为第一个节点的flag的设置
⑤　字符串连接函数strcat
⑥　字符串清空函数memset。memset(item,0,20);清空长20的字符串item
请补充代码实现。
*/
void print(Link head)
{
    Link p; //指向链表要输出的结点
    printf("多项式如下：\n");
    p = head->next;

    if (p == NULL)
    {
        printf("多项式为空\n");
        return;
    }

    // 不是空表
    char item[20] = "";//要打印的当前多项式的一项
    char number[7] = "";//暂时存放系数转换成的字符串

    bool isFirstItem = true;//标志是否为第一个节点的flag
    //打印节点
    do {
        memset(item, 0, 20);//清空字符串item
        //如果是第一项，不要打+号
        if (isFirstItem == true) {
            if (p->coeficient == 1) {//如果系数为1 不打印系数
                strcat(item, "X^");
                sprintf(number, "%d", p->exp);
                strcat(item, number);
            }
            else if ((p->coeficient != 0) && (p->coeficient != -1)) {//如果系数不为0或-1打印系数

                sprintf(number, "%d", p->coeficient);
                strcat(item, number);//将number里面的系数给了item
                sprintf(number, "%d", p->exp);//number存放了指数


                strcat(item, "X^");//此时item（系数）拼接x^
                strcat(item, number);//上面再次拼接number的指数
            }
            else {//如果系数为-1
                strcat(item, "-X^");
                sprintf(number, "%d", p->exp);
                strcat(item, number);
            }
        }
        else//如果不是第一项，且系数为正数，要打加号
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
                else {//如果系数为-1
                    strcat(item, "-X^");
                    sprintf(number, "%d", p->exp);
                    strcat(item, number);
                }
            }
            else {//如果指数为0直接打印系数不打印指数
                sprintf(number, "%d", p->coeficient);
                strcat(item, "+");
                strcat(item, number);
            }
        }
        printf("%s", item);//打印当前节点代表的项
        p = p->next;//指向下个结点
        isFirstItem = false;//flag标志不是第一项了
    } while (p != NULL);
    printf("\n");
}

/**
合并两个有序链表a，b到链表ab
heada.headb,headab分别为链表a,b,ab的头指针
*/
void AddList(Link heada, Link headb, Link headab)
{
    Link pa, pb, p, temp, temp2;//指向a，b链表和ab的指针
    pa = heada->next;
    pb = headb->next;
    p = headab;

    while (pa != NULL && pb != NULL)//a,b链表都没有没有访问完毕
    {
        //如果指数a>指数b，a节点插入ab链表，a指针后移
        //如果指数a<指数b，b节点插入ab链表，b指针后移
        //如果指数a==指数b，a、b系数相加，插入ab链表，a、b指针后移
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
    //如果a、b链表还有尾巴，将它加到ab链表后面

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
    Link pa, pb, p, temp, temp2;//指向a，b链表和ab的指针
    pa = heada->next;
    pb = headb->next;
    p = headab;
    while (pb)
    {
        pb->coeficient = -pb->coeficient;
        pb = pb->next;
    }
    pb = headb->next;
    while (pa != NULL && pb != NULL)//a,b链表都没有没有访问完毕
    {
        //如果指数a>指数b，a节点插入ab链表，a指针后移
        //如果指数a<指数b，b节点插入ab链表，b指针后移
        //如果指数a==指数b，a、b系数相加，插入ab链表，a、b指针后移
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
    //如果a、b链表还有尾巴，将它加到ab链表后面

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