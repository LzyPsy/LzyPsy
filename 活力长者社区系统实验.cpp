/*
�༶�����2108�� 
�鳤��������
��Ա������Ⱥ�����󶫣�����ܲ������ 
 
******��ԱȨ�����룺123
******ְ��Ȩ�����룺456 
******����ԱȨ�����룺789 
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h> 

#define BUILDING 6//���� 
#define UNIT x//��Ԫ�� 
#define FLOOR y//���� 
#define ROOM z//������ 

//Ԥ����¥��ĸ���ת��Ϊ�������  
#define VIPHOUSE \
cn=CN(startPtr->member.bulidingcharacter);\
*(house+BUILDING*FLOOR*UNIT*cn+FLOOR*UNIT*(startPtr->member.unitnumber-1)+UNIT*(startPtr->member.floornumber-1)+startPtr->member.roomnumber-1)='+'; 

//Ԥ�����ж�������ʩ�Ƿ��� 
#define ENJOY \
if(enjoy[newbuilt-1]==1){\
printf("�����ظ��½���������Ч������\n");break;}

//Ԥ�����ж����뷿����Ϣ�Ƿ���� 
#define HOUSECN \
	int num;\
	char character;\
	int unumber,fnumber,rnumber;\
	while(character<'A'||character>'F'||unumber<1||unumber>UNIT||fnumber<1||fnumber>FLOOR||rnumber<1||rnumber>ROOM){\
printf("***�����뷿�ݻ�����Ϣ���磺A 1 1 1 ��\n");\
scanf("%c %d %d %d",&character,&unumber,&fnumber,&rnumber);\
fflush(stdin);\
}\
num=CN(character);

//Ԥ�����жϰ೵�����Ƿ��Ѵ����� 
#define BUSNUM \
int i;\
for(i=0;i<10;i++){\
	if(shuttle[i].number==0){\
	shuttlenum=i;\
	break;}\
	if(shuttle[9].number!=0){\
	printf("***�����Ѵ����ޣ�������Ч");\
	system("pause>nul");\
	return ;} \
}

//Ԥ�����ж��Ƿ�Ϊ�״ε�¼ 
#define FIRSTJUDGE \
if(x==0){ \
instructions();}

//ȫ�ֱ��� 
int power=0;//Ȩ��
struct vip{
	char vipname[20];//���� 
	char vipdocument[20];//���֤�� 
	int vipphone;//��Ա�绰���� 
	int vipnumber;//��Ա�˺� 
	char bulidingcharacter;//¥�� 
	int unitnumber;//��Ԫ�� 
	int floornumber;//���� 
	int roomnumber;//���� 
};
typedef struct vip VIP;//�����Ա��Ϣ�Ľṹ������ 
VIP older;// VIP�����Ϊ���ݵ����� 

struct bus{
int number;//�೵��� 
int fee;//�˳����� 
int timecome[2];//ȥ�����೵ʱ�� 
int timego[2];//�������೵ʱ�� 
};
typedef struct bus BUS;//����೵��Ϣ�Ľṹ������ 

struct serviceLink{//��Ա�����ݣ��û����೵����ʩ����ס����ҹ�������һ�������䴢�棨�ؼ��� 
	VIP member;//�����Ա��Ϣ������������Ϣ�� 
	int enjoyment;//����������ʩԤԼ��Ϣ  
	int staysituation;//������ס״̬
	int usercontact;//������ְ����ϵ��״̬ 
	int busstate;//�����ύ;�����᰸��״̬ 
	struct serviceLink *nextPtr;//�����ýṹ�壨���� 
}; 
typedef struct serviceLink ServiceLink;
typedef ServiceLink *ServiceLinkPtr;
ServiceLinkPtr startPtr=NULL;//��ʼ������ͷ���

 struct user{
	char username[20];//ְ������ 
	int usernumber;//ְ����
	int userphone;//ְ���绰���� 
	int account[10];//ÿ��ְ������ʮ����Ա 
};
typedef struct user USER;//����ְ����Ϣ�Ľṹ������

struct userlink{
	USER information;//����ְ����Ϣ 
	int busstate;//�����ύ;�����᰸��״̬ 
	struct userlink *nextPtr;
};
typedef struct userlink UserLink;//����ְ������Ľṹ������
typedef UserLink *UserLinkPtr; 
USER worker;
UserLinkPtr startuserPtr=NULL;//����һ������ְ����Ϣ������ 

//��ΪԤԼ�������ڶ��У�������ǰȡ���뿪��������������������¼�Ŷ���� 
struct link{//��¼�Ŷ��� 
	int account;
struct link *nextPtr;
};
typedef struct link Link;//�����Ŷӵ�������Ӧ�����Ŷӵĳ���  
typedef Link *LinkPtr;
//��ʼ��ͷβ�ڵ� 
 LinkPtr headPtr[14]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
  
struct buswayslink{//�����೵;���ص�������;���ص���Ϣ 
	char placename[20];//;�������� 
	int employeenumber;//ְ���˺� 
	struct buswayslink *nextPtr;//ָ����һ�ڵ� 
};
typedef struct buswayslink BusLink;
typedef BusLink *BusLinkPtr;
BusLinkPtr startbusPtr[10]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

BUS shuttle[10]; //���ʮ������
int shuttlenum=0;//��¼�೵�������� 
int recreation;//���ֻ 
int vipn=1;//������� 
int usern=1;//������� 
int x,y,z;//��Ԫ�������������� 
unsigned int systemch;//ϵͳѡ�� 
int pingpong=0,badminton=0,yoga=0,chess=0,tableball=0,tea=0,newspaper=0,book=0;
int opera=0,shuttlecock=0,dance=0,handwriting=0,weave=0,chat=0;//�����᰸����
int enjoy[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};//��¼������ʩ״̬
int enjoynum[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};//��¼������ʩ����״̬ 

//�������� 
void readfile();//��ȡ�ļ��е�����
void writefile();//д���ļ����� 
void permission();//�����Ա��ְ��������ԱȨ�� 
void management(char *house);//ѡ�����ϵͳ 
void instructions();//�����������������Ļ������ �����ص�Ԫ���㣬�� �Ĳ��� 
void map(char *house);//ͨ����ӡ��ͼֱ��չʾ���� 
void inithouse(char *house);//��ʼ����������  
void vipmanage(char *house);//��Ա���� 
void housemanage(char *house);//���ݹ��� 
void staymanage(char *house);//��ס���� 
void publicmanage(char *house);//������ʩ���� 
void usermanage(char *house);//�û����� 
void routinemanage(char *house);//�೵·�߹��� 
void vipbuilt(ServiceLinkPtr *sptr,char *house);//�½���Ա
void vipinquiry(ServiceLinkPtr sptr,char *house);//��ѯ��Ա
void vipchange(ServiceLinkPtr *sptr,char *house);//�޸Ļ�Ա
void changevipuserlink(UserLinkPtr *sptr,int useraccount,int vipaccount);//��ɾ����Ա��ͬʱɾ����Ӧְ�������з�����Ա��Ϣ 
void vipdelete(ServiceLinkPtr *sptr,char *house);//ɾ����Ա
void printlist(ServiceLinkPtr sptr);//��ӡ��Ա�б� 
int empty(ServiceLinkPtr sptr);//�жϻ�Ա�б��Ƿ�Ϊ�� 
void housebuy(ServiceLinkPtr sptr,char *house);//��ѯ���ݹ���״��
void housestay(ServiceLinkPtr sptr,char *house);//��ѯ������ס״��
void houseowner(ServiceLinkPtr sptr,char *house);//�鿴������������Ϣ
void hire(ServiceLinkPtr sptr,char *house);//��ѯ����ķ����б�
void vacant(ServiceLinkPtr sptr,char *house);//��ѯ���õķ����б�
void onsale(ServiceLinkPtr sptr,char *house);//�鿴δ�۵ķ����б�
void application(ServiceLinkPtr *sptr);//����������ʩ���� 
void new_built();//�½������б� 
void scheme();//�Ͻ��᰸ 
void end(ServiceLinkPtr *sptr);//�������ַ��� 
int isempty(LinkPtr headPtr);//�������Ƿ�Ϊ��
void enlink(LinkPtr *sptr,int num);//�����Ŷ�����Ԫ�� 
void printlinelink(LinkPtr sptr);//��ӡ�Ŷ����� 
int delink(LinkPtr *sptr,int deletenumber);//ɾ��ԤԼ��Ա 
void creatuser(UserLinkPtr *sptr);//�½�������Ա���� 
void chooseuser(ServiceLinkPtr *sptr,UserLinkPtr *usersptr);//ѡ�������� 
void visituser(UserLinkPtr *sptr);//�鿴�������
void printuser(UserLinkPtr sptr);//�鿴������Ա�б�
void changecontact(ServiceLinkPtr *sptr,int account);//�޸��û��ͳ�Ա��ϵ���� 
void deleteuser(UserLinkPtr *startuserPtr);//ɾ��������Ա	
int userempty(UserLinkPtr sptr) ;//����Ƿ�Ϊ��  
void creatbus();//�½��೵���η��� 
void deletebus();//ɾ���೵����
void deletebuslink(BusLinkPtr *sptr,ServiceLinkPtr *vipsptr,UserLinkPtr *usersptr);//ɾ������;�������� 
void buslist();//�鿴�೵�����б�
void addplace(BusLinkPtr *sptr,char place[20],int number);//����;���� 
void ways(UserLinkPtr *usersptr,ServiceLinkPtr *sptr);//��Ӱ೵;���� 
void changebus();//�޸İ೵����	
void readlinkvip(ServiceLinkPtr *sptr);//��ȡ��Ա����
void readlinkuser(UserLinkPtr *sptr);//��ȡ�û�����
void readlinklink();//��ȡ��������
void readlinkbus();//��ȡ��������
void writehousefile(char *house);//д�뷿������
void readhousefile(char *house);//��ȡ�������� 
int  CN(char character);//��ĸת�����
char  NC(int num);//���ת����ĸ 
void file();//���ļ�������ز��� 

void  gotoxy( int  x,  int  y) //gotoxy Դ������,���ڴ�ӡ��ͼ�Ȳ��� 
{
COORD pos;
pos.X = x ;
pos.Y = y ;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

FILE *data;//ͨ���ı��ļ��������� 
FILE *datalink1;//�����Ա���� 
FILE *datalink2;//�����û����� 
FILE *datalink3;//����������� 
FILE *datalink4;//���湫������ 
FILE *datahouse;//���淿������ 

int main(){//������
    file(); //���� 
    readfile();//��ȡ 
    FIRSTJUDGE//�ж��Ƿ��״� ,�״���Ҫ���������������� 
    permission();//Ȩ�� 
    char house[6][y][x][z];//����
    inithouse((char *)house);//��ʼ����������
	readhousefile((char *)house);//��ȡ�������� 
    map((char *)house);//��ͼ 
    management((char *)house);//�˵� 
    writefile();//д�� 
    writehousefile((char *)house);//д�뷿������ 
	return 0;
} 

void file(){	 
data=fopen("data.txt","a");//���û���򴴽�һ��txt�ļ� 
fclose(data);
datalink1=fopen("datalinkvip.txt","a");//���û���򴴽�һ��txt�ļ� 
fclose(datalink1);
datalink2=fopen("datalinkuser.txt","a");//���û���򴴽�һ��txt�ļ� 
fclose(datalink2);
datalink3=fopen("datalinkqueue.txt","a");//���û���򴴽�һ��txt�ļ� 
fclose(datalink3);
datalink4=fopen("datalinkbus.txt","a");//���û���򴴽�һ��txt�ļ� 
fclose(datalink4);
datahouse=fopen("datahouse.txt","a");//���û���򴴽�һ��txt�ļ� 
fclose(datahouse);
} 

void writehousefile(char *house){//д�뷿������
datahouse=fopen("datahouse.txt","w");
int i,j,m,n;
	for(i=0;i<BUILDING;i++){//����д�� 
		for(j=0;j<FLOOR;j++){
			for(m=0;m<UNIT;m++){
				for(n=0;n<ROOM;n++){
				fprintf(datahouse,"%c,",*(house+FLOOR*UNIT*ROOM*i+UNIT*ROOM*j+ROOM*m+n));//д�������Ϣ 
				}
			}
		}
	} 
fclose(datahouse);
}

void readhousefile(char *house){//��ȡ�������� 
datahouse=fopen("datahouse.txt","r");
int i,j,m,n;
	for(i=0;i<BUILDING;i++){//������ֵ 
		for(j=0;j<FLOOR;j++){
			for(m=0;m<UNIT;m++){
				for(n=0;n<ROOM;n++){
				fscanf(datahouse,"%c,",&(*(house+FLOOR*UNIT*ROOM*i+UNIT*ROOM*j+ROOM*m+n)));//��ȡ������Ϣ 
				}
			}
		}
	} 
fclose(datahouse);
}

void readlinkvip(ServiceLinkPtr *sptr){//��ȡ��Ա����
int t;
if((datalink1=fopen("datalinkvip.txt","r"))==NULL)/*���ļ�*/
{ printf("�ļ��򲻿�!\n");
exit(1);
}
while(fscanf(datalink1,"%d",&t)!=EOF){ //�����½�β����ѭ�� 
ServiceLinkPtr newPtr=(ServiceLinkPtr)malloc(sizeof(ServiceLink));
newPtr->member.vipnumber=t;
fscanf(datalink1,"%s",newPtr->member.vipname);
fscanf(datalink1,"%s",newPtr->member.vipdocument);
fscanf(datalink1,"%d,%c,%d,%d,%d,%d,%d,%d,%d,",&newPtr->member.vipphone,&newPtr->member.bulidingcharacter,
&newPtr->member.unitnumber,&newPtr->member.floornumber,&newPtr->member.roomnumber,&newPtr->busstate,&newPtr->enjoyment,&newPtr->staysituation,&newPtr->usercontact);
ServiceLinkPtr previousPtr=NULL;
ServiceLinkPtr currentPtr=*sptr;
	while (currentPtr!=NULL){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;//��һ���ڵ� 
	}
	if(previousPtr==NULL){//Ϊ�׽ڵ� 
		newPtr->nextPtr=*sptr;
		*sptr=newPtr;
	}
	else {//����һ�ڵ� 
		previousPtr->nextPtr=newPtr;
		newPtr->nextPtr=currentPtr;
	}} 
fclose(datalink1);
}

void readlinkuser(UserLinkPtr *sptr){//��ȡ�û�����
 int t,i;
if((datalink2=fopen("datalinkuser.txt","r"))==NULL)/*���ļ�*/
{ printf("�ļ��򲻿�!\n");
exit(1);
}
while(fscanf(datalink2,"%d",&t)!=EOF){//�����½�β����ѭ�� 
UserLinkPtr newPtr=(UserLinkPtr)malloc(sizeof(UserLink)); 
newPtr->busstate=t;
fscanf(datalink2,"%s",newPtr->information.username);
fscanf(datalink2,"%d,%d,",&newPtr->information.usernumber,&newPtr->information.userphone);
		for(i=0;i<10;i++){
			fscanf(datalink2,"%d,",&newPtr->information.account[i]);
		}
	UserLinkPtr previousPtr=NULL;
	UserLinkPtr currentPtr=*sptr;
	while (currentPtr!=NULL){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;//��һ���ڵ� 
	}
	if(previousPtr==NULL){
		newPtr->nextPtr=*sptr;//˵��Ϊͷ��� 
		*sptr=newPtr;
	}
	else {
		previousPtr->nextPtr=newPtr;
		newPtr->nextPtr=currentPtr;
	}}
fclose(datalink2);
}

