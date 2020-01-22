/*
** EPITECH PROJECT, 2020
** zia API
** File description:
** Overlay interface
*/

#ifndef IOVERLAY_HPP_
#define IOVERLAY_HPP_


namespace Zia
{

	//temporary, until propoer HTTP message classes are defined
	using HTTPRequest = int;
	using HTTPResponse = int;

	constexpr auto	CreateOverlaySymbol = "CreateOverlay";

	class IOverlay {
		public:

			virtual ~IOverlay() = default;

			virtual HTTPRequest		onRequest(HTTPRequest &&request) = 0;
			virtual HTTPResponse	onResponse(HTTPResponse &&request) = 0;
	};

} // namespace Zia

#endif /* !IOVERLAY_HPP_ */
