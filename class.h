#ifndef CLASS_H
#define CLASS_H

	#include<bits/stdc++.h>

	using namespace std;

	class Goods
	{
		private:
			int id, salesVolume, seller;
			double price;
			string name;
		public:
			Goods(); // 无参构造函数创造空对象
			Goods(int,string,double,int,int); // 有参构造函数

			friend istream& operator >> (istream&, Goods&); // 重载流式输入运算符
			friend ostream& operator << (ostream&, Goods&); // 重载流式输出运算符
			
			/*--------------------------

			用于获取private变量的函数

			--------------------------*/

			void setName(string); // 重置姓名
			void setPrice(double); // 重置价格
			int getId(); // 获取ID
			double getPrice(); // 获取价格
			string getName(); // 获取名称
			int getSeller(); // 获取卖家信息
			
			void printInfo(); // 打印物品信息
			void SVinc(); // 销量自增一次
			
			/*--------------------------

			三个排序时需要的友元比较函数

			--------------------------*/

			friend bool cmpById(Goods,Goods); // 比较ID
			friend bool cmpByPrice(Goods,Goods); // 比较价格
			friend bool cmpBySalesVolume(Goods,Goods); // 比较销量
	};//物品类

	class AllGoods
	{
		private:
			queue<Goods> goodsList;
		public:
			AllGoods(); // 空构造函数

			friend istream& operator >> (istream&, AllGoods&); // 重载流式输入运算符
			friend ostream& operator << (ostream&, AllGoods&); // 重载流式输出运算符

			/*--------------------------

			用于获取private变量的函数

			--------------------------*/

			int getsize(); // 获取goodsList的size()
			
			void showAllInfo(); // 打印所有商品信息
			void addGoods(Goods); // 添加商品
			Goods delGoods(int); // 删除商品
			Goods queryGoods(int); // 查询商品信息
			void incSV(int); // 使列表中某一商品销量自增
			void sortById(); // 按照ID为商品排序
			void sortByPrice(); // 按照价格为商品排序
			void sortBySalesVolume(); // 按照销量为商品排序
			AllGoods selectByPrice(double,double); // 按照价格为商品排序
	};//多个物品类

	class shoppingCar
	{
		private:
			queue<pair<int,int> > contents; 
		public:
			shoppingCar(); // 空构造函数

			void showAllInfo(); // 打印购物车中所有信息
			void addGoods(int); // 向购物车中增加商品
			bool delGoods(int); // 删除购物车中的商品
			bool payOff(); // 结账
			void clear(); // 清空购物车
	};//购物车类

	class Account
	{
		//权限 0-买家 1-卖家 2-管理员
		private:
			int authority, id;
			double balance;
			string userName;
			string phoneNumber;
			string password;
			bool banned;
			queue<int> myGoods;
		public:
			/*--------------------------

			三个构造函数

			--------------------------*/

			Account(); // 空构造函数
			Account(int); // 用于返回特定错误信息的构造函数
			Account(int,string,int,string,string,bool ban = 0); // 新账户构造函数

			friend istream& operator >> (istream&, Account&); // 重载流式输入运算符
			friend ostream& operator << (ostream&, Account&); // 重载流式输出运算符

			/*--------------------------

			用于获取private变量的函数

			--------------------------*/

			int getId(); // 获取ID
			double getBalance(); // 获取余额
			int getAuthority(); // 获取权限等级
			string getName(); // 获取名字
			string getPassword(); // 获取密码
			bool getBanned(); // 获取封禁信息

			void pay(double); // 支付金额
			void charge(double); // 充值钱包
			void setBanned(bool); // 设定封禁状态
			bool resetUserName(string); // 重置用户名
			bool resetPassword(string,string); // 重置密码
			void logOut(); // 登出
			void queryMyInfo(); // 查询个人账户信息
			void printInTable(); // 以表格形式输出账户信息
			void shopping(AllGoods); // 购物
			bool cancell(string); // 注销
			bool queryMyGoods(int); // 查询我的物品
			bool AddGoods(string,double); // 添加物品
			Goods DelGoods(int); // 删除物品
			void printMyGoods(); // 打印个人物品信息
			bool banId(int,bool); // 封禁ID（管理员）
			void showMeEverything(); // 打印商城概况（管理员）
	};// 账户类

	extern Account curUser;
	extern AllGoods GoodsList;
	extern shoppingCar curShoppingCar;

#endif