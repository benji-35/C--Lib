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
    kap35::map<int, kap35::string> _map;

    _map.add(1, "1");
    _map.add(2, "2");
    _map.add(3, "3");
    _map.add(4, "4");
    _map.add(5, "5");

    std::cout << "map size: " << std::to_string(_map.size()) << std::endl;

    for (int i = 0; i < _map.size(); i++) {
        if (_map.keyExists(i + 1)) {
            std::cout << _map.get(i + 1).toCharArray() << std::endl;
        }
    }
}
