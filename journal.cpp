#include "journal.hpp"
#include <stdexcept>
#include <iostream>

#include "client.hpp"
#include "function.hpp"
#include "UrClient.hpp"
#include "IndClient.hpp"

std::string Journal::getTelefonNumber(){
    return m_telefonNumber;
}

std::string Journal::getCompaniName(){
    return m_companiName;
}

std::list<Client*> Journal::getClients(){
    return m_clients;
}

int Journal::getSizeListOfClient(){
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
    /*if (!m_clients.empty()) {
        m_clients.push_back(cl); 
    } else {
        m_clients.resize(1);
        m_clients.begin()->set(cl.getName(), cl.getAddres(), cl.getNumberDoc());
    }*/
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

void Journal::print(){
    std::cout << "Compani name: " << m_companiName << std::endl;
    std::cout << "Compani tel: " << m_telefonNumber << std::endl;
    int i = 1;
    for (auto &&client : m_clients) {
        std::cout << "----------------[ "<< i++ <<" ]-----------------" << std::endl;
        client->printClient();
    }
    
}

void Journal::createCopyList(Client& cl, int number){
    for(int i = 0; i < number;++i){
        m_clients.emplace_back(new Client(cl));
    }
}