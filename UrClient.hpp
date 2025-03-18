#include "client.hpp"
#include <string>
#include <iostream>

class UrClient : public Client 
{
private:
    std::string type;
public:
    UrClient() :  Client(), type("OOO"){
        std::cout << "Default constructor UrClient" << std::endl;
    }
    UrClient(std::string name, std::string addres, int numberDoc,std::string t) : Client(name,addres,numberDoc), type(t){
        std::cout << "Constructor UrClient" << std::endl;
    }
    UrClient(const UrClient& i_cl) : Client(i_cl), type(i_cl.type) {
        std::cout << "Copy constructor UrClient" << std::endl;
    }
    ~UrClient(){
        std::cout << "Destructor UrClient" << std::endl;
    }

    std::string getType(){
        return type;
    }

    void setType(std::string s){
        type = s;
    }

    void printClient(){
        std::cout << "UrClient name: " << getName() << std::endl; 
        std::cout << "UrClient addr: " << getAddres() << std::endl; 
        std::cout << "UrClient document number: " << getNumberDoc() << std::endl; 
        std::cout << "UrClient UrClient: " << type << std::endl; 
    }
};

