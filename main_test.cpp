/*
** EPITECH PROJECT, 2022
** C++-Lib
** File description:
** main_test
*/

#include "kshared_ptr.hpp"
#include "kstring.hpp"
#include <iostream>
#include <string>
#include <memory>

int main(int ac, char **av)
{
    // kap35::shared_ptr<std::string> _shared(new std::string("coucou toi"));
    // std::shared_ptr<kap35::string> _shared = std::make_shared<kap35::string>("coucou toi");

    kap35::shared_ptr<kap35::string> _shared(new kap35::string("YOP"));
    kap35::shared_ptr<kap35::string> _shared2;

    _shared2 = _shared;

    std::cout << _shared.get().toCharArray() << std::endl;
    std::cout << _shared2.get().toCharArray() << std::endl;

    _shared.clear();

    // std::cout << *_shared.get() << std::endl;

}
