#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SIZE 9

struct result{
	int i;
	int j;
	char a;
};

typedef struct result Struct;

int huihe;
int jicangji,jitouji,jiyiji,jiweiji;
int jicangai,jitouai,jiyiai,jiweiai;

void guize(char *shili);//��ӡ���� 
void printji(char *ji);//��ӡ�����ɻ� 
void printai(char *ai);//��ӡAI�ɻ� 
void printaiyu(char *aiyu);//��ӡAI�����򣨲��ɼ��� 
void printexample(char *zuobiao);//��ӡʾ�� 
void example(char *zuobiao);//�ɻ���ʾ�� 
void feiji(char *ji);//�����ͷ��β�����Ա���lunkuo������ӡ���ɻ����� 
void aifeiji(char*ai,char *aiyu);//����������ó�AI�ķɻ�λ�� 
void lunkuo(char *feiji,int a,int b,int c,int d,int e);//��ӡ�ɻ������� 
int xingdongji(char *ji,char *ai,char *aiyu);//��¼�������ж� 
int xingdongai(char *ai,char *ji);//��¼AI���ж� 
void yidong(char *dong,int a);//���зɻ����ƶ� 
void hongzhaji(char *zuobiao,int x,int y);//���к�ը 
Struct hongzhaai(char *zuobiao,int x,int y);//���к�ը 


int max(int a,int b){
	return a>=b?a:b;
}
int min(int a,int b){
	return a>b?b:a;
}

int main(){
	srand(time(NULL));
	char ji[SIZE][SIZE],ai[SIZE][SIZE],shili[SIZE][SIZE],aiyu[SIZE][SIZE];
	int i,j;int res1=0,res2=0;
	int jieshu;
		LOOP:
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			ji[i][j]=' ';
			ai[i][j]=' ';
			shili[i][j]=' ';
			aiyu[i][j]=' ';
		}
	} guize((char *)shili);
	feiji((char *)ji);
	aifeiji((char*)ai,(char *)aiyu);
system("pause");
jicangji=0;jitouji=0;jiyiji=0,jiweiji=0;
jicangai=0;jitouai=0;jiyiai=0,jiweiai=0;
for(huihe=0;huihe<100;huihe++){
res1=xingdongji((char *)ji,(char *)ai,(char *)aiyu);
if(res1==1)break;
res2=xingdongai((char *)ai,(char *)ji);	
if(res2==1)break;
printf("\n\n�غϽ���\n\n��������ͼ��ͼ��ʾ��\n");
printji((char *)ji);
	printf("�Է�����ͼ��ͼ��ʾ��\n");
	printai((char *)aiyu);
}
printf("����ս��Ϊ��\n\n��������ͼ��ͼ��ʾ��\n");
printji((char *)ji);
printf("�Է�����ͼ��ͼ��ʾ��\n");
	printai((char *)ai);
	if(res1==1)printf("������ʤ\n");
else if(res2==1)printf("AI��ʤ\n");
system("pause");
LOOP2:
printf("��ѡ�� 1.����һ��  2.��������\n") ;
scanf("%d",&jieshu);
if(jieshu==1)goto LOOP;
else if(jieshu==2)return 0;
else goto LOOP2;
} 

void guize(char *shili){
	printf("�������£�\n ը�ٻ�����Ϸ������ը����β��ը����ֹͣһ�غϵ�������\n") ;
	printf(" ը������ɻ�����ը�ķ���ƫ��һ��ը����ͷ���޷��ƶ���ը������������Ч����\n"); 
	printf("ÿ�غ�˫������һ���ƶ����ᣨ�������һ򲻶�����һ��������ᣨָ�����꣩��\n");
	printf("�ɻ���ʾ����ʾ��\n\n");
	printf("    *��ͷ\n  *****������ջ���\n    *����\n    *����\n   ***��β\n\n "); 
	printf("(��)��ʾ��ĿպͶԷ���δ֪����*��ʾ��õĻ���\n");
	printf(" +��ʾ˫����ը������,#��ʾ��ը�Ļ���\n"); 
	printf("ע�⣺ �Է��Ⱥ�ը�����ƶ�\n");
	printf("����������ɻ�ͷ�ͷɻ�β������\n ������3 3 3 7,�ɻ�λ�ý���:\n");
	example((char *)shili);
	printf("ע�⣺��������ȷ�����꣬���ⱨ��(���꺬��Ϊ�ڼ��еڼ���)\n\n\n") ;
}

void printexample(char *bai){
		int i,j;int zuobiao[9];
for(i=0;i<SIZE;i++){zuobiao[i]=i+1;}
printf("0 1 2 3 4 5 6 7 8 9\n");
	for(i=0;i<SIZE;i++){
		printf("%d ",zuobiao[i]);
		for(j=0;j<SIZE;j++){
			printf("%c ",*(bai+SIZE*i+j));
		}printf("\n");
	}
}

void example(char *zuobiao){
*(zuobiao+SIZE*2+2)='*';*(zuobiao+SIZE*3+2)='*';
*(zuobiao+SIZE*4+2)='*';*(zuobiao+SIZE*5+2)='*';
*(zuobiao+SIZE*6+2)='*';*(zuobiao+SIZE*3+0)='*';
*(zuobiao+SIZE*3+1)='*';*(zuobiao+SIZE*3+3)='*';
*(zuobiao+SIZE*3+4)='*';*(zuobiao+SIZE*6+1)='*';
*(zuobiao+SIZE*6+3)='*';
printexample((char *)zuobiao);
}

void printji(char *hei){
	int i,j;int zuobiao[9];
for(i=0;i<SIZE;i++){zuobiao[i]=i+1;}
printf("0 1 2 3 4 5 6 7 8 9\n");
	for(i=0;i<SIZE;i++){
		printf("%d ",zuobiao[i]);
		for(j=0;j<SIZE;j++){
			printf("%c ",*(hei+SIZE*i+j));
		}printf("\n");
	}printf("\n");
}

void printai(char *bai){
		int i,j;int zuobiao[9];
for(i=0;i<SIZE;i++){zuobiao[i]=i+1;}
printf("0 1 2 3 4 5 6 7 8 9\n");
	for(i=0;i<SIZE;i++){
		printf("%d ",zuobiao[i]);
		for(j=0;j<SIZE;j++){
			printf("%c ",*(bai+SIZE*i+j));
		}printf("\n");
	}printf("\n");
}

