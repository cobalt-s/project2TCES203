//
// Created by Cobalt Stamey on 11/28/25.
//

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <string>
namespace UserInterface {
    void printMainMenu();
    void printActionMenu();
    void printExampleMenu();

    void printError(const std::string& message);
    void printInfo(const std::string& message);


}

#endif //USERINTERFACE_H
