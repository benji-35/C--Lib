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
    kap35::file _file("testFile");

    kap35::text _txt = _file.openT();

    _txt.dump();

    _file.append("test");
}
