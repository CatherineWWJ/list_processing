#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef struct LNode {
    int data; // 编号
    char name[20];
    int age;
    char job; // s:班级， t：职称
    char CL_PR[20]; // 班级 / 职称
    struct LNode *next;
} LNode, *LinkList;

// 尾插法建立单链表
LinkList List_TailCreate(LinkList &L) {
    LinkList r = L; // 尾指针
    LinkList s; // 指向添加的新结点
    while(true) {
        int x;
        printf("请输入编号: ");
        scanf("%d", &x);
        if(x != 0){ // 如果编号输入为0则不再录入信息
            s = (LinkList) malloc(sizeof(LNode));
            s->data = x;
            s->next = NULL;
            printf("请输入姓名: ");
            scanf("%s", s->name);
            printf("请输入年龄: ");
            scanf("%d", &s->age);
            printf("请输入职业: ");
            getchar();
            scanf("%c", &s->job);
            if(s->job == 's') {
                printf("请输入班级号：");
                scanf("%s", s->CL_PR);
            } else {
                printf("请输入职称名：");
                scanf("%s", s->CL_PR);
            }
            r->next = s;    //尾部节点指向新结点
            r = s;
        } else {
            break;
        }
    }
    return L;
}

// 打印链表数据
void PrintList(LinkList L) {
    LinkList p;
    p = L->next;
    printf("表中的元素为：\n");
    printf("编号\t姓名\t年龄\t职业\t班级（职称）:\n");
    while (p != NULL) {
        printf("%d\t%s\t%d\t%c\t%s\n", p->data, p->name, p->age, p->job, p->CL_PR);
        p = p->next;
    }
    printf("\n");
}

// 查找年龄最大的结点并输出对应数据
void FindMax(LinkList L) {
    LinkList m; // 指向所需结点
    LinkList p = L->next; // 遍历结点
    m = p;
    while (p != NULL) {
        if(p->age>m->age) {
            m = p;
        }
        p = p->next;
    }
    if(m) {
        printf("年龄最大的元素为：\n");
        printf("编号\t姓名\t年龄\t职业\t班级（职称）:\n");
        printf("%d\t%s\t%d\t%c\t%s\n", m->data, m->name, m->age, m->job, m->CL_PR);
    } else {
        printf("数据为空！\n");
    }
}

// 删除年龄最大的结点并返回
LinkList DelMax(LinkList &L) {
    LinkList n; // 指向最大年龄结点前一个结点
    LinkList m; // 指向所需最大年龄结点
    LinkList p = L->next; // 遍历结点
    LinkList q = L; // 前一个结点
    m = p;
    n = q;
    while (p != NULL) {
        if(p->age>m->age) {
            m = p;
            n = q;
        }
        p = p->next;
        q = q->next;
    }
    if(m) {
        p = n->next;
        n->next = p->next;
        p->next = NULL;
        printf("删除最大年龄结点后的数据如下：\n");
        PrintList(L);
        return p;
    } else {
        printf("数据为空！\n");
    }
}

// 重新将年龄最大的结点添加到编号1和2之间
void AddEle(LinkList &L, LinkList &ele) {
    LinkList p = L->next;
    if(p) {
        ele->next = p->next;
        p->next = ele;
        printf("重新添加元素成功！数据如下：\n");
        PrintList(L);
    } else {
        printf("数据为空！\n");
    }
}

int main() {
    int N;
    LinkList L; //头指针
    L = (LinkList) malloc(sizeof (LNode)); // 创建头结点，头指针指向头结点
    L->next = NULL;

    List_TailCreate(L);  //尾插法建立单链表
    printf("------------------------------------------------------------\n");
    PrintList(L); // task1:输出所有
    printf("------------------------------------------------------------\n");
    FindMax(L); // task2:找最大并输出
    printf("------------------------------------------------------------\n");
    LinkList ele = DelMax(L); // task3:删除最大年龄结点
    printf("------------------------------------------------------------\n");
    AddEle(L, ele); // task4:将最大年龄结点重新添加到第1个和第2个数据之间的位置

    return 0;
}