#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h> 
#define SIZE 27//25*25�����򼰱߽� 
#define MAXX maxx(x1,maxx(x2,x3))
#define MINX minx(x1,minx(x2,x3))
#define MAXY maxx(ya,maxx(y2,y3))
#define MINY minx(ya,minx(y2,y3))
#define BIANLI 
#define PAND if(i>=1&&i<=25&&j>=1&&j<=25&&*(zuobiao+SIZE*i+j)!='@'&&*(zuobiao+SIZE*i+j)!='*'
#define UAN &&*(zuobiao+SIZE*i+j)!='o'){gotoxy(2*j,i);printf("?");Sleep(10);} 
#define PAN if(i>=1&&i<=25&&j>=1&&j<=25&&*(zuobiao+SIZE*i+j)!='@'&&*(zuobiao+SIZE*i+j)!='*'&&*(zuobiao+SIZE*i+j)!='o')
#define DING {*(zuobiao+SIZE*i+j)=' '; gotoxy(2*j,i);printf("%c",*(zuobiao+SIZE*i+j));Sleep(10);}
#define IF if(huihe!=1)huihe++;else {huihe=0;if(speed>=1)speed=speed-2;}

//�ڵ��������� 
int huihe=0; 
struct a{//��¼���� 
	int x;
	int y; 
};
typedef struct a jilu;
jilu sheshen[100];//����ڵ������ 

char zuobiao[SIZE][SIZE];//�����ӡ 
int x1,ya,x2,y2,x3,y3;//��ʼ���� 
int jifen=0;//���� 
int speed;//��Ϸ�Ѷ� 
int zhuangtai=0;
int k,l;
int paojishu=1;int zidanshu=5; 
int jijie=0;//ѡ�񼾽� 
int yidongcishu=0;//������� ����ֵ 
int dashiwu=0;//���ɴ�ʳ�� 

