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

void guize(char *shili);//打印规则 
void printji(char *ji);//打印己方飞机 
void printai(char *ai);//打印AI飞机 
void printaiyu(char *aiyu);//打印AI的区域（不可见） 
void printexample(char *zuobiao);//打印示例 
void example(char *zuobiao);//飞机的示例 
void feiji(char *ji);//输入机头机尾坐标以便于lunkuo函数打印出飞机轮廓 
void aifeiji(char*ai,char *aiyu);//利用随机数得出AI的飞机位置 
void lunkuo(char *feiji,int a,int b,int c,int d,int e);//打印飞机的轮廓 
int xingdongji(char *ji,char *ai,char *aiyu);//记录己方的行动 
int xingdongai(char *ai,char *ji);//记录AI的行动 
void yidong(char *dong,int a);//进行飞机的移动 
void hongzhaji(char *zuobiao,int x,int y);//进行轰炸 
Struct hongzhaai(char *zuobiao,int x,int y);//进行轰炸 


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
printf("\n\n回合结束\n\n己方坐标图如图所示：\n");
printji((char *)ji);
	printf("对方坐标图如图所示：\n");
	printai((char *)aiyu);
}
printf("最终战况为：\n\n己方坐标图如图所示：\n");
printji((char *)ji);
printf("对方坐标图如图所示：\n");
	printai((char *)ai);
	if(res1==1)printf("己方获胜\n");
else if(res2==1)printf("AI获胜\n");
system("pause");
LOOP2:
printf("请选择 1.再来一局  2.结束程序\n") ;
scanf("%d",&jieshu);
if(jieshu==1)goto LOOP;
else if(jieshu==2)return 0;
else goto LOOP2;
} 

