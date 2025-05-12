#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <iostream>

enum clientFilds {CL_NAME = 1, CL_ADDR, CL_NUM_DOC, CL_TYPE, CL_GEN};

class Client
{
private:
    std::string m_name;  
    std::string m_addres;
    int m_numberDoc;
public:

    Client() : m_name("No name"), m_addres("st.Mira 1"), m_numberDoc(1) {
        std::cout << "Default constructor Client" << std::endl;
    };

    Client(std::string name, std::string addres, int numberDoc) : m_name(name), m_addres(addres), m_numberDoc(numberDoc){
        std::cout << "Constructor Client" << std::endl;
    };

    Client(const Client &cl) : m_name(cl.m_name), m_addres(cl.m_addres), m_numberDoc(cl.m_numberDoc){
        std::cout << "Copy constructor Client" << std::endl;
    }

    virtual ~Client() = default;

    Client(Client&& cl) : m_name(std::move(cl.m_name)), m_addres(std::move(cl.m_addres)), m_numberDoc(std::move(cl.m_numberDoc)) {
        cl.m_name.clear();
        cl.m_addres.clear();
        cl.m_numberDoc = 0;

        std::cout << "Move constructor Client" << std::endl;
    }

    Client& operator=(const Client& cl) = default;
    Client& operator=(Client&& cl) noexcept = default;


    std::string getName() const;
    std::string getAddres() const;
    int getNumberDoc() const;

    void set(std::string); // m_name
    void setAddr(std::string);// m_addres
    void set(int);// m_numberDoc
    void set(std::string, std::string, int);// all

    virtual void printClient(std::ostream& os) const = 0;
    virtual Client* clone() = 0;

    virtual bool operator==(const Client& cl) = 0;
    virtual bool operator<(const Client& cl) = 0;
    virtual bool operator>(const Client& cl) = 0;

    
};

std::ostream& operator<<(std::ostream& os,const Client& cl);

#endif //CLIENT_HPP