#ifndef DATABASEHANDLE_H
#define DATABASEHANDLE_H

	void Init(); // ���ݿ��ʼ��

	void End(); // ���ݿ����ظ���
	
	bool checkDuplicate(string); // ����û����ظ����
	
	void InsUser(Account); // �����ݿ�����û�
	
	Account CheckUser(string,string); // ����û���Ϣ�쳣������������ض�Ӧ�û����󣬷��򷵻��쳣��Ϣ
	
	bool delUser(int); // �����ݿ�ɾ���û�
	
	void banUser(int,bool); // ����û�
	
	void Load(Account); // �����û�
	
	Account queryUser(int); // ����IDȡ���û�
	
	void printInfoOfUsers(); // ��ӡ�����û���Ϣ

#endif