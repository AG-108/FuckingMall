#ifndef INTERFACE_H
#define INTERFACE_H

	/*--------------------------
							
				�ӿڲ�

		  ������ҵ���߼�����

	--------------------------*/

	#include<bits/stdc++.h>
	#include "class.h"

	using namespace std;

	bool checkUserInterface(string); // ����û����Ƿ���

	void registerInterface(string, int, string, string); // ע��ӿ�

	int LoginInterface(string,string); // ��¼�ӿ�

	bool ResetPassInterface(string,string); // ��������ӿ�

	bool ResetNameInterface(string); // �����û����ӿ�
	
	void GoShoppingInterface(AllGoods); // �����ܽӿ�
	
	void ShowMyInformationInterface(); // �˻���Ϣ�ӿ�
	
	void MyShoppingCarInterface(); // ���ﳵ��Ϣ�ӿ�
	
	bool CheckOutInterface(); // ���˽ӿ�
	
	bool DelGoodsFromShoppingCarInterface(int); // ���ﳵ�����Ʒ�ӿ�
	
	void MyGoodsInterface(); // ������Ʒ��Ϣ�ӿ�
	
	void ChargeInterface(double); // ��ֵ�ӿ�
	
	void LogoutInterface(); // �ǳ��ӿ�
	
	void AddGoodsInterface(string,double); // ���̳������Ʒ�ӿ�
	
	Goods DelGoodsInterface(int); // �̳�ɾ����Ʒ�ӿ�
	
	bool CancellInterface(string); // ע���ӿ�
	
	void ShowMeEverythingInterface(); // ��ӡ�̳���Ϣ�ӿ�

	bool banUserInterface(int,bool); // ����˻��ӿ�

#endif