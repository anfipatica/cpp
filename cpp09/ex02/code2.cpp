/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:19:10 by ampjimen          #+#    #+#             */
/*   Updated: 2026/04/21 22:35:34 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"
#include <sstream>
#include <stdexcept>
#include <ctime>

// Constructor
//vuelca los numeros en los dos contenedores
PmergeMe::PmergeMe(const std::string &input) {
    std::stringstream ss(input); //convierte str en un flujo de entrada
    int num; //almacena cada numero extraído
    while (ss >> num) { 
        //Manejo el parseo de valores en el main
        /*if (num <= 0) {
            throw std::invalid_argument("Error: Negative or zero values are not allowed");
        }*/
        _values_vec.push_back(num);
        _values_deque.push_back(num);
    }
}

// Destructor
PmergeMe::~PmergeMe() {}

// Constructor de copia
PmergeMe::PmergeMe(const PmergeMe &other)
    : _values_vec(other._values_vec),
      _values_deque(other._values_deque),
      _alreadyPrinted(other._alreadyPrinted) {}

// Operador de asignación
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        _values_vec = other._values_vec;
        _values_deque = other._values_deque;
        _alreadyPrinted = other._alreadyPrinted;
    }
    return *this;
}

/////////////////////////////////////////////////////////////////////
//divide y vencerás
void PmergeMe::fordJohnsonSort(std::vector<int> &container) {
    if (container.size() <= 1) return;

    std::vector<int> left(container.begin(), container.begin() + container.size() / 2);
    std::vector<int> right(container.begin() + container.size() / 2, container.end());

    fordJohnsonSort(left);
    fordJohnsonSort(right);

    // Llamar a mergeInsert con los iteradores, no el contenedor
    mergeInsert(left.begin(), left.end());
    mergeInsert(right.begin(), right.end());

    // Fusión de los resultados en el contenedor original
    mergeInsert(container.begin(), container.end());
}


void PmergeMe::fordJohnsonSort(std::deque<int> &container) {
    if (container.size() <= 1) return;

    std::deque<int> left(container.begin(), container.begin() + container.size() / 2);
    std::deque<int> right(container.begin() + container.size() / 2, container.end());

    fordJohnsonSort(left);
    fordJohnsonSort(right);

    // Llamar a mergeInsert con los iteradores, no el contenedor
    mergeInsert(left.begin(), left.end());
    mergeInsert(right.begin(), right.end());

    // Fusión de los resultados en el contenedor original
    mergeInsert(container.begin(), container.end());
}

//ordena e inserta elementos en una porción de un contenedor usando la búsqueda binaria
void PmergeMe::mergeInsert(std::vector<int>::iterator first, std::vector<int>::iterator last) {
    if (std::distance(first, last) <= 1) return;

    // Dividir el rango
    std::vector<int>::iterator mid = first + std::distance(first, last) / 2;
    std::vector<int> left(first, mid);
    std::vector<int> right(mid, last);

    // Ordenar recursivamente ambas mitades
    mergeInsert(left.begin(), left.end());
    mergeInsert(right.begin(), right.end());

    // Secuencia ordenada usando búsqueda binaria
    std::vector<int> result;
    
    for (std::vector<int>::iterator it = left.begin(); it != left.end(); ++it) {
        int item = *it;
        std::vector<int>::iterator pos = binaryInsert(result.begin(), result.end(), item);
        result.insert(pos, item);
    }
    
    for (std::vector<int>::iterator it = right.begin(); it != right.end(); ++it) {
        int item = *it;
        std::vector<int>::iterator pos = binaryInsert(result.begin(), result.end(), item);
        result.insert(pos, item);
    }

    // Copiar el resultado ordenado de vuelta al contenedor original
    std::copy(result.begin(), result.end(), first);
}



void PmergeMe::mergeInsert(std::deque<int>::iterator first, std::deque<int>::iterator last) {
    if (std::distance(first, last) <= 1) return;

    std::deque<int>::iterator mid = first + std::distance(first, last) / 2;
    std::deque<int> left(first, mid);
    std::deque<int> right(mid, last);

    mergeInsert(left.begin(), left.end());
    mergeInsert(right.begin(), right.end());

    std::deque<int>::iterator itLeft = left.begin();
    std::deque<int>::iterator itRight = right.begin();
    std::deque<int>::iterator itMain = first;

    while (itLeft != left.end() && itRight != right.end()) {
        if (*itLeft <= *itRight) {
            *itMain++ = *itLeft++;
        } else {
            *itMain++ = *itRight++;
        }
    }

    // Agregar los elementos restantes
    while (itLeft != left.end()) {
        *itMain++ = *itLeft++;
    }
    while (itRight != right.end()) {
        *itMain++ = *itRight++;
    }
}


// Función para imprimir el contenedor
template <typename Container>
void PmergeMe::printContainer(const Container &container) const {
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// Función para verificar si el contenedor está ordenado
template <typename Container>
bool PmergeMe::isSorted(const Container &container) const {
    for (typename Container::const_iterator it = container.begin(); it != container.end() - 1; ++it) {
        if (*it > *(it + 1)) return false;
    }
    return true;
}

// Función para iniciar el proceso de ordenamiento
void PmergeMe::init() {
    try {
        std::cout << "Before: ";
        printContainer(_values_vec);
        clock_t start = clock();
        fordJohnsonSort(_values_vec);
        clock_t end = clock();
        std::cout << "After: ";
        printContainer(_values_vec);
        std::cout << "Time to process with std::vector: " << (double)(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
        start = clock();
        fordJohnsonSort(_values_deque);
        end = clock();
        std::cout << "Time to process with std::deque: " << (double)(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
