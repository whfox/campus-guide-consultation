#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#define INF 0x3f3f3f3f;
#define n 10
using namespace std;
const int max_v=50;
int path[max_v][max_v];
 
typedef struct      //���徰�����ơ����źͼ��
{
    char name[20];
    char code[20];
    char intro[100];
}DataType;
 
typedef struct      //������
{
    int num;
    DataType data;
}View;
 
typedef struct     //����ͼ 
{
    View view[max_v];
    int pl[max_v][max_v];
    int vexnum,arcnum;
}AMGraph;
 
void DisplayTu()   //����ƽ��ͼչʾ
{
    printf("***------------------ѧУƽ��ͼ--------------------***\n\n");
    printf("***                       �����(1)              ***\n");
    printf("***     |-------ѧԺ¥(2)---| | |--������(3)-|     ***\n");
    printf("***     |          |          |       |      |     ***\n");
    printf("***     |          |          |       |      |     ***\n");
    printf("***     |          |----ͼ���(4)-----|      |     ***\n");
    printf("***    ����(5)                        |      |     ***\n");
    printf("***     |                             |      |     ***\n");
    printf("***     |   |--������(6)  |--------��ʳ��(9) |     ***\n");
    printf("***     |   |             |                  |     ***\n");
    printf("***     һ��(7)-------����(8)------------����(10)  ***\n\n");
    printf("***------------------------------------------------***\n\n");
    system("pause");
    system("cls");
}
 
void init(AMGraph &AM){   //�������
    int i=1;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"1");
    strcpy(AM.view[i].data.name,"�����");
    strcpy(AM.view[i].data.intro,"ѧУ���棬����֮Ҫ��.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"2");
    strcpy(AM.view[i].data.name,"ѧԺ¥");
    strcpy(AM.view[i].data.intro,"��ѧԺ�칫¥������������.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"3");
    strcpy(AM.view[i].data.name,"������");
    strcpy(AM.view[i].data.intro,"����֮����δ��ȱ��.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"4");
    strcpy(AM.view[i].data.name,"ͼ���");
    strcpy(AM.view[i].data.intro,"���鴦Ҳ������ڴ�����.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"5");
    strcpy(AM.view[i].data.name,"����");
    strcpy(AM.view[i].data.intro,"��һ���ţ��ſڳ��й���.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"6");
    strcpy(AM.view[i].data.name,"������");
    strcpy(AM.view[i].data.intro,"���ͻ��飬�ݳ������.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"7");
    strcpy(AM.view[i].data.name,"һ��");
    strcpy(AM.view[i].data.intro,"����������.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"8");
    strcpy(AM.view[i].data.name,"����");
    strcpy(AM.view[i].data.intro,"��С������������������.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"9");
    strcpy(AM.view[i].data.name,"��ʳ��");
    strcpy(AM.view[i].data.intro,"�˶࣬��������.");
    i++;
    AM.view[i].num=i;
    strcpy(AM.view[i].data.code,"10");
    strcpy(AM.view[i].data.name,"����");
    strcpy(AM.view[i].data.intro,"�Ƚϴ�������������.");
    for(int j=1;j<=i;j++)            //·������
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
 
void Display(AMGraph AM){           //�г��������
    printf("������ȫ������Ĵ��źͱ��:\n\n");
    printf("����\t\t����\n");
    for(int i=1;i<=n;i++)
        printf("%s\t\t%s\n",AM.view[i].data.code,AM.view[i].data.name);
    printf("\n");
}

 /*
������Ϣ�޸ģ�
1
ͼ���
ѧУ�ı�־�Խ���֮һ.
*/
void Edit(AMGraph &AM){             //������Ϣ�޸�
    printf("��ӭ�༭������Ϣ��\n");
    Display(AM);
    printf("������Ҫ�༭�ľ���Ĵ���:\n");
    char q[20];
    cin>>q;
    int m=0;
    for(int i=1;i<=n;i++){
        if(strcmp(AM.view[i].data.code,q)==0){
            printf("�������µľ�����Ϣ��\n");
            printf("[��ʾ:���� ���š����ơ�����˳������!]\n\n");
            cin>>AM.view[i].data.code;
            cin>>AM.view[i].data.name;
            cin>>AM.view[i].data.intro;
            printf("�޸ĳɹ���\n\n");
            m++; 
        }
    }
    if(m==0){
		printf("�þ��㲻���ڣ����������룡\n");
	    }
    system("pause");
    system("cls");
}
 
void Query(AMGraph AM){     //��ѯ������Ϣ
    printf("��ӭ��ѯ������Ϣ��\n");
    Display(AM);
    printf("������Ҫ��ѯ�ľ���Ĵ��ţ�\n\n");
    char q[20];
    cin>>q;
	int m=0; 
    for(int i=1;i<=n;i++){
        if(strcmp(AM.view[i].data.code,q)==0){
            printf("�þ���ľ�����Ϣ����:\n");
            printf("����:%s\n",AM.view[i].data.name);
            printf("���:%s\n\n",AM.view[i].data.intro);
			m=1;
        }
	}
	if(m==0){
		printf("�þ��㲻���ڣ����������룡\n");
	    }
    system("pause");
    system("cls");
	
}
 
void ShortestPath(AMGraph AM){       //Ѱ�����·��
    printf("��ӭ��ѯ����·����\n");
    Display(AM);
    printf("������Ҫ��ѯ��������ı��:\n");
    int a,b;
    scanf("%d%d",&a,&b);
    
	if(a>10||b>10){
	printf("�þ��㲻����,���������룡\n");
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
    printf("����ѯ�ľ��� %s �� %s ֮������·��Ϊ:\n",AM.view[a].data.name,AM.view[b].data.name);
    while(a!=b){
        printf("%s->",AM.view[a].data.name);
        t=a;
        a=path[a][b];
        sum+=AM.pl[t][a];
    } 
    printf("%s\n\n",AM.view[b].data.name);
    printf("������֮���·������Ϊ:%dm\n\n",sum);
    system("pause");
    system("cls");
    }
}
 
void Menu(){                  //���ܲ˵�
    printf("--------У԰������ѯ--------\n\n");
        printf("       1.����ƽ��ͼչʾ.\n");
        printf("       2.������Ϣ�޸�.\n");
        printf("       3.������Ϣ��ѯ.\n");
        printf("       4.����·����ѯ.\n");
        printf("       5.�˳�.\n\n");
        printf("           ����ߣ�xxx\n");
        printf("------------------------------\n\n");
}
 
int main()
{
    AMGraph AM;
    init(AM);
    while(1){
        Menu();
        printf("��ѡ����:\n");
        int a;
        scanf("%d",&a);
        if(a==5){
            printf("---------------------\n");
            printf("ллʹ�ã���;��죡\n");
            printf("---------------------\n");
            break;
        }
        else if(a!=1&&a!=2&&a!=3&&a!=4){
            printf("��������ѡ�񲻷���Ҫ�����������룡\n");
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
�޸ģ�
1
ͼ���
ѧУ�ı�־�Խ���֮һ.
*/
 
 
 
 
