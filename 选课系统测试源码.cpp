#include<stdio.h>
#include<string.h>
#include<windows.h>
#define SCMAX  6/*每人选课最大数目-1*/
#define TEMAX  4 /*老师能教的最大课程数目-1*/
#define STU 1000/*最大学生人数*/
#define CNO 200  /*课程最大数目*/
#define Tea 200   /*老师最大编号*/
#define CPMAX  80 /*规定每门课人数最大值*/
struct Course{
	int Cno;/*课程号*/
	char  Cname[20];/*课程名*/
	double time;/*上课时间*/
	char  place[20];/*上课地点*/
	char  teacher[10];/*上课老师*/
	int Tno;  /*老师编号*/
	int  pn ; /*学生人数*/
}Cou[CPMAX]={ 
	{1,"数学",109.40, "5#5110", "张三",1,4},
	{2,"语文",210.30,"6#6110", "李四",2,1},
	{3,"英语",307.30, "15#15217","王五",3,1},
	{4,"经济",715.40,"6#6510",  "张三",1,4},
	{5,"防身术",10.00,"8#8321","李四",2,0},
	{6,"电脑游戏",10.00,"5#5310","王五",3,0}
	};  /*课程初始化 课程编号、上课时间、上课地点、老师、老师编号、课程人数*/
                                   
struct STUDENT{
	int no;
	char Sname[10];
}S[6]={{1,"尹新荣"},{2,"李明"},{3,"刘文骁"},{4,"刘成立"},{5,"艾斯"},{6,"司丽芳"}};

