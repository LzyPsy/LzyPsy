#include <stdio.h>
#include <stdlib.h>
#define SIZE 21//19+2避免边界问题 
#define SIZE2 1000
#define PAN if((*(a+SIZE*(i+1)+j)!='W'&&*(a+SIZE*(i+1)+j)!='B'&&*(a+SIZE*(i+1)+j)!='*')||
#define DI (*(a+SIZE*(i-1)+j)!='W'&&*(a+SIZE*(i-1)+j)!='B'&&*(a+SIZE*(i-1)+j)!='*')|| (*(a+SIZE*i+j+1)!='W'&&*(a+SIZE*i+j+1)!='B'&&*(a+SIZE*i+j+1)!='*') ||
#define NG (*(a+SIZE*i+j-1)!='W'&&*(a+SIZE*i+j-1)!='B'&&*(a+SIZE*i+j-1)!='*')){return 1;}

int global_a,global_b,global_c,global_d;
int global_baitizi,global_heitizi; 

 struct wrong{//定义一个结构体以返回两个值 
	int a;
	int b;
};
typedef struct wrong Struct;//自定义一个类型 

struct shunxu {//定义一个结构体以返回一个回合内两颗棋子的坐标 
	int a1;
	int a2;
	int a3;
	int a4;
};
typedef struct shunxu Struct2;//自定义一个类型 

void qipan(char *ge,int* jilu);//打印棋盘 
Struct2 luozi(int *m,char *ge,int* jilu);//黑白落子 
int qibai(int *x,char *ge,int* jilu);//计算白的气 
int qihei(int *x,char *ge,int* jilu);//计算黑的气 
Struct wronghei(char *ge,int* jilu);//判定错误 
Struct wrongbai(char *ge,int* jilu); //判定错误 
//活棋可通过两只眼无法下进行判定 
int jiehei(int *m,char *ge,int* jilu);//判断打劫情况 
int jiebai(int *m,char *ge,int* jilu);
 int lianjiebai(char *ge,int* jilu,int i,int j);//计算两个以上白棋子连起来的气 
 int lianjiehei(char *ge,int* jilu,int i,int j);//计算两个以上黑棋子连起来的气 
 void fupan(char *ge,int *jilu);//进行复盘 
 
  int zuohei(int i,int j,char *a);//棋子串 
   int youhei(int i,int j,char *a);
    int shanghei(int i,int j,char *a);
     int xiahei(int i,int j,char *a);
    int zuobai(int i,int j,char *a);
   int youbai(int i,int j,char *a);
    int shangbai(int i,int j,char *a);
     int xiabai(int i,int j,char *a);
     
     int lianjiehei1(char *ge,int* jilu,int i,int j);//判断气并防止走在无气的位置 
     int lianjiebai1(char *ge,int* jilu,int i,int j);
 
