#include<stdio.h>
#include<string.h>
#include<windows.h>
#define SCMAX  6/*ÿ��ѡ�������Ŀ-1*/
#define TEMAX  4 /*��ʦ�̵ܽ����γ���Ŀ-1*/
#define STU 1000/*���ѧ������*/
#define CNO 200  /*�γ������Ŀ*/
#define Tea 200   /*��ʦ�����*/
#define CPMAX  80 /*�涨ÿ�ſ��������ֵ*/
struct Course{
	int Cno;/*�γ̺�*/
	char  Cname[20];/*�γ���*/
	double time;/*�Ͽ�ʱ��*/
	char  place[20];/*�Ͽεص�*/
	char  teacher[10];/*�Ͽ���ʦ*/
	int Tno;  /*��ʦ���*/
	int  pn ; /*ѧ������*/
}Cou[CPMAX]={ 
	{1,"��ѧ",109.40, "5#5110", "����",1,4},
	{2,"����",210.30,"6#6110", "����",2,1},
	{3,"Ӣ��",307.30, "15#15217","����",3,1},
	{4,"����",715.40,"6#6510",  "����",1,4},
	{5,"������",10.00,"8#8321","����",2,0},
	{6,"������Ϸ",10.00,"5#5310","����",3,0}
	};  /*�γ̳�ʼ�� �γ̱�š��Ͽ�ʱ�䡢�Ͽεص㡢��ʦ����ʦ��š��γ�����*/
                                   
struct STUDENT{
	int no;
	char Sname[10];
}S[6]={{1,"������"},{2,"����"},{3,"������"},{4,"������"},{5,"��˹"},{6,"˾����"}};

int Student[STU][SCMAX]={{1,1,0,0,0},{2,1,0,0,0},{3,3,0,0,0},{4,1,2,3,4},{5,1,0,0,0} ,{6,0,0,0,0}}; 
int Teacher[Tea][SCMAX]={{1,1,4,0,0},{2,2,5,0,0},{3,3,6,0,0}};   
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++ѧ��++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void student();
void manger();
void jiemian();
void Add();
void change();
void select(int XH);
void DropC(int XH) ; 
void teacher();
void manger();
void search(int XH)                                  /*�γ̲�ѯ*/
	{
		int j,i;
		char k[10];
		printf("����ѡ��Ŀγ�Ϊ��\n");
		printf("�γ̺�   �γ���  �Ͽ�ʱ��  �Ͽεص�   �Ͽ���ʦ  ��ʦ���   �γ�����\n");
		for(j=1;j<=4;j++)
		{
			if(Student[XH][j]==0) printf("��\n");
		    else
			{
				printf("%3d %10s %9.2f  ",Cou[Student[XH][j]-1].Cno,Cou[Student[XH][j]-1].Cname,Cou[Student[XH][j]-1].time);
				printf(" %7s %8s %9d %9d\n",Cou[Student[XH][j]-1].place,Cou[Student[XH][j]-1].teacher,Cou[Student[XH][j]-1].Tno,Cou[Student[XH][j]-1].pn);
				
			}        /*�������ѯ�Ŀγ�*/
		}
		printf("���������\n");
		scanf("%s",&k);
		system("cls");
	    printf("%s��ӭ������\n",S[XH].Sname);
    	system("color 80");
   printf("                  ################################################\n");
   printf("                  #                                              #\n");
   printf("                  #                                              #\n");
   printf("                  #             1 ѡ�β�ѯ                       #\n");
   printf("                  #                                              #\n");
   printf("                  #             2 ѡ��                           #\n");
   printf("                  #                                              #\n");
   printf("                  #             3 ѡ����ѡ                       #\n");
   printf("                  #                                              #\n");
   printf("                  #                                              #\n");
   printf("                  #                                    B����     #\n");
   printf("                  ################################################\n");
    	scanf("%d",&i);
    	if(i==1)      {system("cls");search(XH);}
        else if(i==2) {system("cls");select(XH);}
    	else if(i==3) {system("cls");DropC(XH); }
    	else 
		{
		system("cls");
		jiemian();
		}	
	}

