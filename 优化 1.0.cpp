#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
const int N=100;
typedef struct poet
{
	std::vector<std::string> poet_name;
	std::vector<std::string> poet_info;
	std::vector<std::string> poet_poem;;
	std::vector<std::string> poet_life;
	std::vector<std::string> poet_eval;
}POET;
#define ElemType POET
typedef struct List
{
	ElemType Data;
	struct List *next;
}*poet_list;
typedef struct Manager
{
	string  name;
	string  pword;
	int num;
}MGER;
void index(poet_list list,Manager MGER[N]);//登录界面
void visitor(poet_list list,Manager MGER[N]);//游客登录
void manager_index(poet_list list,Manager MGER[N]);//管理员界面
void manager(poet_list list,Manager MGER[N]);//管理员登录
void init_manager(Manager MGER[N]);//管理员列表初始化
void add_poet_infomation(poet_list list);//增加诗人诗词信息
void add_manager_infomation(poet_list list,Manager MGER[N]);//增加管理员信息
poet_list create_list();
void add_node(poet_list list,POET Data);
void initlist(poet_list list);//列表初始化
void print(int op);//打印函数
void nan(poet_list list,Manager MGER[N]);//南宋
void ming(poet_list list,Manager MGER[N]);//明朝
void dong(poet_list list,Manager MGER[N]);//东晋
void bei(poet_list list,Manager MGER[N]);//北宋
void qing(poet_list list,Manager MGER[N]);//明末清初
void tang(poet_list list,Manager MGER[N]);//唐朝
void menu1();
void menu2();
void menu3();

int main()
{
	Manager MANA[N];
	system("color 3F");
	poet_list list = create_list();
	initlist(list);
	init_manager(MANA);
	index(list,MANA);
	return 0;
}

poet_list create_list() 
{
	poet_list list =new List;
	list->next= NULL;
	return list;
}

void add_node(poet_list list,POET data) 
{
	poet_list node=new List;
	node->Data.poet_name=data.poet_name;
	node->Data.poet_info=data.poet_info;
	node->Data.poet_poem=data.poet_poem;
	node->Data.poet_life=data.poet_life;
	node->Data.poet_eval=data.poet_eval;
	node->next = NULL;
	if (list->next == NULL) 
		list->next = node;
	else 
	{
		poet_list p = list->next;
		while (p->next != NULL) 
			p = p->next;
		p->next = node;
	}
}

void initlist(poet_list list) 
{
	int sum=0;
	std::ifstream fp("poets.txt");
	if (!fp) 
	{
		printf("无法打开文件\n");
		return;
	}
	std::string file;
	POET Data;
	while(std::getline(fp,file))
	{
		if(sum%5==0)
            Data.poet_name.push_back(file);
		else if(sum%5==1)
            Data.poet_info.push_back(file);
        else if(sum%5==2)
            Data.poet_poem.push_back(file);
        else if(sum%5==3)
            Data.poet_life.push_back(file);
        else
            Data.poet_eval.push_back(file);
        if(file.find("aa")!=std::string::npos)
            sum++;
        if(file.find("kkk")!=std::string::npos)
        {
        	sum++;
        	add_node(list,Data);
        	Data.poet_name.clear();
        	Data.poet_info.clear();
        	Data.poet_poem.clear();
        	Data.poet_life.clear();
        	Data.poet_eval.clear();
        }
	}
	fp.close();
}

