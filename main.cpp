#include <iostream>
#include <string>
#include <vector> 

#include "client.hpp"
#include "journal.hpp"
#include "function.hpp"

int main(){
    std::vector<Journal> journals;
    journals.reserve(10);
    Journal journal = Journal();
    int choice;
    bool finish = true;
    std::string name, addr, s;
    Client cl;
    Client bb = Client{"BOB","st.jh 8",12};
    int num;
    pause();

    while (true) {

        system("clear");
        MainMenu();
        choice = stoi(test(M_INT,"Entry your chois: "));

        switch (choice)
        {
            case mainMenu::ADD_MENU:
                while (finish) {
                    system("clear");
                    AddMenu();
                    choice = stoi(test(M_INT,"Input your chois: "));

                    switch (choice)
                    {
                    case addMenu::ADD_CLIENT:

                        if (journals.size() == 0 && choice == 1){
                            std::cout << "Compani list is empty" << std::endl;
                            pause();
                            break; 
                        }
                        
                        name = test(M_NAME,"Entry client name: ");
                        addr = test(M_ADDR, "Entry client addr: ");
                        num = stoi(test(M_INT,"Entry client number of document: "));

                        if(journals.size() != 1){
                            while (true) {
                                num = stoi(test(M_INT,"Enter the company number to be added: "));
                                if(num <= journals.size()) {
                                    break;
                                }
                                std::cout << "Invalid input" << std::endl;
                            }
                        }else{
                            journals.begin()->addClient(std::move(Client(name,addr,num)));
                            pause();
                            std::cin.clear();
                            break;
                        }

                        journals.at(num - 1).addClient(Client(name,addr,num));
                        pause();
                        std::cin.clear();
                        break;
                    case addMenu::ADD_COMPANI:
                        name = test(M_NAME,"Entry compani name: ");
                        s = test(M_TEL,"Entry compani tel: ");
                        //journal.setAllFields(name, s, {});

                        journals.push_back(Journal{name, s, {}});
                        pause();
                        std::cin.clear();
                        break;
                    case ADD_COPY_CL:
                        name = test(M_NAME,"Entry client name: ");
                        addr = test(M_ADDR, "Entry client addr: ");
                        num = stoi(test(M_INT,"Entry client number of document: "));
                        choice = stoi(test(M_INT,"Entry count copy client: "));

                        if(journals.size() != 1){
                            while (true) {
                                num = stoi(test(M_INT,"Enter the company number to be added: "));
                                if(num <= journals.size()) {
                                    break;
                                }
                                std::cout << "Invalid input" << std::endl;
                            }
                        }else{
                            cl = Client(name,addr,num);
                            journals.begin()->createCopyList(cl,choice);
                            pause();
                            std::cin.clear();
                            break;
                        }
                        cl = Client(name,addr,num);
                        journals.at(num - 1).createCopyList(cl,choice);
                        pause();
                        std::cin.clear();
                        break;
                    case ADD_COPY_COM:
                        name = test(M_NAME,"Entry compani name: ");
                        s = test(M_TEL,"Entry compani tel: ");
                        choice = stoi(test(M_INT,"Entry count copy compani: "));
                        journal = Journal{name, s, {}};
                        for (size_t i = 0; i < choice; ++i) {
                            journals.push_back(journal);
                        }                        
                        pause();
                        std::cin.clear();
                        break;
                    case 5:
                        finish = false;
                        break;
                    }
                }
                finish = true;
                break;
            case mainMenu::MODIF:
                while (finish) {
                    system("clear");
                    ModMenu();
                    choice = std::stoi(test(M_INT,"Entry your chois: "));

                    switch (choice)
                    {
                    case MOD_CLIENT:                       
                        while (finish) {
                            int clientNum;
                            system("clear");
                            ModMenu_client();
                            choice = stoi(test(M_INT,"Entry your chois: "));
                            
                            switch (choice)
                            {
                            case CL_NAME:
                                while (true) {
                                    num = std::stoi(test(M_INT, "Entry the number compani: "));
                                    if(num <= journals.size()){
                                        break;
                                    }
                                    std::cout << "Invalid input" << std::endl;
                                }
                                clientNum = std::stoi(test(M_INT, "Entry the number client: "));
                                journals.at(num - 1).modClient(clientNum, CL_NAME);
                                break;
                            case CL_ADDR:
                                while (true) {
                                    num = std::stoi(test(M_INT, "Entry the number compani: "));
                                    if(num <= journals.size()){
                                        break;
                                    }
                                    std::cout << "Invalid input" << std::endl;
                                }
                                clientNum = std::stoi(test(M_INT, "Entry the number client: "));
                                journals.at(num - 1).modClient(clientNum, CL_ADDR);
                                break;
                            case CL_NUM_DOC:
                                while (true) {
                                    num = std::stoi(test(M_INT, "Entry the number compani: "));
                                    if(num <= journals.size()){
                                        break;
                                    }
                                    std::cout << "Invalid input" << std::endl;
                                }
                                
                                clientNum = std::stoi(test(M_INT, "Entry the number client: "));
                                journals.at(num - 1).modClient(clientNum, CL_NUM_DOC);
                                break;
                            case 4:
                                finish = false;
                                break; 
                            default:
                                break;
                            }
                        }
                        finish = true;
                        break;
                    case MOD_COMP:
                        while (finish) {
                            system("clear");
                            ModMenu_compani();
                            choice = stoi(test(M_INT,"Entry your chois: "));
                            
                            switch (choice)
                            {
                            case CM_NAME:
                                while (true) {
                                    num = std::stoi(test(M_INT, "Entry the number compani: "));
                                    if(num <= journals.size()){
                                        journals.at(num - 1).modCompami(CM_NAME);
                                        break;
                                    }
                                    std::cout << "Invalid input" << std::endl;
                                }
                                
                                break;
                            case CM_TEL:
                                while (true) {
                                    num = std::stoi(test(M_INT, "Entry the number compani: "));
                                    if(num <= journals.size()){
                                        journals.at(num - 1).modCompami(CM_TEL);
                                        break;
                                    }
                                    std::cout << "Invalid input" << std::endl;
                                }
                                break;
                            case 3:
                                finish = false;
                                break; 
                            default:
                                break;
                            }
                        }
                    finish = true;
                        break;
                    case 3:
                        finish = false;
                        break;
                    default:
                        break;
                    }
                }
                finish = true;
                break;
            case mainMenu::REMOV:
                while (finish) {
                    int clientNum;
                    system("clear");
                    RemovMenu();
                    choice = stoi(test(M_INT,"Entry your chois: "));

                    switch (choice)
                    {
                    case REMOV_CL:
                        while (true) {
                            num = std::stoi(test(M_INT, "Entry the number compani: "));
                            if(num <= journals.size()) {
                                break;
                            }else{
                                std::cout << "Invalid input" << std::endl;
                            }
                        }
                        
                        while (true) {
                            clientNum = std::stoi(test(M_INT, "Entry the number client: "));
                            if (clientNum <= journals.at(num - 1).getSizeListOfClient()) {
                                journals.at(num - 1).removClient(clientNum - 1);
                                break;   
                            } else {
                                std::cout << "Invalid input" << std::endl;
                            }
                        }
                        break;
                    case REMOV_CL_ALL:
                        while (true) {
                            num = std::stoi(test(M_INT, "Entry the number compani: "));
                            if(num <= journals.size()) {
                                break;
                            }else{
                                std::cout << "Invalid input" << std::endl;
                            }
                        }

                        journals.at(num - 1).removClient();
                        break;
                    case REMOV_CM:
                        while (true) {
                            num = std::stoi(test(M_INT, "Entry the number compani: "));
                            if(num <= journals.size()) {
                                break;
                            }else{
                                std::cout << "Invalid input" << std::endl;
                            }
                        }

                        journals.erase(journals.begin() + (num - 1));
                        break;
                    case REMOV_CM_ALL:
                        journals.clear();
                        std::cout << "Compani list clear" << std::endl;
                        break;
                    case 5:
                        finish = false;
                        break;
                    default:
                        break;
                    }
                }
                finish = true;
                break;
            case mainMenu::PRINT:
                num = 1;
                for (auto &&now : journals) {
                    std::cout << "================< "<< num++ <<" >===============" << std::endl;
                    now.print();
                }
                pause();
                break;
            case 5:
                exit(0);
                break;
            case 6:
                
                journals.at(0).createCopyList(bb,10);
                break;
            default:
                break;
        }
    }   
}