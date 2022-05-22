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
    for (unsigned int i = 0; i < 1000; i++) {
        kap35::string trenta = kap35::math::uintToTrentadal(i);
        std::cout << "val: " << std::to_string(i) << ", " << trenta
            << ", back: " << std::to_string(kap35::math::trentadalToUint(trenta)) << std::endl;
    }

    return 0;
}
