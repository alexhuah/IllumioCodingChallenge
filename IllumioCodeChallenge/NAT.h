#pragma once
#include <string>;

#ifndef NAT_H
#define NAT_H

class NAT
{
private:
	std::string ip;
	std::string port;

public:
	NAT(std::string, std::string);
	const std::string& getIp() const;
	void setIp(std::string);
	const std::string& getPort() const;
	void setPort(std::string);
	bool operator<(const NAT& second) const;
};
#endif