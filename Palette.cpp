#include<bits/stdc++.h>
#include<windows.h>
#include "Interface.h"
#include "class.h"
#include "lib.h"

using namespace std;

const int NumberOfCurrency=9;

const string options[10] = {"��¼", "ע��", "ȥ����", "�ҵ��˻�", "�ҵĹ��ﳵ", "�ҵ���Ʒ", "��ֵ", "��ѯǮ�����", "�ǳ�","ע��"};
const string currency[9] = {"�����CNY","��ԪUSD","��ԪJPY","ŷԪEUR","Ӣ��GBP","��ԪKRW","��ԪHKD","��ԪAUD","��ԪCAD"};
const double exchangeRate[9] = {1.0,6.3683,0.00539,7.2248,8.594,0.005375,0.8167,4.6227,4.9811};

extern int loginUser;
extern AllGoods shoppinglist;

void Register();
void login();
void Charge();
void AddGoods();
void DelGoods();

void printHelp()//չʾ������չʾ���˵�;
{
	if(loginUser==-1)
	{
		cout<<"<----------------->"<<endl;
		cout<<"  0:"<<options[0]<<endl<<endl;
		cout<<"��û���˻���ע��һ��"<<endl;
		cout<<"  1:"<<options[1]<<endl;
		cout<<" -1:�˳�"<<endl;
		cout<<"<----------------->"<<endl;
	}
	else
	{
		cout<<endl;
		cout<<"<----------------->"<<endl;
		int w=curUser.getAuthority();
		if(w==0)
		{
			cout<<"  0:"<<options[2]<<endl;
			cout<<"  1:"<<options[3]<<endl;
			cout<<"  2:"<<options[4]<<endl;
			cout<<"  3:"<<options[8]<<endl;
			cout<<"  4:"<<options[9]<<endl;
			cout<<" -1:�˳�"<<endl;
		}
		else if(w==1)
		{
			cout<<"  0:"<<options[2]<<endl;
			cout<<"  1:"<<options[3]<<endl;
			cout<<"  2:"<<options[4]<<endl;
			cout<<"  3:"<<options[5]<<endl;
			cout<<"  4:"<<options[8]<<endl;
			cout<<"  5:"<<options[9]<<endl;
			cout<<" -1:�˳�"<<endl;
		}
		else if(w==2)
		{
			cout<<"  0:"<<options[2]<<endl;
			cout<<"  1:"<<options[3]<<endl;
			cout<<"  2:"<<options[4]<<endl;
			cout<<"  3:"<<options[5]<<endl;
			cout<<"  4:"<<"�̳���Ϣ����"<<endl;
			cout<<"  5:"<<options[8]<<endl;
			cout<<"  6:"<<options[9]<<endl;
			cout<<" -1:�˳�"<<endl;
		}
		cout<<"<----------------->"<<endl;
	}
}

void welcome()//��ӭ;
{
	system("mode con cols=135 lines=40");
	cout<<"����������������������������������������������������������������������������������������������������������������������������������"<<endl;
	cout<<"����������������������������������������������������������������������������������������������������������������������������������"<<endl;
	cout<<"����������������������������������������������������������������������������������������������������������������������������������"<<endl;
	cout<<"����������������������������������������������������������������������������������������������������������������������������������"<<endl;
	cout<<"����������������������������������������������������������������������������������������������������������������������������������"<<endl;
	cout<<"����������������������������������������������������������������������������������������������������������������������������������"<<endl;
	cout<<"����������������������������������������������������������������������������������������������������������������������������������"<<endl;
	cout<<"����������������������������������������������������������������������������������������������������������������������������������"<<endl;
	cout<<"����������������������������������������������������������������������������������������������������������������������������������"<<endl;
	cout<<"����������������������������������������������������������������������������������������������������������������������������������"<<endl;
	cout<<"����������������������������������������������������������������������������������������������������������������������������������"<<endl;
}

