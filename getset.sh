#!/bin/bash

STD='\e[0m'
GRAY='\e[90m'
RED='\e[31m'
GREEN='\e[32m'
YELLOW='\e[33m'
BLUE='\e[34m'
B_BLUE='\e[44m'

# grep -n "private:" inc/Contact.hpp
#sed -i "4i\anything" cpp00/ex01/inc/Contact.hpp 

#---> FUNCTIONS <-----------------------------------------------------------------------#

ft_get_path() {
	read_answer=y

	while [[ $read_answer != 'n' && $read_answer != 'N' ]] ; do
		echo -en "You are currently in "$B_BLUE$PWD$STD
		read -p ", do you wish to move somewhere else? (y/n)" -n 1 read_answer
		echo
		case $read_answer in
			[yY])
				tree $PWD -L 2 -P *.cpp -P Makefile 2>/dev/null
				if [[ $? > 0 ]]; then
					ls
				fi
				read -e -p "Please specify where you want to move to: " new_path
				cd $new_path
				clear -x
			;;
			[nN])
				echo -e $GREEN"\nPerfect :)"$STD
			;;
			*)
				echo -e $RED"\nPlease insert a valid option"$STD
			;;
		esac
	done
}

function ft_get_class() {
	cd ./inc
	if [ $? != 0 ]; then
		echo -e $RED"Invalid Path, no classes found"$STD
	else
		echo -e $BLUE ;ls; echo -e $STD
		read -e -p "Select which class you want to work with: " class_hpp
		class=`echo $class_hpp | tr -d ".hpp"`
		class_cpp=`echo $class_hpp | tr ".hpp" ".cpp"`
	fi
}

function ft_add_variable_in_hpp() {
	read -p "Insert the name of the variale you want to create (no need to write '_'): " variable
	read -p "Specify the full data type (press enter for standard value -> std::string)" type

	#${type//} gets rids of spaces
	if [[ "${type//}"  == "" ]]; then
		type="std::string"
	fi

	#sed inserts the declaration of the private member variable
	sed -i "$last_class_line""i\	\t"$type"\t_$variable;" $class_hpp

	#To choose the line under which to insert the new setter.
	# If there was already a setter defined, we insert the new one under it.
	# Else, under the destructor.

	if grep -qn "set_" $class_hpp ; then
		echo holiwis
		setter_line=`grep -n "set_" $class_hpp | tail -1 | cut -d : -f 1`
	else
		setter_line=`grep -n "~" $class_hpp | tail -1 | cut -d : -f 1`
	fi
	sed -i "$setter_line""a\	\tvoid	set_$variable($type $variable);" $class_hpp

	#To choose the line under which to insert the new getter.
	# Under the last getter or in case there is none, under the setter we just inserted.
	if grep -qn "get_" $class_hpp ; then
		getter_line=`grep -n "get_" $class_hpp | tail -1 | cut -d : -f 1`
	else
		getter_line=`grep -n "set_" $class_hpp | tail -1 | cut -d : -f 1`
	fi
	sed -i "$getter_line""a\	\t$type	get_$variable(void) const;" $class_hpp
}

function ft_add_variable_in_cpp {
	cd ../src

	echo -e "void	$class::set_$variable($type $variable) {" >> $class_cpp
	echo -e "	this->_$variable = $variable;" >> $class_cpp
	echo -e "}\n" >> $class_cpp

	echo -e "$type	$class::get_$variable(void) const {" >> $class_cpp
	echo -e "	return (this->_$variable);" >> $class_cpp
	echo -e "}\n" >> $class_cpp

	cd ../inc
	#It would be cool to insert the setters and getters declarations in order
	#but for now we just insert them at the end of the file.
}

function ft_add_another_variable_menu() {
	read_answer=y

	while [[ $read_answer != 'n' && $read_answer != 'N' ]] ; do
		read -p "add another member variable? (y/n): " -n 1 read_answer
		case $read_answer in
			[yY])
				clear -x
				ft_add_variable_menu
			;;
			[nN])
				echo -e $GREEN"\nHave fun programming! <3"$STD
			;;
			*)
				echo -e $RED"\nPlease insert a valid option"$STD
			;;
		esac
	done
}
function ft_add_variable_menu() {
	echo -e $GRAY
	cat $class_hpp

	if [ $? != 0 ]; then
		echo -e $RED"Invalid CLASS $class"$STD
		exit
	else
		echo -e $STD
		last_class_line=`grep -n "};" $class_hpp | cut -d : -f 1`
		ft_add_variable_in_hpp
		ft_add_variable_in_cpp
		ft_add_another_variable_menu
		#If the user wants to add another variable, it will call this function again
		#in an almost recursive way. I'm not sure If I can call this recursive (?) since I
		#separated that menu into another function but originally it was in here.
	fi
}

#---> MAIN <----------------------------------------------------------------------------#

clear
ft_get_path
sleep 1
clear
ft_get_class
ft_add_variable_menu