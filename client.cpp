#include "client.hpp"
#include <iostream>

std::string Client::getName() const {
    return this->m_name;
}

std::string Client::getAddres() const {
    return this->m_addres;
}

int Client::getNumberDoc() const {
    return this->m_numberDoc;
}

void Client::set(std::string s){
    m_name = s;
}

void Client::setAddr(std::string s){
    m_addres = s;
}

void Client::set(int num){
    m_numberDoc = num;
}

void Client::set(std::string name,std::string addr,int numDoc){
    m_name = name;
    m_addres = addr;
    m_numberDoc = numDoc;
}

std::ostream& operator<<(std::ostream& os, const Client& cl) {
    cl.printClient(os);
    return os;
}