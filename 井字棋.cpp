#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//函数声明 
int res(char number[3][3],int t,int size,int f,int quan,int cha,int i,int result);
void print_a(char number[3][3], int o, int p);
int main(){
begin://重新开始
int a,b,n,c,d,f,m,x,y,k;
 int result=2;//0为圈赢，1为叉赢，-1为平局 
 int size=3;
  int t,quan=0;
  int i,cha=0;
	char number[3][3]; 
	srand(time(0));//时间种子 
	//棋盘及坐标设置 
	printf("注意：坐标先行后列\n") ; 
printf("请输入棋子坐标，如：（1,1）写作 1空格1 \n");
back://重选 
number[0][0]=' ';number[1][0]=' ';number[2][0]=' ';number[0][1]=' ';number[1][1]=' ';number[2][1]=' ';number[0][2]=' ';number[1][2]=' ';number[2][2]=' ';
printf("请选择井字棋模式：1.对战  2.AI\n");
scanf("%d",&m);
printf("圈先手，叉后手，交替进行\n"); 
printf("       1     2     3  \n       %c  |  %c  |  %c  \n  1  _____|_____|_____\n       %c  |  %c  |  %c  \n  2  _____|_____|_____\n       %c  |  %C  |  %c  \n  3       |     |     \n"
,number[0][0],number[0][1],number[0][2],number[1][0],number[1][1],number[1][2],number[2][0],number[2][1],number[2][2]);
if(m==1){//对战模式 
//回合循环 
for(n=0;n<4;n++)
{
error1: 
 printf("请圈落子（输入坐标）\n"); 
scanf("%d %d",&a,&b);
if(a>3 || b>3 || number[b-1][a-1]!=' '){
 printf("输入坐标有误或重叠，请重新输入\n");
 goto error1;//坐标错误 
}
 number[b-1][a-1]='O';
printf("       1     2     3  \n       %c  |  %c  |  %c  \n  1  _____|_____|_____\n       %c  |  %c  |  %c  \n  2  _____|_____|_____\n       %c  |  %C  |  %c  \n  3       |     |     \n"
,number[0][0],number[0][1],number[0][2],number[1][0],number[1][1],number[1][2],number[2][0],number[2][1],number[2][2]);

 result= res(number,t,size,f,quan,cha,i,result); 
 if(result==1 || result==0){
 	goto out;}

error2:
printf("请叉落子（输入坐标）\n") ;
scanf("%d %d",&c,&d);
if(c>3 || d>3 || number[d-1][c-1]!=' '){
 printf("输入坐标有错或重叠， 11 请重新输入\n");
 goto error2;//坐标错误 
}
 number[d-1][c-1]='X';
printf("       1     2     3  \n       %c  |  %c  |  %c  \n  1  _____|_____|_____\n       %c  |  %c  |  %c  \n  2  _____|_____|_____\n       %c  |  %C  |  %c  \n  3       |     |     \n"
,number[0][0],number[0][1],number[0][2],number[1][0],number[1][1],number[1][2],number[2][0],number[2][1],number[2][2]);

 result= res(number,t,size,f,quan,cha,i,result);  
 if(result==1 || result==0){
 	goto out;}}

//最后落子
error3:
  printf("请圈落子（输入坐标）\n") ; 
scanf("%d %d",&a,&b);
if(a>3 || b>3 || number[b-1][a-1]!=' '){
 printf("输入坐标有误或重叠，请重新输入\n");
 goto error3;//坐标错误 
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
else if(m==2){//人工智能模式 
int n; 
back1:
printf("请选择先后手:  1.先手  2.后手\n");
scanf("%d",&n) ;
if(n==1){
	for(k=0;k<4;k++) {//循环落子 
	errora: 
 printf("请圈落子（输入坐标）\n") ; 
scanf("%d %d",&a,&b);
if(a>3 || b>3 || number[b-1][a-1]!=' '){
 printf("输入坐标有误或重叠，请重新输入\n");
 goto errora;//坐标错误 
}
 number[b-1][a-1]='O';
printf("       1     2     3  \n       %c  |  %c  |  %c  \n  1  _____|_____|_____\n       %c  |  %c  |  %c  \n  2  _____|_____|_____\n       %c  |  %C  |  %c  \n  3       |     |     \n"
,number[0][0],number[0][1],number[0][2],number[1][0],number[1][1],number[1][2],number[2][0],number[2][1],number[2][2]);

result= res(number,t,size,f,quan,cha,i,result); 
 if(result==1 || result==0){
 	goto out;}
 	back2://随机 
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
 		//最后一步 
		 errorb: 
 printf("请圈落子（输入坐标）\n") ; 
scanf("%d %d",&a,&b);
if(a>3 || b>3 || number[b-1][a-1]!=' '){
 printf("输入坐标有误或重叠，请重新输入\n");
 goto errorb;//坐标错误 
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
	for(k=0;k<4;k++){//循环落子 
	back3://随机 
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
 printf("请圈落子（输入坐标）\n") ; 
scanf("%d %d",&a,&b);
if(a>3 || b>3 || number[b-1][a-1]!=' '){
 printf("输入坐标有误或重叠，请重新输入\n");
 goto errorc;//坐标错误 
}
 number[b-1][a-1]='O';
printf("       1     2     3  \n       %c  |  %c  |  %c  \n  1  _____|_____|_____\n       %c  |  %c  |  %c  \n  2  _____|_____|_____\n       %c  |  %C  |  %c  \n  3       |     |     \n"
,number[0][0],number[0][1],number[0][2],number[1][0],number[1][1],number[1][2],number[2][0],number[2][1],number[2][2]);

 result= res(number,t,size,f,quan,cha,i,result); 
 if(result==1 || result==0){
 	goto out;}}
 	//最后落子 
 	back4://随机 
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
printf("\n本次井字棋结果为：\n");
 //最终判定胜负 
 if(result==0){
  printf("\t圈赢\n"); 
 }else if(result==1){
  printf("\t叉赢\n"); 
 }else if(result==-1){
 printf("\t平局\n");} 
system("pause");//停顿 
menu:
printf("请选择再来一局（输入 1 ）或关闭窗口（输入 0  ）");
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
//result函数 
int res(char number[3][3],int t,int size,int f,int quan,int cha,int i,int result){
	
	//检查列 
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
  
  //检查行 
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
  
  //检查正对角线 
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
 
  //检查反对角线 
  quan=cha=0;
  for(t=0;t<size;t++){
   if(number[t][size-t-1]=='O'){
    quan++; 
   }else if(number[t][size-t-1]=='X'){
    cha++;
   }}
   
   //判定胜负 
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
