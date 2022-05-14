#include<iostream>
#include<fstream>
#include<string>
#include<cassert>

#define max_person 10

using namespace std;

string FileName = "Saved_Data.txt";

struct Person
{
	int age = 0;
	double body_temprature = 0;
	string gender;
	string firstname;
	string lastname;
	string address;//home address
	string SSN;//social security number
	string Phone_number;
	string history_of_illness;
	string blood_type;
	string breathing_status;
	string cough;
};

//Functions Prototypes
void write(Person personlist[max_person], unsigned int& cur_person_num);//Save Data In a txt File
void Readfromfile(Person personlist[max_person], unsigned int& cur_person_num);
void view_information(Person personlist[max_person], unsigned int cur_person_num);//Show Saved Information
unsigned int Mainmenu();
void AddPerson(Person personlist[max_person], unsigned int& , int );//add new person
void Delete_Person(Person personlist[max_person], unsigned int& cur_person_num);//Delete Person Information
void Edit_Person(Person personlist[max_person], unsigned int& cur_person_num);//Update Person Information
void search_by_ssn(Person personlist[max_person], unsigned int& cur_person_num);//search by Social Security Number
void b_t_more_than_37(Person personlist[max_person], unsigned int& cur_person_num);//Body Temrature More Than 37
void about();
void Handler(Person personlist[max_person], unsigned int& cur_person_num, unsigned int selector);//Main menu Handler Function

int main()
{
	Person personlist[max_person];
	unsigned int cur_person_num = 0, selector = 0;
	Readfromfile(personlist, cur_person_num);
	selector = Mainmenu();
	while (selector != 8)
	{
		Handler(personlist, cur_person_num, selector);
		selector = Mainmenu();
	}
	system("pause>n");
	return 0;
}

void write(Person personlist[max_person], unsigned int& cur_person_num)//Save Data In a txt File
{
	system("cls");
	ofstream File(FileName, ios::out);
	for (unsigned int i = 0; i < cur_person_num; i++)
	{
		if (!File)
		{
			cout << "file is not open." << endl;
			system("pause");
			return;
		}
		else
		{
			File << personlist[i].age << endl;
			File << personlist[i].body_temprature << endl;
			File << personlist[i].gender << endl;
			File << personlist[i].firstname << endl;
			File << personlist[i].lastname << endl;
			File << personlist[i].address << endl;
			File << personlist[i].SSN << endl;
			File << personlist[i].Phone_number << endl;
			File << personlist[i].history_of_illness << endl;
			File << personlist[i].blood_type << endl;
			File << personlist[i].breathing_status << endl;
			File << personlist[i].cough << endl;
		}
	}
	File.close();
}

void Readfromfile(Person personlist[max_person], unsigned int& cur_person_num)
{
	ifstream file(FileName, ios::in);
	if (!file)
	{
		cout << "File is Loading..." << endl;
		system("pause");
	}
	else
	{
		for (int i = 0; !file.eof(); i++)
		{
			file >> personlist[i].age;
			file >> personlist[i].body_temprature;
			file.ignore();
			getline(file, personlist[i].gender);
			getline(file, personlist[i].firstname);
			getline(file, personlist[i].lastname);
			getline(file, personlist[i].address);
			getline(file, personlist[i].SSN);
			getline(file, personlist[i].Phone_number);
			getline(file, personlist[i].history_of_illness);
			getline(file, personlist[i].blood_type);
			getline(file, personlist[i].breathing_status);
			getline(file, personlist[i].cough);
			cur_person_num++;
		}
	}
	file.close();
}


void view_information(Person personlist[max_person], unsigned int cur_person_num)//Show Saved Information
{
	if (cur_person_num == 0)
	{
		cout << "\t\t\t!....No one is Registered....!\a\n";
		system("pause>n");
		return;
	}
	for (unsigned int i = 0; i < cur_person_num; i++)
	{
		system("cls");
		cout << "This is the information of person [" << i << "]:\n" << endl;
		cout << "Age of Person [" << i << "]:" << personlist[i].age << "\n<==========>\n";
		cout << "Body Temrature of Person [" << i << "]:" << personlist[i].body_temprature << "\n<==========>\n";
		cout << "Gender of Person [" << i << "]:" << personlist[i].gender << "\n<==========>\n";
		cout << "First Name of Person [" << i << "]:" << personlist[i].firstname << "\n<==========>\n";
		cout << "Last Name of Person [" << i << "]:" << personlist[i].lastname << "\n<==========>\n";
		cout << "Home Address of Person [" << i << "]:" << personlist[i].address << "\n<==========>\n";
		cout << "Social Security Number (SSN) of Person [" << i << "]:" << personlist[i].SSN << "\n<==========>\n";
		cout << "Phone Number of Person[" << i << "]:" << personlist[i].Phone_number << "\n<==========>\n";
		cout << "History of illness of Person [" << i << "]:" << personlist[i].history_of_illness << "\n<==========>\n";
		cout << "Blood Type of Person [" << i << "]:" << personlist[i].blood_type << "\n<==========>\n";
		cout << "Breathing Status of Person[" << i << "]:" << personlist[i].breathing_status << "\n<==========>\n";
		cout << "'cough' of Person [" << i << "]:" << personlist[i].cough << "\n<==========>\n";
		system("pause>n");
	}
}

