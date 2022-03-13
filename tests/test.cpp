/*
** EPITECH PROJECT, 2022
** C++-Lib
** File description:
** test
*/

#include "kstring.hpp"
#include "ktext.hpp"
#include "kunique_ptr.hpp"
#include "kshared_ptr.hpp"
#include <criterion/criterion.h>

Test(string, contructor_char_ptr) {
    kap35::string str = "yolo";

    cr_assert_str_eq("yolo", str.toCharArray(), "Error: want [%s] and got[%s]\n", "yolo", str.toCharArray());
}

Test(string, empty_char_constructor) {
    kap35::string str;

    cr_assert_str_eq("", str.toCharArray(), "Error: want [%s] and got[%s]\n", "", str.toCharArray());
}

Test(string, concat_str_1_in_diff) {
    kap35::string str1 = "Hello ";
    kap35::string str2 = "World";

    kap35::string get = str1 + str2;
    kap35::string want = "Hello World";
    cr_assert_str_eq(want.toCharArray(), get.toCharArray(), "Error: want [%s] and got[%s]\n", want.toCharArray(), get.toCharArray());
}

Test(string, concat_str_1_in_same) {
    kap35::string get = "Hello ";
    get += "World";

    kap35::string want = "Hello World";
    cr_assert_str_eq(want.toCharArray(), get.toCharArray(), "Error: want [%s] and got[%s]\n", want.toCharArray(), get.toCharArray());
}

Test(string, to_char_array) {
    char want[14];
    want[0] = 'H';
    want[1] = 'e';
    want[2] = 'l';
    want[3] = 'l';
    want[4] = 'o';
    want[5] = ' ';
    want[6] = 'W';
    want[7] = 'o';
    want[8] = 'r';
    want[9] = 'l';
    want[10] = 'd';
    want[11] = ' ';
    want[12] = '!';
    want[13] = 0;
    kap35::string str = "Hello World !";

    cr_assert_str_eq(want, str.toCharArray(), "Error: want [%s] and got[%s]\n", want, str.toCharArray());
}
