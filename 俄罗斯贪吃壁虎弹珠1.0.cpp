#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 27//25*25�����򼰱߽� 
#define MAXX max(x1,max(x2,x3))
#define MINX min(x1,min(x2,x3))
#define MAXY max(y1,max(y2,y3))
#define MINY min(y1,min(y2,y3))
#define BIANLI 
struct a{//��¼���� 
	int x;
	int y; 
};
typedef struct a jilu;
jilu sheshen[100];

char zuobiao[SIZE][SIZE];
int x1,y1,x2,y2,x3,y3;
int jifen=0;
int speed;
int zhuangtai=0;
int k,l;

int max(int a,int b){
	return a>=b?a:b;
}
int min(int a,int b){
	return a>b?b:a;
}

void quyu(char *zuobiao);//��ʼ����Ϸ���� 
void jiemian();//��ӡ���� 
void ditu(char *zuobiao);//��ӡ��ͼ 
void chushihua(char *zuobiao);//��ʼ��ʳ���ͱڻ��� 
void yidong(char *zuobiao); //�����ƶ� 
int shang(char *zuobiao);//�����ƶ� 
int xia(char *zuobiao);//�����ƶ� 
int zuo(char *zuobiao);//�����ƶ� 
int you(char *zuobiao);//�����ƶ� 
void jiashiwu(char *zuobiao); //ˢ�³Ե���ʳ�� 
void jiazhangai(char *zuobiao);//�����ϰ��� 
void jieshu();//��ӡGAME OVER����
void eluosi(char *zuobiao);//������ɶ���˹���� 
void eluosiyidong(char *zuobiao);//����˹������ƶ� 
void  gotoxy( int  x,  int  y) //gotoxy Դ������
{
COORD pos;
pos.X = x ;
pos.Y = y ;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void bianli(int fang){//�������� 
	int i;
	int t1,t2,p1,p2;
			t1=sheshen[0].x;
		t2=sheshen[0].y;
	if(fang==1){
	for(i=1;i<100;i++){
		if(sheshen[i].x==0&&sheshen[i].y==0)break;
		p1=sheshen[i].x;
		p2=sheshen[i].y;
		sheshen[i].x=t1;
		sheshen[i].y=t2;
		t1=p1;t2=p2;
	}sheshen[0].x--;
	}
		if(fang==2){
	for(i=1;i<100;i++){
		if(sheshen[i].x==0&&sheshen[i].y==0)break;
		p1=sheshen[i].x;
		p2=sheshen[i].y;
		sheshen[i].x=t1;
		sheshen[i].y=t2;
		t1=p1;t2=p2;
	}sheshen[0].x++;
	}
		if(fang==3){
	for(i=1;i<100;i++){
		if(sheshen[i].x==0&&sheshen[i].y==0)break;
		p1=sheshen[i].x;
		p2=sheshen[i].y;
		sheshen[i].x=t1;
		sheshen[i].y=t2;
		t1=p1;t2=p2;
	}sheshen[0].y--;
	}
		if(fang==4){
	for(i=1;i<100;i++){
		if(sheshen[i].x==0&&sheshen[i].y==0)break;
		p1=sheshen[i].x;
		p2=sheshen[i].y;
		sheshen[i].x=t1;
		sheshen[i].y=t2;
		t1=p1;t2=p2;
	}sheshen[0].y++;
	}
}
void tianjia(int x3,int y3){//������� 
int i;
	for(i=0;i<100;i++){
		if(sheshen[i].x==0&&sheshen[i].y==0){
			sheshen[i].x=x3;sheshen[i].y=y3;break;
	}else continue;}
}
int fanhui(){
	int i;
		for(i=0;i<100;i++){
		if(sheshen[i].x==0&&sheshen[i].y==0)break;
	}return i-1;
}
int main(){
	LOOP:
		jifen=0;
	int choice; 
	jiemian();
    quyu((char *)zuobiao);
    chushihua((char *)zuobiao);
	ditu((char *)zuobiao);
		printf("������W(��),S(��),A(��),D(��)\n");
	yidong((char *)zuobiao);
	jieshu();
		system("cls");
		system("color 0A");
	menu:
	printf("��ѡ���ؿ���������� 1.�ؿ� 2.��������\n");
	scanf("%d",&choice);
	fflush(stdin);
	if(choice==1)goto LOOP;
	else if(choice==2)return 0;
	else goto menu;
} 

void jieshu(){
		system("cls");
		system("color 0D");
	printf("    **********����˹̰�Աڻ���Ϸ**********\n");
    printf("            GAME OVER  �������� %d\n",jifen) ;
	printf("    ********̫���ˣ��´μ���Ŭ����********\n");
	system("pause");
}
void quyu(char *zuobiao){
	int i,j;
	for(i=0;i<SIZE;i++){
	for(j=0;j<SIZE;j++){
		if(i==0||j==0||i==26||j==26)*(zuobiao+SIZE*i+j)='#';
		else *(zuobiao+SIZE*i+j)=' ';
	}}
} 

void jiemian(){
	system("cls");
	system("color 0C");
	printf("    **********����˹̰�Աڻ���Ϸ**********\n");
	printf("            ү�����Լ�̽������ȥ��\n") ;
	printf("    ***********���������ʼ��Ϸ***********\n");
	system("pause");
	system("cls");
	system("color 0E");
	printf("*���ˣ����Ǹ������ڼ��°ɡ�\n");
	printf("*��ʼ�������Ϊ3��С�ߣ�15���ϰ��㣬4��ʳ���\n") ;
	printf("*����������죬����ᵼ������\n");
	printf("*1.* ����2.@ ��ͷ��3.# �߽缰�ϰ��4. & ����˹���飬5.$ Ϊʳ��,6.oΪ����\n");
	printf("*����˹�����Ϊ���ģ�ֱ�ģ����ģ����ģ�L�������֣��������\n");
	 printf("*@ͷײ#��&��*������*��ײ&��β\n");
	 printf("*ÿ��һ���������һ���ϰ���#\n"); 
	  printf("*ÿ��һ��$����һ�ζ���˹������׹\n");
	  printf("*����˹������ϰ����ʳ��ҪӲ�����Ի�ݻ��ϰ��ﲢˢ��ʳ���\n");
	   printf("*��Ϸ��ʼ�ӵ�ͼ���Ͻǻᵯ��һ�����飬�ԶԽ��߷����ƶ���\n*������ͷ�������ϰ������˹����,ʳ�������һ���Խ��߷��򷴵�\n");
	   printf("*ͬʱ��ײ�����ϰ��Ｐ����˹���鱻�ݻ٣��߽�ͬ���ᱻ��,������˹����Ķѻ����޸��߽�\n"); 
	    printf("*�߽�ͬ���ᱻ�ݻ�,������Ϊ����������Ӱ�죨ʵ���������Ѷ�̫�����治ת��\n"); 
	    printf("*�����鵯���𻵵ı߽�(���ϰ���)��������һ��ʳ���\n"); 
	       printf("*�Ҳ����Ѿ����������Ⲣ����һ��������Ϸ������������Ϸ\n"); 
	       printf("*���ֵĸߵ͸������������ʱ������ǳ���\n"); 
	    printf("*�������ö���˹����͵���������Ϸ����\n");
	  printf("*�����Գ�ʳ������Ϊ׼���������ճ���Ϊ׼���������̫���Ա���\n");
	 system("pause");
	 system("cls");	system("color 0B");
	 menu:
	 printf("\n\n*********��ѡ����Ϸ�Ѷ�**********\n");
	 printf("*****1.S��\n*****2.A��\n*****3.B��\n*****4.C��\n");
	 scanf("%d",&speed);
	 if(speed==1)speed=50;
	 else if(speed==2)speed=100;
	  else if(speed==3)speed=150;
	    else if(speed==4)speed=180;
	 else goto menu;
}

void ditu(char *zuobiao){
	system("color 0F");
	system("cls");
int i,j;
for(i=0;i<SIZE;i++){
	for(j=0;j<SIZE;j++){
		printf("%c ",*(zuobiao+SIZE*i+j));
	}printf("\n");
}
	}
	
	void danzhuyidong(char *zuobiao){
		int m,n;
		m=k;n=l;
		*(zuobiao+SIZE*k+l)=' ';
		gotoxy(2*l,k);
		printf("%c",*(zuobiao+SIZE*k+l));
		if(zhuangtai==1){//���� 
		
			if(*(zuobiao+SIZE*(k+1)+l+1)==' '){
				k++;l++;
				*(zuobiao+SIZE*k+l)='o';
				gotoxy(2*l,k);
				printf("%c",*(zuobiao+SIZE*k+l));
			}
			else if(*(zuobiao+SIZE*(k+1)+l)!=' '&&*(zuobiao+SIZE*k+l+1)==' '){
				zhuangtai=3;
					k--;l++;
				*(zuobiao+SIZE*k+l)='o';
				gotoxy(2*l,k);
				printf("%c",*(zuobiao+SIZE*k+l));
			}
			else if(*(zuobiao+SIZE*(k+1)+l)==' '&&*(zuobiao+SIZE*k+l+1)!=' '){
				zhuangtai=2;
						k++;l--;
				*(zuobiao+SIZE*k+l)='o';
				gotoxy(2*l,k);
				printf("%c",*(zuobiao+SIZE*k+l));
			}
			else {
				zhuangtai=4;
					k--;l--;
				*(zuobiao+SIZE*k+l)='o';
				gotoxy(2*l,k);
				printf("%c",*(zuobiao+SIZE*k+l));
			}
			
				if(*(zuobiao+SIZE*(m+1)+n+1)=='$'){
			jiashiwu((char *)zuobiao);
			*(zuobiao+SIZE*(m+1)+n+1)=' ';
				gotoxy(2*(n+1),m+1);
		printf("%c",*(zuobiao+SIZE*(m+1)+n+1));}
		else if(*(zuobiao+SIZE*(m+1)+n+1)=='#'){
			if(m+1>=1&&m+1<=25&&n+1>=1&&n+1<=25)
			*(zuobiao+SIZE*(m+1)+n+1)=' ';
			else *(zuobiao+SIZE*(m+1)+n+1)='+';
				gotoxy(2*(n+1),m+1);
		printf("%c",*(zuobiao+SIZE*(m+1)+n+1));
		}
		else if(*(zuobiao+SIZE*(m+1)+n+1)=='+')
		jiashiwu((char *)zuobiao);
			
		}
		else if(zhuangtai==2){//���� 
		
			if(*(zuobiao+SIZE*(k+1)+l-1)==' '){
				k++;l--;
				*(zuobiao+SIZE*k+l)='o';
				gotoxy(2*l,k);
				printf("%c",*(zuobiao+SIZE*k+l));
			}
			else if(*(zuobiao+SIZE*(k+1)+l)==' '&&*(zuobiao+SIZE*k+l-1)!=' '){
				zhuangtai=1;
					k++;l++;
				*(zuobiao+SIZE*k+l)='o';
				gotoxy(2*l,k);
				printf("%c",*(zuobiao+SIZE*k+l));
			}
			else if(*(zuobiao+SIZE*(k+1)+l)!=' '&&*(zuobiao+SIZE*k+l-1)==' '){
				zhuangtai=4;
					k--;l--;
				*(zuobiao+SIZE*k+l)='o';
				gotoxy(2*l,k);
				printf("%c",*(zuobiao+SIZE*k+l));
			}
			else {
				zhuangtai=3;
					k--;l++;
				*(zuobiao+SIZE*k+l)='o';
				gotoxy(2*l,k);
				printf("%c",*(zuobiao+SIZE*k+l));
			}
				if(*(zuobiao+SIZE*(m+1)+n-1)=='$'){
			jiashiwu((char *)zuobiao);
			*(zuobiao+SIZE*(m+1)+n-1)=' ';
				gotoxy(2*(n-1),m+1);
		printf("%c",*(zuobiao+SIZE*(m+1)+n-1));}
		else if(*(zuobiao+SIZE*(m+1)+n-1)=='#'){
			if(m+1>=1&&m+1<=25&&n-1>=1&&n-1<=25)
			*(zuobiao+SIZE*(m+1)+n-1)=' ';
			else *(zuobiao+SIZE*(m+1)+n-1)='+';
				gotoxy(2*(n-1),m+1);
		printf("%c",*(zuobiao+SIZE*(m+1)+n-1));
		}
		else if(*(zuobiao+SIZE*(m+1)+n-1)=='+')
		jiashiwu((char *)zuobiao);
			
		}
		else if(zhuangtai==3){//���� 
		
			if(*(zuobiao+SIZE*(m-1)+n+1)=='$'){
			jiashiwu((char *)zuobiao);
			*(zuobiao+SIZE*(m-1)+n+1)=' ';
				gotoxy(2*(n+1),m-1);
		printf("%c",*(zuobiao+SIZE*(m-1)+n+1));}
		else if(*(zuobiao+SIZE*(m-1)+n+1)=='#'){
			if(m-1>=1&&m-1<=25&&n+1>=1&&n+1<=25)
			*(zuobiao+SIZE*(m-1)+n+1)=' ';
			else *(zuobiao+SIZE*(m-1)+n+1)='+';
				gotoxy(2*(n+1),m-1);
		printf("%c",*(zuobiao+SIZE*(m-1)+n+1));
		}
		else if(*(zuobiao+SIZE*(m-1)+n+1)=='+')
		jiashiwu((char *)zuobiao);
		
			if(*(zuobiao+SIZE*(k-1)+l+1)==' '){
				k--;l++;
				*(zuobiao+SIZE*k+l)='o';
				gotoxy(2*l,k);
				printf("%c",*(zuobiao+SIZE*k+l));
			}
			else if(*(zuobiao+SIZE*(k-1)+l)!=' '&&*(zuobiao+SIZE*k+l+1)==' '){
			zhuangtai=1;
					k++;l++;
				*(zuobiao+SIZE*k+l)='o';
				gotoxy(2*l,k);
				printf("%c",*(zuobiao+SIZE*k+l));
			}
			else if(*(zuobiao+SIZE*(k-1)+l)==' '&&*(zuobiao+SIZE*k+l+1)!=' '){
				zhuangtai=4;
					k--;l--;
				*(zuobiao+SIZE*k+l)='o';
				gotoxy(2*l,k);
				printf("%c",*(zuobiao+SIZE*k+l));
			}
			else {
					zhuangtai=2;
						k++;l--;
				*(zuobiao+SIZE*k+l)='o';
				gotoxy(2*l,k);
				printf("%c",*(zuobiao+SIZE*k+l));
			}
		}
		else if(zhuangtai==4){//����
		
			if(*(zuobiao+SIZE*(m-1)+n-1)=='$'){
			jiashiwu((char *)zuobiao);
			*(zuobiao+SIZE*(m-1)+n-1)=' ';
				gotoxy(2*(n-1),m-1);
		printf("%c",*(zuobiao+SIZE*(m-1)+n-1));}
		else if(*(zuobiao+SIZE*(m-1)+n-1)=='#'){
			if(m-1>=1&&m-1<=25&&n-1>=1&&n-1<=25)
			*(zuobiao+SIZE*(m-1)+n-1)=' ';
			else *(zuobiao+SIZE*(m-1)+n-1)='+';
				gotoxy(2*(n-1),m-1);
		printf("%c",*(zuobiao+SIZE*(m-1)+n-1));
		}
		else if(*(zuobiao+SIZE*(m-1)+n-1)=='+')
		jiashiwu((char *)zuobiao);
		
			if(*(zuobiao+SIZE*(k-1)+l-1)==' '){
				k--;l--;
				*(zuobiao+SIZE*k+l)='o';
				gotoxy(2*l,k);
				printf("%c",*(zuobiao+SIZE*k+l));
			}
			else if(*(zuobiao+SIZE*(k-1)+l)==' '&&*(zuobiao+SIZE*k+l-1)!=' '){
					zhuangtai=2;
						k++;l--;
				*(zuobiao+SIZE*k+l)='o';
				gotoxy(2*l,k);
				printf("%c",*(zuobiao+SIZE*k+l));
			}
				else if(*(zuobiao+SIZE*(k-1)+l)==' '&&*(zuobiao+SIZE*k+l-1)!=' '){
					zhuangtai=3;
					k--;l++;
				*(zuobiao+SIZE*k+l)='o';
				gotoxy(2*l,k);
				printf("%c",*(zuobiao+SIZE*k+l));
			}
			else {
					zhuangtai=1;
					k++;l++;
				*(zuobiao+SIZE*k+l)='o';
				gotoxy(2*l,k);
				printf("%c",*(zuobiao+SIZE*k+l));
			}
		}
				*(zuobiao+SIZE*k+l)='o';
		gotoxy(2*l,k);
		printf("%c",*(zuobiao+SIZE*k+l));
	}
	
void chushihua(char *zuobiao){
	//��ʼ������
	*(zuobiao+SIZE+1)='o';
	k=1;l=1;
	zhuangtai=1; 
	int w;
	for(w=0;w<100;w++){
		sheshen[w].x=0;sheshen[w].y=0;
	}
	srand(time(NULL));
		int fangxiang;//��ʼ���ڻ� 
	x1=rand()%22+3;
    y1=rand()%22+3;
		fangxiang=rand()%4+1;
		if(fangxiang==1&&x1-2>=1){x2=x1-1;x3=x1-2;y2=y1;y3=y1;}
		else if(fangxiang==2&&x1+2<=25){x2=x1+1;x3=x1+2;y2=y1;y3=y1;}
		else if(fangxiang==3&&y1-2>=1){y2=y1-1;y3=y1-2;x2=x1;x3=x1;}
		else if(fangxiang==4&&y1+2<=25){y2=y1+1;y3=y1+2;x2=x1;x3=x1;}
		*(zuobiao+SIZE*x1+y1)='@';
		*(zuobiao+SIZE*x2+y2)='*';
		*(zuobiao+SIZE*x3+y3)='*';
		sheshen[0].x=x1;sheshen[0].y=y1;
		sheshen[1].x=x2;sheshen[1].y=y2;
		sheshen[2].x=x3;sheshen[2].y=y3;
		
	int a,b,c,d,e,f,g,h;//��ʼʳ������� 
	srand(time(NULL));
	a=rand()%25+1;b=rand()%25+1;
	c=rand()%25+1;d=rand()%25+1;
	e=rand()%25+1;f=rand()%25+1;
	g=rand()%25+1;h=rand()%25+1;
	while(a==x1&&b==y1||a==x2&&b==y2||a==x3&&b==y3)a=rand()%25+1;b=rand()%25+1;
	while(c==x1&&d==y1||c==x2&&d==y2||c==x3&&d==y3)c=rand()%25+1;d=rand()%25+1;
	while(e==x1&&f==y1||e==x2&&f==y2||e==x3&&f==y3)e=rand()%25+1;f=rand()%25+1;
	while(g==x1&&h==y1||g==x2&&h==y2||g==x3&&h==y3)g=rand()%25+1;h=rand()%25+1;
	*(zuobiao+SIZE*a+b)='$';
	*(zuobiao+SIZE*c+d)='$';
	*(zuobiao+SIZE*e+f)='$';
	*(zuobiao+SIZE*g+h)='$';
	//��ʼ���ϰ��� 
	int m,n;int i;
for(i=0;i<15;i++){
	m=rand()%25+1;
	n=rand()%25+1;
	while(*(zuobiao+SIZE*m+n)!=' '){m=rand()%25+1;n=rand()%25+1;}
	*(zuobiao+SIZE*m+n)='#';
}	
}

    void jiashiwu(char *zuobiao){
    	int a,b;
    	srand(time(NULL));
    	a=rand()%25+1;b=rand()%25+1;
    	while(*(zuobiao+SIZE*a+b)!=' '){a=rand()%25+1;b=rand()%25+1;}
    	*(zuobiao+SIZE*a+b)='$';jifen++;
  gotoxy(2*b,a);
    printf("%c",*(zuobiao+SIZE*a+b));
	}
	
	void jiazhangai(char *zuobiao){
    	int a,b;
    	srand(time(NULL));
    	a=rand()%25+1;b=rand()%25+1;
    	while(*(zuobiao+SIZE*a+b)!=' '||*(zuobiao+SIZE*a+b+1)!=' '||*(zuobiao+SIZE*a+b-1)!=' '
		||*(zuobiao+SIZE*(a+1)+b)!=' '||*(zuobiao+SIZE*(a-1)+b)!=' '
		||*(zuobiao+SIZE*(a+1)+b+1)!=' '||*(zuobiao+SIZE*(a+1)+b-1)!=' '
		||*(zuobiao+SIZE*(a-1)+b+1)!=' '||*(zuobiao+SIZE*(a-1)+b-1)!=' '){a=rand()%25+1;b=rand()%25+1;}
    	*(zuobiao+SIZE*a+b)='#';
  gotoxy(2*b,a);
    printf("%c",*(zuobiao+SIZE*a+b));
	}
	
	void eluosi(char *zuobiao){//������ɶ���˹���� 
	gotoxy(0,0);
	srand(time(NULL));
	int choice1=rand()%5+1;
	int choice2=rand()%4+1;
	int a=1,b=rand()%25+1;
	//�Ϸ� 
	if(choice1==1){//���� 
			if(choice2==1){
				while(*(zuobiao+SIZE*a+b-1)!=' '||*(zuobiao+SIZE*a+b)!=' '||*(zuobiao+SIZE*a+b+1)!=' '||*(zuobiao+SIZE*(a+1)+b)!=' ')b=rand()%25+1;
				gotoxy(2*(b-1),a);*(zuobiao+SIZE*a+b-1)='&';printf("%c",*(zuobiao+SIZE*a+b-1)) ;
				gotoxy(2*b,a);*(zuobiao+SIZE*a+b)='&';printf("%c",*(zuobiao+SIZE*a+b));
				gotoxy(2*(b+1),a);*(zuobiao+SIZE*a+b+1)='&';printf("%c",*(zuobiao+SIZE*a+b+1));
				gotoxy(2*b,a+1);*(zuobiao+SIZE*(a+1)+b)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b));
			}
			else if(choice2==2){
					while(*(zuobiao+SIZE*(a+1)+b-1)!=' '||*(zuobiao+SIZE*(a+1)+b)!=' '||*(zuobiao+SIZE*(a+1)+b+1)!=' '||*(zuobiao+SIZE*a+b)!=' ')b=rand()%25+1;
			gotoxy(2*(b-1),a+1);	*(zuobiao+SIZE*(a+1)+b-1)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b-1));
			gotoxy(2*b,a+1);	*(zuobiao+SIZE*(a+1)+b)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b));
			gotoxy(2*(b+1),a+1);	*(zuobiao+SIZE*(a+1)+b+1)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b+1));
			gotoxy(2*b,a);	*(zuobiao+SIZE*a+b)='&';printf("%c",*(zuobiao+SIZE*a+b));
			}
			else if(choice2==3){
					while(*(zuobiao+SIZE*(a+1)+b)!=' '||*(zuobiao+SIZE*a+b)!=' '||*(zuobiao+SIZE*(a+2)+b)!=' '||*(zuobiao+SIZE*(a+1)+b+1)!=' ')b=rand()%25+1;
			gotoxy(2*b,a+1);	*(zuobiao+SIZE*(a+1)+b)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b));
			gotoxy(2*b,a);	*(zuobiao+SIZE*a+b)='&';printf("%c",*(zuobiao+SIZE*a+b));
			gotoxy(2*b,a+2);	*(zuobiao+SIZE*(a+2)+b)='&';printf("%c",*(zuobiao+SIZE*(a+2)+b));
			gotoxy(2*(b+1),a+1);	*(zuobiao+SIZE*(a+1)+b+1)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b+1));
			}
			else if(choice2==4){
					while(*(zuobiao+SIZE*(a+1)+b)!=' '||*(zuobiao+SIZE*a+b)!=' '||*(zuobiao+SIZE*(a+2)+b)!=' '||*(zuobiao+SIZE*(a+1)+b-1)!=' ')b=rand()%25+1;
			gotoxy(2*b,a+1);	*(zuobiao+SIZE*(a+1)+b)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b));
			gotoxy(2*b,a);	*(zuobiao+SIZE*a+b)='&';printf("%c",*(zuobiao+SIZE*a+b));
			gotoxy(2*b,a+2);	*(zuobiao+SIZE*(a+2)+b)='&';printf("%c",*(zuobiao+SIZE*(a+2)+b));
			gotoxy(2*(b-1),a+1);	*(zuobiao+SIZE*(a+1)+b-1)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b-1));
			}
		}
	
	else if(choice1==2){//���� 
				while(*(zuobiao+SIZE*a+b+1)!=' '||*(zuobiao+SIZE*a+b)!=' '||*(zuobiao+SIZE*(a+1)+b+1)!=' '||*(zuobiao+SIZE*(a+1)+b)!=' ')b=rand()%25+1;
			gotoxy(2*(b+1),a);*(zuobiao+SIZE*a+b+1)='&';printf("%c",*(zuobiao+SIZE*a+b+1));
			gotoxy(2*b,a);*(zuobiao+SIZE*a+b)='&';printf("%c",*(zuobiao+SIZE*a+b));
		    gotoxy(2*(b+1),a+1);*(zuobiao+SIZE*(a+1)+b+1)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b+1));
			gotoxy(2*b,a+1);*(zuobiao+SIZE*(a+1)+b)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b));
		}	
		
	else if(choice1==3){//ֱ�� 
			if(choice2==1||choice2==2){
				while(*(zuobiao+SIZE*a+b-1)!=' '||*(zuobiao+SIZE*a+b)!=' '||*(zuobiao+SIZE*a+b+1)!=' '||*(zuobiao+SIZE*a+b+2)!=' ')b=rand()%25+1;
				gotoxy(2*(b-1),a);*(zuobiao+SIZE*a+b-1)='&';printf("%c",*(zuobiao+SIZE*a+b-1));
				gotoxy(2*b,a+1);*(zuobiao+SIZE*a+b)='&';printf("%c",*(zuobiao+SIZE*a+b));
				gotoxy(2*(b+1),a);*(zuobiao+SIZE*a+b+1)='&';printf("%c",*(zuobiao+SIZE*a+b+1));
				gotoxy(2*(b+2),a);*(zuobiao+SIZE*a+b+2)='&';printf("%c",*(zuobiao+SIZE*a+b+2));
			}
			else if(choice2==3||choice2==4){
					while(*(zuobiao+SIZE*(a+1)+b)!=' '||*(zuobiao+SIZE*a+b)!=' '||*(zuobiao+SIZE*(a+2)+b)!=' '||*(zuobiao+SIZE*(a+3)+b)!=' ')b=rand()%25+1;
				gotoxy(2*b,a+1);*(zuobiao+SIZE*(a+1)+b)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b));
				gotoxy(2*b,a+2);*(zuobiao+SIZE*(a+2)+b)='&';printf("%c",*(zuobiao+SIZE*(a+2)+b));
				gotoxy(2*b,a);*(zuobiao+SIZE*a+b)='&';printf("%c",*(zuobiao+SIZE*a+b));
				gotoxy(2*b,a+3);*(zuobiao+SIZE*(a+3)+b)='&';printf("%c",*(zuobiao+SIZE*(a+3)+b));
			}
		}
			
		else if(choice1==4){//���� 
			if(choice2==1){
				while(*(zuobiao+SIZE*a+b-1)!=' '||*(zuobiao+SIZE*a+b)!=' '||*(zuobiao+SIZE*(a+1)+b+1)!=' '||*(zuobiao+SIZE*(a+1)+b)!=' ')b=rand()%25+1;
			gotoxy(2*(b-1),a);	*(zuobiao+SIZE*a+b-1)='&';printf("%c",*(zuobiao+SIZE*a+b-1));
			gotoxy(2*b,a);	*(zuobiao+SIZE*a+b)='&';printf("%c",*(zuobiao+SIZE*a+b));
			gotoxy(2*(b+1),a+1);	*(zuobiao+SIZE*(a+1)+b+1)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b+1));
			gotoxy(2*b,a+1);	*(zuobiao+SIZE*(a+1)+b)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b));
			}
			else if(choice2==2){
					while(*(zuobiao+SIZE*a+b+1)!=' '||*(zuobiao+SIZE*a+b)!=' '||*(zuobiao+SIZE*(a+1)+b-1)!=' '||*(zuobiao+SIZE*(a+1)+b)!=' ')b=rand()%25+1;
			gotoxy(2*(b+1),a);	*(zuobiao+SIZE*a+b+1)='&';printf("%c",*(zuobiao+SIZE*a+b+1));
			gotoxy(2*b,a);	*(zuobiao+SIZE*a+b)='&';printf("%c",*(zuobiao+SIZE*a+b));
			gotoxy(2*(b-1),a+1);	*(zuobiao+SIZE*(a+1)+b-1)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b-1));
			gotoxy(2*b,a+1);	*(zuobiao+SIZE*(a+1)+b)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b));
			}
			else if(choice2==3){
					while(*(zuobiao+SIZE*(a+1)+b)!=' '||*(zuobiao+SIZE*a+b)!=' '||*(zuobiao+SIZE*(a+1)+b+1)!=' '||*(zuobiao+SIZE*(a+1)+b+2)!=' ')b=rand()%25+1;
			gotoxy(2*b,a+1);	*(zuobiao+SIZE*(a+1)+b)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b));
			gotoxy(2*b,a);	*(zuobiao+SIZE*a+b)='&';printf("%c",*(zuobiao+SIZE*a+b));
			gotoxy(2*(b+1),a+1);	*(zuobiao+SIZE*(a+1)+b+1)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b+1));
			gotoxy(2*(b+2),a+1);	*(zuobiao+SIZE*(a+1)+b+2)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b+2));
			}
			else if(choice2==4){
					while(*(zuobiao+SIZE*(a+1)+b)!=' '||*(zuobiao+SIZE*a+b)!=' '||*(zuobiao+SIZE*(a+1)+b-1)!=' '||*(zuobiao+SIZE*(a+1)+b-2)!=' ')b=rand()%25+1;
			gotoxy(2*b,a+1);	*(zuobiao+SIZE*(a+1)+b)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b));
			gotoxy(2*b,a);	*(zuobiao+SIZE*a+b)='&';printf("%c",*(zuobiao+SIZE*a+b));
			gotoxy(2*(b-1),a+1);	*(zuobiao+SIZE*(a+1)+b-1)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b-1));
			gotoxy(2*(b-2),a+1);	*(zuobiao+SIZE*(a+1)+b-2)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b-2));
			}
		}
		
			else if(choice1==5){//L���� 
				if(choice2==1){
				while(*(zuobiao+SIZE*a+b-1)!=' '||*(zuobiao+SIZE*a+b)!=' '||*(zuobiao+SIZE*a+b+1)!=' '||*(zuobiao+SIZE*(a+1)+b+1)!=' ')b=rand()%25+1;
			gotoxy(2*(b-1),a);	*(zuobiao+SIZE*a+b-1)='&';printf("%c",*(zuobiao+SIZE*a+b-1));
			gotoxy(2*b,a);	*(zuobiao+SIZE*a+b)='&';printf("%c",*(zuobiao+SIZE*a+b));
			gotoxy(2*(b+1),a);	*(zuobiao+SIZE*a+b+1)='&';printf("%c",*(zuobiao+SIZE*a+b+1));
			gotoxy(2*(b+1),a+1);	*(zuobiao+SIZE*(a+1)+b+1)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b+1));
			}
			else if(choice2==2){
					while(*(zuobiao+SIZE*(a+1)+b-1)!=' '||*(zuobiao+SIZE*(a+1)+b)!=' '||*(zuobiao+SIZE*(a+1)+b+1)!=' '||*(zuobiao+SIZE*a+b-1)!=' ')b=rand()%25+1;
			gotoxy(2*(b-1),a+1);	*(zuobiao+SIZE*(a+1)+b-1)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b-1));
			gotoxy(2*b,a+1);	*(zuobiao+SIZE*(a+1)+b)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b));
			gotoxy(2*(b+1),a+1);	*(zuobiao+SIZE*(a+1)+b+1)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b+1));
			gotoxy(2*(b-1),a);	*(zuobiao+SIZE*a+b-1)='&';printf("%c",*(zuobiao+SIZE*a+b-1));
			}
			else if(choice2==3){
					while(*(zuobiao+SIZE*(a+1)+b)!=' '||*(zuobiao+SIZE*a+b)!=' '||*(zuobiao+SIZE*(a+2)+b)!=' '||*(zuobiao+SIZE*(a+2)+b+1)!=' ')b=rand()%25+1;
			gotoxy(2*b,a+1);	*(zuobiao+SIZE*(a+1)+b)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b));
			gotoxy(2*b,a);	*(zuobiao+SIZE*a+b)='&';printf("%c",*(zuobiao+SIZE*a+b));
			gotoxy(2*b,a+2);	*(zuobiao+SIZE*(a+2)+b)='&';printf("%c",*(zuobiao+SIZE*(a+2)+b));
			gotoxy(2*(b+1),a+2);	*(zuobiao+SIZE*(a+2)+b+1)='&';printf("%c",*(zuobiao+SIZE*(a+2)+b+1));
			}
			else if(choice2==4){
					while(*(zuobiao+SIZE*(a+1)+b)!=' '||*(zuobiao+SIZE*a+b)!=' '||*(zuobiao+SIZE*(a+2)+b)!=' '||*(zuobiao+SIZE*a+b-1)!=' ')b=rand()%25+1;
			gotoxy(2*b,a+1);	*(zuobiao+SIZE*(a+1)+b)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b));
			gotoxy(2*b,a);	*(zuobiao+SIZE*a+b)='&';printf("%c",*(zuobiao+SIZE*a+b));
			gotoxy(2*b,a+2);	*(zuobiao+SIZE*(a+2)+b)='&';printf("%c",*(zuobiao+SIZE*(a+2)+b));
			gotoxy(2*(b-1),a);	*(zuobiao+SIZE*a+b-1)='&';printf("%c",*(zuobiao+SIZE*a+b-1));
			}
		}
		}