unsigned int Mainmenu() {
	unsigned int ch;
	system("cls");
	cout << "\t\t" << "__________ Please Select Your Desired Operation __________" << "\n\n";
	cout << "[1]=======> Add Person:" << "\n";
	cout << "[2]=======> Edit Personal Information:" << "\n";
	cout << "[3]=======> Delete a Person:" << "\n";
	cout << "[4]=======> Search Person by SSN:" << "\n";
	cout << "[5]=======> View Saved Information:" << "\n";
	cout << "[6]=======> Body Temprature More Than 37 Degrees:" << "\n";
	cout << "[7]=======> About Developer:" << "\n";
	cout << "[8]=======> Exit." << "\n\n";
	cout << "Select:";
	cin >> ch;
	return ch;
}

void AddPerson(Person personlist[max_person], unsigned int& cur_person_num, int j = 0)//add new person
{
	system("cls");
	if (cur_person_num >= max_person) {
		cout << "\n" << "!....Error....!" << "\n\n" << "You Have Reached the Maximum, You Are Not Allowed to Add Anymore! " << "\a\n";
		system("pause");
		return;
	}
	cout << "\t\t" << "__________ Enter the Personal Information __________" << endl;
	cout << "Age" << " =====> ";
	cin >> personlist[cur_person_num].age;
	cout << "Body Temprature" << " =====> ";
	cin >> personlist[cur_person_num].body_temprature;
	cin.ignore();
	cout << "Gender" << " =====> ";
	getline(cin, personlist[cur_person_num].gender);
	cout << "First Name" << " =====> ";
	getline(cin, personlist[cur_person_num].firstname);
	cout << "Last Name" << " =====> ";
	getline(cin, personlist[cur_person_num].lastname);
	cout << "Home Address" << " =====> ";
	getline(cin, personlist[cur_person_num].address);
	cout << "SSN" << " =====> ";
	getline(cin, personlist[cur_person_num].SSN);
	cout << "Phone Number" << " =====> ";
	getline(cin, personlist[cur_person_num].Phone_number);
	cout << "Do You have History of Ilness?" << "Select (YES=1,NO=0)" << "\n";
	cin >> j;
	if (j > 1 || j < 0)
	{
		cout << "\t\t" << "!......Error......!" << "\n\n" << "!....Selected Choice is not Recognized.....!" << "\a\n\n";
		assert(j <= 1 && j >= 0);
	}
	else {
		while (j != 0) {
			cout << "Please Enter Your Disorder" << " =====> ";
			cin >> personlist[cur_person_num].history_of_illness;
			break;
		}
	}
	cin.ignore();
	cout << "Blood Type:" << " =====> ";
	getline(cin, personlist[cur_person_num].blood_type);
	cout << "Breathing Status (Normal,Abnormal)" << " =====> ";
	getline(cin, personlist[cur_person_num].breathing_status);

	cout << "Do You have cough?" << " =====> ";
	getline(cin, personlist[cur_person_num].cough);
	cur_person_num++;
	//write information to file;
	write(personlist, cur_person_num);
}

void Delete_Person(Person personlist[max_person], unsigned int& cur_person_num)//Delete Person Information
{
	system("cls");
	unsigned int temp = 0;
	cout << "Which Person You want to delete (Search by SSN):" << "\n";
	string ss_number;//code melli (ID)
	cin >> ss_number;
	for (int i=0; i < cur_person_num; i++)
		if (personlist[i].SSN == ss_number)
		{
			temp = i;
			for (temp; temp < cur_person_num - 1; temp++)
				personlist[temp] = personlist[temp + 1];
			cur_person_num--;
			cout << "\n\t\t" << "!.... Information Deleted Successfully ....!" << "\n\a\n";
			system("pause");
			write(personlist, cur_person_num);
			return;
		}
}

