#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h> 
#define SIZE 27//25*25的区域及边界 
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

//炮弹和连拐弯 
int huihe=0; 
struct a{//记录蛇身 
	int x;
	int y; 
};
typedef struct a jilu;
jilu sheshen[100];//蛇身节点的数组 

char zuobiao[SIZE][SIZE];//区域打印 
int x1,ya,x2,y2,x3,y3;//初始蛇身 
int jifen=0;//积分 
int speed;//游戏难度 
int zhuangtai=0;
int k,l;
int paojishu=1;int zidanshu=5; 
int jijie=0;//选择季节 
int yidongcishu=0;//计算次数 即渴值 
int dashiwu=0;//生成大食物 

int maxx(int a,int b)
{
	return a>=b ? a:b;
}
int minx(int a,int b)
{
	return a>b ? b:a;
}

void quyu(char *zuobiao);//初始化游戏区域 
void jiemian();//打印界面 
void ditu(char *zuobiao);//打印地图 
void chushihua(char *zuobiao);//初始化食物点和壁虎点 
void yidong(char *zuobiao); //进行移动 
int shang(char *zuobiao);//向上移动 
int xia(char *zuobiao);//向下移动 
int zuo(char *zuobiao);//向左移动 
int you(char *zuobiao);//向右移动 
void jiashiwu(char *zuobiao); //刷新吃掉的食物 
void jiazhangai(char *zuobiao);//增加障碍物 
void jieshu();//打印GAME OVER界面
void eluosi(char *zuobiao);//随机生成俄罗斯方块 
void eluosiyidong(char *zuobiao);//俄罗斯方块的移动 
int zidan(int fang,char *zuobiao);//发射一个子弹摧毁直线上的障碍物 
void paoji(char *zuobiao);//发射毒液炮弹毁坏3*3区域 
void jinshi();//计算进食后增加射击，炮击机会的概率 
void moshi();//选择季节模式，对应不同的游戏机制 
void  gotoxy( int  x,  int  y) //gotoxy 源代码光标
{
COORD pos;
pos.X = x ;
pos.Y = y ;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void bianli(int fang){//遍历蛇身 
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
void tianjia(int x3,int y3){//添加蛇身 
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
		printf("请输入W(上),S(下),A(左),D(右)\n");
			gotoxy(55,4);
			printf("剩余子弹数：%d\n",zidanshu);
				gotoxy(55,6);
			printf("剩余炮弹数：%d\n",paojishu);
	yidong((char *)zuobiao);
	jieshu();
		system("cls");
		system("color 0A");
	menu:
	printf("请选择重开或结束程序 1.重开 2.结束程序\n");
	scanf("%d",&choice);
	fflush(stdin);
	if(choice==1)goto LOOP;
	else if(choice==2)return 0;
	else goto menu;
} 

void jieshu(){
		system("cls");
		system("color 0D");
	printf("    **********俄罗斯贪吃壁虎游戏**********\n");
    printf("            GAME OVER  积分数： %d\n",jifen) ;
	printf("    ********太拉了，下次继续努力吧********\n");
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

void jiemian(){//规则说明 
	system("cls");
	system("color 0C");
	printf("    **********俄罗斯贪吃壁虎游戏**********\n");
	printf("            爷懒，自己探索规则去吧\n") ;
	printf("    ***********按任意键开始游戏***********\n");
	system("pause");
	system("cls");
	system("color 0E");
	printf("*算了，还是告诉你亿件事吧。\n");
	printf("*初始情况：身长为3的小蛇，15个障碍点，4个食物点\n") ;
	printf("*拐弯操作请勿过快，否则第二次拐弯将作无效处理\n");
	printf("*1.* 蛇身，2.@ 蛇头，3.# 边界及障碍物，4. & 俄罗斯方块，5.$ 为食物(每五次生成一个大食物点S，吃到积分+4),6.o为弹珠\n");
	printf("*游戏分为春夏秋冬四个模式，每个模式有各自的效果"); 
	printf("*春天每拐弯一次会有50%概率随机生成一个藤蔓（ L ），遇到藤蔓蛇会不断挣扎将藤蔓损毁，同时方向随机改变\n"); 
	printf("*夏天由于炎热蛇会趋向水源，地图将随机产生一个小水潭( U ),如果在40次移动内不能赶到水源蛇将会被渴死\n"); 
	printf("*秋天由于落叶每次拐弯将有20%概率产生一个隐藏的不可见的障碍物\n");
	printf("*冬天由于地面结冰打滑，拐弯将延迟两个回合执行\n");
	printf("*俄罗斯方块分为丁四，直四，曲四，方四，L型四五种，朝向随机\n");
	 printf("*@头撞#或&或*死亡，*身撞&断尾\n");
	 printf("*每拐一次弯会增加一个障碍物#,并且速度会小幅度提升\n"); 
	  printf("*每吃一个$触发一次俄罗斯方块下坠\n");
	  printf("*俄罗斯方块比障碍物和食物要硬，所以会摧毁障碍物并刷新食物点\n");
	   printf("*游戏开始从地图左上角会弹出一个弹珠，以对角线方向移动，\n*遇到蛇头，蛇身，障碍物，俄罗斯方块,食物等以另一个对角线方向反弹\n");
	   printf("*同时被撞击的障碍物及俄罗斯方块被摧毁，边界同样会被损坏,而俄罗斯方块的堆积会修复边界\n"); 
	    printf("*边界同样会被摧毁,而蛇因为身体柔软不受影响（实际上是怕难度太高你玩不转）\n"); 
	    printf("*当弹珠弹到损坏的边界(或障碍物)，会增加一个食物点\n"); 
	    printf("*你可以通过按 Q 或 q 来牺牲一次毒液发射机会用于发射毒液子弹，子弹将会摧毁蛇头直线上的最近障碍物（总共五次）\n");
	    printf("*你可以通过按 R 或 r 来牺牲一次强腐蚀性毒液发射机会用于发射毒液炮弹，炮弹将会摧毁3*3的区域（总共一次）\n");
	   	printf("*注意：毒液不会腐蚀蛇自身，子弹会穿过食物点，而炮弹会损坏食物点并不会刷新\n");
	   	printf("*每进食一次会有20%概率增加一次毒液炮击机会，50%概率增加一次毒液射击机会\n");
	      printf("*我猜你已经看出来，这并不是一个养成游戏，而是生存游戏\n"); 
	       printf("*积分的高低更多在于生存的时间而不是长度\n"); 
	    printf("*合理利用俄罗斯方块和弹珠会提高游戏体验\n");
	  printf("*积分以吃食物总数为准，不以最终长度为准（怕你分数太少自卑）\n");
	  printf("*游戏中按 ESC 键强制退出游戏界面\n");
	 system("pause");
	 system("cls");	system("color 0B");
	 menu:
	 printf("\n\n*********请选择游戏难度**********\n");
	 printf("*****1.S级\n*****2.A级\n*****3.B级\n*****4.C级\n");
	 scanf("%d",&speed);
	 fflush(stdin);
	 if(speed==1)speed=50;
	 else if(speed==2)speed=100;
	  else if(speed==3)speed=150;
	    else if(speed==4)speed=180;
	 else goto menu;
	 moshi();
}
void moshi(){//模式选择 
	 menu:
	 printf("\n\n*********请选择游戏模式**********\n");
	 printf("*****1.春季\n*****2.夏季\n*****3.秋季\n*****4.冬季\n*****5.地狱模式\n*****0.菜鸟模式\n");
	 scanf("%d",&jijie);
	 fflush(stdin);
if(jijie!=1&&jijie!=2&&jijie!=3&&jijie!=4&&jijie!=5&&jijie!=0)
	  goto menu;
}

void ditu(char *zuobiao){ //打印 
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
	
	void danzhuyidong(char *zuobiao){//提供弹珠运动轨迹 
		int m,n;
		m=k;n=l;
		*(zuobiao+SIZE*k+l)=' ';
		gotoxy(2*l,k);
		printf("%c",*(zuobiao+SIZE*k+l));
		if(zhuangtai==1){//右下 
		
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
		else if(zhuangtai==2){//左下 
		
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
		else if(zhuangtai==3){//右上 
		
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
		else if(zhuangtai==4){//左上
		
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
	//初始化弹珠
	*(zuobiao+SIZE+1)='o';
	k=1;l=1;
	zhuangtai=1; 
	int w;
	for(w=0;w<100;w++){
		sheshen[w].x=0;sheshen[w].y=0;
	}
	srand(time(NULL));
		int fangxiang;//初始化壁虎 
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
		
	int a,b,c,d,e,f,g,h;//初始食物点坐标 
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
	//初始化障碍物 
	int m,n;int i;
for(i=0;i<15;i++){
	m=rand()%25+1;
	n=rand()%25+1;
	while(*(zuobiao+SIZE*m+n)!=' '){m=rand()%25+1;n=rand()%25+1;}
	*(zuobiao+SIZE*m+n)='#';
}	
if(jijie==2||jijie==5){//夏季 
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
void shuaxin(char *zuobiao){//刷新水潭和渴值
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
void jinshi(){//判断进食后子弹和炮弹变化 
	      int m=rand()%5+1,n=rand()%2+1;
    if(n==1)zidanshu++;
    if(m==1)paojishu++;
    gotoxy(55,4);
    printf("                          ");
    gotoxy(55,4);
	printf("剩余子弹数：%d\n",zidanshu);
	gotoxy(55,6);
	printf("                          ");
	gotoxy(55,6);
	printf("剩余炮弹数：%d\n",paojishu);
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

	void eluosi(char *zuobiao){//随机生成俄罗斯方块 
	gotoxy(0,0);
	srand(time(NULL));
	int choice1=rand()%5+1;
	int choice2=rand()%4+1;
	int a=1,b=rand()%25+1;
	//上方 
	if(choice1==1){//丁四 
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
	
	else if(choice1==2){//方块 
				while(*(zuobiao+SIZE*a+b+1)!=' '||*(zuobiao+SIZE*a+b)!=' '||*(zuobiao+SIZE*(a+1)+b+1)!=' '||*(zuobiao+SIZE*(a+1)+b)!=' ')b=rand()%25+1;
			gotoxy(2*(b+1),a);*(zuobiao+SIZE*a+b+1)='&';printf("%c",*(zuobiao+SIZE*a+b+1));
			gotoxy(2*b,a);*(zuobiao+SIZE*a+b)='&';printf("%c",*(zuobiao+SIZE*a+b));
		    gotoxy(2*(b+1),a+1);*(zuobiao+SIZE*(a+1)+b+1)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b+1));
			gotoxy(2*b,a+1);*(zuobiao+SIZE*(a+1)+b)='&';printf("%c",*(zuobiao+SIZE*(a+1)+b));
		}	
		
	else if(choice1==3){//直四 
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
			
		else if(choice1==4){//曲四 
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
		
			else if(choice1==5){//L型四 
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
void duanwei(int i,int j,char *zuobiao){//计算断尾的情况 
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
void eluosiyidong(char* zuobiao){//记录俄罗斯方块的移动 
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

int zidan(int fang,char *zuobiao){//发射一个子弹摧毁直线上的障碍物 
int i,j; 
if(zidanshu==0){
	gotoxy(55,4);
	printf("毒液子弹数已耗尽\n");return 0;}
	else {
		gotoxy(55,4);
			printf("剩余子弹数：%d\n\a",zidanshu-1);
	
i=sheshen[0].x;j=sheshen[0].y;
if(fang==1){//向上 
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
else if(fang==2){//向下 
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
else if(fang==3){//向左 
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
else if(fang==4){//向右 
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
		
		printf("毒液炮弹数已耗尽\n");return;}
		else {
				gotoxy(55,6);
					printf("剩余炮弹数：%d\n",paojishu-1);
			LOOP:
			gotoxy(0,29);
			printf("请输入炮击的中心坐标（蛇免疫腐蚀性，毒液炮击对其不受影响）\n") ;
			gotoxy(0,30);
			scanf("%d %d",&j,&i);
			fflush(stdin);
			if(i<1||i>25||j<1||j>25)goto LOOP;
			printf("\a");
			p=j;q=i;
	i=p;j=q;PAND UAN//模拟炮弹从定位到发射的步骤 
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

int lianxu=0;int pan=1;//定义判断向上运动的宏 
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
	gotoxy(55,8);printf("渴值：%d   ",yidongcishu);
	if(yidongcishu==40){gotoxy(55,9);printf("蛇已被渴死，游戏结束");return 0;}
}
	SHANG
}if(ch==65||ch==97){if(jijie==4||jijie==5){SHANG}if(jijie==4||jijie==5){SHANG}lianxu=1;jiazhangai((char *)zuobiao);t=zuo((char *)zuobiao);}
if(ch==68||ch==100){if(jijie==4||jijie==5){SHANG}if(jijie==4||jijie==5){SHANG}lianxu=1;jiazhangai((char *)zuobiao);t=you((char *)zuobiao);}
	} 
	//定义判断向下运动的宏 
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
	if(ch==82||ch==114)paoji((char *)zuobiao);}//空格暂停 
	if(jijie==2||jijie==5){
yidongcishu++;
	gotoxy(55,8);printf("渴值：%d   ",yidongcishu);
	if(yidongcishu==40){gotoxy(55,9);printf("蛇已被渴死，游戏结束");return 0;}
}
XIA
}
if(ch==65||ch==97){	if(jijie==4||jijie==5){XIA}if(jijie==4||jijie==5){XIA}lianxu=1;jiazhangai((char *)zuobiao);t=zuo((char *)zuobiao);}
if(ch==68||ch==100){	if(jijie==4||jijie==5){XIA}if(jijie==4||jijie==5){XIA}lianxu=1;jiazhangai((char *)zuobiao);t=you((char *)zuobiao);}
}
//定义判断向左运动的宏 
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
	gotoxy(55,8);printf("渴值：%d   ",yidongcishu);
	if(yidongcishu==40){gotoxy(55,9);printf("蛇已被渴死，游戏结束");return 0;}
}
ZUO
}if(ch==83||ch==115){	if(jijie==4||jijie==5){ZUO}if(jijie==4||jijie==5){ZUO}lianxu=1;jiazhangai((char *)zuobiao);t=xia((char *)zuobiao);}
if(ch==87||ch==119){	if(jijie==4||jijie==5){ZUO}if(jijie==4||jijie==5){ZUO}lianxu=1;jiazhangai((char *)zuobiao);t=shang((char *)zuobiao);}
}
//定义判断向右运动的宏 
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
	gotoxy(55,8);printf("渴值：%d   ",yidongcishu);
	if(yidongcishu==40){gotoxy(55,9);printf("蛇已被渴死，游戏结束");return 0;}
}
	YOU
}if(ch==83||ch==115){	if(jijie==4||jijie==5){YOU}if(jijie==4||jijie==5){YOU}lianxu=1;jiazhangai((char *)zuobiao);t=xia((char *)zuobiao);}
if(ch==87||ch==119){	if(jijie==4||jijie==5){YOU}if(jijie==4||jijie==5){YOU}lianxu=1;jiazhangai((char *)zuobiao);t=shang((char *)zuobiao);}
}
void yidong(char *zuobiao){ 
	if(jijie==2){
	gotoxy(55,8);printf("渴值：%d   ",yidongcishu);}
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
if(jijie==3||jijie==5){gotoxy(0,29);printf("如果你莫名其妙就没了，请看看规则里秋季的规则吧");}
gotoxy(0,30);
    printf("哈哈哈哈HAHAHAHAhahahaha，就这就这？\n");
	system("pause");
}
