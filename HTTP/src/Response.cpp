/*
** EPITECH PROJECT, 2020
** EPITECH_Zia_API_Candidate
** File description:
** Response
*/

#include "Response.hpp"

namespace HTTP
{

	Response::Response(Code status, const std::string &reason):
		_status(status),
		_reason(reason)
	{}

	Response::Response(Code status, const std::string &reason, HeaderSection &&headers):
		Response(status, reason)
	{
		Headers = headers;
		updateStartLine();
	}

	Response::Response(Code status, const std::string &reason, const std::string &body):
		Response(status, reason)
	{
		Body = body;
		updateStartLine();
	}

	Response::Response(Code status, const std::string &reason, HeaderSection &&headers, const std::string &body):
		Response(status, reason, std::forward<HeaderSection>(headers))
	{
		Body = body;
		updateStartLine();
	}

	void	Response::updateStartLine()
	{
		StartLine = "HTTP/1.1" + _status + _reason;
	}

	void	Response::setStatus(Code status)
	{
		_status = status;
		updateStartLine();
	}

	void	Response::setReason(const std::string &reason)
	{
		_reason = reason;
		updateStartLine();
	}

	Response::Code	Response::getStatus() const
	{
		return _status;
	}

	const std::string	&Response::getReason() const
	{
		return _reason;
	}

} // namespace HTTP