void duanwei(int i,int j,char *zuobiao){
	int a,b=0;
	for(a=0;a<100;a++){
		if(sheshen[a].x==i&&sheshen[a].y==j)break;
	}
	x3=sheshen[a-1].x;y3=sheshen[a-1].y;
	for(;a<100;a++){
		if(sheshen[a].x==0&&sheshen[a].y==0)break;
		*(zuobiao+SIZE*sheshen[a].x+sheshen[a].y)=' ';
		gotoxy(2*sheshen[a].y,sheshen[a].x);
		printf("%c",*(zuobiao+SIZE*sheshen[a].x+sheshen[a].y));
		sheshen[a].x=0;sheshen[a].y=0;
	}
}
void eluosiyidong(char* zuobiao){
	gotoxy(0,0);
		int i,j;
for(i=SIZE-2;i>=1;i--){
for(j=0;j<SIZE;j++){
if(*(zuobiao+SIZE*i+j)=='&'){
	gotoxy(2*j,i);
	*(zuobiao+SIZE*i+j)=' ';
	printf("%c",*(zuobiao+SIZE*i+j));
	if(*(zuobiao+SIZE*(i+1)+j)=='$')jiashiwu((char *)zuobiao);
	if(*(zuobiao+SIZE*(i+1)+j)=='*'){duanwei(i,j,(char *)zuobiao);	}
	gotoxy(2*j,i+1);
	*(zuobiao+SIZE*(i+1)+j)='&';
	printf("%c",*(zuobiao+SIZE*(i+1)+j));
}
}}for(j=0,i=26;j<SIZE;j++){
	if(*(zuobiao+SIZE*i+j)=='&'){*(zuobiao+SIZE*i+j)='#';gotoxy(2*j,i);printf("%c",*(zuobiao+SIZE*i+j));}
}
gotoxy(0,0);
}

