#include "User.h"
class Test
{
public:
	Test() {};
	void Show_statistic(string SubName, string GuestName) {
		string buf1, buf2, pos;
		ifstream fin2(GuestName + "_result_Of_test.txt", ios_base::in);
		if (fin2.is_open()) {
			fin2 >> buf2;
			cout << "���� - " << buf2 << endl;
			fin2 >> buf2;
			cout << "����������� - " << GuestName << endl;
			cout << "���������� ������� " << buf2 << " �� �������\n";
			fin2 >> buf2;
			cout << "��� " << buf2 << " %\n";
			fin2 >> buf2;
			cout << "������ - " << buf2 << endl;
			cout << endl;
		}

		fin2.close();
	}


	~Test()
	{
	}
};
