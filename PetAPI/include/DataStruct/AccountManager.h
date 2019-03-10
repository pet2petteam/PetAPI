#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include "PetAPI_global.h"

namespace PetAPI {

class PETAPI AccountManager {
	
	std::string m_login;
	std::string m_password;
	std::string m_email;
	
public:
	
	AccountManager();
	AccountManager(const AccountManager & manager) = delete;
	~AccountManager() = default;
	
	bool setLogin(const std::string & login);
	bool setPassword(const std::string & password);
	bool setEmail(const std::string & email);
	
	const std::string & getLogin() const;
	const std::string & getPassword() const;
	const std::string & getEmail() const;
	
	bool isRegistered() const;
	bool registerThis() const;
	
};

}

#endif // ACCOUNTMANAGER_H
