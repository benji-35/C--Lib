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
    kap35::string str("Hello World !");
    kap35::list<kap35::string> _splts;
    kap35::text _txt;
    _splts = str.split(' ');

    for (int i = 0; i < _splts.size(); i++) {
        std::cout << _splts.at(i).toCharArray() << std::endl;
    }

    _txt = _splts;

    _txt.dump();

}
