/*
** EPITECH PROJECT, 2020
** zia api
** File description:
** Layer interface
*/

#ifndef ILAYER_HPP_
#define ILAYER_HPP_

#include <optional>
#include "Request.hpp"
#include "Response.hpp"

namespace Zia
{

	using HTTPRequest = HTTP::Request;
	using HTTPResponse = HTTP::Response;

	///
	///@brief Symbol used as Layer factory in module loading
	///
	///
	constexpr auto	CreateLayerSymbol = "CreateLayer";

	///
	///@brief Layer interface
	///
	/// Layers are responsible for handling of requests. the request will be passed down
	/// to the next layer the layer do not return a response after handling the request
	///
	class ILayer {
		public:

			///
			///@brief Destroy the ILayer object
			///
			///
			virtual ~ILayer() = default;

			///
			///@brief Handles a request, user implementation point
			///
			///@param request Request to be handled
			///@return std::optional<HTTPResponse> Optional Response, stops layer traversal if returned
			///
			virtual std::optional<HTTPResponse>	onRequest(const HTTPRequest &request) = 0;
	};

} // namespace Zia

#endif /* !ILAYER_HPP_ */
