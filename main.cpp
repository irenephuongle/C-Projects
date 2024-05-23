//Irene Le
#include "pets.h"

int main()
{
	table my_pets; //tree of pet struct
	animal a_pet; //pet struct object
	char response;
	char answer;
	char go_to_menu;
	char key[31];
	char breed[31];
	char category[50];
	char personality[31];
	char purpose[21];
	char size[12];
	char keyword[31];
	char color[21];
	
	//Menu
	int fill = my_pets.load();
	do{
		cout << "What would you like to do? A. Add an animal to the list. B. Display all animals. C. Display all information of a certain breed. D. Remove a certain breed. E. Display all breeds of the same size. ";
		cin >> answer;
		cin.ignore(100,'\n');

		if(toupper(answer) == 'A')
		{
			do
			{
				cout << "Would you like to enter an animal? ";
				cin >> response;
				cin.ignore(100,'\n');
				if(toupper(response) == 'Y')
				{
					cout << "Enter the breed: ";
					cin.get(breed, 31, '\n');
					cin.ignore(100,'\n');
					
					a_pet.breed = new char[strlen(breed)+1];
					strcpy(a_pet.breed, breed);
							
					cout << "Enter the category: ";
					cin.get(category, 50, '\n');
					cin.ignore(100,'\n');
					
					a_pet.category = new char[strlen(category)+1];
					strcpy(a_pet.category, category);
					
					cout << "Enter the personality: ";
					cin.get(personality, 31, '\n');
					cin.ignore(100,'\n');
					
					a_pet.personality = new char[strlen(personality)+1];
					strcpy(a_pet.personality, personality);

					cout << "Enter the purpose: ";
					cin.get(purpose, 21, '\n');
					cin.ignore(100,'\n');
					
					a_pet.purpose = new char[strlen(purpose)+1];
					strcpy(a_pet.purpose, purpose);

					cout << "Enter the size: ";
					cin.get(size, 12, '\n');
					cin.ignore(100,'\n');
					
					a_pet.size = new char[strlen(size)+1];
					strcpy(a_pet.size, size);

					cout << "Enter the keyword: ";
					cin.get(keyword, 31, '\n');
					cin.ignore(100,'\n');
					
					a_pet.keyword = new char[strlen(keyword)+1];
					strcpy(a_pet.keyword, keyword);

					cout << "Enter the color: ";
					cin.get(color, 21, '\n');
					cin.ignore(100,'\n');
					
					a_pet.color = new char[strlen(color)+1];
					strcpy(a_pet.color, color);

					int count = my_pets.add_animal(a_pet);
				//	count = my_pets.display_all();
				}



			}while(toupper(response) == 'Y');
			cout << "Would you like to go back to the menu? ";
			cin >> go_to_menu;
			cin.ignore(100,'\n');
		}

		if(toupper(answer) == 'B')
		{
			my_pets.display_all();
			cout << "Would you like to go back to the menu? ";
			cin >> go_to_menu;
			cin.ignore(100,'\n');
		}

		if(toupper(answer) == 'C')
		{
			do
			{
				cout << "Would you like to enter a breed? ";
				cin >> response;
				cin.ignore(100,'\n');
				if(toupper(response) == 'Y')
				{	
					cout << "What is the breed? ";
					cin.get(key, 31, '\n');
					cin.ignore(100, '\n');
					my_pets.display_breed(key);
				}

			}while(toupper(response) == 'Y');
			cout << "Would you like to go back to the menu? ";
			cin >> go_to_menu;
			cin.ignore(100,'\n');
		}

		if(toupper(answer) == 'D')
		{
			do
			{ 
				cout << "Would you like to remove a breed? ";
				cin >> response;
				cin.ignore(100,'\n');
				if(toupper(response) == 'Y')
				{
					cout << "What is the breed? ";
					cin.get(key, 31, '\n');
					cin.ignore(100 ,'\n');
					int removed = my_pets.remove(key);
					if(removed == 1)
						cout << "We've successfully removed " << key << endl;
					if(removed == 0)
						cout << "We couldn't remove " << key << endl;
				}
			}while(toupper(response) == 'Y');

			cout << "Would you like to go back to the menu? ";
			cin >> go_to_menu;
			cin.ignore(100,'\n');
		}

		if(toupper(answer) == 'E')
		{
			do
			{
				cout << "Would you like to enter a size? ";
				cin >> response;
				cin.ignore(100,'\n');
				if(toupper(response) == 'Y')
				{
					cout << "What is the size you want to search for? (small, medium, or large) ";
					cin.get(key, 31, '\n');
					cin.ignore(100,'\n');
					int display_p = my_pets.display_size(key);
				}
			}while(toupper(response) == 'Y');

			cout << "Would you like to go back to the menu? ";
			cin >> go_to_menu;
			cin.ignore(100,'\n');
		}

	}while(toupper(go_to_menu) == 'Y');
	cout << "Goodbye!" << endl;

	my_pets.~table();
	 response = '\0';
	 answer = '\0';
	 go_to_menu = '\0';

}
