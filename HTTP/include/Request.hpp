/*
** EPITECH PROJECT, 2020
** EPITECH_Zia_API_Candidate
** File description:
** Request
*/

#ifndef REQUEST_HPP_
#define REQUEST_HPP_

#include "Message.hpp"

#define ENUMSTR(e) [e]=#e

namespace HTTP
{

	class Request : public Message {
		public:

			enum Method : size_t {
				GET = 0,
				HEAD,
				POST,
				PUT,
				DELETE,
				CONNECT,
				OPTIONS,
				TRACE,
				SIZE = TRACE + 1
			};

			const char	*MethodToken[SIZE] = {
				ENUMSTR(GET),
				ENUMSTR(HEAD),
				ENUMSTR(POST),
				ENUMSTR(PUT),
				ENUMSTR(DELETE),
				ENUMSTR(CONNECT),
				ENUMSTR(OPTIONS),
				ENUMSTR(TRACE),
			};

			Request() = default;

			Request(Method method, const std::string &URL);
			Request(Method method, const std::string &URL, HeaderSection &&headers);
			Request(Method method, const std::string &URL, const std::string &body);
			Request(Method method, const std::string &URL, HeaderSection &&headers, const std::string &body);

			virtual ~Request() = default;

			void	setMethod(Method method);
			Method	getMethod() const;

			void				setURL(const std::string &url);
			const std::string	&getURL() const;

		protected:
		private:

			void	updateStartLine();

			Method		_method;
			std::string	_URL;
	};

} // namespace HTTP


#endif /* !REQUEST_HPP_ */

