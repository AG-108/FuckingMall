#include<bits/stdc++.h>
#include<windows.h>
#include "Interface.h"
#include "class.h"
#include "lib.h"

using namespace std;

const int NumberOfCurrency=9;

const string options[10] = {"登录", "注册", "去购物", "我的账户", "我的购物车", "我的物品", "充值", "查询钱包余额", "登出","注销"};
const string currency[9] = {"人民币CNY","美元USD","日元JPY","欧元EUR","英镑GBP","韩元KRW","港元HKD","澳元AUD","加元CAD"};
const double exchangeRate[9] = {1.0,6.3683,0.00539,7.2248,8.594,0.005375,0.8167,4.6227,4.9811};

extern int loginUser;
extern AllGoods shoppinglist;

void Register();
void login();
void Charge();
void AddGoods();
void DelGoods();

void printHelp()//展示帮助，展示主菜单;
{
	if(loginUser==-1)
	{
		cout<<"<----------------->"<<endl;
		cout<<"  0:"<<options[0]<<endl<<endl;
		cout<<"还没有账户？注册一个"<<endl;
		cout<<"  1:"<<options[1]<<endl;
		cout<<" -1:退出"<<endl;
		cout<<"<----------------->"<<endl;
	}
	else
	{
		cout<<endl;
		cout<<"<----------------->"<<endl;
		int w=curUser.getAuthority();
		if(w==0)
		{
			cout<<"  0:"<<options[2]<<endl;
			cout<<"  1:"<<options[3]<<endl;
			cout<<"  2:"<<options[4]<<endl;
			cout<<"  3:"<<options[8]<<endl;
			cout<<"  4:"<<options[9]<<endl;
			cout<<" -1:退出"<<endl;
		}
		else if(w==1)
		{
			cout<<"  0:"<<options[2]<<endl;
			cout<<"  1:"<<options[3]<<endl;
			cout<<"  2:"<<options[4]<<endl;
			cout<<"  3:"<<options[5]<<endl;
			cout<<"  4:"<<options[8]<<endl;
			cout<<"  5:"<<options[9]<<endl;
			cout<<" -1:退出"<<endl;
		}
		else if(w==2)
		{
			cout<<"  0:"<<options[2]<<endl;
			cout<<"  1:"<<options[3]<<endl;
			cout<<"  2:"<<options[4]<<endl;
			cout<<"  3:"<<options[5]<<endl;
			cout<<"  4:"<<"商城信息汇总"<<endl;
			cout<<"  5:"<<options[8]<<endl;
			cout<<"  6:"<<options[9]<<endl;
			cout<<" -1:退出"<<endl;
		}
		cout<<"<----------------->"<<endl;
	}
}

void welcome()//欢迎;
{
	system("mode con cols=135 lines=40");
	cout<<"　　　■　　■■　　　　　　　　　　■　　　　　　　　　　　　　　■　■　　　　　　　　　■　　　　　　　　■　　　　　■　■　　"<<endl;
	cout<<"　　　■　　■　　　　　　　　　　　■　　　　　　　　■　　■　■■■■■■　　■■■■■■■■■■■　　　■　　　　　■　　　　"<<endl;
	cout<<"　　■　　　■■■■■■　　　■■■■　■■■■　　　■　　■　　■　■　　　　　　　■　　　■　　　　　　■　　■■■■■■■　"<<endl;
	cout<<"　　■　　■　　　　■　　　　■　　■　■　　■　　　■■　■　■■■■■　　　　■■■■■■■■■　　　■■■　■　　■　　　　"<<endl;
	cout<<"　■■　　　　　■　　　　　　■　　■　■　　■　　　■■　■　　■　■■　　　　■　　　　　　　■　　　　■　　■■■■　■　　"<<endl;
	cout<<"　　■　　　　　■　　　　　　■　　■　■　　■　　　■■　■　　■■■■■　　　■　■■　　■　■　　　　■　　■　■■　■　　"<<endl;
	cout<<"　　■　　■　　■　■　　　　■　　■　■　　■　　　■■　■　　■■■■　　　　■■■　　　　　■　　　　■　　　　■　■■　　"<<endl;
	cout<<"　　■　　■　　■　■　　　　■　　■　■　　■　　　■■　■　■■　■　　　　　■　　■　■■　■　　　　■■■　　■　■■　　"<<endl;
	cout<<"　　■　　■　　■　　■　　　■　　■　■　　■　　　　■　　　■■　■■　　　　■　　■　■■　■　　　■■　■　■　　■　　　"<<endl;
	cout<<"　　■　　　　　■　　　　　■■■■■■■■■■■　　　■　■■　■　■　■　　　■　　■■■　　■　　　　　■■　　　■■■■　"<<endl;
	cout<<"　　■　　　　■■　　　　　　　　　　　　　　　　　　■　　　■　■　■　　　　　■　　　　　　■■　　　　　■　　　■　　　■　"<<endl;
}

