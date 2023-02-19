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
			cout << "Тест - " << buf2 << endl;
			fin2 >> buf2;
			cout << "Тестируемый - " << GuestName << endl;
			cout << "Правильных ответов " << buf2 << " на вопросы\n";
			fin2 >> buf2;
			cout << "Это " << buf2 << " %\n";
			fin2 >> buf2;
			cout << "Оценка - " << buf2 << endl;
			cout << endl;
		}

		fin2.close();
	}


	~Test()
	{
	}
};
