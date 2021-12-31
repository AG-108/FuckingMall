#include<bits/stdc++.h>
#include<windows.h>
#include "class.h"
#include "DatabaseHandle.h"
#include "Palette.h"
#include "lib.h"

using namespace std;

extern int loginUser;
extern AllGoods shoppinglist;

Goods::Goods()
{
	id=price=salesVolume=0;
	string name="";
}

Goods::Goods(int newId,string newname,double newprice,int newSalesVolume,int slr)
{
	id=newId;
	name=newname;
	price=newprice;
	salesVolume=newSalesVolume;
	seller=slr;
}

istream& operator >> (istream &in, Goods &A)
{
	in >> A.id >> A.name >> A.salesVolume >> A.price >> A.seller;
	return in;
}

ostream& operator << (ostream &out, Goods &A)
{
	out << A.id << ' ' << A.name << ' ' << A.salesVolume << ' ' << A.price << ' ' << A.seller << endl;
	return out;
}

void Goods::setName(string newname)
{
	name=newname;
}

void Goods::setPrice(double newprice)
{
	price=newprice;
}

int Goods::getId()
{
	return id;
}

double Goods::getPrice()
{
	return price;
}

string Goods::getName()
{
	return name;
}

int Goods::getSeller()
{
	return seller;
}

void Goods::printInfo()
{
	cout << setw(5) << id << ' ';
	cout << setw(20) << name <<' ';
	cout << setw(15) << fixed << setprecision(2) << price << ' ';
	cout << setw(5) << salesVolume << endl;
	return;
}

void Goods::SVinc()
{
	salesVolume++;
}

bool cmpById(Goods a,Goods b)
{
	return a.id<b.id;
}

bool cmpByPrice(Goods a,Goods b)
{
	return a.price<b.price;
}

bool cmpBySalesVolume(Goods a,Goods b)
{
	return a.salesVolume>b.salesVolume;
}

AllGoods::AllGoods()
{
	//�չ��캯��
}

istream& operator >> (istream &in, AllGoods &A)
{
	int sizeOfQueue;
	extern int GoodsID;
	Goods temp;
	in >> sizeOfQueue >> GoodsID; // ������goodsList��С����GoodsID
	for(int i=1;i<=sizeOfQueue;i++)
	{
		in >> temp; // ����ÿһ����Ʒ
		A.goodsList.push(temp);
	}
	return in;
}

ostream& operator << (ostream &out, AllGoods &A)
{
	extern int GoodsID;
	out << A.goodsList.size() << ' ' << GoodsID << endl; // �����goodsList��С����GoodsID
	while(A.goodsList.size())
	{
		out << A.goodsList.front(); // ���ÿһ����Ʒ
		A.goodsList.pop();
	}
	return out;
}

int AllGoods::getsize()
{
	return goodsList.size();
}

void AllGoods::showAllInfo()
{
	int sizeOfQueue=goodsList.size();
	cout<<endl<<"<---------------------��Ʒ�б�--------------------->"<<endl;
	cout<<"��"<<sizeOfQueue<<"����Ʒ"<<endl<<endl;
	cout<<setw(5)<<"ID"<<' ';
	cout<<setw(20)<<"����"<<' ';
	cout<<setw(15)<<"�۸�"<<' ';
	cout<<setw(5)<<"����"<<endl;
	for(int i=1;i<=sizeOfQueue;i++)
	{
		goodsList.front().printInfo();
		goodsList.push(goodsList.front());
		goodsList.pop();
	}
	cout<<endl<<"<------------------------------------------------->"<<endl;
	return;
}

void AllGoods::addGoods(Goods temp)
{

	goodsList.push(temp);
	return;
}

Goods AllGoods::delGoods(int id)
{
	Goods ret(0,"Not Found",0,0,0);
	int sizeOfQueue=goodsList.size();
	for(int i=1;i<=sizeOfQueue;i++)
	{
		if(goodsList.front().getId()==id)
		{
			ret=goodsList.front();
			goodsList.pop();
		}
		else
		{
			goodsList.push(goodsList.front());
			goodsList.pop();
		}
	}
	return ret;
}

