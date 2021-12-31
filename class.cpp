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
	//空构造函数
}

istream& operator >> (istream &in, AllGoods &A)
{
	int sizeOfQueue;
	extern int GoodsID;
	Goods temp;
	in >> sizeOfQueue >> GoodsID; // 先输入goodsList大小和总GoodsID
	for(int i=1;i<=sizeOfQueue;i++)
	{
		in >> temp; // 输入每一件商品
		A.goodsList.push(temp);
	}
	return in;
}

ostream& operator << (ostream &out, AllGoods &A)
{
	extern int GoodsID;
	out << A.goodsList.size() << ' ' << GoodsID << endl; // 先输出goodsList大小和总GoodsID
	while(A.goodsList.size())
	{
		out << A.goodsList.front(); // 输出每一件商品
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
	cout<<endl<<"<---------------------商品列表--------------------->"<<endl;
	cout<<"共"<<sizeOfQueue<<"项商品"<<endl<<endl;
	cout<<setw(5)<<"ID"<<' ';
	cout<<setw(20)<<"名称"<<' ';
	cout<<setw(15)<<"价格"<<' ';
	cout<<setw(5)<<"销量"<<endl;
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
	Goods ret(0,"Not Found",0,0,0); // 找不到ID时的默认返回值
	int sizeOfQueue = goodsList.size();
	/*--------------------------

	遍历goodsList，寻找相同ID的商品

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

	将goodsList按ID大小排序

	--------------------------*/
	int sizeOfQueue = goodsList.size();
	Goods *temp = new Goods[sizeOfQueue]; // 为排序申请的临时数组
	for(int i=0;i<sizeOfQueue;i++)
	{
		temp[i]=goodsList.front(); // 将所有元素从元容器取出
		goodsList.pop();
	}
	sort(temp,temp+sizeOfQueue,cmpById); // 调用STL中sort方法排序
	for(int i=0;i<sizeOfQueue;i++)
		goodsList.push(temp[i]); // 将元素重新塞回数组中
	delete [] temp; // 释放空间
	return;
}

void AllGoods::sortByPrice()
{
	/*--------------------------

	将goodsList按价格大小排序

	--------------------------*/
	int sizeOfQueue = goodsList.size(); // 为排序申请的临时数组
	Goods *temp = new Goods[sizeOfQueue];
	for(int i=0;i<sizeOfQueue;i++)
	{
		temp[i]=goodsList.front(); // 将所有元素从元容器取出
		goodsList.pop();
	}
	sort(temp,temp+sizeOfQueue,cmpByPrice); // 调用STL中sort方法排序
	for(int i=0;i<sizeOfQueue;i++)
		goodsList.push(temp[i]); // 将元素重新塞回数组中
	delete [] temp; // 释放空间
	return;
}

void AllGoods::sortBySalesVolume()
{
	/*--------------------------

	将goodsList按销量大小排序

	--------------------------*/
	int sizeOfQueue = goodsList.size();
	Goods *temp = new Goods[sizeOfQueue]; // 为排序申请的临时数组
	for(int i=0;i<sizeOfQueue;i++)
	{
		temp[i]=goodsList.front(); // 将所有元素从元容器取出
		goodsList.pop();
	}
	sort(temp,temp+sizeOfQueue,cmpBySalesVolume); // 调用STL中sort方法排序
	for(int i=0;i<sizeOfQueue;i++)
		goodsList.push(temp[i]); // 将元素重新塞回数组中
	delete [] temp; // 释放空间
	return;
}

AllGoods AllGoods::selectByPrice(double l,double r)
{
	/*--------------------------

	将goodsList中落在价格区间内商品取出，组合为一个AllGoods对象，并返回

	--------------------------*/
	AllGoods ret=AllGoods(); // 返回值初始化
	int sizeOfQueue = goodsList.size();
	for(int i=1;i<=sizeOfQueue;i++) // 遍历goodsList
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
	cout<<"<--------------------我的购物车-------------------->"<<endl<<endl;
	int sizeOfQueue=contents.size();
	if(!sizeOfQueue)
		cout<<"   这里还什么也没有呢!快去购物吧!   "<<endl;
	else
	{
		cout<<"共"<<sizeOfQueue<<"项商品"<<endl<<endl;
		cout<<setw(5)<<"ID"<<' ';
		cout<<setw(20)<<"名称"<<' ';
		cout<<setw(15)<<"价格"<<' ';
		cout<<setw(5)<<"销量"<<endl;
		for(int i=1;i<=sizeOfQueue;i++)
		{
			tmp = shoppinglist.queryGoods(contents.front().first);
			tmp.printInfo();cout<<"     数量: "<<contents.front().second << endl;
			contents.push(contents.front());contents.pop();
		}
	}
	cout<<endl<<"<------------------------------------------------->"<<endl;
}

void shoppingCar::addGoods(int id) // 添加商品
{
	int sizeOfQueue = contents.size();
	for(int i=1;i<=sizeOfQueue;i++)
		if(contents.front().first==id) //如果商品已存在于购物车中，则使其数量+1
		{
			contents.front().second++;
			return;
		}
	/*--------------------------

	若商品不在购物车中，则在整个购物列表中查找
	若找不到说明ID不合法，否则将其加入购物车并设定数量为1

	--------------------------*/
	if(shoppinglist.queryGoods(id).getId()==-1)
	{
		cout<<"不存在的商品编号!"<<endl;
		return;
	}
	contents.push(make_pair(id,1));
	return;
}

bool shoppingCar::delGoods(int id)
{
	/*--------------------------

	遍历contents，找到匹配商品后将该项删除
	若找不到不作任何操作
	返回是否找到商品

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

	结账

	首先统计购物车物品总价值，与当前账户余额作比较
	若足够直接结账，返回1
	否则返回0，并不做任何其他操作

	--------------------------*/
	int sizeOfQueue = contents.size();
	double totPrice = 0;
	Goods curGoods;
	Account Seller;
	/*--------------------------

	统计购物车物品总价值

	--------------------------*/
	for(int i=1;i<=sizeOfQueue;i++)
	{
		totPrice+=shoppinglist.queryGoods(contents.front().first).getPrice()*contents.front().second;
		contents.push(contents.front());
		contents.pop();
	}

	if(totPrice>curUser.getBalance()) // 与余额比较
		return 0;

	/*--------------------------

	从账户中减去需要支付的金额
	清空购物车
	将对应资金打到卖家账户上

	--------------------------*/
	curUser.pay(totPrice);
	while(contents.size())
	{
		for(int i=1;i<=contents.front().second;i++) // 遍历contents
		{
			shoppinglist.incSV(contents.front().first);
			curGoods=shoppinglist.queryGoods(contents.front().first);
			Seller=queryUser(curGoods.getSeller()); // 取出卖家对象
			Seller.charge(curGoods.getPrice()); // 为卖家账户充入资金
			Load(Seller); // 上载卖家账户
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

void Account::pay(double num) // 支付
{
	balance-=num;
	return;
}

void Account::charge(double number) // 充值
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

	登出功能
	还原各个变量并上载当前账户

	--------------------------*/
	extern int loginUser;
	extern Account curUser;
	Load(curUser); // 上载账户
	loginUser = -1; // 还原loginUser
	id = balance = banned = 0; // 还原id, balance和banned
	userName = ""; // 还原userName
	curUser = Account(); // 还原curUser
	return;
}

void Account::queryMyInfo()
{
	const string tp[3]={"买家","卖家","管理员"};
	cout<<"         用户名: "<<userName<<endl;
	cout<<"       账户类型: "<<tp[authority]<<endl;
	cout<<fixed<<setprecision(2)<<"  钱包余额(CNY): "<<balance<<endl;
	cout<<"         用户ID: "<<setw(10)<<setfill('0')<<id<<endl;
	cout<<setfill(' ');
	cout<<"         手机号: "<<phoneNumber<<endl;
	return;
}

void Account::printInTable()
{
	const string tp[3]={"买家","卖家","管理员"};
	cout<<setw(20)<<userName<<' ';
	cout<<setw(20)<<tp[authority]<<' ';
	cout<<fixed<<setprecision(2)<<setw(20)<<balance<<' ';
	cout<<setw(10)<<setfill('0')<<id<<' ';
	cout<<setfill(' ');
	cout<<setw(20)<<phoneNumber<<' ';
	cout<<setw(10)<<(banned?"已封禁":"正常")<<endl;
	return;
}

void Account::shopping(AllGoods curShoppingList)
{
	/*--------------------------

	购物功能（第二层）
	对先前提取出子列表操作

	--------------------------*/
	int cmd=0;
	Goods target;
	while(cmd!=-1)
	{
		curShoppingList.showAllInfo();
		cout<<"选择你的操作:"<<endl;
		cout<<"<----------------->"<<endl;
		/*--------------------------

		为防止命令冲突，将指令改为负数

		--------------------------*/
		cout<<" -2:按id从小到大排序商品"<<endl;
		cout<<" -3:按价格从小到大排序商品"<<endl;
		cout<<" -4:按销量从大到小排序商品"<<endl;
		cout<<" -1:返回上一级"<<endl;
		cout<<"<----------------->"<<endl;
		cout<<"从菜单中选择指令或直接输入商品ID来将其添加入您的购物车。"<<endl;
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

				若不为任何命令，考虑输入数值为商品ID的可能

				先检验其合法性，若合法则将该商品加入购物车

				--------------------------*/
				target=curShoppingList.queryGoods(cmd);
				if(target.getName()=="Not Found")
				{
					cout<<"不存在的商品ID!";
					Sleep(1000ul);
					cout<<endl<<endl;
				}
				else if(target.getSeller()==loginUser)
				{
					cout<<"本商城严厉打击刷单行为!请遵守市场秩序!";
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

	注销

	--------------------------*/
	extern int loginUser;
	extern int Cancelled;
	if(passwd==password)
	{
		delUser(loginUser); //需输入密码确认方可注销
		while(myGoods.size()) // 下架所有关联商品
			curUser.DelGoods(myGoods.front());
		Cancelled++; // 注销用户数+1
	}
	else return 1;
	return 0;
}

bool Account::queryMyGoods(int id)
{
	/*--------------------------

	遍历myGoods，逐一比较ID
	找到返回1，未找到返回0

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

	挂出物品出售信息

	--------------------------*/
	extern AllGoods shoppinglist;
	extern int GoodsID;
	if(!authority) //只有卖家和管理员有权操作
	{
		cout<<"非法操作!"<<endl;
		cout<<"权限要求:卖家及管理员"<<endl;
		return 1;
	}
	shoppinglist.addGoods(Goods(++GoodsID,name,price,0,id)); // 调用shoppinglist的addGoods方法
	myGoods.push(GoodsID);
	return 0;
}

Goods Account::DelGoods(int id)
{
	/*--------------------------

	下架商品
	返回被下架对象

	--------------------------*/
	extern AllGoods shoppinglist;
	if(!authority)
	{
		cout<<"非法操作!"<<endl;
		cout<<"权限要求:卖家及管理员"<<endl;
		return Goods();
	}
	Goods k=shoppinglist.delGoods(id); // 从shoppinglist中删除
	cout<<k.getName()<<"已成功删除!"<<endl;
	/*--------------------------

	从myGoods中删除

	--------------------------*/
	int sizeOfQueue = myGoods.size();
	for(int i=1;i<=sizeOfQueue;i++)
	{
		if(myGoods.front()!=k.getId())
			myGoods.push(myGoods.front());
		myGoods.pop();
	}
	return k; // 返回被删除对象
}

void Account::printMyGoods()
{
	cout<<"<--------------------我卖的商品-------------------->"<<endl<<endl;
	int sizeOfQueue=myGoods.size();
	if(!sizeOfQueue)
		cout<<"    你还没有发布过商品信息哦!快来挂出商品吧!"<<endl;
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
		cout<<"非法操作!"<<endl;
		cout<<"权限要求:管理员"<<endl;
		return 0;
	}
	target = queryUser(id); //向数据库请求，检查ID是否存在
	if(target.getId())
		banUser(id,op); // 调用banUser句柄
	else
		return 0;
	return 1;
}

void Account::showMeEverything()
{
	extern AllGoods shoppinglist;
	if(authority!=2)
	{
		cout<<"非法操作!"<<endl;
		cout<<"权限要求:管理员"<<endl;
		return;
	}
	shoppinglist.showAllInfo(); // 打印所有商品
	printInfoOfUsers(); //打印所有用户
	return;
}