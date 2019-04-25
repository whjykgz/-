#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;
void E();
void T();
void E1();
void T1();
void A();
void F();
void V();
char s[50],n='1';
char Table[50][3];
int x,y;
int list_n=0;
int main()
{
x=0;
y=0;
    scanf("%s",s);
    if(s[0]=='\0')
        return 0;
    A();
    return 0;
}
void A()
{
    V();
    if(s[y]==':'&&s[y+1]=='='){
        y=y+2;
        E();
        printf("%s:=%s",Table[list_n-2],Table[list_n-1]);
        printf("     (:=,%s,-,%s)\n",Table[list_n-1],Table[list_n-2]);
    }else{
        printf("spelling mistakes");
        x=1;
        exit(0);
    }
}

void V()
{
    if(islower(s[y])){
        Table[list_n][0]=s[y];
        Table[list_n][1]='\0';
        list_n++;
        y++;
    }else{
        printf("Error\n");
        x=1;
        exit(0);
    }
}

void T()
{
    if(x==0){
        F();
        T1();
    }
}

void E()
{
    if(x==0){
        T();
        E1();
    }
}

void E1()
{
    int p;
    if(x==0){
        if(s[y]=='+'||s[y]=='-'){
            p=y;
            y++;
            T();
            char ch[3];
            ch[0]='T';
            ch[1]=n;
            ch[2]='\0';
            if(s[p]=='+'){
                printf("%s:=%s+%s",ch,Table[list_n-2],Table[list_n-1]);
                printf("     (+,%s,%s,%s)\n",Table[list_n-2],Table[list_n-1],ch);
            }else{
                printf("%s:=%s-%s",ch,Table[list_n-2],Table[list_n-1]);
                printf("     (-,%s,%s,%s)\n",Table[list_n-2],Table[list_n-1],ch);
            }
            strcpy(Table[list_n-2],ch);
            list_n--;
            n++;
            E1();
        }
    }
}

void T1()
{
    int p;
    if(x==0){
        if(s[y]=='*'||s[y]=='/'){
            p=y;
            y++;
            F();
            char ch[3];
            ch[0]='T';
            ch[1]=n;
            ch[2]='\0';
            if(s[p]=='*'){
                printf("%s:=%s*%s",ch,Table[list_n-2],Table[list_n-1]);
                printf("     (*,%s,%s,%s)\n",Table[list_n-2],Table[list_n-1],ch);
            }else{
                printf("%s:=%s/%s",ch,Table[list_n-2],Table[list_n-1]);
                printf("     (/,%s,%s,%s)\n",Table[list_n-2],Table[list_n-1],ch);
            }
            strcpy(Table[list_n-2],ch);
            list_n--;
            n++;
            T1();
        }
    }
}
void F()
{
    if(x==0){
        if(s[y]=='('){
            y++;
            E();
            if(s[y]==')')
                y++;
            else{
                printf("ERROR");
                x=1;
                exit(0);
            }
        }else if(islower(s[y]))
            V();
        else{
            printf("ERROR");
            x=1;
            exit(0);
        }
    }
}