void  select(int XH)            /*ѡ��*/
{      
 leap1: system("color 70");
        int cn,i,j,Cn,k;
		int p=0;
		char t[20];
		printf("�γ̺�   �γ���  �Ͽ�ʱ��  �Ͽεص�   �Ͽ���ʦ  ��ʦ���   �γ�����\n"); /*���*/
		for(k=0;k<=CPMAX;k++) /*���*/
		{
			if(Cou[k].Cno==0) break;
		}
		for(i=0;i<k;i++)
		{
			printf("%3d %10s %9.2f",Cou[i].Cno,Cou[i].Cname,Cou[i].time);
			printf(" %10s %8s %9d %9d\n",Cou[i].place,Cou[i].teacher,Cou[i].Tno,Cou[i].pn);
		}   /*���*/
	
		printf("������γ����\n");
		scanf("%d",&cn);
		Cn=cn-1;

        if(Cou[Cn].Cno==0) 
		{
		   printf("�ÿγ̲�����\n");
	       printf("�Ƿ����ѡ��? 1 ��  2  ��\n");
		   scanf("%d",&j);
		   if(j==1) {system("cls");goto leap1;} 
		}
		else if(Cn<CNO&&Cn>=0)
		{
			printf("�γ̺�   �γ���  �Ͽ�ʱ��  �Ͽεص�   �Ͽ���ʦ  ��ʦ���   �γ�����\n");
			printf("%3d %10s %9.2f",Cou[Cn].Cno,Cou[Cn].Cname,Cou[Cn].time);
			printf(" %10s %8s %9d %9d\n",Cou[Cn].place,Cou[Cn].teacher,Cou[Cn].Tno,Cou[Cn].pn);
			printf("�Ƿ�ѡ��ÿγ�? 1 �� 2 ��\n");
			scanf("%d",&j);
			if(j==1)
			{
					for(j=1;j<(SCMAX-1);j++)	/*+++++++++++++++++++++++++++*/
				{
					if(Student[XH][j]==cn) p=1;
				}
				if(p==1) 
				{
					printf("���ſγ��Ѿ�ѡ����\n");
					printf("�Ƿ�����ѡ�Σ�1 �� 2 ��\n");
					scanf("%d",&i);
					if(i==1) {system("cls");goto leap1;}
				}
				else if(Student[XH][SCMAX-1]>0) 
				{
					printf("����ѡ�γ����������ٽ���ѡ��\n");
			        
				}

				else if(Cou[Cn].pn==CPMAX)  
				{
					printf("���ſ���������");
					printf("�Ƿ�����ѡ�Σ�1 �� 2 ��\n");
					scanf("%d",&i);
					if(i==1) {system("cls");goto leap1;}   /*1111*/
				}
				else
				{
					if(Student[XH][1]==0) Student[XH][1]=Cou[Cn].Cno;
					else if(Student[XH][2]==0) Student[XH][2]=Cou[Cn].Cno;
					else if(Student[XH][3]==0) Student[XH][3]=Cou[Cn].Cno;
					else
						Student[XH][4]=Cou[Cn].Cno;
					    Cou[Cn].pn=Cou[Cn].pn+1;
					    printf("ѡ�γɹ���\n");
					    printf("�Ƿ����ѡ��? 1 ��  2  ��\n");
		                scanf("%d",&j);
		            if(j==1) {system("cls");goto leap1;} 

				}
			}
			else
			{
                 printf("�Ƿ����ѡ��? 1 ��  2  ��\n");
		         scanf("%d",&j);
	             if(j==1) {system("cls");goto leap1;}
			}
		}
	else 
	{
		printf("�ÿγ̲�����\n");
		printf("�Ƿ����ѡ��? 1 ��  2  ��\n");
		scanf("%d",&j);
		if(j==1) {system("cls");goto leap1;}
	}
	printf("���������\n");
	scanf("%s",&t);
	system("cls");
	printf("%s��ӭ������\n",S[XH].Sname);
	system("color 80");
	printf("                  ################################################\n");
	printf("                  #                                              #\n");
	printf("                  #                                              #\n");
    printf("                  #             1 ѡ�β�ѯ                       #\n");
	printf("                  #                                              #\n");
	printf("                  #             2 ѡ��                           #\n");
	printf("                  #                                              #\n");
	printf("                  #             3 ѡ����ѡ                       #\n");
	printf("                  #                                              #\n");
	printf("                  #                                              #\n");
	printf("                  #                                    B����     #\n");
	printf("                  ################################################\n");
	scanf("%d",&i);
	if(i==1)      {system("cls");search(XH);}
    else if(i==2) {system("cls");select(XH);}
	else if(i==3) {system("cls");DropC(XH); }
	else 
	{
		system("cls");
	    jiemian();
	}
	
}

