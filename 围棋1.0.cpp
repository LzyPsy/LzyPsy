#include <stdio.h>
#include <stdlib.h>
#define SIZE 21//19+2����߽����� 
#define SIZE2 1000
#define PAN if((*(a+SIZE*(i+1)+j)!='W'&&*(a+SIZE*(i+1)+j)!='B'&&*(a+SIZE*(i+1)+j)!='*')||
#define DI (*(a+SIZE*(i-1)+j)!='W'&&*(a+SIZE*(i-1)+j)!='B'&&*(a+SIZE*(i-1)+j)!='*')|| (*(a+SIZE*i+j+1)!='W'&&*(a+SIZE*i+j+1)!='B'&&*(a+SIZE*i+j+1)!='*') ||
#define NG (*(a+SIZE*i+j-1)!='W'&&*(a+SIZE*i+j-1)!='B'&&*(a+SIZE*i+j-1)!='*')){return 1;}

int global_a,global_b,global_c,global_d;

 struct wrong{//����һ���ṹ���Է�������ֵ 
	int a;
	int b;
};
typedef struct wrong Struct;//�Զ���һ������ 

struct shunxu {//����һ���ṹ���Է���һ���غ����������ӵ����� 
	int a1;
	int a2;
	int a3;
	int a4;
};
typedef struct shunxu Struct2;//�Զ���һ������ 

void qipan(char *ge,int* jilu);//��ӡ���� 
Struct2 luozi(int *m,char *ge,int* jilu);//�ڰ����� 
int qibai(int *x,char *ge,int* jilu);//����׵��� 
int qihei(int *x,char *ge,int* jilu);//����ڵ��� 
Struct wronghei(char *ge,int* jilu);//�ж����� 
Struct wrongbai(char *ge,int* jilu); //�ж����� 
//�����ͨ����ֻ���޷��½����ж� 
int jiehei(int *m,char *ge,int* jilu);//�жϴ����� 
int jiebai(int *m,char *ge,int* jilu);
 int lianjiebai(char *ge,int* jilu,int i,int j);//�����������ϰ��������������� 
 int lianjiehei(char *ge,int* jilu,int i,int j);//�����������Ϻ��������������� 
 void fupan(char *ge,int *jilu);//���и��� 
 
  int zuohei(int i,int j,char *a);//���Ӵ� 
   int youhei(int i,int j,char *a);
    int shanghei(int i,int j,char *a);
     int xiahei(int i,int j,char *a);
    int zuobai(int i,int j,char *a);
   int youbai(int i,int j,char *a);
    int shangbai(int i,int j,char *a);
     int xiabai(int i,int j,char *a);
     
     int lianjiehei1(char *ge,int* jilu,int i,int j);//�ж�������ֹ����������λ�� 
     int lianjiebai1(char *ge,int* jilu,int i,int j);
 