void nan(poet_list list,Manager MGER[N])
{
	system("cls");
	cout<<"                                   -----------------南宋诗杰-----------------"<<endl<<endl<<endl<<endl;
	poet_list p=list->next;
	poet_list NEW=new List;
	NEW->next = NULL;
	poet_list tail = NEW;
	int i=1;
	while(p!=NULL)
	{
		int flag=0;
        for(auto& s : p->Data.poet_info)
        {
            if(s.find("南宋")!=std::string::npos)
            	flag=1;
        }
		if(flag)
		{
			cout<<"                                                    " << i<<".";
            for(auto& s : p->Data.poet_name)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s;
            }
			cout<<endl<<endl;
			tail->next = new List; // 创建新节点
			tail = tail->next; // 移动尾部
			tail->Data.poet_name = p->Data.poet_name;//复制建立NEW链表
			tail->Data.poet_info = p->Data.poet_info;
			tail->Data.poet_poem = p->Data.poet_poem;
			tail->Data.poet_life = p->Data.poet_life;
			tail->Data.poet_eval = p->Data.poet_eval;
			i++;
		}
		p=p->next;
	}
	cout<<endl<<endl<<endl<<endl<<endl<<"                                                    "<<i<<"."<<"返回菜单"<<endl;
	cout << "请输入您的选择：";
	poet_list q=NEW->next;
	int j;
	cin>>j;
	for(int k=1;k<=i-1;k++)
	{
		if(j>i||j<=0) 
		{
			delete NEW;
			nan(list,MGER);
			return ;
		}	
		if(k==j)
		{
			system("cls");
            for(auto& s :q->Data.poet_name)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s<<endl;
            }
            for(auto& s :q->Data.poet_info)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s<<endl;
            }
            for(auto& s :q->Data.poet_poem)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s<<endl;
            }
            for(auto& s :q->Data.poet_life)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s<<endl;
            }
            for(auto& s :q->Data.poet_eval)
            {
            	if(s.find("kkk")!=std::string::npos)
            		s.erase(s.find("kkk"),3);
                cout<<s<<endl;
            }
			delete NEW;
			system("Pause");
			visitor(list,MGER);
			return ;
		}
		if(j==i)
		{
			system("cls");
			visitor(list,MGER);
			return ;
		}
		q=q->next;
	}
	delete NEW;
	return;
}
void ming(poet_list list,Manager MGER[N])
{
	system("cls");
	cout<<"                                   -----------------明世词宗-----------------"<<endl<<endl<<endl<<endl;
	poet_list p=list->next;
	poet_list NEW=new List;
	NEW->next = NULL;
	poet_list tail = NEW;
	int i=1;
	while(p!=NULL)
	{
		int flag=0;
        for(auto& s : p->Data.poet_info)
        {
            if(s.find("明朝")!=std::string::npos)
            	flag=1;
        }
		if(flag)
		{
			cout<<"                                                    "<<i<<".";
            for(auto& s : p->Data.poet_name)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s;
            }
			cout<<endl<<endl;
			tail->next = new List; // 创建新节点
			tail = tail->next; // 移动尾部
			tail->Data.poet_name = p->Data.poet_name;//复制建立NEW链表
			tail->Data.poet_info = p->Data.poet_info;
			tail->Data.poet_poem = p->Data.poet_poem;
			tail->Data.poet_life = p->Data.poet_life;
			tail->Data.poet_eval = p->Data.poet_eval;
			i++;
		}
		p=p->next;
	}
	cout<<endl<<endl<<endl<<endl<<endl<<"                                                    "<<i<<"."<<"返回菜单"<<endl;
		cout << "请输入您的选择：";
	poet_list q=NEW->next;
	int j;
	cin>>j;
	for(int k=1;k<=i-1;k++)
	{
		if(j>i||j<=0) 
		{
			delete NEW;
			ming(list,MGER);
			return ;
		}	
		if(k==j)
		{
			system("cls");
            for(auto& s :q->Data.poet_name)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s<<endl;
            }
            for(auto& s :q->Data.poet_info)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s<<endl;
            }
            for(auto& s :q->Data.poet_poem)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s<<endl;
            }
            for(auto& s :q->Data.poet_life)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s<<endl;
            }
            for(auto& s :q->Data.poet_eval)
            {
            	if(s.find("kkk")!=std::string::npos)
            		s.erase(s.find("kkk"),3);
                cout<<s<<endl;
            }
			delete NEW;
			system("Pause");
			visitor(list,MGER);
			return ;
		}
		if(j==i)
		{
			system("cls");
			visitor(list,MGER);
			return ;
		}
		q=q->next;
	}
	delete NEW;
	return;
}
void dong(poet_list list,Manager MGER[N])
{
	system("cls");
	cout<<"                                   -----------------晋风诗才-----------------"<<endl<<endl<<endl<<endl;
	poet_list p=list->next;
	poet_list NEW=new List;
	NEW->next = NULL;
	poet_list tail = NEW;
	int i=1;
	while(p!=NULL)
	{
		int flag=0;
        for(auto& s : p->Data.poet_info)
        {
            if(s.find("东晋")!=std::string::npos)
            	flag=1;
        }
		if(flag)
		{
			cout<<"                                                    "<<i<<".";
            for(auto& s : p->Data.poet_name)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s;
            }
			cout<<endl<<endl;
			tail->next = new List; // 创建新节点
			tail = tail->next; // 移动尾部
			tail->Data.poet_name = p->Data.poet_name;//复制建立NEW链表
			tail->Data.poet_info = p->Data.poet_info;
			tail->Data.poet_poem = p->Data.poet_poem;
			tail->Data.poet_life = p->Data.poet_life;
			tail->Data.poet_eval = p->Data.poet_eval;
			i++;
		}
		p=p->next;
	}
	cout<<endl<<endl<<endl<<endl<<endl<<"                                                    "<<i<<"."<<"返回菜单"<<endl;
		cout << "请输入您的选择：";
	poet_list q=NEW->next;
	int j;
	cin>>j;
	for(int k=1;k<=i-1;k++)
	{
		if(j>i||j<=0) 
		{
			delete NEW;
			dong(list,MGER);
			return ;
		}	
		if(k==j)
		{
			system("cls");
            for(auto& s :q->Data.poet_name)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s<<endl;
            }
            for(auto& s :q->Data.poet_info)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s<<endl;
            }
            for(auto& s :q->Data.poet_poem)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s<<endl;
            }
            for(auto& s :q->Data.poet_life)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s<<endl;
            }
            for(auto& s :q->Data.poet_eval)
            {
            	if(s.find("kkk")!=std::string::npos)
            		s.erase(s.find("kkk"),3);
                cout<<s<<endl;
            }
			delete NEW;
			system("Pause");
			visitor(list,MGER);
			return ;
		}
		if(j==i)
		{
			system("cls");
			visitor(list,MGER);
			return ;
		}
		q=q->next;
	}
	delete NEW;
	return;
}
void bei(poet_list list,Manager MGER[N])
{
	system("cls");
	cout<<"                                   -----------------北朝墨客-----------------"<<endl<<endl<<endl<<endl;
	poet_list p=list->next;
	poet_list NEW=new List;
	NEW->next = NULL;
	poet_list tail = NEW;
	int i=1;
	while(p!=NULL)
	{
		int flag=0;
        for(auto& s : p->Data.poet_info)
        {
            if(s.find("北宋")!=std::string::npos)
            	flag=1;
        }
		if(flag)
		{
			cout<<"                                                    "<<i<<".";
            for(auto& s : p->Data.poet_name)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s;
            }
			cout<<endl<<endl;
			tail->next = new List; // 创建新节点
			tail = tail->next; // 移动尾部
			tail->Data.poet_name = p->Data.poet_name;//复制建立NEW链表
			tail->Data.poet_info = p->Data.poet_info;
			tail->Data.poet_poem = p->Data.poet_poem;
			tail->Data.poet_life = p->Data.poet_life;
			tail->Data.poet_eval = p->Data.poet_eval;
			i++;
		}
		p=p->next;
	}
