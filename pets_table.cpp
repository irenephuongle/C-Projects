//Irene Le
//CS 163
//May 6th, 2022
#include "pets.h"
//This file implements the table for the animals
ifstream in_file;

//constructor
table::table()
{
	root = nullptr;
}
table::~table(void)
{/*
	for(int i = 0; i < ht_size; ++i)
	{
		node * current = hash_table[i];
		while(current != nullptr)
		{
			delete [] current -> a_pet.breed;
			delete [] current -> a_pet.category;
			delete [] current -> a_pet.personality;
			delete [] current -> a_pet.purpose;
			delete [] current -> a_pet.size;
			delete [] current -> a_pet.keyword;
			delete [] current -> a_pet.color;
			current -> a_pet.breed = nullptr;
			current -> a_pet.category = nullptr;
			current -> a_pet.personality = nullptr;
			current -> a_pet.purpose = nullptr;
			current -> a_pet.size = nullptr;
			current -> a_pet.keyword = nullptr;
			current -> a_pet.color = nullptr;
				
			if(current->next != nullptr)
			{	
			node * hold = hash_table[i]->next;	
			delete current;
			current = hold;
			}
			else
			{
			delete current; 
			current = nullptr;
			}

		}	
	}
	ht_size = 0; */
}
int table::retrieve(char * breed, char * personality, char match[])
{
	//retrieve information for all dogs with a certain breed and 
}

int table::add_animal(const animal & to_add) 
{
	//add a node in sorted order by breed
	return add_animal(root, to_add);
}
int table::add_animal(node *& root, const animal & to_add)
{
	if(!root) //if root is null
	{
		root = new node;
		root->a_pet.breed = new char[strlen(to_add.breed)+1];
		strcpy(root->a_pet.breed, to_add.breed);
		root->a_pet.category = new char[strlen(to_add.category)+1];
		strcpy(root->a_pet.category, to_add.category);
		root->a_pet.personality = new char[strlen(to_add.personality)+1];
		strcpy(root->a_pet.personality, to_add.personality);
		root->a_pet.purpose = new char[strlen(to_add.purpose)+1];
		strcpy(root->a_pet.purpose, to_add.purpose);
		root->a_pet.size = new char[strlen(to_add.size)+1];
		strcpy(root->a_pet.size, to_add.size);
		root->a_pet.keyword = new char[strlen(to_add.keyword)+1];
		strcpy(root->a_pet.keyword, to_add.keyword);
		root->a_pet.color = new char[strlen(to_add.color)+1];
		strcpy(root->a_pet.color, to_add.color);
		root -> left = root -> right = nullptr;
		return 1;
	}

	//otherwise, compare the data to see if we should add it to the left or right
	if(strcmp(to_add.breed, root->a_pet.breed) < 0) //if new breed is less than root's breed
		//insert left
		return 1 + add_animal(root->left, to_add);
	if(strcmp(to_add.breed, root->a_pet.breed) >= 0) //if new breed is greater than root
		//insert right
		return 1 + add_animal(root->right, to_add);



}