int main(){
	LOOP3:
		global_baitizi=0;global_heitizi=0;float heimu,baimu;
	printf("如果想要结束棋局，请输入（-1，-1)即可\n");
	char ge[SIZE][SIZE];
	int i,j,huihe;//回合数 
	int jilu[SIZE2];
	int res;
	for(i=0;i<SIZE2;i++){
		jilu[i]=0;	}
	Struct2 result;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			if(i==4&&j==4||i==16&&j==16||
			i==4&&j==16||i==16&&j==4||
			i==4&&j==10||i==16&&j==10||
			i==10&&j==4||i==10&&j==16||j==10&&i==10)//星，边，天元 
			ge[i][j]='#';
			else if(i>0&&i<20&&j>0&&j<20)ge[i][j]='+';//交叉点 
			else ge[i][j]='*';//边界外 
		}
	}
	qipan((char*)ge,(int*)jilu);
	for(huihe=0;huihe<500;huihe++){
		result=luozi(&huihe,(char*)ge,&jilu[0]);
		jilu[4*huihe]=result.a1;jilu[4*huihe+1]=result.a2;
		jilu[4*huihe+2]=result.a3;jilu[4*huihe+3]=result.a4;//接受结构体返回的坐标值 
		if(jilu[4*huihe]==0||jilu[4*huihe+1]==0||jilu[4*huihe+2]==0||jilu[4*huihe+3]==0)break;//判断对局是否结束 
	}choice:
	 printf("\n请选择点目或认输\n1.点目  2.黑棋认输  3.白棋认输  4.和棋\n") ;
	 scanf("%d",&res);
	 if(res==1){
	printf("\n黑棋提子数：%d     白棋提子数：%d",global_heitizi,global_baitizi);
	printf("\n请输入黑棋的目数：\n");scanf("%f",&heimu);
	printf("\n请输入白棋的目数：\n");scanf("%f",&baimu);
	if(heimu-7.5>=baimu)printf("黑棋胜\n");
	else printf("白棋胜\n");
	}
		else if(res==2)printf("白棋胜\n");
		else if(res==3)printf("黑棋胜\n");
		else if(res==4)printf("和棋\n"); 
		else goto choice; 
	int again2;int again;//返回到复盘点 
	loop:
	printf("\n请选择结束程序或复盘或重开：1.结束程序  2.复盘  3.重开\n");
	scanf("%d",&again2);
	if(again2==1)return 0;
	else if(again2==3)goto LOOP3;
	else if(again2!=2)goto loop;
	else {
	LOOP:
		for(i=0;i<SIZE;i++){//重新规划棋盘 
		for(j=1;j<SIZE-1;j++){
			if(i==4&&j==4||i==16&&j==16||
			i==4&&j==16||i==16&&j==4||
			i==4&&j==10||i==16&&j==10||
			i==10&&j==4||i==10&&j==16||j==10&&i==10)//星，边，天元 
			ge[i][j]='#';
			else if(i>0&&i<20&&j>0&&j<20)ge[i][j]='+';//交叉点 
			else ge[i][j]='*';//边界外 
		}
	}
	fupan((char*)ge,&jilu[0]);//进行复盘 
	LOOP2:
	printf("\n请选择再次复盘或结束程序或重开：1.结束程序  2.再次复盘  3.重开\n");
	scanf("%d",&again);
	if(again==1)return 0;
	else if(again==2)goto LOOP;
	else if(again==3)goto LOOP3; 
	else goto LOOP2;}
} 

void qipan(char *ge,int* jilu){//打印棋盘 
	int i,j,m; 
	int zuobiao[20];//坐标  横X轴  竖Y轴 
	zuobiao[0]=0;
	printf("%d    ",zuobiao[0]);
	for(i=1;i<10;i++){
		zuobiao[i]=i;
		printf("%d     ",zuobiao[i]);
	}	for(i=10;i<20;i++){
		zuobiao[i]=i;
		printf("%d    ",zuobiao[i]);
	}
	printf(" --->X轴") ; //标明坐标轴 
	for(i=1;i<SIZE-1;i++){
		m=i-1;
		printf("\n");
		if(m<9)printf("%d  ",zuobiao[m+1]);
		else printf("%d ",zuobiao[m+1]);
		for(j=1;j<SIZE-1;j++){
			if(ge[SIZE*i+j]=='B')printf(" ○○ ");//黑棋子 
			else if(ge[SIZE*i+j]=='W')printf(" ●● ");//白棋子 
			else printf("  %c%c  ",ge[SIZE*i+j],ge[SIZE*i+j]);
		}if(m<9)printf("%d  ",zuobiao[m+1]);
		else printf("%d ",zuobiao[m+1]);
		printf("\n");
		if(m<9)printf("%d  ",zuobiao[m+1]);
		else printf("%d ",zuobiao[m+1]);
			for(j=1;j<SIZE-1;j++){
			if(ge[SIZE*i+j]=='B')printf(" ○○ ");
			else if(ge[SIZE*i+j]=='W')printf(" ●● ");
			else printf("  %c%c  ",ge[SIZE*i+j],ge[SIZE*i+j]);
		
		}if(m<9)printf("%d  ",zuobiao[m+1]);
		else printf("%d ",zuobiao[m+1]);
		printf("\n");	
}
	printf("%d    ",zuobiao[0]);
	for(i=1;i<10;i++){
		printf("%d     ",zuobiao[i]);
	}	for(i=10;i<20;i++){
		printf("%d    ",zuobiao[i]);
	}
	printf("\nY\n轴\n");	
}