Goods AllGoods::queryGoods(int id)
{
	Goods ret(0,"Not Found",0,0,0); // �Ҳ���IDʱ��Ĭ�Ϸ���ֵ
	int sizeOfQueue = goodsList.size();
	/*--------------------------

	����goodsList��Ѱ����ͬID����Ʒ

	--------------------------*/
	for(int i=1;i<=sizeOfQueue;i++)
	{
		if(goodsList.front().getId()==id)
		{
			ret=goodsList.front();
		}
		goodsList.push(goodsList.front());
		goodsList.pop();
	}
	return ret;
}

void AllGoods::incSV(int id)
{
	int sizeOfQueue = goodsList.size();
	for(int i=1;i<=sizeOfQueue;i++)
	{
		if(goodsList.front().getId()==id)
		{
			goodsList.front().SVinc();
			return;
		}
		goodsList.push(goodsList.front());
		goodsList.pop();
	}
}

void AllGoods::sortById()
{
	/*--------------------------

	��goodsList��ID��С����

	--------------------------*/
	int sizeOfQueue = goodsList.size();
	Goods *temp = new Goods[sizeOfQueue]; // Ϊ�����������ʱ����
	for(int i=0;i<sizeOfQueue;i++)
	{
		temp[i]=goodsList.front(); // ������Ԫ�ش�Ԫ����ȡ��
		goodsList.pop();
	}
	sort(temp,temp+sizeOfQueue,cmpById); // ����STL��sort��������
	for(int i=0;i<sizeOfQueue;i++)
		goodsList.push(temp[i]); // ��Ԫ����������������
	delete [] temp; // �ͷſռ�
	return;
}

void AllGoods::sortByPrice()
{
	/*--------------------------

	��goodsList���۸��С����

	--------------------------*/
	int sizeOfQueue = goodsList.size(); // Ϊ�����������ʱ����
	Goods *temp = new Goods[sizeOfQueue];
	for(int i=0;i<sizeOfQueue;i++)
	{
		temp[i]=goodsList.front(); // ������Ԫ�ش�Ԫ����ȡ��
		goodsList.pop();
	}
	sort(temp,temp+sizeOfQueue,cmpByPrice); // ����STL��sort��������
	for(int i=0;i<sizeOfQueue;i++)
		goodsList.push(temp[i]); // ��Ԫ����������������
	delete [] temp; // �ͷſռ�
	return;
}

void AllGoods::sortBySalesVolume()
{
	/*--------------------------

	��goodsList��������С����

	--------------------------*/
	int sizeOfQueue = goodsList.size();
	Goods *temp = new Goods[sizeOfQueue]; // Ϊ�����������ʱ����
	for(int i=0;i<sizeOfQueue;i++)
	{
		temp[i]=goodsList.front(); // ������Ԫ�ش�Ԫ����ȡ��
		goodsList.pop();
	}
	sort(temp,temp+sizeOfQueue,cmpBySalesVolume); // ����STL��sort��������
	for(int i=0;i<sizeOfQueue;i++)
		goodsList.push(temp[i]); // ��Ԫ����������������
	delete [] temp; // �ͷſռ�
	return;
}

AllGoods AllGoods::selectByPrice(double l,double r)
{
	/*--------------------------

	��goodsList�����ڼ۸���������Ʒȡ�������Ϊһ��AllGoods���󣬲�����

	--------------------------*/
	AllGoods ret=AllGoods(); // ����ֵ��ʼ��
	int sizeOfQueue = goodsList.size();
	for(int i=1;i<=sizeOfQueue;i++) // ����goodsList
	{
		if(l<=goodsList.front().getPrice()&&goodsList.front().getPrice()<=r)
			ret.addGoods(goodsList.front());
		goodsList.push(goodsList.front());
		goodsList.pop();
	}
	return ret;
}

shoppingCar::shoppingCar()
{}

void shoppingCar::showAllInfo()
{
	Goods tmp;
	cout<<"<--------------------�ҵĹ��ﳵ-------------------->"<<endl<<endl;
	int sizeOfQueue=contents.size();
	if(!sizeOfQueue)
		cout<<"   ���ﻹʲôҲû����!��ȥ�����!   "<<endl;
	else
	{
		cout<<"��"<<sizeOfQueue<<"����Ʒ"<<endl<<endl;
		cout<<setw(5)<<"ID"<<' ';
		cout<<setw(20)<<"����"<<' ';
		cout<<setw(15)<<"�۸�"<<' ';
		cout<<setw(5)<<"����"<<endl;
		for(int i=1;i<=sizeOfQueue;i++)
		{
			tmp = shoppinglist.queryGoods(contents.front().first);
			tmp.printInfo();cout<<"     ����: "<<contents.front().second << endl;
			contents.push(contents.front());contents.pop();
		}
	}
	cout<<endl<<"<------------------------------------------------->"<<endl;
}

