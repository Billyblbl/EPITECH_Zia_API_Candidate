/*
** EPITECH PROJECT, 2020
** EPITECH_Zia_API_Candidate
** File description:
** Request
*/

#ifndef REQUEST_HPP_
#define REQUEST_HPP_

#include "Message.hpp"


namespace HTTP
{

	///
	///@brief HTTP Request message class
	///
	/// Automaticly set its Start Line according to its Method & URL
	///
	class Request : public Message {
		public:

			///
			///@brief HTTP Method enum
			///
			///
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

			///
			///@brief HTTP Method string representation tokens
			///
			///
			const char	*MethodToken[SIZE] = {
				"GET",
				"HEAD",
				"POST",
				"PUT",
				"DELETE",
				"CONNECT",
				"OPTIONS",
				"TRACE",
			};

	//#define ENUMSTR(e) [e]=#e

	//		const char	*MethodToken[SIZE] = {
	//			ENUMSTR(GET),
	//			ENUMSTR(HEAD),
	//			ENUMSTR(POST),
	//			ENUMSTR(PUT),
	//			ENUMSTR(DELETE),
	//			ENUMSTR(CONNECT),
	//			ENUMSTR(OPTIONS),
	//			ENUMSTR(TRACE),
	//		};

			///
			///@brief Construct a new Request
			///
			/// Default constructor
			///
			Request() = default;

			///
			///@brief Construct a new Request
			///
			///@param method HTTP Method of the request
			///@param URL URL of the request
			///
			Request(Method method, const std::string &URL);

			///
			///@brief Construct a new Request
			///
			///@param method HTTP Method of the request
			///@param URL URL of the request
			///@param headers Headers included in the request
			///
			Request(Method method, const std::string &URL, HeaderSection &&headers);

			///
			///@brief Construct a new Request
			///
			///@param method HTTP Method of the request
			///@param URL URL of the request
			///@param body Text body of the request
			///
			Request(Method method, const std::string &URL, const std::string &body);

			///
			///@brief Construct a new Request
			///
			///@param method HTTP Method of the request
			///@param URL URL of the request
			///@param headers Headers included in the request
			///@param body Text body of the request
			///
			Request(Method method, const std::string &URL, HeaderSection &&headers, const std::string &body);

			///
			///@brief Destroy the Request
			///
			///
			virtual ~Request() = default;

			///
			///@brief Set the Method to method
			///
			///
			void	setMethod(Method method);

			///
			///@brief Get the Method
			///
			///
			Method	getMethod() const;

			///
			///@brief Set the URL to url
			///
			///
			void				setURL(const std::string &url);

			///
			///@brief Get the URL
			///
			///
			const std::string	&getURL() const;

		protected:
		private:

			void	updateStartLine();

			Method		_method;
			std::string	_URL;
	};

} // namespace HTTP


#endif /* !REQUEST_HPP_ */