Struct wronghei(char *ge,int* jilu){//纠正黑棋错误落子 
int i,j;
Struct c;
	scanf("%d%d",&j,&i) ;
		fflush(stdin);
	if(j==-1&&i==-1){
		c.a=0;c.b=0;return c;
	}
	else if(ge[SIZE*i+j]!='+'&&ge[SIZE*i+j]!='#'){
		printf("坐标错误，请重新输入坐标（重叠或超出范围）\n");
		wronghei((char*)ge,(int*)jilu);
	}
		else if(j<1||j>20||i<1||i>20){
		printf("坐标错误，请重新输入坐标（重叠或超出范围）\n");
		wronghei((char*)ge,(int*)jilu);
	}else {ge[SIZE*i+j]='B';
	c.a=j;c.b=i;
	return c;} 
}

Struct wrongbai(char *ge,int* jilu){//纠正白棋错误落子 
int i,j;
Struct d;
	scanf("%d%d",&j,&i) ;
		fflush(stdin);
		if(j==-1&&i==-1){
		d.a=0;d.b=0;return d;}	
	else if(ge[SIZE*i+j]!='+'&&ge[SIZE*i+j]!='#'){
		printf("坐标错误，请重新输入坐标（重叠或超出范围）\n");
		wrongbai((char*)ge,(int*)jilu);
	}	else if(j<1||j>20||i<1||i>20){
		printf("坐标错误，请重新输入坐标（重叠或超出范围）\n");
		wrongbai((char*)ge,(int*)jilu);
	}else {ge[SIZE*i+j]='W'; 
	d.a=j;d.b=i;
	return d;} 
}

Struct2 luozi(int *m,char *ge,int* jilu){
	int i,j,n;
	int x=0,y=0;//判断是否因未找劫材重下 
	Struct2 resu;//接受四个坐标值 
	n=*m;
		Struct result1;
	LOOP3:

	printf("请黑棋落子(输入坐标)\n");
	result1=wronghei((char*)ge,(int*)jilu);
		*(jilu+4*n)=result1.a;*(jilu+4*n+1)=result1.b;
		resu.a1=*(jilu+4*n);resu.a2=*(jilu+4*n+1);
		if(resu.a1==0&&resu.a2==0)return resu;
		global_a=0;global_b=0;
x=qibai(&n,(char*)ge,(int*)jilu);
	if(x!=0)goto LOOP3;
	qipan((char*)ge,(int*)jilu);
		Struct result2;
	LOOP4:
	
	printf("请白棋落子(输入坐标)\n");
result2=wrongbai((char*)ge,(int*)jilu);
	*(jilu+4*n+2)=result2.a;*(jilu+4*n+3)=result2.b;
		resu.a1=*(jilu+4*n);resu.a2=*(jilu+4*n+1);resu.a3=*(jilu+4*n+2);resu.a4=*(jilu+4*n+3);
		if(resu.a3==0&&resu.a4==0)return resu;
	global_c=0;global_d=0;
	y=qihei(&n,(char*)ge,(int*)jilu);
	if(y!=0)goto LOOP4;
	qipan((char*)ge,(int*)jilu);
		return resu;
}

