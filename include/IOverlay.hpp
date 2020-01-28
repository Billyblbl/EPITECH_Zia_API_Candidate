/*
** EPITECH PROJECT, 2020
** zia API
** File description:
** Overlay interface
*/

#ifndef IOVERLAY_HPP_
#define IOVERLAY_HPP_

#include "Request.hpp"
#include "Response.hpp"

namespace Zia
{

	using HTTPRequest = HTTP::Request;
	using HTTPResponse = HTTP::Response;

	///
	///@brief Symbol used as Overlay factory in module loading
	///
	///
	constexpr auto	CreateOverlaySymbol = "CreateOverlay";

	///
	///@brief Symbol used as Overlay factory-destructor in module loading
	///
	///
	constexpr auto	DestroyOverlaySymbol = "DestroyOverlay";

	///
	///@brief Overlay interface
	///
	/// Overlays tranforms HTTP requests & reponses before they are passed down
	/// to the next layer/overlay
	///
	class IOverlay {
		public:

			///
			///@brief Destroy the IOverlay object
			///
			///
			virtual ~IOverlay() = default;

			///
			///@brief Transforms a request
			///
			///@param request Incoming request
			///@return HTTPRequest Transformed request
			///
			virtual HTTPRequest		onRequest(HTTPRequest &&request) = 0;

			///
			///@brief Transforms a response
			///
			///@param response Outgoing response
			///@return HTTPResponse Transformed response
			///
			virtual HTTPResponse	onResponse(HTTPResponse &&response) = 0;
	};

} // namespace Zia

#endif /* !IOVERLAY_HPP_ */
