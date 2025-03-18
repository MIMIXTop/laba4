#include "client.hpp"
#include <string>
#include <iostream>

class IndClient : public Client 
{
private:
    std::string gender;
public:
    IndClient() : Client(), gender("man"){
        std::cout << "Default constructor IndClient" << std::endl;
    }
    IndClient(std::string name, std::string addres, int numberDoc,std::string gen) : Client(name,addres,numberDoc), gender(gen){
        std::cout << "Constructor IndClient" << std::endl;
    }
    IndClient(const IndClient& i_cl) : Client(i_cl), gender(i_cl.gender) {
        std::cout << "Copy constructor IndClient" << std::endl;
    }
    ~IndClient(){
        std::cout << "Destructor IndClient" << std::endl;
    }

    std::string getGender(){
        return gender;
    }

    void setGender(std::string s){
        gender = s;
    }

    void printClient(){
        std::cout << "IndClient name: " << getName() << std::endl; 
        std::cout << "IndClient addr: " << getAddres() << std::endl; 
        std::cout << "IndClient document number: " << getNumberDoc() << std::endl; 
        std::cout << "IndClient gender: " << gender << std::endl; 
    }
};