int zuobai(int i,int j,char *a){//注意：上下左右没按顺序来 
 	i=i-1;int qi=0,qi1=0,qi2=0,qi3=0;
 	*(a+SIZE*i+j)='*';
PAN DI NG
 	if(*(a+SIZE*(i-1)+j)=='W')qi1=zuobai(i,j,(char *)a);
if(*(a+SIZE*i+j-1)=='W')qi2=shangbai(i,j,(char *)a);
if(*(a+SIZE*i+j+1)=='W')qi3=xiabai(i,j,(char *)a);
if(qi==0&&qi1==0&&qi2==0&&qi3==0)return 0;
else return 1;
 }
  int youbai(int i,int j,char *a){
 	i=i+1;int qi=0,qi1=0,qi2=0,qi3=0;
 	*(a+SIZE*i+j)='*';
PAN DI NG
 	if(*(a+SIZE*(i+1)+j)=='W')qi1=youbai(i,j,(char *)a);
if(*(a+SIZE*i+j-1)=='W')qi2=shangbai(i,j,(char *)a);
if(*(a+SIZE*i+j+1)=='W')qi3=xiabai(i,j,(char *)a);
if(qi==0&&qi1==0&&qi2==0&&qi3==0)return 0;
else return 1;
 }
  int shangbai(int i,int j,char *a){
 	j=j-1;int qi=0,qi1=0,qi2=0,qi3=0;
 	*(a+SIZE*i+j)='*';
PAN DI NG
 	if(*(a+SIZE*(i-1)+j)=='W')qi1=zuobai(i,j,(char *)a);
if(*(a+SIZE*(i+1)+j)=='W')qi2=youbai(i,j,(char *)a);
if(*(a+SIZE*i+j-1)=='W')qi3=shangbai(i,j,(char *)a);
if(qi==0&&qi1==0&&qi2==0&&qi3==0)return 0;
else return 1;
 }
  int xiabai(int i,int j,char *a){
 	j=j+1;int qi=0,qi1=0,qi2=0,qi3=0;
 	*(a+SIZE*i+j)='*';
PAN DI NG
 	if(*(a+SIZE*(i-1)+j)=='W')qi1=zuobai(i,j,(char *)a);
if(*(a+SIZE*(i+1)+j)=='W')qi2=youbai(i,j,(char *)a);
if(*(a+SIZE*i+j+1)=='W')qi3=xiabai(i,j,(char *)a);
if(qi==0&&qi1==0&&qi2==0&&qi3==0)return 0;
else return 1;
 }