void shoppingCar::addGoods(int id) // �����Ʒ
{
	int sizeOfQueue = contents.size();
	for(int i=1;i<=sizeOfQueue;i++)
		if(contents.front().first==id) //�����Ʒ�Ѵ����ڹ��ﳵ�У���ʹ������+1
		{
			contents.front().second++;
			return;
		}
	/*--------------------------

	����Ʒ���ڹ��ﳵ�У��������������б��в���
	���Ҳ���˵��ID���Ϸ�����������빺�ﳵ���趨����Ϊ1

	--------------------------*/
	if(shoppinglist.queryGoods(id).getId()==-1)
	{
		cout<<"�����ڵ���Ʒ���!"<<endl;
		return;
	}
	contents.push(make_pair(id,1));
	return;
}

bool shoppingCar::delGoods(int id)
{
	/*--------------------------

	����contents���ҵ�ƥ����Ʒ�󽫸���ɾ��
	���Ҳ��������κβ���
	�����Ƿ��ҵ���Ʒ

	--------------------------*/
	int sizeOfQueue = contents.size();
	bool findID=0;
	for(int i=1;i<=sizeOfQueue;i++)
	{
		if(contents.front().first==id)
		{
			findID=1;
			contents.front().second=0;
		}
		if(contents.front().second)
			contents.push(contents.front());
		contents.pop();
	}
	return findID;
}

bool shoppingCar::payOff()
{
	/*--------------------------

	����

	����ͳ�ƹ��ﳵ��Ʒ�ܼ�ֵ���뵱ǰ�˻�������Ƚ�
	���㹻ֱ�ӽ��ˣ�����1
	���򷵻�0���������κ���������

	--------------------------*/
	int sizeOfQueue = contents.size();
	double totPrice = 0;
	Goods curGoods;
	Account Seller;
	/*--------------------------

	ͳ�ƹ��ﳵ��Ʒ�ܼ�ֵ

	--------------------------*/
	for(int i=1;i<=sizeOfQueue;i++)
	{
		totPrice+=shoppinglist.queryGoods(contents.front().first).getPrice()*contents.front().second;
		contents.push(contents.front());
		contents.pop();
	}

	if(totPrice>curUser.getBalance()) // �����Ƚ�
		return 0;

	/*--------------------------

	���˻��м�ȥ��Ҫ֧���Ľ��
	��չ��ﳵ
	����Ӧ�ʽ�������˻���

	--------------------------*/
	curUser.pay(totPrice);
	while(contents.size())
	{
		for(int i=1;i<=contents.front().second;i++) // ����contents
		{
			shoppinglist.incSV(contents.front().first);
			curGoods=shoppinglist.queryGoods(contents.front().first);
			Seller=queryUser(curGoods.getSeller()); // ȡ�����Ҷ���
			Seller.charge(curGoods.getPrice()); // Ϊ�����˻������ʽ�
			Load(Seller); // ���������˻�
		}
		contents.pop();
	}
	return 1;
}

void shoppingCar::clear()
{
	while(contents.size())
		contents.pop();
	return;
}

Account::Account()
{
	authority=id=balance=0;banned=0;
	userName="";password="";
}

Account::Account(int val)
{
	id=val;
	authority=balance=0;banned=0;
	userName="";password="";
}

Account::Account(int ID,string newname,int type,string newpassword,string phoneNum,bool ban)
{
	id = ID;
	userName = newname;
	authority = type;
	password = newpassword;
	balance = 0;
	phoneNumber = phoneNum;
	banned = ban;
}

istream& operator >> (istream &in, Account &A)
{
	int sizeOfQueue, myg;
	in >> A.id >> A.userName >> A.balance >> A.password >> A.authority >> A.phoneNumber >> A.banned >> sizeOfQueue;
	for(int i=1;i<=sizeOfQueue;i++)
	{
		in >> myg;
		A.myGoods.push(myg);
	}
	return in;
}

