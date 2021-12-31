#ifndef INTERFACE_H
#define INTERFACE_H

	/*--------------------------
							
				接口层

		  负责宏观业务逻辑调控

	--------------------------*/

	#include<bits/stdc++.h>
	#include "class.h"

	using namespace std;

	bool checkUserInterface(string); // 检查用户名是否复用

	void registerInterface(string, int, string, string); // 注册接口

	int LoginInterface(string,string); // 登录接口

	bool ResetPassInterface(string,string); // 重置密码接口

	bool ResetNameInterface(string); // 重置用户名接口
	
	void GoShoppingInterface(AllGoods); // 购物总接口
	
	void ShowMyInformationInterface(); // 账户信息接口
	
	void MyShoppingCarInterface(); // 购物车信息接口
	
	bool CheckOutInterface(); // 结账接口
	
	bool DelGoodsFromShoppingCarInterface(int); // 购物车清除物品接口
	
	void MyGoodsInterface(); // 售卖物品信息接口
	
	void ChargeInterface(double); // 充值接口
	
	void LogoutInterface(); // 登出接口
	
	void AddGoodsInterface(string,double); // 向商城添加物品接口
	
	Goods DelGoodsInterface(int); // 商城删除物品接口
	
	bool CancellInterface(string); // 注销接口
	
	void ShowMeEverythingInterface(); // 打印商城信息接口

	bool banUserInterface(int,bool); // 封禁账户接口

#endif