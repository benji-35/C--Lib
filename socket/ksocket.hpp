/*
** EPITECH PROJECT, 2022
** C++-Lib
** File description:
** ksocket
*/

#ifndef KSOCKET_HPP_
#define KSOCKET_HPP_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <functional>
#include "kexceptions.hpp"

namespace kap35 {

    class Socket
    {
        public:

            enum Protocol {
                TCP,
                UDP
            };

            enum FamilyProtocol {
                INET,
                INET6
            };

            Socket() {

            }

            ~Socket() {
                disconnect();
            }

            bool connectServer() {
                if (!isServer)
                    return;
                __loopServer();
            }

            bool connectClient() {
                if (isServer)
                    return;
                __loopClient();
            }

            void disconnect() {
                if (!isConnected)
                    return;
                isConnected = false;
            }

            void setFunction(std::function<void(Socket &sock, int fd)> func) {
                _func = func;
            }

            void sendMessage() {}

        private:
            bool isConnected = false;
            bool isServer = false;
            int nbMax = -1;

            FamilyProtocol _fProtocol;
            Protocol _protocol;

            std::function<void(Socket &sock, int fd)> _func;

            void __loopServer() {
                while (isConnected) {

                }
            }

            void __loopClient() {
                while (isConnected) {

                }
            }

        protected:
    };

}

#endif /* !KSOCKET_HPP_ */