ostream& operator << (ostream &out, Account &A)
{
	out << A.id << ' ' << A.userName << ' ' << A.balance << ' ' << A.password << ' ' << A.authority << ' '<< A.phoneNumber << ' ' << A.banned << endl;
	out << A.myGoods.size() << ' ';
	while(A.myGoods.size())
	{
		out << A.myGoods.front() << ' ';
		A.myGoods.pop();
	}
	out << endl;
	return out;
}

int Account::getId()
{
	return id;
}

double Account::getBalance()
{
	return balance;
}

int Account::getAuthority()
{
	return authority;
}

string Account::getName()
{
	return userName;
}

string Account::getPassword()
{
	return password;
}

bool Account::getBanned()
{
	return banned;
}

void Account::pay(double num) // ֧��
{
	balance-=num;
	return;
}

void Account::charge(double number) // ��ֵ
{
	balance+=number;
	return;
}

void Account::setBanned(bool newStat)
{
	banned=newStat;
	return;
}

bool Account::resetUserName(string newname)
{
	userName=newname;
	return 0;
}

bool Account::resetPassword(string passwd,string newpasswd)
{
	if(passwd==password)
	{
		password=newpasswd;
		return 1;
	}
	return 0;
}

void Account::logOut()
{
	/*--------------------------

	�ǳ�����
	��ԭ�������������ص�ǰ�˻�

	--------------------------*/
	extern int loginUser;
	extern Account curUser;
	Load(curUser); // �����˻�
	loginUser = -1; // ��ԭloginUser
	id = balance = banned = 0; // ��ԭid, balance��banned
	userName = ""; // ��ԭuserName
	curUser = Account(); // ��ԭcurUser
	return;
}

void Account::queryMyInfo()
{
	const string tp[3]={"���","����","����Ա"};
	cout<<"         �û���: "<<userName<<endl;
	cout<<"       �˻�����: "<<tp[authority]<<endl;
	cout<<fixed<<setprecision(2)<<"  Ǯ�����(CNY): "<<balance<<endl;
	cout<<"         �û�ID: "<<setw(10)<<setfill('0')<<id<<endl;
	cout<<setfill(' ');
	cout<<"         �ֻ���: "<<phoneNumber<<endl;
	return;
}

void Account::printInTable()
{
	const string tp[3]={"���","����","����Ա"};
	cout<<setw(20)<<userName<<' ';
	cout<<setw(20)<<tp[authority]<<' ';
	cout<<fixed<<setprecision(2)<<setw(20)<<balance<<' ';
	cout<<setw(10)<<setfill('0')<<id<<' ';
	cout<<setfill(' ');
	cout<<setw(20)<<phoneNumber<<' ';
	cout<<setw(10)<<(banned?"�ѷ��":"����")<<endl;
	return;
}

void Account::shopping(AllGoods curShoppingList)
{
	/*--------------------------

	���﹦�ܣ��ڶ��㣩
	����ǰ��ȡ�����б����

	--------------------------*/
	int cmd=0;
	Goods target;
	while(cmd!=-1)
	{
		curShoppingList.showAllInfo();
		cout<<"ѡ����Ĳ���:"<<endl;
		cout<<"<----------------->"<<endl;
		/*--------------------------

		Ϊ��ֹ�����ͻ����ָ���Ϊ����

		--------------------------*/
		cout<<" -2:��id��С����������Ʒ"<<endl;
		cout<<" -3:���۸��С����������Ʒ"<<endl;
		cout<<" -4:�������Ӵ�С������Ʒ"<<endl;
		cout<<" -1:������һ��"<<endl;
		cout<<"<----------------->"<<endl;
		cout<<"�Ӳ˵���ѡ��ָ���ֱ��������ƷID��������������Ĺ��ﳵ��"<<endl;
		cout<<">>>>";
		cmd=readint();
		int low=0,high=0;
		switch (cmd)
		{
			case -2:
				curShoppingList.sortById();
				continue;
				break;
			case -3:
				curShoppingList.sortByPrice();
				continue;
				break;
			case -4:
				curShoppingList.sortBySalesVolume();
				continue;
				break;
			case -1:
				return;
			default:
				/*--------------------------

				����Ϊ�κ��������������ֵΪ��ƷID�Ŀ���

				�ȼ�����Ϸ��ԣ����Ϸ��򽫸���Ʒ���빺�ﳵ

				--------------------------*/
				target=curShoppingList.queryGoods(cmd);
				if(target.getName()=="Not Found")
				{
					cout<<"�����ڵ���ƷID!";
					Sleep(1000ul);
					cout<<endl<<endl;
				}
				else if(target.getSeller()==loginUser)
				{
					cout<<"���̳��������ˢ����Ϊ!�������г�����!";
					Sleep(1000ul);
					cout<<endl<<endl;
				}
				else
					curShoppingCar.addGoods(cmd);
				break;
		}
	}
	return;
}

