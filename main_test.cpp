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
#include <iostream>

int main(int ac, char **av)
{
    kap35::string str("Hello World\t!");
    kap35::list<kap35::string> separators;
    kap35::text txt;

    separators.push_back(" ");
    separators.push_back("\t");

    txt = str.ssplit(separators);
    txt.dump();
    separators.clear();
}
