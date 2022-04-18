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
#include "kfile.hpp"
#include "kymlfile.hpp"

#include <iostream>

int main(int ac, char **av)
{
    kap35::string str("Hello World !");

    std::cout << "nb o in " << str.toCharArray() << " = " << std::to_string(str.nbOcurrenceOf("o")) << std::endl;

    return 0;
}
