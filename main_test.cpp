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
#include "kmath.hpp"

#include <iostream>
#include <string>

int main(int ac, char **av)
{
    kap35::string str("Coucou toi !");

    kap35::list<kap35::string> txtL;

    txtL = str.split(" ");

    kap35::text txt(txtL);

    for (kap35::size_t i = 0; i < txt.size(); i++) {
        kap35::string out("txt[");
        std::cout << out + kap35::string(i) + "] = " + txt[i] << std::endl;
    }

    return 0;
}
