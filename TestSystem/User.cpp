#include"User.h"
User::User() {
	this->login = "Default login";
	this->password = "Default password";
}

int Guest::get_counter() { return counter; }
string Guest::get_full_name() { return full_name; }
string Guest::get_telephone_number() { return telephone_number; }
string Guest::get_login() { return login; }
string Guest::get_password() { return password; }

Guest::Guest() :User() {
	this->full_name = "Default name";
	this->home_adress = "Default homeadress";
	this->telephone_number = "Default telnumber";
	counter = 0;
}
Guest::Guest(string full_name, string home_adress, string telphone_number) {
	this->full_name = full_name;
	this->home_adress = home_adress;
	this->telephone_number = telephone_number;
}
Guest::Guest(string login, string password){
	this->login = login;
	this->password = password;
}

void Guest:: Registration() {
	puts("Введите ФИО:");
	getline(cin, full_name);
	puts("Введите домашний адрес:");
	getline(cin, home_adress);
	puts("Введите номер телефона:");
	getline(cin, telephone_number);
	ofstream fout("Guest_registration.txt", ios_base::out | ios_base::app);
	try {
		if (!fout.is_open()) {
			throw myExeption("Файл не открылся для записи!", "SaveToFile", 102);
			return;
		}
	}
	catch (myExeption obj) {
		obj.Show();
	}
	fout << full_name << " " << home_adress << " " << telephone_number << endl;
	fout.close();
	cout << "Вы успешно зарегестрировались!\n";
}
void Guest:: RegisLogPas() {
	cout << "Регестрация логина и пароля:\n";
	puts("Введите логин для регестрации:");
	getline(cin, login);
	puts("Введите пароль:");
	getline(cin, password);
	string buf = login + " " + password;
	CheckRegis();
	char* str = new char[buf.size() + 1];
	strcpy(str, buf.c_str());
	shifr(str);

	ofstream fout("Guest_entrance.txt", ios_base::out | ios_base::app);
	try {
		if (!fout.is_open()) {
			throw myExeption("Файл не открылся для записи!", "SaveToFile", 102);
			return;
		}
	}
	catch (myExeption obj) {
		obj.Show();
	}
	fout << str << endl;
	fout.close();
}
void Guest::CheckRegis() {
	string logUser, passUser;
	puts("Введите логин:");
	getline(cin, logUser);
	puts("Введите пароль:");
	getline(cin, passUser);
	string buf_str, buf_str2;
	ifstream fin("Guest_entrance.txt", ios_base::in);
	try {
		if (!fin.is_open()) {
			throw myExeption("Файл не открылся для чтения !", "ShowFromFile", 103);
			return;
		}
	}
	catch (myExeption obj) {
		obj.Show();
	}

	buf_str2 = logUser + " " + passUser;
	bool flag = true;
	while (!fin.eof())
	{
		getline(fin, buf_str);

		if (buf_str2 == buf_str) {
			cout << "Такой логин уже есть!:\n";
			flag = false;
			return;
		}

	}
	if (flag == true) {

		cout << "Логин зарегестрирован!\n";
	}
	fin.close();
}
void Guest::AutorizationGuest()
{
	string logUser, passUser;
	string buf_str, buf_str2;
	puts("Введите логин:");
	getline(cin, logUser);
	puts("Введите пароль:");
	getline(cin, passUser);
	ifstream fin("Guest_entrance.txt", ios_base::in);
	try {
		if (!fin.is_open()) {
			throw myExeption("Файл не открылся для чтения !", "ShowFromFile", 103);
			return;
		}
	}
	catch (myExeption obj) {
		obj.Show();
	}

	buf_str2 = logUser + " " + passUser;
	bool flag = true;
	while (!fin.eof())
	{
		getline(fin, buf_str);
		char* str = new char[buf_str.size() + 1];
		strcpy(str, buf_str.c_str());
		deshifr(str);


		if (buf_str2 == this->login) {
			cout << "Student:\n";
			cout << "Вы успешно вошли!!\n";
			flag = false;
			return;
		}

	}
	if (flag == true) {
		cout << "Такого логина не найдено, зарегестрируйтесь,пожалуйста!\n";
	}
	fin.close();
}
void Guest::PassTest(string SubName)
{
	string buf, all_answers;
	char answer;
	int i = 0;
	ifstream fin1(SubName + "_question.txt", ios_base::in);
	ifstream fin2(SubName + "_answer.txt", ios_base::in);
	ifstream fin3(SubName + "_correct_answer.txt", ios_base::in);
	while (!fin1.eof() && !fin2.eof() && !fin3.eof())
	{
		getline(fin1, buf);

		if (buf.length() != 0)
		{
			cout << i + 1 << ". " << buf << endl;
			i++;
			for (char j = 'a'; j <= 'c'; j++)
			{
				getline(fin2, buf);
				cout << j << ") " << buf << endl;
			}
			cin >> answer;
			cin.ignore();
			all_answers += answer;
		}
	}
	int count = 0;
	int max_count = all_answers.size();
	for (int i = 0; i < max_count; i++)
	{
		fin3.get(answer);
		if (answer == all_answers[i])
		{
			count++;
		}
	}
	fin1.close();
	fin2.close();
	fin3.close();
	double percent = (double)count / max_count * 100;
	double mark = 12 * percent / 100;
	cout << "Правильных ответов " << count << "  из вопросов: " << max_count << endl;
	cout << percent << "%\n";
	cout << "Ваша оценка - " << mark << endl;
	ofstream fout(this->login + "_result_Of_test.txt", ios_base::out | ios_base::app);
	fout << SubName << " " << count << " " << percent << " " << mark << endl;
}
void Guest::shifr(char* log)
{
	int key = 3;

	for (int i = 0; i < strlen(log); i++)
	{
		if (log[i] != ' ')
			log[i] += key;
	}
	cout << "Зашифрованое слово: " << log << endl;

}
void Guest::deshifr(char* log)
{
	int key = 3;

	for (int i = 0; i < strlen(log); i++)
	{
		if (log[i] != ' ')
			log[i] -= key;
	}
	cout << "Расшифрованое слово: " << log << endl;
	this->login = string(log);

}
istream& operator>>(istream& is, Guest& S)
{
	is >> S.full_name >> S.home_adress >> S.telephone_number >> S.login >> S.password;
	return is;
}
ostream& operator<<(ostream& os, const Guest& S)
{
	os << S.full_name << S.home_adress << S.telephone_number << S.login << S.password;
	return os;

}

