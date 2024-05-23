//Irene Le
//CS 163
//May 6th, 2022
//This is the header file. It contains the data for every animal
#include <iostream>
#include <cctype>
#include <cstring>
#include <cmath>
#include <fstream>

using namespace std;

//This is a class that manages an individual pet
struct animal
{ 
	char * breed;
	char * category;
       	char * personality;
	char * purpose;
       	char * size;
	char * keyword;
	char * color;

};

//This is a node that contains a pet and a next pointer
struct node
{
	animal a_pet;
	node * left;
	node * right;
};

//Make a hash table of animals
//array of head pointers to a linear linked list of nodes, each node has an animal and it info
class table
{
	public:
		table();
		int add_animal(const animal & to_add);
		int retrieve(char * find, animal & found);
		int load();

		~table();
		int display_all();
		bool display_breed(char * match);
		int retrieve(char * breed, char * personality, char match[]);
		int remove(char * breed);
		bool display_size(char * match);
		

	private:
		node * root;
		int display_all(node *& root);
		int add_animal(node *& root, const animal & to_add);
		bool display_breed(node *& root, char * match);
		bool display_size(node *& root, char * match);
};