int shang(char *zuobiao){
	int t;eluosiyidong((char *)zuobiao);
int x;char ch=0;
while(ch!=68&&ch!=65&&ch!=97&&ch!=100)
{danzhuyidong((char *)zuobiao);
if(kbhit()){ch=getch();if(ch==65||ch==68||ch==97||ch==100)break;
if(ch==32){gotoxy(70,12);system("pause");gotoxy(70,12);printf("                   ");}}
	if(*(zuobiao+SIZE*(x1-1)+y1)=='$'){
			jiashiwu((char*)zuobiao);
			eluosi((char *)zuobiao);
		gotoxy(0,0);
		gotoxy(2*y1,x1);
	*(zuobiao+SIZE*x1+y1)='*';
	printf("%c",*(zuobiao+SIZE*x1+y1));
	x1--;
		gotoxy(2*y1,x1);
	*(zuobiao+SIZE*x1+y1)='@';
	printf("%c",*(zuobiao+SIZE*x1+y1));
	bianli(1);
	tianjia(x3,y3);
	gotoxy(0,0);}
	else if(*(zuobiao+SIZE*(x1-1)+y1)=='#'||*(zuobiao+SIZE*(x1-1)+y1)=='&'||*(zuobiao+SIZE*(x1-1)+y1)=='*')return 0;
		else {gotoxy(0,0);	
				gotoxy(2*y1,x1);
				*(zuobiao+SIZE*x1+y1)='*';
				printf("%c",*(zuobiao+SIZE*x1+y1));
				x1--;
					gotoxy(2*y1,x1);
				*(zuobiao+SIZE*x1+y1)='@';
					printf("%c",*(zuobiao+SIZE*x1+y1));
			gotoxy(2*y3,x3);
				*(zuobiao+SIZE*x3+y3)=' ';
					printf("%c",*(zuobiao+SIZE*x3+y3));			
				bianli(1);
				int jie=fanhui();
				x3=sheshen[jie].x;y3=sheshen[jie].y;
	gotoxy(0,0);	}
eluosiyidong((char *)zuobiao);
		Sleep(speed);
}if(ch==65||ch==97){jiazhangai((char *)zuobiao);t=zuo((char *)zuobiao);}
if(ch==68||ch==100){jiazhangai((char *)zuobiao);t=you((char *)zuobiao);}
	} 
