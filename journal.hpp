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
    std::list<Client*> m_clients {};
public:

    Journal(){
        std::cout << "Default constructor Journal" << std::endl;
    }

    Journal(std::string compName, std::string tel, std::list<Client*> list) : m_companiName(compName), m_telefonNumber(tel), m_clients(list) {
        std::cout << "Constructor Journal" << std::endl;
    };

    Journal(const Journal &jou) : m_companiName(jou.m_companiName), m_telefonNumber(jou.m_telefonNumber), m_clients(jou.m_clients){
        std::cout << "Copy constructor Journal" << std::endl;
    }

    ~Journal(){
        for (auto client : m_clients) {
            delete client; 
        }
        m_clients.clear();
        std::cout << "Destructor Journal" <<std::endl;
    }

    Journal(Journal &&journal) noexcept : m_companiName(journal.m_companiName), m_telefonNumber(journal.m_telefonNumber), m_clients(journal.m_clients){

        journal.m_companiName.clear();
        journal.m_telefonNumber.clear();
        journal.m_clients.clear();

        std::cout << "Move constructor Journal" << std::endl;
    }

    Journal operator+ (Client* cl);
    Journal& operator++();
    Journal operator++(int);
    Client* operator[] (int counter); 

    //особенность С++
    Journal& operator=(const Journal &jor);
    Journal& operator=(Journal &&jor) noexcept = default;

    //void print();

    std::string getTelefonNumber() const;
    std::string getCompaniName() const;
    std::list<Client*> getClients() const;
    int getSizeListOfClient() const;

    void modClient(int clNum, clientFilds field);
    void modCompami(compFields field);

    void setTelefonNumber(std::string tel);
    void setCompaniName(std::string name);
    void setAllFields(std::string compName, std::string tel, std::list<Client*>);
    
    void addClient(Client *cl);

    void createCopyList(Client &cl, int number);

    void removClient(int index);
    void removClient();
};

std::ostream& operator<<(std::ostream &os,const Journal& list);

#endif //JOURNAL_HPP