void readlinklink(){//��ȡ��������
 int t,i;
if((datalink3=fopen("datalinkqueue.txt","r"))==NULL)/*���ļ�*/
{ printf("�ļ��򲻿�!\n");
exit(1);
}
for(i=0;i<14;i++){
while((fscanf(datalink3,"%d,",&t),t)!=1&&!feof(datalink3)){//�м���t����������ѭ���������� 
LinkPtr newPtr=(LinkPtr)malloc(sizeof(Link)); //feof��������һ��fscanf���棬�����fscanfһ���������� 
newPtr->account=t;
LinkPtr previousPtr=NULL;
LinkPtr currentPtr=headPtr[i];
while (currentPtr!=NULL){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;//��һ���ڵ� 
}
if(previousPtr==NULL){
		newPtr->nextPtr=headPtr[i];//˵��Ϊͷ��� 
		headPtr[i]=newPtr;
}
else {
		previousPtr->nextPtr=newPtr;
		newPtr->nextPtr=currentPtr;
}}}
fclose(datalink3);
}

void readlinkbus(){//��ȡ��������
 int t,i;
if((datalink4=fopen("datalinkbus.txt","r"))==NULL)/*���ļ�*/
{ printf("�ļ��򲻿�!\n");
exit(1);
}
for(i=0;i<10;i++){
while((fscanf(datalink4,"%d",&t),t)!=1&&!feof(datalink4)){//�м���t����������ѭ���������� 
BusLinkPtr newPtr=(BusLinkPtr)malloc(sizeof(BusLink)); //feof��������һ��fscanf���棬�����fscanfһ���������� 
newPtr->employeenumber=t;
fscanf(datalink4,"%s",newPtr->placename);
BusLinkPtr previousPtr=NULL;
BusLinkPtr currentPtr=startbusPtr[i];
while (currentPtr!=NULL){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;//��һ���ڵ� 
}
if(previousPtr==NULL){
		newPtr->nextPtr=startbusPtr[i];//˵��Ϊͷ��� 
		startbusPtr[i]=newPtr;
}
else {
		previousPtr->nextPtr=newPtr;
		newPtr->nextPtr=currentPtr;
}}}
fclose(datalink4);
}

void readfile(){//��ȡ�ļ��е�����
int i;
//data
data=fopen("data.txt","r");//��data�ļ�����ȡ����������Ϣ 
fscanf(data,"%d,%d,%d,%d,%d,%d,%d\n",&shuttlenum,&recreation,&vipn,&usern,&x,&y,&z);
fscanf(data,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",&pingpong,&badminton,&yoga,&chess,&tableball,&tea,&newspaper,&book,
&opera,&shuttlecock,&dance,&handwriting,&weave,&chat);
fscanf(data,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",&enjoy[0],&enjoy[1],&enjoy[2],&enjoy[3],&enjoy[4],&enjoy[5],&enjoy[6],
&enjoy[7],&enjoy[8],&enjoy[9],&enjoy[10],&enjoy[11],&enjoy[12],&enjoy[13]);
fscanf(data,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",&enjoynum[0],&enjoynum[1],&enjoynum[2],&enjoynum[3],&enjoynum[4],&enjoynum[5],&enjoynum[6],
&enjoynum[7],&enjoynum[8],&enjoynum[9],&enjoynum[10],&enjoynum[11],&enjoynum[12],&enjoynum[13]);
for(i=0;i<10;i++){
fscanf(data,"%d,%d,%d,%d,%d,%d\n",&shuttle[i].fee,&shuttle[i].number,&shuttle[i].timecome[0],&shuttle[i].timecome[1],&shuttle[i].timego[0],&shuttle[i].timego[1]);
}
fclose(data);

//��Ա���� 
readlinkvip(&startPtr); 

//�û����� 
readlinkuser(&startuserPtr); 

//�������� 
readlinklink();

//�������� 
readlinkbus();
}
 
 //�ö��ţ����з���t����������������� 
void writefile(){//д���ļ�����
int i; 
int t=1;
//data
data=fopen("data.txt","w");//д���������Ϣ 
fprintf(data,"%d,%d,%d,%d,%d,%d,%d\n",shuttlenum,recreation,vipn,usern,x,y,z);
fprintf(data,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",pingpong,badminton,yoga,chess,tableball,tea,newspaper,book,
opera,shuttlecock,dance,handwriting,weave,chat);
fprintf(data,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",enjoy[0],enjoy[1],enjoy[2],enjoy[3],enjoy[4],enjoy[5],enjoy[6],
enjoy[7],enjoy[8],enjoy[9],enjoy[10],enjoy[11],enjoy[12],enjoy[13]);
fprintf(data,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",enjoynum[0],enjoynum[1],enjoynum[2],enjoynum[3],enjoynum[4],enjoynum[5],enjoynum[6],
enjoynum[7],enjoynum[8],enjoynum[9],enjoynum[10],enjoynum[11],enjoynum[12],enjoynum[13]);
for(i=0;i<10;i++){
fprintf(data,"%d,%d,%d,%d,%d,%d\n",shuttle[i].fee,shuttle[i].number,shuttle[i].timecome[0],shuttle[i].timecome[1],shuttle[i].timego[0],shuttle[i].timego[1]);
}
fclose(data);
//link1
datalink1=fopen("datalinkvip.txt","w");//д���Ա������Ϣ 
	if(empty(startPtr)){}
	else {
	ServiceLinkPtr sptr=startPtr;
		while (sptr!=NULL){//ѭ����ӡ�ڵ� 
		fprintf(datalink1,"%d\n%s\n%s\n%d,%c,%d,%d,%d,%d,%d,%d,%d,\n",sptr->member.vipnumber,sptr->member.vipname,sptr->member.vipdocument,sptr->member.vipphone,sptr->member.bulidingcharacter,
		sptr->member.unitnumber,sptr->member.floornumber,sptr->member.roomnumber,sptr->busstate,sptr->enjoyment,sptr->staysituation,sptr->usercontact);
sptr=sptr->nextPtr;}}
fclose(datalink1);

//link2
datalink2=fopen("datalinkuser.txt","w");//д���û�������Ϣ 
	if(userempty(startuserPtr)){}
	else {
		UserLinkPtr usersptr=startuserPtr;
		while (usersptr!=NULL){//ѭ����ӡ�ڵ� 
		fprintf(datalink2,"%d\n%s\n%d,%d,",usersptr->busstate,usersptr->information.username,usersptr->information.usernumber,usersptr->information.userphone);
		for(i=0;i<10;i++){
			fprintf(datalink2,"%d,",usersptr->information.account[i]);
		}fprintf(datalink2,"\n");
		usersptr=usersptr->nextPtr;
		}}
	fclose(datalink2);
	
//link3
		datalink3=fopen("datalinkqueue.txt","w");//д���Ŷ�������Ϣ 
		LinkPtr linksptr;
		for(i=0;i<14;i++){
		LinkPtr linksptr=headPtr[i];
		if(linksptr==NULL){}
        else {
	    while (linksptr!=NULL){
		fprintf(datalink3,"%d,",linksptr->account);
		linksptr=linksptr->nextPtr;
	    }}fprintf(datalink3,"%d,",t);}
	    fclose(datalink3);
		
//link4		
		datalink4=fopen("datalinkbus.txt","w");//д�빫��������Ϣ 
        BusLinkPtr bussptr;
		for(i=0;i<10;i++){
        if(startbusPtr[i]==NULL){}
        else{
        	bussptr=startbusPtr[i];
		while (bussptr!=NULL){//ѭ����ӡ�ڵ� 
		fprintf(datalink4,"%d\n%s\n",bussptr->employeenumber,bussptr->placename);
		bussptr=bussptr->nextPtr;
		}}fprintf(datalink4,"%d\n",t);}
		fclose(datalink4);
} 

void permission(){//�����Ա��ְ��������ԱȨ�� 
		int choicepower=0;//Ȩ��ѡ�� 
int password;//�������� 
system("color 0E");
while(power!=1&&power!=2&&power!=3){
	system("cls");
	printf("********************************************************************\n");
	printf("***              ---------������������ϵͳ---------              ***\n");
	printf("********************************************************************\n"); 
		printf("**********������������Ȩ��ϵͳ**********\n");
	    printf("****        ---��ѡ��Ȩ��---        ****\n");
	    printf("***1.��ԱȨ�� 2.ְ��Ȩ�� 3.����ԱȨ��***\n");
	    printf("****************************************\n");
	scanf("%d",&choicepower);
	fflush(stdin);
while(choicepower<1||choicepower>3){//��֧Ȩ�� 
	printf("***��ѡ��Ȩ��\n***1.��ԱȨ�� 2.ְ��Ȩ�� 3.����ԱȨ��\n");
	scanf("%d",&choicepower);//ѭ������
	fflush(stdin);
}
if(choicepower==1){ 
printf("***�������ԱȨ�����룺\n");
scanf("%d",&password);
fflush(stdin);
if(password!=123){
	printf("***�����������������ѡ��\n");
	system("pause>nul");
	power=0;
}else power=1;
} 
else if(choicepower==2){ 
printf("***������ְ��Ȩ�����룺\n");
scanf("%d",&password);
fflush(stdin);
if(password!=456){
	power=0;
	printf("***�����������������ѡ��\n");
	system("pause>nul");
}else power=2;
} 
else if(choicepower==3){ 
printf("***���������ԱȨ�����룺\n");
scanf("%d",&password);
fflush(stdin);
if(password!=789){
	power=0;
	printf("***�����������������ѡ��\n");
	system("pause>nul");
}else power=3;
}} 
if(power==1)
printf("***�����ԱȨ��\n");
else if(power==2)
printf("***����ְ��Ȩ��\n");
else if(power==3)
printf("***�������ԱȨ��\n");
} 

int CN(char character){//��ĸת�����
int num; 
 if(character=='A')num=0; 
 else if(character=='B')num=1; 
 else if(character=='C')num=2; 
 else if(character=='D')num=3; 
 else if(character=='E')num=4; 
 else if(character=='F')num=5;
 return num;
 }

char  NC(int num){//���ת����ĸ 
char character;
if(num==0) character='A';
else if(num==1) character='B';
else if(num==2) character='C';
else if(num==3) character='D';
else if(num==4) character='E';
else if(num==5) character='F';
return character;
} 
void inithouse(char *house)//��ʼ���������� 
{
int i,j,m,n;
	for(i=0;i<BUILDING;i++){//������ֵ 
		for(j=0;j<FLOOR;j++){
			for(m=0;m<UNIT;m++){
				for(n=0;n<ROOM;n++){
					*(house+FLOOR*UNIT*ROOM*i+UNIT*ROOM*j+ROOM*m+n)='+';//���񷿳�ʼ�� 
				}
			}
		}
	} 
	system("pause>nul");
}  
 
void map(char *house)//��ӡ������ͼ 
{	
	system("cls");
		system("color 0C");
	int i1,i2,j,m,n;
	printf("\n*�������������ͼ��ʾ(\"+\"��ʾ�շ�,\"@\"��ʾ��ס����\"#\"��ʾ��Ӧ�õ�����������\n");
	printf("\n");
	if(ROOM==2&&UNIT==4)
	printf("      A¥\t\t\t      F¥\n"); //��ӡ¥�� 
	else if(ROOM==3&&UNIT==4)
	printf("      A¥\t\t\t      \t\tF¥\n"); //��ӡ¥�� 
	else if(ROOM==2&&UNIT==5)
	printf("      A¥\t\t\t      \tF¥\n"); //��ӡ¥��
	else if(ROOM==3&&UNIT==5) 
	printf("      A¥\t\t\t      \t  \tF¥\n"); //��ӡ¥�� 
		for(i1=0,i2=BUILDING-1;i1<BUILDING/2;i1++,i2--){//������ӡ��ͬ״̬�ķ��� 
		for(j=0;j<FLOOR;j++){		
			for(m=0;m<UNIT;m++){		
			for(n=0;n<ROOM;n++){		
					printf("%c ",*(house+FLOOR*UNIT*ROOM*i1+UNIT*ROOM*j+ROOM*m+n));//��ӡ���� 
				}} 
				printf("\t\t");//���� 
			for(m=0;m<UNIT;m++){	
			for(n=0;n<ROOM;n++){		
					printf("%c ",*(house+FLOOR*UNIT*ROOM*i2+UNIT*ROOM*j+ROOM*m+n));//��ӡ���� 
				}}
	printf("\n");
		}
	printf("\n");
	if(i1==0){
	 	if(ROOM==2&&UNIT==4)
	printf("      B¥\t\t\t      E¥\n"); //��ӡ¥�� 
	else if(ROOM==3&&UNIT==4)
	printf("      B¥\t\t\t      \t\tE¥\n"); //��ӡ¥�� 
	else if(ROOM==2&&UNIT==5)
	printf("      B¥\t\t\t      \tE¥\n"); //��ӡ¥��
	else if(ROOM==3&&UNIT==5) 
	printf("      B¥\t\t\t      \t  \tE¥\n"); //��ӡ¥�� 
}
	else if(i1==1) {
		if(ROOM==2&&UNIT==4)
	printf("      C¥\t\t\t      D¥\n"); //��ӡ¥�� 
	else if(ROOM==3&&UNIT==4)
	printf("      C¥\t\t\t      \t\tD¥\n"); //��ӡ¥�� 
	else if(ROOM==2&&UNIT==5)
	printf("      C¥\t\t\t      \tD¥\n"); //��ӡ¥��
	else if(ROOM==3&&UNIT==5) 
	printf("      C¥\t\t\t      \t  \tD¥\n"); //��ӡ¥�� 
	}
	else printf("\n");
	}
		system("pause>nul");
} 

