#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#define INF 0x3f3f3f3f;
#define n 10
using namespace std;
const int max_v=50;
int path[max_v][max_v];
 
typedef struct      //定义景点名称、代号和简介
{
    char name[20];
    char code[20];
    char intro[100];
}DataType;
 
typedef struct      //定义编号
{
    int num;
    DataType data;
}View;
 
typedef struct     //定义图 
{
    View view[max_v];
    int pl[max_v][max_v];
    int vexnum,arcnum;
}AMGraph;
 
void DisplayTu()   //景点平面图展示
{
    printf("***------------------学校平面图--------------------***\n\n");
    printf("***                       矿大东门(1)              ***\n");
    printf("***     |-------学院楼(2)---| | |--公教区(3)-|     ***\n");
    printf("***     |          |          |       |      |     ***\n");
    printf("***     |          |          |       |      |     ***\n");
    printf("***     |          |----图书馆(4)-----|      |     ***\n");
    printf("***    北门(5)                        |      |     ***\n");
    printf("***     |                             |      |     ***\n");
    printf("***     |   |--体育馆(6)  |--------二食堂(9) |     ***\n");
    printf("***     |   |             |                  |     ***\n");
    printf("***     一运(7)-------二运(8)------------三运(10)  ***\n\n");
    printf("***------------------------------------------------***\n\n");
    system("pause");
    system("cls");
}
 
