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
    int nb = 16;

    kap35::string bin = kap35::math::uintToBinary(nb);
    kap35::string hex = kap35::math::uintToHexa(nb);
    kap35::string oct = kap35::math::uintToOctal(nb);

    std::cout << "number : " << std::to_string(nb) << std::endl << std::endl;
    std::cout << "convert:" << std::endl;
    std::cout << "binary : " << bin << std::endl;
    std::cout << "hexa   : " << hex << std::endl;
    std::cout << "octal  : " << oct << std::endl;

    std::cout << std::endl << "back:" << std::endl;

    std::cout << "binary : " << std::to_string(kap35::math::binToUInt(bin)) << std::endl;
    std::cout << "hexa   : " << std::to_string(kap35::math::hexaToUInt(hex)) << std::endl;
    std::cout << "octal  : " << std::to_string(kap35::math::octalToUint(oct)) << std::endl;

    return 0;
}