int main(){
	LOOP3:
	printf("\n\n�����Ҫֹͣ�Ծֽ��и��̻����������������ʱ���루-1,-1��\n");
	printf("����������䣬�����ֵ������µ�ʱ�����루-1��-1���������ֵ������µ�ʱ��������һ�Σ�-1��-1��\n");
printf("����������䣬�����ֵ������µ�ʱ�����루-1��-1������\n"); 
	char ge[SIZE][SIZE];
	int i,j,huihe;//�غ��� 
	int jilu[SIZE2];
	for(i=0;i<SIZE2;i++){
		jilu[i]=0;	}
	int baitizi=0,heitiz=0; 
	Struct2 result;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			if(i==4&&j==4||i==16&&j==16||
			i==4&&j==16||i==16&&j==4||
			i==4&&j==10||i==16&&j==10||
			i==10&&j==4||i==10&&j==16||j==10&&i==10)//�ǣ��ߣ���Ԫ 
			ge[i][j]='#';
			else if(i>0&&i<20&&j>0&&j<20)ge[i][j]='+';//����� 
			else ge[i][j]='*';//�߽��� 
		}
	}
	qipan((char*)ge,(int*)jilu);
	for(huihe=0;huihe<500;huihe++){
		result=luozi(&huihe,(char*)ge,&jilu[0]);
		jilu[4*huihe]=result.a1;jilu[4*huihe+1]=result.a2;
		jilu[4*huihe+2]=result.a3;jilu[4*huihe+3]=result.a4;//���ܽṹ�巵�ص�����ֵ 
		if(jilu[4*huihe]==0||jilu[4*huihe+1]==0||jilu[4*huihe+2]==0||jilu[4*huihe+3]==0)break;//�ж϶Ծ��Ƿ���� 
	}int again2;int again;//���ص����̵� 
	loop:
	printf("\n��ѡ�����������̻��ؿ���1.��������  2.����  3.�ؿ�\n");
	scanf("%d",&again2);
	if(again2==1)return 0;
	else if(again2==3)goto LOOP3;
	else if(again2!=2)goto loop;
	else {
	LOOP:
		for(i=0;i<SIZE;i++){//���¹滮���� 
		for(j=1;j<SIZE-1;j++){
			if(i==4&&j==4||i==16&&j==16||
			i==4&&j==16||i==16&&j==4||
			i==4&&j==10||i==16&&j==10||
			i==10&&j==4||i==10&&j==16||j==10&&i==10)//�ǣ��ߣ���Ԫ 
			ge[i][j]='#';
			else if(i>0&&i<20&&j>0&&j<20)ge[i][j]='+';//����� 
			else ge[i][j]='*';//�߽��� 
		}
	}
	fupan((char*)ge,&jilu[0]);//���и��� 
	LOOP2:
	printf("\n��ѡ���ٴθ��̻����������ؿ���1.��������  2.�ٴθ���  3.�ؿ�\n");
	scanf("%d",&again);
	if(again==1)return 0;
	else if(again==2)goto LOOP;
	else if(again==3)goto LOOP3; 
	else goto LOOP2;}
} 

