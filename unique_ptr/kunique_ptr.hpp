/*
** EPITECH PROJECT, 2022
** C++-Lib
** File description:
** unique_ptr
*/

#ifndef UNIQUE_PTR_HPP_
#define UNIQUE_PTR_HPP_

#include "kexceptions.hpp"

namespace kap35 {
    template<typename T>
    class unique_ptr {
        public:

            unique_ptr(T *ptr) {
                _val = ptr;
            }

            ~unique_ptr() {
                delete _val;
            }

            T &get() {
                if (_val == nullptr)
                    throw exception("no value in unique ptr");
                return *_val;
            }

        private:
            T *_val = nullptr;
    };
}

#endif /* !UNIQUE_PTR_HPP_ */
