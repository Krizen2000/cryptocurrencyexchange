#ifndef USERDATA_HPP
#define USERDATA_HPP

#include<string>

class UserData {

public:

    const std::string getToken() const {return m_token;}
    const void setToken(const std::string& token) {m_token = token;}

    const bool tokenExist() const {return m_token.empty();}

private:
    std::string m_token;

};

#endif // USERDATA_HPP