void instructions()//�ṩ�������� 
{
	unsigned int choice;
	system("cls");
	system("color 0A");
	printf("************************************************************************\n");
	printf("*****              ---------������������ϵͳ---------              *****\n");
	printf("************************************************************************\n");
	printf("***************�������������������棬˵�������״ε�¼��***************\n");
	printf("*****����ѡ�������Ļ������跽���Թ�������ͼ�Ĺ����ͻ������ܵ�ʵ�֣�*****\n");
	printf("************************************************************************\n");
	printf("��ϵͳ��Ϊ��Ա�������ݹ�����ס����������ʩ�����û������೵����\n"); 
	printf("����������ϵͳ�����л�Ա����Ϊ����ϵͳ��ϵͳ���ܵ�ʵ�ִ�����Աϵͳ���\n");
	printf("************************************************************************\n");
	printf("****��Ա������Խ����½���Ա���޸Ļ�Ա��Ϣ���鿴��Ա�б��һϵ�в���****\n"); 
	printf("****���ݹ�����Խ��в�ѯ����״̬�Ȳ�����Ȩ�޲�ͬ���ܲ鿴����Ϣ�Ͳ�ͬ****\n"); 
	printf("*****��ס������Բ�ѯ��ס״̬�Ȳ�����ͬ��Ҳ����ͬȨ�޳��ֲ�ͬ��Ϣ*****\n"); 
	printf("****������ʩ����ɽ����½���ʩ���Ŷӹ���Ȳ��������Ա��Ϣ�н�����ϵ****\n"); 
	printf("****�û����������ְ���Ĺ���ϵͳ���ɽ����½�ְ��������������Ȳ���****\n"); 
	printf("***�೵����ɴ����೵���Σ��������û���Ա����Ҫ����;�������ƹ�������***\n");
	printf("************************************************************************\n");
	printf("*��ѡ����������Ԥ����A,B,C,D,E,FΪ��������¥\n*���Զ��嵥Ԫ����¥������ÿ�㻧������������������Ҫ����ѡ��\n");
	printf("*��ѡ�����½��跽����\n");
    printf("*****1.6*4*4*2��\n*****2.6*4*4*3��\n*****3.6*4*5*2��\n*****4.6*4*5*3��\n") ;
    printf("*****5.6*5*4*2��\n*****6.6*5*4*3��\n*****7.6*5*5*2��\n*****8.6*5*5*3��\n") ;
    scanf("%d",&choice);
    fflush(stdin);
    while(choice<1||choice>8){
    	printf("***�����������������\n");
scanf("%d",&choice);
fflush(stdin);
	}
	switch(choice){
		case 1:
			x=4;y=4;z=2;
			break;
		case 2:
			x=4;y=4;z=3;
			break;
		case 3:
			x=4;y=5;z=2;
			break;
		case 4:
			x=4;y=5;z=3;
			break;
		case 5:
			x=5;y=4;z=2;
			break;
		case 6:
			x=5;y=4;z=3;
			break;
		case 7:
			x=5;y=5;z=2;
			break;
		case 8:
			x=5;y=5;z=3;
			break;
	}
	printf("***��ѡ����%d��Ԫ%d��%d������\n",x,y,z);
		printf("    **********�������������������**********\n");
		printf("*A,B,C,D,E,F����Ϊ����¥��ÿ��¥��%d����Ԫ��%d��¥��ÿ����%d���˼ң���%d��ס��\n",x,y,z,6*x*y*z);
			system("pause>nul");
} 

void management(char *house)//ѡ�����ϵͳ 
{
	int i=0;
	system("cls");
	int choice=10;
	system("color 0B");
	printf("    **********������������ϵͳ**********\n");
	printf("    ***********��ѡ�����ϵͳ***********\n");
	if(power==1){ 
	printf("    1.��Ա���� 2.���ݹ��� 3.��ס���� 4.������ʩ�Ŷӹ��� 5.�೵·�߹���\n    6.�������� 0.�鿴��ͼ -1.��������\n");
	while(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5&&choice!=6&&choice!=0&&choice!=-1) 
	{
		gotoxy(0,4+i);
	printf("***��ѡ�����ϵͳ���������֣�:\n"); 
	gotoxy(31,4+i);
	scanf("%d",&choice);
	fflush(stdin);//��ֹ��� 
	i++;
	}
	systemch=choice;//ѡ�� 
	if(systemch==1)vipmanage((char *)house); //��Ա���� 
	else if(systemch==2)housemanage((char *)house); //���ݹ��� 
	else if(systemch==3)staymanage((char *)house); //��ס���� 
	else if(systemch==4)publicmanage((char *)house); //������ʩ�Ŷӹ��� 
	else if(systemch==6){writefile();//����  
	writehousefile((char *)house);}//д�뷿������ 
	else if(systemch==5)routinemanage((char *)house); //�೵·�߹��� 
	} 
	else{ 
	printf("    1.��Ա���� 2.���ݹ��� 3.��ס���� 4.������ʩ�Ŷӹ��� 5.�೵·�߹��� 6.�û�����\n    7.�������� 0.�鿴��ͼ -1.��������\n");
	while(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5&&choice!=6&&choice!=0&&choice!=-1&&choice!=7) 
	{
		gotoxy(0,4+i);
	printf("***��ѡ�����ϵͳ���������֣�:\n"); 
	gotoxy(31,4+i);
	scanf("%d",&choice);
	fflush(stdin);//��ֹ��� 
	i++;
	}
	systemch=choice;//ѡ�� 
	if(systemch==1)vipmanage((char *)house); //��Ա���� 
	else if(systemch==2)housemanage((char *)house); //���ݹ��� 
	else if(systemch==3)staymanage((char *)house); //��ס���� 
	else if(systemch==4)publicmanage((char *)house); //������ʩ�Ŷӹ��� 
	else if(systemch==6)usermanage((char *)house); //�û����� 
	else if(systemch==5)routinemanage((char *)house); //�೵·�߹��� 
	else if(systemch==7){writefile();//���� 
	 writehousefile((char *)house);}//д�뷿������ 
} 
	 if(systemch==0)map((char *)house);//�鿴��ͼ 
	else if(systemch==-1){//���� 
	writefile();
	 writehousefile((char *)house);//д�뷿������ 
	exit(0);
}
	management((char *)house);
	system("pause>nul");
}

void vipbuilt(ServiceLinkPtr *sptr,char *house)//�½���Ա
{
		system("cls");
	system("color 0F");
	int i=0; 
	char ch;
	int cn=10;//��¥��ת��Ϊ�����е���� 
	older.vipnumber=20210000+vipn;
	vipn++;
	printf("**�������»�Ա�Ļ�����Ϣ\n") ;
	printf("**1.������Ӣ�ģ�\n");
    scanf("%s",older.vipname) ;
    fflush(stdin);
    printf("**2.���֤��\n");
    scanf("%s", older.vipdocument);
    fflush(stdin);
    printf("**3.�绰����\n");
    scanf("%d",&older.vipphone);
    fflush(stdin);
    LOOP:
    do{
		 printf("**4.ѡ����(��ʽ��A 1 1 1 ΪA¥1��Ԫ1��1��)\n");
	scanf("%c %d %d %d",&older.bulidingcharacter,&older.unitnumber,&older.floornumber,&older.roomnumber);
	fflush(stdin);
}
    while(older.bulidingcharacter<'A'||older.bulidingcharacter>'F'||
	older.unitnumber<1||older.unitnumber>UNIT||
	older.floornumber<1||older.floornumber>FLOOR||
	older.roomnumber<1||older.roomnumber>ROOM);//��ֹ������� 
cn=CN(older.bulidingcharacter);
if(*(house+FLOOR*UNIT*ROOM*cn+UNIT*ROOM*(older.unitnumber-1)+ROOM*(older.floornumber-1)+older.roomnumber-1)=='@')
{
	printf("**�÷�����������������ѡ��\n");
	goto LOOP;
}
else *(house+FLOOR*UNIT*ROOM*cn+UNIT*ROOM*(older.unitnumber-1)+ROOM*(older.floornumber-1)+older.roomnumber-1)='@';
unsigned int situation=0;
while(situation!=1&&situation!=2&&situation!=3){
printf("**5.ѡ����״̬ 1.��ס 2.���� 3.����\n");
scanf("%d",&situation); 
fflush(stdin);
}
printf("\n**�����ݳɹ�����鿴��Ա��Ϣ\n");//��ӡ��Ա��Ϣ 
printf("***��Ա�ţ�%d\n***��Ա������%s\n***��Ա���֤�ţ�%s\n***��Ա�绰��%d\n***��Ա���ݣ�%c¥%d��Ԫ%d��%d��\n"
,older.vipnumber,older.vipname,older.vipdocument,older.vipphone,older.bulidingcharacter,older.unitnumber,older.floornumber,older.roomnumber);
if(situation==1)
printf("***��ס״̬������ס\n"); 
else if(situation==2)
printf("***��ס״̬���ѳ���\n");
else if(situation==3)
printf("***��ס״̬������\n");
printf("***��δ�Ըû�Ա���������Ա\n"); 
ServiceLinkPtr newPtr=(ServiceLinkPtr)malloc(sizeof(ServiceLink));
if(newPtr!=NULL){//�ж��Ƿ��пռ� 
	newPtr->member=older;//��ֵ�����ڵ�
	newPtr->usercontact=0;
	newPtr->staysituation=situation; 
	newPtr->enjoyment=0;//��ԤԼ״̬ 
	newPtr->busstate=0;//��ʼ������״̬ 
	newPtr->nextPtr;//�ýڵ㲻ָ���κνڵ� 
	ServiceLinkPtr previousPtr=NULL;
	ServiceLinkPtr currentPtr=*sptr;
	while (currentPtr!=NULL&&older.vipnumber>currentPtr->member.vipnumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;//��һ���ڵ� 
	}
	if(previousPtr==NULL){
		newPtr->nextPtr=*sptr;
		*sptr=newPtr;
	}
	else {
		previousPtr->nextPtr=newPtr;
		newPtr->nextPtr=currentPtr;
	}
} 
else {
	printf("**�ڴ���������Ա�˺�%dδ�ܴ����ɹ�",older.vipnumber); 
}
system("pause>nul");
}

