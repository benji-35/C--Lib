/*
** EPITECH PROJECT, 2022
** C++-Lib
** File description:
** kexceptions
*/

#ifndef KEXCEPTIONS_HPP_
#define KEXCEPTIONS_HPP_

#include <exception>


namespace kap35 {
    class exception : std::exception {
        public:
            exception(char const* str) {
                _message = str;
            }
            virtual ~exception() throw() {}
            virtual const char* what() const noexcept {
                return _message;
            }
        private:
            char const*_message;
    };
}

#endif /* !KEXCEPTIONS_HPP_ */
