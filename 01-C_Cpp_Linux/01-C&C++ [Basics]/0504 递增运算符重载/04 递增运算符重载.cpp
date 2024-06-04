#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyInter
{
	friend ostream& operator<<(ostream& cout, MyInter& myInt);
public:
	MyInter()
	{
		m_Num = 0;
	}

	//ǰ��++ ����
	MyInter& operator++() // ����������MyInter�����ã������Ϳ�����ʽ���
	{
		this->m_Num++;
		return *this;
	}

	//����++ ����
	MyInter operator++(int)
	{
		//�ȼ�¼��ʼ״̬0
		MyInter temp = *this;

		//���ֱ���+1
		this->m_Num++;

		//���ص��ǳ�ʼ��״̬0
		return temp; //����++���ص���ֵ���������õĻ�temp�����������ʧЧ�ˣ�temp��ջ�ϣ��������ʧ
	}

private:
	int m_Num;
};


ostream& operator<<(ostream& cout , MyInter& myInt)
{
	cout << myInt.m_Num;
	return cout;
}

void test01()
{
	MyInter myInt;
	cout << ++(++myInt) << endl; 
	cout << myInt << endl; 
}

void test02()
{
	MyInter myInt;

	cout << myInt++ << endl;
	cout << myInt << endl;

}

int main(){
	//test01();
	test02();


	//int a = 0;
	//cout << ++(++a) << endl;
	//cout << a << endl;

	//int b = 0;
	//cout << (b++)++ << endl;

	system("pause");
	return EXIT_SUCCESS;
}