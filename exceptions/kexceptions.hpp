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
    class string;
}

namespace kap35 {

    namespace Exception {
        class Error : public virtual std::exception {
            protected:
                char *_message;
            public:
                explicit Error(char *msg) {
                    _message = msg;
                }
                ~Error() = default;
                const char* what() const noexcept override {
                    return _message;
                }
        };

        class SocketError : public Error {
            public:
                SocketError(char *msg) : Error(msg) {}
                ~SocketError() = default;
        };

        class FloatError : public Error {
            public:
                FloatError(char *msg) : Error(msg) {}
                ~FloatError() = default;
        };

        class StringError : public Error {
            public:
                StringError(char *msg) : Error(msg) {}
                ~StringError() = default;
        };

        class FileError : public Error {
            public:
                FileError(char *msg) : Error(msg) {}
                ~FileError() = default;
        };

        class TextError : public Error {
            public:
                TextError(char *msg) : Error(msg) {}
                ~TextError() = default;
        };

        class MathError : public Error {
            public:
                MathError(char *msg) : Error(msg) {}
                ~MathError() = default;
        };

        class UniquePointerError : public Error {
            public:
                UniquePointerError(char *msg) : Error(msg) {}
                ~UniquePointerError() = default;
        };

        class SharedPointerError : public Error {
            public:
                SharedPointerError(char *msg) : Error(msg) {}
                ~SharedPointerError() = default;
        };
    
        class ListError : public Error {
            public:
                ListError(char *msg) : Error(msg) {}
                ~ListError() = default;
        };

        class MapError : public Error {
            public:
                MapError(char *msg) : Error(msg) {}
                ~MapError() = default;
        };
    }
}

#endif /* !KEXCEPTIONS_HPP_ */
