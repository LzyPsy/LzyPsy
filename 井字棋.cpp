#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//�������� 
int res(char number[3][3],int t,int size,int f,int quan,int cha,int i,int result);
void print_a(char number[3][3], int o, int p);
int main(){
begin://���¿�ʼ
int a,b,n,c,d,f,m,x,y,k;
 int result=2;//0ΪȦӮ��1Ϊ��Ӯ��-1Ϊƽ�� 
 int size=3;
  int t,quan=0;
  int i,cha=0;
	char number[3][3]; 
	srand(time(0));//ʱ������ 
	//���̼��������� 
	printf("ע�⣺�������к���\n") ; 
printf("�������������꣬�磺��1,1��д�� 1�ո�1 \n");
back://��ѡ 
number[0][0]=' ';number[1][0]=' ';number[2][0]=' ';number[0][1]=' ';number[1][1]=' ';number[2][1]=' ';number[0][2]=' ';number[1][2]=' ';number[2][2]=' ';
printf("��ѡ������ģʽ��1.��ս  2.AI\n");
scanf("%d",&m);
printf("Ȧ���֣�����֣��������\n"); 
printf("       1     2     3  \n       %c  |  %c  |  %c  \n  1  _____|_____|_____\n       %c  |  %c  |  %c  \n  2  _____|_____|_____\n       %c  |  %C  |  %c  \n  3       |     |     \n"
,number[0][0],number[0][1],number[0][2],number[1][0],number[1][1],number[1][2],number[2][0],number[2][1],number[2][2]);
if(m==1){//��սģʽ 
//�غ�ѭ�� 
for(n=0;n<4;n++)
{
error1: 
 printf("��Ȧ���ӣ��������꣩\n"); 
scanf("%d %d",&a,&b);
if(a>3 || b>3 || number[b-1][a-1]!=' '){
 printf("��������������ص�������������\n");
 goto error1;//������� 
}
 number[b-1][a-1]='O';
printf("       1     2     3  \n       %c  |  %c  |  %c  \n  1  _____|_____|_____\n       %c  |  %c  |  %c  \n  2  _____|_____|_____\n       %c  |  %C  |  %c  \n  3       |     |     \n"
,number[0][0],number[0][1],number[0][2],number[1][0],number[1][1],number[1][2],number[2][0],number[2][1],number[2][2]);

 result= res(number,t,size,f,quan,cha,i,result); 
 if(result==1 || result==0){
 	goto out;}

error2:
printf("������ӣ��������꣩\n") ;
scanf("%d %d",&c,&d);
if(c>3 || d>3 || number[d-1][c-1]!=' '){
 printf("���������д���ص��� 11 ����������\n");
 goto error2;//������� 
}
 number[d-1][c-1]='X';
printf("       1     2     3  \n       %c  |  %c  |  %c  \n  1  _____|_____|_____\n       %c  |  %c  |  %c  \n  2  _____|_____|_____\n       %c  |  %C  |  %c  \n  3       |     |     \n"
,number[0][0],number[0][1],number[0][2],number[1][0],number[1][1],number[1][2],number[2][0],number[2][1],number[2][2]);

 result= res(number,t,size,f,quan,cha,i,result);  
 if(result==1 || result==0){
 	goto out;}}

//�������
error3:
  printf("��Ȧ���ӣ��������꣩\n") ; 
scanf("%d %d",&a,&b);
if(a>3 || b>3 || number[b-1][a-1]!=' '){
 printf("��������������ص�������������\n");
 goto error3;//������� 
}
number[b-1][a-1]='O';
printf("       1     2     3  \n       %c  |  %c  |  %c  \n  1  _____|_____|_____\n       %c  |  %c  |  %c  \n  2  _____|_____|_____\n       %c  |  %C  |  %c  \n  3       |     |     \n"
,number[0][0],number[0][1],number[0][2],number[1][0],number[1][1],number[1][2],number[2][0],number[2][1],number[2][2]);

result= res(number,t,size,f,quan,cha,i,result); 
 if(result==1 || result==0){
 	goto out;}
 	else
	 {result=-1;goto out;}
}
else if(m==2){//�˹�����ģʽ 
int n; 
back1:
printf("��ѡ���Ⱥ���:  1.����  2.����\n");
scanf("%d",&n) ;
if(n==1){
	for(k=0;k<4;k++) {//ѭ������ 
	errora: 
 printf("��Ȧ���ӣ��������꣩\n") ; 
scanf("%d %d",&a,&b);
if(a>3 || b>3 || number[b-1][a-1]!=' '){
 printf("��������������ص�������������\n");
 goto errora;//������� 
}
 number[b-1][a-1]='O';
printf("       1     2     3  \n       %c  |  %c  |  %c  \n  1  _____|_____|_____\n       %c  |  %c  |  %c  \n  2  _____|_____|_____\n       %c  |  %C  |  %c  \n  3       |     |     \n"
,number[0][0],number[0][1],number[0][2],number[1][0],number[1][1],number[1][2],number[2][0],number[2][1],number[2][2]);

result= res(number,t,size,f,quan,cha,i,result); 
 if(result==1 || result==0){
 	goto out;}
 	back2://��� 
	  x=rand()%3;
 	 y=rand()%3;
 	if(number[x][y]!=' '){
 		goto back2;
	 }else{	number[x][y]='X';
	 	}
 	printf("       1     2     3  \n       %c  |  %c  |  %c  \n  1  _____|_____|_____\n       %c  |  %c  |  %c  \n  2  _____|_____|_____\n       %c  |  %C  |  %c  \n  3       |     |     \n"
,number[0][0],number[0][1],number[0][2],number[1][0],number[1][1],number[1][2],number[2][0],number[2][1],number[2][2]);
result= res(number,t,size,f,quan,cha,i,result); 
 if(result==1 || result==0){result= res(number,t,size,f,quan,cha,i,result); 
 	goto out;}}
 		//���һ�� 
		 errorb: 
 printf("��Ȧ���ӣ��������꣩\n") ; 
scanf("%d %d",&a,&b);
if(a>3 || b>3 || number[b-1][a-1]!=' '){
 printf("��������������ص�������������\n");
 goto errorb;//������� 
}
 number[b-1][a-1]='O';
printf("       1     2     3  \n       %c  |  %c  |  %c  \n  1  _____|_____|_____\n       %c  |  %c  |  %c  \n  2  _____|_____|_____\n       %c  |  %C  |  %c  \n  3       |     |     \n"
,number[0][0],number[0][1],number[0][2],number[1][0],number[1][1],number[1][2],number[2][0],number[2][1],number[2][2]);

result= res(number,t,size,f,quan,cha,i,result); 
 if(result==1 || result==0){
 	goto out;}else{
 		result=-1;
		 goto out;} }
else if(n==2){
	for(k=0;k<4;k++){//ѭ������ 
	back3://��� 
 	 x=rand()%3;
 	 y=rand()%3;
 	if(number[x][y]!=' '){	
	 goto back3;
	 }else{number[x][y]='X';
	 }
 	printf("       1     2     3  \n       %c  |  %c  |  %c  \n  1  _____|_____|_____\n       %c  |  %c  |  %c  \n  2  _____|_____|_____\n       %c  |  %C  |  %c  \n  3       |     |     \n"
,number[0][0],number[0][1],number[0][2],number[1][0],number[1][1],number[1][2],number[2][0],number[2][1],number[2][2]);
result= res(number,t,size,f,quan,cha,i,result); 
 if(result==1 || result==0){
 	goto out;}
 	errorc: 
 printf("��Ȧ���ӣ��������꣩\n") ; 
scanf("%d %d",&a,&b);
if(a>3 || b>3 || number[b-1][a-1]!=' '){
 printf("��������������ص�������������\n");
 goto errorc;//������� 
}
 number[b-1][a-1]='O';
printf("       1     2     3  \n       %c  |  %c  |  %c  \n  1  _____|_____|_____\n       %c  |  %c  |  %c  \n  2  _____|_____|_____\n       %c  |  %C  |  %c  \n  3       |     |     \n"
,number[0][0],number[0][1],number[0][2],number[1][0],number[1][1],number[1][2],number[2][0],number[2][1],number[2][2]);

 result= res(number,t,size,f,quan,cha,i,result); 
 if(result==1 || result==0){
 	goto out;}}
 	//������� 
 	back4://��� 
 	 x=rand()%3;
 	 y=rand()%3;
 	if(number[x][y]!=' '){
 		goto back4;	
	 }else{number[x][y]='X';
	 }printf("       1     2     3  \n       %c  |  %c  |  %c  \n  1  _____|_____|_____\n       %c  |  %c  |  %c  \n  2  _____|_____|_____\n       %c  |  %C  |  %c  \n  3       |     |     \n"
,number[0][0],number[0][1],number[0][2],number[1][0],number[1][1],number[1][2],number[2][0],number[2][1],number[2][2]);
result= res(number,t,size,f,quan,cha,i,result);  
 if(result==1 || result==0){
 	goto out;}else{
 		result=-1;goto out;
	 } }
}else{goto back;}
out:
printf("\n���ξ�������Ϊ��\n");
 //�����ж�ʤ�� 
 if(result==0){
  printf("\tȦӮ\n"); 
 }else if(result==1){
  printf("\t��Ӯ\n"); 
 }else if(result==-1){
 printf("\tƽ��\n");} 
system("pause");//ͣ�� 
menu:
printf("��ѡ������һ�֣����� 1 ����رմ��ڣ����� 0  ��");
int e;
scanf("%d",&e) ;
if(e==1) {
	goto begin;
}else if(e==0){
	return 0;
}
else if(e!=0 && e!=1){
	goto menu;
}
return 0;
}
//result���� 
int res(char number[3][3],int t,int size,int f,int quan,int cha,int i,int result){
	
	//����� 
 for(t=0;t<size;t++){
 	f=t;
  quan=cha=0;
  for(i=0;i<size;i++){
  if(number[t][i]=='O'){
   quan++;
  }else if(number[t][i]=='X'){cha++;
  }} 
  if(quan==size){
  result=0;
  goto out;
 }else if(cha==size){
  result=1;
  goto out;
 }t=f;} 
  
  //����� 
   for(i=0;i<size;i++){
   	f=i;
  quan=cha=0;
  for(t=0;t<size;t++){
  if(number[t][i]=='O'){
   quan++;
  }else if(number[t][i]=='X'){cha++;
  }}if(quan==size){
  result=0;
  goto out;
 }else if(cha==size){
  result=1;
 goto out;
 }i=f;}
  
  //������Խ��� 
  quan=cha=0;
 for(t=0;t<size;t++) {
  if(number[t][t]=='O'){
   quan++;
  }else if(number[t][t]=='X'){
   cha++;
  }}
  if(quan==size){
  result=0;
  goto out;
 }else if(cha==size){
  result=1;
  goto out;}
 
  //��鷴�Խ��� 
  quan=cha=0;
  for(t=0;t<size;t++){
   if(number[t][size-t-1]=='O'){
    quan++; 
   }else if(number[t][size-t-1]=='X'){
    cha++;
   }}
   
   //�ж�ʤ�� 
  if(quan==size){
  result=0;
  goto out;
 }else if(cha==size){
  result=1;
  goto out;
 }
 out:
 	return result;
}
