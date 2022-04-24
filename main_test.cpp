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
    kap35::shared_ptr<int> shared;
    kap35::shared_ptr<int> shared2;

    shared = new int(12);

    std::cout << std::to_string(shared.get()) << std::endl;

    shared.clear();
    shared2 = shared;
    int i = -1;
    try {
        i = shared2.get();
    } catch(kap35::exception e) {
        std::cout << "good: " << e.what() << std::endl;
    }

    if (i != -1) {
        std::cout << "error: got (" << std::to_string(shared2.get()) << ")" << std::endl;
    }

    return 0;
}
