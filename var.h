#ifndef VAR_H
#define VAR_H

	//�ⲿ��������

	#include "class.h"
	#include<bits/stdc++.h>

	extern int loginUser=-1; //��ǰ��¼�û���ID��
	extern int GoodsID=0; //��Ʒ��ID�����ڴ�������Ʒ��
	extern int UserID=0; //�û�ID
	extern int Cancelled=0; // ע���û�����
	extern Account curUser=Account(); //��ǰ��¼�û����û��ࣩ
	extern AllGoods shoppinglist=AllGoods();//�����б�
	extern shoppingCar curShoppingCar=shoppingCar();//��ǰ���ﳵ

#endif