void DropC(int XH)   /*�γ���ѡ*/
	{
leap2:  int i,j,k;
		char l[20];
		int m=0;
		printf("����ѡ��Ŀγ�Ϊ��\n");
		printf("�γ̺�   �γ���  �Ͽ�ʱ��  �Ͽεص�   �Ͽ���ʦ  ��ʦ���   �γ�����\n");
		for(j=1;j<=4;j++)
		{
			if(Student[XH][j]==0) printf("��\n");
		    else
			{
				printf("%3d %10s %9.2f  ",Cou[Student[XH][j]-1].Cno,Cou[Student[XH][j]-1].Cname,Cou[Student[XH][j]-1].time);
				printf(" %7s %8s %9d %9d\n",Cou[Student[XH][j]-1].place,Cou[Student[XH][j]-1].teacher,Cou[Student[XH][j]-1].Tno,Cou[Student[XH][j]-1].pn);
				
			}        /*�������ѯ�Ŀγ�*/
		}

		printf("��������ѡ�Ŀγ̺�:\n");
		scanf("%d",&i);
		if(i>CNO||i<0) 
		{
			printf("��������\n");
			goto leap2;
		}
		else if(Cou[i-1].Cno==0){
			printf("�ÿγ̲�����\n");
			printf("�Ƿ�������ѡ�γ̣�1 �� 2 ��\n");
			scanf("%d",&k);
			if(k==1) {system("cls"); goto leap2;}
		}
		else
		{
		for(j=1;j<=4;j++)
		{
			if(Student[XH][j]==Cou[i-1].Cno) {m=1;break;}
		}
		if(m==1) 
		{
			Student[XH][j]=0; 
			Cou[i-1].pn=Cou[i-1].pn-1;
			printf("��ѡ�ɹ���\n");
			printf("�Ƿ������ѡ�γ�? 1��  2 ��\n");
			scanf("%d",&k);
			if(k==1) {system("cls"); goto leap2;}
		}
		else
		{
			printf("�㻹ûѡ�����ſγ�\n");

            printf("�Ƿ�������ѡ�γ̣�1 �� 2 ��\n");
			scanf("%d",&k);
			if(k==1) {system("cls"); goto leap2;}
		
		}

	}
	printf("���������\n");
	scanf("%d",l);
	system("cls");
	printf("%s��ӭ������\n",S[XH].Sname);
	system("color 80");
	printf("                  ################################################\n");
	printf("                  #                                              #\n");
	printf("                  #                                              #\n");
    printf("                  #             1 ѡ�β�ѯ                       #\n");
	printf("                  #                                              #\n");
	printf("                  #             2 ѡ��                           #\n");
	printf("                  #                                              #\n");
	printf("                  #             3 ѡ����ѡ                       #\n");
	printf("                  #                                              #\n");
	printf("                  #                                              #\n");
	printf("                  #                                    B����     #\n");
	printf("                  ################################################\n");
	scanf("%d",&i);
	if(i==1)      {system("cls");search(XH); }
    else if(i==2) {system("cls");select(XH); }
	else if(i==3) {system("cls");DropC(XH);}
	else 
	{
		system("cls");
		jiemian();
	}
	}

 void student()
{
	int xh,i;
leap7: printf("�������˺�:\n");
	scanf("%d",&xh);
	if(xh>6||xh<1) { printf("�����������������\n"); goto leap7;}
	else{
	system("cls");
	printf("%s��ӭ������\n",S[xh-1].Sname);
	system("color 80");
	printf("                  ################################################\n");
	printf("                  #                                              #\n");
	printf("                  #                                              #\n");
    printf("                  #             1 ѡ�β�ѯ                       #\n");
	printf("                  #                                              #\n");
	printf("                  #             2 ѡ��                           #\n");
	printf("                  #                                              #\n");
	printf("                  #             3 ѡ����ѡ                       #\n");
	printf("                  #                                              #\n");
	printf("                  #                                              #\n");
	printf("                  #                                    B����     #\n");
	printf("                  ################################################\n");
	scanf("%d",&i);
	if(i==1)      {system("cls");search(xh-1);}
    else if(i==2) {system("cls");select(xh-1);}
	else if(i==3) {system("cls");DropC(xh-1); }
	else 
	{
		system("cls");
		jiemian();
	}
	}
	}
