#ifndef DATABASEHANDLE_H
#define DATABASEHANDLE_H

	void Init(); // 数据库初始化

	void End(); // 数据库上载更新
	
	bool checkDuplicate(string); // 检查用户名重复情况
	
	void InsUser(Account); // 向数据库插入用户
	
	Account CheckUser(string,string); // 检查用户信息异常与否，若正常返回对应用户对象，否则返回异常信息
	
	bool delUser(int); // 从数据库删除用户
	
	void banUser(int,bool); // 封禁用户
	
	void Load(Account); // 上载用户
	
	Account queryUser(int); // 根据ID取出用户
	
	void printInfoOfUsers(); // 打印所有用户信息

#endif