void lunkuo(char *feiji,int a,int b,int c,int d,int e){
	if(a-c==4){
			*(feiji+SIZE*c+d)='*';*(feiji+SIZE*a+d)='*';
		*(feiji+SIZE*(c+3)+d)='*';*(feiji+SIZE*(c+2)+d)='*';
		*(feiji+SIZE*(c+1)+d)='*';*(feiji+SIZE*(c+3)+d-2)='*';
		*(feiji+SIZE*(c+3)+d-1)='*';*(feiji+SIZE*(c+3)+d+1)='*';
		*(feiji+SIZE*(c+3)+d+2)='*';*(feiji+SIZE*c+d-1)='*';
		*(feiji+SIZE*c+d+1)='*';
	}
	else if(c-a==4){
		*(feiji+SIZE*a+b)='*';*(feiji+SIZE*c+b)='*';
		*(feiji+SIZE*(a+1)+b)='*';*(feiji+SIZE*(a+2)+b)='*';
		*(feiji+SIZE*(a+3)+b)='*';*(feiji+SIZE*(a+1)+b-2)='*';
		*(feiji+SIZE*(a+1)+b-1)='*';*(feiji+SIZE*(a+1)+b+1)='*';
		*(feiji+SIZE*(a+1)+b+2)='*';*(feiji+SIZE*c+b-1)='*';
		*(feiji+SIZE*c+b+1)='*';
	}
	else if(b-d==4){
			*(feiji+SIZE*c+d)='*';*(feiji+SIZE*c+b)='*';
		*(feiji+SIZE*c+d+1)='*';*(feiji+SIZE*c+d+2)='*';
		*(feiji+SIZE*c+d+3)='*';*(feiji+SIZE*(c-2)+d+3)='*';
		*(feiji+SIZE*(c-1)+d+3)='*';*(feiji+SIZE*(c+1)+d+3)='*';
		*(feiji+SIZE*(c+2)+d+3)='*';*(feiji+SIZE*(a-1)+d)='*';
		*(feiji+SIZE*(a+1)+d)='*';
	}
	else if(d-b==4){
			*(feiji+SIZE*a+b)='*';*(feiji+SIZE*c+d)='*';
		*(feiji+SIZE*a+b+1)='*';*(feiji+SIZE*a+b+2)='*';
		*(feiji+SIZE*a+b+3)='*';*(feiji+SIZE*(a-2)+b+1)='*';
		*(feiji+SIZE*(a-1)+b+1)='*';*(feiji+SIZE*(a+1)+b+1)='*';
		*(feiji+SIZE*(a+2)+b+1)='*';*(feiji+SIZE*(c-1)+d)='*';
		*(feiji+SIZE*(c+1)+d)='*';
	}if(e==0)printji((char *)feiji);
}

void feiji(char *ji){
	int a,b,c,d;
	printf("�������ͷ�ͻ�β�����꣨�磺3 3 3 7��\n");
	LOOP:
	scanf("%d %d %d %d",&a,&b,&c,&d);fflush(stdin);
	if((fabs(a-c)!=4&&fabs(b-d)!=4)||
	max(a,max(b,max(c,d)))>9||
	min(a,min(b,min(c,d)))<1){
		printf("�����������������\n");
		goto LOOP;
	}else if(a==c&&(a<3||a>7)){printf("�����������������\n");goto LOOP;}
	else if(b==d&&(b<3||b>7)){printf("�����������������\n");goto LOOP;}
		printf("��������ͼ��ͼ��ʾ��\n");
	lunkuo((char *)ji,a-1,b-1,c-1,d-1,0);
}

void aifeiji(char*ai,char *aiyu){
		int a,b,c,d;
	LOOP:
		a=rand()%9+1,b=rand()%9+1,c=rand()%9+1,d=rand()%9+1;
	if(	max(a,max(b,max(c,d)))>9||
	min(a,min(b,min(c,d)))<1){goto LOOP;}
	else if(a==c&&(a<3||a>7)){goto LOOP;}
	else if(b==d&&(b<3||b>7)){goto LOOP;}
	else if(fabs(a-c)==4&&b==d||fabs(b-d)==4&&c==a){
	printf("�Է�����ͼ��ͼ��ʾ��\n");}
	else goto LOOP;
	lunkuo((char *)ai,a-1,b-1,c-1,d-1,1);
	printai((char *)aiyu);
}

void yidong(char *dong,int a){
	int i,j;
	if(a==1){
		for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
				if(*(dong+SIZE*i+j)=='*'||*(dong+SIZE*i+j)=='#')
		*(dong+SIZE*i+j)=' ';
		if(i!=8){
		if(*(dong+SIZE*(i+1)+j)!='+'&&*(dong+SIZE*(i+1)+j)!=' ')
		*(dong+SIZE*i+j)=*(dong+SIZE*(i+1)+j);}
		}
	}
	}
	else if(a==2){
		for(i=SIZE-1;i>=0;i--){
		for(j=SIZE-1;j>=0;j--){
				if(*(dong+SIZE*i+j)=='*'||*(dong+SIZE*i+j)=='#')
		*(dong+SIZE*i+j)=' ';
				if(i!=0){
				if(*(dong+SIZE*(i-1)+j)!='+'&&*(dong+SIZE*(i-1)+j)!=' ')
		*(dong+SIZE*i+j)=*(dong+SIZE*(i-1)+j);}
		}
	}
	}
	else if(a==3){
		for(j=0;j<SIZE;j++){
		for(i=0;i<SIZE;i++){
					if(*(dong+SIZE*i+j)=='*'||*(dong+SIZE*i+j)=='#')
		*(dong+SIZE*i+j)=' ';
		if(j!=8){
		if(*(dong+SIZE*i+j+1)!='+'&&*(dong+SIZE*i+j+1)!=' ')
		*(dong+SIZE*i+j)=*(dong+SIZE*i+j+1);}
		}
	}
	}
	else if(a==4){
		for(j=SIZE-1;j>=0;j--){
		for(i=SIZE-1;i>=0;i--){
				if(*(dong+SIZE*i+j)=='*'||*(dong+SIZE*i+j)=='#')
		*(dong+SIZE*i+j)=' ';	
			if(j!=0){
			if(*(dong+SIZE*i+j-1)!='+'&&*(dong+SIZE*i+j-1)!=' ')
		*(dong+SIZE*i+j)=*(dong+SIZE*i+j-1);}
		}
	}
	}
}