int lianjiebai(char *ge,int* jilu,int i,int j){//计算白棋子串的气 
char a[SIZE][SIZE];int qi=0,qi1=0,qi2=0,qi3=0,qi4=0;
int x,y;
for(x=0;x<SIZE;x++){
	for(y=0;y<SIZE;y++){
		a[x][y]=*(ge+SIZE*x+y);
	}
} a[i][j]='*';
if((a[i+1][j]=='+'|| a[i+1][j]=='#')||
 (a[i-1][j]=='+'|| a[i-1][j]=='#')|| (a[i][j-1]=='#'
||a[i][j-1]=='+')||(a[i][j+1]=='#'||a[i][j+1]=='+')){return 0;}
if(a[i-1][j]=='W')qi1=zuobai(i,j,(char *)a);
if(a[i+1][j]=='W')qi2=youbai(i,j,(char *)a);
if(a[i][j-1]=='W')qi3=shangbai(i,j,(char *)a);
if(a[i][j+1]=='W')qi4=xiabai(i,j,(char *)a);
if(qi1==0&&qi2==0&&qi3==0&&qi4==0&&qi==0){
	for(x=1;x<SIZE-1;x++){
	for(y=1;y<SIZE-1;y++){
		if(a[x][y]=='*'){	if(x==4&&y==4||x==16&&y==16||
			x==4&&y==16||x==16&&y==4||
			x==4&&y==10||x==16&&y==10||
			x==10&&y==4||x==10&&y==16||y==10&&x==10)
			ge[SIZE*x+y]='#';
			else if(x>0 && x<20 && y>0 && y<20) ge[SIZE*x+y]='+';
			global_heitizi++;
		}
	}
}}
	 return 0;
		}
  
  int lianjiebai1(char *ge,int* jilu,int j,int i){//计算白棋子串的气 
char b[SIZE][SIZE];int qi=0,qi1=0,qi2=0,qi3=0,qi4=0;
int x,y;
for(x=0;x<SIZE;x++){
	for(y=0;y<SIZE;y++){
		b[x][y]=*(ge+SIZE*x+y);
	}
}
b[i][j]='*';
if((b[i+1][j]=='+'|| b[i+1][j]=='#')||
 (b[i-1][j]=='+'|| b[i-1][j]=='#')|| (b[i][j-1]=='#'
||b[i][j-1]=='+')||(b[i][j+1]=='+'||b[i][j+1]=='#')){return 1;}
if(b[i-1][j]=='W')qi1=zuobai(i,j,(char *)b);
if(b[i+1][j]=='W')qi2=youbai(i,j,(char *)b);
if(b[i][j-1]=='W')qi3=shangbai(i,j,(char *)b);
if(b[i][j+1]=='W')qi4=xiabai(i,j,(char *)b);
if(qi1==0&&qi2==0&&qi3==0&&qi4==0&&qi==0)return 0;
	 else return 1;
		}
		
 int zuohei(int i,int j,char *a){
 	i=i-1;int qi=0,qi1=0,qi2=0,qi3=0;
 	*(a+SIZE*i+j)='*';
PAN DI NG
 	if(*(a+SIZE*(i-1)+j)=='B')qi1=zuohei(i,j,(char *)a);
if(*(a+SIZE*i+j-1)=='B')qi2=shanghei(i,j,(char *)a);
if(*(a+SIZE*i+j+1)=='B')qi3=xiahei(i,j,(char *)a);
if(qi==0&&qi1==0&&qi2==0&&qi3==0)return 0;
else return 1;
 }
  int youhei(int i,int j,char *a){
 	i=i+1;int qi=0,qi1=0,qi2=0,qi3=0;
 	*(a+SIZE*i+j)='*';
PAN DI NG
 	if(*(a+SIZE*(i+1)+j)=='B')qi1=youhei(i,j,(char *)a);
if(*(a+SIZE*i+j-1)=='B')qi2=shanghei(i,j,(char *)a);
if(*(a+SIZE*i+j+1)=='B')qi3=xiahei(i,j,(char *)a);
if(qi==0&&qi1==0&&qi2==0&&qi3==0)return 0;
else return 1;
 }
  int shanghei(int i,int j,char *a){
 	j=j-1;int qi=0,qi1=0,qi2=0,qi3=0;
 	*(a+SIZE*i+j)='*';
PAN DI NG
 	if(*(a+SIZE*(i-1)+j)=='B')qi1=zuohei(i,j,(char *)a);
if(*(a+SIZE*(i+1)+j)=='B')qi2=youhei(i,j,(char *)a);
if(*(a+SIZE*i+j-1)=='B')qi3=shanghei(i,j,(char *)a);
if(qi==0&&qi1==0&&qi2==0&&qi3==0)return 0;
else return 1;
 }
  int xiahei(int i,int j,char *a){
 	j=j+1;int qi=0,qi1=0,qi2=0,qi3=0;
 	*(a+SIZE*i+j)='*';
PAN DI NG
 	if(*(a+SIZE*(i-1)+j)=='B')qi1=zuohei(i,j,(char *)a);
if(*(a+SIZE*(i+1)+j)=='B')qi2=youhei(i,j,(char *)a);
if(*(a+SIZE*i+j+1)=='B')qi3=xiahei(i,j,(char *)a);
if(qi==0&&qi1==0&&qi2==0&&qi3==0)return 0;
else return 1;
 }
 
 