void login()//登录;
{
	string name, password, input;
	int correct=0,cmd;//标志变量，cmd表示用户选择的操作，correct表示用户是否正确输入;
	while(true)
	{
		bool flag=1;
		while(flag)
		{
			flag=0;
			cout<<"请输入你的用户名:";
			getline(cin, input);
			if(!input.size())
			{
				cout<<"用户名不能为空!"<<endl;
				flag=1;
				continue;
			}
			for(int i=0; i<input.size(); i++)
			{
				if(input[i]==' ')
				{
					cout<<"你的用户名不能包含任何空格!"<<endl;
					flag=1;
					break;
				}
			}
		}
		name=input;
		flag=1;
		while(flag)
		{
			flag=0;
			cout<<"请输入你的密码:";
			input=readPass();
			if(!input.size())
			{
				cout<<"密码不能为空!"<<endl;
				flag=1;
				continue;
			}
			for(int i=0; i<input.size(); i++)
			{
				if(input[i]==' ')
				{
					cout<<"你的密码不能包含任何空格!"<<endl;
					flag=1;
					break;
				}
			}
		}
		password=input;
		correct=LoginInterface(name,password);//correct确认用户是否输入正确;
		if(correct==0)
		{
			cout<<"非法用户名";
			Sleep(1000ul);
			cout<<endl<<endl;
		}
		else if(correct==-1)
		{
			cout<<"密码错误!";
			Sleep(1000ul);
			cout<<endl<<endl;
		}
		else if(correct>0)
			break;
		cout<<"<----------------->"<<endl;
		cout<<"  0:重新登录"<<endl;
		cout<<"  1:注册"<<endl;
		cout<<" -1:返回上一级"<<endl;
		cout<<"<----------------->"<<endl;
		cout<<">>>>";
		cmd=readint();
		switch (cmd)
		{
			case 0:
				break;
			case 1:
				Register();
				break;
			case -1:
				correct=1;
				break;
			default:
				cout<<"请输入一个0到2之间的整数!"<<endl;
				correct=-2;
				break;
		}
	}
	if(curUser.getBanned())
	{
		cout<<"当前账户已被封禁，如有疑问请询问管理员。";
		curUser.logOut();
		Sleep(1000ul);
		cout<<endl<<endl;
	}
}

