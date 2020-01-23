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

	class Message {
		public:

			virtual ~Message() = default;

			using HeaderSection = std::map<std::string, std::string>;

			HeaderSection	Headers;
			std::string		Body;

			const std::string &getStartLine();

		protected:
			Message() = default;

			std::string		StartLine;
	};

} // namespace HTTP



#endif /* !MESSAGE_HPP_ */