void login()//��¼;
{
	string name, password, input;
	int correct=0,cmd;//��־������cmd��ʾ�û�ѡ��Ĳ�����correct��ʾ�û��Ƿ���ȷ����;
	while(true)
	{
		bool flag=1;
		while(flag)
		{
			flag=0;
			cout<<"����������û���:";
			getline(cin, input);
			if(!input.size())
			{
				cout<<"�û�������Ϊ��!"<<endl;
				flag=1;
				continue;
			}
			for(int i=0; i<input.size(); i++)
			{
				if(input[i]==' ')
				{
					cout<<"����û������ܰ����κοո�!"<<endl;
					flag=1;
					break;
				}
			}
		}
		name=input;
		flag=1;
		while(flag)
		{
			flag=0;
			cout<<"�������������:";
			input=readPass();
			if(!input.size())
			{
				cout<<"���벻��Ϊ��!"<<endl;
				flag=1;
				continue;
			}
			for(int i=0; i<input.size(); i++)
			{
				if(input[i]==' ')
				{
					cout<<"������벻�ܰ����κοո�!"<<endl;
					flag=1;
					break;
				}
			}
		}
		password=input;
		correct=LoginInterface(name,password);//correctȷ���û��Ƿ�������ȷ;
		if(correct==0)
		{
			cout<<"�Ƿ��û���";
			Sleep(1000ul);
			cout<<endl<<endl;
		}
		else if(correct==-1)
		{
			cout<<"�������!";
			Sleep(1000ul);
			cout<<endl<<endl;
		}
		else if(correct>0)
			break;
		cout<<"<----------------->"<<endl;
		cout<<"  0:���µ�¼"<<endl;
		cout<<"  1:ע��"<<endl;
		cout<<" -1:������һ��"<<endl;
		cout<<"<----------------->"<<endl;
		cout<<">>>>";
		cmd=readint();
		switch (cmd)
		{
			case 0:
				break;
			case 1:
				Register();
				break;
			case -1:
				correct=1;
				break;
			default:
				cout<<"������һ��0��2֮�������!"<<endl;
				correct=-2;
				break;
		}
	}
	if(curUser.getBanned())
	{
		cout<<"��ǰ�˻��ѱ����������������ѯ�ʹ���Ա��";
		curUser.logOut();
		Sleep(1000ul);
		cout<<endl<<endl;
	}
}

