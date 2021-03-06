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

            T &get() const {
                if (_val == nullptr)
                    throw Exception::UniquePointerError("no value in unique ptr");
                return *_val;
            }

            bool isEmpty() const {
                if (_val == nullptr)
                    return true;
                return false;
            }

        private:
            T *_val = nullptr;
    };
}

#endif /* !UNIQUE_PTR_HPP_ */
