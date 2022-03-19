#ifndef USERDATA_HPP
#define USERDATA_HPP

#include<string>

class UserData {
private:
    std::string m_token;

public:

    const std::string getToken() const {
        return m_token;
    }
    const void setToken(const std::string& token) {
        m_token = token;
    }
    const bool tokenExist() const {
        return m_token.empty();
    }
};

#endif // USERDATA_HPP