void hongzhaji(char *zuobiao,int x,int y){
	if(*(zuobiao+SIZE*x+y)=='*'){
	*(zuobiao+SIZE*x+y)='#';
	if((*(zuobiao+SIZE*x+y-1)=='#'||*(zuobiao+SIZE*x+y-1)=='*')&&(*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')//���� 
	&&(*(zuobiao+SIZE*x+y+1)=='#'||*(zuobiao+SIZE*x+y+1)=='*')&&(*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*'))
	jicangji=1;
	
	else if((*(zuobiao+SIZE*(x-2)+y-1)=='#'||*(zuobiao+SIZE*(x-2)+y-1)=='*')&&(*(zuobiao+SIZE*(x-1)+y-1)=='#'||*(zuobiao+SIZE*(x-1)+y-1)=='*')//��ͷ 
	&&(*(zuobiao+SIZE*x+y-1)=='#'||*(zuobiao+SIZE*x+y-1)=='*')&&(*(zuobiao+SIZE*(x+1)+y-1)=='#'||*(zuobiao+SIZE*(x+1)+y-1)=='*')
	&&(*(zuobiao+SIZE*(x+2)+y-1)=='#'||*(zuobiao+SIZE*(x+2)+y-1)=='*'))jitouji=1;
	
		else if((*(zuobiao+SIZE*(x-2)+y+1)=='#'||*(zuobiao+SIZE*(x-2)+y+1)=='*')&&(*(zuobiao+SIZE*(x-1)+y+1)=='#'||*(zuobiao+SIZE*(x-1)+y+1)=='*')//��ͷ 
	&&(*(zuobiao+SIZE*x+y+1)=='#'||*(zuobiao+SIZE*x+y+1)=='*')&&(*(zuobiao+SIZE*(x+1)+y+1)=='#'||*(zuobiao+SIZE*(x+1)+y+1)=='*')
	&&(*(zuobiao+SIZE*(x+2)+y+1)=='#'||*(zuobiao+SIZE*(x+2)+y+1)=='*'))jitouji=1;
	
		else if((*(zuobiao+SIZE*(x-1)+y-2)=='#'||*(zuobiao+SIZE*(x-1)+y-2)=='*')&&(*(zuobiao+SIZE*(x-1)+y-1)=='#'||*(zuobiao+SIZE*(x-1)+y-1)=='*')//��ͷ 
	&&(*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+y+1)=='#'||*(zuobiao+SIZE*(x-1)+y+1)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y+2)=='#'||*(zuobiao+SIZE*(x-1)+y+2)=='*'))jitouji=1;
	
		else if((*(zuobiao+SIZE*(x+1)+y-2)=='#'||*(zuobiao+SIZE*(x+1)+y-2)=='*')&&(*(zuobiao+SIZE*(x+1)+y-1)=='#'||*(zuobiao+SIZE*(x+1)+y-1)=='*')//��ͷ 
	&&(*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*')&&(*(zuobiao+SIZE*(x+1)+y+1)=='#'||*(zuobiao+SIZE*(x+1)+y+1)=='*')
	&&(*(zuobiao+SIZE*(x+1)+y+2)=='#'||*(zuobiao+SIZE*(x+1)+y+2)=='*'))jitouji=1;
	
		else if((*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*')&&(*(zuobiao+SIZE*(x+1)+y-1)=='#'||*(zuobiao+SIZE*(x+1)+y-1)=='*')//��β 
	&&(*(zuobiao+SIZE*(x+1)+y-2)=='#'||*(zuobiao+SIZE*(x+1)+y-2)=='*')&&(*(zuobiao+SIZE*(x+1)+y-3)=='#'||*(zuobiao+SIZE*(x+1)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x+1)+y-4)=='#'||*(zuobiao+SIZE*(x+1)+y-4)=='*'))jiweiji=1;
	
		else if((*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*')&&(*(zuobiao+SIZE*(x+1)+y+1)=='#'||*(zuobiao+SIZE*(x+1)+y+1)=='*')//��β 
	&&(*(zuobiao+SIZE*(x+1)+y+2)=='#'||*(zuobiao+SIZE*(x+1)+y+2)=='*')&&(*(zuobiao+SIZE*(x+1)+y+3)=='#'||*(zuobiao+SIZE*(x+1)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x+1)+y+4)=='#'||*(zuobiao+SIZE*(x+1)+y+4)=='*'))jiweiji=1;
	
		else if((*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+y-1)=='#'||*(zuobiao+SIZE*(x-1)+y-1)=='*')//��β 
	&&(*(zuobiao+SIZE*(x-1)+y-2)=='#'||*(zuobiao+SIZE*(x-1)+y-2)=='*')&&(*(zuobiao+SIZE*(x+1)+y-3)=='#'||*(zuobiao+SIZE*(x-1)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y-4)=='#'||*(zuobiao+SIZE*(x-1)+y-4)=='*'))jiweiji=1;
	
	else if((*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+y+1)=='#'||*(zuobiao+SIZE*(x-1)+y+1)=='*')//��β 
	&&(*(zuobiao+SIZE*(x-1)+y+2)=='#'||*(zuobiao+SIZE*(x-1)+y+2)=='*')&&(*(zuobiao+SIZE*(x+1)+y+3)=='#'||*(zuobiao+SIZE*(x-1)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y+4)=='#'||*(zuobiao+SIZE*(x-1)+y+4)=='*'))jiweiji=1;
	
		else if((*(zuobiao+SIZE*(y+1)+x)=='#'||*(zuobiao+SIZE*(y+1)+x)=='*')&&(*(zuobiao+SIZE*(y+1)+x-1)=='#'||*(zuobiao+SIZE*(y+1)+x-1)=='*')//��β 
	&&(*(zuobiao+SIZE*(y+1)+x-2)=='#'||*(zuobiao+SIZE*(y+1)+x-2)=='*')&&(*(zuobiao+SIZE*(y+1)+x-3)=='#'||*(zuobiao+SIZE*(y+1)+x-3)=='*')
	&&(*(zuobiao+SIZE*(y+1)+x-4)=='#'||*(zuobiao+SIZE*(y+1)+x-4)=='*'))jiweiji=1;
	
		else if((*(zuobiao+SIZE*(y+1)+x)=='#'||*(zuobiao+SIZE*(x+1)+x)=='*')&&(*(zuobiao+SIZE*(y+1)+x+1)=='#'||*(zuobiao+SIZE*(y+1)+x+1)=='*')//��β 
	&&(*(zuobiao+SIZE*(y+1)+x+2)=='#'||*(zuobiao+SIZE*(y+1)+x+2)=='*')&&(*(zuobiao+SIZE*(y+1)+x+3)=='#'||*(zuobiao+SIZE*(y+1)+x+3)=='*')
	&&(*(zuobiao+SIZE*(y+1)+x+4)=='#'||*(zuobiao+SIZE*(y+1)+x+4)=='*'))jiweiji=1;
	
		else if((*(zuobiao+SIZE*(y-1)+x)=='#'||*(zuobiao+SIZE*(x-1)+x)=='*')&&(*(zuobiao+SIZE*(y-1)+x-1)=='#'||*(zuobiao+SIZE*(y-1)+x-1)=='*')//��β 
	&&(*(zuobiao+SIZE*(y-1)+x-2)=='#'||*(zuobiao+SIZE*(y-1)+x-2)=='*')&&(*(zuobiao+SIZE*(y+1)+x-3)=='#'||*(zuobiao+SIZE*(y-1)+x-3)=='*')
	&&(*(zuobiao+SIZE*(y-1)+x-4)=='#'||*(zuobiao+SIZE*(y-1)+x-4)=='*'))jiweiji=1;
	
	else if((*(zuobiao+SIZE*(y-1)+x)=='#'||*(zuobiao+SIZE*(x-1)+x)=='*')&&(*(zuobiao+SIZE*(y-1)+x+1)=='#'||*(zuobiao+SIZE*(y-1)+x+1)=='*')//��β 
	&&(*(zuobiao+SIZE*(y-1)+x+2)=='#'||*(zuobiao+SIZE*(y-1)+x+2)=='*')&&(*(zuobiao+SIZE*(y+1)+x+3)=='#'||*(zuobiao+SIZE*(y-1)+x+3)=='*')
	&&(*(zuobiao+SIZE*(y-1)+x+4)=='#'||*(zuobiao+SIZE*(y-1)+x+4)=='*'))jiweiji=1;
	
		else if((*(zuobiao+SIZE*(y-1)+x)=='#'||*(zuobiao+SIZE*(y-1)+x)=='*')&&(*(zuobiao+SIZE*y+x-1)=='#'||*(zuobiao+SIZE*y+x-1)=='*')//��β�м� 
	&&(*(zuobiao+SIZE*y+x-2)=='#'||*(zuobiao+SIZE*y+x-2)=='*')&&(*(zuobiao+SIZE*y+x-3)=='#'||*(zuobiao+SIZE*y+x-3)=='*')
	&&(*(zuobiao+SIZE*y+x-4)=='#'||*(zuobiao+SIZE*y+x-4)=='*')&&(*(zuobiao+SIZE*(y+1)+x)=='#'||*(zuobiao+SIZE*(y+1)+x)=='*'))jiweiji=1;
	
		else if((*(zuobiao+SIZE*(y-1)+x)=='#'||*(zuobiao+SIZE*(y-1)+x)=='*')&&(*(zuobiao+SIZE*y+x+1)=='#'||*(zuobiao+SIZE*y+x+1)=='*')//��β�м� 
	&&(*(zuobiao+SIZE*y+x+2)=='#'||*(zuobiao+SIZE*y+x+2)=='*')&&(*(zuobiao+SIZE*y+x+3)=='#'||*(zuobiao+SIZE*y+x+3)=='*')
	&&(*(zuobiao+SIZE*y+x+4)=='#'||*(zuobiao+SIZE*y+x+4)=='*')&&(*(zuobiao+SIZE*(y+1)+x)=='#'||*(zuobiao+SIZE*(y+1)+x)=='*'))jiweiji=1;
	
		else if((*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+y-1)=='#'||*(zuobiao+SIZE*(x-1)+y-1)=='*')//��β�м� 
	&&(*(zuobiao+SIZE*(x-1)+y-2)=='#'||*(zuobiao+SIZE*(x-1)+y-2)=='*')&&(*(zuobiao+SIZE*(x+1)+y-3)=='#'||*(zuobiao+SIZE*(x-1)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y-4)=='#'||*(zuobiao+SIZE*(x-1)+y-4)=='*')&&(*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*'))jiweiji=1;
	
	else if((*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+x+1)=='#'||*(zuobiao+SIZE*(x-1)+y+1)=='*')//��β�м� 
	&&(*(zuobiao+SIZE*(x-1)+y+2)=='#'||*(zuobiao+SIZE*(x-1)+y+2)=='*')&&(*(zuobiao+SIZE*(x+1)+x+3)=='#'||*(zuobiao+SIZE*(x-1)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y+4)=='#'||*(zuobiao+SIZE*(x-1)+y+4)=='*')&&(*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*'))jiweiji=1;
	
		else if((*(zuobiao+SIZE*(x-2)+y)=='#'||*(zuobiao+SIZE*(x-2)+y)=='*')&&(*(zuobiao+SIZE*(x-2)+y+1)=='#'||*(zuobiao+SIZE*(x-2)+y+1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(x-2)+y+2)=='#'||*(zuobiao+SIZE*(x-2)+y+2)=='*')&&(*(zuobiao+SIZE*(x-2)+y+3)=='#'||*(zuobiao+SIZE*(x-2)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x-2)+y-1)=='#'||*(zuobiao+SIZE*(x-2)+y-1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,2);}
	
	else if((*(zuobiao+SIZE*(x-2)+y)=='#'||*(zuobiao+SIZE*(x-2)+y)=='*')&&(*(zuobiao+SIZE*(x-2)+y-1)=='#'||*(zuobiao+SIZE*(x-2)+y-1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(x-2)+y-2)=='#'||*(zuobiao+SIZE*(x-2)+y-2)=='*')&&(*(zuobiao+SIZE*(x-2)+y-3)=='#'||*(zuobiao+SIZE*(x-2)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x-2)+y+1)=='#'||*(zuobiao+SIZE*(x-2)+y+1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,2);}
	
	else if((*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+y+1)=='#'||*(zuobiao+SIZE*(x-1)+y+1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(x-1)+y+2)=='#'||*(zuobiao+SIZE*(x-1)+y+2)=='*')&&(*(zuobiao+SIZE*(x-1)+y+3)=='#'||*(zuobiao+SIZE*(x-1)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y-1)=='#'||*(zuobiao+SIZE*(x-1)+y-1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,2);}
	
	else if((*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+y-1)=='#'||*(zuobiao+SIZE*(x-1)+y-1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(x-1)+y-2)=='#'||*(zuobiao+SIZE*(x-1)+y-2)=='*')&&(*(zuobiao+SIZE*(x-1)+y-3)=='#'||*(zuobiao+SIZE*(x-1)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y+1)=='#'||*(zuobiao+SIZE*(x-1)+y+1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,2);}
	
	else if((*(zuobiao+SIZE*(x+2)+y)=='#'||*(zuobiao+SIZE*(x+2)+y)=='*')&&(*(zuobiao+SIZE*(x+2)+y+1)=='#'||*(zuobiao+SIZE*(x+2)+y+1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(x+2)+y+2)=='#'||*(zuobiao+SIZE*(x+2)+y+2)=='*')&&(*(zuobiao+SIZE*(x+2)+y+3)=='#'||*(zuobiao+SIZE*(x+2)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x+2)+y-1)=='#'||*(zuobiao+SIZE*(x+2)+y-1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,1);}
	
	else if((*(zuobiao+SIZE*(x+2)+y)=='#'||*(zuobiao+SIZE*(x+2)+y)=='*')&&(*(zuobiao+SIZE*(x+2)+y-1)=='#'||*(zuobiao+SIZE*(x+2)+y-1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(x+2)+y-2)=='#'||*(zuobiao+SIZE*(x+2)+y-2)=='*')&&(*(zuobiao+SIZE*(x+2)+y-3)=='#'||*(zuobiao+SIZE*(x+2)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x+2)+y+1)=='#'||*(zuobiao+SIZE*(x+2)+y+1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,1);}
	
	else if((*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*')&&(*(zuobiao+SIZE*(x+1)+y+1)=='#'||*(zuobiao+SIZE*(x+1)+y+1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(x+1)+y+2)=='#'||*(zuobiao+SIZE*(x+1)+y+2)=='*')&&(*(zuobiao+SIZE*(x+1)+y+3)=='#'||*(zuobiao+SIZE*(x+1)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x+1)+y-1)=='#'||*(zuobiao+SIZE*(x+1)+y-1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,1);}
	
	else if((*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*')&&(*(zuobiao+SIZE*(x+1)+y-1)=='#'||*(zuobiao+SIZE*(x+1)+y-1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(x+1)+y-2)=='#'||*(zuobiao+SIZE*(x+1)+y-2)=='*')&&(*(zuobiao+SIZE*(x+1)+y-3)=='#'||*(zuobiao+SIZE*(x+1)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x+1)+y+1)=='#'||*(zuobiao+SIZE*(x+1)+y+1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,1);}
	
	else if((*(zuobiao+SIZE*(y-2)+x)=='#'||*(zuobiao+SIZE*(y-2)+x)=='*')&&(*(zuobiao+SIZE*(y-2)+x+1)=='#'||*(zuobiao+SIZE*(y-2)+x+1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(y-2)+x+2)=='#'||*(zuobiao+SIZE*(y-2)+x+2)=='*')&&(*(zuobiao+SIZE*(y-2)+x+3)=='#'||*(zuobiao+SIZE*(y-2)+x+3)=='*')
	&&(*(zuobiao+SIZE*(y-2)+x-1)=='#'||*(zuobiao+SIZE*(y-2)+x-1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,4);}
	
	else if((*(zuobiao+SIZE*(y-2)+x)=='#'||*(zuobiao+SIZE*(y-2)+x)=='*')&&(*(zuobiao+SIZE*(y-2)+x-1)=='#'||*(zuobiao+SIZE*(y-2)+x-1)=='*')//����������
	&&(*(zuobiao+SIZE*(y-2)+x-2)=='#'||*(zuobiao+SIZE*(y-2)+x-2)=='*')&&(*(zuobiao+SIZE*(y-2)+x-3)=='#'||*(zuobiao+SIZE*(y-2)+x-3)=='*')
	&&(*(zuobiao+SIZE*(y-2)+x+1)=='#'||*(zuobiao+SIZE*(y-2)+x+1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,4);}
	
	else if((*(zuobiao+SIZE*(y-1)+x)=='#'||*(zuobiao+SIZE*(y-1)+x)=='*')&&(*(zuobiao+SIZE*(y-1)+x+1)=='#'||*(zuobiao+SIZE*(y-1)+x+1)=='*')//����������
	&&(*(zuobiao+SIZE*(y-1)+x+2)=='#'||*(zuobiao+SIZE*(y-1)+x+2)=='*')&&(*(zuobiao+SIZE*(y-1)+x+3)=='#'||*(zuobiao+SIZE*(y-1)+x+3)=='*')
	&&(*(zuobiao+SIZE*(y-1)+x-1)=='#'||*(zuobiao+SIZE*(y-1)+x-1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,4);}
	
	else if((*(zuobiao+SIZE*(y-1)+x)=='#'||*(zuobiao+SIZE*(y-1)+x)=='*')&&(*(zuobiao+SIZE*(y-1)+x-1)=='#'||*(zuobiao+SIZE*(y-1)+x-1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(y-1)+x-2)=='#'||*(zuobiao+SIZE*(y-1)+x-2)=='*')&&(*(zuobiao+SIZE*(y-1)+x-3)=='#'||*(zuobiao+SIZE*(y-1)+x-3)=='*')
	&&(*(zuobiao+SIZE*(y-1)+x+1)=='#'||*(zuobiao+SIZE*(y-1)+x+1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,4);}
	
	else if((*(zuobiao+SIZE*(y+2)+x)=='#'||*(zuobiao+SIZE*(y+2)+x)=='*')&&(*(zuobiao+SIZE*(y+2)+x+1)=='#'||*(zuobiao+SIZE*(y+2)+x+1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(y+2)+x+2)=='#'||*(zuobiao+SIZE*(y+2)+x+2)=='*')&&(*(zuobiao+SIZE*(y+2)+x+3)=='#'||*(zuobiao+SIZE*(y+2)+x+3)=='*')
	&&(*(zuobiao+SIZE*(y+2)+x-1)=='#'||*(zuobiao+SIZE*(y+2)+x-1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,3);}
	
	else if((*(zuobiao+SIZE*(y+2)+x)=='#'||*(zuobiao+SIZE*(y+2)+x)=='*')&&(*(zuobiao+SIZE*(y+2)+x-1)=='#'||*(zuobiao+SIZE*(y+2)+x-1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(y+2)+x-2)=='#'||*(zuobiao+SIZE*(y+2)+x-2)=='*')&&(*(zuobiao+SIZE*(y+2)+x-3)=='#'||*(zuobiao+SIZE*(y+2)+x-3)=='*')
	&&(*(zuobiao+SIZE*(y+2)+x+1)=='#'||*(zuobiao+SIZE*(y+2)+x+1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,3);}
	
	else if((*(zuobiao+SIZE*(y+1)+x)=='#'||*(zuobiao+SIZE*(y+1)+x)=='*')&&(*(zuobiao+SIZE*(y+1)+x+1)=='#'||*(zuobiao+SIZE*(y+1)+x+1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(y+1)+x+2)=='#'||*(zuobiao+SIZE*(y+1)+x+2)=='*')&&(*(zuobiao+SIZE*(y+1)+x+3)=='#'||*(zuobiao+SIZE*(y+1)+x+3)=='*')
	&&(*(zuobiao+SIZE*(y+1)+x-1)=='#'||*(zuobiao+SIZE*(y+1)+x-1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,3);}
	
	else if((*(zuobiao+SIZE*(y+1)+x)=='#'||*(zuobiao+SIZE*(y+1)+x)=='*')&&(*(zuobiao+SIZE*(y+1)+x-1)=='#'||*(zuobiao+SIZE*(y+1)+x-1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(y+1)+x-2)=='#'||*(zuobiao+SIZE*(y+1)+x-2)=='*')&&(*(zuobiao+SIZE*(y+1)+x-3)=='#'||*(zuobiao+SIZE*(y+1)+x-3)=='*')
	&&(*(zuobiao+SIZE*(y+1)+x+1)=='#'||*(zuobiao+SIZE*(y+1)+x+1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,3);}
}

	else if(*(zuobiao+SIZE*x+y)==' ')*(zuobiao+SIZE*x+y)='+';
	else if(*(zuobiao+SIZE*x+y)=='+'){}
	else if(*(zuobiao+SIZE*x+y)=='#'){}
}

Struct hongzhaai(char *zuobiao,int x,int y){
	if(*(zuobiao+SIZE*x+y)=='*'){
	*(zuobiao+SIZE*x+y)='#';
	if((*(zuobiao+SIZE*x+y-1)=='#'||*(zuobiao+SIZE*x+y-1)=='*')&&(*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')//���� 
	&&(*(zuobiao+SIZE*x+y+1)=='#'||*(zuobiao+SIZE*x+y+1)=='*')&&(*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*'))
	jicangai=1;
	
	else if((*(zuobiao+SIZE*(x-2)+y-1)=='#'||*(zuobiao+SIZE*(x-2)+y-1)=='*')&&(*(zuobiao+SIZE*(x-1)+y-1)=='#'||*(zuobiao+SIZE*(x-1)+y-1)=='*')//��ͷ 
	&&(*(zuobiao+SIZE*x+y-1)=='#'||*(zuobiao+SIZE*x+y-1)=='*')&&(*(zuobiao+SIZE*(x+1)+y-1)=='#'||*(zuobiao+SIZE*(x+1)+y-1)=='*')
	&&(*(zuobiao+SIZE*(x+2)+y-1)=='#'||*(zuobiao+SIZE*(x+2)+y-1)=='*'))jitouai=1;
	
		else if((*(zuobiao+SIZE*(x-2)+y+1)=='#'||*(zuobiao+SIZE*(x-2)+y+1)=='*')&&(*(zuobiao+SIZE*(x-1)+y+1)=='#'||*(zuobiao+SIZE*(x-1)+y+1)=='*')//��ͷ 
	&&(*(zuobiao+SIZE*x+y+1)=='#'||*(zuobiao+SIZE*x+y+1)=='*')&&(*(zuobiao+SIZE*(x+1)+y+1)=='#'||*(zuobiao+SIZE*(x+1)+y+1)=='*')
	&&(*(zuobiao+SIZE*(x+2)+y+1)=='#'||*(zuobiao+SIZE*(x+2)+y+1)=='*'))jitouai=1;
	
		else if((*(zuobiao+SIZE*(x-1)+y-2)=='#'||*(zuobiao+SIZE*(x-1)+y-2)=='*')&&(*(zuobiao+SIZE*(x-1)+y-1)=='#'||*(zuobiao+SIZE*(x-1)+y-1)=='*')//��ͷ 
	&&(*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+y+1)=='#'||*(zuobiao+SIZE*(x-1)+y+1)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y+2)=='#'||*(zuobiao+SIZE*(x-1)+y+2)=='*'))jitouai=1;
	
		else if((*(zuobiao+SIZE*(x+1)+y-2)=='#'||*(zuobiao+SIZE*(x+1)+y-2)=='*')&&(*(zuobiao+SIZE*(x+1)+y-1)=='#'||*(zuobiao+SIZE*(x+1)+y-1)=='*')//��ͷ 
	&&(*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*')&&(*(zuobiao+SIZE*(x+1)+y+1)=='#'||*(zuobiao+SIZE*(x+1)+y+1)=='*')
	&&(*(zuobiao+SIZE*(x+1)+y+2)=='#'||*(zuobiao+SIZE*(x+1)+y+2)=='*'))jitouai=1;
	
		else if((*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*')&&(*(zuobiao+SIZE*(x+1)+y-1)=='#'||*(zuobiao+SIZE*(x+1)+y-1)=='*')//��β 
	&&(*(zuobiao+SIZE*(x+1)+y-2)=='#'||*(zuobiao+SIZE*(x+1)+y-2)=='*')&&(*(zuobiao+SIZE*(x+1)+y-3)=='#'||*(zuobiao+SIZE*(x+1)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x+1)+y-4)=='#'||*(zuobiao+SIZE*(x+1)+y-4)=='*'))jiweiai=1;
	
		else if((*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*')&&(*(zuobiao+SIZE*(x+1)+y+1)=='#'||*(zuobiao+SIZE*(x+1)+y+1)=='*')//��β 
	&&(*(zuobiao+SIZE*(x+1)+y+2)=='#'||*(zuobiao+SIZE*(x+1)+y+2)=='*')&&(*(zuobiao+SIZE*(x+1)+y+3)=='#'||*(zuobiao+SIZE*(x+1)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x+1)+y+4)=='#'||*(zuobiao+SIZE*(x+1)+y+4)=='*'))jiweiai=1;
	
		else if((*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+y-1)=='#'||*(zuobiao+SIZE*(x-1)+y-1)=='*')//��β 
	&&(*(zuobiao+SIZE*(x-1)+y-2)=='#'||*(zuobiao+SIZE*(x-1)+y-2)=='*')&&(*(zuobiao+SIZE*(x+1)+y-3)=='#'||*(zuobiao+SIZE*(x-1)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y-4)=='#'||*(zuobiao+SIZE*(x-1)+y-4)=='*'))jiweiai=1;
	
	else if((*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+y+1)=='#'||*(zuobiao+SIZE*(x-1)+y+1)=='*')//��β 
	&&(*(zuobiao+SIZE*(x-1)+y+2)=='#'||*(zuobiao+SIZE*(x-1)+y+2)=='*')&&(*(zuobiao+SIZE*(x+1)+y+3)=='#'||*(zuobiao+SIZE*(x-1)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y+4)=='#'||*(zuobiao+SIZE*(x-1)+y+4)=='*'))jiweiai=1;
	
	else if((*(zuobiao+SIZE*(y+1)+x)=='#'||*(zuobiao+SIZE*(y+1)+x)=='*')&&(*(zuobiao+SIZE*(y+1)+x-1)=='#'||*(zuobiao+SIZE*(y+1)+x-1)=='*')//��β 
	&&(*(zuobiao+SIZE*(y+1)+x-2)=='#'||*(zuobiao+SIZE*(y+1)+x-2)=='*')&&(*(zuobiao+SIZE*(y+1)+x-3)=='#'||*(zuobiao+SIZE*(y+1)+x-3)=='*')
	&&(*(zuobiao+SIZE*(y+1)+x-4)=='#'||*(zuobiao+SIZE*(y+1)+x-4)=='*'))jiweiai=1;
	
		else if((*(zuobiao+SIZE*(y+1)+x)=='#'||*(zuobiao+SIZE*(x+1)+x)=='*')&&(*(zuobiao+SIZE*(y+1)+x+1)=='#'||*(zuobiao+SIZE*(y+1)+x+1)=='*')//��β 
	&&(*(zuobiao+SIZE*(y+1)+x+2)=='#'||*(zuobiao+SIZE*(y+1)+x+2)=='*')&&(*(zuobiao+SIZE*(y+1)+x+3)=='#'||*(zuobiao+SIZE*(y+1)+x+3)=='*')
	&&(*(zuobiao+SIZE*(y+1)+x+4)=='#'||*(zuobiao+SIZE*(y+1)+x+4)=='*'))jiweiai=1;
	
		else if((*(zuobiao+SIZE*(y-1)+x)=='#'||*(zuobiao+SIZE*(x-1)+x)=='*')&&(*(zuobiao+SIZE*(y-1)+x-1)=='#'||*(zuobiao+SIZE*(y-1)+x-1)=='*')//��β 
	&&(*(zuobiao+SIZE*(y-1)+x-2)=='#'||*(zuobiao+SIZE*(y-1)+x-2)=='*')&&(*(zuobiao+SIZE*(y+1)+x-3)=='#'||*(zuobiao+SIZE*(y-1)+x-3)=='*')
	&&(*(zuobiao+SIZE*(y-1)+x-4)=='#'||*(zuobiao+SIZE*(y-1)+x-4)=='*'))jiweiai=1;
	
	else if((*(zuobiao+SIZE*(y-1)+x)=='#'||*(zuobiao+SIZE*(x-1)+x)=='*')&&(*(zuobiao+SIZE*(y-1)+x+1)=='#'||*(zuobiao+SIZE*(y-1)+x+1)=='*')//��β 
	&&(*(zuobiao+SIZE*(y-1)+x+2)=='#'||*(zuobiao+SIZE*(y-1)+x+2)=='*')&&(*(zuobiao+SIZE*(y+1)+x+3)=='#'||*(zuobiao+SIZE*(y-1)+x+3)=='*')
	&&(*(zuobiao+SIZE*(y-1)+x+4)=='#'||*(zuobiao+SIZE*(y-1)+x+4)=='*'))jiweiai=1;
	
		else if((*(zuobiao+SIZE*(y-1)+x)=='#'||*(zuobiao+SIZE*(y-1)+x)=='*')&&(*(zuobiao+SIZE*y+x-1)=='#'||*(zuobiao+SIZE*y+x-1)=='*')//��β�м� 
	&&(*(zuobiao+SIZE*y+x-2)=='#'||*(zuobiao+SIZE*y+x-2)=='*')&&(*(zuobiao+SIZE*y+x-3)=='#'||*(zuobiao+SIZE*y+x-3)=='*')
	&&(*(zuobiao+SIZE*y+x-4)=='#'||*(zuobiao+SIZE*y+x-4)=='*')&&(*(zuobiao+SIZE*(y+1)+x)=='#'||*(zuobiao+SIZE*(y+1)+x)=='*'))jiweiai=1;
	
		else if((*(zuobiao+SIZE*(y-1)+x)=='#'||*(zuobiao+SIZE*(y-1)+x)=='*')&&(*(zuobiao+SIZE*y+x+1)=='#'||*(zuobiao+SIZE*y+x+1)=='*')//��β�м� 
	&&(*(zuobiao+SIZE*y+x+2)=='#'||*(zuobiao+SIZE*y+x+2)=='*')&&(*(zuobiao+SIZE*y+x+3)=='#'||*(zuobiao+SIZE*y+x+3)=='*')
	&&(*(zuobiao+SIZE*y+x+4)=='#'||*(zuobiao+SIZE*y+x+4)=='*')&&(*(zuobiao+SIZE*(y+1)+x)=='#'||*(zuobiao+SIZE*(y+1)+x)=='*'))jiweiai=1;
	
		else if((*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+y-1)=='#'||*(zuobiao+SIZE*(x-1)+y-1)=='*')//��β�м� 
	&&(*(zuobiao+SIZE*(x-1)+y-2)=='#'||*(zuobiao+SIZE*(x-1)+y-2)=='*')&&(*(zuobiao+SIZE*(x+1)+y-3)=='#'||*(zuobiao+SIZE*(x-1)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y-4)=='#'||*(zuobiao+SIZE*(x-1)+y-4)=='*')&&(*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*'))jiweiai=1;
	
	else if((*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+x+1)=='#'||*(zuobiao+SIZE*(x-1)+y+1)=='*')//��β�м� 
	&&(*(zuobiao+SIZE*(x-1)+y+2)=='#'||*(zuobiao+SIZE*(x-1)+y+2)=='*')&&(*(zuobiao+SIZE*(x+1)+x+3)=='#'||*(zuobiao+SIZE*(x-1)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y+4)=='#'||*(zuobiao+SIZE*(x-1)+y+4)=='*')&&(*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*'))jiweiai=1;
	
	else if((*(zuobiao+SIZE*(x-2)+y)=='#'||*(zuobiao+SIZE*(x-2)+y)=='*')&&(*(zuobiao+SIZE*(x-2)+y+1)=='#'||*(zuobiao+SIZE*(x-2)+y+1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(x-2)+y+2)=='#'||*(zuobiao+SIZE*(x-2)+y+2)=='*')&&(*(zuobiao+SIZE*(x-2)+y+3)=='#'||*(zuobiao+SIZE*(x-2)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x-2)+y-1)=='#'||*(zuobiao+SIZE*(x-2)+y-1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,2);}
	
	else if((*(zuobiao+SIZE*(x-2)+y)=='#'||*(zuobiao+SIZE*(x-2)+y)=='*')&&(*(zuobiao+SIZE*(x-2)+y-1)=='#'||*(zuobiao+SIZE*(x-2)+y-1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(x-2)+y-2)=='#'||*(zuobiao+SIZE*(x-2)+y-2)=='*')&&(*(zuobiao+SIZE*(x-2)+y-3)=='#'||*(zuobiao+SIZE*(x-2)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x-2)+y+1)=='#'||*(zuobiao+SIZE*(x-2)+y+1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,2);}
	
	else if((*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+y+1)=='#'||*(zuobiao+SIZE*(x-1)+y+1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(x-1)+y+2)=='#'||*(zuobiao+SIZE*(x-1)+y+2)=='*')&&(*(zuobiao+SIZE*(x-1)+y+3)=='#'||*(zuobiao+SIZE*(x-1)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y-1)=='#'||*(zuobiao+SIZE*(x-1)+y-1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,2);}
	
	else if((*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+y-1)=='#'||*(zuobiao+SIZE*(x-1)+y-1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(x-1)+y-2)=='#'||*(zuobiao+SIZE*(x-1)+y-2)=='*')&&(*(zuobiao+SIZE*(x-1)+y-3)=='#'||*(zuobiao+SIZE*(x-1)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y+1)=='#'||*(zuobiao+SIZE*(x-1)+y+1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,2);}
	
	else if((*(zuobiao+SIZE*(x+2)+y)=='#'||*(zuobiao+SIZE*(x+2)+y)=='*')&&(*(zuobiao+SIZE*(x+2)+y+1)=='#'||*(zuobiao+SIZE*(x+2)+y+1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(x+2)+y+2)=='#'||*(zuobiao+SIZE*(x+2)+y+2)=='*')&&(*(zuobiao+SIZE*(x+2)+y+3)=='#'||*(zuobiao+SIZE*(x+2)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x+2)+y-1)=='#'||*(zuobiao+SIZE*(x+2)+y-1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,1);}
	
	else if((*(zuobiao+SIZE*(x+2)+y)=='#'||*(zuobiao+SIZE*(x+2)+y)=='*')&&(*(zuobiao+SIZE*(x+2)+y-1)=='#'||*(zuobiao+SIZE*(x+2)+y-1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(x+2)+y-2)=='#'||*(zuobiao+SIZE*(x+2)+y-2)=='*')&&(*(zuobiao+SIZE*(x+2)+y-3)=='#'||*(zuobiao+SIZE*(x+2)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x+2)+y+1)=='#'||*(zuobiao+SIZE*(x+2)+y+1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,1);}
	
	else if((*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*')&&(*(zuobiao+SIZE*(x+1)+y+1)=='#'||*(zuobiao+SIZE*(x+1)+y+1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(x+1)+y+2)=='#'||*(zuobiao+SIZE*(x+1)+y+2)=='*')&&(*(zuobiao+SIZE*(x+1)+y+3)=='#'||*(zuobiao+SIZE*(x+1)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x+1)+y-1)=='#'||*(zuobiao+SIZE*(x+1)+y-1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,1);}
	
	else if((*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*')&&(*(zuobiao+SIZE*(x+1)+y-1)=='#'||*(zuobiao+SIZE*(x+1)+y-1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(x+1)+y-2)=='#'||*(zuobiao+SIZE*(x+1)+y-2)=='*')&&(*(zuobiao+SIZE*(x+1)+y-3)=='#'||*(zuobiao+SIZE*(x+1)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x+1)+y+1)=='#'||*(zuobiao+SIZE*(x+1)+y+1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,1);}
	
	else if((*(zuobiao+SIZE*(y-2)+x)=='#'||*(zuobiao+SIZE*(y-2)+x)=='*')&&(*(zuobiao+SIZE*(y-2)+x+1)=='#'||*(zuobiao+SIZE*(y-2)+x+1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(y-2)+x+2)=='#'||*(zuobiao+SIZE*(y-2)+x+2)=='*')&&(*(zuobiao+SIZE*(y-2)+x+3)=='#'||*(zuobiao+SIZE*(y-2)+x+3)=='*')
	&&(*(zuobiao+SIZE*(y-2)+x-1)=='#'||*(zuobiao+SIZE*(y-2)+x-1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,4);}
	
	else if((*(zuobiao+SIZE*(y-2)+x)=='#'||*(zuobiao+SIZE*(y-2)+x)=='*')&&(*(zuobiao+SIZE*(y-2)+x-1)=='#'||*(zuobiao+SIZE*(y-2)+x-1)=='*')//����������
	&&(*(zuobiao+SIZE*(y-2)+x-2)=='#'||*(zuobiao+SIZE*(y-2)+x-2)=='*')&&(*(zuobiao+SIZE*(y-2)+x-3)=='#'||*(zuobiao+SIZE*(y-2)+x-3)=='*')
	&&(*(zuobiao+SIZE*(y-2)+x+1)=='#'||*(zuobiao+SIZE*(y-2)+x+1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,4);}
	
	else if((*(zuobiao+SIZE*(y-1)+x)=='#'||*(zuobiao+SIZE*(y-1)+x)=='*')&&(*(zuobiao+SIZE*(y-1)+x+1)=='#'||*(zuobiao+SIZE*(y-1)+x+1)=='*')//����������
	&&(*(zuobiao+SIZE*(y-1)+x+2)=='#'||*(zuobiao+SIZE*(y-1)+x+2)=='*')&&(*(zuobiao+SIZE*(y-1)+x+3)=='#'||*(zuobiao+SIZE*(y-1)+x+3)=='*')
	&&(*(zuobiao+SIZE*(y-1)+x-1)=='#'||*(zuobiao+SIZE*(y-1)+x-1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,4);}
	
	else if((*(zuobiao+SIZE*(y-1)+x)=='#'||*(zuobiao+SIZE*(y-1)+x)=='*')&&(*(zuobiao+SIZE*(y-1)+x-1)=='#'||*(zuobiao+SIZE*(y-1)+x-1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(y-1)+x-2)=='#'||*(zuobiao+SIZE*(y-1)+x-2)=='*')&&(*(zuobiao+SIZE*(y-1)+x-3)=='#'||*(zuobiao+SIZE*(y-1)+x-3)=='*')
	&&(*(zuobiao+SIZE*(y-1)+x+1)=='#'||*(zuobiao+SIZE*(y-1)+x+1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,4);}
	
	else if((*(zuobiao+SIZE*(y+2)+x)=='#'||*(zuobiao+SIZE*(y+2)+x)=='*')&&(*(zuobiao+SIZE*(y+2)+x+1)=='#'||*(zuobiao+SIZE*(y+2)+x+1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(y+2)+x+2)=='#'||*(zuobiao+SIZE*(y+2)+x+2)=='*')&&(*(zuobiao+SIZE*(y+2)+x+3)=='#'||*(zuobiao+SIZE*(y+2)+x+3)=='*')
	&&(*(zuobiao+SIZE*(y+2)+x-1)=='#'||*(zuobiao+SIZE*(y+2)+x-1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,3);}
	
	else if((*(zuobiao+SIZE*(y+2)+x)=='#'||*(zuobiao+SIZE*(y+2)+x)=='*')&&(*(zuobiao+SIZE*(y+2)+x-1)=='#'||*(zuobiao+SIZE*(y+2)+x-1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(y+2)+x-2)=='#'||*(zuobiao+SIZE*(y+2)+x-2)=='*')&&(*(zuobiao+SIZE*(y+2)+x-3)=='#'||*(zuobiao+SIZE*(y+2)+x-3)=='*')
	&&(*(zuobiao+SIZE*(y+2)+x+1)=='#'||*(zuobiao+SIZE*(y+2)+x+1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,3);}
	
	else if((*(zuobiao+SIZE*(y+1)+x)=='#'||*(zuobiao+SIZE*(y+1)+x)=='*')&&(*(zuobiao+SIZE*(y+1)+x+1)=='#'||*(zuobiao+SIZE*(y+1)+x+1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(y+1)+x+2)=='#'||*(zuobiao+SIZE*(y+1)+x+2)=='*')&&(*(zuobiao+SIZE*(y+1)+x+3)=='#'||*(zuobiao+SIZE*(y+1)+x+3)=='*')
	&&(*(zuobiao+SIZE*(y+1)+x-1)=='#'||*(zuobiao+SIZE*(y+1)+x-1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,3);}
	
	else if((*(zuobiao+SIZE*(y+1)+x)=='#'||*(zuobiao+SIZE*(y+1)+x)=='*')&&(*(zuobiao+SIZE*(y+1)+x-1)=='#'||*(zuobiao+SIZE*(y+1)+x-1)=='*')//���������� 
	&&(*(zuobiao+SIZE*(y+1)+x-2)=='#'||*(zuobiao+SIZE*(y+1)+x-2)=='*')&&(*(zuobiao+SIZE*(y+1)+x-3)=='#'||*(zuobiao+SIZE*(y+1)+x-3)=='*')
	&&(*(zuobiao+SIZE*(y+1)+x+1)=='#'||*(zuobiao+SIZE*(y+1)+x+1)=='*')){printf("�����𻵣�������ƫ��\n");yidong((char *)zuobiao,3);}
}
	else if(*(zuobiao+SIZE*x+y)==' ')*(zuobiao+SIZE*x+y)='+';
	else if(*(zuobiao+SIZE*x+y)=='+'){}
	else if(*(zuobiao+SIZE*x+y)=='#'){}
	Struct result;
	result.i=x;result.j=y;result.a=*(zuobiao+SIZE*x+y);
	return result;
	
}

int xingdongji(char *ji,char *ai,char *aiyu){
	Struct result;
		int choice,a,b,c,d,i,j;
		int x,y;
		if(jiweiji==1){jiweiji=0;printf("������β�𻵣�ͣһ�غ�\n");return 0;}
			if(jitouji==0){
	LOOP:
			 a=9;b=0;c=10;d=0;
	 printf("��ѡ�� 1.�����ƶ� 2.�����ƶ� 3.�����ƶ� 4,�����ƶ� 0.���ƶ�\n");
	 scanf("%d",&choice);fflush(stdin);
	 if(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=0)goto LOOP;
	 	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
				if(*(ji+SIZE*i+j)=='*'||*(ji+SIZE*i+j)=='#'){
					if(a>i)a=i;if(b<i)b=i;if(c>j)c=j;if(d<j)d=j;
				}
	}
	}if(choice==1&&a==0||choice==2&&b==8||choice==3&&c==0||choice==4&&d==8)goto LOOP;}
	else {printf("������ͷ����٣��޷��ƶ�\n");choice=0;}
yidong((char *)ji,choice);
LOOP2:
	printf("��ָ����ը����(�ظ���ը���ظ�������)\n");
	scanf("%d %d",&x,&y);fflush(stdin);
	if(x<1||x>9||y<1||y>9)goto LOOP2;
	result=hongzhaai((char *)ai,x-1,y-1);
	*(aiyu+SIZE*result.i+result.j)=result.a;
	if(jicangai==1)return 1;
	else return 0;
}

int xingdongai(char *ai,char *ji){
		int choice,a,b,c,d,i,j;
		int x,y;if(jiweiai==1){jiweiai=0;printf("AI��β�𻵣�ͣһ�غ�\n");return 0;}
		if(jitouai==0){
	LOOP:
	choice=rand()%5;
	 a=9;b=0;c=10;d=0;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
				if(*(ai+SIZE*i+j)=='*'||*(ai+SIZE*i+j)=='#'){
					if(a>i)a=i;if(b<i)b=i;if(c>j)c=j;if(d<j)d=j;
				}
	}
	}if(choice==1&&a==0||choice==2&&b==8||choice==3&&c==0||choice==4&&d==8)goto LOOP;}
	else {printf("AI��ͷ����٣��޷��ƶ�\n");choice=0;}
	yidong((char *)ai,choice);
	x=rand()%9;y=rand()%9;
	hongzhaji((char *)ji,x,y);
	if(jicangji==1)return 1;
	else return 0;
} 

