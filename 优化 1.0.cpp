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
void index(poet_list list,Manager MGER[N]);//��¼����
void visitor(poet_list list,Manager MGER[N]);//�ο͵�¼
void manager_index(poet_list list,Manager MGER[N]);//����Ա����
void manager(poet_list list,Manager MGER[N]);//����Ա��¼
void init_manager(Manager MGER[N]);//����Ա�б��ʼ��
void add_poet_infomation(poet_list list);//����ʫ��ʫ����Ϣ
void add_manager_infomation(poet_list list,Manager MGER[N]);//���ӹ���Ա��Ϣ
poet_list create_list();
void add_node(poet_list list,POET Data);
void initlist(poet_list list);//�б��ʼ��
void print(int op);//��ӡ����
void nan(poet_list list,Manager MGER[N]);//����
void ming(poet_list list,Manager MGER[N]);//����
void dong(poet_list list,Manager MGER[N]);//����
void bei(poet_list list,Manager MGER[N]);//����
void qing(poet_list list,Manager MGER[N]);//��ĩ���
void tang(poet_list list,Manager MGER[N]);//�Ƴ�
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
		printf("�޷����ļ�\n");
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
	cout<<"                                   -----------------����ʫ��-----------------"<<endl<<endl<<endl<<endl;
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
            if(s.find("����")!=std::string::npos)
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
			tail->next = new List; // �����½ڵ�
			tail = tail->next; // �ƶ�β��
			tail->Data.poet_name = p->Data.poet_name;//���ƽ���NEW����
			tail->Data.poet_info = p->Data.poet_info;
			tail->Data.poet_poem = p->Data.poet_poem;
			tail->Data.poet_life = p->Data.poet_life;
			tail->Data.poet_eval = p->Data.poet_eval;
			i++;
		}
		p=p->next;
	}
	cout<<endl<<endl<<endl<<endl<<endl<<"                                                    "<<i<<"."<<"���ز˵�"<<endl;
	cout << "����������ѡ��";
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
	cout<<"                                   -----------------��������-----------------"<<endl<<endl<<endl<<endl;
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
            if(s.find("����")!=std::string::npos)
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
			tail->next = new List; // �����½ڵ�
			tail = tail->next; // �ƶ�β��
			tail->Data.poet_name = p->Data.poet_name;//���ƽ���NEW����
			tail->Data.poet_info = p->Data.poet_info;
			tail->Data.poet_poem = p->Data.poet_poem;
			tail->Data.poet_life = p->Data.poet_life;
			tail->Data.poet_eval = p->Data.poet_eval;
			i++;
		}
		p=p->next;
	}
	cout<<endl<<endl<<endl<<endl<<endl<<"                                                    "<<i<<"."<<"���ز˵�"<<endl;
		cout << "����������ѡ��";
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
	cout<<"                                   -----------------����ʫ��-----------------"<<endl<<endl<<endl<<endl;
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
            if(s.find("����")!=std::string::npos)
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
			tail->next = new List; // �����½ڵ�
			tail = tail->next; // �ƶ�β��
			tail->Data.poet_name = p->Data.poet_name;//���ƽ���NEW����
			tail->Data.poet_info = p->Data.poet_info;
			tail->Data.poet_poem = p->Data.poet_poem;
			tail->Data.poet_life = p->Data.poet_life;
			tail->Data.poet_eval = p->Data.poet_eval;
			i++;
		}
		p=p->next;
	}
	cout<<endl<<endl<<endl<<endl<<endl<<"                                                    "<<i<<"."<<"���ز˵�"<<endl;
		cout << "����������ѡ��";
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
	cout<<"                                   -----------------����ī��-----------------"<<endl<<endl<<endl<<endl;
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
            if(s.find("����")!=std::string::npos)
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
			tail->next = new List; // �����½ڵ�
			tail = tail->next; // �ƶ�β��
			tail->Data.poet_name = p->Data.poet_name;//���ƽ���NEW����
			tail->Data.poet_info = p->Data.poet_info;
			tail->Data.poet_poem = p->Data.poet_poem;
			tail->Data.poet_life = p->Data.poet_life;
			tail->Data.poet_eval = p->Data.poet_eval;
			i++;
		}
		p=p->next;
	}