void init(AMGraph &AM){   //景点介绍
    int i=1;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"1");
    strcpy(AM.view[i].data.name,"矿大东门");
    strcpy(AM.view[i].data.intro,"学校排面，出入之要塞.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"2");
    strcpy(AM.view[i].data.name,"学院楼");
    strcpy(AM.view[i].data.intro,"各学院办公楼，繁杂事务处理.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"3");
    strcpy(AM.view[i].data.name,"公教区");
    strcpy(AM.view[i].data.intro,"书修之处，未尝缺人.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"4");
    strcpy(AM.view[i].data.name,"图书馆");
    strcpy(AM.view[i].data.intro,"藏书处也，亦可于此自修.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"5");
    strcpy(AM.view[i].data.name,"北门");
    strcpy(AM.view[i].data.intro,"另一大门，门口常有公交.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"6");
    strcpy(AM.view[i].data.name,"体育馆");
    strcpy(AM.view[i].data.intro,"大型会议，演出或比赛.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"7");
    strcpy(AM.view[i].data.name,"一运");
    strcpy(AM.view[i].data.intro,"最大的体育场.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"8");
    strcpy(AM.view[i].data.name,"二运");
    strcpy(AM.view[i].data.intro,"最小的体育场，旁有篮球场.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"9");
    strcpy(AM.view[i].data.name,"二食堂");
    strcpy(AM.view[i].data.intro,"人多，物美价廉.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"10");
    strcpy(AM.view[i].data.name,"三运");
    strcpy(AM.view[i].data.intro,"比较大，旁有网球、篮球场.");
    for(int j=1;j<=i;j++)            //路径输入
        for(int k=1;k<=i;k++){
            if(k==j)
                AM.pl[j][k]=0;
            else
                AM.pl[j][k]=INF;
            path[j][k]=k;
        }
    AM.pl[1][2]=AM.pl[2][1]=460;
    AM.pl[1][3]=AM.pl[3][1]=400;
    AM.pl[1][4]=AM.pl[4][1]=730;
    AM.pl[2][4]=AM.pl[4][2]=340;
    AM.pl[2][5]=AM.pl[5][2]=820;
    AM.pl[3][4]=AM.pl[4][3]=400;
    AM.pl[3][9]=AM.pl[9][3]=500;
    AM.pl[3][10]=AM.pl[10][3]=1000;
    AM.pl[5][7]=AM.pl[7][5]=530;
    AM.pl[6][7]=AM.pl[7][6]=130;
    AM.pl[7][8]=AM.pl[8][7]=450;
    AM.pl[8][9]=AM.pl[9][8]=550;
    AM.pl[8][10]=AM.pl[10][8]=850;
}
 
void Display(AMGraph AM){           //列出景点代号
    printf("以下是全部景点的代号和编号:\n\n");
    printf("代号\t\t名称\n");
    for(int i=1;i<=n;i++)
        printf("%s\t\t%s\n",AM.view[i].data.code,AM.view[i].data.name);
    printf("\n");
}

 /*
景点信息修改：
1
图书馆
学校的标志性建筑之一.
*/
void Edit(AMGraph &AM){             //景点信息修改
    printf("欢迎编辑景点信息！\n");
    Display(AM);
    printf("请输入要编辑的景点的代号:\n");
    char q[20];
    cin>>q;
    int m=0;
    for(int i=1;i<=n;i++){
        if(strcmp(AM.view[i].data.code,q)==0){
            printf("请输入新的景点信息：\n");
            printf("[提示:按照 代号、名称、介绍顺序输入!]\n\n");
            cin>>AM.view[i].data.code;
            cin>>AM.view[i].data.name;
            cin>>AM.view[i].data.intro;
            printf("修改成功！\n\n");
            m++; 
        }
    }
    if(m==0){
		printf("该景点不存在，请重新输入！\n");
	    }
    system("pause");
    system("cls");
}
 
void Query(AMGraph AM){     //查询景点信息
    printf("欢迎查询景点信息！\n");
    Display(AM);
    printf("请输入要查询的景点的代号：\n\n");
    char q[20];
    cin>>q;
	int m=0; 
    for(int i=1;i<=n;i++){
        if(strcmp(AM.view[i].data.code,q)==0){
            printf("该景点的具体信息如下:\n");
            printf("名称:%s\n",AM.view[i].data.name);
            printf("简介:%s\n\n",AM.view[i].data.intro);
			m=1;
        }
	}
	if(m==0){
		printf("该景点不存在，请重新输入！\n");
	    }
    system("pause");
    system("cls");
	
}
 
void ShortestPath(AMGraph AM){       //寻找最短路径
    printf("欢迎查询景点路径！\n");
    Display(AM);
    printf("请输入要查询的两景点的编号:\n");
    int a,b;
    scanf("%d%d",&a,&b);
    
	if(a>10||b>10){
	printf("该景点不存在,请重新输入！\n");
	}
   else
    {
	 for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(AM.pl[i][k]+AM.pl[j][k]<AM.pl[i][j]){
                    AM.pl[i][j]=AM.pl[i][k]+AM.pl[j][k];
                    path[i][j]=path[i][k];
                }
            }
    int sum=0,t;
    printf("您查询的景点 %s 到 %s 之间的最短路径为:\n",AM.view[a].data.name,AM.view[b].data.name);
    while(a!=b){
        printf("%s->",AM.view[a].data.name);
        t=a;
        a=path[a][b];
        sum+=AM.pl[t][a];
    } 
    printf("%s\n\n",AM.view[b].data.name);
    printf("两景点之间的路径长度为:%dm\n\n",sum);
    system("pause");
    system("cls");
    }
}
 
void Menu(){                  //功能菜单
    printf("--------校园导游咨询--------\n\n");
        printf("       1.景点平面图展示.\n");
        printf("       2.基本信息修改.\n");
        printf("       3.景点信息查询.\n");
        printf("       4.景点路径查询.\n");
        printf("       5.退出.\n\n");
        printf("           设计者：xxx\n");
        printf("------------------------------\n\n");
}
 
int main()
{
    AMGraph AM;
    init(AM);
    while(1){
        Menu();
        printf("请选择功能:\n");
        int a;
        scanf("%d",&a);
        if(a==5){
            printf("---------------------\n");
            printf("谢谢使用！旅途愉快！\n");
            printf("---------------------\n");
            break;
        }
        else if(a!=1&&a!=2&&a!=3&&a!=4){
            printf("您的输入选择不符合要求，请重新输入！\n");
            continue;
        }
        switch(a){
            case 1:DisplayTu();break;
            case 2:Edit(AM);break;
            case 3:Query(AM);break;
            case 4:ShortestPath(AM);break;
        }
    }
    return 0;
}
 
/*
修改：
1
图书馆
学校的标志性建筑之一.
*/
 
 
 
 
