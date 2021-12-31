#ifndef LIB_H
#define LIB_H

	/*--------------------------

	此处存放所有公共方法

	--------------------------*/
	
	#include<conio.h>

	using namespace std;

	inline int readint()//安全读入int
	{
	    int ret=0,f=1,correct=1;string in;
	    while(true)
	    {
	        correct=1;
	        getline(cin,in);
	        for(int i=1;i<in.size();i++)
	            if((!in.size())||(!isdigit(in[i]))||(in[0]!='-'&&(!isdigit(in[0])))) // 只有首位能出现负号，其余时候只能出现数字
	            {
	                cout<<"请输入一个整数!"<<endl;
	                cout<<">>>>";
	                correct=0;
	                break;
	            }
	        if(correct)
	            break;
	    }
	    if(in[0]=='-')f=-1;
	    else ret=in[0]^48;
	    for(int i=1;i<in.size();i++)
	        ret=(ret<<3)+(ret<<1)+(in[i]^48); // 二进制计算加速
	    return ret*f;
	}

	inline double readDouble() // 安全读入浮点数
	{
	    double ret=0,curBit=0.1,f=1;
	    bool ocurrDot=0,correct=1;
	    string in;
	    while(true)
	    {
	        correct=1;
	        ocurrDot=0;
	        getline(cin,in);
	        /*--------------------------

			合法的浮点数只能在中间出现一次小数点以及开头出现一次负号

			--------------------------*/
	        for(int i=1;i<in.size();i++)
	            if((!in.size())||(!isdigit(in[i]))||(in[0]!='-'&&(!isdigit(in[0]))))
	            {
	                if(i==0||i==in.size()-1||in[i]!='.'||ocurrDot)
	                {
	                    cout<<"请输入一个数字!"<<endl;
	                    cout<<">>>>";
	                    correct=0;
	                    break;
	                }
	                else ocurrDot=1;
	            }
	        if(correct)
	            break;
	    }
	    ocurrDot=0;
	    if(in[0]=='-')f=-1;
	    else ret=in[0]^48;
	    for(int i=1;i<in.size();i++)
	    {
	        if(in[i]=='.')
	        {
	            ocurrDot=1;
	            continue;
	        }
	        if(!ocurrDot)
	            ret=(ret*10)+(in[i]^48);
	        else
	        {
	        	/*--------------------------

				小数部分处理

				--------------------------*/
	            ret+=curBit*double(in[i]^48);
	            curBit/=10;
	        }
	    }
	    ret=round(ret*100)/100; // 保留两位小数
	    return ret*f;
	}

	inline string readPass() // 密码读入
	{
	    string ret="";
	    char ch=getch(); // 使用getch取消回显
	    while(ch!='\r')
	    {
	        if(ch=='\b')
	        {
	            if(ret.size())
	            {
	                putchar('\b'); // 退格时清除字符
	                putchar(' ');
	                putchar('\b');
	                ret.pop_back();
	            }
	        }
	        else
	        {
	            putchar('*');
	            ret+=ch;
	        }
	        ch=getch();
	    }
	    putchar('\0');
	    putchar('\n');
	    return ret;
	}

#endif