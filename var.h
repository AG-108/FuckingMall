#ifndef VAR_H
#define VAR_H

	//外部变量汇总

	#include "class.h"
	#include<bits/stdc++.h>

	extern int loginUser=-1; //当前登录用户（ID）
	extern int GoodsID=0; //物品总ID（用于创建新物品）
	extern int UserID=0; //用户ID
	extern int Cancelled=0; // 注销用户总数
	extern Account curUser=Account(); //当前登录用户（用户类）
	extern AllGoods shoppinglist=AllGoods();//购物列表
	extern shoppingCar curShoppingCar=shoppingCar();//当前购物车

#endif