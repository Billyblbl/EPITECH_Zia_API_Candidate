/*
** EPITECH PROJECT, 2020
** zia API
** File description:
** Overlay interface
*/

#ifndef IOVERLAY_HPP_
#define IOVERLAY_HPP_

//temporary, until propoer HTTP message classes are defined
using HTTPRequest = int;
using HTTPResponse = int;

namespace Zia
{
	class IOverlay {
		public:

			virtual ~IOverlay() = default;

			virtual HTTPRequest		onRequest(HTTPRequest &&request) = 0;
			virtual HTTPResponse	onResponse(HTTPResponse &&request) = 0;
	};

} // namespace Zia

#endif /* !IOVERLAY_HPP_ */
