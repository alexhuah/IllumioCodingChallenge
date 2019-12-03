#include "NAT.h";
#include <iostream>

using namespace std;


NAT::NAT(std::string temp1, std::string temp2)
{
	ip = temp1;
	port = temp2;
}
const std::string& NAT::getIp() const
{
	return ip;
}
void NAT::setIp(std::string temp)
{
	ip = temp;
}
const std::string& NAT::getPort() const
{
	return port;
}
void NAT::setPort(std::string temp)
{
	port = temp;
}

bool NAT::operator<(const NAT& second) const
{
	if (second.getIp() == "*")
	{
		if (port >= second.getPort())
		{
			return false;
		}
		return port < second.getPort();
	}
	else if ((ip == second.getIp()) || (ip == "*"))
	{
		if (port == "*")
		{
			return false;
		}
		return port < second.getPort();
	}
	return ip < second.getIp();
}