int lianjiehei(char *ge,int* jilu,int i,int j){//计算黑棋子串的气 
char a[SIZE][SIZE];int qi=0,qi1=0,qi2=0,qi3=0,qi4=0;
int x,y;
for(x=0;x<SIZE;x++){
	for(y=0;y<SIZE;y++){
		a[x][y]=*(ge+SIZE*x+y);	}
}a[i][j]='*';
 if((a[i+1][j]=='+'|| a[i+1][j]=='#')||
 (a[i-1][j]=='+'|| a[i-1][j]=='#')|| (a[i][j-1]=='#'
||a[i][j-1]=='+')||(a[i][j+1]=='#'||a[i][j+1]=='+')){return 0;}
if(a[i-1][j]=='B')qi1=zuohei(i,j,(char *)a);
if(a[i+1][j]=='B')qi2=youhei(i,j,(char *)a);
if(a[i][j-1]=='B')qi3=shanghei(i,j,(char *)a);
if(a[i][j+1]=='B')qi4=xiahei(i,j,(char *)a);
if(qi1==0&&qi2==0&&qi3==0&&qi4==0&&qi==0){
	for(x=1;x<SIZE-1;x++){
	for(y=1;y<SIZE-1;y++){
		if(a[x][y]=='*'){
			if(x==4&&y==4||x==16&&y==16||
			x==4&&y==16||x==16&&y==4||
			x==4&&y==10||x==16&&y==10||
			x==10&&y==4||x==10&&y==16||y==10&&x==10)
			ge[SIZE*x+y]='#';
			else if(x>0 && x<20 && y>0 && y<20) ge[SIZE*x+y]='+';
			global_baitizi++;}
	}
}}
			 return 0;
}
int lianjiehei1(char *ge,int* jilu,int j,int i){//计算黑棋子串的气 
char b[SIZE][SIZE];int qi=0,qi1=0,qi2=0,qi3=0,qi4=0;
int x,y;
for(x=0;x<SIZE;x++){
	for(y=0;y<SIZE;y++){
		b[x][y]=*(ge+SIZE*x+y);
	}
}b[i][j]='*';
 if((b[i+1][j]=='+'|| b[i+1][j]=='#')||
 (b[i-1][j]=='+'|| b[i-1][j]=='#')|| (b[i][j-1]=='#'
||b[i][j-1]=='+')||(b[i][j+1]=='#'||b[i][j+1]=='+')){return 1;}
if(b[i-1][j]=='B')qi1=zuohei(i,j,(char *)b);
if(b[i+1][j]=='B')qi2=youhei(i,j,(char *)b);
if(b[i][j-1]=='B')qi3=shanghei(i,j,(char *)b);
if(b[i][j+1]=='B')qi4=xiahei(i,j,(char *)b);
if(qi1==0&&qi2==0&&qi3==0&&qi4==0&&qi==0) return 0;
			 else return 1;
}

int jiehei(int *m,char *ge,int* jilu){//计算黑棋打劫的状况 
	int n;n=*m;
	if(*(jilu+4*n)==global_d&&*(jilu+4*n+1)==global_c)
	return 1;
	else return 0;
}

int jiebai(int *m,char *ge,int* jilu){//计算白棋打劫的状况 
	int n;n=*m;
	if(*(jilu+4*n+2)==global_b&&*(jilu+4*n+3)==global_a)
	return 1;
	else return 0;
}