void qipan(char *ge,int* jilu){//��ӡ���� 
	int i,j,m; 
	int zuobiao[20];//����  ��X��  ��Y�� 
	zuobiao[0]=0;
	printf("%d    ",zuobiao[0]);
	for(i=1;i<10;i++){
		zuobiao[i]=i;
		printf("%d     ",zuobiao[i]);
	}	for(i=10;i<20;i++){
		zuobiao[i]=i;
		printf("%d    ",zuobiao[i]);
	}
	printf(" --->X��") ; //���������� 
	for(i=1;i<SIZE-1;i++){
		m=i-1;
		printf("\n");
		if(m<9)printf("%d  ",zuobiao[m+1]);
		else printf("%d ",zuobiao[m+1]);
		for(j=1;j<SIZE-1;j++){
			if(ge[SIZE*i+j]=='B')printf(" ��� ");//������ 
			else if(ge[SIZE*i+j]=='W')printf(" ��� ");//������ 
			else printf("  %c%c  ",ge[SIZE*i+j],ge[SIZE*i+j]);
		}if(m<9)printf("%d  ",zuobiao[m+1]);
		else printf("%d ",zuobiao[m+1]);
		printf("\n");
		if(m<9)printf("%d  ",zuobiao[m+1]);
		else printf("%d ",zuobiao[m+1]);
			for(j=1;j<SIZE-1;j++){
			if(ge[SIZE*i+j]=='B')printf(" ��� ");
			else if(ge[SIZE*i+j]=='W')printf(" ��� ");
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
	printf("\nY\n��\n");	
}

Struct wronghei(char *ge,int* jilu){//��������������� 
int i,j;
Struct c;
	scanf("%d%d",&j,&i) ;
		fflush(stdin);
	if(j==-1&&i==-1){
		c.a=0;c.b=0;return c;
	}
	else if(ge[SIZE*i+j]!='+'&&ge[SIZE*i+j]!='#'){
		printf("��������������������꣨�ص��򳬳���Χ��\n");
		wronghei((char*)ge,(int*)jilu);
	}
		else if(j<1||j>20||i<1||i>20){
		printf("��������������������꣨�ص��򳬳���Χ��\n");
		wronghei((char*)ge,(int*)jilu);
	}else {ge[SIZE*i+j]='B';
	c.a=j;c.b=i;
	return c;} 
}

Struct wrongbai(char *ge,int* jilu){//��������������� 
int i,j;
Struct d;
	scanf("%d%d",&j,&i) ;
		fflush(stdin);
		if(j==-1&&i==-1){
		d.a=0;d.b=0;return d;}	
	else if(ge[SIZE*i+j]!='+'&&ge[SIZE*i+j]!='#'){
		printf("��������������������꣨�ص��򳬳���Χ��\n");
		wrongbai((char*)ge,(int*)jilu);
	}	else if(j<1||j>20||i<1||i>20){
		printf("��������������������꣨�ص��򳬳���Χ��\n");
		wrongbai((char*)ge,(int*)jilu);
	}else {ge[SIZE*i+j]='W'; 
	d.a=j;d.b=i;
	return d;} 
}

Struct2 luozi(int *m,char *ge,int* jilu){
	int i,j,n;
	int x=0,y=0;//�ж��Ƿ���δ�ҽٲ����� 
	Struct2 resu;//�����ĸ�����ֵ 
	n=*m;
		Struct result1;
	LOOP3:

	printf("���������(��������)\n");
	result1=wronghei((char*)ge,(int*)jilu);
		*(jilu+4*n)=result1.a;*(jilu+4*n+1)=result1.b;
		global_a=0;global_b=0;
x=qibai(&n,(char*)ge,(int*)jilu);
	if(x!=0)goto LOOP3;
	qipan((char*)ge,(int*)jilu);
		Struct result2;
	LOOP4:
	
	printf("���������(��������)\n");
result2=wrongbai((char*)ge,(int*)jilu);
	*(jilu+4*n+2)=result2.a;*(jilu+4*n+3)=result2.b;
	global_c=0;global_d=0;
	y=qihei(&n,(char*)ge,(int*)jilu);
	if(y!=0)goto LOOP4;
	qipan((char*)ge,(int*)jilu);
		resu.a1=*(jilu+4*n);resu.a2=*(jilu+4*n+1);resu.a3=*(jilu+4*n+2);resu.a4=*(jilu+4*n+3);
		return resu;
}

int zuobai(int i,int j,char *a){printf("1\n");//ע�⣺��������û��˳���� 
 	i=i-1;int qi=0,qi1=0,qi2=0,qi3=0;
 	*(a+SIZE*i+j)='*';
PAN DI NG
 	if(*(a+SIZE*(i-1)+j)=='W')qi1=zuobai(i,j,(char *)a);
if(*(a+SIZE*i+j-1)=='W')qi2=shangbai(i,j,(char *)a);
if(*(a+SIZE*i+j+1)=='W')qi3=xiabai(i,j,(char *)a);
if(qi==0&&qi1==0&&qi2==0&&qi3==0)return 0;
else return 1;
 }
  int youbai(int i,int j,char *a){printf("2\n");
 	i=i+1;int qi=0,qi1=0,qi2=0,qi3=0;
 	*(a+SIZE*i+j)='*';
PAN DI NG
 	if(*(a+SIZE*(i+1)+j)=='W')qi1=youbai(i,j,(char *)a);
if(*(a+SIZE*i+j-1)=='W')qi2=shangbai(i,j,(char *)a);
if(*(a+SIZE*i+j+1)=='W')qi3=xiabai(i,j,(char *)a);
if(qi==0&&qi1==0&&qi2==0&&qi3==0)return 0;
else return 1;
 }
  int shangbai(int i,int j,char *a){printf("3\n");
 	j=j-1;int qi=0,qi1=0,qi2=0,qi3=0;
 	*(a+SIZE*i+j)='*';
PAN DI NG
 	if(*(a+SIZE*(i-1)+j)=='W')qi1=zuobai(i,j,(char *)a);
if(*(a+SIZE*(i+1)+j)=='W')qi2=youbai(i,j,(char *)a);
if(*(a+SIZE*i+j-1)=='W')qi3=shangbai(i,j,(char *)a);
if(qi==0&&qi1==0&&qi2==0&&qi3==0)return 0;
else return 1;
 }
  int xiabai(int i,int j,char *a){printf("4\n");
 	j=j+1;int qi=0,qi1=0,qi2=0,qi3=0;
 	*(a+SIZE*i+j)='*';
PAN DI NG
 	if(*(a+SIZE*(i-1)+j)=='W')qi1=zuobai(i,j,(char *)a);
if(*(a+SIZE*(i+1)+j)=='W')qi2=youbai(i,j,(char *)a);
if(*(a+SIZE*i+j+1)=='W')qi3=xiabai(i,j,(char *)a);
if(qi==0&&qi1==0&&qi2==0&&qi3==0)return 0;
else return 1;
 }

int lianjiebai(char *ge,int* jilu,int i,int j){//��������Ӵ����� 
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
		}
	}
}}
	 return 0;
		}
  
  int lianjiebai1(char *ge,int* jilu,int j,int i){//��������Ӵ����� 
char b[SIZE][SIZE];int qi=0,qi1=0,qi2=0,qi3=0,qi4=0;
int x,y;
for(x=0;x<SIZE;x++){
	for(y=0;y<SIZE;y++){
		b[x][y]=*(ge+SIZE*x+y);
	}
}
b[i][j]='*';printf("\n\n%c%c%c%c\n\n",b[i-1][j],b[i+1][j],b[i][j-1],b[i][j+1]);
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
		
 int zuohei(int i,int j,char *a){printf("1\n");
 	i=i-1;int qi=0,qi1=0,qi2=0,qi3=0;
 	*(a+SIZE*i+j)='*';
PAN DI NG
 	if(*(a+SIZE*(i-1)+j)=='B')qi1=zuohei(i,j,(char *)a);
if(*(a+SIZE*i+j-1)=='B')qi2=shanghei(i,j,(char *)a);
if(*(a+SIZE*i+j+1)=='B')qi3=xiahei(i,j,(char *)a);
if(qi==0&&qi1==0&&qi2==0&&qi3==0)return 0;
else return 1;
 }
  int youhei(int i,int j,char *a){printf("2\n");
 	i=i+1;int qi=0,qi1=0,qi2=0,qi3=0;
 	*(a+SIZE*i+j)='*';
PAN DI NG
 	if(*(a+SIZE*(i+1)+j)=='B')qi1=youhei(i,j,(char *)a);
if(*(a+SIZE*i+j-1)=='B')qi2=shanghei(i,j,(char *)a);
if(*(a+SIZE*i+j+1)=='B')qi3=xiahei(i,j,(char *)a);
if(qi==0&&qi1==0&&qi2==0&&qi3==0)return 0;
else return 1;
 }
  int shanghei(int i,int j,char *a){printf("3\n");
 	j=j-1;int qi=0,qi1=0,qi2=0,qi3=0;
 	*(a+SIZE*i+j)='*';
PAN DI NG
 	if(*(a+SIZE*(i-1)+j)=='B')qi1=zuohei(i,j,(char *)a);
if(*(a+SIZE*(i+1)+j)=='B')qi2=youhei(i,j,(char *)a);
if(*(a+SIZE*i+j-1)=='B')qi3=shanghei(i,j,(char *)a);
if(qi==0&&qi1==0&&qi2==0&&qi3==0)return 0;
else return 1;
 }
  int xiahei(int i,int j,char *a){printf("4\n");
 	j=j+1;int qi=0,qi1=0,qi2=0,qi3=0;
 	*(a+SIZE*i+j)='*';
PAN DI NG
 	if(*(a+SIZE*(i-1)+j)=='B')qi1=zuohei(i,j,(char *)a);
if(*(a+SIZE*(i+1)+j)=='B')qi2=youhei(i,j,(char *)a);
if(*(a+SIZE*i+j+1)=='B')qi3=xiahei(i,j,(char *)a);
if(qi==0&&qi1==0&&qi2==0&&qi3==0)return 0;
else return 1;
 }
 
 
int lianjiehei(char *ge,int* jilu,int i,int j){//��������Ӵ����� 
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
			else if(x>0 && x<20 && y>0 && y<20) ge[SIZE*x+y]='+';}
	}
}}
			 return 0;
}
int lianjiehei1(char *ge,int* jilu,int j,int i){//��������Ӵ����� 
char b[SIZE][SIZE];int qi=0,qi1=0,qi2=0,qi3=0,qi4=0;
int x,y;
for(x=0;x<SIZE;x++){
	for(y=0;y<SIZE;y++){
		b[x][y]=*(ge+SIZE*x+y);
	}
}b[i][j]='*';printf("\n\n%c%c%c%c\n\n",b[i-1][j],b[i+1][j],b[i][j-1],b[i][j+1]);
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

int jiehei(int *m,char *ge,int* jilu){//��������ٵ�״�� 
	int n;n=*m;
		printf("\n%d %d %d %d\n",*(jilu+4*n),*(jilu+4*n-4),*(jilu+4*n+1),*(jilu+4*n-3));
	if(*(jilu+4*n)==global_d&&*(jilu+4*n+1)==global_c)
	return 1;
	else return 0;
}

int jiebai(int *m,char *ge,int* jilu){//��������ٵ�״�� 
	int n;n=*m;
	printf("\n%d %d %d %d\n",*(jilu+4*n+2),*(jilu+4*n-2),*(jilu+4*n+3),*(jilu+4*n-1));
	if(*(jilu+4*n+2)==global_b&&*(jilu+4*n+3)==global_a)
	return 1;
	else return 0;
}

int qibai(int *x,char *ge,int* jilu){//���� 
	int i,j,ret,l=0;//l��ֵ�����ж����� 
	int a,m;m=*x;int p=1;printf("\n\n\n%d\n\n\n%d\n",*(jilu+4*m),*(jilu+4*m+1));
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
		 	if(ret==1){//ret�����ٺ������صĽ�� 
			 	printf("�·����Ϸ���δ�ҽٲ�,����������\n");
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
			else if(i>0 && i<20 && j>0 && j<20) ge[SIZE*i+j]='+';
			global_a=i;global_b=j;p=2;}
		}else{
			l=lianjiebai((char*)ge,(int*)jilu,i,j);
		}
		}	}	}	if(p!=2){printf("\n\n\n%d\n\n\n%d\n",*(jilu+4*m),*(jilu+4*m+1));
			p=lianjiehei1((char*)ge,(int*)jilu,*(jilu+4*m),*(jilu+4*m+1));
		if(p==0){printf("������������·�����������\n");
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

int qihei(int *x,char *ge,int* jilu){//���� 
	int i,j,ret,l=0;
	int a,m;m=*x;int p=1;printf("\n\n\n%d\n\n\n%d\n",*(jilu+4*m+2),*(jilu+4*m+3));
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
		 	if(ret==1){//ret��ʾ��ٽ�� 
			 printf("�·����Ϸ���δ�ҽٲ�,����������\n");
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
			else if(i>0 && i<20 && j>0 && j<20) ge[SIZE*i+j]='+';
			global_c=i;global_d=j;p=2;}
		}else{
			l=lianjiehei((char*)ge,(int*)jilu,i,j);
		}
		}	}	}if(p!=2){printf("\n\n\n%d\n\n\n%d\n",*(jilu+4*m+2),*(jilu+4*m+3));
			p=lianjiebai1((char*)ge,(int*)jilu,*(jilu+4*m+2),*(jilu+4*m+3));
	if(p==0){printf("������������·�����������\n");
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

void fupan(char *ge,int *jilu) {//���и��̵Ĳ��� 
int i; 
	printf("���������ʼ����\n") ;
	qipan((char*)ge,(int*)jilu); 
	system("pause");//ͣ�� 
	for( i=0;jilu[4*i]!=0;i++){
		ge[SIZE**(jilu+4*i+1)+*(jilu+4*i)]='B';
		global_a=0;global_b=0;
			qibai(&i,(char*)ge,(int*)jilu);
	qipan((char*)ge,(int*)jilu);
	printf("�����������\n") ;
	system("pause");//ͣ�� 
		ge[SIZE**(jilu+4*i+3)+*(jilu+4*i+2)]='W';
		global_c=0;global_d=0;
	qihei(&i,(char*)ge,(int*)jilu);
	qipan((char*)ge,(int*)jilu);
	printf("�����������\n") ;
	system("pause");
	}
}