void Register()//注册;
{
	cout<<endl;
	string newname,input,input2,newpassword,confirmpassword,phoneNumber;//各项需输入的变量以及两个输入暂存变量;
	bool flag=1,correct=1;//标志变量，cmd表示用户选择的操作，correct表示用户是否正确输入;
	int type;//权限;

	while(flag)
	{
		flag=0;
		cout<<"请输入用户名:";
		getline(cin, input);
		if(!input.size())
		{
			cout<<"用户名不能为空!"<<endl;
			flag=1;
			continue;
		}
		for(int i=0; i<input.size(); i++)
		{
			if(input[i]==' ')
			{
				cout<<"你的用户名不能包含任何空格!"<<endl;
				flag=1;
				break;
			}
		}
		if(!checkUserInterface(input))
		{
			cout<<"用户名已被使用。"<<endl;
			flag=1;
		}
	}
	newname=input;
	if(newname[0]=='_'&&newname[1]=='_')type=2;//注册时用户名的头两个字符是“__”可以生成管理员账户。
	else
	{
		flag=1;
		while(flag)
		{
			flag=0;
			cout<<"请选择账户类型:"<<endl;
			cout<<"<----------------->"<<endl;
			cout<<"  0:买家"<<endl;
			cout<<"  1:卖家"<<endl;
			cout<<"<----------------->"<<endl;
			type=readint();
			if(type<0||type>1)
			{
				cout<<"请输入一个0到1之间的整数!";
				flag=1;
				Sleep(1000ul);
				cout<<endl<<endl;
				break;
			}
		}
	}

	flag=1;
	while(flag)
	{
		flag=0;
		cout<<"请输入密码:";
		input=readPass();
		if(!input.size())
		{
			cout<<"密码不能为空!"<<endl;
			flag=1;
			continue;
		}
		for(int i=0; i<input.size(); i++)
		{
			if( ( (input[i]>'9')||(input[i]<'0') )&&( (input[i]>'Z')||(input[i]<'A') )&&( (input[i]>'z')||(input[i]<'a') ) )
			{
				cout<<"你的密码只能包含英文字母和数字!"<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<"确认密码:";
			input2=readPass();
			for(int i=0; i<input2.size(); i++)
				if( ( (input2[i]>'9')||(input2[i]<'0') )&&( (input2[i]>'Z')||(input2[i]<'A') )&&( (input2[i]>'z')||(input2[i]<'a') ) )
				{
					cout<<"你的密码应该只包含字母和数字!"<<endl;
					flag=1;
					break;
				}
			if(flag==0)
			{
				for(int i=0; i<max(input.size(),input2.size()); i++)
				{
					if(input[i]!=input2[i])
					{
						cout<<"两个密码不一致!"<<endl;
						flag=1;
						break;
					}
				}
			}

		}


	}
	newpassword=input;

	flag=1;
	while(flag)
	{
		flag=0;
		cout<<"请输入你的电话号码:";
		getline(cin, input);
		for(int i=0; i<input.size(); i++)
			if((input[i]<'0')||input[i]>'9')
			{
				cout<<"你的电话号码应该只包含数字!"<<endl<<endl;
				flag=1;
				break;
			}
		if(input.size()!=11)
		{
			cout<<"电话号码应该是十一位的！"<<endl;
			flag=1;
		}

	}
	phoneNumber=input;
	registerInterface(newname,type,newpassword,phoneNumber);
	cout<<"注册成功!"<<endl<<endl;
	return;

}

void ResetPass()//重置密码;
{
	string inputold,inputnew,inputnew2;
	bool correct=1,cohere=1;//标志变量，cohere标志先后输入的两个旧密码是否一致，correct表示用户是否正确输入;
	while(correct)
	{
		correct=0;
		cout<<"请输入旧密码:";
		inputold=readPass();
		if(!inputold.size())
		{
			cout<<"密码不能为空!"<<endl;
			correct=1;
			continue;
		}
		for(int i=0; i<inputold.size(); i++)
		{
			if( ( (inputold[i]>'9')||(inputold[i]<'0') )&&( (inputold[i]>'Z')||(inputold[i]<'A') )&&( (inputold[i]>'z')||(inputold[i]<'a') ) )
			{
				cout<<"你的旧密码应该只包含字母和数字!"<<endl<<endl;
				correct=1;
				break;
			}
		}
	}
	while(cohere)
	{
		correct=1;
		cohere=0;
		while(correct)
		{
			correct=0;
			cout<<"请输入新密码:";
			inputnew=readPass();
			if(!inputnew.size())
			{
				correct=1;
				cout<<"密码不能为空!"<<endl;
				continue;
			}
			for(int i=0; i<inputnew.size(); i++)
				if( ( (inputnew[i]>'9')||(inputnew[i]<'0') )&&( (inputnew[i]>'Z')||(inputnew[i]<'A') )&&( (inputnew[i]>'z')||(inputnew[i]<'a') ) )
				{
					cout<<"你的新密码应该只包含字母和数字!"<<endl<<endl;
					correct=1;
					break;
				}
		}
		correct=1;
		while(correct)
		{
			correct=0;
			cout<<"确认新密码:";
			inputnew2=readPass();
			for(int i=0; i<inputnew2.size(); i++)
				if( ( (inputnew2[i]>'9')||(inputnew2[i]<'0') )&&( (inputnew2[i]>'Z')||(inputnew2[i]<'A') )&&( (inputnew2[i]>'z')||(inputnew2[i]<'a') ) )
				{
					cout<<"你的新密码应该只包含字母和数字!"<<endl<<endl;
					correct=1;
					break;
				}
		}
		for(int i=0; i<max(inputnew.size(),inputnew2.size()); i++)
		{
			if(inputnew[i]!=inputnew2[i])
			{
				cout<<"两个密码不一致!"<<endl;
				cout<<"请重新输入新密码!"<<endl<<endl;
				cohere=1;
				break;
			}
		}
		if(cohere)continue;
		correct=ResetPassInterface(inputold,inputnew2);
		if(!correct)
			cout<<"旧密码错误!"<<endl<<endl;
		else
			cout<<"重置成功!"<<endl<<endl;
	}
}
void ResetName()//重置用户名;
{
	bool flag=1;
	string input;
	while(flag)
	{
		flag=0;
		cout<<"请输入你的新用户名:";
		getline(cin, input);
		if(!input.size())
		{
			cout<<"用户名不能为空!"<<endl;
			flag=1;
			continue;
		}
		for(int i=0; i<input.size(); i++)
			if(input[i]==' ')
			{
				cout<<"你的用户名不应该包含任何空格!"<<endl<<endl;
				flag=1;
				break;
			}
	}
	ResetNameInterface(input);
	cout<<"用户名重置成功!"<<endl<<endl;
}


void GoShopping()//去购物;
{
	cout<<endl;
	shoppinglist.showAllInfo();
	int cmd=0;//标志变量，cmd标志用户选择的操作;
	cout<<"选择你的操作:"<<endl;
	cout<<"<----------------->"<<endl;
	cout<<"  1:按价格从小到大排序商品"<<endl;
	cout<<"  2:按销量从大到小排序商品"<<endl;
	cout<<"  3:按价格筛选商品"<<endl;
	cout<<"  4:直接开始选购"<<endl;
	cout<<" -1:返回上一级"<<endl;
	cout<<"<----------------->"<<endl;
	AllGoods selected=shoppinglist;
	while(!cmd)
	{
		cout<<">>>>";
		cmd=readint();
		int low=0,high=0;
		switch (cmd)
		{
			case 1:
				selected.sortByPrice();
				GoShoppingInterface(selected);
				break;
			case 2:
				selected.sortBySalesVolume();
				GoShoppingInterface(selected);
				break;
			case 3:
				cout<<"请输入您想筛选的最低价格: ";
				low=readint();
				cout<<"请输入您想筛选的最高价格:";
				high=readint();
				cout<<endl;
				selected=shoppinglist.selectByPrice(low,high);
				GoShoppingInterface(selected);
				break;
			case 4:
				GoShoppingInterface(selected);
				break;
			case -1:
				return;
			default:
				cmd=0;
				break;
		}
	}
}


void ShowMyInformation()//展示个人信息;
{
	cout<<endl;
	ShowMyInformationInterface();
	int cmd=0;//标志变量，cmd标志用户选择的操作;
	cout<<"选择你的操作:"<<endl;
	cout<<"<----------------->"<<endl;
	cout<<"  1:充值"<<endl;
	cout<<"  2:重置用户名"<<endl;
	cout<<"  3:重置密码"<<endl;
	cout<<" -1:返回上一级"<<endl;
	cout<<"<----------------->"<<endl;
	while(!cmd)
	{
		cout<<">>>>";
		cmd=readint();
		switch (cmd)
		{
		case 1:
			Charge();
			break;
		case 2:
			ResetName();
			break;
		case 3:
			ResetPass();
			break;
		case -1:
			return;
		default:
			cmd=0;
			break;
		}
	}
}


void MyShoppingCar()//我的购物车;
{
	MyShoppingCarInterface();
	cout<<"选择你的操作:"<<endl;
	cout<<"<----------------->"<<endl;
	cout<<"  1:结账"<<endl;
	cout<<"  2:删除物品"<<endl;
	cout<<" -1:返回上一级"<<endl;
	cout<<"<----------------->"<<endl;
	int cmd,ID;//cmd表示用户选择的操作，ID用于写入用户的输入的ID;
	bool flag=1;
	cout<<">>>>";
	cmd=readint();
	while(cmd!=-1)
	{
		switch(cmd)
		{
			case 1:
				if(CheckOutInterface())
				{
					cout<<"购买成功!";
					Sleep(1000ul);
					cout<<endl<<endl;
				}
				else
				{
					cout<<"余额不足!请充值";
					Sleep(1000ul);
					cout<<endl<<endl;
				}
				break;
			case 2:
				cout<<"请输入您想删除的物品ID:";
				ID=readint();
				if(!DelGoodsFromShoppingCarInterface(ID))
				{
					cout<<"不存在的物品ID!";
					Sleep(1000ul);
					cout<<endl<<endl;
				}
				break;
			case -1:
				break;
			default:
				cout<<"请输入1、2或-1!";
				Sleep(1000ul);
				cout<<endl<<endl;                    
				break;
		}
		MyShoppingCarInterface();
		cout<<"选择你的操作:"<<endl;
		cout<<"<----------------->"<<endl;
		cout<<"  1:结账"<<endl;
		cout<<"  2:删除物品"<<endl;
		cout<<" -1:返回上一级"<<endl;
		cout<<"<----------------->"<<endl;
		cout<<">>>>";
		cmd=readint();
	}
}

void MyGoods()//展示个人的商品;
{
	cout<<"以下是你的商品: "<<endl<<endl;
	MyGoodsInterface();
	int cmd=0,ID;
	Goods temp;
	cout<<"<----------------->"<<endl;
	cout<<"选择您的操作:"<<endl;
	cout<<"  0:添加商品"<<endl;
	cout<<"  1:删除商品"<<endl;
	cout<<" -1:返回上一级"<<endl;
	cout<<"<----------------->"<<endl;
	while(cmd!=-1)
	{
		cout<<">>>>";
		cmd=readint();
		switch (cmd)
		{
		case 0:
			AddGoods();
			cout<<"添加成功!";
			Sleep(1000ul);
			cout<<endl<<endl;
			break;
		case 1:
			DelGoods();
			break;
		case (-1):
			break;
		default:
			cout<<"请输入一个0到1之间的整数!"<<endl;
			cout<<"或输入-1来返回上一级";
			Sleep(1000ul);
			cout<<endl<<endl;
			cmd=0;
			break;

		}
		cout<<"以下是你的商品: "<<endl;
		MyGoodsInterface();
		cout<<"<----------------->"<<endl;
		cout<<"选择您的操作:"<<endl;
		cout<<"  0:添加商品"<<endl;
		cout<<"  1:删除商品"<<endl;
		cout<<" -1:返回上一级"<<endl;
		cout<<"<----------------->"<<endl;
	}
}


void Charge()//充值;
{
	int cmd;//cmd标志用户选择的操作，num写入用户输入的金额;
	double num=0;
	bool correct=0;
	string input;
	while(true)
	{
		cout<<"请选择支付所使用的货币:"<<endl;
		for(int i=0; i<NumberOfCurrency; i++)
			cout<<"  "<<i<<":"<<currency[i]<<endl;
		cout<<">>>>";
		cmd=readint();
		if(cmd<0||cmd>=NumberOfCurrency)
		{
			cout<<"请输入一个0到"<<NumberOfCurrency-1<<"之间的整数!";
			Sleep(1000ul);
			cout<<endl<<endl;
			continue;
		}
		break;
	}
	while(true)
	{
		cout<<"请输入充值金额:";
		num=readDouble();
		if(num<0)
		{
			cout<<"只能输入正数!"<<endl<<endl;
			continue;
		}
		break;
	}
	num*=exchangeRate[cmd];
	ChargeInterface(num);
}


void Logout()//登出;
{
	LogoutInterface();
}


void AddGoods()//添加商品;
{
	string input;//添加的商品的名字;
	double price;//添加的商品的价格;
	bool flag=1;
	while(flag)
	{
		flag=0;
		cout<<"请输入商品名:";
		getline(cin, input);
		if(!input.size())
		{
			cout<<"商品名不能为空!"<<endl;
			flag=1;
			continue;
		}
		for(int i=0; i<input.size(); i++)
		{
			if(input[i]==' ')
			{
				cout<<"你的商品名不能包含任何空格!"<<endl;
				flag=1;
				break;
			}
		}
	}
	cout<<"请输入商品价格:";
	price=readDouble();
	AddGoodsInterface(input,price);
}


void DelGoods()//删除商品;
{
	cout<<"请输入你想删除的商品编号:";
	int Id,flag=0;//
	Goods temp;
	Id=readint();
	if(!curUser.queryMyGoods(Id))
	{
		cout<<"非法商品编号!"; // 检查ID是否正确
		Sleep(1000ul);
		cout<<endl<<endl;
		return;
	}
	cout<<"确认删除？"<<endl;
	cout<<"输入1来确认，其他任意数字退出"<<endl;
	cout<<">>>>";
	flag=readint();
	switch (flag)
	{
		case 1:
			temp=DelGoodsInterface(Id);
			if(temp.getName()!="Not Found")
				cout<<temp.getName()<<"已成功删除!";
			Sleep(1000ul);
			cout<<endl<<endl;
			break;
		default :
			break;
	}

}


void Cancell()//注销账户;
{
	string input;
	bool flag=1;
	int w=0;
	cout<<"您真的要狠心注销账户吗？"<<endl;
	cout<<"输入1来确认，其他任意数字退出"<<endl<<endl;
	cout<<">>>>";
	w=readint();
	if(w==1)
	{
		while(flag)
		{
			flag=0;
			cout<<"请输入密码:";
			input=readPass();
			for(int i=0; i<input.size(); i++)
			{
				if( ( (input[i]>'9')||(input[i]<'0') )&&( (input[i]>'Z')||(input[i]<'A') )&&( (input[i]>'z')||(input[i]<'a') ) )
				{
					cout<<endl<<"你的密码应该仅由数字和大小写字母组成!"<<endl<<endl;
					flag=1;
					break;
				}
			}
		}
		bool q=CancellInterface(input);
		if(!q)
		{
			cout<<"注销成功!感谢您的陪伴!";
			Logout();
			Sleep(1000ul);
			cout<<endl<<endl;
			return;
		}
		else
		{
			cout<<"密码错误!";
			Sleep(1000ul);
			cout<<endl<<endl;
		} 
	}
	return;
}


void ShowMeEverything()//仅管理员使用:展示商城所有信息;
{

	ShowMeEverythingInterface();
	cout<<"您可以选择:"<<endl;
	cout<<"<----------------->"<<endl;
	cout<<"  1:封禁用户"<<endl;
	cout<<"  2:解封用户"<<endl;
	cout<<" -1:返回上一级"<<endl;
	cout<<"<----------------->"<<endl;
	int Id=0, cmd=0;
	while(!cmd)
	{
		cout<<">>>>";
		cmd=readint();
		bool w;
		switch (cmd)
		{
			case 1:
				cout<<"请输入您想封禁的用户的Id:";
				Id=readint();
				if(Id==curUser.getId()) 
				{
					cout<<"您正在尝试封禁您自己！！";
					Sleep(1000ul);
					cout<<endl<<endl;
				}
				else
				{
					w=banUserInterface(Id,0);
					if(w) cout<<"封禁成功！"<<endl;
					else cout<<"该Id不存在！";
					Sleep(1000ul);
					cout<<endl<<endl;
				}
				break;
			case 2:
				cout<<"请输入您想解封的用户的Id:";
				Id=readint();
				w=banUserInterface(Id,1);
				if(w) cout<<"解封成功！"<<endl;
				else cout<<"该Id不存在！";
				Sleep(1000ul);
				cout<<endl<<endl;
				break;
			case -1:
				return;
			default:
				cout<<"请输入一个1到2之间的整数或者-1!";
				cmd=0;
				break;
		}
	}
}
