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
    kap35::file _file;

    _file.setPath("test.yml");
    kap35::text txt = _file.openT();

    txt.dump();
    txt.removeEmptyLines();
    std::cout << std::endl << std::endl;
    txt.dump();

    return 0;
}
