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
	delete(this->_item);
}

void	ItemList::insert_element(AMateria *item_dir)
{
	if (_head == NULL)
	{
		_head = this;
		_tail = this;
	}
	else
	{
		ItemList *new_node = new ItemList(*item_dir);
		_tail->_next = new_node;
		_tail = new_node;
	}
}

void	ItemList::print_list(void)
{
	ItemList	*aux = _head;
	std::cout << "------------------------------------------\n";

	while (aux)
	{
		std::cout <<  aux << " - " << aux->_item << "\n";
		aux = aux->_next;
	}
	std::cout << "------------------------------------------\n";
}

ItemList	*ItemList::get_next(void) const
{
	return (_next);
}

AMateria	*ItemList::get_item(void) const
{
	return (_item);
}
