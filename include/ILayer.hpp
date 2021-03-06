/*
** EPITECH PROJECT, 2020
** zia api
** File description:
** Layer interface
*/

#ifndef ILAYER_HPP_
#define ILAYER_HPP_

// #include <optional>
#include <memory>
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
	///@brief Symbol used as Layer factory-destructor in module loading
	///
	///
	constexpr auto	DestroyLayerSymbol = "DestroyLayer";

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
			///@return std::unique_ptr<HTTPResponse> Optional Response, stops layer traversal if returned non-null
			///
			virtual std::unique_ptr<HTTPResponse>	onRequest(const HTTPRequest &request) = 0;
	};

} // namespace Zia

#endif /* !ILAYER_HPP_ */