int qibai(int *x,char *ge,int* jilu){//气白 
	int i,j,ret,l=0;//l的值用来判断重下 
	int a,m;m=*x;int p=1;
	for(i=1;i<SIZE-1;i++){
		for(j=1;j<SIZE-1;j++){
			if(ge[SIZE*i+j]=='W'){
		 if(*((char *)ge+SIZE*(i+1)+j)=='+'||*((char *)ge+SIZE*i+(j-1))=='+'
		 ||*((char *)ge+SIZE*(i-1)+j)=='+'||*((char *)ge+SIZE*i+(j+1))=='+'||
		 *((char *)ge+SIZE*(i+1)+j)=='#'||*((char *)ge+SIZE*i+(j-1))=='#'
		 ||*((char *)ge+SIZE*(i-1)+j)=='#'||*((char *)ge+SIZE*i+(j+1))=='#'){
		 continue;}
		else if(*((char *)ge+SIZE*(i+1)+j)!='W'&&*((char *)ge+SIZE*i+(j-1))!='W'
		 &&*((char *)ge+SIZE*(i-1)+j)!='W'&&*((char *)ge+SIZE*i+(j+1))!='W'){
		 	
		 	ret=jiehei(&m,(char*)ge,(int*)jilu);
		 	if(ret==1){//ret代表打劫函数返回的结果 
			 	printf("下法不合法，未找劫材,请重新落子\n");
			 	if(*(jilu+4*m+1)==4&&*(jilu+4*m)==4||*(jilu+4*m+1)==16&&*(jilu+4*m)==16||
			*(jilu+4*m+1)==4&&*(jilu+4*m)==16||*(jilu+4*m+1)==16&&*(jilu+4*m)==4||
			*(jilu+4*m+1)==4&&*(jilu+4*m)==10||*(jilu+4*m+1)==16&&*(jilu+4*m)==10||
			*(jilu+4*m+1)==10&&*(jilu+4*m)==4||*(jilu+4*m+1)==10&&*(jilu+4*m)==16||*(jilu+4*m)==10&&*(jilu+4*m+1)==10)
			ge[SIZE**(jilu+4*m+1)+*(jilu+4*m)]='#';
			else if(*(jilu+4*m+1)>0 && *(jilu+4*m+1)<20 && *(jilu+4*m)>0 && *(jilu+4*m)<20) ge[SIZE**(jilu+4*m+1)+*(jilu+4*m)]='+';
			l=1;
			}
			else {
			if(i==4&&j==4||i==16&&j==16||
			i==4&&j==16||i==16&&j==4||
			i==4&&j==10||i==16&&j==10||
			i==10&&j==4||i==10&&j==16||j==10&&i==10)
			ge[SIZE*i+j]='#';
			else if(i>0 && i<20 && j>0 && j<20) ge[SIZE*i+j]='+';global_heitizi++;
			global_a=i;global_b=j;p=2;}
		}else{
			l=lianjiebai((char*)ge,(int*)jilu,i,j);
		}
		}	}	}	if(p!=2){
			p=lianjiehei1((char*)ge,(int*)jilu,*(jilu+4*m),*(jilu+4*m+1));
		if(p==0){printf("下完后无气，下法错误，请重下\n");
		if(*(jilu+4*m)==4&&*(jilu+4*m+1)==4||*(jilu+4*m)==16&&*(jilu+4*m+1)==16||
			*(jilu+4*m)==4&&*(jilu+4*m+1)==16||*(jilu+4*m)==16&&*(jilu+4*m+1)==4||
			*(jilu+4*m)==4&&*(jilu+4*m+1)==10||*(jilu+4*m)==16&&*(jilu+4*m+1)==10||
			*(jilu+4*m)==10&&*(jilu+4*m+1)==4||*(jilu+4*m)==10&&*(jilu+4*m+1)==16||*(jilu+4*m+1)==10&&*(jilu+4*m)==10)
			ge[SIZE**(jilu+4*m+1)+*(jilu+4*m)]='#';
			else if(*(jilu+4*m+1)>0 && *(jilu+4*m+1)<20 && *(jilu+4*m)>0 && *(jilu+4*m)<20) ge[SIZE**(jilu+4*m+1)+*(jilu+4*m)]='+';
			l=1;}}
	if(l==1)return 1;
	else return 0;
}