/*++++++++++++++++++++++++++++++++++++++++++++++++ѧ��++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++��ʦ++++++++++++++++++++++++++++++++++++++++++++++++*/
void teacher()                /*��ʦ*/
	{/*f*/
leap3:	int BH,bh,i,j,d,m;
		char l[20];
		int k=0;
     	printf("�������˺ţ�\n");
		scanf("%d",&bh);
		if(bh>6||bh<1) { printf("�����������������\n"); goto leap3;}
	    else{
		BH=bh-1;
		if(BH>CNO||BH<0) 
		{
			printf("��������\n");
			goto leap3;
		}
		else
		{/*kk*/
			printf("�����̵�ѡ�޿��У�\n");
			printf("�γ̺�   �γ���  �Ͽ�ʱ��  �Ͽεص�   �Ͽ���ʦ  ��ʦ���   �γ�����\n");
			for(i=1;i<=TEMAX;i++)
			{	printf("%3d %10s %9.2f ",Cou[Teacher[BH][i]-1].Cno,Cou[Teacher[BH][i]-1].Cname,Cou[Teacher[BH][i]-1].time);
			    printf(" %10s %8s %9d %9d\n",Cou[Teacher[BH][i]-1].place,Cou[Teacher[BH][i]-1].teacher,Cou[Teacher[BH][i]-1].Tno,Cou[Teacher[BH][i]-1].pn);
			}
            printf("��ʾ���̿γ�ѧ��������1 �� 2 ��\n");
			scanf("%d",&j);
			if(j==1)
			{
	leap4: 	  printf("������γ̺�\n");
			  scanf("%d",&j);
			  if(j>CNO||j<1) { printf("�������\n"); goto leap4; }
			else if(Cou[j-1].Cno!=0)
			{/*ff*/
				i=1;
				while(i<4)
				{
					if(j==Teacher[BH][i])
					{
						m=1;
						i++;
					}
					else
						i++;
				}
				if(m==0) { printf("��û�н̸��ſ�\n"); goto leap4; }
				else
				{
			
					printf("ѡ�޸��ſγ̵�ѧ����:\n");
					for(i=0;i<=5;i++)
						for(d=1;d<5;d++)
						{
							if(j==Student[i][d])
								printf("%3d %s\n",S[i].no,S[i].Sname);
						}
				}
			}
			}
			}
		
		printf("�����������\n");
		scanf("%s",l);
		system("cls");
		jiemian();

		}
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++��ʦ+++++++++++++++++++++++++++++++++++++++++++++++++++/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++����Ա+++++++++++++++++++++++++++++++++++++++++++++++++*/


void Delete()  /*�Կγ̽���ɾ��*/
		{
leap5:      int i,j;
			char l[20];
			printf("������Ҫɾ���Ŀγ̵Ŀγ̺�:\n");
            scanf("%d",&i);
			if(i<1||i>CNO)  {printf("�������\n"); goto leap5;}
			else if(Cou[i-1].Cno==0) {
				printf("�ÿγ̲�����\n");
				printf("�Ƿ����ɾ���γ�? 1 ��  2��\n");
				scanf("%d",&j);
				if(j==1){system("cls"); goto leap5;}
			}
			else
			{
				printf("����ɾ�����Ժ�\n");
				memset(&Cou[i-1],0,sizeof(struct Course));
				printf("ɾ���ɹ���\n");
				printf("�Ƿ����ɾ���γ�? 1 ��  2��\n");
				scanf("%d",&j);
				if(j==1){system("cls"); goto leap5;}
			}
			printf("���������\n");
			scanf("%s",&l);
			system("cls");
	        printf("                  ################################################\n");
        	printf("                  #                 ����Ա                       #\n");
        	printf("                  #                                              #\n");
            printf("                  #              1 ���ӿγ�                      #\n");
        	printf("                  #                                              #\n");
        	printf("                  #              2 ɾ���γ�                      #\n");
        	printf("                  #                                              #\n");
        	printf("                  #              3 �޸Ŀγ�                      #\n");
        	printf("                  #                                              #\n");
        	printf("                  #                                              #\n");
        	printf("                  #                                   B����      #\n");
        	printf("                  ################################################\n");
        	scanf("%d",&i);
         	if(i==1) {system("cls");Add();}
        	else if(i==2) {system("cls");Delete();}
        	else if(i==3) {system("cls");change();}
        	else
			{system("cls");jiemian();}
			
}

void	change()  /*�Կγ̽����޸�*/
		{
	char l[20];
leap6:      int i,j,m,d;
			int k=0;
			printf(" ������Ҫ�޸ĵĿγ̵Ŀγ̺�:\n");
			scanf("%d",&i);
			if(i<1||i>CNO)  {printf("�������\n"); goto leap6;}
			else if(Cou[i-1].Cno==0) {printf("�ÿγ̲�����\n"); goto leap6;}
            else
			{
				int cno;
              	char  cname[20];
	            float Time;
             	char  Place[20];
	            char  Teacher[10];
             	int tno;  
	 
				printf("�����ΰ�' �γ̺�   �γ���  �Ͽ�ʱ��  �Ͽεص�   �Ͽ���ʦ  ��ʦ���'  ����:\n");
				scanf("%d",&cno);
			    scanf("%s",&cname);
				scanf("%f",&Time);
				scanf("%s",&Place);
				scanf("%s",&Teacher);
				scanf("%d",&tno);
				for(j=0;j<CNO;j++)
				{
					if(Cou[j].Cno==0) break;
				}
				m=j;
				for(j=0;j<m;j++)
				{
					if(Cou[j].time==Time&&strcmp(Cou[j].place,Place)==0) {k=1;break;}
					
				}
				if(k==1) {printf("������������޸ĵĿγ������γ��г�ͻ\n");goto leap6;}
				else
				{
					
					Cou[i-1].Cno=cno;
					strcpy(Cou[i-1].Cname,cname);
					Cou[i-1].time=Time;
					strcpy(Cou[i-1].place,Place);
					strcpy(Cou[i-1].teacher,Teacher);
					Cou[i-1].Tno=tno;
					printf("�޸ĳɹ���\n");
					printf("�����޸Ŀγ̣� 1��  2��\n");
					scanf("%d",&d);
					if(d==1){system("cls"); goto leap6;}
		
				}
			}
						printf("���������\n");
			scanf("%s",&l);
			system("cls");
	printf("                  ################################################\n");
	printf("                  #                 ����Ա                       #\n");
	printf("                  #                                              #\n");
    printf("                  #              1 ���ӿγ�                      #\n");
	printf("                  #                                              #\n");
	printf("                  #              2 ɾ���γ�                      #\n");
	printf("                  #                                              #\n");
	printf("                  #              3 �޸Ŀγ�                      #\n");
	printf("                  #                                              #\n");
	printf("                  #                                              #\n");
	printf("                  #                                   B����      #\n");
	printf("                  ################################################\n");
	scanf("%d",&i);
	if(i==1) {system("cls");Add();}
	else if(i==2) {system("cls");Delete();}
	else if(i==3) {system("cls");change();}
	else
	{system("cls");jiemian();}
			
}

void	Add()  /*���ӿγ�*/
			{
	            char l[20];
leap7:      	int i,m,d,j,k;
				int cno;
              	char  cname[20];
	            double Time;
             	char  Place[20];
	            char  Teacher[10];
             	int tno;  
				printf("������ÿγ̵Ŀγ̺�:\n");
                scanf("%d",&i);
				if(Cou[i-1].Cno!=0) {printf("�ÿγ̺��Ѿ�����\n");goto leap7;}
				else if(i<1||i>CNO) {printf("��������\n");goto leap7;}
				else
				{
				    printf("�����ΰ�    �γ���  �Ͽ�ʱ��  �Ͽεص�   �Ͽ���ʦ  ��ʦ���   �γ����� ����:\n");
				scanf("%d",&cno);
			    scanf("%s",&cname);
				scanf("%f",&Time);
				scanf("%s",&Place);
				scanf("%s",&Teacher);
				scanf("%d",&tno);
				for(j=0;j<CNO;j++)
				{
					if(Cou[j].Cno==0) break;
				}
				m=j;
				for(j=0;j<m;j++)
				{
					if(Cou[j].time==Time&&strcmp(Cou[j].place,Place)==0) k=1;
					if(k==1) break;
					
				}
				if(k==1) {printf("��������������ӵĿγ��������γ��г�ͻ\n");goto leap7;}
				else
				{
					
					Cou[i-1].Cno=(i-1);
					strcpy(Cou[i-1].Cname,cname);
					Cou[i-1].time=Time;
					strcpy(Cou[i-1].place,Place);
					strcpy(Cou[i-1].teacher,Teacher);
					Cou[i-1].Tno=tno;
					Cou[i-1].pn=0;
					printf("���ӿγ̳ɹ���\n");
					printf("�������ӿγ̣� 1��  2��\n");
					scanf("%d",&d);
					if(d==1){system("cls"); goto leap7;}
		
				}
				}
							printf("���������\n");
			scanf("%s",&l);
			system("cls");
	printf("                  ################################################\n");
	printf("                  #                 ����Ա                       #\n");
	printf("                  #                                              #\n");
    printf("                  #              1 ���ӿγ�                      #\n");
	printf("                  #                                              #\n");
	printf("                  #              2 ɾ���γ�                      #\n");
	printf("                  #                                              #\n");
	printf("                  #              3 �޸Ŀγ�                      #\n");
	printf("                  #                                              #\n");
	printf("                  #                                              #\n");
	printf("                  #                                   B����      #\n");
	printf("                  ################################################\n");
	scanf("%d",&i);
	if(i==1) {system("cls");Add();}
	else if(i==2) {system("cls");Delete();}
	else if(i==3) {system("cls");change();}
	else
	{system("cls");jiemian();}
			}
void manger()
{
	int i;
	system("color 80");
	printf("                  ################################################\n");
	printf("                  #                 ����Ա                       #\n");
	printf("                  #                                              #\n");
    printf("                  #              1 ���ӿγ�                      #\n");
	printf("                  #                                              #\n");
	printf("                  #              2 ɾ���γ�                      #\n");
	printf("                  #                                              #\n");
	printf("                  #              3 �޸Ŀγ�                      #\n");
	printf("                  #                                              #\n");
	printf("                  #                                              #\n");
	printf("                  #                                   B����      #\n");
	printf("                  ################################################\n");
	scanf("%d",&i);
	if(i==1) {system("cls");Add();}
	else if(i==2) {system("cls");Delete();}
	else if(i==3) {system("cls");change();}
	else
	{system("cls");jiemian();}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++����Ա+++++++++++++++++++++++++++++++++++++++++++++++++*/
void jiemian()
{
	int i;
	system("color 80");
	printf("                  ################################################\n");
	printf("                  #              ѧ��ѡ��ϵͳ                    #\n");
	printf("                  #                                              #\n");
    printf("                  #              1 ѧ�����                      #\n");
	printf("                  #                                              #\n");
	printf("                  #              2 ��ʦ���                      #\n");
	printf("                  #                                              #\n");
	printf("                  #              3 ����Ա���                    #\n");
	printf("                  #                                              #\n");
	printf("                  #                                              #\n");
	printf("                  #                                    �˳�      #\n");
	printf("                  ################################################\n");
	scanf("%d",&i);
	if(i==1) {system("cls");student();}
	else if(i==2) {system("cls");teacher();}
	else if(i==3)        {system("cls");	manger();}

}
int main()
{
	jiemian();
	return 0;
}