int xia(char *zuobiao){eluosiyidong((char *)zuobiao);
	int t;
	int x;char ch=0;
while(ch!=68&&ch!=65&&ch!=97&&ch!=100)
{danzhuyidong((char *)zuobiao);
	if(kbhit()){ch=getch();if(ch==65||ch==68||ch==97||ch==100)break;
	if(ch==32){gotoxy(70,12);system("pause");gotoxy(70,12);printf("                   ");}}//�ո���ͣ 
if(*(zuobiao+SIZE*(x1+1)+y1)=='$'){
	jiashiwu((char*)zuobiao);
	eluosi((char *)zuobiao);gotoxy(0,0);
		gotoxy(2*y1,x1);*(zuobiao+SIZE*x1+y1)='*';
	printf("%c",*(zuobiao+SIZE*x1+y1));
	x1++;

	gotoxy(2*y1,x1);*(zuobiao+SIZE*x1+y1)='@';
		printf("%c",*(zuobiao+SIZE*x1+y1));
		bianli(2);
			tianjia(x3,y3);
gotoxy(0,0);}
	else if(*(zuobiao+SIZE*(x1+1)+y1)=='#'||*(zuobiao+SIZE*(x1+1)+y1)=='&'||*(zuobiao+SIZE*(x1+1)+y1)=='*')return 0;
		else {gotoxy(0,0);	
				gotoxy(2*y1,x1);*(zuobiao+SIZE*x1+y1)='*';
					printf("%c",*(zuobiao+SIZE*x1+y1));
				x1++;
				gotoxy(2*y1,x1);*(zuobiao+SIZE*x1+y1)='@';
					printf("%c",*(zuobiao+SIZE*x1+y1));
				gotoxy(2*y3,x3);	*(zuobiao+SIZE*x3+y3)=' ';
				printf("%c",*(zuobiao+SIZE*x3+y3));
				bianli(2);
								int jie=fanhui();
				x3=sheshen[jie].x;y3=sheshen[jie].y;
			
		gotoxy(0,0);}
eluosiyidong((char *)zuobiao);
		Sleep(speed);
}if(ch==65||ch==97){jiazhangai((char *)zuobiao);t=zuo((char *)zuobiao);}
if(ch==68||ch==100){jiazhangai((char *)zuobiao);t=you((char *)zuobiao);}
}
int zuo(char *zuobiao){eluosiyidong((char *)zuobiao);
	int t;
		int x;char ch=0;
while(ch!=83&&ch!=87&&ch!=115&&ch!=119)
{danzhuyidong((char *)zuobiao);
if(kbhit()){ch=getch();if(ch==83||ch==87||ch==115||ch==119)break;
if(ch==32){gotoxy(70,12);system("pause");gotoxy(70,12);printf("                   ");}}
if(*(zuobiao+SIZE*x1+y1-1)=='$'){
	jiashiwu((char*)zuobiao);
	eluosi((char *)zuobiao);gotoxy(0,0);
		gotoxy(2*y1,x1) ;*(zuobiao+SIZE*x1+y1)='*';
	printf("%c",*(zuobiao+SIZE*x1+y1));
	y1--;

		gotoxy(2*y1,x1);*(zuobiao+SIZE*x1+y1)='@';
	printf("%c",*(zuobiao+SIZE*x1+y1));
	bianli(3);
		tianjia(x3,y3);
gotoxy(0,0);}
	else if(*(zuobiao+SIZE*x1+y1-1)=='#'||*(zuobiao+SIZE*x1+y1-1)=='&'||*(zuobiao+SIZE*x1+y1-1)=='*')return 0;
		else {gotoxy(0,0);
				gotoxy(2*y1,x1);	*(zuobiao+SIZE*x1+y1)='*';
				printf("%c",*(zuobiao+SIZE*x1+y1));
				y1--;
				gotoxy(2*y1,x1);	*(zuobiao+SIZE*x1+y1)='@';
				printf("%c",*(zuobiao+SIZE*x1+y1));
				gotoxy(2*y3,x3);	*(zuobiao+SIZE*x3+y3)=' ';
				printf("%c",*(zuobiao+SIZE*x3+y3));
						bianli(3);
								int jie=fanhui();
				x3=sheshen[jie].x;y3=sheshen[jie].y;
			
	gotoxy(0,0);}
eluosiyidong((char *)zuobiao);
		Sleep(speed);
}if(ch==83||ch==115){jiazhangai((char *)zuobiao);t=xia((char *)zuobiao);}
if(ch==87||ch==119){jiazhangai((char *)zuobiao);t=shang((char *)zuobiao);}
}
int you(char *zuobiao){
	eluosiyidong((char *)zuobiao);
	int t;
		int x;char ch=0;
while(ch!=83&&ch!=87&&ch!=115&&ch!=119)
{danzhuyidong((char *)zuobiao);
	if(kbhit()){ch=getch();if(ch==83||ch==87||ch==115||ch==119)break;
	if(ch==32){gotoxy(70,12);system("pause");gotoxy(70,12);printf("                   ");}}
	if(*(zuobiao+SIZE*x1+y1+1)=='$'){
	jiashiwu((char*)zuobiao);
	eluosi((char *)zuobiao);gotoxy(0,0);
		gotoxy(2*y1,x1);*(zuobiao+SIZE*x1+y1)='*';
	printf("%c",*(zuobiao+SIZE*x1+y1));
	y1++;

	gotoxy(2*y1,x1);	*(zuobiao+SIZE*x1+y1)='@';
	printf("%c",*(zuobiao+SIZE*x1+y1));
	bianli(4);
		tianjia(x3,y3);
	gotoxy(0,0);}
	else if(*(zuobiao+SIZE*x1+y1+1)=='#'||*(zuobiao+SIZE*x1+y1+1)=='&'||*(zuobiao+SIZE*x1+y1+1)=='*')return 0;
		else {gotoxy(0,0);	
				gotoxy(2*y1,x1);*(zuobiao+SIZE*x1+y1)='*';
					printf("%c",*(zuobiao+SIZE*x1+y1));
				y1++;
				gotoxy(2*y1,x1);	*(zuobiao+SIZE*x1+y1)='@';
				printf("%c",*(zuobiao+SIZE*x1+y1));
				gotoxy(2*y3,x3);*(zuobiao+SIZE*x3+y3)=' ';
					printf("%c",*(zuobiao+SIZE*x3+y3));
						bianli(4);
						int jie=fanhui();
				x3=sheshen[jie].x;y3=sheshen[jie].y;
			
	gotoxy(0,0);	}
eluosiyidong((char *)zuobiao);
				Sleep(speed);
}if(ch==83||ch==115){jiazhangai((char *)zuobiao);t=xia((char *)zuobiao);}
if(ch==87||ch==119){jiazhangai((char *)zuobiao);t=shang((char *)zuobiao);}
}
void yidong(char *zuobiao){
	int t;
	LOOP:
		char zhiling;
	scanf("%c",&zhiling);
	fflush(stdin);
	 if(zhiling=='W'||zhiling=='w'){if(MAXX==x1&&y1==y2) goto LOOP;else t=shang((char *)zuobiao);}
	else if(zhiling=='S'||zhiling=='s'){if(MINX==x1&&y1==y2) goto LOOP;else t=xia((char *)zuobiao);}
	else if(zhiling=='A'||zhiling=='a'){if(MAXY==y1&&x1==x2) goto LOOP;else t=zuo((char *)zuobiao);}
	else if(zhiling=='D'||zhiling=='d'){if(MINY==y1&&x1==x2) goto LOOP;else t=you((char *)zuobiao);}
	else goto LOOP;
gotoxy(0,27);
    printf("\n\n\n\n��������HAHAHAHAhahahaha��������⣿\n");
	system("pause");
}