cout<<endl<<endl<<endl<<endl<<endl<<"                                                    "<<i<<"."<<"���ز˵�"<<endl;
	cout << "����������ѡ��";
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
	cout<<"                                   -----------------����ɧ��-----------------"<<endl<<endl<<endl<<endl;
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
            if(s.find("�峯")!=std::string::npos)
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
			tail->next = new List; // �����½ڵ�
			tail = tail->next; // �ƶ�β��
			tail->Data.poet_name = p->Data.poet_name;//���ƽ���NEW����
			tail->Data.poet_info = p->Data.poet_info;
			tail->Data.poet_poem = p->Data.poet_poem;
			tail->Data.poet_life = p->Data.poet_life;
			tail->Data.poet_eval = p->Data.poet_eval;
			i++;
		}
		p=p->next;
	}
	cout<<endl<<endl<<endl<<endl<<endl<<"                                                    "<<i<<"."<<"���ز˵�"<<endl;
		cout << "����������ѡ��";
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
	cout<<"                                   -----------------��ĩ���ʫ��ʿ-----------------"<<endl<<endl<<endl<<endl;
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
            if(s.find("�Ƴ�")!=std::string::npos)
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
			tail->next = new List; // �����½ڵ�
			tail = tail->next; // �ƶ�β��
			tail->Data.poet_name = p->Data.poet_name;//���ƽ���NEW����
			tail->Data.poet_info = p->Data.poet_info;
			tail->Data.poet_poem = p->Data.poet_poem;
			tail->Data.poet_life = p->Data.poet_life;
			tail->Data.poet_eval = p->Data.poet_eval;
			i++;
		}
		p=p->next;
	}
	cout<<endl<<endl<<endl<<endl<<endl<<"                                                    "<<i<<"."<<"���ز˵�"<<endl;
		cout << "����������ѡ��";
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
	printf("                                  ��        ��ӭ���롶���Ͻ�����ʫ�ʻ��¡�    ��    \n");
	printf("                                  ��        ----��ѡ���¼��ʽ----            ��    \n\n");
	printf("                                  ��            1.�ο͵�¼                    ��   \n\n");
	printf("                                  ��            2.����Ա��¼                  ��    \n\n");
	printf("                                  ��            3.�˳�ϵͳ                    ��    \n\n");
	printf("                                  ��                                          ��    \n");
	printf("                                  ********************************************\n");
}
void menu2()
{
	printf("                                  ****************************************************\n");
	printf("                                  ��              ----�˵���----                     ��    \n\n");
	printf("                                  ��            1.������֮�Ρ�--����                   ��    \n\n");
	printf("                                  ��            2.����������--����                   ��    \n\n");
	printf("                                  ��            3.����ѧ֮�硱--����                   ��    \n\n");
	printf("                                  ��            4.������֮����--����                   ��    \n\n");
	printf("                                  ��            5.���������ˡ�--��ĩ���               ��    \n\n");
	printf("                                  ��            6.��ʢ��֮�Ρ�--�Ƴ�                   ��    \n\n");
	printf("                                  ��            7.�˳�����¼����                     ��    \n\n");
	printf("                                  ��            8.�˳�ϵͳ                           ��    \n\n");
	printf("                                  ��                                                 ��    \n");
	printf("                                  ****************************************************\n");
}
void menu3() {
	printf("                                  ****************************************************\n");
	printf("                                  ��              ----�˵���----                     ��    \n\n");
	printf("                                  ��            1.����ʫ�˼�ʫ����Ϣ                   ��    \n\n");
	printf("                                  ��            2.���ӹ���Ա                           ��    \n\n");
	printf("                                  ��            3.�л��˺�                             ��    \n\n");
	printf("                                  ��            0.�˳�����¼����                       ��    \n\n");
	printf("                                  ��                                                 ��    \n");
	printf("                                  ****************************************************\n");
}
void visitor(poet_list list,Manager MGER[N])//�ο͵�¼
{
	int x,flag=0;
	while(!flag)
	{
		system("cls");
		menu2();
		cout << "����������ѡ��";
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
				cout<<"�˳�ϵͳ�ɹ���";
				exit(0);
				break;
			default:
				printf("ѡ���������������ѡ����!\n");
				system("Pause");
				break;
		}
	}
	return ;
}
void index(poet_list list,Manager MGER[N])//��¼��ҳ
{
	int x,flag=0;
	while(!flag)
	{
		system("cls");
		menu1();
		cout << "�������¼��ʽ��";
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
				cout<<"�˳�ϵͳ�ɹ���";
				exit(0);
				break;
			default:
				cout<<"ѡ���������,����������";
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
void manager(poet_list list,Manager MGER[N]) { //����Ա��¼ҳ��
	init_manager(MGER);
		string name, password;
		int i = 0;
		printf("                                  ********************************************\n");
		printf("                                  ��        ----����Ա��¼----               ��    \n");
		printf("                                  ��            �������˺�����");
		cin >> name;
		printf("                                  ��            ���������룺");
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
		printf("                                  ��                                         ��    \n");
		printf("                                  ********************************************\n");
		for (i = 0; i < N; i++) {
			if (MGER[i].name == name && MGER[i].pword == password) {
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				manager_index(list, MGER);
				return ;
			}
		}
		system("cls");
		cout << "�˺Ż������������������" << endl;
		manager(list, MGER);
		return ;
}
void manager_index(poet_list list, Manager MGER[N]) { //����Ա��ҳ
	menu3();
	cout<<"���������Ĳ�����";
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
void add_manager_infomation(poet_list list, Manager MGER[N]) { //���ӹ���Ա��Ϣ
	string name, password;
		ofstream ofs("manager_info.txt", ios::out | ios::trunc);
		if (ofs) {
			cout << "�������û�����";
			cin >> name;
			cout << "���������룺";
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
			cout << "�ѳɹ���Ӹù���Ա" << endl;
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
	cout<<"������¼��ʫ���ǳ�:";
	while(getline(std::cin,x))
	{
		x+="aa";
		data.poet_name.push_back(x);
	}

	cout<<"������¼��ʫ�˼��:";
	while(getline(std::cin,x))
	{
		x+="aa";
		data.poet_info.push_back(x);
	}
	
	cout<<"������¼��ʫ��ʫ����Ʒ:";
	while(getline(std::cin,x))
	{
		x+="aa";
		data.poet_poem.push_back(x);
	}
	
	cout<<"������¼��ʫ����ƽ��Ϣ:";
	while(getline(std::cin,x))
	{
		x+="aa";
		data.poet_life.push_back(x);
	}
	
	cout<<"������¼��ʫ����������:";
	while(getline(std::cin,x))
	{
		x+="kkk";
		data.poet_eval.push_back(x);
	}
	add_node(list,data);
}
