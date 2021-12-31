#ifndef LIB_H
#define LIB_H

	/*--------------------------

	�˴�������й�������

	--------------------------*/
	
	#include<conio.h>

	using namespace std;

	inline int readint()//��ȫ����int
	{
	    int ret=0,f=1,correct=1;string in;
	    while(true)
	    {
	        correct=1;
	        getline(cin,in);
	        for(int i=1;i<in.size();i++)
	            if((!in.size())||(!isdigit(in[i]))||(in[0]!='-'&&(!isdigit(in[0])))) // ֻ����λ�ܳ��ָ��ţ�����ʱ��ֻ�ܳ�������
	            {
	                cout<<"������һ������!"<<endl;
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
	        ret=(ret<<3)+(ret<<1)+(in[i]^48); // �����Ƽ������
	    return ret*f;
	}

	inline double readDouble() // ��ȫ���븡����
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

			�Ϸ��ĸ�����ֻ�����м����һ��С�����Լ���ͷ����һ�θ���

			--------------------------*/
	        for(int i=1;i<in.size();i++)
	            if((!in.size())||(!isdigit(in[i]))||(in[0]!='-'&&(!isdigit(in[0]))))
	            {
	                if(i==0||i==in.size()-1||in[i]!='.'||ocurrDot)
	                {
	                    cout<<"������һ������!"<<endl;
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

				С�����ִ���

				--------------------------*/
	            ret+=curBit*double(in[i]^48);
	            curBit/=10;
	        }
	    }
	    ret=round(ret*100)/100; // ������λС��
	    return ret*f;
	}

	inline string readPass() // �������
	{
	    string ret="";
	    char ch=getch(); // ʹ��getchȡ������
	    while(ch!='\r')
	    {
	        if(ch=='\b')
	        {
	            if(ret.size())
	            {
	                putchar('\b'); // �˸�ʱ����ַ�
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