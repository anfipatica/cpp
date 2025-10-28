#ifndef ITEMLIST_HPP
# define ITEMLIST_HPP

class AMateria;

class ItemList
{
public:
	ItemList(void);
	ItemList(AMateria &item_dir);
	ItemList &operator=(const ItemList &item_list);
	~ItemList(void);

	ItemList	*get_next(void) const;
	AMateria	*get_item(void) const;
	void	insert_element(AMateria *item_dir);
	void	print_list(void);


private:
	ItemList(const ItemList &list);

	static ItemList	*_head;
	static ItemList	*_tail;
	AMateria		*_item;
	ItemList		*_next;
};

#endif