void vipinquiry(ServiceLinkPtr sptr,char *house)//��ѯ��Ա
{ 
	system("cls");
	system("color 0F");	
	int cn;
	if(!empty(sptr)){
	int inquirynumber;
	int result=0; 
	printf("***�������ѯ��Ա�Ļ�Ա�˺�\n");
	scanf("%d",&inquirynumber);
	fflush(stdin);
	if(inquirynumber==(sptr)->member.vipnumber){//�ڵ�һ���ڵ� 
		printf("***��ѯ�ɹ�\n");
printf("***��Ա�ţ�%d\n***��Ա������%s\n***��Ա���֤�ţ�%s\n***��Ա�绰��%d\n***��Ա���ݣ�%c¥%d��Ԫ%d��%d��\n"
,(sptr)->member.vipnumber,(sptr)->member.vipname,(sptr)->member.vipdocument,(sptr)->member.vipphone,
(sptr)->member.bulidingcharacter,(sptr)->member.unitnumber,(sptr)->member.floornumber,(sptr)->member.roomnumber);
if((sptr)->staysituation==1)
printf("***��ס״̬������ס\n"); 
else if((sptr)->staysituation==2)
printf("***��ס״̬���ѳ���\n");
else if((sptr)->staysituation==3)
printf("***��ס״̬������\n");
if((sptr)->usercontact==0)
printf("***��δ���������Ա\n");
else printf("***�ѷ��������Ա %d\n",(sptr)->usercontact);
		result=1;
	}
	else {
	ServiceLinkPtr previousPtr=(sptr);//δ�ڵ�һ���ڵ� 
	ServiceLinkPtr currentPtr=(sptr)->nextPtr;
	while(currentPtr!=NULL&&currentPtr->member.vipnumber!=inquirynumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	if(currentPtr!=NULL){//��ѯ�м�ڵ� 
	printf("***��ѯ�ɹ�\n");
	printf("***��Ա�ţ�%d\n***��Ա������%s\n***��Ա���֤�ţ�%s\n***��Ա�绰��%d\n***��Ա���ݣ�%c¥%d��Ԫ%d��%d��\n"
,currentPtr->member.vipnumber,currentPtr->member.vipname,currentPtr->member.vipdocument,currentPtr->member.vipphone,currentPtr->member.bulidingcharacter,
currentPtr->member.unitnumber,currentPtr->member.floornumber,currentPtr->member.roomnumber);
if(currentPtr->staysituation==1)
printf("***��ס״̬������ס\n"); 
else if(currentPtr->staysituation==2)
printf("***��ס״̬���ѳ���\n");
else if(currentPtr->staysituation==3)
printf("***��ס״̬������\n");
if(currentPtr->usercontact==0)
printf("***��δ���������Ա\n");
else printf("***�ѷ��������Ա %d\n",currentPtr->usercontact);
		result=1; 
	}
	}
	if(result==0) {
		printf("***δ�ҵ���Ա��Ϊ %d �Ļ�Ա\n",inquirynumber);
	}}
	else {
		printf("***��Ա�б�Ϊ��\n");
	}	
	system("pause>nul");
}

void vipchange(ServiceLinkPtr (*sptr),char *house)//�޸Ļ�Ա
{
	system("cls");
	system("color 0F");	
		int cn;
		unsigned int choice;
	if(!empty((*sptr))){
	int changenumber;
	int result=0; 
	printf("***�������޸Ļ�Ա�Ļ�Ա�˺�\n");
	scanf("%d",&changenumber);
	fflush(stdin);
	if(changenumber==(*sptr)->member.vipnumber){
		printf("***��ѡ���޸ĵ�����\n");
		while (choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5){
			printf("***1.���� 2.���֤�� 3.��ϵ�绰 4.��Ա���� 5.��ס״̬\n");
			scanf("%d",&choice);
			fflush(stdin);
		}
		if(choice==1){
			printf("***�������µĻ�Ա����\n") ;
			scanf("%s",(*sptr)->member.vipname);
			fflush(stdin);
		}
			else if(choice==2){
			printf("***�������µĻ�Ա���֤��\n") ;
			scanf("%s",(*sptr)->member.vipdocument);
			fflush(stdin);
		}
			else if(choice==3){
			printf("***�������µĻ�Ա��ϵ�绰\n") ;
			scanf("%d",&(*sptr)->member.vipphone);
			fflush(stdin);
		}
			else if(choice==4){
            VIPHOUSE//ִ��Ԥ�������� 
    LOOP:
    do{
		 printf("**3.ѡ����(��ʽ��A 1 1 1 ΪA¥1��Ԫ1��1��)\n");
	scanf("%c %d %d %d",&(*sptr)->member.bulidingcharacter,&(*sptr)->member.unitnumber,&(*sptr)->member.floornumber,&(*sptr)->member.roomnumber);
	fflush(stdin);
}
    while((*sptr)->member.bulidingcharacter<'A'||(*sptr)->member.bulidingcharacter>'F'||
	(*sptr)->member.unitnumber<1||(*sptr)->member.unitnumber>UNIT||
	(*sptr)->member.floornumber<1||(*sptr)->member.floornumber>FLOOR||
	(*sptr)->member.roomnumber<1||(*sptr)->member.roomnumber>ROOM);//��ֹ������� 
cn=CN((*sptr)->member.bulidingcharacter);
if(*(house+FLOOR*UNIT*ROOM*cn+UNIT*ROOM*((*sptr)->member.unitnumber-1)+ROOM*((*sptr)->member.floornumber-1)+(*sptr)->member.roomnumber-1)=='@')
{
	printf("**�÷�����������������ѡ��\n");
	goto LOOP;
}
else *(house+FLOOR*UNIT*ROOM*cn+UNIT*ROOM*((*sptr)->member.unitnumber-1)+ROOM*((*sptr)->member.floornumber-1)+(*sptr)->member.roomnumber-1)='@';
		}
			else if(choice==5){
			printf("***�������µ���ס״̬ 1.��ס 2.���� 3.����\n") ;
			scanf("%d",&(*sptr)->staysituation);
			fflush(stdin);
			}
		printf("***�޸ĳɹ�\n"); 
printf("***��Ա�ţ�%d\n***��Ա������%s\n***��Ա���֤�ţ�%s\n***��Ա�绰��%d\n***��Ա���ݣ�%c¥%d��Ԫ%d��%d��\n"
,(*sptr)->member.vipnumber,(*sptr)->member.vipname,(*sptr)->member.vipdocument,(*sptr)->member.vipphone,
(*sptr)->member.bulidingcharacter,(*sptr)->member.unitnumber,(*sptr)->member.floornumber,(*sptr)->member.roomnumber);
if((*sptr)->staysituation==1)//��ӡ��ס״̬ 
printf("***��ס״̬������ס\n"); 
else if((*sptr)->staysituation==2)
printf("***��ס״̬���ѳ���\n");
else if((*sptr)->staysituation==3)
printf("***��ס״̬������\n");
if((*sptr)->usercontact==0)
printf("***��δ���������Ա\n");
else printf("***�ѷ��������Ա %d\n",(*sptr)->usercontact);
		result=1;
	}
	else {//�ֿ�ͷ����������� 
	ServiceLinkPtr previousPtr=(*sptr);
	ServiceLinkPtr currentPtr=(*sptr)->nextPtr;
	while(currentPtr!=NULL&&currentPtr->member.vipnumber!=changenumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	if(currentPtr!=NULL){//�޸��м�ڵ� 
		printf("***��ѡ���޸ĵ�����\n");
		while (choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5){
			printf("***1.���� 2.���֤�� 3.��ϵ�绰 4.��Ա���� 5.��ס״̬\n");
			scanf("%d",&choice);
			fflush(stdin);
		}
		if(choice==1){
			printf("***�������µĻ�Ա����\n") ;
			scanf("%s",currentPtr->member.vipname);
			fflush(stdin);
		}
			else if(choice==2){
			printf("***�������µĻ�Ա���֤��\n") ;
			scanf("%s",currentPtr->member.vipdocument);
			fflush(stdin);
		}
			else if(choice==3){
			printf("***�������µĻ�Ա��ϵ�绰\n") ;
			scanf("%d",&currentPtr->member.vipphone);
			fflush(stdin);
		}
			else if(choice==4){
cn=CN(currentPtr->member.bulidingcharacter);
*(house+FLOOR*UNIT*ROOM*cn+UNIT*ROOM*(currentPtr->member.unitnumber-1)+ROOM*(currentPtr->member.floornumber-1)+currentPtr->member.roomnumber-1)='+'; 
    LOOP2:
    do{
		 printf("**3.ѡ����(��ʽ��A 1 1 1 ΪA¥1��Ԫ1��1��)\n");
	scanf("%c %d %d %d",&currentPtr->member.bulidingcharacter,&currentPtr->member.unitnumber,&currentPtr->member.floornumber,&currentPtr->member.roomnumber);
	fflush(stdin);
}
    while(currentPtr->member.bulidingcharacter<'A'||currentPtr->member.bulidingcharacter>'F'||
	currentPtr->member.unitnumber<1||currentPtr->member.unitnumber>UNIT||//��ֹ������������ֵ 
	currentPtr->member.floornumber<1||currentPtr->member.floornumber>FLOOR||
	currentPtr->member.roomnumber<1||currentPtr->member.roomnumber>ROOM);//��ֹ������� 
cn=CN(currentPtr->member.bulidingcharacter);
if(*(house+FLOOR*UNIT*ROOM*cn+UNIT*ROOM*(currentPtr->member.unitnumber-1)+ROOM*(currentPtr->member.floornumber-1)+currentPtr->member.roomnumber-1)=='@')
{
	printf("**�÷�����������������ѡ��\n");
	goto LOOP2;
}
else *(house+FLOOR*UNIT*ROOM*cn+UNIT*ROOM*(currentPtr->member.unitnumber-1)+ROOM*(currentPtr->member.floornumber-1)+currentPtr->member.roomnumber-1)='@';
		}
			else if(choice==5){
			printf("***�������µ���ס״̬ 1.��ס 2.���� 3.����\n") ;
			scanf("%d",&currentPtr->staysituation);
			fflush(stdin);
			}
		printf("***�޸ĳɹ�\n"); 
printf("***��Ա�ţ�%d\n***��Ա������%s\n***��Ա���֤�ţ�%s\n***��Ա�绰��%d\n***��Ա���ݣ�%c¥%d��Ԫ%d��%d��\n"
,currentPtr->member.vipnumber,currentPtr->member.vipname,currentPtr->member.vipdocument,currentPtr->member.vipphone,
currentPtr->member.bulidingcharacter,currentPtr->member.unitnumber,currentPtr->member.floornumber,currentPtr->member.roomnumber);
if(currentPtr->staysituation==1)
printf("***��ס״̬������ס\n"); 
else if(currentPtr->staysituation==2)
printf("***��ס״̬���ѳ���\n");
else if(currentPtr->staysituation==3)
printf("***��ס״̬������\n");
if(currentPtr->usercontact==0)
printf("***��δ���������Ա\n");
else printf("***�ѷ��������Ա %d\n",currentPtr->usercontact);
		result=1;
	}
	}
	if(result==0) {
		printf("***δ�ҵ���Ա��Ϊ %d �Ļ�Ա\n",changenumber);
	}}
	else {
		printf("***��Ա�б�Ϊ��\n");
	}
	system("pause>nul");
}

void changevipuserlink(UserLinkPtr *sptr,int useraccount,int vipaccount){//��ɾ����Ա��ͬʱɾ����Ӧְ�������з�����Ա��Ϣ 
int i;
	if(useraccount==(*sptr)->information.usernumber){
for(i=0;i<10;i++){//��10����Ա�˻���Ϣȫ����ʼ�� 
	if(vipaccount==(*sptr)->information.account[i]){
		(*sptr)->information.account[i]=0;
	}
}
	}
	else {
	UserLinkPtr previousPtr=(*sptr);
	UserLinkPtr currentPtr=(*sptr)->nextPtr;
	while(currentPtr!=NULL&&currentPtr->information.usernumber!=useraccount){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;}
	if(currentPtr!=NULL){//ɾ���м�ڵ� 
	for(i=0;i<10;i++){
	if(vipaccount==currentPtr->information.account[i]){
		currentPtr->information.account[i]=0;
	}
}
	}}
} 

void vipdelete(ServiceLinkPtr (*sptr),char *house)//ɾ����Ա
{
	system("cls");
	system("color 0F");
	int cn;
	if(!empty((*sptr))){
	int deletenumber;
	int result=0; 
	printf("***�����뱻ɾ����Ա�Ļ�Ա�˺�\n");
	scanf("%d",&deletenumber);
	fflush(stdin);
	if(deletenumber==(*sptr)->member.vipnumber){
    VIPHOUSE//ִ��Ԥ�������� 
    printf("***��Ա�ţ�%d\n***��Ա������%s\n***��Ա���֤�ţ�%s\n***��Ա�绰��%d\n***��Ա���ݣ�%c¥%d��Ԫ%d��%d��\n"
,(*sptr)->member.vipnumber,(*sptr)->member.vipname,(*sptr)->member.vipdocument,(*sptr)->member.vipphone,
(*sptr)->member.bulidingcharacter,(*sptr)->member.unitnumber,(*sptr)->member.floornumber,(*sptr)->member.roomnumber);
if((*sptr)->staysituation==1)
printf("***��ס״̬������ס\n"); 
else if((*sptr)->staysituation==2)
printf("***��ס״̬���ѳ���\n");
else if((*sptr)->staysituation==3)
printf("***��ס״̬������\n");
changevipuserlink(&startuserPtr,(*sptr)->usercontact,deletenumber);
		ServiceLinkPtr tempPtr=(*sptr);//��(*sptr)����tempPtr�����ͷſռ� 
		(*sptr)=(*sptr)->nextPtr;//���ڶ����ڵ㸳����һ���ڵ� 
		free(tempPtr);//�ͷ��ڴ�ռ� 
		result=1;
	}
	else {
	ServiceLinkPtr previousPtr=(*sptr);
	ServiceLinkPtr currentPtr=(*sptr)->nextPtr;
	while(currentPtr!=NULL&&currentPtr->member.vipnumber!=deletenumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	if(currentPtr!=NULL){//ɾ���м�ڵ� 
	printf("***��Ա�ţ�%d\n***��Ա������%s\n***��Ա���֤�ţ�%s\n***��Ա�绰��%d\n***��Ա���ݣ�%c¥%d��Ԫ%d��%d��\n"
,currentPtr->member.vipnumber,currentPtr->member.vipname,currentPtr->member.vipdocument,currentPtr->member.vipphone,
currentPtr->member.bulidingcharacter,currentPtr->member.unitnumber,currentPtr->member.floornumber,currentPtr->member.roomnumber);
if(currentPtr->staysituation==1)
printf("***��ס״̬������ס\n"); 
else if(currentPtr->staysituation==2)
printf("***��ס״̬���ѳ���\n");
else if(currentPtr->staysituation==3)
printf("***��ס״̬������\n");
changevipuserlink(&startuserPtr,currentPtr->usercontact,deletenumber);
		ServiceLinkPtr tempPtr=currentPtr;
		previousPtr->nextPtr=currentPtr->nextPtr;
		free(tempPtr);
		result=1; 
	}
	}
	if(result==1){
		printf("*****�û�Ա�ѱ�ɾ��\n"); 
	}
	else {
		printf("***δ�ҵ���Ա��Ϊ %d �Ļ�Ա\n",deletenumber);
	}}
	else {
		printf("***��Ա�б�Ϊ��\n");
	}
	system("pause>nul");
}

void printlist(ServiceLinkPtr sptr){//��ӡ��Ա�б� 
		system("cls");
	system("color 0F");
	if(empty((sptr))){
		printf("\n*****��Ա�б�Ϊ��\n");
	}
	else {
		printf("\n*****��Ա�б�Ϊ��\n\n");
		while ((sptr)!=NULL){//ѭ����ӡ�ڵ� 
			printf("***��Ա�ţ�%d\n***��Ա������%s\n***��Ա���֤�ţ�%s\n***��Ա�绰��%d\n***��Ա���ݣ�%c¥%d��Ԫ%d��%d��\n"
,(sptr)->member.vipnumber,(sptr)->member.vipname,(sptr)->member.vipdocument,(sptr)->member.vipphone,
(sptr)->member.bulidingcharacter,(sptr)->member.unitnumber,(sptr)->member.floornumber,(sptr)->member.roomnumber);
if((sptr)->usercontact==0)
printf("***��δ���������Ա\n");
else printf("***�ѷ��������Ա %d\n",(sptr)->usercontact);
printf("\n\n");
(sptr)=(sptr)->nextPtr;
		}
	}
system("pause>nul");	
}

int empty(ServiceLinkPtr sptr){//�жϻ�Ա�б��Ƿ�Ϊ�� 
	return sptr==NULL;
} 

void vipmanage(char * house)//��Ա���� 
{
	int choicevip=10;
	system("cls");
	system("color 0E");
	printf("    **********��������������Ա����ϵͳ**********\n");
	printf("    ***************��ѡ���Ա����***************\n");
	if(power==1){
		printf("    1.��ѯ��Ա 2.�½���Ա 3.�������� 0.�鿴��ͼ -1.������һ����\n");
	while(choicevip!=1&&choicevip!=0&&choicevip!=-1&&choicevip!=2&&choicevip!=3){
		printf("***��ѡ�������ţ�"); 
	scanf("%d",&choicevip);
	fflush(stdin);
}
if(choicevip==1) vipinquiry(startPtr,(char *)house);//��ѯ
else if(choicevip==2) vipbuilt(&startPtr,(char *)house);//�½� 
else if(choicevip==3) {writefile(); //���� 
 writehousefile((char *)house);}//д�뷿������ 
else if(choicevip==0) map((char *)house);//�鿴��ͼ
else if(choicevip==-1) return ;//���� 
	} 
	else if(power==2){
	printf("    1.�½���Ա 2.��ѯ��Ա 3.�޸Ļ�Ա 4.ɾ����Ա\n    5.�������� 0.�鿴��ͼ -1.������һ����\n");
	while(choicevip!=1&&choicevip!=2&&choicevip!=3&&choicevip!=4&&choicevip!=0&&choicevip!=-1&&choicevip!=5){
		printf("***��ѡ�������ţ�"); 
	scanf("%d",&choicevip);
	fflush(stdin);
}
if(choicevip==1) vipbuilt(&startPtr,(char *)house);//�½� 
else if(choicevip==2) vipinquiry(startPtr,(char *)house);//��ѯ 
else if(choicevip==3) vipchange(&startPtr,(char *)house);//�޸� 
else if(choicevip==4) vipdelete(&startPtr,(char *)house);//ɾ��  
else if(choicevip==5) {writefile(); //���� 
 writehousefile((char *)house);}//д�뷿������ 
}
	else {
	printf("    1.�½���Ա 2.��ѯ��Ա 3.�޸Ļ�Ա 4.ɾ����Ա 5.���л�Աչʾ\n    6.�������� 0.�鿴��ͼ -1.������һ����\n");
	while(choicevip!=1&&choicevip!=2&&choicevip!=3&&choicevip!=4&&choicevip!=0&&choicevip!=-1&&choicevip!=5&&choicevip!=6){
		printf("***��ѡ�������ţ�"); 
	scanf("%d",&choicevip);
	fflush(stdin);
}
if(choicevip==1) vipbuilt(&startPtr,(char *)house);//�½� 
else if(choicevip==2) vipinquiry(startPtr,(char *)house);//��ѯ 
else if(choicevip==3) vipchange(&startPtr,(char *)house);//�޸� 
else if(choicevip==4) vipdelete(&startPtr,(char *)house);//ɾ�� 
else if(choicevip==5) printlist(startPtr);//��ӡ��Ա�б� 
else if(choicevip==6) {writefile(); //���� 
 writehousefile((char *)house);}//д�뷿������ 
}
if(choicevip==-1) return ;//���� 
else if(choicevip==0) map((char *)house);//�鿴��ͼ
vipmanage((char *)house); 
} 
//��ţ���ĸת�� 
 
void housebuy(ServiceLinkPtr (sptr),char *house){//��ѯ���ݹ���״��
	system("cls");
	system("color 0F");
HOUSECN
 if( *(house+FLOOR*UNIT*ROOM*num+UNIT*ROOM*(unumber-1)+ROOM*(fnumber-1)+rnumber-1)!='@')
 printf("*****�÷�����δ����\n");
 else{
 		printf("***��ѯ�ɹ�\n");
 	if(character==(sptr)->member.bulidingcharacter&&unumber==(sptr)->member.unitnumber&&
	 fnumber==(sptr)->member.floornumber&&rnumber==(sptr)->member.roomnumber){
	 	printf("***�÷������۳�\n***������ϵ�绰��%d\n(�����������˺ţ����֤�ű���)\n",(sptr)->member.vipphone);
	 }
	 else{
	 		ServiceLinkPtr previousPtr=(sptr);
	ServiceLinkPtr currentPtr=(sptr)->nextPtr;
	while(currentPtr!=NULL&&character==currentPtr->member.bulidingcharacter&&unumber==currentPtr->member.unitnumber&&
	 fnumber==currentPtr->member.floornumber&&rnumber==currentPtr->member.roomnumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	printf("***��ѯ�ɹ�\n");
	printf("***�÷������۳�\n***������ϵ�绰��%d\n(�����������˺ţ����֤�ű���)\n",currentPtr->member.vipphone);
	 }
 } 
system("pause>nul");
}

void housestay(ServiceLinkPtr (sptr),char *house){//��ѯ������ס״�� 	
system("cls");
system("color 0F");
HOUSECN
 if( *(house+FLOOR*UNIT*ROOM*num+UNIT*ROOM*(unumber-1)+ROOM*(fnumber-1)+rnumber-1)!='@')
 printf("*****�÷�����δ����\n");
  else{
 		printf("***��ѯ�ɹ�\n");
 			if(character==(sptr)->member.bulidingcharacter&&unumber==(sptr)->member.unitnumber&&
	 fnumber==(sptr)->member.floornumber&&rnumber==(sptr)->member.roomnumber){
	 	printf("***�÷������۳�\n***����������%s\n***������ϵ�绰��%d\n(�����˺ţ����֤�ű���)\n",(sptr)->member.vipname,(sptr)->member.vipphone);
	 	if((sptr)->staysituation==1)
printf("***��ס״̬������ס\n"); 
else if((sptr)->staysituation==2)
printf("***��ס״̬���ѳ���\n");
else if((sptr)->staysituation==3)
printf("***��ס״̬������\n");
if((sptr)->usercontact==0)
printf("***��δ���������Ա\n");
else printf("***�ѷ��������Ա %d\n",(sptr)->usercontact);
	 }
	 else{
	 		ServiceLinkPtr previousPtr=(sptr);
	ServiceLinkPtr currentPtr=(sptr)->nextPtr;
	while(currentPtr!=NULL&&character==currentPtr->member.bulidingcharacter&&unumber==currentPtr->member.unitnumber&&
	 fnumber==currentPtr->member.floornumber&&rnumber==currentPtr->member.roomnumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	printf("***��ѯ�ɹ�\n");
	printf("***�÷������۳�\n***����������%s\n***������ϵ�绰��%d\n(�����˺ţ����֤�ű���)\n",currentPtr->member.vipname,currentPtr->member.vipphone);
if(currentPtr->staysituation==1)
printf("***��ס״̬������ס\n"); 
else if(currentPtr->staysituation==2)
printf("***��ס״̬���ѳ���\n");
else if(currentPtr->staysituation==3)
printf("***��ס״̬������\n");
if(currentPtr->usercontact==0)
printf("***��δ���������Ա\n");
else printf("***�ѷ��������Ա %d\n",currentPtr->usercontact);
 } } 
system("pause>nul");
} 

void houseowner(ServiceLinkPtr (sptr),char *house){//�鿴������������Ϣ 
	system("cls");
	system("color 0F");
HOUSECN
 if( *(house+FLOOR*UNIT*ROOM*num+UNIT*ROOM*(unumber-1)+ROOM*(fnumber-1)+rnumber-1)!='@')
 printf("*****�÷�����δ����\n");
  else{
 		printf("***��ѯ�ɹ�\n");
 			if(character==(sptr)->member.bulidingcharacter&&unumber==(sptr)->member.unitnumber&&
	 fnumber==(sptr)->member.floornumber&&rnumber==(sptr)->member.roomnumber){
	 	printf("***�÷������۳�\n***�����˺ţ�%d\n***����������%s\n***�������֤�ţ�%s\n***�����绰��%d\n"
,(sptr)->member.vipnumber,(sptr)->member.vipname,(sptr)->member.vipdocument,(sptr)->member.vipphone);
if((sptr)->staysituation==1)
printf("***��ס״̬������ס\n"); 
else if((sptr)->staysituation==2)
printf("***��ס״̬���ѳ���\n");
else if((sptr)->staysituation==3)
printf("***��ס״̬������\n");
if((sptr)->usercontact==0)
printf("***��δ���������Ա\n");
else printf("***�ѷ��������Ա %d\n",(sptr)->usercontact);
	 }
	 else{
	 ServiceLinkPtr previousPtr=(sptr);
	ServiceLinkPtr currentPtr=(sptr)->nextPtr;
	while(currentPtr!=NULL&&character==currentPtr->member.bulidingcharacter&&unumber==currentPtr->member.unitnumber&&
	 fnumber==currentPtr->member.floornumber&&rnumber==currentPtr->member.roomnumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	printf("***��ѯ�ɹ�\n");
	printf("***�÷������۳�\n***�����˺ţ�%d\n***����������%s\n***�������֤�ţ�%s\n***�����绰��%d\n"
,currentPtr->member.vipnumber,currentPtr->member.vipname,currentPtr->member.vipdocument,currentPtr->member.vipphone);
if(currentPtr->staysituation==1)
printf("***��ס״̬������ס\n"); 
else if(currentPtr->staysituation==2)
printf("***��ס״̬���ѳ���\n");
else if(currentPtr->staysituation==3)
printf("***��ס״̬������\n");	
if(currentPtr->usercontact==0)
printf("***��δ���������Ա\n");
else printf("***�ѷ��������Ա %d\n",currentPtr->usercontact);
	 }
 } 
system("pause>nul");
}

void housemanage(char *house)//���ݹ��� 
{
	int choicehouse=10;
	system("cls");
	system("color 0E");
	printf("    **********���������������ݹ���ϵͳ**********\n");
	printf("    ***************��ѡ���ݷ���***************\n");
	if(power==1){
		printf("    1.��ѯ���ݹ���״�� 2.�������� 0.�鿴��ͼ -1.������һ����\n");
	while(choicehouse!=1&&choicehouse!=0&&choicehouse!=-1&&choicehouse!=0&&choicehouse!=2){
		printf("***��ѡ�������ţ�"); 
	scanf("%d",&choicehouse);
	fflush(stdin);
}
if(choicehouse==1) housebuy(startPtr,(char *)house);//��ѯ���ݹ���״��
 else if(choicehouse==-1) return ;//���� 
 else if(choicehouse==0) map((char *)house);//�鿴��ͼ 
 else if(choicehouse==2) {writefile();//���� 
  writehousefile((char *)house);}//д�뷿������ 
	}
	else if(power==2){
		printf("    1.��ѯ���ݹ���״�� 2.��ѯ������ס״�� 3.�������� 0.�鿴��ͼ -1.������һ����\n");
	while(choicehouse!=1&&choicehouse!=2&&choicehouse!=0&&choicehouse!=-1&&choicehouse!=0&&choicehouse!=3){
		printf("***��ѡ�������ţ�"); 
	scanf("%d",&choicehouse);
	fflush(stdin);
}
if(choicehouse==1) housebuy(startPtr,(char *)house);//��ѯ���ݹ���״��
else if(choicehouse==2) housestay(startPtr,(char *)house);//��ѯ������ס״��
else if(choicehouse==3){ writefile();//���� 
 writehousefile((char *)house);}//д�뷿������ 
	}
	else{
	printf("    1.��ѯ���ݹ���״�� 2.��ѯ������ס״�� 3.�鿴������������Ϣ\n    4.�������� 0.�鿴��ͼ -1.������һ����\n");
	while(choicehouse!=1&&choicehouse!=2&&choicehouse!=3&&choicehouse!=0&&choicehouse!=-1&&choicehouse!=0&&choicehouse!=4){
		printf("***��ѡ�������ţ�"); 
	scanf("%d",&choicehouse);
	fflush(stdin);
}
if(choicehouse==1) housebuy(startPtr,(char *)house);//��ѯ���ݹ���״��
else if(choicehouse==2) housestay(startPtr,(char *)house);//��ѯ������ס״��
else if(choicehouse==3) houseowner(startPtr,(char *)house);//�鿴������������Ϣ 
else if(choicehouse==4) {writefile();//����  
 writehousefile((char *)house);}//д�뷿������ 
}
if(choicehouse==-1) return ;//���� 
else if(choicehouse==0) map((char *)house);//�鿴��ͼ
housemanage((char *)house); 
}
 
 void hire(ServiceLinkPtr sptr,char *house){//��ѯ����ķ����б�
 int serial=1; 
 	system("cls");
	system("color 0F");
		if(empty(sptr))
		printf("\n*****���ⷿ���б�Ϊ��\n");
	else {
		gotoxy(0,2); 
		while ((sptr)!=NULL){//ѭ����ӡ���ⷿ�ݽڵ� 
		if((sptr)->staysituation==2){
printf("***%d.%c��%d��Ԫ%d��%d��\n",serial,(sptr)->member.bulidingcharacter,(sptr)->member.unitnumber,(sptr)->member.floornumber,(sptr)->member.roomnumber);
        serial++;
			}
(sptr)=(sptr)->nextPtr;
		}
		if(serial==1){
		printf("\n*****���ⷿ���б�Ϊ��\n");}
	else {
			gotoxy(0,1);
			printf("*****���ⷿ���б�\n");
	}
	}
	system("pause>nul");
 }
 
 void vacant(ServiceLinkPtr (sptr),char *house){//��ѯ���õķ����б�
 int serial=1; 
 	system("cls");
	system("color 0F");
		if(empty(sptr))
		printf("\n*****���÷����б�Ϊ��\n");
	else {
		gotoxy(0,2) ;
		while ((sptr)!=NULL){//ѭ����ӡ���÷��ݽڵ� 
		if((sptr)->staysituation==3){
printf("***%d.%c��%d��Ԫ%d��%d��\n",serial,(sptr)->member.bulidingcharacter,(sptr)->member.unitnumber,(sptr)->member.floornumber,(sptr)->member.roomnumber);
        serial++;
			}
(sptr)=(sptr)->nextPtr;
		}
		if(serial==1){
		printf("\n*****���÷����б�Ϊ��\n");}
		else {
			gotoxy(0,1);
			printf("*****���÷����б�\n");
		}
	}
	system("pause>nul");
 }
 
void onsale(ServiceLinkPtr (sptr),char *house){//δ�۵ķ����б�
	system("cls");
	system("color 0F");
printf("*****δ�۷����б�\n");
 	int i,j,m,n;
 	char c;
 	int serial=1;//��� 
 	for(i=0;i<BUILDING-1;i++){
 		for(j=0;j<UNIT;j++){
 			for(m=0;m<FLOOR;m++){
 				for(n=0;n<ROOM;n++){
 					if(*(house+FLOOR*UNIT*ROOM*i+UNIT*ROOM*j+ROOM*m+n)=='+'){
 					c=NC(i);
 					printf("%d.%c��%d��Ԫ%d��%d��\n",serial,c,j+1,m+1,n+1);
					 serial++;
					 }
				 }
			 }
		 }
	 }
	 system("pause>nul");
 }
 
void staymanage(char *house)//��ס���� 
{
int choicestay=10;
	system("cls");
	system("color 0E");
	printf("    **********��������������ס����ϵͳ**********\n");
	printf("    ***************��ѡ����ס����***************\n");
	printf("    1.��ѯ����ķ����б� 2.��ѯ���õķ����б� 3.�鿴δ�۵ķ����б�\n    4.�������� 0.�鿴��ͼ -1.������һ����\n");
	while(choicestay!=1&&choicestay!=2&&choicestay!=3&&choicestay!=0&&choicestay!=-1&&choicestay!=0&&choicestay!=4){
		printf("***��ѡ�������ţ�"); 
	scanf("%d",&choicestay);
	fflush(stdin);
}
if(choicestay==1) hire(startPtr,(char *)house);//��ѯ����ķ����б�
else if(choicestay==2) vacant(startPtr,(char *)house);//��ѯ���õķ����б�
else if(choicestay==3) onsale(startPtr,(char *)house);//�鿴δ�۵ķ����б�
else if(choicestay==4) {writefile();//����
 writehousefile((char *)house);}//д�뷿������  
 else if(choicestay==-1) return ;//���� 
 else if(choicestay==0) map((char *)house);//�鿴��ͼ 
staymanage((char *)house); 
}

void new_built(){//�½�
int i;
unsigned int newbuilt; 
system("cls");
system("color 0F");
printf("*****�����᰸���£�\n");//��Switch���ʵ��ѡ���ڶ���ѡ���нϺ� 
if(pingpong>0)printf("***ƹ������᰸��%d\n",pingpong);
if(badminton>0)printf("***��ë���᰸��%d\n",badminton);
if(yoga>0)printf("***�٤���᰸��%d\n",yoga);
if(chess>0)printf("***�������᰸��%d\n",chess);
if(tableball>0)printf("***̨�����᰸��%d\n",tableball);
if(tea>0)printf("***��ˮ���᰸��%d\n",tea);
if(newspaper>0)printf("***��ֽ�������᰸��%d\n",newspaper);
if(book>0)printf("***ͼ����᰸��%d\n",book);
if(opera>0)printf("***�������᰸��%d\n",opera);
if(shuttlecock>0)printf("***������᰸��%d\n",shuttlecock);
if(dance>0)printf("***�㳡�����᰸��%d\n",dance);
if(handwriting>0)printf("***�鷨���᰸��%d\n",handwriting);
if(weave>0)printf("***��֯���᰸��%d\n",weave);
if(chat>0)printf("***�������᰸��%d\n",chat);
system("pause>nul");
printf("*****����ݾ����᰸ѡ���½�������ʩ������\n");
printf("***��ѡ�����½��跽����\n*1.ƹ�����\t2.��ë���\n*3.�٤��\t4.������\n*5.̨���\t6.��ˮ��\n7.��ֽ������\t8.ͼ���\n"); 
printf("*9.������\t10.�����\n*11.�㳡����\t12.�鷨��\n*13.��֯��\t14.������\n"); 

scanf("%d",&newbuilt);
fflush(stdin);
switch (newbuilt){//��Switch���ʵ��ѡ���ڶ���ѡ���нϺ� 
	case 1:{ENJOY enjoy[newbuilt-1]=1;printf("***�½�ƹ����ݳɹ�\n");break;}case 2:{ENJOY enjoy[newbuilt-1]=1;printf("***�½���ë��ݳɹ�\n");break;}
	case 3:{ENJOY enjoy[newbuilt-1]=1;printf("***�½��٤�ݳɹ�\n");break;}case 4:{ENJOY enjoy[newbuilt-1]=1;printf("***�½������ҳɹ�\n");break;}
	case 5:{ENJOY enjoy[newbuilt-1]=1;printf("***�½�̨��ݳɹ�\n");break;}case 6:{ENJOY enjoy[newbuilt-1]=1;printf("***�½���ˮ�ҳɹ�\n");break;}
	case 7:{ENJOY enjoy[newbuilt-1]=1;printf("***�½���ֽ�����ҳɹ�\n");break;}case 8:{ENJOY enjoy[newbuilt-1]=1;printf("***�½�ͼ��ݳɹ�\n");break;}
	case 9:{ENJOY enjoy[newbuilt-1]=1;printf("***�½�������ɹ�\n");break;}case 10:{ENJOY enjoy[newbuilt-1]=1;printf("***�½������ɹ�\n");break;}
	case 11:{ENJOY enjoy[newbuilt-1]=1;printf("***�½��㳡����ɹ�\n");break;}case 12:{ENJOY enjoy[newbuilt-1]=1;printf("***�½��鷨�ҳɹ�\n");break;}
	case 13:{ENJOY enjoy[newbuilt-1]=1;printf("***�½���֯�ҳɹ�\n");break;}case 14:{ENJOY enjoy[newbuilt-1]=1;printf("***�½������ҳɹ�\n");break;}
	default :{
	printf("***��ѡ���в��½�������ʩ\n");
	system("pause>nul");
	return ;}	
}
system("pause>nul");
}

void scheme(){//�Ͻ��᰸ 
unsigned int choice;
system("cls");
system("color 0F");
printf("***��ѡ������Ԥ�������Ľ��齫�ᷴ����������Ա����\n*1.ƹ�����\t2.��ë���\n*3.�٤��\t4.������\n*5.̨���\t6.��ˮ��\n7.��ֽ������\t8.ͼ���\n"); 
printf("*9.������\t10.�����\n*11.�㳡����\t12.�鷨��\n*13.��֯��\t14.������\n"); 
scanf("%d",&choice);
fflush(stdin);
switch (choice){
	case 1:pingpong++;break;case 2:badminton++;break;
	case 3:yoga++;break;case 4:chess++;break;
	case 5:tableball++;break;case 6:tea++;break;
	case 7:newspaper++;break;case 8:book++;break;
	case 9:opera++;break;case 10:shuttlecock++;break;
	case 11:dance++;break;case 12:handwriting++;break;
	case 13:weave++;break;case 14:chat++;break;
	default :{
	printf("***�᰸����Ԥ���ڣ��᰸��Ч\n");
	system("pause>nul");
	return ;}
}printf("***�ύ�ɹ�����ȴ�������Ա����\n");
system("pause>nul");
}
 
int isempty(LinkPtr headPtr){//�������Ƿ�Ϊ��
return headPtr==NULL;
}

int delink(LinkPtr *sptr,int deletenumber){//ɾ��ԤԼ��Ա 
int result=0;
	if(deletenumber==(*sptr)->account){
		LinkPtr tempPtr=(*sptr);//��(*sptr)����tempPtr�����ͷſռ� 
		(*sptr)=(*sptr)->nextPtr;//���ڶ����ڵ㸳����һ���ڵ� 
		free(tempPtr);//�ͷ��ڴ�ռ� 
		result=1;
	}
	else {
	LinkPtr previousPtr=(*sptr);
	LinkPtr currentPtr=(*sptr)->nextPtr;
	while(currentPtr!=NULL&&currentPtr->account!=deletenumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	if(currentPtr!=NULL){//ɾ���м�ڵ� 
		LinkPtr tempPtr=currentPtr;
		previousPtr->nextPtr=currentPtr->nextPtr;
		free(tempPtr);
		result=1; 
	}
	}
	return result;
}
 
void enlink(LinkPtr *sptr,int num){//�����Ŷ�����Ԫ�� 
	LinkPtr newPtr=(LinkPtr)malloc(sizeof(Link));
if(newPtr!=NULL){//�ж��Ƿ��пռ� 
	newPtr->account=num;
	newPtr->nextPtr;//�ýڵ㲻ָ���κνڵ� 
	LinkPtr previousPtr=NULL;
	LinkPtr currentPtr=*sptr;
	while (currentPtr!=NULL){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;//��һ���ڵ� 
	}
	if(previousPtr==NULL){
		newPtr->nextPtr=*sptr;
		*sptr=newPtr;
	}
	else {
		previousPtr->nextPtr=newPtr;
		newPtr->nextPtr=currentPtr;
	}
} 
else {
	printf("**�ڴ��������ڵ�δ�ܴ����ɹ�\n"); 
}
}

void printlinelink(LinkPtr sptr){//��ӡ�Ŷ����� 
	if(sptr==NULL){
	printf("***����Ϊ��\n");
}
else {
	printf("***����Ϊ��\n");
	while (sptr!=NULL){
		printf("%d-->",sptr->account);
		sptr=sptr->nextPtr;
	}printf("\n");
}
}
 
void application(ServiceLinkPtr *sptr){//����������ʩ����
int t;//���� enjoyment��ֵ 
int result=0;
int applicationnumber;
	system("cls");
	system("color 0F");	
		int application;//��Switch���ʵ��ѡ���ڶ���ѡ���нϺ� 
		printf("***ÿ����ʩ��ԤԼʮ�ˣ���ѡ����ҪԤԼ�ķ���\n");
printf("*1.ƹ�����\t2.��ë���\n*3.�٤��\t4.������\n*5.̨���\t6.��ˮ��\n7.��ֽ������\t8.ͼ���\n"); 
printf("*9.������\t10.�����\n*11.�㳡����\t12.�鷨��\n*13.��֯��\t14.������\n"); 
scanf("%d",&application);
fflush(stdin);
if(application<1||application>14){
	printf("**δ�ҵ���Ӧ��������ʩ��������Ч������\n");
	system("pause>nul");
	return ;}
	if(enjoy[application-1]==0){
		printf("**����ʩ��δ���ɣ������Է�����һ��������᰸\n");
		system("pause>nul");
		return ;}
		if(enjoynum[application-1]>=10) {
			printf("**����ʩԤԼ�������������Ŷӵȴ����˷������\n");
			system("pause>nul");
			return ;
		}
	int cn;
	if(!empty(*sptr)){
//һ����ֻ��ԤԼһ������ ��������Ҫ������˺��Ƿ��Ѿ�ԤԼ�������enjoyment��ֵ 
    result=0; 
	printf("***�������Ա�˺�\n");
	scanf("%d",&applicationnumber);
	fflush(stdin);
	if(applicationnumber==(*sptr)->member.vipnumber){
		result=1;
		t=(*sptr)->enjoyment;
		(*sptr)->enjoyment=application;
	}
	else {
	ServiceLinkPtr previousPtr=(*sptr);
	ServiceLinkPtr currentPtr=(*sptr)->nextPtr;
	while(currentPtr!=NULL&&currentPtr->member.vipnumber!=applicationnumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	if(currentPtr!=NULL){//��ѯ�м�ڵ� 
		result=1; 
			t=currentPtr->enjoyment;
			currentPtr->enjoyment=application;
	}
	}
	if(result==0) {
		printf("***δ�ҵ���Ա��Ϊ %d �Ļ�Ա\n",applicationnumber);
		system("pause>nul");
		return ;
	}}
	else {
		printf("***��Ա�б�Ϊ��\n");
		system("pause>nul");
		return ;
	}
	if(t!=0){
		printf("***����ԤԼ���������������ٴ�ԤԼ\n");//
			system("pause>nul");
		return ;
	}
		printf("**ԤԼ�ɹ�������������н�����������ö��б仯\n");
		enjoynum[application-1]++; 
			enlink(&headPtr[application-1],applicationnumber);
			printlinelink(headPtr[application-1]);
	system("pause>nul");
} 
 
void end(ServiceLinkPtr *sptr){//�������ַ��� 
int result,search=0; 
int t;//����enjoyment��ֵ 
int applicationnumber;
system("cls");
system("color 0F");
	int cn;
	if(!empty(*sptr)){
    result=0; 
	printf("***�������Ա�˺�\n");
	scanf("%d",&applicationnumber);
	fflush(stdin);
	if(applicationnumber==(*sptr)->member.vipnumber){
		result=1;
		t=(*sptr)->enjoyment;
		(*sptr)->enjoyment=0;
	}
	else {
	ServiceLinkPtr previousPtr=(*sptr);
	ServiceLinkPtr currentPtr=(*sptr)->nextPtr;
	while(currentPtr!=NULL&&currentPtr->member.vipnumber!=applicationnumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	if(currentPtr!=NULL){//��ѯ�м�ڵ� 
		result=1; 
		t=currentPtr->enjoyment;
		currentPtr->enjoyment=0;
	}
	}
	if(result==0) {
		printf("***δ�ҵ���Ա��Ϊ %d �Ļ�Ա\n",applicationnumber);
		system("pause>nul");
		return ;
	}}
	else {
		printf("***��Ա�б�Ϊ��\n");
		system("pause>nul");
		return ;
	}
		search=delink(&headPtr[t-1],applicationnumber);
		if(search==1)
		printf("***%d �ѽ�������\n",applicationnumber);
		else printf("***%d ���ڶ����������Ч\n");
		//���������ͬʱ����Ա������ʩʹ��״̬���³�ʼ�� 
system("pause>nul");
}
 
void printlineall(){//��ӡȫ���б� 
	system("cls");
	system("color 0E");
	printf("1.ƹ�����\n");	printlinelink(headPtr[0]);
	printf("2.��ë���\n");	printlinelink(headPtr[1]);
	printf("3.�٤��\n");	printlinelink(headPtr[2]);
	printf("4.������\n");	printlinelink(headPtr[3]);
	printf("5.̨���\n");	printlinelink(headPtr[4]);
	printf("6.��ˮ��\n");	printlinelink(headPtr[5]);
	printf("7.��ֽ������\n");	printlinelink(headPtr[6]);
	printf("8.ͼ���\n");	printlinelink(headPtr[7]);
	printf("9.������\n");	printlinelink(headPtr[8]);
	printf("10.�����\n");	printlinelink(headPtr[9]);
	printf("11.�㳡����\n");	printlinelink(headPtr[10]);
	printf("12.�鷨��\n");	printlinelink(headPtr[11]);
	printf("13.��֯��\n");	printlinelink(headPtr[12]);
	printf("14.������\n");	printlinelink(headPtr[13]);
	system("pause>nul") ;
}
 
void publicmanage(char *house)//������ʩ����
{
 int choicepublic=10;
	system("cls");
	system("color 0E");
	printf("    **********������������������ʩ����ϵͳ**********\n");
	printf("    ***************��ѡ����ʩ�������***************\n");
	if(power==1){
	printf("    1.��¼�˺�ԤԼ������ʩ���� 2.�Ͻ�������ʩ�����᰸ 3.�������� 4.��ӡ�Ŷ��б�\n    5.�������� 0.�鿴��ͼ -1.������һ����\n");
	while(choicepublic!=1&&choicepublic!=2&&choicepublic!=0&&choicepublic!=-1&&choicepublic!=3&&choicepublic!=4&&choicepublic!=5){
		printf("***��ѡ�������ţ�"); 
	scanf("%d",&choicepublic);
	fflush(stdin);
}
if(choicepublic==1) application(&startPtr);//����������ʩ���� 
else if(choicepublic==2) scheme();//�Ͻ� 
else if(choicepublic==3) end(&startPtr);//�������ַ��� 
else if(choicepublic==5) {writefile();//���� 
 writehousefile((char *)house);}//д�뷿������ 
else if(choicepublic==4) printlineall();//��ӡȫ������ 
 else if(choicepublic==-1) return ;//���� 
 else if(choicepublic==0) map((char *)house);//�鿴��ͼ 
	}
	else if(power==2){
		printf("     1.�Ͻ�������ʩ�����᰸ 2.�������� 3.��ӡ�Ŷ��б� 0.�鿴��ͼ -1.������һ����\n");
	while(choicepublic!=1&&choicepublic!=0&&choicepublic!=-1&&choicepublic!=2&&choicepublic!=3){
		printf("***��ѡ�������ţ�"); 
	scanf("%d",&choicepublic);
	fflush(stdin);
}
 if(choicepublic==1) scheme();//�Ͻ� 
 else if(choicepublic==2) {writefile();//����
  writehousefile((char *)house);}//д�뷿������ 
 else if(choicepublic==3) printlineall();//��ӡȫ������ 
	}
	else {
	printf("    1.��¼�˺�ԤԼ������ʩ���� 2.�½�������ʩ 3.�Ͻ�������ʩ�����᰸ 4.�������� 5.��ӡ�Ŷ��б�\n    6.�������� 0.�鿴��ͼ -1.������һ����\n");
	while(choicepublic!=1&&choicepublic!=2&&choicepublic!=3&&choicepublic!=0&&choicepublic!=-1&&choicepublic!=4&&choicepublic!=5&&choicepublic!=6){
		printf("***��ѡ�������ţ�"); 
	scanf("%d",&choicepublic);
	fflush(stdin);
}
if(choicepublic==1) application(&startPtr);//����������ʩ���� 
else if(choicepublic==2) new_built();//�½�
else if(choicepublic==3) scheme();//�Ͻ� 
else if(choicepublic==4) end(&startPtr);//�������ַ��� 
 else if(choicepublic==5) printlineall();//��ӡȫ������ 
else if(choicepublic==6) {writefile();//����
  writehousefile((char *)house);}//д�뷿������ 
}
if(choicepublic==-1) return ;//���� 
else if(choicepublic==0) map((char *)house);//�鿴��ͼ
publicmanage((char *)house); 
}
 
void creatuser(UserLinkPtr *sptr){//�½�������Ա���� 
	system("cls");
	system("color 0F");
	int i=0; 
	char ch;
	int cn=10;//��¥��ת��Ϊ�����е���� 
	worker.usernumber=2021000+usern;
	usern++;
	printf("**��������ְ���Ļ�����Ϣ\n") ;
	printf("**1.������Ӣ�ģ�\n");
    scanf("%s", worker.username);
    	fflush(stdin);
    printf("**3.�绰����\n");
    scanf("%d",&worker.userphone);
    fflush(stdin);
printf("\n**�½�ְ���ɹ�����鿴ְ����Ϣ\n");//��ӡ��Ա��Ϣ 
printf("***ְ���ţ�%d\n***ְ��������%s\n***ְ���绰��%d\n"
,worker.usernumber,worker.username,worker.userphone);
UserLinkPtr newPtr=(UserLinkPtr)malloc(sizeof(UserLink));
if(newPtr!=NULL){//�ж��Ƿ��пռ� 
	newPtr->information=worker;//��ֵ�����ڵ�
	newPtr->busstate=0;//��ʼ������״̬ 
	newPtr->nextPtr;//�ýڵ㲻ָ���κνڵ� 
	UserLinkPtr previousPtr=NULL;
	UserLinkPtr currentPtr=*sptr;
	while (currentPtr!=NULL&&worker.usernumber>currentPtr->information.usernumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;//��һ���ڵ� 
	}
	if(previousPtr==NULL){
		newPtr->nextPtr=*sptr;//˵��Ϊͷ��� 
		*sptr=newPtr;
	}
	else {
		previousPtr->nextPtr=newPtr;
		newPtr->nextPtr=currentPtr;
	}
} 
else {
	printf("**�ڴ���������Ա�˺�%dδ�ܴ����ɹ�",worker.usernumber); 
}
system("pause>nul");
}

void chooseuser(ServiceLinkPtr *sptr,UserLinkPtr *usersptr){//ѡ�������� 
int i,result1=0,result2=0;
int workeraccount;
	system("cls");
	system("color 0F");
	if(!userempty(*usersptr)){
	printf("*****������ְ���˺�\n");
	scanf("%d",&workeraccount);
	fflush(stdin);
	if(workeraccount==(*usersptr)->information.usernumber){//���������޸������ܵĻ�����ʵ���û�����ͻ�Ա�����˫���޸� 
		result1=1;
		unsigned int choice;
	if(!empty((*sptr))){
	int changenumber;
	int result2=0; 
	printf("***������ѡ��ķ�������˺�\n");
	scanf("%d",&changenumber);
	fflush(stdin);
	if(changenumber==(*sptr)->member.vipnumber){
				if((*sptr)->usercontact!=0){
			printf("***�û�Ա���з�����Ա��������Ч\n");
				system("pause>nul");
			return ;
		}
		for(i=0;i<10;i++){
	if((*usersptr)->information.account[i]==0){
	(*usersptr)->information.account[i]=changenumber;
	break;}
	if(i==9){
	printf("***������󳬹�ʮ�ˣ�������Ч\n");
	system("pause>nul");
	return ;}
}
	printf("***ѡ��ɹ�����Ϊ��ƥ�����»�Ա��\n") ;
printf("***��Ա�ţ�%d\n***��Ա������%s\n***��Ա���֤�ţ�%s\n***��Ա�绰��%d\n***��Ա���ݣ�%c¥%d��Ԫ%d��%d��\n"
,(*sptr)->member.vipnumber,(*sptr)->member.vipname,(*sptr)->member.vipdocument,(*sptr)->member.vipphone,
(*sptr)->member.bulidingcharacter,(*sptr)->member.unitnumber,(*sptr)->member.floornumber,(*sptr)->member.roomnumber);
(*sptr)->usercontact=workeraccount; 
		result2=1;
	}
	else {
	ServiceLinkPtr previousPtr=(*sptr);//����ͷ��� 
	ServiceLinkPtr currentPtr=(*sptr)->nextPtr;
	while(currentPtr!=NULL&&currentPtr->member.vipnumber!=changenumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	if(currentPtr!=NULL){//�޸��м�ڵ� 
			if(currentPtr->usercontact!=0){
			printf("***�û�Ա���з�����Ա��������Ч\n");
				system("pause>nul");
			return ;
		}
		for(i=0;i<10;i++){
	if((*usersptr)->information.account[i]==0){
	(*usersptr)->information.account[i]=changenumber;
	break;}
	if(i==9){
	printf("***������󳬹�ʮ�ˣ�������Ч\n");
	system("pause>nul");
	return ;}
} 
	printf("***ѡ��ɹ�����Ϊ��ƥ�����»�Ա��\n") ;
printf("***��Ա�ţ�%d\n***��Ա������%s\n***��Ա���֤�ţ�%s\n***��Ա�绰��%d\n***��Ա���ݣ�%c¥%d��Ԫ%d��%d��\n"
,currentPtr->member.vipnumber,currentPtr->member.vipname,currentPtr->member.vipdocument,currentPtr->member.vipphone,
currentPtr->member.bulidingcharacter,currentPtr->member.unitnumber,currentPtr->member.floornumber,currentPtr->member.roomnumber);
		result2=1;	
	}
	}
	if(result2==0) {
		printf("***δ�ҵ���Ա��Ϊ %d �Ļ�Ա\n",changenumber);
	}}
	else {
		printf("***��Ա�б�Ϊ��\n");
	}	
	}
	else {
	UserLinkPtr previoususerPtr=(*usersptr);
	UserLinkPtr currentuserPtr=(*usersptr)->nextPtr;
	while(currentuserPtr!=NULL&&currentuserPtr->information.usernumber!=workeraccount){
		previoususerPtr=currentuserPtr;
		currentuserPtr=currentuserPtr->nextPtr;
	}
	if(currentuserPtr!=NULL){//�޸��м�ڵ� 
		result1=1;
		unsigned int choice;
	if(!empty((*sptr))){
	int changenumber;
	int result2=0; 
	printf("***������ѡ��ķ�������˺�\n");
	scanf("%d",&changenumber);
	fflush(stdin);
	if(changenumber==(*sptr)->member.vipnumber){
		if((*sptr)->usercontact!=0){//�жϸû�Ա�Ƿ�͸��û��й�ϵ 
			printf("***�û�Ա���з�����Ա��������Ч\n");
				system("pause>nul");
			return ;
		}
		for(i=0;i<10;i++){
	if(currentuserPtr->information.account[i]==0){
	currentuserPtr->information.account[i]=changenumber;
	break;}
	if(i==9){
	printf("***������󳬹�ʮ�ˣ�������Ч\n");
	system("pause>nul");
	return ;}
}
	printf("***ѡ��ɹ�����Ϊ��ƥ�����»�Ա��\n") ;
printf("***��Ա�ţ�%d\n***��Ա������%s\n***��Ա���֤�ţ�%s\n***��Ա�绰��%d\n***��Ա���ݣ�%c¥%d��Ԫ%d��%d��\n"
,(*sptr)->member.vipnumber,(*sptr)->member.vipname,(*sptr)->member.vipdocument,(*sptr)->member.vipphone,
(*sptr)->member.bulidingcharacter,(*sptr)->member.unitnumber,(*sptr)->member.floornumber,(*sptr)->member.roomnumber);
(*sptr)->usercontact=workeraccount; 
		result2=1;
	}
	else {
	ServiceLinkPtr previousPtr=(*sptr);
	ServiceLinkPtr currentPtr=(*sptr)->nextPtr;
	while(currentPtr!=NULL&&currentPtr->member.vipnumber!=changenumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	if(currentPtr!=NULL){//�޸��м�ڵ� 
			if(currentPtr->usercontact!=0){//�жϸû�Ա�Ƿ�͸��û��й�ϵ 
			printf("***�û�Ա���з�����Ա��������Ч\n");
				system("pause>nul");
			return ;
		}
		for(i=0;i<10;i++){
	if(currentuserPtr->information.account[i]==0){
	currentuserPtr->information.account[i]=changenumber;
	break;}
	if(i==9){
	printf("***������󳬹�ʮ�ˣ�������Ч\n");
	system("pause>nul");
	return ;}
} 
	printf("***ѡ��ɹ�����Ϊ��ƥ�����»�Ա��\n") ;
printf("***��Ա�ţ�%d\n***��Ա������%s\n***��Ա���֤�ţ�%s\n***��Ա�绰��%d\n***��Ա���ݣ�%c¥%d��Ԫ%d��%d��\n"//��ӡ��Ա��Ϣ 
,currentPtr->member.vipnumber,currentPtr->member.vipname,currentPtr->member.vipdocument,currentPtr->member.vipphone,
currentPtr->member.bulidingcharacter,currentPtr->member.unitnumber,currentPtr->member.floornumber,currentPtr->member.roomnumber);
		result2=1;	
	}
	}
	if(result2==0) {
		printf("***δ�ҵ���Ա��Ϊ %d �Ļ�Ա\n",changenumber);
	}}
	else {
		printf("***��Ա�б�Ϊ��\n");
	}
	}
	}
	if(result1==0) {
		printf("***δ�ҵ�ְ����Ϊ %d �Ļ�ְ��\n",workeraccount);
	}}
	else {
		printf("***ְ���б�Ϊ��\n");
	}
	system("pause>nul");
}

void visituser(ServiceLinkPtr sptr){//�鿴�������,����Ա�б� 
 	system("cls");
	system("color 0F");
	if(empty((sptr))){
		printf("\n*****��������б�Ϊ��\n");
	}
	else {
		printf("\n*****��������б�Ϊ��\n\n");
		while ((sptr)!=NULL){//ѭ����ӡ�ڵ� 
			printf("***��Ա�ţ�%d\n***��Ա������%s\n***��Ա���֤�ţ�%s\n***��Ա�绰��%d\n***��Ա���ݣ�%c¥%d��Ԫ%d��%d��\n"//��ӡ��Ա��Ϣ 
,(sptr)->member.vipnumber,(sptr)->member.vipname,(sptr)->member.vipdocument,(sptr)->member.vipphone,
(sptr)->member.bulidingcharacter,(sptr)->member.unitnumber,(sptr)->member.floornumber,(sptr)->member.roomnumber);
if(sptr->usercontact!=0)printf("***�ѷ��������Ա %d\n",sptr->usercontact);
else printf("***δ���������Ա\n");//�жϻ�Ա�ķ�����Ա������� 
printf("\n\n");
(sptr)=(sptr)->nextPtr;
		}
	}
system("pause>nul");
}
 
 int userempty(UserLinkPtr sptr) {//����Ƿ�Ϊ�� 
 	return sptr==NULL;
 }
 
void printuser(UserLinkPtr sptr) {//�鿴������Ա�б� 
int i;int m=1;
 	system("cls");
	system("color 0F");
	if(userempty((sptr))){
		printf("\n*****ְ���б�Ϊ��\n");
	}
	else {
		printf("\n*****ְ���б�Ϊ��\n\n");
		while ((sptr)!=NULL){//ѭ����ӡ�ڵ� 
			printf("***ְ���ţ�%d\n***ְ��������%s\n***ְ���绰��%d\n***��������У�\n"
,(sptr)->information.usernumber,(sptr)->information.username,(sptr)->information.userphone);
printf("***����������£����ռ��޷������\n"); 
for(i=0;i<10;i++){
	if((sptr)->information.account[i]!=0){
		printf("%d.%d\n",m,(sptr)->information.account[i]);
		m++;
	}
}
printf("\n\n");
(sptr)=(sptr)->nextPtr;//ָ����һ�ڵ� 
		}
	}
system("pause>nul");
}
	
void changecontact(ServiceLinkPtr *sptr,int account){//�޸��û��ͳ�Ա��ϵ���� 
	if(account==(*sptr)->member.vipnumber){
(*sptr)->usercontact=0; }
	else {
	ServiceLinkPtr previousPtr=(*sptr);
	ServiceLinkPtr currentPtr=(*sptr)->nextPtr;
	while(currentPtr!=NULL&&currentPtr->member.vipnumber!=account){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;}
	if(currentPtr!=NULL){//�޸��м�ڵ� 
	currentPtr->usercontact=0; 
	}}	
}
	
void deleteuser(UserLinkPtr *sptr){//ɾ��������Ա 
	system("cls");
	system("color 0F");
	int i,m=1,n=1; 
	if(!userempty((*sptr))){
	int deletenumber;
	int result=0; 
	printf("***�����뱻ɾ��ְ���˺�\n");
	scanf("%d",&deletenumber);
	fflush(stdin);
	if(deletenumber==(*sptr)->information.usernumber){
    printf("***ְ���ţ�%d\n***ְ��������%s\n***��Ա�绰��%d\n"
,(*sptr)->information.usernumber,(*sptr)->information.username,(*sptr)->information.userphone);
printf("***����������£����ռ��޷������\n");
for(i=0;i<10;i++){
	if((*sptr)->information.account[i]!=0){
		printf("%d.%d\n",m,(*sptr)->information.account[i]);
		m++;
			changecontact(&startPtr,(*sptr)->information.account[i]);
	}
}
		UserLinkPtr tempPtr=(*sptr);//��(*sptr)����tempPtr�����ͷſռ� 
		(*sptr)=(*sptr)->nextPtr;//���ڶ����ڵ㸳����һ���ڵ� 
		free(tempPtr);//�ͷ��ڴ�ռ� 
		result=1;
	}
	else {
	UserLinkPtr previousPtr=(*sptr);
	UserLinkPtr currentPtr=(*sptr)->nextPtr;
	while(currentPtr!=NULL&&currentPtr->information.usernumber!=deletenumber){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	if(currentPtr!=NULL){//ɾ���м�ڵ� 
	 printf("***ְ���ţ�%d\n***ְ��������%s\n***��Ա�绰��%d\n"
,currentPtr->information.usernumber,currentPtr->information.username,currentPtr->information.userphone);
		UserLinkPtr tempPtr=currentPtr;
		for(i=0;i<10;i++){
	if(currentPtr->information.account[i]!=0){
		printf("%d.%d\n",n,currentPtr->information.account[i]);
		n++;
		changecontact(&startPtr,currentPtr->information.account[i]);
	}//���ú����ı�������ϵ״̬ 
}
		previousPtr->nextPtr=currentPtr->nextPtr;
		free(tempPtr);
		result=1; 
	}
	}
	if(result==1){
		printf("*****��ְ���ѱ�ɾ��\n"); 
	}
	else {
		printf("***δ�ҵ�ְ����Ϊ %d ��ְ��\n",deletenumber);
	}}
	else {
		printf("***ְ���б�Ϊ��\n");
	}
	system("pause>nul");
}
	
void usermanage(char *house)//�û����� 
{
	unsigned int choiceuser=10; 
	system("cls");
	system("color 0E");
	printf("    **********�������������û�����ϵͳ**********\n");
	printf("    ***************��ѡ���û��������***************\n");
	if(power==2){
		printf("    1.�½�������Ա 2.ѡ�������� 3.�鿴�������\n    4.�������� 0.�鿴��ͼ -1.������һ����\n");
	while(choiceuser!=1&&choiceuser!=2&&choiceuser!=3&&choiceuser!=0&&choiceuser!=-1&&choiceuser!=4){
		printf("***��ѡ�������ţ�"); 
	scanf("%d",&choiceuser);
	fflush(stdin);
}
if(choiceuser==1) creatuser(&startuserPtr);//�½�������Ա���� 
else if(choiceuser==2) chooseuser(&startPtr,&startuserPtr);//ѡ�������� 
else if(choiceuser==3) visituser(startPtr);//�鿴�������
else if(choiceuser==4) {writefile();//����
  writehousefile((char *)house);}//д�뷿������  
	}
	else {
	printf("    1.�½�������Ա 2.ѡ�������� 3.�鿴������� 4.�鿴������Ա�б� 5.ɾ��������Ա\n    6.�������� 0.�鿴��ͼ -1.������һ����\n");
	while(choiceuser!=1&&choiceuser!=2&&choiceuser!=3&&choiceuser!=0&&choiceuser!=-1&&choiceuser!=4&&choiceuser!=5&&choiceuser!=6){
		printf("***��ѡ�������ţ�"); 
	scanf("%d",&choiceuser);
	fflush(stdin);
}
if(choiceuser==1) creatuser(&startuserPtr);//�½�������Ա���� 
else if(choiceuser==2) chooseuser(&startPtr,&startuserPtr);//ѡ�������� 
else if(choiceuser==3) visituser(startPtr);//�鿴�������
else if(choiceuser==4) printuser(startuserPtr);//�鿴������Ա�б� 
else if(choiceuser==5) deleteuser(&startuserPtr);//ɾ��������Ա
else if(choiceuser==6) {writefile();//����
  writehousefile((char *)house);}//д�뷿������ 
}
if(choiceuser==-1) return ;//���� 
else if(choiceuser==0) map((char *)house);//�鿴��ͼ
usermanage((char *)house); 
}

void creatbus(){//�½��೵���η��� 
	system("cls");
	system("color 0F");
	BUSNUM
	printf("***�ϰ�ʱ������Ϊ������㵽ʮ��\n");
	printf("***�ϰ�ʱ������Ϊ�����ĵ㵽�ŵ�\n");
	printf("***����24Сʱ��ʱ\n");
	while(shuttle[shuttlenum].timecome[0]<5||shuttle[shuttlenum].timecome[0]>9||shuttle[shuttlenum].timecome[1]<0||shuttle[shuttlenum].timecome[1]>59){
			printf("***�������½��೵���ε��ϰ�ʱ�䣨8 30����ʽ\n");
		scanf("%d %d",&shuttle[shuttlenum].timecome[0],&shuttle[shuttlenum].timecome[1]);
		fflush(stdin);
	}
	while(shuttle[shuttlenum].timego[0]<16||shuttle[shuttlenum].timego[0]>20||shuttle[shuttlenum].timego[1]<0||shuttle[shuttlenum].timego[1]>59){
			printf("***�������½��೵���ε��°�ʱ�䣨17 30����ʽ\n");
		scanf("%d %d",&shuttle[shuttlenum].timego[0],&shuttle[shuttlenum].timego[1]);
		fflush(stdin);
	}
	while(shuttle[shuttlenum].fee<1||shuttle[shuttlenum].fee>5) {
		printf("***�������½��೵�ĳ˳����ã�һԪ����Ԫ��(2)��ʽ\n");
		scanf("%d",&shuttle[shuttlenum].fee);
		fflush(stdin);
	}
	shuttle[shuttlenum].number=202101+shuttlenum;
	printf("***�½��ɹ����೵��Ϣ���£�\n");
	printf("***�೵��ţ�%d\n***�˳��ѣ�%dԪ\n***�ϰ�ʱ�䣺%02d:%02d\n***�°�ʱ�䣺%02d:%02d\n",shuttle[shuttlenum].number,shuttle[shuttlenum].fee,shuttle[shuttlenum].timecome[0],
	shuttle[shuttlenum].timecome[1],shuttle[shuttlenum].timego[0],shuttle[shuttlenum].timego[1]);
	system("pause>nul");
}

void deletebuslink(BusLinkPtr *sptr,ServiceLinkPtr *vipsptr,UserLinkPtr *usersptr){//ɾ������;�������� 
	BusLinkPtr currentPtr=(*sptr);
	BusLinkPtr tempPtr=currentPtr;
	while(currentPtr!=NULL){
		
//���������޸������ܵĻ�����ʵ���û�����ͻ�Ա����͹�������Ķ����޸� 
	(*usersptr)->busstate=0;
	UserLinkPtr previoususerPtr=(*usersptr);
	UserLinkPtr currentuserPtr=(*usersptr)->nextPtr;
	while(currentuserPtr!=NULL){
	if(currentuserPtr!=NULL)//�޸��м�ڵ� 
	currentuserPtr->busstate=0;
	previoususerPtr=currentuserPtr;
	currentuserPtr=currentuserPtr->nextPtr;
	}
//���������޸������ܵĻ�����ʵ���û�����ͻ�Ա����͹�������Ķ����޸� 
	(*vipsptr)->busstate=0;
	ServiceLinkPtr previousvipPtr=(*vipsptr);
	ServiceLinkPtr currentvipPtr=(*vipsptr)->nextPtr;
	while(currentvipPtr!=NULL){
	if(currentvipPtr!=NULL)//�޸��м�ڵ� 
	currentvipPtr->busstate=0;
	previousvipPtr=currentvipPtr;
	currentvipPtr=currentvipPtr->nextPtr;
	}
		tempPtr=currentPtr->nextPtr;
		free(currentPtr);
		currentPtr=tempPtr;
	}
} 

void deletebus(){//ɾ���೵����
int busnumber; 
int i;
int fail=1;//�ж��Ƿ������ɹ� 
	system("cls");
	system("color 0F");
	printf("***������ɾ���೵�����α��\n");
	scanf("%d",&busnumber);
	fflush(stdin);
	for(i=0;i<10;i++){
		if(busnumber==shuttle[i].number){
	shuttle[i].fee=0;//ɾ����������Ϣ 
	shuttle[i].timecome[1]=0;
	shuttle[i].timecome[0]=0;
	shuttle[i].timego[1]=0;	
	shuttle[i].timego[0]=0;	
	shuttle[i].number=0;
deletebuslink(&startbusPtr[busnumber-202101],&startPtr,&startuserPtr);
		printf("***��ɾ�����Ϊ%d�İ೵����\n",busnumber) ;
		fail=0;
		break;
		}
	}
		if(fail==1)
		{
			printf("***δ�ҵ���Ӧ�İ೵����\n");
		}
	system("pause>nul");

}

void changebus(){//�޸İ೵����	
    system("cls");
	system("color 0F");
	int changechoice; 
	int busnumber;//���α�� 
	int i;//ѭ�� 
	int fail=1;//�ж��Ƿ������ɹ� 
	printf("***�������޸İ೵�����α��\n");
	scanf("%d",&busnumber);
	fflush(stdin);
	for(i=0;i<10;i++){
		if(busnumber==shuttle[i].number){
		printf("***��ѡ���޸ĵ�����\n");
		printf("***1.�೵����\n***2.�ϰ�ʱ��\n***3.�°�ʱ��\n");
	scanf("%d",&changechoice);
	fflush(stdin);
	switch(changechoice){
		case 1:
			do {
		printf("***�������޸ĺ�ĳ˳����ã�һԪ����Ԫ��(2)��ʽ\n");
		scanf("%d",&shuttle[i].fee);
		fflush(stdin);
	}
		while(shuttle[i].fee<1||shuttle[i].fee>5);
		printf("***�޸ĳɹ����೵��Ϣ���£�\n");
	printf("***�೵��ţ�%d\n***�˳��ѣ�%dԪ\n***�ϰ�ʱ�䣺%02d:%02d\n***�°�ʱ�䣺%02d:%02d\n",shuttle[i].number,shuttle[i].fee,shuttle[i].timecome[0],
	shuttle[i].timecome[1],shuttle[i].timego[0],shuttle[i].timego[1]);
			break;
		case 2:
			do{
			printf("***�������޸ĺ�೵���ϰ�ʱ�䣨8 30����ʽ\n");
		scanf("%d %d",&shuttle[i].timecome[0],&shuttle[i].timecome[1]);
		fflush(stdin);
	}while(shuttle[i].timecome[0]<5||shuttle[i].timecome[0]>9||shuttle[i].timecome[1]<0||shuttle[i].timecome[1]>59);
	printf("***�޸ĳɹ����೵��Ϣ���£�\n");
	printf("***�೵��ţ�%d\n***�˳��ѣ�%dԪ\n***�ϰ�ʱ�䣺%02d:%02d\n***�°�ʱ�䣺%02d:%02d\n",shuttle[i].number,shuttle[i].fee,shuttle[i].timecome[0],
	shuttle[i].timecome[1],shuttle[i].timego[0],shuttle[i].timego[1]);
			break;	
		case 3:
			do{
			printf("***�������޸ĺ�೵���°�ʱ�䣨17 30����ʽ\n");
		scanf("%d %d",&shuttle[i].timego[0],&shuttle[i].timego[1]);
		fflush(stdin);
	}while(shuttle[i].timego[0]<16||shuttle[i].timego[0]>20||shuttle[i].timego[1]<0||shuttle[i].timego[1]>59);
	printf("***�޸ĳɹ����೵��Ϣ���£�\n");
	printf("***�೵��ţ�%d\n***�˳��ѣ�%dԪ\n***�ϰ�ʱ�䣺%02d:%02d\n***�°�ʱ�䣺%02d:%02d\n",shuttle[i].number,shuttle[i].fee,shuttle[i].timecome[0],
	shuttle[i].timecome[1],shuttle[i].timego[0],shuttle[i].timego[1]);
			break;	
		default:
			printf("***������Ч\n");
			break;
	}
		fail=0;
		break;
		}
	}
		if(fail==1)
		{
			printf("***δ�ҵ���Ӧ�İ೵����\n");
		}
	system("pause>nul");
}

void printplacelink(BusLinkPtr sptr){//��ӡ;�������� 
        printf("BusStation---");
		while ((sptr)!=NULL){//ѭ����ӡ�ڵ� 
		if(sptr->employeenumber>=20210000)
		printf("%s(��Ա��%d)---",sptr->placename,sptr->employeenumber);
		else if(sptr->employeenumber>=2021000)
		printf("%s(ְ����%d)---",sptr->placename,sptr->employeenumber);
		else 
		printf("%s---",sptr->placename,sptr->employeenumber);
(sptr)=(sptr)->nextPtr;
		}
		printf("ElderlyCommunity\n\n");	
}

void buslist(){//�鿴�೵�����б�
	system("cls");
	system("color 0F");
	int i;
	int nul=0; 
	printf("***�೵�б����£�\n\n");
	for(i=0;i<10;i++){
		if(shuttle[i].number!=0){
			nul=1;
	printf("***�೵��ţ�%d\n***�˳��ѣ�%dԪ\n***�ϰ�ʱ�䣺%02d:%02d\n***�°�ʱ�䣺%02d:%02d\n",shuttle[i].number,shuttle[i].fee,shuttle[i].timecome[0],
	shuttle[i].timecome[1],shuttle[i].timego[0],shuttle[i].timego[1]);
	printplacelink(startbusPtr[shuttle[i].number-202101]);
		}
	}if(nul==0){
	gotoxy(0,0);
	printf("*****�೵�б�Ϊ��\n\n");}
	system("pause>nul");
}

void addplace(BusLinkPtr *sptr,char place[20],int number){//����;���� 
		BusLinkPtr newPtr=(BusLinkPtr)malloc(sizeof(BusLink));
if(newPtr!=NULL){//�ж��Ƿ��пռ� 
	strcpy(newPtr->placename,place);//��ֵ�����ڵ�
	newPtr->employeenumber=number;//ͷβ 
	newPtr->nextPtr;//�ýڵ㲻ָ���κνڵ� 
	BusLinkPtr previousPtr=NULL;
	BusLinkPtr currentPtr=*sptr;
	while (currentPtr!=NULL&&currentPtr->placename!="ElderlyCommunity"){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;//��һ���ڵ� 
	}
	if(previousPtr==NULL){
		newPtr->nextPtr=*sptr;
		*sptr=newPtr;
	}
	else {
		previousPtr->nextPtr=newPtr;
		newPtr->nextPtr=currentPtr;
	}
} 
else {
	printf("**�ڴ��������ڵ�δ�ܴ����ɹ�\n"); 
}
}

void ways(UserLinkPtr *usersptr,ServiceLinkPtr *sptr){//����;���� 
UserLinkPtr previoususerPtr;//user���� 
UserLinkPtr currentuserPtr;
ServiceLinkPtr previousPtr;//vip���� 
ServiceLinkPtr currentPtr;
int i,result1=0;
int choice;
int identity=0;
if(power==1)identity=1;
else if(power==2)identity=2;
else if(power==3)identity=3;
int account;
	system("cls");
	system("color 0F");
	
	while(identity!=2&&identity!=1){
	printf("***��ѡ���Ա��ݻ�ְ�����\n***1.��Ա\n***2.ְ��\n");
	scanf("%d",&identity);
	fflush(stdin);
}if(identity==2){
		if(!userempty(*usersptr)){
			printf("*****������ְ���˺�\n");
	scanf("%d",&account);
	fflush(stdin);
	if(account==(*usersptr)->information.usernumber){//���������޸������ܵĻ�����ʵ���û�����ͻ�Ա�����˫���޸� 
	if(	(*usersptr)->busstate==1){
		printf("***��ְ������дԤ���������ظ���д\n");
		system("pause>nul");
		return ;
	}
	(*usersptr)->busstate=1;
		result1=1;
	}
	else {
	UserLinkPtr previoususerPtr=(*usersptr);
	UserLinkPtr currentuserPtr=(*usersptr)->nextPtr;
	while(currentuserPtr!=NULL&&currentuserPtr->information.usernumber!=account){
		previoususerPtr=currentuserPtr;
		currentuserPtr=currentuserPtr->nextPtr;
	}
	if(currentuserPtr!=NULL){//�޸��м�ڵ� 
		if(currentuserPtr->busstate==1){
		printf("***��ְ������дԤ���������ظ���д\n");
		system("pause>nul");
		return ;
	}
	currentuserPtr->busstate=1;
		result1=1;
	}
	if(result1==0) {
		printf("***δ�ҵ�ְ����Ϊ %d ��ְ��\n",account);
			system("pause>nul");
	return ;
	}}}
	else {
		printf("***ְ���б�Ϊ��\n");
			system("pause>nul");
	return ;
	}}
	else if(identity==1){
			int cn;
	if(!empty(*sptr)){
	int result=0; 
	printf("***�������Ա�Ļ�Ա�˺�\n");
	scanf("%d",&account);
	fflush(stdin);
	if(account==(*sptr)->member.vipnumber){
		if((*sptr)->busstate==1){
			printf("***�û�Ա����дԤ���������ظ���д\n");
		system("pause>nul");
		return ;
		}
		(*sptr)->busstate=1;
		result=1;
	}
	else {
	ServiceLinkPtr previousPtr=(*sptr);
	ServiceLinkPtr currentPtr=(*sptr)->nextPtr;
	while(currentPtr!=NULL&&currentPtr->member.vipnumber!=account){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
	}
	if(currentPtr!=NULL){//��ѯ�м�ڵ� 
		if(currentPtr->busstate==1){
			printf("***�û�Ա����дԤ���������ظ���д\n");
		system("pause>nul");
		return ;
		}
		currentPtr->busstate=1;
		result=1; 
	}
	}
	if(result==0) {
		printf("***δ�ҵ���Ա��Ϊ %d �Ļ�Ա\n",account);		
			system("pause>nul");
	return ;
	}}
	else {
		printf("***��Ա�б�Ϊ��\n");
					system("pause>nul");
	return ;
	}}
	char place[20];//���ڵ�Ӣ�ļ�д 
	int busnumber; 
	int fail=1;
	printf("***��ѡ��೵����\n");
scanf("%d",&busnumber);
fflush(stdin);
	for(i=0;i<10;i++){
		if(busnumber==shuttle[i].number){
		printf("***�������������ڵأ�Ӣ�ļ�д��\n");
	scanf("%s",place); 
	fflush(stdin);
addplace(&startbusPtr[busnumber-202101],place,account);
printf("***;������ӳɹ�\n");
		fail=0;
		break;
		}
	}if(fail==1)
		{
			if(identity==1){
			if(account==(*sptr)->member.vipnumber)
				(*sptr)->busstate=0;
			else currentPtr->busstate=0;
			}
			else {
			if(account==(*usersptr)->information.usernumber)
				(*usersptr)->busstate=0;
			else currentuserPtr->busstate=0;	
			}
			printf("***δ�ҵ���Ӧ�İ೵����\n");
			system("pause>nul");
	return ;
		}
	system("pause>nul");
}

 void routinemanage(char *house)//�೵·�߹��� 
{
unsigned int choicebus=10; 
	system("cls");
	system("color 0E");
	printf("    **********�������������೵����ϵͳ**********\n");
	printf("    *************��ѡ��೵�������*************\n");
	if(power==1||power==2){
		printf("    1.�鿴�೵�����б� 2.�Ͻ��೵�����᰸ 3.�������� 0.�鿴��ͼ -1.������һ����\n");
	while(choicebus!=1&&choicebus!=2&&choicebus!=0&&choicebus!=-1&&choicebus!=3){
		printf("***��ѡ�������ţ�"); 
	scanf("%d",&choicebus);
	fflush(stdin);
}
 if(choicebus==1) buslist();//�鿴�೵�����б�
else if(choicebus==2) ways(&startuserPtr,&startPtr);//����;���� 
else if(choicebus==3){writefile();//����
  writehousefile((char *)house);}//д�뷿������ 
	}
	else{
	printf("    1.�½��೵���� 2.ɾ���೵���� 3.�޸İ೵���� 4.�鿴�೵�����б�5.����;����\n    6.�������� 0.�鿴��ͼ -1.������һ����\n");
	while(choicebus!=1&&choicebus!=2&&choicebus!=3&&choicebus!=0&&choicebus!=-1&&choicebus!=4&&choicebus!=5&&choicebus!=6){
		printf("***��ѡ�������ţ�"); 
	scanf("%d",&choicebus);
	fflush(stdin);
}
if(choicebus==1) creatbus();//�½��೵���η��� 
else if(choicebus==2) deletebus();//ɾ���೵����
else if(choicebus==3) changebus();//�޸İ೵����
else if(choicebus==4) buslist();//�鿴�೵�����б�
else if(choicebus==5) ways(&startuserPtr,&startPtr);//����;���� 
else if(choicebus==6){writefile();//����
  writehousefile((char *)house);}//д�뷿������ 
}
if(choicebus==-1) return ;//���� 
else if(choicebus==0) map((char *)house);//�鿴��ͼ 
routinemanage((char *)house); 
}
 