bool Account::cancell(string passwd)
{
	/*--------------------------

	ע��

	--------------------------*/
	extern int loginUser;
	extern int Cancelled;
	if(passwd==password)
	{
		delUser(loginUser); //����������ȷ�Ϸ���ע��
		while(myGoods.size()) // �¼����й�����Ʒ
			curUser.DelGoods(myGoods.front());
		Cancelled++; // ע���û���+1
	}
	else return 1;
	return 0;
}

bool Account::queryMyGoods(int id)
{
	/*--------------------------

	����myGoods����һ�Ƚ�ID
	�ҵ�����1��δ�ҵ�����0

	--------------------------*/
	bool findID=0;
	for(int i=1;i<=myGoods.size();i++)
	{
		if(myGoods.front()==id)
			findID=1;
		myGoods.push(myGoods.front());
		myGoods.pop();
	}
	return findID;
}

bool Account::AddGoods(string name,double price)
{
	/*--------------------------

	�ҳ���Ʒ������Ϣ

	--------------------------*/
	extern AllGoods shoppinglist;
	extern int GoodsID;
	if(!authority) //ֻ�����Һ͹���Ա��Ȩ����
	{
		cout<<"�Ƿ�����!"<<endl;
		cout<<"Ȩ��Ҫ��:���Ҽ�����Ա"<<endl;
		return 1;
	}
	shoppinglist.addGoods(Goods(++GoodsID,name,price,0,id)); // ����shoppinglist��addGoods����
	myGoods.push(GoodsID);
	return 0;
}

Goods Account::DelGoods(int id)
{
	/*--------------------------

	�¼���Ʒ
	���ر��¼ܶ���

	--------------------------*/
	extern AllGoods shoppinglist;
	if(!authority)
	{
		cout<<"�Ƿ�����!"<<endl;
		cout<<"Ȩ��Ҫ��:���Ҽ�����Ա"<<endl;
		return Goods();
	}
	Goods k=shoppinglist.delGoods(id); // ��shoppinglist��ɾ��
	cout<<k.getName()<<"�ѳɹ�ɾ��!"<<endl;
	/*--------------------------

	��myGoods��ɾ��

	--------------------------*/
	int sizeOfQueue = myGoods.size();
	for(int i=1;i<=sizeOfQueue;i++)
	{
		if(myGoods.front()!=k.getId())
			myGoods.push(myGoods.front());
		myGoods.pop();
	}
	return k; // ���ر�ɾ������
}

void Account::printMyGoods()
{
	cout<<"<--------------------��������Ʒ-------------------->"<<endl<<endl;
	int sizeOfQueue=myGoods.size();
	if(!sizeOfQueue)
		cout<<"    �㻹û�з�������Ʒ��ϢŶ!�����ҳ���Ʒ��!"<<endl;
	for (int i=1;i<=sizeOfQueue;i++)
	{
		shoppinglist.queryGoods(myGoods.front()).printInfo();
		myGoods.push(myGoods.front());
		myGoods.pop();
	}
	cout<<endl<<"<------------------------------------------------->"<<endl;
}

bool Account::banId(int id,bool op)
{
	Account target;
	if(authority!=2)
	{
		cout<<"�Ƿ�����!"<<endl;
		cout<<"Ȩ��Ҫ��:����Ա"<<endl;
		return 0;
	}
	target = queryUser(id); //�����ݿ����󣬼��ID�Ƿ����
	if(target.getId())
		banUser(id,op); // ����banUser���
	else
		return 0;
	return 1;
}

void Account::showMeEverything()
{
	extern AllGoods shoppinglist;
	if(authority!=2)
	{
		cout<<"�Ƿ�����!"<<endl;
		cout<<"Ȩ��Ҫ��:����Ա"<<endl;
		return;
	}
	shoppinglist.showAllInfo(); // ��ӡ������Ʒ
	printInfoOfUsers(); //��ӡ�����û�
	return;
}