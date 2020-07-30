#include "orderFile.h"

//���캯��
OrderFile::OrderFile(){
	
	//date:3 interval : 2 stuId : 1 stuName���� roomId3 status1
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	string date;		// ����
	string interval;	//ʱ���
	string stuId;		//ѧ�����
	string stuName;		//ѧ������
	string roomId;		//.�������
	string status;		//ԤԼ״̬


	this->m_Size = 0;  //��¼����

	while (ifs >> date && ifs >> interval && ifs >>
		stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		///*cout << date <<endl;
		//cout << interval <<endl;
		//cout << stuId <<endl;
		//cout << stuName <<endl;
		//cout << roomId <<endl;
		//cout << status <<endl;
		//cout << endl;*/

		string key;
		string value;
		map<string, string>m;


		int pos = date.find(":");
		if (pos != -1) {
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size()-pos -1);
			m.insert(make_pair(key, value));
		}

		 pos = interval.find(":");
		if (pos != -1) {
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size()-pos-1);
			m.insert(make_pair(key, value));
		}
		pos = stuId.find(":");
		if (pos != -1) {
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		 pos = stuName.find(":");
		if (pos != -1) {
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		 pos = roomId.find(":");
		if (pos != -1) {
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		 pos = status.find(":");
		if (pos != -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		
		//��Сmap �������뵽�� map ������
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;


	///*	cout << key << endl;
	//	cout << value << endl;*/
	}
	ifs.close();

	//��������map ���� 
	///*for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end();it++) {
	//
	//	cout << "��¼����  " << it->first << "  value =  " << endl;
	//	for (map<string, string>::iterator mit = (*it).second.begin(); mit != it->second.end();mit++ ) {
	//		cout << "  key =  " << mit->first << "  value=  " << mit->second << "";
	//	}
	//	cout << endl;
	//}*/
}
//����ԤԼ��¼
void OrderFile::updateOrder() {
	
	if (this->m_Size == 0) {
		return;// ԤԼ��¼Ϊ0 �� 
	}
	//ɾ�����ؽ�
	ofstream ofs(ORDER_FILE,ios::out |ios::trunc);
	//string date;		// ����
	//string interval;	//ʱ���
	//string stuId;		//ѧ�����
	//string stuName;		//ѧ������
	//string roomId;		//.�������
	//string status;		//ԤԼ״̬

	for (int i = 0; i < this->m_Size;i++) {
		ofs << "date:" << this->m_orderData[i]["date"] << "  ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << "  ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << "  ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << "  ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << "  ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
}