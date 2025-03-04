#ifndef JOURNAL_HPP
#define JOURNAL_HPP

#include <list> 
#include <string>

#include "client.hpp"

enum compFields {CM_NAME = 1, CM_TEL, CM_CLIENT};

class Journal
{
private:
    std::string m_telefonNumber;
    std::string m_companiName;
    std::list<Client> m_clients {};
public:
    void print();

    std::string getTelefonNumber();
    std::string getCompaniName();
    std::list<Client> getClients();
    int getSizeListOfClient();

    void modClient(int clNum, clientFilds field);
    void modCompami(compFields field);

    void setTelefonNumber(std::string tel);
    void setCompaniName(std::string name);
    void setAllFields(std::string compName, std::string tel, std::list<Client>);
    
    void addClient(Client cl);

    void removClient(int index);
    void removClient();
};

#endif //JOURNAL_HPP