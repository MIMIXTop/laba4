#include "journal.hpp"
#include <stdexcept>
#include <iostream>

#include "client.hpp"
#include "function.hpp"
#include "UrClient.hpp"
#include "IndClient.hpp"
#include "MyException.hpp"

std::string Journal::getTelefonNumber() const{
    return m_telefonNumber;
}

std::string Journal::getCompaniName() const {
    return m_companiName;
}

std::list<Client*> Journal::getClients() const {
    return m_clients;
}

int Journal::getSizeListOfClient() const {
    return m_clients.size();
}

void Journal::setTelefonNumber(std::string num){
    m_telefonNumber = num;
}

void Journal::setCompaniName(std::string s){
    m_companiName = s;
}

void Journal::setAllFields(std::string compName, std::string tel, std::list<Client*> list){
    m_clients = std::move(list);
    m_companiName = compName;
    m_telefonNumber = tel;
}

void Journal::addClient(Client* cl) {
   m_clients.push_back(cl);
}

void Journal::removClient(){
    for (Client* client : m_clients) {
        delete client;
    }
}

void Journal::removClient(int number){
    auto it = std::next(m_clients.begin(), number);
    delete *it;   
}

void Journal::modClient(int clNum,clientFilds field) {
    auto it = m_clients.begin();
    it = std::next(it, clNum - 1);
    int num;
    std::string s;

    switch (field) 
    {
    case clientFilds::CL_NAME:
        s = test(typeTest::M_NAME, "Entry the client name: ");
        (*it)->set(s);
        break;
    case clientFilds::CL_ADDR:
        s = test(typeTest::M_ADDR, "Entry the addr client: ");
        (*it)->setAddr(s);
        break;
    case clientFilds::CL_NUM_DOC:
        num = std::stoi(test(typeTest::M_INT, "Entry the document number: "));
        (*it)->set(num);
        break;
    case clientFilds::CL_TYPE:
        s = test(typeTest::M_NAME, "Entry type of UrClient: ");
        dynamic_cast<UrClient*>(*it)->setType(s);
        break;
    case clientFilds::CL_GEN:
        s = test(typeTest::M_NAME, "Entry gender of IndClient: ");
        dynamic_cast<IndClient*>(*it)->setGender(s);
        break;
    }
}

void Journal::modCompami(compFields field){

    if(field == compFields::CM_CLIENT){
        throw std::invalid_argument("This method does not modify clients");
    }
    std::string s;
    int num;

    switch (field)
    {
    case compFields::CM_NAME:
        s = test(typeTest::M_NAME, "Entry the compani name: ");
        setCompaniName(s);
        break;
    case compFields::CM_TEL:
        s = test(typeTest::M_TEL, "Entry the tel number: ");
        setTelefonNumber(s);
        break;
    default:
        break;
    }
}

void Journal::createCopyList(Client& cl, int number){
    for(int i = 0; i < number;++i){
        m_clients.emplace_back(cl.clone());
    }
}

Journal Journal::operator+ (Client* cl) {
    this->addClient(cl);
    return *this;
}

Journal& Journal::operator++() {
    this->addClient(*this->m_clients.begin());
    return *this;
}

Journal Journal::operator++(int) {
    auto copy = *this;
    this->addClient(*this->m_clients.begin());
    return copy;
}

Client* Journal::operator[] (int counter) {
    if (counter > this->m_clients.size()) {throw std::my_out_of_range("");} //* необходимо в будущем вернуть std::out_of_range

    auto it = this->m_clients.begin();

    std::advance(it, counter);

    return *it;
}

std::ostream& operator<<(std::ostream &os,const Journal& list) {
    os << "Compani name: " << list.getCompaniName() << std::endl;
    os << "Compani tel: " << list.getTelefonNumber() << std::endl;
    int i = 1;
    for (auto &&client : list.getClients()) {
        os << "----------------[ "<< i++ <<" ]-----------------" << std::endl;
        os << client;
    }
    return os;
}

Journal& Journal::operator=(const Journal& jr) {
    this->m_clients = jr.getClients();
    this->m_companiName = jr.getCompaniName();
    this->m_telefonNumber = jr.getTelefonNumber();
    return *this;
}