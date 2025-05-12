#include "function.hpp"
#include <iostream>

void MainMenu(){
    std::cout << "====================================" << std::endl;
    std::cout << "              Main Menu             " << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "1.Add " << std::endl;
    std::cout << "2.Modificotion " << std::endl;
    std::cout << "3.Remov " << std::endl;
    std::cout << "4.Print " << std::endl;
    std::cout << "5.Exit " << std::endl;
    std::cout << "====================================" << std::endl;
}

void PrintMenu(){
    std::cout << "====================================" << std::endl;
    std::cout << "             Print Menu             " << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "1.Print all compani" << std::endl;
    std::cout << "2.Print all clients" << std::endl;
    std::cout << "3.Back" << std::endl;
    std::cout << "====================================" << std::endl;
}

void AddMenu(){
    std::cout << "====================================" << std::endl;
    std::cout << "              Add Menu              " << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "1.Add compani" << std::endl;
    std::cout << "2.Add copy client" << std::endl;
    std::cout << "3.Add copy compani" << std::endl;
    std::cout << "4.Add UrClient" << std::endl;
    std::cout << "5.Add IndClient" << std::endl;
    std::cout << "6.Back" << std::endl;
    std::cout << "====================================" << std::endl;
}

void RemovMenu(){
    std::cout << "====================================" << std::endl;
    std::cout << "             Remov Menu             " << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "1.Remov one client " << std::endl;
    std::cout << "2.Remov all clients " << std::endl;
    std::cout << "3.Remov one compani " << std::endl;
    std::cout << "4.Remov all companis " << std::endl;
    std::cout << "5.Back" << std::endl;
    std::cout << "====================================" << std::endl;
}

void ModMenu(){
    std::cout << "====================================" << std::endl;
    std::cout << "         Modificotion Menu          " << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "1.Modificot client " << std::endl;
    std::cout << "2.Modificot compani" << std::endl;
    std::cout << "3.Back" << std::endl;
    std::cout << "====================================" << std::endl;
}

void ModMenu_client(){
    std::cout << "====================================" << std::endl;
    std::cout << "     Modificotion Menu(client)      " << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "1.Modificot client name " << std::endl;
    std::cout << "2.Modificot addr" << std::endl;
    std::cout << "3.Modificot number of document " << std::endl;
    std::cout << "4.Modificot type of UrClient " << std::endl;
    std::cout << "5.Modificot gender of IndClient " << std::endl;
    std::cout << "6.Back" << std::endl;
    std::cout << "====================================" << std::endl;
}

void ModMenu_compani(){
    std::cout << "====================================" << std::endl;
    std::cout << "     Modificotion Menu(compani)     " << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "1.Modificot compani name" << std::endl;
    std::cout << "2.Modificot telephon" << std::endl;
    std::cout << "3.Back" << std::endl;
    std::cout << "====================================" << std::endl;
}

bool isValidInput4_5(const std::string& s) {
    if (s.size() == 0) {
        std::cout << "Empty input" << std::endl;
        return false;
    }

    if(s.size() > 10){
        std::cout << "Incorrect input" << std::endl;
        return false;
    }

    for (char ch : s) {
        if (!isdigit(ch)) {
            std::cout << "Is not digit" << std::endl;
            return false;
        }
    }
    return true;
}

bool isValidInput(const std::string& s) {
    for (char ch : s) {
        if (!((ch >= 'a' && ch <= 'z') or (ch >= 'A' && ch <= 'Z'))) {
            std::cout << "Is not Name" << std::endl;
            return false;
        }
    }
    return true;
}

bool isTelNum(std::string s) {
    if (s.size() == 0) {
        std::cout << "Empty input" << std::endl;
        return false;
    }

    if(s[0] != '+') {
        std::cout << "Incorrect input" << std::endl;
        return false;        
    }

    if(s.size() != 13){
        std::cout << "Incorrect input" << std::endl;
        return false;
    }

    for (int i = 1; i < s.size(); ++i) {
        if (!isdigit(s[i])) {
            std::cout << "Is not digit" << std::endl;
            return false;
        }
    }
    return true;
}

bool isValidAddr(const std::string& s) {
    if((s[0] == 's' && s[1] == 't' && s[2] == '.') || 
        (s[0] == 'a' && s[1] == 'v' && s[2] == '.') ) {
            for (size_t i = 3; i < s.size(); ++i) {
                if(s[i] == ' ') {

                    int t = s.size() - i;
                    if(t <= 1){
                        std::cout << "Incorrect input addr" << std::endl;
                        return false;
                    }
                    for (size_t j = i + 1; j < s.size(); ++j) {
                        if(!isdigit(s[j])) {
                            std::cout << "Incorrect input addr" << std::endl;
                            return false;                                    
                        }   
                    }
                    if(i + 1 <= s.size()){
                        return true;
                    } else {
                        return false;
                    }
                }
                if(!isalpha(s[i])) {
                    std::cout << "This is no addr" << std::endl;
                    return false;
                }
            }
        } 
            
        std::cout << "Incorrect input addr" << std::endl;
        return false;
}

std::string test(typeTest magicNumber ,std::string str){
    std::string s;
    std::cin.clear();
    switch (magicNumber) {
        case M_INT: // int
            while (true) {
                std::cout << str;
                std::getline(std::cin,s);

                if(!isValidInput4_5(s)){
                    continue;
                }else{
                    return s;
                }  
            }
            break;
        case M_NAME: // string
            while (true) {
                std::cout << str;
                std::getline(std::cin, s);

                if (!isValidInput(s)) {
                    continue;
                }else{
                    std::cin.clear();
                    return s;
                }
            }
            break;
        case M_ADDR: //addr
            while (true) {
                std::cout << str;
                std::getline(std::cin, s);

                if(!isValidAddr(s)){
                    continue;
                }else{
                    return s;
                }
            } 
            break;
        case M_TEL:// tel
            while (true) {
                std::cout << str;
                std::getline(std::cin, s);

                if (!isTelNum(s)) {
                    continue;
                }else{
                    return s;
                }
            }
            break;
        case M_IND:// tel
            while (true) {
                std::cout << str;
                std::getline(std::cin, s);

                if (s != "wonem" && s != "man") {
                    continue;
                }else{
                    return s;
                }
            }
            break;
        case M_UR:// tel
            while (true) {
                std::cout << str;
                std::getline(std::cin, s);

                if (s != "OOO" && s != "IP" && s != "OAO") {
                    continue;
                }else{
                    return s;
                }
            }
            break;
        case M_TYPE_CL:
            while (true) {
                std::cout << str;
                std::getline(std::cin, s);

                if (s != "Ur" && s != "Ind") {
                    continue;
                }else{
                    if(s == "Url"){
                        return "1";
                    }else{
                        return "2";
                    }
                }
            }
            break;
    }
    return "";
}

void pause() {
    std::cout << "Press Enter to continue...";
    std::cin.get();
}