/*
** EPITECH PROJECT, 2022
** C++-Lib
** File description:
** main_test
*/

#include "kexceptions.hpp"
#include "kshared_ptr.hpp"
#include "kunique_ptr.hpp"
#include "kstring.hpp"
#include "ktext.hpp"
#include "kmap.hpp"
#include "klist.hpp"
#include <iostream>

int main(int ac, char **av)
{
    kap35::list<kap35::string> _list;

    _list.push_back("toto");
    _list.push_back("toto2");
    _list.push_back("toto3");

    for (unsigned int i = 0; i < _list.size(); i++) {
        std::cout << _list.at(i).toCharArray() << std::endl;
    }
}
