#include"myExeption.h"
class User
{
protected:
	string login;
	string password;
public:
	User();
	virtual void RegisLogPas() =0;
	virtual string get_login() = 0;
	virtual string get_password() = 0;
	virtual void shifr(char* log) = 0;
	virtual void deshifr(char* log) = 0;


};
class Guest :public User
{
	string full_name;
	string home_adress;
	string telephone_number;
	int counter;
public:
	int get_counter();
	string get_full_name();
	string get_telephone_number();
	string get_login();
	string get_password();
	Guest();
	Guest(string , string , string );
	Guest(string , string );
	
	
	void Registration();
	void RegisLogPas();
	void CheckRegis();
	void AutorizationGuest();
	void PassTest(string SubName);
	void shifr(char* log);
	void deshifr(char* log);
	friend istream& operator>>(istream& is, Guest& S);
	friend ostream& operator<<(ostream& os, const Guest& S);
	virtual void SaveToFile() {}
};

class Admin :public User
{
public:
	string get_login();
	string get_password();
	Admin() ;
	Admin(string , string );
	void RegisLogPas();
	void AutorizationAd();
	void CreateStud();
	void RemoveStud();
	void AddCategory();
	void AddNameTest(int SubName);
	void AddQuestion(string SubName);
	void ShowDatabase();
	void ModifyStud();
	void shifr(char* log);
	void deshifr(char* log);
	friend istream& operator>>(istream& is, Admin& Ad);
	friend ostream& operator<<(ostream& os, const Admin& Ad);
};