int maxx(int a,int b)
{
	return a>=b ? a:b;
}
int minx(int a,int b)
{
	return a>b ? b:a;
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
int zidan(int fang,char *zuobiao);//����һ���ӵ��ݻ�ֱ���ϵ��ϰ��� 
void paoji(char *zuobiao);//���䶾Һ�ڵ��ٻ�3*3���� 
void jinshi();//�����ʳ������������ڻ�����ĸ��� 
void moshi();//ѡ�񼾽�ģʽ����Ӧ��ͬ����Ϸ���� 
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
		dashiwu=0;
		jijie=0;
		paojishu=1;
		zidanshu=5;
		jifen=0;
	int choice; 
	jiemian();
    quyu((char *)zuobiao);
    chushihua((char *)zuobiao);
	ditu((char *)zuobiao);
		printf("������W(��),S(��),A(��),D(��)\n");
			gotoxy(55,4);
			printf("ʣ���ӵ�����%d\n",zidanshu);
				gotoxy(55,6);
			printf("ʣ���ڵ�����%d\n",paojishu);
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

void jiemian(){//����˵�� 
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
	printf("*�������������죬����ڶ��ι��佫����Ч����\n");
	printf("*1.* ����2.@ ��ͷ��3.# �߽缰�ϰ��4. & ����˹���飬5.$ Ϊʳ��(ÿ�������һ����ʳ���S���Ե�����+4),6.oΪ����\n");
	printf("*��Ϸ��Ϊ�����ﶬ�ĸ�ģʽ��ÿ��ģʽ�и��Ե�Ч��"); 
	printf("*����ÿ����һ�λ���50%�����������һ�������� L �������������߻᲻��������������٣�ͬʱ��������ı�\n"); 
	printf("*�������������߻�����ˮԴ����ͼ���������һ��Сˮ̶( U ),�����40���ƶ��ڲ��ܸϵ�ˮԴ�߽��ᱻ����\n"); 
	printf("*����������Ҷÿ�ι��佫��20%���ʲ���һ�����صĲ��ɼ����ϰ���\n");
	printf("*�������ڵ������򻬣����佫�ӳ������غ�ִ��\n");
	printf("*����˹�����Ϊ���ģ�ֱ�ģ����ģ����ģ�L�������֣��������\n");
	 printf("*@ͷײ#��&��*������*��ײ&��β\n");
	 printf("*ÿ��һ���������һ���ϰ���#,�����ٶȻ�С��������\n"); 
	  printf("*ÿ��һ��$����һ�ζ���˹������׹\n");
	  printf("*����˹������ϰ����ʳ��ҪӲ�����Ի�ݻ��ϰ��ﲢˢ��ʳ���\n");
	   printf("*��Ϸ��ʼ�ӵ�ͼ���Ͻǻᵯ��һ�����飬�ԶԽ��߷����ƶ���\n*������ͷ�������ϰ������˹����,ʳ�������һ���Խ��߷��򷴵�\n");
	   printf("*ͬʱ��ײ�����ϰ��Ｐ����˹���鱻�ݻ٣��߽�ͬ���ᱻ��,������˹����Ķѻ����޸��߽�\n"); 
	    printf("*�߽�ͬ���ᱻ�ݻ�,������Ϊ����������Ӱ�죨ʵ���������Ѷ�̫�����治ת��\n"); 
	    printf("*�����鵯���𻵵ı߽�(���ϰ���)��������һ��ʳ���\n"); 
	    printf("*�����ͨ���� Q �� q ������һ�ζ�Һ����������ڷ��䶾Һ�ӵ����ӵ�����ݻ���ͷֱ���ϵ�����ϰ���ܹ���Σ�\n");
	    printf("*�����ͨ���� R �� r ������һ��ǿ��ʴ�Զ�Һ����������ڷ��䶾Һ�ڵ����ڵ�����ݻ�3*3�������ܹ�һ�Σ�\n");
	   	printf("*ע�⣺��Һ���ḯʴ�������ӵ��ᴩ��ʳ��㣬���ڵ�����ʳ��㲢����ˢ��\n");
	   	printf("*ÿ��ʳһ�λ���20%��������һ�ζ�Һ�ڻ����ᣬ50%��������һ�ζ�Һ�������\n");
	      printf("*�Ҳ����Ѿ����������Ⲣ����һ��������Ϸ������������Ϸ\n"); 
	       printf("*���ֵĸߵ͸������������ʱ������ǳ���\n"); 
	    printf("*�������ö���˹����͵���������Ϸ����\n");
	  printf("*�����Գ�ʳ������Ϊ׼���������ճ���Ϊ׼���������̫���Ա���\n");
	  printf("*��Ϸ�а� ESC ��ǿ���˳���Ϸ����\n");
	 system("pause");
	 system("cls");	system("color 0B");
	 menu:
	 printf("\n\n*********��ѡ����Ϸ�Ѷ�**********\n");
	 printf("*****1.S��\n*****2.A��\n*****3.B��\n*****4.C��\n");
	 scanf("%d",&speed);
	 fflush(stdin);
	 if(speed==1)speed=50;
	 else if(speed==2)speed=100;
	  else if(speed==3)speed=150;
	    else if(speed==4)speed=180;
	 else goto menu;
	 moshi();
}
void moshi(){//ģʽѡ�� 
	 menu:
	 printf("\n\n*********��ѡ����Ϸģʽ**********\n");
	 printf("*****1.����\n*****2.�ļ�\n*****3.�＾\n*****4.����\n*****5.����ģʽ\n*****0.����ģʽ\n");
	 scanf("%d",&jijie);
	 fflush(stdin);
if(jijie!=1&&jijie!=2&&jijie!=3&&jijie!=4&&jijie!=5&&jijie!=0)
	  goto menu;
}

void ditu(char *zuobiao){ //��ӡ 
	system("color 0F");
	system("cls");
	gotoxy(0,0);
int i,j;
for(i=0;i<SIZE;i++){
	for(j=0;j<SIZE;j++){
		printf("%c ",*(zuobiao+SIZE*i+j));
	}printf("\n");
}
	}
	
	void danzhuyidong(char *zuobiao){//�ṩ�����˶��켣 
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
		
			else if(*(zuobiao+SIZE*(m+1)+n+1)=='L'){
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
			else if(*(zuobiao+SIZE*(m+1)+n-1)=='L'){
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
			else if(*(zuobiao+SIZE*(m-1)+n+1)=='L'){
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
			else if(*(zuobiao+SIZE*(m-1)+n-1)=='L'){
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
    ya=rand()%22+3;
		fangxiang=rand()%4+1;
		if(fangxiang==1&&x1-2>=1){x2=x1-1;x3=x1-2;y2=ya;y3=ya;}
		else if(fangxiang==2&&x1+2<=25){x2=x1+1;x3=x1+2;y2=ya;y3=ya;}
		else if(fangxiang==3&&ya-2>=1){y2=ya-1;y3=ya-2;x2=x1;x3=x1;}
		else if(fangxiang==4&&ya+2<=25){y2=ya+1;y3=ya+2;x2=x1;x3=x1;}
		*(zuobiao+SIZE*x1+ya)='@';
		*(zuobiao+SIZE*x2+y2)='*';
		*(zuobiao+SIZE*x3+y3)='*';
		sheshen[0].x=x1;sheshen[0].y=ya;
		sheshen[1].x=x2;sheshen[1].y=y2;
		sheshen[2].x=x3;sheshen[2].y=y3;
		
	int a,b,c,d,e,f,g,h;//��ʼʳ������� 
	srand(time(NULL));
	a=rand()%25+1;b=rand()%25+1;
	c=rand()%25+1;d=rand()%25+1;
	e=rand()%25+1;f=rand()%25+1;
	g=rand()%25+1;h=rand()%25+1;
	while(*(zuobiao+SIZE*a+b)!=' ')a=rand()%25+1;b=rand()%25+1;
	while(*(zuobiao+SIZE*a+b)!=' ')c=rand()%25+1;d=rand()%25+1;
	while(*(zuobiao+SIZE*a+b)!=' ')e=rand()%25+1;f=rand()%25+1;
	while(*(zuobiao+SIZE*a+b)!=' ')g=rand()%25+1;h=rand()%25+1;
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
if(jijie==2||jijie==5){//�ļ� 
	 m=rand()%23+2; n=rand()%23+2;
while(*(zuobiao+SIZE*m+n)!=' '||*(zuobiao+SIZE*m+n-1)!=' '||*(zuobiao+SIZE*(m-1)+n-1)!=' '||*(zuobiao+SIZE*(m-1)+n)!=' ')
{m=rand()%23+2; n=rand()%23+2;}
*(zuobiao+SIZE*m+n)='U';
*(zuobiao+SIZE*(m-1)+n)='U';
*(zuobiao+SIZE*(m-1)+n-1)='U';
*(zuobiao+SIZE*m+n-1)='U';
gotoxy(2*n,m);printf("%c",*(zuobiao+SIZE*m+n));
gotoxy(2*n,m-1);printf("%c",*(zuobiao+SIZE*(m-1)+n));
gotoxy(2*(n-1),m-1);printf("%c",*(zuobiao+SIZE*(m-1)+n-1));
gotoxy(2*(n-1),m);printf("%c",*(zuobiao+SIZE*m+n-1));
}
}
void shuaxin(char *zuobiao){//ˢ��ˮ̶�Ϳ�ֵ
int i,j;
for(i=1;i<SIZE-1;i++){
	for(j=1;j<SIZE-1;j++){
		if(*(zuobiao+SIZE*i+j)=='U'){
			*(zuobiao+SIZE*i+j)=' ';
			gotoxy(2*j,i);
			printf("%c",*(zuobiao+SIZE*i+j));
		}
	}
}yidongcishu=0;
  int m=rand()%23+2; int n=rand()%23+2;
while(*(zuobiao+SIZE*m+n)!=' '||*(zuobiao+SIZE*m+n-1)!=' '||*(zuobiao+SIZE*(m-1)+n-1)!=' '||*(zuobiao+SIZE*(m-1)+n)!=' ')
{m=rand()%23+2; n=rand()%23+2;}
*(zuobiao+SIZE*m+n)='U';
*(zuobiao+SIZE*(m-1)+n)='U';
*(zuobiao+SIZE*(m-1)+n-1)='U';
*(zuobiao+SIZE*m+n-1)='U';
gotoxy(2*n,m);printf("%c",*(zuobiao+SIZE*m+n));
gotoxy(2*n,m-1);printf("%c",*(zuobiao+SIZE*(m-1)+n));
gotoxy(2*(n-1),m-1);printf("%c",*(zuobiao+SIZE*(m-1)+n-1));
gotoxy(2*(n-1),m);printf("%c",*(zuobiao+SIZE*m+n-1));
} 
void jinshi(){//�жϽ�ʳ���ӵ����ڵ��仯 
	      int m=rand()%5+1,n=rand()%2+1;
    if(n==1)zidanshu++;
    if(m==1)paojishu++;
    gotoxy(55,4);
    printf("                          ");
    gotoxy(55,4);
	printf("ʣ���ӵ�����%d\n",zidanshu);
	gotoxy(55,6);
	printf("                          ");
	gotoxy(55,6);
	printf("ʣ���ڵ�����%d\n",paojishu);
}
    void jiashiwu(char *zuobiao){
    	if(dashiwu==5){
    		dashiwu=0;
    		  int m=rand()%23+2; int n=rand()%23+2;
while(*(zuobiao+SIZE*m+n)!=' '||*(zuobiao+SIZE*m+n-1)!=' '||*(zuobiao+SIZE*(m-1)+n-1)!=' '||*(zuobiao+SIZE*(m-1)+n)!=' ')
{m=rand()%23+2; n=rand()%23+2;}
*(zuobiao+SIZE*m+n)='S';
*(zuobiao+SIZE*(m-1)+n)='S';
*(zuobiao+SIZE*(m-1)+n-1)='S';
*(zuobiao+SIZE*m+n-1)='S';
gotoxy(2*n,m);printf("%c",*(zuobiao+SIZE*m+n));
gotoxy(2*n,m-1);printf("%c",*(zuobiao+SIZE*(m-1)+n));
gotoxy(2*(n-1),m-1);printf("%c",*(zuobiao+SIZE*(m-1)+n-1));
gotoxy(2*(n-1),m);printf("%c",*(zuobiao+SIZE*m+n-1));
		}
		else {
    	int a,b;
    	srand(time(NULL));
    	a=rand()%25+1;b=rand()%25+1;
    	while(*(zuobiao+SIZE*a+b)!=' '){a=rand()%25+1;b=rand()%25+1;}
    	*(zuobiao+SIZE*a+b)='$';jifen++;
  gotoxy(2*b,a);
    printf("%c",*(zuobiao+SIZE*a+b));
}
	}
	
	void jiazhangai(char *zuobiao){
    	int a,b,c,d;
    	srand(time(NULL));
    	c=rand()%2+1;
    	d=rand()%5+1;
		    	a=rand()%25+1;b=rand()%25+1;
    	while(*(zuobiao+SIZE*a+b)!=' '||*(zuobiao+SIZE*a+b+1)!=' '||*(zuobiao+SIZE*a+b-1)!=' '
		||*(zuobiao+SIZE*(a+1)+b)!=' '||*(zuobiao+SIZE*(a-1)+b)!=' '||
        *(zuobiao+SIZE*a+b+2)!=' '||*(zuobiao+SIZE*a+b-2)!=' '
		||*(zuobiao+SIZE*(a+2)+b)!=' '||*(zuobiao+SIZE*(a-2)+b)!=' '
		||*(zuobiao+SIZE*(a+1)+b+1)!=' '||*(zuobiao+SIZE*(a+1)+b-1)!=' '
		||*(zuobiao+SIZE*(a-1)+b+1)!=' '||*(zuobiao+SIZE*(a-1)+b-1)!=' '){a=rand()%25+1;b=rand()%25+1;}
		if(jijie==1||jijie==5){
		if(c==1)
    	*(zuobiao+SIZE*a+b)='#';
    	else *(zuobiao+SIZE*a+b)='L';
  gotoxy(2*b,a);
  if((jijie==3||jijie==5)&&d==1)printf(" ");
    else printf("%c",*(zuobiao+SIZE*a+b));
	}
	else {
			*(zuobiao+SIZE*a+b)='#';
			gotoxy(2*b,a);
			  if((jijie==3||jijie==5)&&d==1)printf(" ");
    else printf("%c",*(zuobiao+SIZE*a+b));
	}
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
void duanwei(int i,int j,char *zuobiao){//�����β����� 
	int a,b=0;
	for(a=0;a<100;a++){
		if(sheshen[a].x==i&&sheshen[a].y==j)break;
	}
	x3=sheshen[a-1].x;y3=sheshen[a-1].y;
	for(;a<100;a++){
		if(sheshen[a].x==0||sheshen[a].y==0)break;
		*(zuobiao+SIZE*sheshen[a].x+sheshen[a].y)=' ';
		gotoxy(2*sheshen[a].y,sheshen[a].x);
		printf("%c",*(zuobiao+SIZE*sheshen[a].x+sheshen[a].y));
		sheshen[a].x=0;sheshen[a].y=0;
	}
}
void eluosiyidong(char* zuobiao){//��¼����˹������ƶ� 
	gotoxy(0,0);
		int i,j;
for(i=SIZE-2;i>=1;i--){
for(j=0;j<SIZE;j++){
if(*(zuobiao+SIZE*i+j)=='&'){
	gotoxy(2*j,i);
	*(zuobiao+SIZE*i+j)=' ';
	printf("%c",*(zuobiao+SIZE*i+j));
	if(*(zuobiao+SIZE*(i+1)+j)=='$')jiashiwu((char *)zuobiao);
	else if(*(zuobiao+SIZE*(i+1)+j)=='*'){duanwei(i+1,j,(char *)zuobiao);	}
	gotoxy(2*j,i+1);
	*(zuobiao+SIZE*(i+1)+j)='&';
	printf("%c",*(zuobiao+SIZE*(i+1)+j));
}
}}for(j=0,i=26;j<SIZE;j++){
	if(*(zuobiao+SIZE*i+j)=='&'){*(zuobiao+SIZE*i+j)='#';gotoxy(2*j,i);printf("%c",*(zuobiao+SIZE*i+j));}
}
gotoxy(0,0);
}

int zidan(int fang,char *zuobiao){//����һ���ӵ��ݻ�ֱ���ϵ��ϰ��� 
int i,j; 
if(zidanshu==0){
	gotoxy(55,4);
	printf("��Һ�ӵ����Ѻľ�\n");return 0;}
	else {
		gotoxy(55,4);
			printf("ʣ���ӵ�����%d\n\a",zidanshu-1);
	
i=sheshen[0].x;j=sheshen[0].y;
if(fang==1){//���� 
	 for(;i>1;i--){
	 	if(*(zuobiao+SIZE*(i-1)+j)=='#'||*(zuobiao+SIZE*(i-1)+j)=='&'||*(zuobiao+SIZE*(i-1)+j)=='+'){i--;
	 		gotoxy(2*j,i);
	 		*(zuobiao+SIZE*i+j)=' ';
	 		printf("%c",*(zuobiao+SIZE*i+j));
	 		break;
		 } 
		 	gotoxy(2*j,i-1);
		 	printf("o");
		 	gotoxy(0,0);
		 		Sleep(15);
		 		gotoxy(2*j,i-1);
		 	printf(" ");
		 		gotoxy(0,0);
	 }
}
else if(fang==2){//���� 
	 for(;i<25;i++){
	 	if(*(zuobiao+SIZE*(i+1)+j)=='#'||*(zuobiao+SIZE*(i+1)+j)=='&'||*(zuobiao+SIZE*(i+1)+j)=='+'){i++;
	 		gotoxy(2*j,i);
	 		*(zuobiao+SIZE*i+j)=' ';
	 		printf("%c",*(zuobiao+SIZE*i+j));
	 		break;
		 }
		 	gotoxy(2*j,i+1);
		 	printf("o");
		 		gotoxy(0,0);
		 		Sleep(15);
		 		gotoxy(2*j,i+1);
		 	printf(" "); 
		 		gotoxy(0,0);
	 }
}
else if(fang==3){//���� 
	 for(;j>1;j--){
	 	if(*(zuobiao+SIZE*i+j-1)=='#'||*(zuobiao+SIZE*i+j-1)=='&'||*(zuobiao+SIZE*i+j-1)=='+'){j--;
	 		gotoxy(2*j,i);
	 		*(zuobiao+SIZE*i+j)=' ';
	 		printf("%c",*(zuobiao+SIZE*i+j));
	 		break;
		 } 
		 	gotoxy(2*(j-1),i);
		 	printf("o");
		 		gotoxy(0,0);
		 	Sleep(15);
		 		gotoxy(2*(j-1),i);
		 	printf(" ");
		 		gotoxy(0,0);
	 }
}
else if(fang==4){//���� 
	 for(;j<25;j++){
	 	if(*(zuobiao+SIZE*i+j+1)=='#'||*(zuobiao+SIZE*i+j+1)=='&'||*(zuobiao+SIZE*i+j+1)=='+'){j++;
	 		gotoxy(2*j,i);
	 		*(zuobiao+SIZE*i+j)=' ';
	 		printf("%c\a",*(zuobiao+SIZE*i+j));
	 		break;
		 } 
		 	gotoxy(2*(j+1),i);
		 	printf("o");
		 		gotoxy(0,0);
		 		Sleep(15);
		 		gotoxy(2*(j+1),i);
		 	printf(" ");
		 		gotoxy(0,0);
	 }
}}
zidanshu--;
} 
void paoji(char *zuobiao){ 
	int i,j,p,q,cishu;
		if(paojishu==0){
		gotoxy(55,6);
		
		printf("��Һ�ڵ����Ѻľ�\n");return;}
		else {
				gotoxy(55,6);
					printf("ʣ���ڵ�����%d\n",paojishu-1);
			LOOP:
			gotoxy(0,29);
			printf("�������ڻ����������꣨�����߸�ʴ�ԣ���Һ�ڻ����䲻��Ӱ�죩\n") ;
			gotoxy(0,30);
			scanf("%d %d",&j,&i);
			fflush(stdin);
			if(i<1||i>25||j<1||j>25)goto LOOP;
			printf("\a");
			p=j;q=i;
	i=p;j=q;PAND UAN//ģ���ڵ��Ӷ�λ������Ĳ��� 
	Sleep(100);
	i=p-1;j=q;PAND UAN
	i=p+1;j=q;PAND UAN
	j=q-1;i=p;PAND UAN
	j=q+1;i=p;PAND UAN
		Sleep(100); 
	i=p-1;j=q-1;PAND UAN
	i=p+1;j=q-1;PAND UAN
	i=p-1;j=q+1;PAND UAN
	i=p+1;j=q+1;PAND UAN
	Sleep(100);
	i=p;j=q;PAN DING
	Sleep(100);
	i=p-1;j=q;PAN DING
	i=p+1;j=q;PAN DING
	j=q-1;i=p;PAN DING
	j=q+1;i=p;PAN DING
		Sleep(100); 
	i=p-1;j=q-1;PAN DING
	i=p+1;j=q-1;PAN DING
	i=p-1;j=q+1;PAN DING
	i=p+1;j=q+1;PAN DING
	Sleep(100);
				gotoxy(60,0);
		system("pause");
		gotoxy(60,0);
		printf("                    ");
		paojishu--;	}
} 

int lianxu=0;int pan=1;//�����ж������˶��ĺ� 
#define SHANG \
	if(*(zuobiao+SIZE*(x1-1)+ya)=='L'&&(jijie==1||jijie==5)){\
	srand(time(NULL));\
		int zhuan=rand()%2+1;\
	gotoxy(0,0);\
		gotoxy(2*ya,x1);*(zuobiao+SIZE*x1+ya)='*';\
	printf("%c",*(zuobiao+SIZE*x1+ya));\
	x1--;\
	gotoxy(2*ya,x1);*(zuobiao+SIZE*x1+ya)='@';\
		printf("%c",*(zuobiao+SIZE*x1+ya));\
			gotoxy(2*y3,x3);\
				*(zuobiao+SIZE*x3+y3)=' ';\
					printf("%c",*(zuobiao+SIZE*x3+y3));\
		bianli(1);\
			int jie=fanhui();\
				x3=sheshen[jie].x;y3=sheshen[jie].y;\
			eluosiyidong((char *)zuobiao);\
gotoxy(0,0); \
  if(zhuan==1){pan=zuo((char *)zuobiao);if(pan==0){pan=1;return 0;}}\
 else if(zhuan==2){pan=you((char *)zuobiao);if(pan==0){pan=1;return 0;}}\
	}\
		else if(*(zuobiao+SIZE*(x1-1)+ya)=='S'){\
		jifen+=4;\
		jiashiwu((char*)zuobiao);\
	eluosi((char *)zuobiao);\
	gotoxy(0,0);\
	jinshi();\
		gotoxy(2*ya,x1) ;*(zuobiao+SIZE*x1+ya)='*';\
	printf("%c",*(zuobiao+SIZE*x1+ya));\
	x1--;\
		gotoxy(2*ya,x1);*(zuobiao+SIZE*x1+ya)='@';\
	printf("%c",*(zuobiao+SIZE*x1+ya));\
	bianli(1);\
		tianjia(x3,y3);\
		eluosiyidong((char *)zuobiao);\
		int i,j;\
		for(i=1;i<SIZE-1;i++){\
			for(j=1;j<SIZE-1;j++){\
				if(*(zuobiao+SIZE*i+j)=='S')\
				*(zuobiao+SIZE*i+j)=' ';\
				gotoxy(2*j,i);\
				printf("%c",*(zuobiao+SIZE*i+j));\
			}\
		}\
gotoxy(0,0);\
	}\
else if(*(zuobiao+SIZE*(x1-1)+ya)=='$'){\
dashiwu++;\
			jiashiwu((char*)zuobiao);\
			eluosi((char *)zuobiao);\
		gotoxy(0,0);\
		jinshi(); \
		gotoxy(2*ya,x1);\
	*(zuobiao+SIZE*x1+ya)='*';\
	printf("%c",*(zuobiao+SIZE*x1+ya));\
	x1--;\
		gotoxy(2*ya,x1);\
	*(zuobiao+SIZE*x1+ya)='@';\
	printf("%c",*(zuobiao+SIZE*x1+ya));\
	bianli(1);\
	tianjia(x3,y3);\
	eluosiyidong((char *)zuobiao);gotoxy(0,0);}\
	else if(*(zuobiao+SIZE*(x1-1)+ya)=='#'||*(zuobiao+SIZE*(x1-1)+ya)=='&'||\
	*(zuobiao+SIZE*(x1-1)+ya)=='*'||*(zuobiao+SIZE*(x1-1)+ya)=='+')return 0;\
	else if(*(zuobiao+SIZE*(x1-1)+ya)=='U') {gotoxy(0,0);	\
				gotoxy(2*ya,x1);\
				*(zuobiao+SIZE*x1+ya)='*';\
				printf("%c",*(zuobiao+SIZE*x1+ya));\
				x1--;\
					gotoxy(2*ya,x1);\
				*(zuobiao+SIZE*x1+ya)='@';\
					printf("%c",*(zuobiao+SIZE*x1+ya));\
			gotoxy(2*y3,x3);\
				*(zuobiao+SIZE*x3+y3)=' ';\
					printf("%c",*(zuobiao+SIZE*x3+y3));bianli(1);\
				int jie=fanhui();\
				x3=sheshen[jie].x;y3=sheshen[jie].y;\
				eluosiyidong((char *)zuobiao);\
	gotoxy(0,0);	shuaxin((char *)zuobiao);}\
		else {gotoxy(0,0);	\
				gotoxy(2*ya,x1);\
				*(zuobiao+SIZE*x1+ya)='*';\
				printf("%c",*(zuobiao+SIZE*x1+ya));\
				x1--;\
					gotoxy(2*ya,x1);\
				*(zuobiao+SIZE*x1+ya)='@';\
					printf("%c",*(zuobiao+SIZE*x1+ya));\
			gotoxy(2*y3,x3);\
				*(zuobiao+SIZE*x3+y3)=' ';\
					printf("%c",*(zuobiao+SIZE*x3+y3));bianli(1);\
				int jie=fanhui();\
				x3=sheshen[jie].x;y3=sheshen[jie].y;\
				eluosiyidong((char *)zuobiao);\
	gotoxy(0,0);	}\
	 if(*(zuobiao+SIZE*(x1-1)+ya)=='&')return 0;\
lianxu=0;\
		Sleep(speed);\
		
int shang(char *zuobiao){
	IF
	int t;
	eluosiyidong((char *)zuobiao);
int x;char ch=0;
while(ch!=68&&ch!=65&&ch!=97&&ch!=100)
{danzhuyidong((char *)zuobiao);
if(kbhit()){ch=getch();
if(ch==27)return 0; 
if(lianxu==1){lianxu=0;ch=0;}
if(ch==65||ch==68||ch==97||ch==100)break;
if(ch==32){gotoxy(70,12);
system("pause");gotoxy(70,12);printf("                   ");}
if(ch==81||ch==113) zidan(1,(char *)zuobiao);
if(ch==82||ch==114)paoji((char *)zuobiao);}
if(jijie==2||jijie==5){
yidongcishu++;
	gotoxy(55,8);printf("��ֵ��%d   ",yidongcishu);
	if(yidongcishu==40){gotoxy(55,9);printf("���ѱ���������Ϸ����");return 0;}
}
	SHANG
}if(ch==65||ch==97){if(jijie==4||jijie==5){SHANG}if(jijie==4||jijie==5){SHANG}lianxu=1;jiazhangai((char *)zuobiao);t=zuo((char *)zuobiao);}
if(ch==68||ch==100){if(jijie==4||jijie==5){SHANG}if(jijie==4||jijie==5){SHANG}lianxu=1;jiazhangai((char *)zuobiao);t=you((char *)zuobiao);}
	} 
	//�����ж������˶��ĺ� 
	#define XIA\
	if(*(zuobiao+SIZE*(x1+1)+ya)=='L'&&(jijie==1||jijie==5)){\
		srand(time(NULL));\
		int zhuan=rand()%2+1;\
	gotoxy(0,0);\
		gotoxy(2*ya,x1);*(zuobiao+SIZE*x1+ya)='*';\
	printf("%c",*(zuobiao+SIZE*x1+ya));\
	x1++;\
	gotoxy(2*ya,x1);*(zuobiao+SIZE*x1+ya)='@';\
		printf("%c",*(zuobiao+SIZE*x1+ya));\
			gotoxy(2*y3,x3);	*(zuobiao+SIZE*x3+y3)=' ';\
				printf("%c",*(zuobiao+SIZE*x3+y3));\
		bianli(2);\
		int jie=fanhui();\
				x3=sheshen[jie].x;y3=sheshen[jie].y;\
			eluosiyidong((char *)zuobiao);\
gotoxy(0,0);\
  if(zhuan==1){pan=zuo((char *)zuobiao);if(pan==0){pan=1;return 0;}}\
 else if(zhuan==2){pan=you((char *)zuobiao);if(pan==0){pan=1;return 0;}}\
	}\
		else if(*(zuobiao+SIZE*(x1+1)+ya)=='S'){\
			jifen+=4;\
		jiashiwu((char*)zuobiao);\
	eluosi((char *)zuobiao);\
	gotoxy(0,0);\
	jinshi();\
		gotoxy(2*ya,x1) ;*(zuobiao+SIZE*x1+ya)='*';\
	printf("%c",*(zuobiao+SIZE*x1+ya));\
	x1++;\
		gotoxy(2*ya,x1);*(zuobiao+SIZE*x1+ya)='@';\
	printf("%c",*(zuobiao+SIZE*x1+ya));\
	bianli(2);\
		tianjia(x3,y3);\
		eluosiyidong((char *)zuobiao);\
		int i,j;\
		for(i=1;i<SIZE-1;i++){\
			for(j=1;j<SIZE-1;j++){\
				if(*(zuobiao+SIZE*i+j)=='S')\
				*(zuobiao+SIZE*i+j)=' ';\
				gotoxy(2*j,i);\
				printf("%c",*(zuobiao+SIZE*i+j));\
			}\
		}\
gotoxy(0,0);\
	}\
	else if(*(zuobiao+SIZE*(x1+1)+ya)=='$'){\
	dashiwu++;\
	jiashiwu((char*)zuobiao);\
	eluosi((char *)zuobiao);\
	gotoxy(0,0);\
	jinshi();\
		gotoxy(2*ya,x1);*(zuobiao+SIZE*x1+ya)='*';\
	printf("%c",*(zuobiao+SIZE*x1+ya));\
	x1++;\
	gotoxy(2*ya,x1);*(zuobiao+SIZE*x1+ya)='@';\
		printf("%c",*(zuobiao+SIZE*x1+ya));\
		bianli(2);\
			tianjia(x3,y3);\
			eluosiyidong((char *)zuobiao);\
gotoxy(0,0);}\
	else if(*(zuobiao+SIZE*(x1+1)+ya)=='#'||*(zuobiao+SIZE*(x1+1)+ya)=='&'||\
	*(zuobiao+SIZE*(x1+1)+ya)=='*'||*(zuobiao+SIZE*(x1-1)+ya)=='+')return 0;\
		else if(*(zuobiao+SIZE*(x1+1)+ya)=='U') {gotoxy(0,0);	\
				gotoxy(2*ya,x1);\
				*(zuobiao+SIZE*x1+ya)='*';\
				printf("%c",*(zuobiao+SIZE*x1+ya));\
				x1++;\
					gotoxy(2*ya,x1);\
				*(zuobiao+SIZE*x1+ya)='@';\
					printf("%c",*(zuobiao+SIZE*x1+ya));\
			gotoxy(2*y3,x3);\
				*(zuobiao+SIZE*x3+y3)=' ';\
					printf("%c",*(zuobiao+SIZE*x3+y3));bianli(2);\
				int jie=fanhui();\
				x3=sheshen[jie].x;y3=sheshen[jie].y;\
				eluosiyidong((char *)zuobiao);\
	gotoxy(0,0);	shuaxin((char *)zuobiao);}\
		else {gotoxy(0,0);	\
				gotoxy(2*ya,x1);*(zuobiao+SIZE*x1+ya)='*';\
					printf("%c",*(zuobiao+SIZE*x1+ya));\
				x1++;\
				gotoxy(2*ya,x1);*(zuobiao+SIZE*x1+ya)='@';\
					printf("%c",*(zuobiao+SIZE*x1+ya));\
				gotoxy(2*y3,x3);	*(zuobiao+SIZE*x3+y3)=' ';\
				printf("%c",*(zuobiao+SIZE*x3+y3));\
				bianli(2);\
								int jie=fanhui();\
				x3=sheshen[jie].x;y3=sheshen[jie].y;\
			eluosiyidong((char *)zuobiao);\
		gotoxy(0,0);}\
			 if(*(zuobiao+SIZE*(x1+1)+ya)=='&')return 0;\
		Sleep(speed);\
		lianxu=0;\
	
int xia(char *zuobiao){
	
	IF
eluosiyidong((char *)zuobiao);
	int t;
	int x;char ch=0;
while(ch!=68&&ch!=65&&ch!=97&&ch!=100)
{danzhuyidong((char *)zuobiao);

	if(kbhit()){ch=getch();
	if(ch==27)return 0; 
	if(lianxu==1){lianxu=0;ch=0;}
	if(ch==65||ch==68||ch==97||ch==100)break;
	if(ch==32){gotoxy(70,12);
	system("pause");gotoxy(70,12);printf("                   ");}
	if(ch==81||ch==113) zidan(2,(char *)zuobiao);
	if(ch==82||ch==114)paoji((char *)zuobiao);}//�ո���ͣ 
	if(jijie==2||jijie==5){
yidongcishu++;
	gotoxy(55,8);printf("��ֵ��%d   ",yidongcishu);
	if(yidongcishu==40){gotoxy(55,9);printf("���ѱ���������Ϸ����");return 0;}
}
XIA
}
if(ch==65||ch==97){	if(jijie==4||jijie==5){XIA}if(jijie==4||jijie==5){XIA}lianxu=1;jiazhangai((char *)zuobiao);t=zuo((char *)zuobiao);}
if(ch==68||ch==100){	if(jijie==4||jijie==5){XIA}if(jijie==4||jijie==5){XIA}lianxu=1;jiazhangai((char *)zuobiao);t=you((char *)zuobiao);}
}
//�����ж������˶��ĺ� 
#define ZUO \
	if(*(zuobiao+SIZE*x1+ya-1)=='L'&&(jijie==1||jijie==5)){\
		srand(time(NULL));\
		int zhuan=rand()%2+1;\
	gotoxy(0,0);\
		gotoxy(2*ya,x1);*(zuobiao+SIZE*x1+ya)='*';\
	printf("%c",*(zuobiao+SIZE*x1+ya));\
	ya--;\
	gotoxy(2*ya,x1);*(zuobiao+SIZE*x1+ya)='@';\
		printf("%c",*(zuobiao+SIZE*x1+ya));\
			gotoxy(2*y3,x3);	*(zuobiao+SIZE*x3+y3)=' ';\
				printf("%c",*(zuobiao+SIZE*x3+y3));\
		bianli(3);\
		int jie=fanhui();\
				x3=sheshen[jie].x;y3=sheshen[jie].y;\
			eluosiyidong((char *)zuobiao);\
gotoxy(0,0);\
 if(zhuan==1){pan=xia((char *)zuobiao);if(pan==0){pan=1;return 0;}}\
 else if(zhuan==2){pan=shang((char *)zuobiao);if(pan==0){pan=1;return 0;}}\
	}\
	else if(*(zuobiao+SIZE*x1+ya-1)=='S'){\
		jifen+=4;\
		jiashiwu((char*)zuobiao);\
	eluosi((char *)zuobiao);\
	gotoxy(0,0);\
	jinshi();\
		gotoxy(2*ya,x1) ;*(zuobiao+SIZE*x1+ya)='*';\
	printf("%c",*(zuobiao+SIZE*x1+ya));\
	ya--;\
		gotoxy(2*ya,x1);*(zuobiao+SIZE*x1+ya)='@';\
	printf("%c",*(zuobiao+SIZE*x1+ya));\
	bianli(3);\
		tianjia(x3,y3);\
		eluosiyidong((char *)zuobiao);\
		int i,j;\
		for(i=1;i<SIZE-1;i++){\
			for(j=1;j<SIZE-1;j++){\
				if(*(zuobiao+SIZE*i+j)=='S')\
				*(zuobiao+SIZE*i+j)=' ';\
				gotoxy(2*j,i);\
				printf("%c",*(zuobiao+SIZE*i+j));\
			}\
		}\
gotoxy(0,0);\
	}\
else if(*(zuobiao+SIZE*x1+ya-1)=='$'){\
dashiwu++;\
	jiashiwu((char*)zuobiao);\
	eluosi((char *)zuobiao);\
	gotoxy(0,0);\
	jinshi();\
		gotoxy(2*ya,x1) ;*(zuobiao+SIZE*x1+ya)='*';\
	printf("%c",*(zuobiao+SIZE*x1+ya));\
	ya--;\
		gotoxy(2*ya,x1);*(zuobiao+SIZE*x1+ya)='@';\
	printf("%c",*(zuobiao+SIZE*x1+ya));\
	bianli(3);\
		tianjia(x3,y3);\
		eluosiyidong((char *)zuobiao);\
gotoxy(0,0);}\
	else if(*(zuobiao+SIZE*x1+ya-1)=='#'||*(zuobiao+SIZE*x1+ya-1)=='&'||\
	*(zuobiao+SIZE*x1+ya-1)=='*'||*(zuobiao+SIZE*(x1-1)+ya)=='+')return 0;\
		else if(*(zuobiao+SIZE*x1+ya-1)=='U') {gotoxy(0,0);	\
				gotoxy(2*ya,x1);\
				*(zuobiao+SIZE*x1+ya)='*';\
				printf("%c",*(zuobiao+SIZE*x1+ya));\
				ya--;\
					gotoxy(2*ya,x1);\
				*(zuobiao+SIZE*x1+ya)='@';\
					printf("%c",*(zuobiao+SIZE*x1+ya));\
			gotoxy(2*y3,x3);\
				*(zuobiao+SIZE*x3+y3)=' ';\
					printf("%c",*(zuobiao+SIZE*x3+y3));bianli(3);\
				int jie=fanhui();\
				x3=sheshen[jie].x;y3=sheshen[jie].y;\
				eluosiyidong((char *)zuobiao);\
	gotoxy(0,0);	shuaxin((char *)zuobiao);}\
		else {gotoxy(0,0);\
				gotoxy(2*ya,x1);	*(zuobiao+SIZE*x1+ya)='*';\
				printf("%c",*(zuobiao+SIZE*x1+ya));\
				ya--;\
				gotoxy(2*ya,x1);	*(zuobiao+SIZE*x1+ya)='@';\
				printf("%c",*(zuobiao+SIZE*x1+ya));\
				gotoxy(2*y3,x3);	*(zuobiao+SIZE*x3+y3)=' ';\
				printf("%c",*(zuobiao+SIZE*x3+y3));\
						bianli(3);\
								int jie=fanhui();\
				x3=sheshen[jie].x;y3=sheshen[jie].y;\
			eluosiyidong((char *)zuobiao);\
	gotoxy(0,0);}\
		 if(*(zuobiao+SIZE*x1+ya-1)=='&')return 0;\
lianxu=0;\
		Sleep(speed);\
		
int zuo(char *zuobiao){
	IF
eluosiyidong((char *)zuobiao);
	int t;
		int x;char ch=0;
while(ch!=83&&ch!=87&&ch!=115&&ch!=119)
{danzhuyidong((char *)zuobiao);

if(kbhit()){ch=getch();
if(ch==27)return 0; 
if(lianxu==1){lianxu=0;ch=0;}
if(ch==83||ch==87||ch==115||ch==119)break;
if(ch==32){gotoxy(70,12);
system("pause");gotoxy(70,12);printf("                   ");}
if(ch==81||ch==113) zidan(3,(char *)zuobiao);
if(ch==82||ch==114)paoji((char *)zuobiao);}
if(jijie==2||jijie==5){
yidongcishu++;
	gotoxy(55,8);printf("��ֵ��%d   ",yidongcishu);
	if(yidongcishu==40){gotoxy(55,9);printf("���ѱ���������Ϸ����");return 0;}
}
ZUO
}if(ch==83||ch==115){	if(jijie==4||jijie==5){ZUO}if(jijie==4||jijie==5){ZUO}lianxu=1;jiazhangai((char *)zuobiao);t=xia((char *)zuobiao);}
if(ch==87||ch==119){	if(jijie==4||jijie==5){ZUO}if(jijie==4||jijie==5){ZUO}lianxu=1;jiazhangai((char *)zuobiao);t=shang((char *)zuobiao);}
}
//�����ж������˶��ĺ� 
#define YOU \
	if(*(zuobiao+SIZE*x1+ya+1)=='L'&&(jijie==1||jijie==5)){  \
		srand(time(NULL));\
		int zhuan=rand()%2+1;\
	gotoxy(0,0);\
		gotoxy(2*ya,x1);*(zuobiao+SIZE*x1+ya)='*';\
	printf("%c",*(zuobiao+SIZE*x1+ya));\
	ya++;\
	gotoxy(2*ya,x1);*(zuobiao+SIZE*x1+ya)='@';\
		printf("%c",*(zuobiao+SIZE*x1+ya));\
			gotoxy(2*y3,x3);*(zuobiao+SIZE*x3+y3)=' ';\
					printf("%c",*(zuobiao+SIZE*x3+y3));\
		bianli(4);\
			int jie=fanhui();\
				x3=sheshen[jie].x;y3=sheshen[jie].y;\
			eluosiyidong((char *)zuobiao);\
gotoxy(0,0);\
 if(zhuan==1){pan=xia((char *)zuobiao);if(pan==0){pan=1;return 0;}}\
 else if(zhuan==2){pan=shang((char *)zuobiao);if(pan==0){pan=1;return 0;}}\
	}\
		else if(*(zuobiao+SIZE*x1+ya+1)=='S'){\
			jifen+=4;\
		jiashiwu((char*)zuobiao);\
	eluosi((char *)zuobiao);\
	gotoxy(0,0);\
	jinshi();\
		gotoxy(2*ya,x1) ;*(zuobiao+SIZE*x1+ya)='*';\
	printf("%c",*(zuobiao+SIZE*x1+ya));\
	ya++;\
		gotoxy(2*ya,x1);*(zuobiao+SIZE*x1+ya)='@';\
	printf("%c",*(zuobiao+SIZE*x1+ya));\
	bianli(4);\
		tianjia(x3,y3);\
		eluosiyidong((char *)zuobiao);\
		int i,j;\
		for(i=1;i<SIZE-1;i++){\
			for(j=1;j<SIZE-1;j++){\
				if(*(zuobiao+SIZE*i+j)=='S')\
				*(zuobiao+SIZE*i+j)=' ';\
				gotoxy(2*j,i);\
				printf("%c",*(zuobiao+SIZE*i+j));\
			}\
		}\
gotoxy(0,0);\
	}\
else if(*(zuobiao+SIZE*x1+ya+1)=='$'){\
dashiwu++;\
	jiashiwu((char*)zuobiao);\
	eluosi((char *)zuobiao);\
	gotoxy(0,0);\
	jinshi();\
		gotoxy(2*ya,x1);*(zuobiao+SIZE*x1+ya)='*';\
	printf("%c",*(zuobiao+SIZE*x1+ya));\
	ya++;\
	gotoxy(2*ya,x1);	*(zuobiao+SIZE*x1+ya)='@';\
	printf("%c",*(zuobiao+SIZE*x1+ya));\
	bianli(4);\
		tianjia(x3,y3);\
		eluosiyidong((char *)zuobiao);\
	gotoxy(0,0);}\
	else if(*(zuobiao+SIZE*x1+ya+1)=='#'||*(zuobiao+SIZE*x1+ya+1)=='&'||\
	*(zuobiao+SIZE*x1+ya+1)=='*'||*(zuobiao+SIZE*(x1-1)+ya)=='+')return 0;\
		else if(*(zuobiao+SIZE*x1+ya+1)=='U') {gotoxy(0,0);	\
				gotoxy(2*ya,x1);\
				*(zuobiao+SIZE*x1+ya)='*';\
				printf("%c",*(zuobiao+SIZE*x1+ya));\
				ya++;\
					gotoxy(2*ya,x1);\
				*(zuobiao+SIZE*x1+ya)='@';\
					printf("%c",*(zuobiao+SIZE*x1+ya));\
			gotoxy(2*y3,x3);\
				*(zuobiao+SIZE*x3+y3)=' ';\
					printf("%c",*(zuobiao+SIZE*x3+y3));bianli(4);\
				int jie=fanhui();\
				x3=sheshen[jie].x;y3=sheshen[jie].y;\
				eluosiyidong((char *)zuobiao);\
	gotoxy(0,0);	shuaxin((char *)zuobiao);}\
		else {gotoxy(0,0);	\
				gotoxy(2*ya,x1);*(zuobiao+SIZE*x1+ya)='*';\
					printf("%c",*(zuobiao+SIZE*x1+ya));\
				ya++;\
				gotoxy(2*ya,x1);	*(zuobiao+SIZE*x1+ya)='@';\
				printf("%c",*(zuobiao+SIZE*x1+ya));\
				gotoxy(2*y3,x3);*(zuobiao+SIZE*x3+y3)=' ';\
					printf("%c",*(zuobiao+SIZE*x3+y3));\
						bianli(4);\
						int jie=fanhui();\
				x3=sheshen[jie].x;y3=sheshen[jie].y;\
			eluosiyidong((char *)zuobiao);\
	gotoxy(0,0);	}\
		 if(*(zuobiao+SIZE*x1+ya+1)=='&')return 0;\
lianxu=0;\
				Sleep(speed);\
				
int you(char *zuobiao){
	IF
	eluosiyidong((char *)zuobiao);
	int t;
		int x;char ch=0;
	
while(ch!=83&&ch!=87&&ch!=115&&ch!=119)
{danzhuyidong((char *)zuobiao);

	if(kbhit()){ch=getch();
	if(ch==27)return 0; 
	if(lianxu==1){lianxu=0;ch=0;}
	if(ch==83||ch==87||ch==115||ch==119)break;
	if(ch==32){gotoxy(70,12);
	system("pause");gotoxy(70,12);printf("                   ");}
	if(ch==81||ch==113) zidan(4,(char *)zuobiao);
	if(ch==82||ch==114)paoji((char *)zuobiao);}
	if(jijie==2||jijie==5){
yidongcishu++;
	gotoxy(55,8);printf("��ֵ��%d   ",yidongcishu);
	if(yidongcishu==40){gotoxy(55,9);printf("���ѱ���������Ϸ����");return 0;}
}
	YOU
}if(ch==83||ch==115){	if(jijie==4||jijie==5){YOU}if(jijie==4||jijie==5){YOU}lianxu=1;jiazhangai((char *)zuobiao);t=xia((char *)zuobiao);}
if(ch==87||ch==119){	if(jijie==4||jijie==5){YOU}if(jijie==4||jijie==5){YOU}lianxu=1;jiazhangai((char *)zuobiao);t=shang((char *)zuobiao);}
}
void yidong(char *zuobiao){ 
	if(jijie==2){
	gotoxy(55,8);printf("��ֵ��%d   ",yidongcishu);}
	int t;
	LOOP:
		gotoxy(0,28);
		char zhiling;
	zhiling=getch();
	fflush(stdin);
	 if(zhiling=='W'||zhiling=='w'){if(MAXX==x1&&ya==y2) goto LOOP;else t=shang((char *)zuobiao);}
	else if(zhiling=='S'||zhiling=='s'){if(MINX==x1&&ya==y2) goto LOOP;else t=xia((char *)zuobiao);}
	else if(zhiling=='A'||zhiling=='a'){if(MAXY==ya&&x1==x2) goto LOOP;else t=zuo((char *)zuobiao);}
	else if(zhiling=='D'||zhiling=='d'){if(MINY==ya&&x1==x2) goto LOOP;else t=you((char *)zuobiao);}
	else goto LOOP;
if(jijie==3||jijie==5){gotoxy(0,29);printf("�����Ī�������û�ˣ��뿴���������＾�Ĺ����");}
gotoxy(0,30);
    printf("��������HAHAHAHAhahahaha��������⣿\n");
	system("pause");
}
