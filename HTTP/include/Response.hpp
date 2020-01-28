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

	///
	///@brief HTTP Response message class
	///
	/// Automaticly set its Start Line according to its status code & reason
	///
	class Response : public Message {
		public:

			///
			///@brief Status code type
			///
			///
			using Code = uint8_t;

			///
			///@brief Construct a new Response
			///
			/// Default constructor
			///
			Response() = default;

			///
			///@brief Construct a new Response
			///
			///@param status Status code of the response
			///@param reason Reason for the status of the response
			///
			Response(Code status, const std::string &reason);

			///
			///@brief Construct a new Response
			///
			///@param status Status code of the response
			///@param reason Reason for the status of the response
			///@param headers Headers included in the response
			///
			Response(Code status, const std::string &reason, HeaderSection &&headers);

			///
			///@brief Construct a new Response
			///
			///@param status Status code of the response
			///@param reason Reason for the status of the response
			///@param body Response text body
			///
			Response(Code status, const std::string &reason, const std::string &body);

			///
			///@brief Construct a new Response
			///
			///@param status Status code of the response
			///@param reason Reason for the status of the response
			///@param headers Headers included in the response
			///@param body Response text body
			///
			Response(Code status, const std::string &reason, HeaderSection &&headers, const std::string &body);

			///
			///@brief Set the Status to status
			///
			///
			void	setStatus(Code status);

			///
			///@brief Get the Status
			///
			///
			Code	getStatus() const;

			///
			///@brief Set the Reason to reason
			///
			///
			void				setReason(const std::string &reason);

			///
			///@brief Get the Reason
			///
			///
			const std::string	&getReason() const;

		protected:
		private:

			void	updateStartLine();

			Code		_status;
			std::string	_reason;
	};

} // namespace HTTP

#endif /* !RESPONSE_HPP_ */
