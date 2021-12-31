#include<bits/stdc++.h>
#include "class.h"

using namespace std;

extern int UserID;
extern int GoodsID;
extern int loginUser;
extern int Cancelled;
extern AllGoods shoppinglist;

Account all[1005];
Goods lists[1005];
int cntUsers;

void Init()
{
	ifstream UserIn("user.txt",ios::in);
	UserIn >> cntUsers >> UserID >> Cancelled;
	for(int i=1;i<=cntUsers;i++)
	UserIn >> all[i];
	UserIn.close();
	ifstream GoodsIn("goods.txt",ios::in);
	GoodsIn >> shoppinglist;
	GoodsIn.close();
	return;
}

void End()
{
	ofstream UserOut("user.txt",ios::out);
	UserOut << cntUsers << ' ' << UserID << ' ' << Cancelled << endl;
	for(int i=1;i<=cntUsers;i++)
		UserOut << all[i];
	ofstream GoodsOut("goods.txt",ios::out);
	GoodsOut << shoppinglist << endl;
}

bool checkDuplicate(string name)
{
	for(int i=1;i<=cntUsers;i++)
		if(all[i].getName()==name)
			return 0;
	return 1;
}

void InsUser(Account newA)
{
	all[++cntUsers]=newA;
	return;
}

Account CheckUser(string name,string password)
{
	for(int i=1;i<=cntUsers;i++)
	if(all[i].getName()==name)
	{
		if(all[i].getPassword()==password)
			return all[i];
		else return Account(-1);
	}
	return Account(0);
}

Account queryUser(int id)
{
	for(int i=1;i<=cntUsers;i++)
		if(all[i].getId()==id)
			return all[i];
	return Account();
}

bool delUser(int id)
{
	int pos=0;
	for(int i=1;i<=cntUsers;i++)
		if(all[i].getId()==id)
		{
			pos=i;
			break;
		}
	if(!pos)return 0;
	for(int i=pos;i<cntUsers;i++)
		all[i]=all[i+1];
	cntUsers--;
	return 1;
}

void banUser(int id,bool op)
{
	for(int i=1;i<=cntUsers;i++)
		if(all[i].getId()==id)
			all[i].setBanned(op^1);
}

void Load(Account loadUser)
{
	for(int i=1;i<=cntUsers;i++)
		if(all[i].getId()==loadUser.getId())
			all[i]=loadUser;
	return;
}

void printInfoOfUsers()
{
	cout<<"用户总数:"<<cntUsers<<endl;
	cout<<"有记录的用户信息如下:"<<endl;
	cout<<setw(20)<<"用户名"<<' ';
	cout<<setw(20)<<"账户类型"<<' ';
	cout<<setw(20)<<"钱包余额(CNY)"<<' ';
	cout<<setw(10)<<"用户ID"<<' ';
	cout<<setw(20)<<"手机号"<<' ';
	cout<<setw(10)<<"账户状态"<<endl;
	for(int i=1;i<=cntUsers;i++)
		all[i].printInTable(),cout<<endl;
	cout<<"已注销用户数:"<<Cancelled<<endl;
}
