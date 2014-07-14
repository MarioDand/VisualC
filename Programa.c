#include<iostream.h>
#include<stdio.h>
FILE *f1,*f2,*f3;
int cnt(FILE *fp);
char FileName2[20],FileName3[20];
void funk1(void);
void funk2(void);
void funk3(void);
void funk4(void);
void menu(void);
int main()
{
    menu();
    return 0;    
}
void menu()
{
	int n;
	do	
	{	
        printf("\tMENU\n1) Chetene ot fail i zapis vyv drug fail\n2) Chetene ot fail i izvejdane na ekrana\n3) Chetene ot klaviatura i izvejdane vyv fail ot potrevitelq\n4) Chetene ot klaviaturata i izvejdane na ekrana\nSistemata ochakva vashiq izbor:");
		scanf("%d",&n);
		switch(n)
		{
		case 1:funk1();continue;
		case 2:funk2();continue;
		case 3:funk3();continue;
		case 4:funk4();
		}
	}while(1);
}
int broqch(FILE *fp)
{
    int pr=0;
    char ch;
    while ((ch=fgetc(fp)) != EOF)
              {if(ch!='==') pr++;}
               fprintf(f2,"%d\n",pr);
}
int broqch2(FILE *fp)
{
    int pr=0;
    char ch;
    while ((ch=fgetc(fp)) != EOF)
              {if((ch!='==')&&(ch!='!=')&&(ch=='='))pr++;}
               printf("%d\n",pr);
}
void funk1()
{
    char FileName[20];
    int pr;
    do
    {
    printf("Vavedete imeto na faila koito iskate da otvorite: \n");
    scanf("%s",&FileName);
    f1=fopen(FileName,"r");
    }while(f1==NULL);
    do
    {
    printf("Vavedete imeto na faila na koito iskate da zapisvate :\n");
    scanf("%s",&FileName2);
    f2=fopen(FileName2,"w");
    }while(f2==NULL);
    broqch(f1);
    fclose(f1);
    fclose(f2);
}
void funk2()
{
    char FileName[20];
    int pr;
    do
    {
    printf("Vavedete imeto na faila koito iskate da otvorite: \n");
    scanf("%s",&FileName);
    f1=fopen(FileName,"r");
    }while(f1==NULL);
    broqch2(f1);
    fclose(f1);
}
void funk3()
{
    char tekst[100];
    printf("Vavedete svoboden tekst: \n");
    f3=fopen("text4.txt","w");
    fflush(stdin);
    while(fgets(tekst,99,stdin)!=NULL){
    fputs(tekst,f3);}
    do
    {
    printf("Vavedete imeto na faila na koito iskate da zapisvate :\n");
    scanf("%s",&FileName2);
    f2=fopen(FileName2,"w");
    }while(f2==NULL);
    fclose(f3);
    f3=fopen("text4.txt","r");
    broqch(f3);
    fclose(f2);
    fclose(f3);    
     }
void funk4()
{
    char tekst[100];
    printf("Vavedete svoboden tekst: \n");
    f3=fopen("text4.txt","w");
    fflush(stdin);
    while(fgets(tekst,99,stdin)!=NULL)
    {
    fprintf(f3,"%s",tekst);
}
    fclose(f3);
    f3=fopen("text4.txt","r");
    broqch2(f3);
    fclose(f3);   
     }
