#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>

enum clientFilds {CL_NAME = 1, CL_ADDR, CL_NUM_DOC};

class Client
{
private:
    std::string m_name = "No name";  
    std::string m_addres = "st.Mira 1";
    int m_numberDoc = 1;
public:
    std::string getName();
    std::string getAddres();
    int getNumberDoc();

    void set(std::string); // m_name
    void setAddr(std::string);// m_addres
    void set(int);// m_numberDoc
    void set(std::string, std::string, int);// all

    void printClient();
};

#endif //CLIENT_HPP