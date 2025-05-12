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

    std::string getGender() const {
        return gender;
    }

    void setGender(std::string s){
        gender = s;
    }

    void printClient(std::ostream& os)const override{
        os << "IndClient name: " << this->getName() << std::endl; 
        os << "IndClient addr: " << getAddres() << std::endl; 
        os << "IndClient document number: " << getNumberDoc() << std::endl; 
        os << "IndClient gender: " << gender << std::endl; 
    }

    IndClient* clone() override {
        return new IndClient(*this);
    }

    IndClient& operator=(IndClient& cl) {
        this->gender = cl.gender;
        this->setAddr(cl.getAddres()); 
        this->set(cl.getName());
        this->set(cl.getNumberDoc());
        return *this;
    }

    IndClient& operator=(IndClient&& cl) {
        this->gender = std::move(cl.gender);
        this->setAddr(std::move(cl.getAddres())); 
        this->set(std::move(cl.getName()));
        this->set(std::move(cl.getNumberDoc()));
        return *this;
    }

    bool operator==(const Client& cl) override {
        if(typeid(*this) != typeid(cl)) return false;
        auto&& copy = static_cast<const IndClient&>(cl);
        return this->getAddres() == copy.getAddres() && 
                this->gender == copy.getGender() &&
                this->getNumberDoc() == copy.getNumberDoc();
    }

    bool operator>(const Client& cl) override{
        if(typeid(*this) != typeid(cl)) return typeid(*this).before(typeid(cl));
        auto&& copy = static_cast<const IndClient&>(cl);
        return this->getNumberDoc() > copy.getNumberDoc();
    }

    bool operator<(const Client& cl) override {
        if (typeid(*this) != typeid(cl)) return typeid(*this).before(typeid(cl));
        auto&& copy = static_cast<const IndClient&>(cl);
        return this->getNumberDoc() < copy.getNumberDoc();
    }
};

