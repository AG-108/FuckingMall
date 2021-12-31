#include<bits/stdc++.h>
#include<windows.h>
#include "class.h"
#include "var.h"
#include "lib.h"
#include "Palette.h"
#include "DatabaseHandle.h"

using namespace std;

extern int loginUser;
extern Account curUser;

const int maxCmd[3]={4,5,6};

void run()
{
	SetConsoleTitle("你血赚，我不赔，两情相悦何不为?");
	system("color f0");
    int cmd=0;
    welcome();
    while(cmd!=-1)
    {
    	printHelp();
        cout<<">>>>";
        cmd = readint();
        if(loginUser==-1)
        {
            switch(cmd)
            {
                case 0: login();break;
                case 1: Register();break;
                case -1: break;
                default: 
                	puts("请输入一个-1到1之间的整数!");
                	Sleep(1000ul);
                	break;
            }
        }
        else 
        {
        	if(cmd>maxCmd[curUser.getAuthority()]||cmd<-1)
        	{
        		cout<<"请输入一个-1到"<<maxCmd[curUser.getAuthority()]<<"之间的整数!"<<endl;
        		Sleep(1000ul);
        		continue;
        	}
        	else
        	{
        		if(curUser.getAuthority()==0)
        		{
        			if(cmd>=3)
        				cmd+=2;
        		}
        		else if(curUser.getAuthority()==1)
        		{
        			if(cmd>=4)
        				cmd++;
        		}
        	}
            switch(cmd)
            {
                case 0: GoShopping();break;
                case 1: ShowMyInformation();break;
                case 2: MyShoppingCar();break;
                case 3: MyGoods();break;
                case 4: ShowMeEverything();break;
                case 5: Logout();break;
                case 6: Cancell();break;
                case -1: break;
            }
        }
    }
    if(loginUser)
        Logout();
}

int main()
{
    Init();
    run();
    End();
    return 0;
}