#!/bin/bash

STD='\e[0m'
GRAY='\e[90m'
RED='\e[31m'
GREEN='\e[32m'
YELLOW='\e[33m'
BLUE='\e[34m'
B_BLUE='\e[44m'

clear

#---> FUNCTIONS <-----------------------------------------------------------------------#

ft_get_path()
{
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

function ft_create_hpp() {
	file=inc/"$class".hpp
	define=`echo "$class"_HPP | tr '[:lower:]' '[:upper:]'`

	mkdir -p inc
	touch $file
	echo "#ifndef $define" > $file
	echo -e "# define $define\n" >> $file
	printf "class %s {\n\tpublic:\n\t\t%s(void);\n\t\t~%s(void);\n\n\tprivate:\n};\n\n"\
		$class $class $class >> $file
	echo "#endif" >> $file
}

function ft_create_cpp() {
	file=src/"$class".cpp

	mkdir -p src
	touch src/"$class".cpp
	echo -e "#include \"$class.hpp\"\n" > $file
	printf "%s::%s(void) {}\n\n" $class $class >> $file
	printf "%s::~%s(void) {}" $class $class >> $file
}

function ft_create_class() {

	clear
	read -p "What class do you want to create? " class
	ft_create_hpp
	ft_create_cpp

	read -p "Do you wish to create any more classes in $PWD? (y/n)" -n 1 read_answer
	case $read_answer in
	[yY])
		ft_create_class
	;;
	[nN])
		echo -e $GREEN"\nThank you for using CPPEITOR.SH :)"$STD
	;;
	*)
		echo -e $RED"\nPlease insert a valid option"$STD
	;;
	esac
}

#---> START <---------------------------------------------------------------------------#

ft_get_path
sleep 1
ft_create_class