string Admin::get_login() { return login; }
string Admin::get_password() { return password; }
Admin::Admin() :User()
{

}
Admin::Admin(string login, string password)
{
	this->login = login;
	this->password = password;
}

void Admin::RegisLogPas()
{
	cout << "Регестрация логина и пароля:\n";
	puts("Введите логин для регестрации:");
	getline(cin, login);
	puts("Введите пароль:");
	getline(cin, password);
	string buf = login + " " + password;
	char* str = new char[buf.size() + 1];
	strcpy(str, buf.c_str());
	shifr(str);
	ofstream fout("Admin_registration.txt", ios_base::out | ios_base::trunc);
	try {
		if (!fout.is_open()) {
			throw myExeption("Файл не открылся для записи!", "SaveToFile", 102);
			return;
		}
	}
	catch (myExeption obj) {
		obj.Show();
	}
	fout << str << endl;
	fout.close();
}
void Admin::AutorizationAd()
{
	string log_admin, pass_admin;
	string buf_str, buf_str2;
	puts("Введите логин:");
	getline(cin, log_admin);
	puts("Введите пароль:");
	getline(cin, pass_admin);
	ifstream fin("Admin_registration.txt", ios_base::in);
	try {
		if (!fin.is_open()) {
			throw myExeption("Файл не открылся для чтения !", "ShowFromFile", 103);
			return;
		}
	}
	catch (myExeption obj) {
		obj.Show();
	}


	bool flag = true;
	while (!fin.eof())
	{
		buf_str2 = log_admin + " " + pass_admin;
		getline(fin, buf_str);
		char* str = new char[buf_str.size() + 1];
		strcpy(str, buf_str.c_str());
		deshifr(str);


		if (buf_str2 == this->login) {
			cout << "Вы успешно вошли!!\n";
			flag = false;
			break;
		}
	}
	if (flag == true) {

		cout << "Такого логина не найдено, зарегестрируйтесь,пожалуйста!\n";
	}
	fin.close();
}
void Admin::CreateStud()
{
	string full_name, home_adress, telephone_number;
	puts("Введите ФИО:");
	getline(cin, full_name);
	puts("Введите домашний адрес:");
	getline(cin, home_adress);
	puts("Введите номер телефона:");
	getline(cin, telephone_number);
	ofstream fout("Guest_registration.txt", ios_base::out | ios_base::app);
	try {
		if (!fout.is_open()) {
			throw myExeption("Файл не открылся для записи!", "SaveToFile", 102);
			return;
		}
	}
	catch (myExeption obj) {
		obj.Show();
	}
	fout << full_name << " " << home_adress << " " << telephone_number << endl;
	fout.close();
	cout << "Вы успешно зарегестрировали тестируемого!\n";
}
void Admin::RemoveStud() {
	string buf_str1, buf_str2;
	int pos;
	string log;
	puts("Введите логин:");
	getline(cin, log);
	int counter = 0;
	vector <string> vec1, vec2;
	ifstream fin1("Guest_entrance.txt", ios_base::in);
	ifstream fin2("Guest_registration.txt", ios_base::in);

	try {
		if (!fin1.is_open() && !fin2.is_open()) {
			throw myExeption("Файл не открылся для чтения !", "ShowFromFile", 103);
			exit(1);
		}
	}
	catch (myExeption obj) {
		obj.Show();
	}

	while (!fin1.eof() && !fin2.eof())
	{
		getline(fin1, buf_str1);
		getline(fin2, buf_str2);
		vec1.push_back(buf_str1);
		vec2.push_back(buf_str2);

		if (buf_str1.find(log) != -1) {
			pos = counter;
		}
		counter++;
	}
	fin1.close();
	fin2.close();


	ofstream fout1("Guest_entrance.txt", ios_base::out);
	ofstream fout2("Guest_registration.txt", ios_base::out);

	try {
		if (!fout1.is_open() && !fin2.is_open()) {
			throw myExeption("Файл не открылся для записи!", "SaveToFile", 102);
			return;
		}
	}
	catch (myExeption obj) {
		obj.Show();
	}

	for (int i = 0; i < counter; i++)
	{
		if (i != pos) {
			fout1 << vec1[i] << endl;
			fout2 << vec2[i] << endl;
		}

	}
	fout1.close();
	fout2.close();

}
void Admin::AddCategory()
{
	string Category, buf;
	puts("Введите название категории");
	getline(cin, Category);
	ofstream fout("Categories.txt", ios_base::out | ios_base::app);
	fout << Category << endl;
	fout.close();

	ifstream fin("Categories.txt", ios_base::in);
	try {
		if (!fin.is_open()) {
			throw myExeption("Файл не открылся для чтения !", "ShowFromFile", 103);
			return;
		}
	}
	catch (myExeption obj) {
		obj.Show();
	}
	int i = 0;
	while (!fin.eof())
	{
		getline(fin, buf);
		for (int i = 0; i < buf.length(); i++) {
			if (Category == buf)
			{
				break;
			}
		}
	}
	fin.close();
	AddNameTest(i + 1);
}
void Admin::AddNameTest(int SubName)
{
	string TestName;
	puts("Введите название теста");
	getline(cin, TestName);
	ofstream fout("Tests_name.txt", ios_base::out | ios_base::app);
	fout << SubName << " " << TestName << endl;
	fout.close();
	AddQuestion(TestName);
}
void Admin::AddQuestion(string SubName)
{
	string tmp, buf;
	ofstream fout1(SubName + "_question.txt", ios_base::out | ios_base::app);
	puts("Введите вопрос: ");
	getline(cin, buf);
	fout1 << buf << endl;
	fout1.close();
	ofstream fout2(SubName + "_answer.txt", ios_base::out | ios_base::app);
	cout << "Введите ответ: a \n";
	getline(cin, buf);
	fout2 << buf << endl;
	cout << "Введите ответ: b \n";
	getline(cin, buf);
	fout2 << buf << endl;
	cout << "Введите ответ: c \n";
	getline(cin, buf);
	fout2 << buf << endl;
	fout2.close();
	ofstream fout3(SubName + "_correct_answer.txt", ios_base::out | ios_base::app);
	char correct;
	cout << "Введите букву правильного ответа: \n";
	cin >> correct;
	fout3 << correct;
	fout3.close();
}
void Admin::ShowDatabase()
{
	string buf;
	vector <string> vec;
	ifstream fin("Student_registration.txt", ios_base::in);
	while (!fin.eof())
	{
		getline(fin, buf);
		vec.push_back(buf);

	}
	fin.close();

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}
}
void Admin::ModifyStud()
{
	string mod, buf;
	int counter = 0;
	int pos;
	vector <string> vec;
	ifstream fin("Guest_registration.txt", ios_base::in);
	while (!fin.eof())
	{
		getline(fin, buf);
		vec.push_back(buf);
		counter++;
	}
	fin.close();
	ofstream fout("Guest_registration.txt", ios_base::out);
	cout << "Введите позицию для изменения данных\n";
	cin >> pos;
	cin.ignore();
	puts("Введите данные студента: ФИО, адрес, телефон:");
	getline(cin, mod);
	for (int i = 0; i < counter; i++)
	{
		if (i != pos) {
			fout << endl << vec[i];
		}

		else if (i == pos)
		{
			vec[i] = mod;
			fout << endl << vec[i];

		}
	}
	fout.close();
}
void Admin::shifr(char* log)
{
	int key = 3;

	for (int i = 0; i < strlen(log); i++)
	{
		if (log[i] != ' ')
			log[i] += key;
	}
	cout << "Зашифрованое слово: " << log << endl;

}
void Admin::deshifr(char* log)
{
	int key = 3;

	for (int i = 0; i < strlen(log); i++)
	{
		if (log[i] != ' ')
			log[i] -= key;
	}
	cout << "Расшифрованое слово: " << log << endl;
	this->login = string(log);

}
istream& operator>>(istream& is, Admin& Ad)
{
	is >> Ad.login >> Ad.password;
	return is;

}
ostream& operator<<(ostream& os, const Admin& Ad)
{
	os << Ad.login << Ad.password;
	return os;
}