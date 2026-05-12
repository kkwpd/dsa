#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
union REGS reg;
void cd(){
char path[25];
printf("Enter the path of the directory to be created : ");
gets(path);
reg.h.ah=0x39;
reg.x.dx=(unsigned)path;
int86(0x21,&reg,&reg);
if(reg.x.cflag)printf("Directory Not Created");
else printf("Directory Created");}

void cf(){
char path[25];
printf("Enter the path of the File to be created : ");
gets(path);
reg.h.ah=0x3C;
reg.x.dx=(unsigned)path;
int86(0x21,&reg,&reg);
if(reg.x.cflag)printf("File Not Created");
else printf("File Created");}

void df(){
char path[25];
printf("Enter the path of the File to be deleted: ");
gets(path);
reg.h.ah=0x41;
reg.x.dx=(unsigned)path;
int86(0x21,&reg,&reg);
if(reg.x.cflag)printf("File Not Deleted");
else printf("File Deleted");}

void dd(){
char path[25];
printf("Enter the path of the Directory to be deleted: ");
gets(path);
reg.h.ah=0x3A;
reg.x.dx=(unsigned)path;
int86(0x21,&reg,&reg);
if(reg.x.cflag)printf("Directory Not Deleted");
else printf("Directory Deleted");}

int main(){int c;
do{printf("\n\n-----Menu-----\n");
   printf("1. Create Directory\n");
   printf("2. Create File\n");
   printf("3. Delete File\n");
   printf("4. Delete Directory\n");
   printf("5. EXIT\n");
   printf("Enter your choice : ");
   scanf("%d",&c);
   fflush(stdin);
switch(c){case 1:cd();break;
          case 2:cf();break;
          case 3:df();break;
          case 4:dd();break;
          case 5:;break;
          default:printf("Invalid Choice!\n")
}}while(c!=5);
return 0;}