int qihei(int *x,char *ge,int* jilu){//气黑 
	int i,j,ret,l=0;
	int a,m;m=*x;int p=1;
	for(i=1;i<SIZE-1;i++){
		for(j=1;j<SIZE-1;j++){
			if(ge[SIZE*i+j]=='B'){
		 if(*((char *)ge+SIZE*(i+1)+j)=='+'||*((char *)ge+SIZE*i+(j-1))=='+'
		 ||*((char *)ge+SIZE*(i-1)+j)=='+'||*((char *)ge+SIZE*i+(j+1))=='+'||
		 *((char *)ge+SIZE*(i+1)+j)=='#'||*((char *)ge+SIZE*i+(j-1))=='#'
		 ||*((char *)ge+SIZE*(i-1)+j)=='#'||*((char *)ge+SIZE*i+(j+1))=='#'){
		 continue;}
		else if(*((char *)ge+SIZE*(i+1)+j)!='B'&&*((char *)ge+SIZE*i+(j-1))!='B'
		 &&*((char *)ge+SIZE*(i-1)+j)!='B'&&*((char *)ge+SIZE*i+(j+1))!='B'){
		 ret=jiebai(&m,(char*)ge,(int*)jilu);
		 	if(ret==1){//ret表示打劫结果 
			 printf("下法不合法，未找劫材,请重新落子\n");
			 if(*(jilu+4*m+3)==4&&*(jilu+4*m+2)==4||*(jilu+4*m+3)==16&&*(jilu+4*m+2)==16||
			*(jilu+4*m+3)==4&&*(jilu+4*m+2)==16||*(jilu+4*m+3)==16&&*(jilu+4*m+2)==4||
			*(jilu+4*m+3)==4&&*(jilu+4*m+2)==10||*(jilu+4*m+3)==16&&*(jilu+4*m+2)==10||
			*(jilu+4*m+3)==10&&*(jilu+4*m+2)==4||*(jilu+4*m+3)==10&&*(jilu+4*m+2)==16||*(jilu+4*m+2)==10&&*(jilu+4*m+3)==10)
			ge[SIZE**(jilu+4*m+3)+*(jilu+4*m+2)]='#';
			else if(*(jilu+4*m+3)>0 && *(jilu+4*m+3)<20 && *(jilu+4*m+2)>0 && *(jilu+4*m+2)<20) ge[SIZE**(jilu+4*m+3)+*(jilu+4*m+2)]='+';
			return 1; 
			}
			 else {
			 if(i==4&&j==4||i==16&&j==16||
			i==4&&j==16||i==16&&j==4||
			i==4&&j==10||i==16&&j==10||
			i==10&&j==4||i==10&&j==16||j==10&&i==10)
			ge[SIZE*i+j]='#';
			else if(i>0 && i<20 && j>0 && j<20) ge[SIZE*i+j]='+';global_baitizi++;
			global_c=i;global_d=j;p=2;}
		}else{
			l=lianjiehei((char*)ge,(int*)jilu,i,j);
		}
		}	}	}if(p!=2){
			p=lianjiebai1((char*)ge,(int*)jilu,*(jilu+4*m+2),*(jilu+4*m+3));
	if(p==0){printf("下完后无气，下法错误，请重下\n");
	if(*(jilu+4*m+2)==4&&*(jilu+4*m+3)==4||*(jilu+4*m+2)==16&&*(jilu+4*m+3)==16||
			*(jilu+4*m+2)==4&&*(jilu+4*m+3)==16||*(jilu+4*m+2)==16&&*(jilu+4*m+3)==4||
			*(jilu+4*m+2)==4&&*(jilu+4*m+3)==10||*(jilu+4*m+2)==16&&*(jilu+4*m+3)==10||
			*(jilu+4*m+2)==10&&*(jilu+4*m+3)==4||*(jilu+4*m+2)==10&&*(jilu+4*m+3)==16||*(jilu+4*m+3)==10&&*(jilu+4*m+2)==10)
			ge[SIZE**(jilu+4*m+3)+*(jilu+4*m+2)]='#';
			else if(*(jilu+4*m+2)>0 && *(jilu+4*m+2)<20 && *(jilu+4*m+3)>0 && *(jilu+4*m+3)<20) ge[SIZE**(jilu+4*m+3)+*(jilu+4*m+2)]='+';
	l=1;}}
		if(l==1)return 1;
	else return 0;
}

void fupan(char *ge,int *jilu) {//进行复盘的操作 
int i; 
	printf("按任意键开始复盘\n") ;
	qipan((char*)ge,(int*)jilu); 
	system("pause");//停顿 
	for( i=0;jilu[4*i]!=0;i++){
		ge[SIZE**(jilu+4*i+1)+*(jilu+4*i)]='B';
		global_a=0;global_b=0;
			qibai(&i,(char*)ge,(int*)jilu);
	qipan((char*)ge,(int*)jilu);
	printf("按任意键继续\n") ;
	system("pause");//停顿 
		ge[SIZE**(jilu+4*i+3)+*(jilu+4*i+2)]='W';
		global_c=0;global_d=0;
	qihei(&i,(char*)ge,(int*)jilu);
	qipan((char*)ge,(int*)jilu);
	printf("按任意键继续\n") ;
	system("pause");
	}
}