int table::load()
{
	animal new_pet;
	char breed[100];
	char category[100];
	char personality[100];
	char purpose[100];
	char size[100];
	char keyword[100];
	char color[100];
	char key_value[100];

	//load each of the animals in the file into thw hash table
	//load individually using the hash function
	//load the rest of the information to the recent animal added
	in_file.open("data.txt");
		while(!in_file.eof())
		{
			in_file.get(breed, 100, '|');
			in_file.ignore(100, '|');
			new_pet.breed = new char[strlen(breed)+1];
			strcpy(new_pet.breed, breed);

			in_file.get(category, 100, '|');
			in_file.ignore(100, '|');
			new_pet.category = new char[strlen(category)+1];
			strcpy(new_pet.category, category);

			in_file.get(personality,100, '|');
			in_file.ignore(100, '|');
			new_pet.personality = new char[strlen(personality)+1];
			strcpy(new_pet.personality, personality);

			in_file.get(purpose, 100, '|');
			in_file.ignore(100, '|');
			new_pet.purpose = new char[strlen(purpose)+1];
			strcpy(new_pet.purpose, purpose);

			in_file.get(size, 100, '|');
			in_file.ignore(100, '|');
			new_pet.size = new char[strlen(size)+1];
			strcpy(new_pet.size, size);

			in_file.get(keyword, 100, '|');
			in_file.ignore(100, '|');
			new_pet.keyword = new char[strlen(keyword)+1];
			strcpy(new_pet.keyword, keyword);

			in_file.get(color, 100, '\n');
			in_file.ignore(100, '\n');
			new_pet.color = new char[strlen(color)+1];
			strcpy(new_pet.color, color);

			add_animal(new_pet); //add this animal to the hash table
			//repeat with another animal
		/*	in_file.get(breed, 100, '|');
			in_file.ignore(100,'|');
			new_pet.breed = new char[strlen(breed)+1];
			strcpy(new_pet.breed, breed);
	*/
		}
		in_file.close();
	return 0;		
}
int table::remove(char * key_value)
{
/*	int index = hash_function(key_value);
	node * previous;
	node * current = hash_table[index];
	//if there is nothing in the index
	if(hash_table[index] == nullptr)
		return 0;

	//if theres only one thing in the index
	if(hash_table[index] -> next == nullptr)
	{
		delete current -> a_pet.breed;
		delete current -> a_pet.category;
		delete current -> a_pet.personality;
		delete current -> a_pet.purpose;
		delete current -> a_pet.size;
		delete current -> a_pet.keyword;
		delete current -> a_pet.color;
		current -> a_pet.breed = nullptr;
		current -> a_pet.category = nullptr;
		current -> a_pet.personality = nullptr;
		current -> a_pet.purpose = nullptr;
		current -> a_pet.size = nullptr;
		current -> a_pet.keyword = nullptr;
		current -> a_pet.color = nullptr;

		delete current;
		current = nullptr;

		return 1;
	}
	while(current != nullptr)
	{
		delete current -> a_pet.breed;
		delete current -> a_pet.category;
		delete current -> a_pet.personality;
		delete current -> a_pet.purpose;
		delete current -> a_pet.size;
		delete current -> a_pet.keyword;
		delete current -> a_pet.color;
		current -> a_pet.breed = nullptr;
		current -> a_pet.category = nullptr;
		current -> a_pet.personality = nullptr;
		current -> a_pet.purpose = nullptr;
		current -> a_pet.size = nullptr;
		current -> a_pet.keyword = nullptr;
		current -> a_pet.color = nullptr;
		
		delete current;
		current = current -> next;	
		
	}
	current = nullptr; */
return 1;	
}


bool table::display_breed(char * match) //display info of particular breed
{
	//traverse through the tree to find a matching breed
	return display_breed(root, match);
return 1;
}
bool table::display_breed(node *& root, char * match)
{
	if(root == nullptr)
		return false;
	//preorder traversal to look for matching breed
	if(strcmp(root->a_pet.breed, match) == 0) //if we found a match
	{

		cout << "Breed: " << root->a_pet.breed << endl;
		cout << "Category: " << root->a_pet.category << endl;
		cout << "Personality: " << root->a_pet.personality << endl;
		cout << "Purpose: " << root->a_pet.purpose << endl;
		cout << "Size: " << root->a_pet.size << endl;
		cout << "Keyword: " << root->a_pet.keyword << endl;
			return true;
	}
	if(strcmp(root->a_pet.breed, match) < 0) //if root data is less than match
		return display_breed(root->right, match); //go to the right pointer
	if(strcmp(root->a_pet.breed, match) > 0) //if root dats is larger than match
		return display_breed(root->left, match);
}
bool table::display_size(char * match)
{
	return display_size(root, match);
}

bool table::display_size(node *& root, char * match)
{
	if(root == nullptr)
		return false;
	//traverse to find a match
	int count = display_size(root->left, match);
	if(strcmp(root->a_pet.size, match) == 0) //if we found a match
	{
		cout << "Breed: " << root->a_pet.breed << endl;
		cout << "Category: " << root->a_pet.category << endl;
		cout << "Personality: " << root->a_pet.personality << endl;
		cout << "Purpose: " << root->a_pet.purpose << endl;
		cout << "Size: " << root->a_pet.size << endl;
		cout << "Keyword: " << root->a_pet.keyword << endl;
	}	
	return display_size(root->right, match);
}
			
int table::display_all()
{
	//display all of the animals in sorted order by breed and personality
	return display_all(root);
}
int table::display_all(node *& root)
{

	//base case
	if(!root)
		return 0;
	int count = display_all(root->left);
	cout << "Breed: " << root->a_pet.breed << endl;
	cout << "Category: " << root->a_pet.category << endl;
	cout << "Personality: " << root->a_pet.personality << endl;
	cout << "Purpose: " << root->a_pet.purpose << endl;
	cout << "Size: " << root->a_pet.size << endl;
	cout << "Keyword: " << root->a_pet.keyword << endl;
	return 1 + display_all(root->right);
}
