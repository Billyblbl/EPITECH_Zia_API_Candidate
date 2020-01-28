/*
** EPITECH PROJECT, 2020
** ZIA API http
** File description:
** Message
*/

#ifndef MESSAGE_HPP_
#define MESSAGE_HPP_

#include <string>
#include <map>

namespace HTTP
{

	///
	///@brief HTTP Base message class
	///
	///
	class Message {
		public:

			///
			///@brief Destroy the Message
			///
			///
			virtual ~Message() = default;

			using HeaderSection = std::map<std::string, std::string>;

			///
			///@brief Headers of the message
			///
			///
			HeaderSection	Headers;

			///
			///@brief Body of the message
			///
			///
			std::string		Body;

			///
			///@brief Get the Start Line of the message
			///
			///
			const std::string &getStartLine();

		protected:
			Message() = default;

			std::string		StartLine;
	};

} // namespace HTTP



#endif /* !MESSAGE_HPP_ */
