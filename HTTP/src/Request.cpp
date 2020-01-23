/*
** EPITECH PROJECT, 2020
** EPITECH_Zia_API_Candidate
** File description:
** Request
*/

#include "Request.hpp"

namespace HTTP
{

	Request::Request(Method method, const std::string &URL):
		_method(method),
		_URL(URL)
	{}

	Request::Request(Method method, const std::string &URL, HeaderSection &&headers):
		Request(method, URL)
	{
		Headers = headers;
		updateStartLine();
	}

	Request::Request(Method method, const std::string &URL, const std::string &body):
		Request(method, URL)
	{
		Body = body;
		updateStartLine();
	}

	Request::Request(Method method, const std::string &URL, HeaderSection &&headers, const std::string &body):
		Request(method, URL, std::forward<HeaderSection>(headers))
	{
		Body = body;
		updateStartLine();
	}

	void	Request::setMethod(Method method)
	{
		_method = method;
		updateStartLine();
	}

	void	Request::updateStartLine()
	{
		StartLine = MethodToken[_method] + _URL + "HTTP/1.1";
	}

	void				Request::setURL(const std::string &url)
	{
		_URL = url;
		updateStartLine();
	}

	const std::string	&Request::getURL() const
	{
		return _URL;
	}

} // namespace HTTP