cout<<endl<<endl<<endl<<endl<<endl<<"                                                    "<<i<<"."<<"返回菜单"<<endl;
	cout << "请输入您的选择：";
	poet_list q=NEW->next;
	int j;
	cin>>j;
	for(int k=1;k<=i-1;k++)
	{
		if(j>i||j<=0) 
		{
			delete NEW;
			bei(list,MGER);
			return ;
		}	
		if(k==j)
		{
			system("cls");
            for(auto& s :q->Data.poet_name)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s<<endl;
            }
            for(auto& s :q->Data.poet_info)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s<<endl;
            }
            for(auto& s :q->Data.poet_poem)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s<<endl;
            }
            for(auto& s :q->Data.poet_life)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s<<endl;
            }
            for(auto& s :q->Data.poet_eval)
            {
            	if(s.find("kkk")!=std::string::npos)
            		s.erase(s.find("kkk"),3);
                cout<<s<<endl;
            }
			delete NEW;
			system("Pause");
			visitor(list,MGER);
			return ;
		}
		if(j==i)
		{
			system("cls");
			visitor(list,MGER);
			return ;
		}
		q=q->next;
	}
	delete NEW;
	return;
}
void qing(poet_list list,Manager MGER[N])
{
	system("cls");
	cout<<"                                   -----------------唐韵骚人-----------------"<<endl<<endl<<endl<<endl;
	poet_list p=list->next;
	poet_list NEW=new List;
	NEW->next = NULL;
	poet_list tail = NEW;
	int i=1;
	while(p!=NULL)
	{
		int flag=0;
        for(auto& s : p->Data.poet_info)
        {
            if(s.find("清朝")!=std::string::npos)
            	flag=1;
        }
		if(flag)
		{
			cout<<"                                                    "<<i<<".";
            for(auto& s : p->Data.poet_name)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s;
            }
			cout<<endl<<endl;
			tail->next = new List; // 创建新节点
			tail = tail->next; // 移动尾部
			tail->Data.poet_name = p->Data.poet_name;//复制建立NEW链表
			tail->Data.poet_info = p->Data.poet_info;
			tail->Data.poet_poem = p->Data.poet_poem;
			tail->Data.poet_life = p->Data.poet_life;
			tail->Data.poet_eval = p->Data.poet_eval;
			i++;
		}
		p=p->next;
	}
	cout<<endl<<endl<<endl<<endl<<endl<<"                                                    "<<i<<"."<<"返回菜单"<<endl;
		cout << "请输入您的选择：";
	poet_list q=NEW->next;
	int j;
	cin>>j;
	for(int k=1;k<=i-1;k++)
	{
		if(j>i||j<=0) 
		{
			delete NEW;
			qing(list,MGER);
			return ;
		}	
		if(k==j)
		{
			system("cls");
            for(auto& s :q->Data.poet_name)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s<<endl;
            }
            for(auto& s :q->Data.poet_info)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s<<endl;
            }
            for(auto& s :q->Data.poet_poem)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s<<endl;
            }
            for(auto& s :q->Data.poet_life)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s<<endl;
            }
            for(auto& s :q->Data.poet_eval)
            {
            	if(s.find("kkk")!=std::string::npos)
            		s.erase(s.find("kkk"),3);
                cout<<s<<endl;
            }
			delete NEW;
			system("Pause");
			visitor(list,MGER);
			return ;
		}
		if(j==i)
		{
			system("cls");
			visitor(list,MGER);
			return ;
		}
		q=q->next;
	}
	delete NEW;
	return;
}
void tang(poet_list list,Manager MGER[N])
{
	system("cls");
	cout<<"                                   -----------------明末清初诗豪士-----------------"<<endl<<endl<<endl<<endl;
	poet_list p=list->next;
	poet_list NEW=new List;
	NEW->next = NULL;
	poet_list tail = NEW;
	int i=1;
	while(p!=NULL)
	{
		int flag=0;
        for(auto& s : p->Data.poet_info)
        {
            if(s.find("唐朝")!=std::string::npos)
            	flag=1;
        }
		if(flag)
		{
			cout<<"                                                    "<<i<<".";
            for(auto& s : p->Data.poet_name)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s;
            }
			cout<<endl<<endl;
			tail->next = new List; // 创建新节点
			tail = tail->next; // 移动尾部
			tail->Data.poet_name = p->Data.poet_name;//复制建立NEW链表
			tail->Data.poet_info = p->Data.poet_info;
			tail->Data.poet_poem = p->Data.poet_poem;
			tail->Data.poet_life = p->Data.poet_life;
			tail->Data.poet_eval = p->Data.poet_eval;
			i++;
		}
		p=p->next;
	}
	cout<<endl<<endl<<endl<<endl<<endl<<"                                                    "<<i<<"."<<"返回菜单"<<endl;
		cout << "请输入您的选择：";
	poet_list q=NEW->next;
	int j;
	cin>>j;
	for(int k=1;k<=i-1;k++)
	{
		if(j>i||j<=0) 
		{
			delete NEW;
			system("cls");
			cout<<"qing"<<endl;
			tang(list,MGER);
			return ;
		}	
		if(k==j)
		{
			system("cls");
            for(auto& s :q->Data.poet_name)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s<<endl;
            }
            for(auto& s :q->Data.poet_info)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s<<endl;
            }
            for(auto& s :q->Data.poet_poem)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s<<endl;
            }
            for(auto& s :q->Data.poet_life)
            {
            	if(s.find("aa")!=std::string::npos)
            		s.erase(s.find("aa"),2);
                cout<<s<<endl;
            }
            for(auto& s :q->Data.poet_eval)
            {
            	if(s.find("kkk")!=std::string::npos)
            		s.erase(s.find("kkk"),3);
                cout<<s<<endl;
            }
			delete NEW;
			system("Pause");
			visitor(list,MGER);
			return ;
		}
		if(j==i)
		{
			system("cls");
			visitor(list,MGER);
			return ;
		}
		q=q->next;
	}
	delete NEW;
	return;
}
void menu1()
{
	printf("                                  ********************************************\n");
	printf("                                  ·        欢迎进入《古韵江西，诗词华章》    ·    \n");
	printf("                                  ·        ----请选择登录方式----            ·    \n\n");
	printf("                                  ·            1.游客登录                    ·   \n\n");
	printf("                                  ·            2.管理员登录                  ·    \n\n");
	printf("                                  ·            3.退出系统                    ·    \n\n");
	printf("                                  ·                                          ·    \n");
	printf("                                  ********************************************\n");
}
void menu2()
{
	printf("                                  ****************************************************\n");
	printf("                                  ·              ----菜单栏----                     ·    \n\n");
	printf("                                  ·            1.“文献之治”--南宋                   ·    \n\n");
	printf("                                  ·            2.“光明正大”--明朝                   ·    \n\n");
	printf("                                  ·            3.“文学之乡”--东晋                   ·    \n\n");
	printf("                                  ·            4.“王朝之都”--北宋                   ·    \n\n");
	printf("                                  ·            5.“明亡清兴”--明末清初               ·    \n\n");
	printf("                                  ·            6.“盛世之治”--唐朝                   ·    \n\n");
	printf("                                  ·            7.退出到登录界面                     ·    \n\n");
	printf("                                  ·            8.退出系统                           ·    \n\n");
	printf("                                  ·                                                 ·    \n");
	printf("                                  ****************************************************\n");
}
void menu3() {
	printf("                                  ****************************************************\n");
	printf("                                  ·              ----菜单栏----                     ·    \n\n");
	printf("                                  ·            1.增加诗人及诗词信息                   ·    \n\n");
	printf("                                  ·            2.增加管理员                           ·    \n\n");
	printf("                                  ·            3.切换账号                             ·    \n\n");
	printf("                                  ·            0.退出到登录界面                       ·    \n\n");
	printf("                                  ·                                                 ·    \n");
	printf("                                  ****************************************************\n");
}
void visitor(poet_list list,Manager MGER[N])//游客登录
{
	int x,flag=0;
	while(!flag)
	{
		system("cls");
		menu2();
		cout << "请输入您的选择：";
		cin >> x;
		switch (x) 
		{
			case 1:
				nan(list,MGER);
				flag=1;
				break;
			case 2:
				ming(list,MGER);
				flag=1;
				break;
			case 3:
				dong(list,MGER);
				flag=1;
				break;
			case 4:
				bei(list,MGER);
				flag=1;
				break;
			case 5:
				qing(list,MGER);
				flag=1;
				break;
			case 6:
	            system("cls");
				tang(list,MGER);
				flag=1;
				break;
			case 7:
				index(list,MGER);
				flag=1;
				break;
			case 8:
				system("cls");
				cout<<"退出系统成功！";
				exit(0);
				break;
			default:
				printf("选择错误，请重新输入选择项!\n");
				system("Pause");
				break;
		}
	}
	return ;
}
void index(poet_list list,Manager MGER[N])//登录主页
{
	int x,flag=0;
	while(!flag)
	{
		system("cls");
		menu1();
		cout << "请输入登录方式：";
		cin >> x;
		switch (x) 
		{
			case 1:
				system("cls");
				visitor(list,MGER);
				flag=1;
				break;
			case 2:
				system("cls");
				manager(list,MGER);
				flag=1;
				break;
			case 3:
				system("cls");
				cout<<"退出系统成功！";
				exit(0);
				break;
			default:
				cout<<"选项输入错误,请重新输入";
				system("Pause");
				
		}
	}
	
}
void init_manager(Manager MGER[N])
{
	int i=0;
	ifstream ifs("manager_info.txt",ios::in);
	if(ifs)
	{
		string  line;
		while(getline(ifs,line))
		{
			MGER[i].name.assign(line);
			line.clear();
			getline(ifs,line);
			MGER[i].pword.assign(line);
			line.clear();
			i++;
		}
	}
}
void manager(poet_list list,Manager MGER[N]) { //管理员登录页面
	init_manager(MGER);
		string name, password;
		int i = 0;
		printf("                                  ********************************************\n");
		printf("                                  ·        ----管理员登录----               ·    \n");
		printf("                                  ·            请输入账号名：");
		cin >> name;
		printf("                                  ·            请输入密码：");
		getchar();
		char ch = _getch();
		while (ch != 13) {
			if (ch == 8) {
				if (password.length() > 0) {
					cout << "\b \b"; // Move cursor back, overwrite with space, move cursor back again
					password.resize(password.size() - 1); // Remove last character
				}
			} else {
				password.push_back(ch);
				cout << "*";
			}
			ch = _getch(); // Get next character
		}
		cout << "\n";
		printf("                                  ·                                         ·    \n");
		printf("                                  ********************************************\n");
		for (i = 0; i < N; i++) {
			if (MGER[i].name == name && MGER[i].pword == password) {
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				manager_index(list, MGER);
				return ;
			}
		}
		system("cls");
		cout << "账号或密码错误，请重新输入" << endl;
		manager(list, MGER);
		return ;
}
void manager_index(poet_list list, Manager MGER[N]) { //管理员主页
	menu3();
	cout<<"请输入您的操作：";
	int x;
	cin >> x;
	switch (x) {
		case 1:
			add_poet_infomation(list);
			break;
		case 2:
			add_manager_infomation(list, MGER);
			break;
		case 3:
			manager(list, MGER);
			break;
		case 0:
			index(list, MGER);
			break;
	}
}
void add_manager_infomation(poet_list list, Manager MGER[N]) { //增加管理员信息
	string name, password;
		ofstream ofs("manager_info.txt", ios::out | ios::trunc);
		if (ofs) {
			cout << "请输入用户名：";
			cin >> name;
			cout << "请输入密码：";
			getchar();
			char ch = _getch();
	
			while (ch != 13) {
				if (ch == 8) {
					if (password.length() > 0) {
						cout << "\b \b"; // Move cursor back, overwrite with space, move cursor back again
						password.resize(password.size() - 1); // Remove last character
					}
				} else {
					password.push_back(ch);
					cout << "*";
				}
				ch = _getch(); // Get next character
			}
			cout << "\n";
			//stream.seek[g | p](10, ios::end);
			ofs << name << endl;
			ofs << password << endl;
			cout << "已成功添加该管理员" << endl;
		}
		system("Pause");
		system("cls");
		manager_index(list, MGER);
		
		return ;
}
void add_poet_infomation(poet_list list)
{
	POET data;
	std::string x;
	cout<<"请输入录入诗人昵称:";
	while(getline(std::cin,x))
	{
		x+="aa";
		data.poet_name.push_back(x);
	}

	cout<<"请输入录入诗人简介:";
	while(getline(std::cin,x))
	{
		x+="aa";
		data.poet_info.push_back(x);
	}
	
	cout<<"请输入录入诗人诗歌作品:";
	while(getline(std::cin,x))
	{
		x+="aa";
		data.poet_poem.push_back(x);
	}
	
	cout<<"请输入录入诗人生平信息:";
	while(getline(std::cin,x))
	{
		x+="aa";
		data.poet_life.push_back(x);
	}
	
	cout<<"请输入录入诗人所受评价:";
	while(getline(std::cin,x))
	{
		x+="kkk";
		data.poet_eval.push_back(x);
	}
	add_node(list,data);
}