void Register()//ע��;
{
	cout<<endl;
	string newname,input,input2,newpassword,confirmpassword,phoneNumber;//����������ı����Լ����������ݴ����;
	bool flag=1,correct=1;//��־������cmd��ʾ�û�ѡ��Ĳ�����correct��ʾ�û��Ƿ���ȷ����;
	int type;//Ȩ��;

	while(flag)
	{
		flag=0;
		cout<<"�������û���:";
		getline(cin, input);
		if(!input.size())
		{
			cout<<"�û�������Ϊ��!"<<endl;
			flag=1;
			continue;
		}
		for(int i=0; i<input.size(); i++)
		{
			if(input[i]==' ')
			{
				cout<<"����û������ܰ����κοո�!"<<endl;
				flag=1;
				break;
			}
		}
		if(!checkUserInterface(input))
		{
			cout<<"�û����ѱ�ʹ�á�"<<endl;
			flag=1;
		}
	}
	newname=input;
	if(newname[0]=='_'&&newname[1]=='_')type=2;//ע��ʱ�û�����ͷ�����ַ��ǡ�__���������ɹ���Ա�˻���
	else
	{
		flag=1;
		while(flag)
		{
			flag=0;
			cout<<"��ѡ���˻�����:"<<endl;
			cout<<"<----------------->"<<endl;
			cout<<"  0:���"<<endl;
			cout<<"  1:����"<<endl;
			cout<<"<----------------->"<<endl;
			type=readint();
			if(type<0||type>1)
			{
				cout<<"������һ��0��1֮�������!";
				flag=1;
				Sleep(1000ul);
				cout<<endl<<endl;
				break;
			}
		}
	}

	flag=1;
	while(flag)
	{
		flag=0;
		cout<<"����������:";
		input=readPass();
		if(!input.size())
		{
			cout<<"���벻��Ϊ��!"<<endl;
			flag=1;
			continue;
		}
		for(int i=0; i<input.size(); i++)
		{
			if( ( (input[i]>'9')||(input[i]<'0') )&&( (input[i]>'Z')||(input[i]<'A') )&&( (input[i]>'z')||(input[i]<'a') ) )
			{
				cout<<"�������ֻ�ܰ���Ӣ����ĸ������!"<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<"ȷ������:";
			input2=readPass();
			for(int i=0; i<input2.size(); i++)
				if( ( (input2[i]>'9')||(input2[i]<'0') )&&( (input2[i]>'Z')||(input2[i]<'A') )&&( (input2[i]>'z')||(input2[i]<'a') ) )
				{
					cout<<"�������Ӧ��ֻ������ĸ������!"<<endl;
					flag=1;
					break;
				}
			if(flag==0)
			{
				for(int i=0; i<max(input.size(),input2.size()); i++)
				{
					if(input[i]!=input2[i])
					{
						cout<<"�������벻һ��!"<<endl;
						flag=1;
						break;
					}
				}
			}

		}


	}
	newpassword=input;

	flag=1;
	while(flag)
	{
		flag=0;
		cout<<"��������ĵ绰����:";
		getline(cin, input);
		for(int i=0; i<input.size(); i++)
			if((input[i]<'0')||input[i]>'9')
			{
				cout<<"��ĵ绰����Ӧ��ֻ��������!"<<endl<<endl;
				flag=1;
				break;
			}
		if(input.size()!=11)
		{
			cout<<"�绰����Ӧ����ʮһλ�ģ�"<<endl;
			flag=1;
		}

	}
	phoneNumber=input;
	registerInterface(newname,type,newpassword,phoneNumber);
	cout<<"ע��ɹ�!"<<endl<<endl;
	return;

}

void ResetPass()//��������;
{
	string inputold,inputnew,inputnew2;
	bool correct=1,cohere=1;//��־������cohere��־�Ⱥ�����������������Ƿ�һ�£�correct��ʾ�û��Ƿ���ȷ����;
	while(correct)
	{
		correct=0;
		cout<<"�����������:";
		inputold=readPass();
		if(!inputold.size())
		{
			cout<<"���벻��Ϊ��!"<<endl;
			correct=1;
			continue;
		}
		for(int i=0; i<inputold.size(); i++)
		{
			if( ( (inputold[i]>'9')||(inputold[i]<'0') )&&( (inputold[i]>'Z')||(inputold[i]<'A') )&&( (inputold[i]>'z')||(inputold[i]<'a') ) )
			{
				cout<<"��ľ�����Ӧ��ֻ������ĸ������!"<<endl<<endl;
				correct=1;
				break;
			}
		}
	}
	while(cohere)
	{
		correct=1;
		cohere=0;
		while(correct)
		{
			correct=0;
			cout<<"������������:";
			inputnew=readPass();
			if(!inputnew.size())
			{
				correct=1;
				cout<<"���벻��Ϊ��!"<<endl;
				continue;
			}
			for(int i=0; i<inputnew.size(); i++)
				if( ( (inputnew[i]>'9')||(inputnew[i]<'0') )&&( (inputnew[i]>'Z')||(inputnew[i]<'A') )&&( (inputnew[i]>'z')||(inputnew[i]<'a') ) )
				{
					cout<<"���������Ӧ��ֻ������ĸ������!"<<endl<<endl;
					correct=1;
					break;
				}
		}
		correct=1;
		while(correct)
		{
			correct=0;
			cout<<"ȷ��������:";
			inputnew2=readPass();
			for(int i=0; i<inputnew2.size(); i++)
				if( ( (inputnew2[i]>'9')||(inputnew2[i]<'0') )&&( (inputnew2[i]>'Z')||(inputnew2[i]<'A') )&&( (inputnew2[i]>'z')||(inputnew2[i]<'a') ) )
				{
					cout<<"���������Ӧ��ֻ������ĸ������!"<<endl<<endl;
					correct=1;
					break;
				}
		}
		for(int i=0; i<max(inputnew.size(),inputnew2.size()); i++)
		{
			if(inputnew[i]!=inputnew2[i])
			{
				cout<<"�������벻һ��!"<<endl;
				cout<<"����������������!"<<endl<<endl;
				cohere=1;
				break;
			}
		}
		if(cohere)continue;
		correct=ResetPassInterface(inputold,inputnew2);
		if(!correct)
			cout<<"���������!"<<endl<<endl;
		else
			cout<<"���óɹ�!"<<endl<<endl;
	}
}
void ResetName()//�����û���;
{
	bool flag=1;
	string input;
	while(flag)
	{
		flag=0;
		cout<<"������������û���:";
		getline(cin, input);
		if(!input.size())
		{
			cout<<"�û�������Ϊ��!"<<endl;
			flag=1;
			continue;
		}
		for(int i=0; i<input.size(); i++)
			if(input[i]==' ')
			{
				cout<<"����û�����Ӧ�ð����κοո�!"<<endl<<endl;
				flag=1;
				break;
			}
	}
	ResetNameInterface(input);
	cout<<"�û������óɹ�!"<<endl<<endl;
}


void GoShopping()//ȥ����;
{
	cout<<endl;
	shoppinglist.showAllInfo();
	int cmd=0;//��־������cmd��־�û�ѡ��Ĳ���;
	cout<<"ѡ����Ĳ���:"<<endl;
	cout<<"<----------------->"<<endl;
	cout<<"  1:���۸��С����������Ʒ"<<endl;
	cout<<"  2:�������Ӵ�С������Ʒ"<<endl;
	cout<<"  3:���۸�ɸѡ��Ʒ"<<endl;
	cout<<"  4:ֱ�ӿ�ʼѡ��"<<endl;
	cout<<" -1:������һ��"<<endl;
	cout<<"<----------------->"<<endl;
	AllGoods selected=shoppinglist;
	while(!cmd)
	{
		cout<<">>>>";
		cmd=readint();
		int low=0,high=0;
		switch (cmd)
		{
			case 1:
				selected.sortByPrice();
				GoShoppingInterface(selected);
				break;
			case 2:
				selected.sortBySalesVolume();
				GoShoppingInterface(selected);
				break;
			case 3:
				cout<<"����������ɸѡ����ͼ۸�: ";
				low=readint();
				cout<<"����������ɸѡ����߼۸�:";
				high=readint();
				cout<<endl;
				selected=shoppinglist.selectByPrice(low,high);
				GoShoppingInterface(selected);
				break;
			case 4:
				GoShoppingInterface(selected);
				break;
			case -1:
				return;
			default:
				cmd=0;
				break;
		}
	}
}


void ShowMyInformation()//չʾ������Ϣ;
{
	cout<<endl;
	ShowMyInformationInterface();
	int cmd=0;//��־������cmd��־�û�ѡ��Ĳ���;
	cout<<"ѡ����Ĳ���:"<<endl;
	cout<<"<----------------->"<<endl;
	cout<<"  1:��ֵ"<<endl;
	cout<<"  2:�����û���"<<endl;
	cout<<"  3:��������"<<endl;
	cout<<" -1:������һ��"<<endl;
	cout<<"<----------------->"<<endl;
	while(!cmd)
	{
		cout<<">>>>";
		cmd=readint();
		switch (cmd)
		{
		case 1:
			Charge();
			break;
		case 2:
			ResetName();
			break;
		case 3:
			ResetPass();
			break;
		case -1:
			return;
		default:
			cmd=0;
			break;
		}
	}
}


void MyShoppingCar()//�ҵĹ��ﳵ;
{
	MyShoppingCarInterface();
	cout<<"ѡ����Ĳ���:"<<endl;
	cout<<"<----------------->"<<endl;
	cout<<"  1:����"<<endl;
	cout<<"  2:ɾ����Ʒ"<<endl;
	cout<<" -1:������һ��"<<endl;
	cout<<"<----------------->"<<endl;
	int cmd,ID;//cmd��ʾ�û�ѡ��Ĳ�����ID����д���û��������ID;
	bool flag=1;
	cout<<">>>>";
	cmd=readint();
	while(cmd!=-1)
	{
		switch(cmd)
		{
			case 1:
				if(CheckOutInterface())
				{
					cout<<"����ɹ�!";
					Sleep(1000ul);
					cout<<endl<<endl;
				}
				else
				{
					cout<<"����!���ֵ";
					Sleep(1000ul);
					cout<<endl<<endl;
				}
				break;
			case 2:
				cout<<"����������ɾ������ƷID:";
				ID=readint();
				if(!DelGoodsFromShoppingCarInterface(ID))
				{
					cout<<"�����ڵ���ƷID!";
					Sleep(1000ul);
					cout<<endl<<endl;
				}
				break;
			case -1:
				break;
			default:
				cout<<"������1��2��-1!";
				Sleep(1000ul);
				cout<<endl<<endl;                    
				break;
		}
		MyShoppingCarInterface();
		cout<<"ѡ����Ĳ���:"<<endl;
		cout<<"<----------------->"<<endl;
		cout<<"  1:����"<<endl;
		cout<<"  2:ɾ����Ʒ"<<endl;
		cout<<" -1:������һ��"<<endl;
		cout<<"<----------------->"<<endl;
		cout<<">>>>";
		cmd=readint();
	}
}

void MyGoods()//չʾ���˵���Ʒ;
{
	cout<<"�����������Ʒ: "<<endl<<endl;
	MyGoodsInterface();
	int cmd=0,ID;
	Goods temp;
	cout<<"<----------------->"<<endl;
	cout<<"ѡ�����Ĳ���:"<<endl;
	cout<<"  0:�����Ʒ"<<endl;
	cout<<"  1:ɾ����Ʒ"<<endl;
	cout<<" -1:������һ��"<<endl;
	cout<<"<----------------->"<<endl;
	while(cmd!=-1)
	{
		cout<<">>>>";
		cmd=readint();
		switch (cmd)
		{
		case 0:
			AddGoods();
			cout<<"��ӳɹ�!";
			Sleep(1000ul);
			cout<<endl<<endl;
			break;
		case 1:
			DelGoods();
			break;
		case (-1):
			break;
		default:
			cout<<"������һ��0��1֮�������!"<<endl;
			cout<<"������-1��������һ��";
			Sleep(1000ul);
			cout<<endl<<endl;
			cmd=0;
			break;

		}
		cout<<"�����������Ʒ: "<<endl;
		MyGoodsInterface();
		cout<<"<----------------->"<<endl;
		cout<<"ѡ�����Ĳ���:"<<endl;
		cout<<"  0:�����Ʒ"<<endl;
		cout<<"  1:ɾ����Ʒ"<<endl;
		cout<<" -1:������һ��"<<endl;
		cout<<"<----------------->"<<endl;
	}
}


void Charge()//��ֵ;
{
	int cmd;//cmd��־�û�ѡ��Ĳ�����numд���û�����Ľ��;
	double num=0;
	bool correct=0;
	string input;
	while(true)
	{
		cout<<"��ѡ��֧����ʹ�õĻ���:"<<endl;
		for(int i=0; i<NumberOfCurrency; i++)
			cout<<"  "<<i<<":"<<currency[i]<<endl;
		cout<<">>>>";
		cmd=readint();
		if(cmd<0||cmd>=NumberOfCurrency)
		{
			cout<<"������һ��0��"<<NumberOfCurrency-1<<"֮�������!";
			Sleep(1000ul);
			cout<<endl<<endl;
			continue;
		}
		break;
	}
	while(true)
	{
		cout<<"�������ֵ���:";
		num=readDouble();
		if(num<0)
		{
			cout<<"ֻ����������!"<<endl<<endl;
			continue;
		}
		break;
	}
	num*=exchangeRate[cmd];
	ChargeInterface(num);
}


void Logout()//�ǳ�;
{
	LogoutInterface();
}


void AddGoods()//�����Ʒ;
{
	string input;//��ӵ���Ʒ������;
	double price;//��ӵ���Ʒ�ļ۸�;
	bool flag=1;
	while(flag)
	{
		flag=0;
		cout<<"��������Ʒ��:";
		getline(cin, input);
		if(!input.size())
		{
			cout<<"��Ʒ������Ϊ��!"<<endl;
			flag=1;
			continue;
		}
		for(int i=0; i<input.size(); i++)
		{
			if(input[i]==' ')
			{
				cout<<"�����Ʒ�����ܰ����κοո�!"<<endl;
				flag=1;
				break;
			}
		}
	}
	cout<<"��������Ʒ�۸�:";
	price=readDouble();
	AddGoodsInterface(input,price);
}


void DelGoods()//ɾ����Ʒ;
{
	cout<<"����������ɾ������Ʒ���:";
	int Id,flag=0;//
	Goods temp;
	Id=readint();
	if(!curUser.queryMyGoods(Id))
	{
		cout<<"�Ƿ���Ʒ���!"; // ���ID�Ƿ���ȷ
		Sleep(1000ul);
		cout<<endl<<endl;
		return;
	}
	cout<<"ȷ��ɾ����"<<endl;
	cout<<"����1��ȷ�ϣ��������������˳�"<<endl;
	cout<<">>>>";
	flag=readint();
	switch (flag)
	{
		case 1:
			temp=DelGoodsInterface(Id);
			if(temp.getName()!="Not Found")
				cout<<temp.getName()<<"�ѳɹ�ɾ��!";
			Sleep(1000ul);
			cout<<endl<<endl;
			break;
		default :
			break;
	}

}


void Cancell()//ע���˻�;
{
	string input;
	bool flag=1;
	int w=0;
	cout<<"�����Ҫ����ע���˻���"<<endl;
	cout<<"����1��ȷ�ϣ��������������˳�"<<endl<<endl;
	cout<<">>>>";
	w=readint();
	if(w==1)
	{
		while(flag)
		{
			flag=0;
			cout<<"����������:";
			input=readPass();
			for(int i=0; i<input.size(); i++)
			{
				if( ( (input[i]>'9')||(input[i]<'0') )&&( (input[i]>'Z')||(input[i]<'A') )&&( (input[i]>'z')||(input[i]<'a') ) )
				{
					cout<<endl<<"�������Ӧ�ý������ֺʹ�Сд��ĸ���!"<<endl<<endl;
					flag=1;
					break;
				}
			}
		}
		bool q=CancellInterface(input);
		if(!q)
		{
			cout<<"ע���ɹ�!��л�������!";
			Logout();
			Sleep(1000ul);
			cout<<endl<<endl;
			return;
		}
		else
		{
			cout<<"�������!";
			Sleep(1000ul);
			cout<<endl<<endl;
		} 
	}
	return;
}


void ShowMeEverything()//������Աʹ��:չʾ�̳�������Ϣ;
{

	ShowMeEverythingInterface();
	cout<<"������ѡ��:"<<endl;
	cout<<"<----------------->"<<endl;
	cout<<"  1:����û�"<<endl;
	cout<<"  2:����û�"<<endl;
	cout<<" -1:������һ��"<<endl;
	cout<<"<----------------->"<<endl;
	int Id=0, cmd=0;
	while(!cmd)
	{
		cout<<">>>>";
		cmd=readint();
		bool w;
		switch (cmd)
		{
			case 1:
				cout<<"���������������û���Id:";
				Id=readint();
				if(Id==curUser.getId()) 
				{
					cout<<"�����ڳ��Է�����Լ�����";
					Sleep(1000ul);
					cout<<endl<<endl;
				}
				else
				{
					w=banUserInterface(Id,0);
					if(w) cout<<"����ɹ���"<<endl;
					else cout<<"��Id�����ڣ�";
					Sleep(1000ul);
					cout<<endl<<endl;
				}
				break;
			case 2:
				cout<<"��������������û���Id:";
				Id=readint();
				w=banUserInterface(Id,1);
				if(w) cout<<"���ɹ���"<<endl;
				else cout<<"��Id�����ڣ�";
				Sleep(1000ul);
				cout<<endl<<endl;
				break;
			case -1:
				return;
			default:
				cout<<"������һ��1��2֮�����������-1!";
				cmd=0;
				break;
		}
	}
}
