#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define delimiter "\n--------------------------------------------------------------------\n"
class Human
{
protected:
	string last_name;
	string first_name;
	int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}

	Human(const std::string& last_name, const std::string& first_name, int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t\t" << this << endl;
	}
	void print()const
	{
		cout << last_name << " " << first_name << " " << age << endl;
	}
};

class Student :public Human
{
	std::string speciality;
	std::string group;
	double rating;
	double attendence;
public:
	const std::string get_speciality()
	{
		return speciality;
	}
	const std::string get_group()
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendence()
	{
		return attendence;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendence(double attendence)
	{
		this->attendence = attendence;
	}
						//Constructors
	Student(const std::string& last_name, const std::string& first_name, int age, 
			const std::string& speciality, const std::string& group, double rating, double attendence
	):Human(last_name,first_name,age)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendence(attendence);
		cout << "SConstructor:\t\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t\t" << this << endl;
	}
	void print()const
	{
		Human::print();
		cout << speciality << " " << group << " " << rating << " " << attendence << endl;
	}
};

class Teacher :public Human
{
	std::string speciality;
	int experience;
public:
	const std::string get_speciality()
	{
		return speciality;
	}
	int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(int experience)
	{
		this->experience = experience;
	}
	Teacher 
	(
		const std::string& last_name, const std::string& first_name, int age,
		const std::string& speciality, int experience
		):Human (last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	void print()const
	{
		Human::print();
		cout << speciality << " " << experience << endl;
	}
};

class Graduate : public Student
{
	std::string subject;
public:
	const std::string get_subject()
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	Graduate
	(
		const std::string& last_name, const std::string& first_name, int age,
		const std::string& speciality, const std::string& group, double rating, double attendence,
		const std::string& subject
	) :Student(last_name, first_name, age, speciality, group, rating, attendence)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	void print()const
	{
		Student::print();
		cout << subject << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Human human("Montana", "Antonio", 30);
	cout << delimiter;
	human.print();
	cout << delimiter;

	Student stud("Pinkman","Jessie", 25, "Chemistry","WW_220", 95, 98);
	cout << delimiter;
	stud.print();
	cout << delimiter;

	Teacher teacher("White", "Walter", 50, "Chemistry", 20);
	cout << delimiter;
	teacher.print();
	cout << delimiter;

	Graduate grad("Schrader", "Hank", 40, "Criminalistic", "OBN", 50, 50, "How to catch");
	cout << delimiter;
	grad.print();
	cout << delimiter;
}