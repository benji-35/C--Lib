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

int main(int ac, char **av)
{
    kap35::ymlFile yml("test.yml");
    kap35::string str("testName");

    if (ac > 1)
        str = av[1];

    try {
        std::cout << "value of [" << str << "] = " << yml.get(str) << std::endl;
    } catch(kap35::exception e) {
        std::cout << "error kap35::exception: " << e.what() << std::endl;
    }

    return 0;
}
