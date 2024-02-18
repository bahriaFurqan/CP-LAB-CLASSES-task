#include<iostream>
#include<string>
#include <vector>
using namespace std;

class Dog
{
public:
	string name;
	string breed;
    int age;
	void bark()
	{
		cout << name << " Says Woof!" << endl;
	}
};

class person
{
public:
	string name;
	int age;
	Dog pet;

	void introduce()
	{
		cout << "\nHi! My name is " << name << endl;
        cout<<"And I'm "<<age<<"Years old\n" << endl;
	}
	void introducepet()
	{
		cout << "This is my pet: " << pet.name << endl;
		cout << "He is a " << pet.breed << endl;
		cout << "He is " << pet.age << " years old" << endl;
		pet.bark();
	}
};


class house
{
	public:
		string address;
		vector<person> people;

		void addperson(const person& newperson)
		{
			people.push_back(newperson);
		}
		void displaypeopledata()
		{
			cout<<endl<<" Residents of the house at "<<address<<":-" << endl;
			for (int i = 0; i < people.size(); i++)
			{
				cout << i + 1<< "- Name: " << people[i].name << endl;
			}
			for (;;)
			{
				cout << "Do you want to see details of any of the resident. Press 'y' for yes and 'n' for no." << endl;
				char choice;
				cin >> choice;
				if (choice == 'y' || choice == 'Y')
				{
						cout << "Enter the number of the resident whose details you want to see." << endl;
						int num;
						cin >> num;
						people[num - 1].introduce();
						people[num - 1].introducepet();

						cout << endl;
						continue;
				}
				else if (choice == 'n' || choice == 'N')
				{
					break;
				}
				else
				{
					cout << "Invalid choice" << endl;
					continue;
				}
			}
		}
};
int main()
{
	person newperson;
	house myhouse;

	cout << "Enter the address of the house: ";
	getline(cin, myhouse.address);
	cout << endl;
	
	int num;
	cout << "Enter the number of people: ";
	cin >> num;
	cout << endl;

	for (int i = 0; i < num; i++)
	{
		cout<< "Enter the details of the Resident" << i + 1 << " :-" << endl<<endl;
		cout << "Enter the name of the Resident"<<i+1<<" :" << endl;
		cin>>newperson.name;
		cout << "Enter the age of the Resident" << i + 1 << " :" << endl;
		cin >> newperson.age;
		cin.ignore();
		cout << "Enter the name of the pet of Resident" << i + 1 << " :" << endl;
		getline(cin,newperson.pet.name);
		cout << "Enter the breed of the pet of Resident" << i + 1 << " :" << endl;
		getline(cin,newperson.pet.breed);
		cout<<"Enter the age of the pet of Resident" << i + 1 << " :" << endl;
		cin >> newperson.pet.age;

		myhouse.addperson(newperson);
		cout << "*********************************" << endl;
	}
	for (;;)
	{
		int choice;
		cout << "Press 1 to change the owner's pet\n";
		cout << "Press 2 to see the details of the residents\n";
		cout << "Press 3 to exit\n";
		cin >> choice;

		if (choice == 1)
		{
			cout << "Enter option for the owner whose pet you want to change:- "<<endl;
			for (int i = 0; i < num; i++)
			{
				cout << "Press " << i + 1 << " for Resident = " << myhouse.people[i].name << endl;

			}
			int option;
			cin >> option;

			cout << "Enter the name of the new pet: ";	
			cin.ignore();
			getline(cin, myhouse.people[option - 1].pet.name) ;
			cout << "Enter the breed of the new pet: ";
			getline(cin, myhouse.people[option - 1].pet.breed);
			cout << "Enter the age of the new pet: ";
			cin >> myhouse.people[option - 1].pet.age;
			continue;
		}
		else if (choice == 2)
		{
			myhouse.displaypeopledata();
			continue;
		}
		else if (choice == 3)
		{
			break;
		}
		else
		{
			cout << "Invalid choice\n";
			continue;
		}
	}
	system("pause");
	return 0;
}
