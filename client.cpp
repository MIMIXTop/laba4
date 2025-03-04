#include "client.hpp"
#include <iostream>

std::string Client::getName(){
    return this->m_name;
}

std::string Client::getAddres() {
    return this->m_addres;
}

int Client::getNumberDoc(){
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

void Client::printClient() {
    std::cout << "Client name: " << m_name << std::endl; 
    std::cout << "Client addr: " << m_addres << std::endl; 
    std::cout << "Client document number: " << m_numberDoc << std::endl; 
}