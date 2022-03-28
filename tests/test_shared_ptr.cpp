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

Test(shared_ptr, two_shared)
{
    kap35::shared_ptr<int> _sptr1;
    kap35::shared_ptr<int> _sptr2;

    _sptr1 = new int(12);
    _sptr2 = new int(24);
    _sptr2 = _sptr1;

    cr_assert((_sptr1.get() == 12 && _sptr1.get() == _sptr2.get()), "Error: want[12] and sptr1[%d], sprt2[%d]\n", _sptr1.get(), _sptr2.get());
}
