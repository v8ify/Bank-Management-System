#include "Linked_list.h"
#include <iostream>

bool Linked_list::isEmpty()
{
	return first == NULL;
}

int Linked_list::size()
{
	Node* current = first;
	int count = 0;
	while (current != NULL)
	{
		++count;
		current = current->link;
	}
	return count;
}

void Linked_list::add_at_end(Account acc)
{
	if (first == NULL)
	{
		first = last = new Node(acc, NULL);
	}
	else
	{
		Node* new_node = new Node(acc, NULL);
		last->link = new_node;
		last = last->link;
	}
}

void Linked_list::remove_by_id(int id)
{
	if (first == NULL)	// if list is empty
	{
		std::cerr << "Cannot delete from an empty list.\n";
	}
	else if (id == first->data)  // first is the required one
	{
		auto temp = first;
		first = first->link;
		delete temp;
	}
	else
	{
		auto trailcurrent = first;
		auto current = first->link;

		bool found = false;

		while (current != NULL && !found)
		{
			if (id == current->data)
			{
				found == true;
				break;
			}

			trailcurrent = current;
			current = current->link;
		}

		if (found)
		{
			trailcurrent->link = current->link;
			delete current;
		}
		else
		{
			std::cerr << "No such element with given id exists.\n";
		}
	}
	
}

void Linked_list::clear()
{
	Node* current = first;
	while (current != NULL)
	{
		auto temp = current;
		current = current->link;
		delete temp;
	}

	first = NULL;
}

Linked_list::~Linked_list()
{
	this->clear();
}