int Student[STU][SCMAX]={{1,1,0,0,0},{2,1,0,0,0},{3,3,0,0,0},{4,1,2,3,4},{5,1,0,0,0} ,{6,0,0,0,0}}; 
int Teacher[Tea][SCMAX]={{1,1,4,0,0},{2,2,5,0,0},{3,3,6,0,0}};   
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++学生++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void student();
void manger();
void jiemian();
void Add();
void change();
void select(int XH);
void DropC(int XH) ; 
void teacher();
void manger();
void search(int XH)                                  /*课程查询*/
	{
		int j,i;
		char k[10];
		printf("您已选择的课程为：\n");
		printf("课程号   课程名  上课时间  上课地点   上课老师  老师编号   课程人数\n");
		for(j=1;j<=4;j++)
		{
			if(Student[XH][j]==0) printf("空\n");
		    else
			{
				printf("%3d %10s %9.2f  ",Cou[Student[XH][j]-1].Cno,Cou[Student[XH][j]-1].Cname,Cou[Student[XH][j]-1].time);
				printf(" %7s %8s %9d %9d\n",Cou[Student[XH][j]-1].place,Cou[Student[XH][j]-1].teacher,Cou[Student[XH][j]-1].Tno,Cou[Student[XH][j]-1].pn);
				
			}        /*输出所查询的课程*/
		}
		printf("任意键返回\n");
		scanf("%s",&k);
		system("cls");
	    printf("%s欢迎回来！\n",S[XH].Sname);
    	system("color 80");
   printf("                  ################################################\n");
   printf("                  #                                              #\n");
   printf("                  #                                              #\n");
   printf("                  #             1 选课查询                       #\n");
   printf("                  #                                              #\n");
   printf("                  #             2 选课                           #\n");
   printf("                  #                                              #\n");
   printf("                  #             3 选课退选                       #\n");
   printf("                  #                                              #\n");
   printf("                  #                                              #\n");
   printf("                  #                                    B返回     #\n");
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

void  select(int XH)            /*选课*/
{      
 leap1: system("color 70");
        int cn,i,j,Cn,k;
		int p=0;
		char t[20];
		printf("课程号   课程名  上课时间  上课地点   上课老师  老师编号   课程人数\n"); /*添加*/
		for(k=0;k<=CPMAX;k++) /*添加*/
		{
			if(Cou[k].Cno==0) break;
		}
		for(i=0;i<k;i++)
		{
			printf("%3d %10s %9.2f",Cou[i].Cno,Cou[i].Cname,Cou[i].time);
			printf(" %10s %8s %9d %9d\n",Cou[i].place,Cou[i].teacher,Cou[i].Tno,Cou[i].pn);
		}   /*添加*/
	
		printf("请输入课程序号\n");
		scanf("%d",&cn);
		Cn=cn-1;

        if(Cou[Cn].Cno==0) 
		{
		   printf("该课程不存在\n");
	       printf("是否继续选课? 1 是  2  否\n");
		   scanf("%d",&j);
		   if(j==1) {system("cls");goto leap1;} 
		}
		else if(Cn<CNO&&Cn>=0)
		{
			printf("课程号   课程名  上课时间  上课地点   上课老师  老师编号   课程人数\n");
			printf("%3d %10s %9.2f",Cou[Cn].Cno,Cou[Cn].Cname,Cou[Cn].time);
			printf(" %10s %8s %9d %9d\n",Cou[Cn].place,Cou[Cn].teacher,Cou[Cn].Tno,Cou[Cn].pn);
			printf("是否选择该课程? 1 是 2 否\n");
			scanf("%d",&j);
			if(j==1)
			{
					for(j=1;j<(SCMAX-1);j++)	/*+++++++++++++++++++++++++++*/
				{
					if(Student[XH][j]==cn) p=1;
				}
				if(p==1) 
				{
					printf("该门课程已经选过了\n");
					printf("是否重新选课？1 是 2 否\n");
					scanf("%d",&i);
					if(i==1) {system("cls");goto leap1;}
				}
				else if(Student[XH][SCMAX-1]>0) 
				{
					printf("你所选课程已满不能再进行选择\n");
			        
				}

				else if(Cou[Cn].pn==CPMAX)  
				{
					printf("该门课人数已满");
					printf("是否重新选课？1 是 2 否\n");
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
					    printf("选课成功！\n");
					    printf("是否继续选课? 1 是  2  否\n");
		                scanf("%d",&j);
		            if(j==1) {system("cls");goto leap1;} 

				}
			}
			else
			{
                 printf("是否继续选课? 1 是  2  否\n");
		         scanf("%d",&j);
	             if(j==1) {system("cls");goto leap1;}
			}
		}
	else 
	{
		printf("该课程不存在\n");
		printf("是否继续选课? 1 是  2  否\n");
		scanf("%d",&j);
		if(j==1) {system("cls");goto leap1;}
	}
	printf("任意键返回\n");
	scanf("%s",&t);
	system("cls");
	printf("%s欢迎回来！\n",S[XH].Sname);
	system("color 80");
	printf("                  ################################################\n");
	printf("                  #                                              #\n");
	printf("                  #                                              #\n");
    printf("                  #             1 选课查询                       #\n");
	printf("                  #                                              #\n");
	printf("                  #             2 选课                           #\n");
	printf("                  #                                              #\n");
	printf("                  #             3 选课退选                       #\n");
	printf("                  #                                              #\n");
	printf("                  #                                              #\n");
	printf("                  #                                    B返回     #\n");
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

void DropC(int XH)   /*课程退选*/
	{
leap2:  int i,j,k;
		char l[20];
		int m=0;
		printf("您已选择的课程为：\n");
		printf("课程号   课程名  上课时间  上课地点   上课老师  老师编号   课程人数\n");
		for(j=1;j<=4;j++)
		{
			if(Student[XH][j]==0) printf("空\n");
		    else
			{
				printf("%3d %10s %9.2f  ",Cou[Student[XH][j]-1].Cno,Cou[Student[XH][j]-1].Cname,Cou[Student[XH][j]-1].time);
				printf(" %7s %8s %9d %9d\n",Cou[Student[XH][j]-1].place,Cou[Student[XH][j]-1].teacher,Cou[Student[XH][j]-1].Tno,Cou[Student[XH][j]-1].pn);
				
			}        /*输出所查询的课程*/
		}

		printf("请输入退选的课程号:\n");
		scanf("%d",&i);
		if(i>CNO||i<0) 
		{
			printf("输入有误\n");
			goto leap2;
		}
		else if(Cou[i-1].Cno==0){
			printf("该课程不存在\n");
			printf("是否重新退选课程？1 是 2 否\n");
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
			printf("退选成功！\n");
			printf("是否继续退选课程? 1是  2 否\n");
			scanf("%d",&k);
			if(k==1) {system("cls"); goto leap2;}
		}
		else
		{
			printf("你还没选择这门课程\n");

            printf("是否重新退选课程？1 是 2 否\n");
			scanf("%d",&k);
			if(k==1) {system("cls"); goto leap2;}
		
		}

	}
	printf("任意键返回\n");
	scanf("%d",l);
	system("cls");
	printf("%s欢迎回来！\n",S[XH].Sname);
	system("color 80");
	printf("                  ################################################\n");
	printf("                  #                                              #\n");
	printf("                  #                                              #\n");
    printf("                  #             1 选课查询                       #\n");
	printf("                  #                                              #\n");
	printf("                  #             2 选课                           #\n");
	printf("                  #                                              #\n");
	printf("                  #             3 选课退选                       #\n");
	printf("                  #                                              #\n");
	printf("                  #                                              #\n");
	printf("                  #                                    B返回     #\n");
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
leap7: printf("请输入账号:\n");
	scanf("%d",&xh);
	if(xh>6||xh<1) { printf("输入错误请重新输入\n"); goto leap7;}
	else{
	system("cls");
	printf("%s欢迎回来！\n",S[xh-1].Sname);
	system("color 80");
	printf("                  ################################################\n");
	printf("                  #                                              #\n");
	printf("                  #                                              #\n");
    printf("                  #             1 选课查询                       #\n");
	printf("                  #                                              #\n");
	printf("                  #             2 选课                           #\n");
	printf("                  #                                              #\n");
	printf("                  #             3 选课退选                       #\n");
	printf("                  #                                              #\n");
	printf("                  #                                              #\n");
	printf("                  #                                    B返回     #\n");
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
/*++++++++++++++++++++++++++++++++++++++++++++++++学生++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++老师++++++++++++++++++++++++++++++++++++++++++++++++*/
void teacher()                /*老师*/
	{/*f*/
leap3:	int BH,bh,i,j,d,m;
		char l[20];
		int k=0;
     	printf("请输入账号：\n");
		scanf("%d",&bh);
		if(bh>6||bh<1) { printf("输入错误请重新输入\n"); goto leap3;}
	    else{
		BH=bh-1;
		if(BH>CNO||BH<0) 
		{
			printf("输入有误\n");
			goto leap3;
		}
		else
		{/*kk*/
			printf("您所教的选修课有：\n");
			printf("课程号   课程名  上课时间  上课地点   上课老师  老师编号   课程人数\n");
			for(i=1;i<=TEMAX;i++)
			{	printf("%3d %10s %9.2f ",Cou[Teacher[BH][i]-1].Cno,Cou[Teacher[BH][i]-1].Cname,Cou[Teacher[BH][i]-1].time);
			    printf(" %10s %8s %9d %9d\n",Cou[Teacher[BH][i]-1].place,Cou[Teacher[BH][i]-1].teacher,Cou[Teacher[BH][i]-1].Tno,Cou[Teacher[BH][i]-1].pn);
			}
            printf("显示所教课程学生名单？1 是 2 否\n");
			scanf("%d",&j);
			if(j==1)
			{
	leap4: 	  printf("请输入课程号\n");
			  scanf("%d",&j);
			  if(j>CNO||j<1) { printf("输入错误\n"); goto leap4; }
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
				if(m==0) { printf("你没有教该门课\n"); goto leap4; }
				else
				{
			
					printf("选修该门课程的学生有:\n");
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
		
		printf("按任意键返回\n");
		scanf("%s",l);
		system("cls");
		jiemian();

		}
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++老师+++++++++++++++++++++++++++++++++++++++++++++++++++/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++管理员+++++++++++++++++++++++++++++++++++++++++++++++++*/


void Delete()  /*对课程进行删除*/
		{
leap5:      int i,j;
			char l[20];
			printf("请输入要删除的课程的课程号:\n");
            scanf("%d",&i);
			if(i<1||i>CNO)  {printf("输入错误\n"); goto leap5;}
			else if(Cou[i-1].Cno==0) {
				printf("该课程不存在\n");
				printf("是否继续删除课程? 1 是  2否\n");
				scanf("%d",&j);
				if(j==1){system("cls"); goto leap5;}
			}
			else
			{
				printf("正在删除请稍后\n");
				memset(&Cou[i-1],0,sizeof(struct Course));
				printf("删除成功！\n");
				printf("是否继续删除课程? 1 是  2否\n");
				scanf("%d",&j);
				if(j==1){system("cls"); goto leap5;}
			}
			printf("任意键返回\n");
			scanf("%s",&l);
			system("cls");
	        printf("                  ################################################\n");
        	printf("                  #                 管理员                       #\n");
        	printf("                  #                                              #\n");
            printf("                  #              1 增加课程                      #\n");
        	printf("                  #                                              #\n");
        	printf("                  #              2 删除课程                      #\n");
        	printf("                  #                                              #\n");
        	printf("                  #              3 修改课程                      #\n");
        	printf("                  #                                              #\n");
        	printf("                  #                                              #\n");
        	printf("                  #                                   B返回      #\n");
        	printf("                  ################################################\n");
        	scanf("%d",&i);
         	if(i==1) {system("cls");Add();}
        	else if(i==2) {system("cls");Delete();}
        	else if(i==3) {system("cls");change();}
        	else
			{system("cls");jiemian();}
			
}

void	change()  /*对课程进行修改*/
		{
	char l[20];
leap6:      int i,j,m,d;
			int k=0;
			printf(" 请输入要修改的课程的课程号:\n");
			scanf("%d",&i);
			if(i<1||i>CNO)  {printf("输入错误\n"); goto leap6;}
			else if(Cou[i-1].Cno==0) {printf("该课程不存在\n"); goto leap6;}
            else
			{
				int cno;
              	char  cname[20];
	            float Time;
             	char  Place[20];
	            char  Teacher[10];
             	int tno;  
	 
				printf("请依次按' 课程号   课程名  上课时间  上课地点   上课老师  老师编号'  输入:\n");
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
				if(k==1) {printf("输入的有误，所修改的课程其他课程有冲突\n");goto leap6;}
				else
				{
					
					Cou[i-1].Cno=cno;
					strcpy(Cou[i-1].Cname,cname);
					Cou[i-1].time=Time;
					strcpy(Cou[i-1].place,Place);
					strcpy(Cou[i-1].teacher,Teacher);
					Cou[i-1].Tno=tno;
					printf("修改成功！\n");
					printf("继续修改课程？ 1是  2否\n");
					scanf("%d",&d);
					if(d==1){system("cls"); goto leap6;}
		
				}
			}
						printf("任意键返回\n");
			scanf("%s",&l);
			system("cls");
	printf("                  ################################################\n");
	printf("                  #                 管理员                       #\n");
	printf("                  #                                              #\n");
    printf("                  #              1 增加课程                      #\n");
	printf("                  #                                              #\n");
	printf("                  #              2 删除课程                      #\n");
	printf("                  #                                              #\n");
	printf("                  #              3 修改课程                      #\n");
	printf("                  #                                              #\n");
	printf("                  #                                              #\n");
	printf("                  #                                   B返回      #\n");
	printf("                  ################################################\n");
	scanf("%d",&i);
	if(i==1) {system("cls");Add();}
	else if(i==2) {system("cls");Delete();}
	else if(i==3) {system("cls");change();}
	else
	{system("cls");jiemian();}
			
}

void	Add()  /*增加课程*/
			{
	            char l[20];
leap7:      	int i,m,d,j,k;
				int cno;
              	char  cname[20];
	            double Time;
             	char  Place[20];
	            char  Teacher[10];
             	int tno;  
				printf("请输入该课程的课程号:\n");
                scanf("%d",&i);
				if(Cou[i-1].Cno!=0) {printf("该课程号已经存在\n");goto leap7;}
				else if(i<1||i>CNO) {printf("输入有误\n");goto leap7;}
				else
				{
				    printf("请依次按    课程名  上课时间  上课地点   上课老师  老师编号   课程人数 输入:\n");
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
				if(k==1) {printf("输入的有误，所增加的课程与其他课程有冲突\n");goto leap7;}
				else
				{
					
					Cou[i-1].Cno=(i-1);
					strcpy(Cou[i-1].Cname,cname);
					Cou[i-1].time=Time;
					strcpy(Cou[i-1].place,Place);
					strcpy(Cou[i-1].teacher,Teacher);
					Cou[i-1].Tno=tno;
					Cou[i-1].pn=0;
					printf("增加课程成功！\n");
					printf("继续增加课程？ 1是  2否\n");
					scanf("%d",&d);
					if(d==1){system("cls"); goto leap7;}
		
				}
				}
							printf("任意键返回\n");
			scanf("%s",&l);
			system("cls");
	printf("                  ################################################\n");
	printf("                  #                 管理员                       #\n");
	printf("                  #                                              #\n");
    printf("                  #              1 增加课程                      #\n");
	printf("                  #                                              #\n");
	printf("                  #              2 删除课程                      #\n");
	printf("                  #                                              #\n");
	printf("                  #              3 修改课程                      #\n");
	printf("                  #                                              #\n");
	printf("                  #                                              #\n");
	printf("                  #                                   B返回      #\n");
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
	printf("                  #                 管理员                       #\n");
	printf("                  #                                              #\n");
    printf("                  #              1 增加课程                      #\n");
	printf("                  #                                              #\n");
	printf("                  #              2 删除课程                      #\n");
	printf("                  #                                              #\n");
	printf("                  #              3 修改课程                      #\n");
	printf("                  #                                              #\n");
	printf("                  #                                              #\n");
	printf("                  #                                   B返回      #\n");
	printf("                  ################################################\n");
	scanf("%d",&i);
	if(i==1) {system("cls");Add();}
	else if(i==2) {system("cls");Delete();}
	else if(i==3) {system("cls");change();}
	else
	{system("cls");jiemian();}
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++管理员+++++++++++++++++++++++++++++++++++++++++++++++++*/
void jiemian()
{
	int i;
	system("color 80");
	printf("                  ################################################\n");
	printf("                  #              学生选课系统                    #\n");
	printf("                  #                                              #\n");
    printf("                  #              1 学生入口                      #\n");
	printf("                  #                                              #\n");
	printf("                  #              2 教师入口                      #\n");
	printf("                  #                                              #\n");
	printf("                  #              3 管理员入口                    #\n");
	printf("                  #                                              #\n");
	printf("                  #                                              #\n");
	printf("                  #                                    退出      #\n");
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

