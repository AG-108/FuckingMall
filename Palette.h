#ifndef PALETTE_H
#define PALLETE_H

	int readint(); // 安全读入整数
	
	void printHelp(); // 打印菜单
	
	void welcome(); // 显示欢迎界面
	
	void login(); // 登录
	
	void Register(); // 注册
	
	void showOptions(); // 显示所有的选项
	
	void ResetName(); // 重置用户名
	
	void GoShopping(); // 进入商城界面
	
	void ShowMyInformation(); // 打印我的个人信息
	
	void MyShoppingCar(); // 打印购物车中所有物品及其数量
	
	void MyGoods(); // （卖家）打印所有的自己所卖的物品信息
	
	void Charge(); // 充值
	
	void Logout(); // 登出
	
	void AddGoods(); // （卖家，管理员）向商城中添加物品
	
	void DelGoods(); // （卖家，管理员）删除商城中的物品
	
	void Cancell(); // 注销账户
	
	void ShowMeEverything(); // （管理员）打印商城的所有信息

#endif
