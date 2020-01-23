/*
** EPITECH PROJECT, 2020
** EPITECH_Zia_API_Candidate
** File description:
** Response
*/

#ifndef RESPONSE_HPP_
#define RESPONSE_HPP_

#include "Message.hpp"
namespace HTTP
{

	class Response : public Message {
		public:

			using Code = uint8_t;

			Response() = default;

			Response(Code status, const std::string &reason);
			Response(Code status, const std::string &reason, HeaderSection &&headers);
			Response(Code status, const std::string &reason, const std::string &body);
			Response(Code status, const std::string &reason, HeaderSection &&headers, const std::string &body);

			void	setStatus(Code status);
			Code	getStatus() const;

			void				setReason(const std::string &reason);
			const std::string	&getReason() const;

		protected:
		private:

			void	updateStartLine();

			Code		_status;
			std::string	_reason;
	};

} // namespace HTTP

#endif /* !RESPONSE_HPP_ */
