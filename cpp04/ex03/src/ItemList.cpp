#include "ItemList.hpp"

#include <iostream>

ItemList *ItemList::_head = NULL;
ItemList *ItemList::_tail = NULL;
bool	ItemList::is_empty = true;

ItemList::ItemList(void): _item(NULL), _next(NULL)
{}
ItemList::ItemList(AMateria &item_dir): _item(&item_dir), _next(NULL)
{}
ItemList &ItemList::operator=(const ItemList &item_list)
{
	this->_item = item_list._item;
	this->_next = item_list._next;
	return (*this);
}

ItemList::~ItemList(void)
{

}

void	ItemList::insert_element(AMateria *item_dir)
{
	ItemList new_node(*item_dir);
	if (_head == NULL)
	{
		_head = this;
		_tail = this;
		is_empty = false;
	}
	else
	{
		std::cout << "yuhu\n";
		_tail->_next = &new_node;
		_tail = &new_node;
	}
	std::cout << "eo\n";
}

void	ItemList::print_list(void)
{
	ItemList	*aux = _head;
	std::cout << "------------------------------------------\n";
	while (aux)
	{
		std::cout << aux->_item << "\n";
		aux = aux->_next;
	}
	std::cout << "------------------------------------------\n";

}