void guize(char *shili){
	printf("规则如下：\n 炸毁机舱游戏结束，炸坏机尾被炸方需停止一回合调整方向。\n") ;
	printf(" 炸坏机翼飞机将向被炸的方向偏移一格，炸坏机头将无法移动，炸坏机身无特殊效果。\n"); 
	printf("每回合双方各有一次移动机会（上下左右或不动）和一次射击机会（指定坐标）。\n");
	printf("飞机如示例所示：\n\n");
	printf("    *机头\n  *****机翼机舱机翼\n    *机身\n    *机身\n   ***机尾\n\n "); 
	printf("(空)表示你的空和对方的未知区域，*表示完好的机身\n");
	printf(" +表示双方被炸的区域,#表示被炸的机身\n"); 
	printf("注意： 对方先轰炸完再移动\n");
	printf("请依次输入飞机头和飞机尾的坐标\n 如输入3 3 3 7,飞机位置将是:\n");
	example((char *)shili);
	printf("注意：请输入正确的坐标，以免报错(坐标含义为第几行第几列)\n\n\n") ;
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
	printf("请输入机头和机尾的坐标（如：3 3 3 7）\n");
	LOOP:
	scanf("%d %d %d %d",&a,&b,&c,&d);fflush(stdin);
	if((fabs(a-c)!=4&&fabs(b-d)!=4)||
	max(a,max(b,max(c,d)))>9||
	min(a,min(b,min(c,d)))<1){
		printf("输入错误，请重新输入\n");
		goto LOOP;
	}else if(a==c&&(a<3||a>7)){printf("输入错误，请重新输入\n");goto LOOP;}
	else if(b==d&&(b<3||b>7)){printf("输入错误，请重新输入\n");goto LOOP;}
		printf("己方坐标图如图所示：\n");
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
	printf("对方坐标图如图所示：\n");}
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
	if((*(zuobiao+SIZE*x+y-1)=='#'||*(zuobiao+SIZE*x+y-1)=='*')&&(*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')//机舱 
	&&(*(zuobiao+SIZE*x+y+1)=='#'||*(zuobiao+SIZE*x+y+1)=='*')&&(*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*'))
	jicangji=1;
	
	else if((*(zuobiao+SIZE*(x-2)+y-1)=='#'||*(zuobiao+SIZE*(x-2)+y-1)=='*')&&(*(zuobiao+SIZE*(x-1)+y-1)=='#'||*(zuobiao+SIZE*(x-1)+y-1)=='*')//机头 
	&&(*(zuobiao+SIZE*x+y-1)=='#'||*(zuobiao+SIZE*x+y-1)=='*')&&(*(zuobiao+SIZE*(x+1)+y-1)=='#'||*(zuobiao+SIZE*(x+1)+y-1)=='*')
	&&(*(zuobiao+SIZE*(x+2)+y-1)=='#'||*(zuobiao+SIZE*(x+2)+y-1)=='*'))jitouji=1;
	
		else if((*(zuobiao+SIZE*(x-2)+y+1)=='#'||*(zuobiao+SIZE*(x-2)+y+1)=='*')&&(*(zuobiao+SIZE*(x-1)+y+1)=='#'||*(zuobiao+SIZE*(x-1)+y+1)=='*')//机头 
	&&(*(zuobiao+SIZE*x+y+1)=='#'||*(zuobiao+SIZE*x+y+1)=='*')&&(*(zuobiao+SIZE*(x+1)+y+1)=='#'||*(zuobiao+SIZE*(x+1)+y+1)=='*')
	&&(*(zuobiao+SIZE*(x+2)+y+1)=='#'||*(zuobiao+SIZE*(x+2)+y+1)=='*'))jitouji=1;
	
		else if((*(zuobiao+SIZE*(x-1)+y-2)=='#'||*(zuobiao+SIZE*(x-1)+y-2)=='*')&&(*(zuobiao+SIZE*(x-1)+y-1)=='#'||*(zuobiao+SIZE*(x-1)+y-1)=='*')//机头 
	&&(*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+y+1)=='#'||*(zuobiao+SIZE*(x-1)+y+1)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y+2)=='#'||*(zuobiao+SIZE*(x-1)+y+2)=='*'))jitouji=1;
	
		else if((*(zuobiao+SIZE*(x+1)+y-2)=='#'||*(zuobiao+SIZE*(x+1)+y-2)=='*')&&(*(zuobiao+SIZE*(x+1)+y-1)=='#'||*(zuobiao+SIZE*(x+1)+y-1)=='*')//机头 
	&&(*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*')&&(*(zuobiao+SIZE*(x+1)+y+1)=='#'||*(zuobiao+SIZE*(x+1)+y+1)=='*')
	&&(*(zuobiao+SIZE*(x+1)+y+2)=='#'||*(zuobiao+SIZE*(x+1)+y+2)=='*'))jitouji=1;
	
		else if((*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*')&&(*(zuobiao+SIZE*(x+1)+y-1)=='#'||*(zuobiao+SIZE*(x+1)+y-1)=='*')//机尾 
	&&(*(zuobiao+SIZE*(x+1)+y-2)=='#'||*(zuobiao+SIZE*(x+1)+y-2)=='*')&&(*(zuobiao+SIZE*(x+1)+y-3)=='#'||*(zuobiao+SIZE*(x+1)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x+1)+y-4)=='#'||*(zuobiao+SIZE*(x+1)+y-4)=='*'))jiweiji=1;
	
		else if((*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*')&&(*(zuobiao+SIZE*(x+1)+y+1)=='#'||*(zuobiao+SIZE*(x+1)+y+1)=='*')//机尾 
	&&(*(zuobiao+SIZE*(x+1)+y+2)=='#'||*(zuobiao+SIZE*(x+1)+y+2)=='*')&&(*(zuobiao+SIZE*(x+1)+y+3)=='#'||*(zuobiao+SIZE*(x+1)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x+1)+y+4)=='#'||*(zuobiao+SIZE*(x+1)+y+4)=='*'))jiweiji=1;
	
		else if((*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+y-1)=='#'||*(zuobiao+SIZE*(x-1)+y-1)=='*')//机尾 
	&&(*(zuobiao+SIZE*(x-1)+y-2)=='#'||*(zuobiao+SIZE*(x-1)+y-2)=='*')&&(*(zuobiao+SIZE*(x+1)+y-3)=='#'||*(zuobiao+SIZE*(x-1)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y-4)=='#'||*(zuobiao+SIZE*(x-1)+y-4)=='*'))jiweiji=1;
	
	else if((*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+y+1)=='#'||*(zuobiao+SIZE*(x-1)+y+1)=='*')//机尾 
	&&(*(zuobiao+SIZE*(x-1)+y+2)=='#'||*(zuobiao+SIZE*(x-1)+y+2)=='*')&&(*(zuobiao+SIZE*(x+1)+y+3)=='#'||*(zuobiao+SIZE*(x-1)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y+4)=='#'||*(zuobiao+SIZE*(x-1)+y+4)=='*'))jiweiji=1;
	
		else if((*(zuobiao+SIZE*(y+1)+x)=='#'||*(zuobiao+SIZE*(y+1)+x)=='*')&&(*(zuobiao+SIZE*(y+1)+x-1)=='#'||*(zuobiao+SIZE*(y+1)+x-1)=='*')//机尾 
	&&(*(zuobiao+SIZE*(y+1)+x-2)=='#'||*(zuobiao+SIZE*(y+1)+x-2)=='*')&&(*(zuobiao+SIZE*(y+1)+x-3)=='#'||*(zuobiao+SIZE*(y+1)+x-3)=='*')
	&&(*(zuobiao+SIZE*(y+1)+x-4)=='#'||*(zuobiao+SIZE*(y+1)+x-4)=='*'))jiweiji=1;
	
		else if((*(zuobiao+SIZE*(y+1)+x)=='#'||*(zuobiao+SIZE*(x+1)+x)=='*')&&(*(zuobiao+SIZE*(y+1)+x+1)=='#'||*(zuobiao+SIZE*(y+1)+x+1)=='*')//机尾 
	&&(*(zuobiao+SIZE*(y+1)+x+2)=='#'||*(zuobiao+SIZE*(y+1)+x+2)=='*')&&(*(zuobiao+SIZE*(y+1)+x+3)=='#'||*(zuobiao+SIZE*(y+1)+x+3)=='*')
	&&(*(zuobiao+SIZE*(y+1)+x+4)=='#'||*(zuobiao+SIZE*(y+1)+x+4)=='*'))jiweiji=1;
	
		else if((*(zuobiao+SIZE*(y-1)+x)=='#'||*(zuobiao+SIZE*(x-1)+x)=='*')&&(*(zuobiao+SIZE*(y-1)+x-1)=='#'||*(zuobiao+SIZE*(y-1)+x-1)=='*')//机尾 
	&&(*(zuobiao+SIZE*(y-1)+x-2)=='#'||*(zuobiao+SIZE*(y-1)+x-2)=='*')&&(*(zuobiao+SIZE*(y+1)+x-3)=='#'||*(zuobiao+SIZE*(y-1)+x-3)=='*')
	&&(*(zuobiao+SIZE*(y-1)+x-4)=='#'||*(zuobiao+SIZE*(y-1)+x-4)=='*'))jiweiji=1;
	
	else if((*(zuobiao+SIZE*(y-1)+x)=='#'||*(zuobiao+SIZE*(x-1)+x)=='*')&&(*(zuobiao+SIZE*(y-1)+x+1)=='#'||*(zuobiao+SIZE*(y-1)+x+1)=='*')//机尾 
	&&(*(zuobiao+SIZE*(y-1)+x+2)=='#'||*(zuobiao+SIZE*(y-1)+x+2)=='*')&&(*(zuobiao+SIZE*(y+1)+x+3)=='#'||*(zuobiao+SIZE*(y-1)+x+3)=='*')
	&&(*(zuobiao+SIZE*(y-1)+x+4)=='#'||*(zuobiao+SIZE*(y-1)+x+4)=='*'))jiweiji=1;
	
		else if((*(zuobiao+SIZE*(y-1)+x)=='#'||*(zuobiao+SIZE*(y-1)+x)=='*')&&(*(zuobiao+SIZE*y+x-1)=='#'||*(zuobiao+SIZE*y+x-1)=='*')//机尾中间 
	&&(*(zuobiao+SIZE*y+x-2)=='#'||*(zuobiao+SIZE*y+x-2)=='*')&&(*(zuobiao+SIZE*y+x-3)=='#'||*(zuobiao+SIZE*y+x-3)=='*')
	&&(*(zuobiao+SIZE*y+x-4)=='#'||*(zuobiao+SIZE*y+x-4)=='*')&&(*(zuobiao+SIZE*(y+1)+x)=='#'||*(zuobiao+SIZE*(y+1)+x)=='*'))jiweiji=1;
	
		else if((*(zuobiao+SIZE*(y-1)+x)=='#'||*(zuobiao+SIZE*(y-1)+x)=='*')&&(*(zuobiao+SIZE*y+x+1)=='#'||*(zuobiao+SIZE*y+x+1)=='*')//机尾中间 
	&&(*(zuobiao+SIZE*y+x+2)=='#'||*(zuobiao+SIZE*y+x+2)=='*')&&(*(zuobiao+SIZE*y+x+3)=='#'||*(zuobiao+SIZE*y+x+3)=='*')
	&&(*(zuobiao+SIZE*y+x+4)=='#'||*(zuobiao+SIZE*y+x+4)=='*')&&(*(zuobiao+SIZE*(y+1)+x)=='#'||*(zuobiao+SIZE*(y+1)+x)=='*'))jiweiji=1;
	
		else if((*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+y-1)=='#'||*(zuobiao+SIZE*(x-1)+y-1)=='*')//机尾中间 
	&&(*(zuobiao+SIZE*(x-1)+y-2)=='#'||*(zuobiao+SIZE*(x-1)+y-2)=='*')&&(*(zuobiao+SIZE*(x+1)+y-3)=='#'||*(zuobiao+SIZE*(x-1)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y-4)=='#'||*(zuobiao+SIZE*(x-1)+y-4)=='*')&&(*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*'))jiweiji=1;
	
	else if((*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+x+1)=='#'||*(zuobiao+SIZE*(x-1)+y+1)=='*')//机尾中间 
	&&(*(zuobiao+SIZE*(x-1)+y+2)=='#'||*(zuobiao+SIZE*(x-1)+y+2)=='*')&&(*(zuobiao+SIZE*(x+1)+x+3)=='#'||*(zuobiao+SIZE*(x-1)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y+4)=='#'||*(zuobiao+SIZE*(x-1)+y+4)=='*')&&(*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*'))jiweiji=1;
	
		else if((*(zuobiao+SIZE*(x-2)+y)=='#'||*(zuobiao+SIZE*(x-2)+y)=='*')&&(*(zuobiao+SIZE*(x-2)+y+1)=='#'||*(zuobiao+SIZE*(x-2)+y+1)=='*')//机翼在下面 
	&&(*(zuobiao+SIZE*(x-2)+y+2)=='#'||*(zuobiao+SIZE*(x-2)+y+2)=='*')&&(*(zuobiao+SIZE*(x-2)+y+3)=='#'||*(zuobiao+SIZE*(x-2)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x-2)+y-1)=='#'||*(zuobiao+SIZE*(x-2)+y-1)=='*')){printf("机翼损坏，将向下偏移\n");yidong((char *)zuobiao,2);}
	
	else if((*(zuobiao+SIZE*(x-2)+y)=='#'||*(zuobiao+SIZE*(x-2)+y)=='*')&&(*(zuobiao+SIZE*(x-2)+y-1)=='#'||*(zuobiao+SIZE*(x-2)+y-1)=='*')//机翼在下面 
	&&(*(zuobiao+SIZE*(x-2)+y-2)=='#'||*(zuobiao+SIZE*(x-2)+y-2)=='*')&&(*(zuobiao+SIZE*(x-2)+y-3)=='#'||*(zuobiao+SIZE*(x-2)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x-2)+y+1)=='#'||*(zuobiao+SIZE*(x-2)+y+1)=='*')){printf("机翼损坏，将向下偏移\n");yidong((char *)zuobiao,2);}
	
	else if((*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+y+1)=='#'||*(zuobiao+SIZE*(x-1)+y+1)=='*')//机翼在下面 
	&&(*(zuobiao+SIZE*(x-1)+y+2)=='#'||*(zuobiao+SIZE*(x-1)+y+2)=='*')&&(*(zuobiao+SIZE*(x-1)+y+3)=='#'||*(zuobiao+SIZE*(x-1)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y-1)=='#'||*(zuobiao+SIZE*(x-1)+y-1)=='*')){printf("机翼损坏，将向下偏移\n");yidong((char *)zuobiao,2);}
	
	else if((*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+y-1)=='#'||*(zuobiao+SIZE*(x-1)+y-1)=='*')//机翼在下面 
	&&(*(zuobiao+SIZE*(x-1)+y-2)=='#'||*(zuobiao+SIZE*(x-1)+y-2)=='*')&&(*(zuobiao+SIZE*(x-1)+y-3)=='#'||*(zuobiao+SIZE*(x-1)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y+1)=='#'||*(zuobiao+SIZE*(x-1)+y+1)=='*')){printf("机翼损坏，将向下偏移\n");yidong((char *)zuobiao,2);}
	
	else if((*(zuobiao+SIZE*(x+2)+y)=='#'||*(zuobiao+SIZE*(x+2)+y)=='*')&&(*(zuobiao+SIZE*(x+2)+y+1)=='#'||*(zuobiao+SIZE*(x+2)+y+1)=='*')//机翼在上面 
	&&(*(zuobiao+SIZE*(x+2)+y+2)=='#'||*(zuobiao+SIZE*(x+2)+y+2)=='*')&&(*(zuobiao+SIZE*(x+2)+y+3)=='#'||*(zuobiao+SIZE*(x+2)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x+2)+y-1)=='#'||*(zuobiao+SIZE*(x+2)+y-1)=='*')){printf("机翼损坏，将向上偏移\n");yidong((char *)zuobiao,1);}
	
	else if((*(zuobiao+SIZE*(x+2)+y)=='#'||*(zuobiao+SIZE*(x+2)+y)=='*')&&(*(zuobiao+SIZE*(x+2)+y-1)=='#'||*(zuobiao+SIZE*(x+2)+y-1)=='*')//机翼在上面 
	&&(*(zuobiao+SIZE*(x+2)+y-2)=='#'||*(zuobiao+SIZE*(x+2)+y-2)=='*')&&(*(zuobiao+SIZE*(x+2)+y-3)=='#'||*(zuobiao+SIZE*(x+2)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x+2)+y+1)=='#'||*(zuobiao+SIZE*(x+2)+y+1)=='*')){printf("机翼损坏，将向上偏移\n");yidong((char *)zuobiao,1);}
	
	else if((*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*')&&(*(zuobiao+SIZE*(x+1)+y+1)=='#'||*(zuobiao+SIZE*(x+1)+y+1)=='*')//机翼在上面 
	&&(*(zuobiao+SIZE*(x+1)+y+2)=='#'||*(zuobiao+SIZE*(x+1)+y+2)=='*')&&(*(zuobiao+SIZE*(x+1)+y+3)=='#'||*(zuobiao+SIZE*(x+1)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x+1)+y-1)=='#'||*(zuobiao+SIZE*(x+1)+y-1)=='*')){printf("机翼损坏，将向上偏移\n");yidong((char *)zuobiao,1);}
	
	else if((*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*')&&(*(zuobiao+SIZE*(x+1)+y-1)=='#'||*(zuobiao+SIZE*(x+1)+y-1)=='*')//机翼在上面 
	&&(*(zuobiao+SIZE*(x+1)+y-2)=='#'||*(zuobiao+SIZE*(x+1)+y-2)=='*')&&(*(zuobiao+SIZE*(x+1)+y-3)=='#'||*(zuobiao+SIZE*(x+1)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x+1)+y+1)=='#'||*(zuobiao+SIZE*(x+1)+y+1)=='*')){printf("机翼损坏，将向上偏移\n");yidong((char *)zuobiao,1);}
	
	else if((*(zuobiao+SIZE*(y-2)+x)=='#'||*(zuobiao+SIZE*(y-2)+x)=='*')&&(*(zuobiao+SIZE*(y-2)+x+1)=='#'||*(zuobiao+SIZE*(y-2)+x+1)=='*')//机翼在右面 
	&&(*(zuobiao+SIZE*(y-2)+x+2)=='#'||*(zuobiao+SIZE*(y-2)+x+2)=='*')&&(*(zuobiao+SIZE*(y-2)+x+3)=='#'||*(zuobiao+SIZE*(y-2)+x+3)=='*')
	&&(*(zuobiao+SIZE*(y-2)+x-1)=='#'||*(zuobiao+SIZE*(y-2)+x-1)=='*')){printf("机翼损坏，将向右偏移\n");yidong((char *)zuobiao,4);}
	
	else if((*(zuobiao+SIZE*(y-2)+x)=='#'||*(zuobiao+SIZE*(y-2)+x)=='*')&&(*(zuobiao+SIZE*(y-2)+x-1)=='#'||*(zuobiao+SIZE*(y-2)+x-1)=='*')//机翼在右面
	&&(*(zuobiao+SIZE*(y-2)+x-2)=='#'||*(zuobiao+SIZE*(y-2)+x-2)=='*')&&(*(zuobiao+SIZE*(y-2)+x-3)=='#'||*(zuobiao+SIZE*(y-2)+x-3)=='*')
	&&(*(zuobiao+SIZE*(y-2)+x+1)=='#'||*(zuobiao+SIZE*(y-2)+x+1)=='*')){printf("机翼损坏，将向右偏移\n");yidong((char *)zuobiao,4);}
	
	else if((*(zuobiao+SIZE*(y-1)+x)=='#'||*(zuobiao+SIZE*(y-1)+x)=='*')&&(*(zuobiao+SIZE*(y-1)+x+1)=='#'||*(zuobiao+SIZE*(y-1)+x+1)=='*')//机翼在右面
	&&(*(zuobiao+SIZE*(y-1)+x+2)=='#'||*(zuobiao+SIZE*(y-1)+x+2)=='*')&&(*(zuobiao+SIZE*(y-1)+x+3)=='#'||*(zuobiao+SIZE*(y-1)+x+3)=='*')
	&&(*(zuobiao+SIZE*(y-1)+x-1)=='#'||*(zuobiao+SIZE*(y-1)+x-1)=='*')){printf("机翼损坏，将向右偏移\n");yidong((char *)zuobiao,4);}
	
	else if((*(zuobiao+SIZE*(y-1)+x)=='#'||*(zuobiao+SIZE*(y-1)+x)=='*')&&(*(zuobiao+SIZE*(y-1)+x-1)=='#'||*(zuobiao+SIZE*(y-1)+x-1)=='*')//机翼在右面 
	&&(*(zuobiao+SIZE*(y-1)+x-2)=='#'||*(zuobiao+SIZE*(y-1)+x-2)=='*')&&(*(zuobiao+SIZE*(y-1)+x-3)=='#'||*(zuobiao+SIZE*(y-1)+x-3)=='*')
	&&(*(zuobiao+SIZE*(y-1)+x+1)=='#'||*(zuobiao+SIZE*(y-1)+x+1)=='*')){printf("机翼损坏，将向右偏移\n");yidong((char *)zuobiao,4);}
	
	else if((*(zuobiao+SIZE*(y+2)+x)=='#'||*(zuobiao+SIZE*(y+2)+x)=='*')&&(*(zuobiao+SIZE*(y+2)+x+1)=='#'||*(zuobiao+SIZE*(y+2)+x+1)=='*')//机翼在左面 
	&&(*(zuobiao+SIZE*(y+2)+x+2)=='#'||*(zuobiao+SIZE*(y+2)+x+2)=='*')&&(*(zuobiao+SIZE*(y+2)+x+3)=='#'||*(zuobiao+SIZE*(y+2)+x+3)=='*')
	&&(*(zuobiao+SIZE*(y+2)+x-1)=='#'||*(zuobiao+SIZE*(y+2)+x-1)=='*')){printf("机翼损坏，将向左偏移\n");yidong((char *)zuobiao,3);}
	
	else if((*(zuobiao+SIZE*(y+2)+x)=='#'||*(zuobiao+SIZE*(y+2)+x)=='*')&&(*(zuobiao+SIZE*(y+2)+x-1)=='#'||*(zuobiao+SIZE*(y+2)+x-1)=='*')//机翼在左面 
	&&(*(zuobiao+SIZE*(y+2)+x-2)=='#'||*(zuobiao+SIZE*(y+2)+x-2)=='*')&&(*(zuobiao+SIZE*(y+2)+x-3)=='#'||*(zuobiao+SIZE*(y+2)+x-3)=='*')
	&&(*(zuobiao+SIZE*(y+2)+x+1)=='#'||*(zuobiao+SIZE*(y+2)+x+1)=='*')){printf("机翼损坏，将向左偏移\n");yidong((char *)zuobiao,3);}
	
	else if((*(zuobiao+SIZE*(y+1)+x)=='#'||*(zuobiao+SIZE*(y+1)+x)=='*')&&(*(zuobiao+SIZE*(y+1)+x+1)=='#'||*(zuobiao+SIZE*(y+1)+x+1)=='*')//机翼在左面 
	&&(*(zuobiao+SIZE*(y+1)+x+2)=='#'||*(zuobiao+SIZE*(y+1)+x+2)=='*')&&(*(zuobiao+SIZE*(y+1)+x+3)=='#'||*(zuobiao+SIZE*(y+1)+x+3)=='*')
	&&(*(zuobiao+SIZE*(y+1)+x-1)=='#'||*(zuobiao+SIZE*(y+1)+x-1)=='*')){printf("机翼损坏，将向左偏移\n");yidong((char *)zuobiao,3);}
	
	else if((*(zuobiao+SIZE*(y+1)+x)=='#'||*(zuobiao+SIZE*(y+1)+x)=='*')&&(*(zuobiao+SIZE*(y+1)+x-1)=='#'||*(zuobiao+SIZE*(y+1)+x-1)=='*')//机翼在左面 
	&&(*(zuobiao+SIZE*(y+1)+x-2)=='#'||*(zuobiao+SIZE*(y+1)+x-2)=='*')&&(*(zuobiao+SIZE*(y+1)+x-3)=='#'||*(zuobiao+SIZE*(y+1)+x-3)=='*')
	&&(*(zuobiao+SIZE*(y+1)+x+1)=='#'||*(zuobiao+SIZE*(y+1)+x+1)=='*')){printf("机翼损坏，将向左偏移\n");yidong((char *)zuobiao,3);}
}

	else if(*(zuobiao+SIZE*x+y)==' ')*(zuobiao+SIZE*x+y)='+';
	else if(*(zuobiao+SIZE*x+y)=='+'){}
	else if(*(zuobiao+SIZE*x+y)=='#'){}
}

