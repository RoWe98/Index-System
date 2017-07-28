
 //  main.c
 //  index
 //
 //  Created by luoshaoqi on 2017/7/13.
 //  Copyright © 2017年 luoshaoqi. All rights reserved.
 //

//通信录管理系统 代码不是特别完善 在win平台上可能不能运行
//代码编写平台为 macos serria
//编译工具为xcode

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Telephone
{
    char name[50];
    char sex[30];
    char tel[30];
    char city[30];
    char componey[30];
    struct Telephone *next;
}Telephone, *head;


//Initiate
void  Initiate(Telephone *head)
{
    head->next = NULL;
}


//Show Menu
void Menu()
{
    printf("Welcome to use the Index System\n");
    printf("1.Create the Index\n");
    printf("2.Find the index\n");
    printf("3.Change the Index\n");
    printf("4.delete the index\n");
    printf("5.show all the index\n");
    printf("6.Inset the new data\n");
    printf("0.Exit the index\n");
    printf("INPUT0-6 to Use The Function\n");
}


//Create the new Index。
void Enter(Telephone *head)
{
    int c;
    Telephone *s, *r, *p;
    int flag=1 , m;
    s = r = head;
    p = (Telephone*)malloc(sizeof(Telephone)); //生成新结点
    if (p == NULL) //验证空间申请是否成功
    {
        printf("内存分配失败\n");
        return;      //若分配内存不成功，则返回继续分配。
    }
    while (flag)
    {
        printf("请选择是否继续进行操作！\n");
        printf("请输入 1(是)   or  2(否) ！\n");
        scanf("%d", &m);
        if (m == 1)
        {
            p = (Telephone*)malloc(sizeof(Telephone)); //生成新结点
            printf("姓名:\n");
            scanf("%s", p->name);
        lop:printf("电话:\n");
            scanf("%s", p->tel);
            if (s->next == NULL)
                goto lip;
            while (s->next != 0 && strcmp(s->next->tel, p->tel)) //从LHead指向得头结点的下一个结点开判断结点中的城市名与输入城市名是否相等。
            {
                s = s->next;
            }//  当不相等则指针LHead下移，继续查找
            if (s->next != 0)
            {
                printf("你输入的电话号已存在请重新输入手机号\n\n");
                goto lop;
            }
            else
            {
            lip:printf("性别:\n");
                scanf("%s", p->sex);
                printf("工作单位:\n");
                scanf("%s", p->componey);
                printf("城市:\n");
                scanf("%s", p->city);
                while (head->next != NULL)
                {
                    head = head->next;
                }
                //如果非空，HLead指针的位置向后移
                p->next = head->next;
                head->next = p;
                s = r;
            }
        }
        else if (m == 2)
            flag = 0;
    }
    while ((c = getchar()) != '\n')
        printf("%c", c);
}


//查找通讯录信息
void Search(Telephone *head)
{
    int c;
    char tel[50], name[20];
    int j = 0, m;
    if (head->next == NULL)
    {
        printf("当前未存储通讯录信息，请先存储通讯录信息后再进行此操作，谢谢！\n");
        goto loop;
    }
    printf("请输入您需要查找的方式为1(按手机号查找 )or2( 按联系人姓名查找)\n");
    scanf("%d", &m);
    if (m == 1)
    {
        printf("请输入您要搜索的手机号\n");
        scanf("%s", tel);
        while (head->next != 0 && strcmp(head->next->tel, tel))
        {
            head = head->next; //  当不相等则指针LHead下移，继续查找
        }
        if (head->next != 0)
        {
            printf("你所查找的手机号%s，其余信息为姓名：%s性别%s：公司：%s城市：%s\n", head->next->tel, head->next->name, head->next->sex, head->next->componey, head->next->city);
        }
        else
            printf("已存储信息里面找不到你所查手机号\n");
    }
    if (m == 2)
    {
        printf("请输入您要搜索的联系人姓名\n");
        scanf("%s", name);
        while (1)
        {
            if (strcmp(head->next->name, name) == 0)
            {
                printf("你所查找的联系人%s，其余信息为手机号：%s性别%s：公司：%s城市：%s\n\n", head->next->name, head->next->tel, head->next->sex, head->next->componey, head->next->city);
                j++;
            }
            head = head->next; //  当不相等则指针LHead下移，继续查找
            if (head->next == 0 && j == 0)
                printf("已存储信息里面找不到你所查联系人\n");
            if (head->next == 0)
                break;
        }
        
    }
loop:printf("\n");
    while ((c = getchar()) != '\n')
        printf("%c", c);
}


