/*--------------------------
							
			接口层

	  负责宏观业务逻辑调控

--------------------------*/
#include "class.h" 
#include "DatabaseHandle.h"
#include "md5.h" // 实现MD5加密用户密码（第三方开源）
#include<bits/stdc++.h>

using namespace std;

/*--------------------------
							
		声明extern变量

--------------------------*/

extern int UserID;
extern int GoodsID;
extern int loginUser;
extern AllGoods shoppinglist;
extern shoppingCar curShoppingCar;

/*--------------------------
							
		   具体实现

--------------------------*/

bool checkUserInterface(string name)
{
	/*--------------------------

	检查用户名是否复用:
		0:否
		1:是

	--------------------------*/
	return checkDuplicate(name);
}

void registerInterface(string name, int type, string newpassword, string phoneNumber)
{
	/*--------------------------

	创建新的账户类，调用数据库句柄插入

	--------------------------*/
	UserID++;
	newpassword = MD5(newpassword).toStr();
	InsUser(Account(UserID,name,type,newpassword,phoneNumber));
	return;
}

int LoginInterface(string name,string password)
{
	/*--------------------------

	根据用户名查找账户，并尝试匹配密码，
	若成功返回对应的账户ID，否则返回0

	--------------------------*/
	password = MD5(password).toStr();
	Account ret = CheckUser(name,password);
	if(ret.getId()>0)
	{
		loginUser = ret.getId();
		curUser = ret;
	}
	return ret.getId();
}

bool ResetPassInterface(string oldpass,string newpass)
{
	/*--------------------------

	MD5加密两个密码
	传给curUser变量的resetPassword方法并返回其结果

	--------------------------*/

	oldpass = MD5(oldpass).toStr();
	newpass = MD5(newpass).toStr();
	return curUser.resetPassword(oldpass,newpass);
}

bool ResetNameInterface(string newname)
{
	/*--------------------------

	调用curUser的resetUserName方法

	--------------------------*/
	return curUser.resetUserName(newname);
}

void GoShoppingInterface(AllGoods curShoppingList)
{
	/*--------------------------

  	调用curUser的shopping方法

	--------------------------*/
	curUser.shopping(curShoppingList);
	return;
}

void ShowMyInformationInterface()
{
	/*--------------------------

	调用curUser的queryMyInfo方法

	--------------------------*/
	curUser.queryMyInfo();
	return;
}

void MyShoppingCarInterface()
{
	/*--------------------------

	调用curShoppingCar的showAllInfo方法

	--------------------------*/
	curShoppingCar.showAllInfo();
	return;
}

bool CheckOutInterface()
{
	/*--------------------------

	调用curUser的payOff方法

	--------------------------*/
	return curShoppingCar.payOff();
}

bool DelGoodsFromShoppingCarInterface(int id)
{
	/*--------------------------

	调用curUser的delGoods方法

	--------------------------*/
	return curShoppingCar.delGoods(id);
}

void MyGoodsInterface()
{
	curUser.printMyGoods();
	return;
}

void ChargeInterface(double num)
{
	curUser.charge(num);
	return;
}

void LogoutInterface()
{
	curUser.logOut();
	return;
}

void AddGoodsInterface(string name,double price)
{
	curUser.AddGoods(name,price);
	return;
}

Goods DelGoodsInterface(int id)
{
	return curUser.DelGoods(id);;
}

bool CancellInterface(string password)
{
	password = MD5(password).toStr();
	return curUser.cancell(password);
}

void ShowMeEverythingInterface()
{
	curUser.showMeEverything();
	return;
}

bool banUserInterface(int id,bool op)
{
	return curUser.banId(id,op);
}