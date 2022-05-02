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

int main(int ac, char **av)
{
    int nb = 43;

    kap35::string bin = kap35::math::intToBinary(nb);
    kap35::string hex = kap35::math::intToHexa(nb);

    std::cout << "nb: " << std::to_string(nb) << ", bin: " << bin << ", hexa: " << hex << std::endl;

    return 0;
}