void Edit_Person(Person personlist[max_person], unsigned int& cur_person_num)//Update Person Information
{
	system("cls");
	if (cur_person_num == 0)
	{
		cout << "\t\t\t!....No one is Registered....!\a\n";
		system("pause>n");
		return;
	}
	cout << "\t\t\t\n" << " Please Enter the SSN of Your Specific Person For Editing Information :\n\n";
	cout << "Enter:";
	string ss_number;
	cin >> ss_number;
	for (unsigned int i = 0; i < cur_person_num; i++)
	{
		if (personlist[i].SSN != ss_number)
		{
			cout << "\t\t\n" << "!....Person Not Found....!\a\n";
		}
		else if (personlist[i].SSN == ss_number)
		{
			AddPerson(personlist, i);
			write(personlist, i);
		}
	}
	cout << "\n\n";
	system("pause>n");
}



void search_by_ssn(Person personlist[max_person], unsigned int& cur_person_num)//search by Social Security Number
{
	system("cls");
	string ss_number;
	unsigned int i = 0;
	cout << "Please Enter SSN to Find Your Specific Person: ";
	cin >> ss_number;
	for (i; i < cur_person_num; i++)
	{
		if (personlist[i].SSN == ss_number)
		{
			cout << "\n\n\t\t" << "__________ Result of Search Operation __________\n\n";
			cout << "Age of Person [" << i << "]:" << personlist[i].age << "\n<==========>\n";
			cout << "Body Temrature of Person [" << i << "]:" << personlist[i].body_temprature << "\n<==========>\n";
			cout << "Gender of Person [" << i << "]:" << personlist[i].gender << "\n<==========>\n";
			cout << "First Name of Person [" << i << "]:" << personlist[i].firstname << "\n<==========>\n";
			cout << "Last Name of Person [" << i << "]:" << personlist[i].lastname << "\n<==========>\n";
			cout << "Home Address of Person [" << i << "]:" << personlist[i].address << "\n<==========>\n";
			cout << "Social Security Number (SSN) of Person [" << i << "]:" << personlist[i].SSN << "\n<==========>\n";
			cout << "Phone Number of Person[" << i << "]:" << personlist[i].Phone_number << "\n<==========>\n";
			cout << "History of illness of Person [" << i << "]:" << personlist[i].history_of_illness << "\n<==========>\n";
			cout << "Blood Type of Person [" << i << "]:" << personlist[i].blood_type << "\n<==========>\n";
			cout << "Breathing Status of Person[" << i << "]:" << personlist[i].breathing_status << "\n<==========>\n";
			cout << "'cough' of Person [" << i << "]:" << personlist[i].cough << "\n<==========>\n";
			system("pause>n");
		}
	}
}

void b_t_more_than_37(Person personlist[max_person], unsigned int& cur_person_num)//Body Temrature More Than 37
{
	system("cls");
	cout << "\t\t" << "list of Persons Who have body temprature more than 37:" << "\n\n";
	for (unsigned int i = 0; i < cur_person_num; i++)
	{
		if (personlist[i].body_temprature > 37) {
			cout << i << " - ";
			cout << personlist[i].firstname << " ";
			cout << personlist[i].lastname << "\t";
			cout << "SSN: " << personlist[i].SSN << "\t ";
			cout << "Temprature: " << personlist[i].body_temprature << endl;
		}
	}
	system("pause>n");
}
void about()
{
	system("cls");
	cout << "Written By:\n\t\t";
	cout << "ßßßßßßßßßßßßßßßßßßßß\n";
	cout<<"\n\t\tSayed Alireza Hossaini\n\t   Sadjad University of Technology\n\t\t    August 2020" << endl;
	cout << "\n\t\tßßßßßßßßßßßßßßßßßßßßß\n";
	system("pause");
	return;
}

void Handler(Person personlist[max_person], unsigned int& cur_person_num, unsigned int selector)//Main menu Handler Function
{
	switch (selector)
	{
	case 1:AddPerson(personlist, cur_person_num);//Add New Person Menu
		break;
	case 2:Edit_Person(personlist, cur_person_num);//Update Personal Information
		break;
	case 3:Delete_Person(personlist, cur_person_num);//Delete Personal Information
		break;
	case 4:search_by_ssn(personlist, cur_person_num);//Search Person By Social Security Number Menu
		break;
	case 5:view_information(personlist, cur_person_num);//View Information Menu
		break;
	case 6:b_t_more_than_37(personlist, cur_person_num);//body temprature more than 37
		break;
	case 7:about();
		break;
	default:
		cout << "\n\t\t" << "!.....Error....!" << "\n\n" << "!....Selected Operation is Not Recognized....!" << "\a\n\n";
		system("pause>n");
		break;
	}
}