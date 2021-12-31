/*--------------------------
							
			�ӿڲ�

	  ������ҵ���߼�����

--------------------------*/
#include "class.h" 
#include "DatabaseHandle.h"
#include "md5.h" // ʵ��MD5�����û����루��������Դ��
#include<bits/stdc++.h>

using namespace std;

/*--------------------------
							
		����extern����

--------------------------*/

extern int UserID;
extern int GoodsID;
extern int loginUser;
extern AllGoods shoppinglist;
extern shoppingCar curShoppingCar;

/*--------------------------
							
		   ����ʵ��

--------------------------*/

bool checkUserInterface(string name)
{
	/*--------------------------

	����û����Ƿ���:
		0:��
		1:��

	--------------------------*/
	return checkDuplicate(name);
}

void registerInterface(string name, int type, string newpassword, string phoneNumber)
{
	/*--------------------------

	�����µ��˻��࣬�������ݿ�������

	--------------------------*/
	UserID++;
	newpassword = MD5(newpassword).toStr();
	InsUser(Account(UserID,name,type,newpassword,phoneNumber));
	return;
}

int LoginInterface(string name,string password)
{
	/*--------------------------

	�����û��������˻���������ƥ�����룬
	���ɹ����ض�Ӧ���˻�ID�����򷵻�0

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

	MD5������������
	����curUser������resetPassword��������������

	--------------------------*/

	oldpass = MD5(oldpass).toStr();
	newpass = MD5(newpass).toStr();
	return curUser.resetPassword(oldpass,newpass);
}

bool ResetNameInterface(string newname)
{
	/*--------------------------

	����curUser��resetUserName����

	--------------------------*/
	return curUser.resetUserName(newname);
}

void GoShoppingInterface(AllGoods curShoppingList)
{
	/*--------------------------

  	����curUser��shopping����

	--------------------------*/
	curUser.shopping(curShoppingList);
	return;
}

void ShowMyInformationInterface()
{
	/*--------------------------

	����curUser��queryMyInfo����

	--------------------------*/
	curUser.queryMyInfo();
	return;
}

void MyShoppingCarInterface()
{
	/*--------------------------

	����curShoppingCar��showAllInfo����

	--------------------------*/
	curShoppingCar.showAllInfo();
	return;
}

bool CheckOutInterface()
{
	/*--------------------------

	����curUser��payOff����

	--------------------------*/
	return curShoppingCar.payOff();
}

bool DelGoodsFromShoppingCarInterface(int id)
{
	/*--------------------------

	����curUser��delGoods����

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