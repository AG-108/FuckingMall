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
			Goods(); // �޲ι��캯������ն���
			Goods(int,string,double,int,int); // �вι��캯��

			friend istream& operator >> (istream&, Goods&); // ������ʽ���������
			friend ostream& operator << (ostream&, Goods&); // ������ʽ��������
			
			/*--------------------------

			���ڻ�ȡprivate�����ĺ���

			--------------------------*/

			void setName(string); // ��������
			void setPrice(double); // ���ü۸�
			int getId(); // ��ȡID
			double getPrice(); // ��ȡ�۸�
			string getName(); // ��ȡ����
			int getSeller(); // ��ȡ������Ϣ
			
			void printInfo(); // ��ӡ��Ʒ��Ϣ
			void SVinc(); // ��������һ��
			
			/*--------------------------

			��������ʱ��Ҫ����Ԫ�ȽϺ���

			--------------------------*/

			friend bool cmpById(Goods,Goods); // �Ƚ�ID
			friend bool cmpByPrice(Goods,Goods); // �Ƚϼ۸�
			friend bool cmpBySalesVolume(Goods,Goods); // �Ƚ�����
	};//��Ʒ��

	class AllGoods
	{
		private:
			queue<Goods> goodsList;
		public:
			AllGoods(); // �չ��캯��

			friend istream& operator >> (istream&, AllGoods&); // ������ʽ���������
			friend ostream& operator << (ostream&, AllGoods&); // ������ʽ��������

			/*--------------------------

			���ڻ�ȡprivate�����ĺ���

			--------------------------*/

			int getsize(); // ��ȡgoodsList��size()
			
			void showAllInfo(); // ��ӡ������Ʒ��Ϣ
			void addGoods(Goods); // �����Ʒ
			Goods delGoods(int); // ɾ����Ʒ
			Goods queryGoods(int); // ��ѯ��Ʒ��Ϣ
			void incSV(int); // ʹ�б���ĳһ��Ʒ��������
			void sortById(); // ����IDΪ��Ʒ����
			void sortByPrice(); // ���ռ۸�Ϊ��Ʒ����
			void sortBySalesVolume(); // ��������Ϊ��Ʒ����
			AllGoods selectByPrice(double,double); // ���ռ۸�Ϊ��Ʒ����
	};//�����Ʒ��

	class shoppingCar
	{
		private:
			queue<pair<int,int> > contents; 
		public:
			shoppingCar(); // �չ��캯��

			void showAllInfo(); // ��ӡ���ﳵ��������Ϣ
			void addGoods(int); // ���ﳵ��������Ʒ
			bool delGoods(int); // ɾ�����ﳵ�е���Ʒ
			bool payOff(); // ����
			void clear(); // ��չ��ﳵ
	};//���ﳵ��

	class Account
	{
		//Ȩ�� 0-��� 1-���� 2-����Ա
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

			�������캯��

			--------------------------*/

			Account(); // �չ��캯��
			Account(int); // ���ڷ����ض�������Ϣ�Ĺ��캯��
			Account(int,string,int,string,string,bool ban = 0); // ���˻����캯��

			friend istream& operator >> (istream&, Account&); // ������ʽ���������
			friend ostream& operator << (ostream&, Account&); // ������ʽ��������

			/*--------------------------

			���ڻ�ȡprivate�����ĺ���

			--------------------------*/

			int getId(); // ��ȡID
			double getBalance(); // ��ȡ���
			int getAuthority(); // ��ȡȨ�޵ȼ�
			string getName(); // ��ȡ����
			string getPassword(); // ��ȡ����
			bool getBanned(); // ��ȡ�����Ϣ

			void pay(double); // ֧�����
			void charge(double); // ��ֵǮ��
			void setBanned(bool); // �趨���״̬
			bool resetUserName(string); // �����û���
			bool resetPassword(string,string); // ��������
			void logOut(); // �ǳ�
			void queryMyInfo(); // ��ѯ�����˻���Ϣ
			void printInTable(); // �Ա����ʽ����˻���Ϣ
			void shopping(AllGoods); // ����
			bool cancell(string); // ע��
			bool queryMyGoods(int); // ��ѯ�ҵ���Ʒ
			bool AddGoods(string,double); // �����Ʒ
			Goods DelGoods(int); // ɾ����Ʒ
			void printMyGoods(); // ��ӡ������Ʒ��Ϣ
			bool banId(int,bool); // ���ID������Ա��
			void showMeEverything(); // ��ӡ�̳Ǹſ�������Ա��
	};// �˻���

	extern Account curUser;
	extern AllGoods GoodsList;
	extern shoppingCar curShoppingCar;

#endif