/*
** EPITECH PROJECT, 2022
** C++-Lib
** File description:
** unique_ptr
*/

#ifndef UNIQUE_PTR_HPP_
#define UNIQUE_PTR_HPP_

namespace kap35 {
    template<typename T>
    class unique_ptr {
        public:

            unique_ptr(T *ptr) {
                _val = ptr;
            }
            ~unique_ptr() {
                delete val;
            }

            T &get() {
                return *val;
            }

        private:
            T *_val;
    };
}

#endif /* !UNIQUE_PTR_HPP_ */
