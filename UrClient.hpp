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

    std::string getType() const{
        return type;
    }

    void setType(std::string s){
        type = s;
    }

    void printClient(std::ostream& os) const override{
        os << "UrClient name: " << getName() << std::endl; 
        os << "UrClient addr: " << getAddres() << std::endl; 
        os << "UrClient document number: " << getNumberDoc() << std::endl; 
        os << "UrClient UrClient: " << type << std::endl; 
    }

    UrClient* clone() override {
        return new UrClient(*this);
    }

    UrClient& operator=(UrClient& cl) {
        this->type = cl.type;
        this->setAddr(cl.getAddres()); 
        this->set(cl.getName());
        this->set(cl.getNumberDoc());
        return *this;
    }

    UrClient& operator=(UrClient&& cl) {
        this->type = std::move(cl.getType());
        this->setAddr(std::move(cl.getAddres())); 
        this->set(std::move(cl.getName()));
        this->set(std::move(cl.getNumberDoc()));
        return *this;
    }

    bool operator==(const Client& cl) override {
        if(typeid(*this) != typeid(cl)) return false;
        auto&& copy = static_cast<const UrClient&>(cl);
        return this->getAddres() == copy.getAddres() && 
                this->type == copy.getType() &&
                this->getNumberDoc() == copy.getNumberDoc();
    }

    bool operator>(const Client& cl) override{
        if(typeid(*this) != typeid(cl)) return typeid(*this).before(typeid(cl));
        auto&& copy = static_cast<const UrClient&>(cl);
        return this->getNumberDoc() > copy.getNumberDoc();
    }

    bool operator<(const Client& cl) override {
        if (typeid(*this) != typeid(cl)) return typeid(*this).before(typeid(cl));
        auto&& copy = static_cast<const UrClient&>(cl);
        return this->getNumberDoc() < copy.getNumberDoc();
    }
};

