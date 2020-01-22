/*
** EPITECH PROJECT, 2020
** zia api
** File description:
** Layer interface
*/

#ifndef ILAYER_HPP_
#define ILAYER_HPP_

#include <optional>


namespace Zia
{

	//temporary, until propoer HTTP message classes are defined
	using HTTPRequest = int;
	using HTTPResponse = int;

	constexpr auto	CreateLayerSymbol = "CreateLayer";

	class ILayer {
		public:

			virtual ~ILayer() = default;

			virtual std::optional<HTTPResponse>	onRequest(const HTTPRequest &request) = 0;
	};

} // namespace Zia

#endif /* !ILAYER_HPP_ */