Struct hongzhaai(char *zuobiao,int x,int y){
	if(*(zuobiao+SIZE*x+y)=='*'){
	*(zuobiao+SIZE*x+y)='#';
	if((*(zuobiao+SIZE*x+y-1)=='#'||*(zuobiao+SIZE*x+y-1)=='*')&&(*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')//机舱 
	&&(*(zuobiao+SIZE*x+y+1)=='#'||*(zuobiao+SIZE*x+y+1)=='*')&&(*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*'))
	jicangai=1;
	
	else if((*(zuobiao+SIZE*(x-2)+y-1)=='#'||*(zuobiao+SIZE*(x-2)+y-1)=='*')&&(*(zuobiao+SIZE*(x-1)+y-1)=='#'||*(zuobiao+SIZE*(x-1)+y-1)=='*')//机头 
	&&(*(zuobiao+SIZE*x+y-1)=='#'||*(zuobiao+SIZE*x+y-1)=='*')&&(*(zuobiao+SIZE*(x+1)+y-1)=='#'||*(zuobiao+SIZE*(x+1)+y-1)=='*')
	&&(*(zuobiao+SIZE*(x+2)+y-1)=='#'||*(zuobiao+SIZE*(x+2)+y-1)=='*'))jitouai=1;
	
		else if((*(zuobiao+SIZE*(x-2)+y+1)=='#'||*(zuobiao+SIZE*(x-2)+y+1)=='*')&&(*(zuobiao+SIZE*(x-1)+y+1)=='#'||*(zuobiao+SIZE*(x-1)+y+1)=='*')//机头 
	&&(*(zuobiao+SIZE*x+y+1)=='#'||*(zuobiao+SIZE*x+y+1)=='*')&&(*(zuobiao+SIZE*(x+1)+y+1)=='#'||*(zuobiao+SIZE*(x+1)+y+1)=='*')
	&&(*(zuobiao+SIZE*(x+2)+y+1)=='#'||*(zuobiao+SIZE*(x+2)+y+1)=='*'))jitouai=1;
	
		else if((*(zuobiao+SIZE*(x-1)+y-2)=='#'||*(zuobiao+SIZE*(x-1)+y-2)=='*')&&(*(zuobiao+SIZE*(x-1)+y-1)=='#'||*(zuobiao+SIZE*(x-1)+y-1)=='*')//机头 
	&&(*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+y+1)=='#'||*(zuobiao+SIZE*(x-1)+y+1)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y+2)=='#'||*(zuobiao+SIZE*(x-1)+y+2)=='*'))jitouai=1;
	
		else if((*(zuobiao+SIZE*(x+1)+y-2)=='#'||*(zuobiao+SIZE*(x+1)+y-2)=='*')&&(*(zuobiao+SIZE*(x+1)+y-1)=='#'||*(zuobiao+SIZE*(x+1)+y-1)=='*')//机头 
	&&(*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*')&&(*(zuobiao+SIZE*(x+1)+y+1)=='#'||*(zuobiao+SIZE*(x+1)+y+1)=='*')
	&&(*(zuobiao+SIZE*(x+1)+y+2)=='#'||*(zuobiao+SIZE*(x+1)+y+2)=='*'))jitouai=1;
	
		else if((*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*')&&(*(zuobiao+SIZE*(x+1)+y-1)=='#'||*(zuobiao+SIZE*(x+1)+y-1)=='*')//机尾 
	&&(*(zuobiao+SIZE*(x+1)+y-2)=='#'||*(zuobiao+SIZE*(x+1)+y-2)=='*')&&(*(zuobiao+SIZE*(x+1)+y-3)=='#'||*(zuobiao+SIZE*(x+1)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x+1)+y-4)=='#'||*(zuobiao+SIZE*(x+1)+y-4)=='*'))jiweiai=1;
	
		else if((*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*')&&(*(zuobiao+SIZE*(x+1)+y+1)=='#'||*(zuobiao+SIZE*(x+1)+y+1)=='*')//机尾 
	&&(*(zuobiao+SIZE*(x+1)+y+2)=='#'||*(zuobiao+SIZE*(x+1)+y+2)=='*')&&(*(zuobiao+SIZE*(x+1)+y+3)=='#'||*(zuobiao+SIZE*(x+1)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x+1)+y+4)=='#'||*(zuobiao+SIZE*(x+1)+y+4)=='*'))jiweiai=1;
	
		else if((*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+y-1)=='#'||*(zuobiao+SIZE*(x-1)+y-1)=='*')//机尾 
	&&(*(zuobiao+SIZE*(x-1)+y-2)=='#'||*(zuobiao+SIZE*(x-1)+y-2)=='*')&&(*(zuobiao+SIZE*(x+1)+y-3)=='#'||*(zuobiao+SIZE*(x-1)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y-4)=='#'||*(zuobiao+SIZE*(x-1)+y-4)=='*'))jiweiai=1;
	
	else if((*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+y+1)=='#'||*(zuobiao+SIZE*(x-1)+y+1)=='*')//机尾 
	&&(*(zuobiao+SIZE*(x-1)+y+2)=='#'||*(zuobiao+SIZE*(x-1)+y+2)=='*')&&(*(zuobiao+SIZE*(x+1)+y+3)=='#'||*(zuobiao+SIZE*(x-1)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y+4)=='#'||*(zuobiao+SIZE*(x-1)+y+4)=='*'))jiweiai=1;
	
	else if((*(zuobiao+SIZE*(y+1)+x)=='#'||*(zuobiao+SIZE*(y+1)+x)=='*')&&(*(zuobiao+SIZE*(y+1)+x-1)=='#'||*(zuobiao+SIZE*(y+1)+x-1)=='*')//机尾 
	&&(*(zuobiao+SIZE*(y+1)+x-2)=='#'||*(zuobiao+SIZE*(y+1)+x-2)=='*')&&(*(zuobiao+SIZE*(y+1)+x-3)=='#'||*(zuobiao+SIZE*(y+1)+x-3)=='*')
	&&(*(zuobiao+SIZE*(y+1)+x-4)=='#'||*(zuobiao+SIZE*(y+1)+x-4)=='*'))jiweiai=1;
	
		else if((*(zuobiao+SIZE*(y+1)+x)=='#'||*(zuobiao+SIZE*(x+1)+x)=='*')&&(*(zuobiao+SIZE*(y+1)+x+1)=='#'||*(zuobiao+SIZE*(y+1)+x+1)=='*')//机尾 
	&&(*(zuobiao+SIZE*(y+1)+x+2)=='#'||*(zuobiao+SIZE*(y+1)+x+2)=='*')&&(*(zuobiao+SIZE*(y+1)+x+3)=='#'||*(zuobiao+SIZE*(y+1)+x+3)=='*')
	&&(*(zuobiao+SIZE*(y+1)+x+4)=='#'||*(zuobiao+SIZE*(y+1)+x+4)=='*'))jiweiai=1;
	
		else if((*(zuobiao+SIZE*(y-1)+x)=='#'||*(zuobiao+SIZE*(x-1)+x)=='*')&&(*(zuobiao+SIZE*(y-1)+x-1)=='#'||*(zuobiao+SIZE*(y-1)+x-1)=='*')//机尾 
	&&(*(zuobiao+SIZE*(y-1)+x-2)=='#'||*(zuobiao+SIZE*(y-1)+x-2)=='*')&&(*(zuobiao+SIZE*(y+1)+x-3)=='#'||*(zuobiao+SIZE*(y-1)+x-3)=='*')
	&&(*(zuobiao+SIZE*(y-1)+x-4)=='#'||*(zuobiao+SIZE*(y-1)+x-4)=='*'))jiweiai=1;
	
	else if((*(zuobiao+SIZE*(y-1)+x)=='#'||*(zuobiao+SIZE*(x-1)+x)=='*')&&(*(zuobiao+SIZE*(y-1)+x+1)=='#'||*(zuobiao+SIZE*(y-1)+x+1)=='*')//机尾 
	&&(*(zuobiao+SIZE*(y-1)+x+2)=='#'||*(zuobiao+SIZE*(y-1)+x+2)=='*')&&(*(zuobiao+SIZE*(y+1)+x+3)=='#'||*(zuobiao+SIZE*(y-1)+x+3)=='*')
	&&(*(zuobiao+SIZE*(y-1)+x+4)=='#'||*(zuobiao+SIZE*(y-1)+x+4)=='*'))jiweiai=1;
	
		else if((*(zuobiao+SIZE*(y-1)+x)=='#'||*(zuobiao+SIZE*(y-1)+x)=='*')&&(*(zuobiao+SIZE*y+x-1)=='#'||*(zuobiao+SIZE*y+x-1)=='*')//机尾中间 
	&&(*(zuobiao+SIZE*y+x-2)=='#'||*(zuobiao+SIZE*y+x-2)=='*')&&(*(zuobiao+SIZE*y+x-3)=='#'||*(zuobiao+SIZE*y+x-3)=='*')
	&&(*(zuobiao+SIZE*y+x-4)=='#'||*(zuobiao+SIZE*y+x-4)=='*')&&(*(zuobiao+SIZE*(y+1)+x)=='#'||*(zuobiao+SIZE*(y+1)+x)=='*'))jiweiai=1;
	
		else if((*(zuobiao+SIZE*(y-1)+x)=='#'||*(zuobiao+SIZE*(y-1)+x)=='*')&&(*(zuobiao+SIZE*y+x+1)=='#'||*(zuobiao+SIZE*y+x+1)=='*')//机尾中间 
	&&(*(zuobiao+SIZE*y+x+2)=='#'||*(zuobiao+SIZE*y+x+2)=='*')&&(*(zuobiao+SIZE*y+x+3)=='#'||*(zuobiao+SIZE*y+x+3)=='*')
	&&(*(zuobiao+SIZE*y+x+4)=='#'||*(zuobiao+SIZE*y+x+4)=='*')&&(*(zuobiao+SIZE*(y+1)+x)=='#'||*(zuobiao+SIZE*(y+1)+x)=='*'))jiweiai=1;
	
		else if((*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+y-1)=='#'||*(zuobiao+SIZE*(x-1)+y-1)=='*')//机尾中间 
	&&(*(zuobiao+SIZE*(x-1)+y-2)=='#'||*(zuobiao+SIZE*(x-1)+y-2)=='*')&&(*(zuobiao+SIZE*(x+1)+y-3)=='#'||*(zuobiao+SIZE*(x-1)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y-4)=='#'||*(zuobiao+SIZE*(x-1)+y-4)=='*')&&(*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*'))jiweiai=1;
	
	else if((*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+x+1)=='#'||*(zuobiao+SIZE*(x-1)+y+1)=='*')//机尾中间 
	&&(*(zuobiao+SIZE*(x-1)+y+2)=='#'||*(zuobiao+SIZE*(x-1)+y+2)=='*')&&(*(zuobiao+SIZE*(x+1)+x+3)=='#'||*(zuobiao+SIZE*(x-1)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y+4)=='#'||*(zuobiao+SIZE*(x-1)+y+4)=='*')&&(*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*'))jiweiai=1;
	
	else if((*(zuobiao+SIZE*(x-2)+y)=='#'||*(zuobiao+SIZE*(x-2)+y)=='*')&&(*(zuobiao+SIZE*(x-2)+y+1)=='#'||*(zuobiao+SIZE*(x-2)+y+1)=='*')//机翼在下面 
	&&(*(zuobiao+SIZE*(x-2)+y+2)=='#'||*(zuobiao+SIZE*(x-2)+y+2)=='*')&&(*(zuobiao+SIZE*(x-2)+y+3)=='#'||*(zuobiao+SIZE*(x-2)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x-2)+y-1)=='#'||*(zuobiao+SIZE*(x-2)+y-1)=='*')){printf("机翼损坏，将向下偏移\n");yidong((char *)zuobiao,2);}
	
	else if((*(zuobiao+SIZE*(x-2)+y)=='#'||*(zuobiao+SIZE*(x-2)+y)=='*')&&(*(zuobiao+SIZE*(x-2)+y-1)=='#'||*(zuobiao+SIZE*(x-2)+y-1)=='*')//机翼在下面 
	&&(*(zuobiao+SIZE*(x-2)+y-2)=='#'||*(zuobiao+SIZE*(x-2)+y-2)=='*')&&(*(zuobiao+SIZE*(x-2)+y-3)=='#'||*(zuobiao+SIZE*(x-2)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x-2)+y+1)=='#'||*(zuobiao+SIZE*(x-2)+y+1)=='*')){printf("机翼损坏，将向下偏移\n");yidong((char *)zuobiao,2);}
	
	else if((*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+y+1)=='#'||*(zuobiao+SIZE*(x-1)+y+1)=='*')//机翼在下面 
	&&(*(zuobiao+SIZE*(x-1)+y+2)=='#'||*(zuobiao+SIZE*(x-1)+y+2)=='*')&&(*(zuobiao+SIZE*(x-1)+y+3)=='#'||*(zuobiao+SIZE*(x-1)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y-1)=='#'||*(zuobiao+SIZE*(x-1)+y-1)=='*')){printf("机翼损坏，将向下偏移\n");yidong((char *)zuobiao,2);}
	
	else if((*(zuobiao+SIZE*(x-1)+y)=='#'||*(zuobiao+SIZE*(x-1)+y)=='*')&&(*(zuobiao+SIZE*(x-1)+y-1)=='#'||*(zuobiao+SIZE*(x-1)+y-1)=='*')//机翼在下面 
	&&(*(zuobiao+SIZE*(x-1)+y-2)=='#'||*(zuobiao+SIZE*(x-1)+y-2)=='*')&&(*(zuobiao+SIZE*(x-1)+y-3)=='#'||*(zuobiao+SIZE*(x-1)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x-1)+y+1)=='#'||*(zuobiao+SIZE*(x-1)+y+1)=='*')){printf("机翼损坏，将向下偏移\n");yidong((char *)zuobiao,2);}
	
	else if((*(zuobiao+SIZE*(x+2)+y)=='#'||*(zuobiao+SIZE*(x+2)+y)=='*')&&(*(zuobiao+SIZE*(x+2)+y+1)=='#'||*(zuobiao+SIZE*(x+2)+y+1)=='*')//机翼在上面 
	&&(*(zuobiao+SIZE*(x+2)+y+2)=='#'||*(zuobiao+SIZE*(x+2)+y+2)=='*')&&(*(zuobiao+SIZE*(x+2)+y+3)=='#'||*(zuobiao+SIZE*(x+2)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x+2)+y-1)=='#'||*(zuobiao+SIZE*(x+2)+y-1)=='*')){printf("机翼损坏，将向上偏移\n");yidong((char *)zuobiao,1);}
	
	else if((*(zuobiao+SIZE*(x+2)+y)=='#'||*(zuobiao+SIZE*(x+2)+y)=='*')&&(*(zuobiao+SIZE*(x+2)+y-1)=='#'||*(zuobiao+SIZE*(x+2)+y-1)=='*')//机翼在上面 
	&&(*(zuobiao+SIZE*(x+2)+y-2)=='#'||*(zuobiao+SIZE*(x+2)+y-2)=='*')&&(*(zuobiao+SIZE*(x+2)+y-3)=='#'||*(zuobiao+SIZE*(x+2)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x+2)+y+1)=='#'||*(zuobiao+SIZE*(x+2)+y+1)=='*')){printf("机翼损坏，将向上偏移\n");yidong((char *)zuobiao,1);}
	
	else if((*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*')&&(*(zuobiao+SIZE*(x+1)+y+1)=='#'||*(zuobiao+SIZE*(x+1)+y+1)=='*')//机翼在上面 
	&&(*(zuobiao+SIZE*(x+1)+y+2)=='#'||*(zuobiao+SIZE*(x+1)+y+2)=='*')&&(*(zuobiao+SIZE*(x+1)+y+3)=='#'||*(zuobiao+SIZE*(x+1)+y+3)=='*')
	&&(*(zuobiao+SIZE*(x+1)+y-1)=='#'||*(zuobiao+SIZE*(x+1)+y-1)=='*')){printf("机翼损坏，将向上偏移\n");yidong((char *)zuobiao,1);}
	
	else if((*(zuobiao+SIZE*(x+1)+y)=='#'||*(zuobiao+SIZE*(x+1)+y)=='*')&&(*(zuobiao+SIZE*(x+1)+y-1)=='#'||*(zuobiao+SIZE*(x+1)+y-1)=='*')//机翼在上面 
	&&(*(zuobiao+SIZE*(x+1)+y-2)=='#'||*(zuobiao+SIZE*(x+1)+y-2)=='*')&&(*(zuobiao+SIZE*(x+1)+y-3)=='#'||*(zuobiao+SIZE*(x+1)+y-3)=='*')
	&&(*(zuobiao+SIZE*(x+1)+y+1)=='#'||*(zuobiao+SIZE*(x+1)+y+1)=='*')){printf("机翼损坏，将向上偏移\n");yidong((char *)zuobiao,1);}
	
	else if((*(zuobiao+SIZE*(y-2)+x)=='#'||*(zuobiao+SIZE*(y-2)+x)=='*')&&(*(zuobiao+SIZE*(y-2)+x+1)=='#'||*(zuobiao+SIZE*(y-2)+x+1)=='*')//机翼在右面 
	&&(*(zuobiao+SIZE*(y-2)+x+2)=='#'||*(zuobiao+SIZE*(y-2)+x+2)=='*')&&(*(zuobiao+SIZE*(y-2)+x+3)=='#'||*(zuobiao+SIZE*(y-2)+x+3)=='*')
	&&(*(zuobiao+SIZE*(y-2)+x-1)=='#'||*(zuobiao+SIZE*(y-2)+x-1)=='*')){printf("机翼损坏，将向右偏移\n");yidong((char *)zuobiao,4);}
	
	else if((*(zuobiao+SIZE*(y-2)+x)=='#'||*(zuobiao+SIZE*(y-2)+x)=='*')&&(*(zuobiao+SIZE*(y-2)+x-1)=='#'||*(zuobiao+SIZE*(y-2)+x-1)=='*')//机翼在右面
	&&(*(zuobiao+SIZE*(y-2)+x-2)=='#'||*(zuobiao+SIZE*(y-2)+x-2)=='*')&&(*(zuobiao+SIZE*(y-2)+x-3)=='#'||*(zuobiao+SIZE*(y-2)+x-3)=='*')
	&&(*(zuobiao+SIZE*(y-2)+x+1)=='#'||*(zuobiao+SIZE*(y-2)+x+1)=='*')){printf("机翼损坏，将向右偏移\n");yidong((char *)zuobiao,4);}
	
	else if((*(zuobiao+SIZE*(y-1)+x)=='#'||*(zuobiao+SIZE*(y-1)+x)=='*')&&(*(zuobiao+SIZE*(y-1)+x+1)=='#'||*(zuobiao+SIZE*(y-1)+x+1)=='*')//机翼在右面
	&&(*(zuobiao+SIZE*(y-1)+x+2)=='#'||*(zuobiao+SIZE*(y-1)+x+2)=='*')&&(*(zuobiao+SIZE*(y-1)+x+3)=='#'||*(zuobiao+SIZE*(y-1)+x+3)=='*')
	&&(*(zuobiao+SIZE*(y-1)+x-1)=='#'||*(zuobiao+SIZE*(y-1)+x-1)=='*')){printf("机翼损坏，将向右偏移\n");yidong((char *)zuobiao,4);}
	
	else if((*(zuobiao+SIZE*(y-1)+x)=='#'||*(zuobiao+SIZE*(y-1)+x)=='*')&&(*(zuobiao+SIZE*(y-1)+x-1)=='#'||*(zuobiao+SIZE*(y-1)+x-1)=='*')//机翼在右面 
	&&(*(zuobiao+SIZE*(y-1)+x-2)=='#'||*(zuobiao+SIZE*(y-1)+x-2)=='*')&&(*(zuobiao+SIZE*(y-1)+x-3)=='#'||*(zuobiao+SIZE*(y-1)+x-3)=='*')
	&&(*(zuobiao+SIZE*(y-1)+x+1)=='#'||*(zuobiao+SIZE*(y-1)+x+1)=='*')){printf("机翼损坏，将向右偏移\n");yidong((char *)zuobiao,4);}
	
	else if((*(zuobiao+SIZE*(y+2)+x)=='#'||*(zuobiao+SIZE*(y+2)+x)=='*')&&(*(zuobiao+SIZE*(y+2)+x+1)=='#'||*(zuobiao+SIZE*(y+2)+x+1)=='*')//机翼在左面 
	&&(*(zuobiao+SIZE*(y+2)+x+2)=='#'||*(zuobiao+SIZE*(y+2)+x+2)=='*')&&(*(zuobiao+SIZE*(y+2)+x+3)=='#'||*(zuobiao+SIZE*(y+2)+x+3)=='*')
	&&(*(zuobiao+SIZE*(y+2)+x-1)=='#'||*(zuobiao+SIZE*(y+2)+x-1)=='*')){printf("机翼损坏，将向左偏移\n");yidong((char *)zuobiao,3);}
	
	else if((*(zuobiao+SIZE*(y+2)+x)=='#'||*(zuobiao+SIZE*(y+2)+x)=='*')&&(*(zuobiao+SIZE*(y+2)+x-1)=='#'||*(zuobiao+SIZE*(y+2)+x-1)=='*')//机翼在左面 
	&&(*(zuobiao+SIZE*(y+2)+x-2)=='#'||*(zuobiao+SIZE*(y+2)+x-2)=='*')&&(*(zuobiao+SIZE*(y+2)+x-3)=='#'||*(zuobiao+SIZE*(y+2)+x-3)=='*')
	&&(*(zuobiao+SIZE*(y+2)+x+1)=='#'||*(zuobiao+SIZE*(y+2)+x+1)=='*')){printf("机翼损坏，将向左偏移\n");yidong((char *)zuobiao,3);}
	
	else if((*(zuobiao+SIZE*(y+1)+x)=='#'||*(zuobiao+SIZE*(y+1)+x)=='*')&&(*(zuobiao+SIZE*(y+1)+x+1)=='#'||*(zuobiao+SIZE*(y+1)+x+1)=='*')//机翼在左面 
	&&(*(zuobiao+SIZE*(y+1)+x+2)=='#'||*(zuobiao+SIZE*(y+1)+x+2)=='*')&&(*(zuobiao+SIZE*(y+1)+x+3)=='#'||*(zuobiao+SIZE*(y+1)+x+3)=='*')
	&&(*(zuobiao+SIZE*(y+1)+x-1)=='#'||*(zuobiao+SIZE*(y+1)+x-1)=='*')){printf("机翼损坏，将向左偏移\n");yidong((char *)zuobiao,3);}
	
	else if((*(zuobiao+SIZE*(y+1)+x)=='#'||*(zuobiao+SIZE*(y+1)+x)=='*')&&(*(zuobiao+SIZE*(y+1)+x-1)=='#'||*(zuobiao+SIZE*(y+1)+x-1)=='*')//机翼在左面 
	&&(*(zuobiao+SIZE*(y+1)+x-2)=='#'||*(zuobiao+SIZE*(y+1)+x-2)=='*')&&(*(zuobiao+SIZE*(y+1)+x-3)=='#'||*(zuobiao+SIZE*(y+1)+x-3)=='*')
	&&(*(zuobiao+SIZE*(y+1)+x+1)=='#'||*(zuobiao+SIZE*(y+1)+x+1)=='*')){printf("机翼损坏，将向左偏移\n");yidong((char *)zuobiao,3);}
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
		if(jiweiji==1){jiweiji=0;printf("己方机尾损坏，停一回合\n");return 0;}
			if(jitouji==0){
	LOOP:
			 a=9;b=0;c=10;d=0;
	 printf("请选择 1.向上移动 2.向下移动 3.向左移动 4,向右移动 0.不移动\n");
	 scanf("%d",&choice);fflush(stdin);
	 if(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=0)goto LOOP;
	 	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
				if(*(ji+SIZE*i+j)=='*'||*(ji+SIZE*i+j)=='#'){
					if(a>i)a=i;if(b<i)b=i;if(c>j)c=j;if(d<j)d=j;
				}
	}
	}if(choice==1&&a==0||choice==2&&b==8||choice==3&&c==0||choice==4&&d==8)goto LOOP;}
	else {printf("己方机头已损毁，无法移动\n");choice=0;}
yidong((char *)ji,choice);
LOOP2:
	printf("请指定轰炸区域(重复轰炸不重复起作用)\n");
	scanf("%d %d",&x,&y);fflush(stdin);
	if(x<1||x>9||y<1||y>9)goto LOOP2;
	result=hongzhaai((char *)ai,x-1,y-1);
	*(aiyu+SIZE*result.i+result.j)=result.a;
	if(jicangai==1)return 1;
	else return 0;
}

int xingdongai(char *ai,char *ji){
		int choice,a,b,c,d,i,j;
		int x,y;if(jiweiai==1){jiweiai=0;printf("AI机尾损坏，停一回合\n");return 0;}
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
	else {printf("AI机头已损毁，无法移动\n");choice=0;}
	yidong((char *)ai,choice);
	x=rand()%9;y=rand()%9;
	hongzhaji((char *)ji,x,y);
	if(jicangji==1)return 1;
	else return 0;
} 

