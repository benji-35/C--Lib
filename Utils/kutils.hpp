/*
** EPITECH PROJECT, 2022
** C++-Lib
** File description:
** kutils
*/

#ifndef KUTILS_HPP_
#define KUTILS_HPP_

#ifndef K_SIZE_T
    namespace kap35 {
        typedef unsigned long size_t;
    }
#endif


#ifdef KAP_DEBUG
    #define DEB_K(x) std::cout << x << std::endl;
    #else
    #define DEB_K(x)
#endif

#ifndef INDEX_OUT_OF_RANGE
    #define INDEX_OUT_OF_RANGE "index is out of range\0"
#endif

#endif /* !KUTILS_HPP_ */