void Alter(Telephone *head)//修改记录如果未找到要修改的人，则提示通讯录中没有此人的信息，并返回选单。
{
    int c;
    Telephone *p, *s;
    char tel[50];
    int m;
    s = p = head;
    if (head->next == NULL)
    {
        printf("当前未存储通讯录信息，请先存储通讯录信息后再进行此操作，谢谢！\n");
        goto loop;
    }
    printf("请输入您要更新信息的手机号\n");
    scanf("%s", tel);
    while (head->next != 0 && strcmp(head->next->tel, tel))
    {
        head = head->next;
    }
    if (head->next != 0)
    {
        printf("你所查找的手机号%s，其余信息为姓名：%s性别%s：公司：%s城市：%s\n", head->next->tel, head->next->name, head->next->sex, head->next->componey, head->next->city);
        printf("请输入您需要修改的项目为1(手机号 )or2( 其他信息)\n");
        scanf("%d", &m);
        if (m == 2)
        {
            printf("请输入该手机号新信息\n");
            printf("请输入通讯录新姓名\n");
            scanf("%s", head->next->name);
            printf("请输入性别:\n");
            scanf("%s", (head->next->sex));
            printf("请输入工作单位:\n");
            scanf("%s", (head->next->componey));
            printf("请输入城市:\n");
            scanf("%s", (head->next->city));
            printf("修改后信息为 ：手机号%s其余信息为姓名：%s性别%s：公司：%s城市：%s", head->next->tel, head->next->name, head->next->sex, head->next->componey, head->next->city);
        }
        if (m == 1)
        {
        lop:printf("请输入新手机号\n");
            scanf("%s", tel);
            while (p->next != 0 && strcmp(p->next->tel, tel))
            {
                p = p->next;
            }
            if (p->next != 0)
            {
                printf("您输入的手机号已存在请重新输入！\n");
                p = s;
                goto lop;
            }
            else
            {
                strcpy(head->next->tel, tel);
                printf("修改后信息为 ：手机号%s其余信息为姓名：%s性别%s：公司：%s城市：%s\n", head->next->tel, head->next->name, head->next->sex, head->next->componey, head->next->city);
            }
        }
    }
    else printf("已存储的通讯录信息中无您需要修改的信息\n");
loop:printf("\n");
    while ((c = getchar()) != '\n')
        printf("%c", c);
}


void Delete(Telephone *head)
{
    int c;
    char  tel[50];
    int b;
    Telephone *r;
    if (head->next == NULL)
    {
        printf("当前未存储通讯录信息，请先存储通讯录信息后再进行此操作，谢谢！\n\n");
        goto loop;
    }
    printf("请输入要删除的手机号\n");
    scanf("%s", tel);
    while (head->next != 0 && strcmp(head->next->tel, tel))
    {
        head = head->next;
    }
    if (head->next != 0)
    {
        printf("你所需要删除的联系人信息为手机号%s，其余信息为姓名：%s性别%s：公司：%s城市：%s\n", head->next->tel, head->next->name, head->next->sex, head->next->componey, head->next->city);
        printf("请确认是否删除删除该联系人的通讯录信息：1（是）   2（否）\n");
        scanf("%d", &b);
        if (b == 1)
        {
            r = head->next;
            head->next = r->next;
            printf("已删除你所选择的通讯录信息\n");
        }
        if (b == 2)
            goto loop;
    }
    else
        printf("已存储信息里面找不到你所需要删除的通讯录信息\n");
loop:printf("");
    while ((c = getchar()) != '\n')
        printf("%c", c);
}


void Display(Telephone *head)//的功能是：显示通讯录中的所有记录。
{
    int c;
    Telephone  *p;
    p = head->next;
    if (p != 0)
    {
        printf("通讯录管理系统\n");
        while (p)
        {
            
            printf("姓名：%s\t电话：%s\t性别：%s\t城市：%s\t工作单位：%s\n\n", p->name, p->tel, p->sex, p->city, p->componey);
            p = p->next;
        }
        printf("通讯录管理系统\n");
    }
    else if (p == 0)
        printf("此通讯录中无记录!\n");
    while ((c = getchar()) != '\n')
        printf("%c", c);
}



int main()
{
    Telephone *head,*hello;
    int  choice,c;
    head = (Telephone*)malloc(sizeof(Telephone));
    hello= head;
    Initiate(head);
    do
    {
        Menu();
        printf("请选择0-6的数字: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                Enter(hello);
                while ((c = getchar()) != '\n')
                    printf("%c", c);
                break;
            case 2:
                Search(hello);
                while ((c = getchar()) != '\n')
                    printf("%c", c);
                break;
            case 3:
                Alter(hello);
                while ((c = getchar()) != '\n')
                    printf("%c", c);
                break;
            case 4:
                Delete(hello);
                while ((c = getchar()) != '\n')
                    printf("%c", c);
                break;
            case 5:
                Display(hello);
                while ((c = getchar()) != '\n')
                    printf("%c", c);
                break;
            case 7:
                Enter(hello);
                while ((c = getchar()) != '\n')
                    printf("%c", c);
                break;
            case 0:
                printf("感谢您的使用\n");
                exit(0);
                break;
            default:
                printf("输入有误!请重新输入\n");
                break;
        }
    } while (1);
    return 0;
}




