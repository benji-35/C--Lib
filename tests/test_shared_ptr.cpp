/*
** EPITECH PROJECT, 2022
** C++-Lib
** File description:
** test_shared_ptr
*/

#include "kstring.hpp"
#include "ktext.hpp"
#include "kunique_ptr.hpp"
#include "kshared_ptr.hpp"
#include <criterion/criterion.h>

Test(shared_ptr, first_test)
{
    kap35::shared_ptr<int> _sptr;
    _sptr = new int(12);
    cr_assert(_sptr.get() == 12, "Error: want[12] and got[%d]\n", _sptr.get());
}
