#include "DataStruct/AccountManager.h"
#include "Utils/RegExValidator.h"

namespace PetAPI {

AccountManager::AccountManager() {
	m_login = "";
	m_password = "";
	m_email = "";
}

bool AccountManager::setLogin(const std::string & login) {
	if (!Utils::RegExValidator::isDataValid(login, Utils::LOGIN_DEF_VALIDATION_PATTERN))
		return false;
	m_login = login;
	return true;
}

bool AccountManager::setPassword(const std::string & password) {
	if (!Utils::RegExValidator::isDataValid(password, Utils::PASSWORD_DEF_VALIDATION_PATTERN))
		return false;
	m_password = password;
	return true;
}

bool AccountManager::setEmail(const std::string & email) {
	if (!Utils::RegExValidator::isDataValid(email, Utils::EMAIL_DEF_VALIDATION_PATTERN))
		return false;
	m_email = email;
	return true;
}

const std::string & AccountManager::getLogin() const { return m_login; }

const std::string & AccountManager::getPassword() const { return m_password; }

const std::string & AccountManager::getEmail() const { return m_email; }

//TODO: It's a stub. When the server is ready i'll write this functions
bool AccountManager::isRegistered() const { return true; }
bool AccountManager::registerThis() const { return true; }

}
