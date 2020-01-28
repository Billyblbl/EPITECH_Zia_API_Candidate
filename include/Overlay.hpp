/*
** EPITECH PROJECT, 2020
** EPITECH_Zia_API_Candidate
** File description:
** Overlay
*/

#ifndef OVERLAY_HPP_
#define OVERLAY_HPP_

#include <memory>
#include <string>
#include "IOverlay.hpp"
#include "DynLib.hpp"

namespace Zia
{

	///
	///@brief Overlay module handle abstraction
	///
	/// Delagates tranformations to the IOVerlay object of a module's Overlay factory
	///
	class Overlay : public IOverlay {
	public:

		///
		///@brief Construct a new Overlay object
		///
		///@param path to the module
		///
		Overlay(const std::string &path);

		///
		///@brief Transforms a request
		///
		/// Delagates transformation to the module's Overlay
		///
		///@param request Incoming request
		///@return HTTPRequest Transformed request
		///
		virtual HTTPRequest		onRequest(HTTPRequest &&request) override;

		///
		///@brief Transforms a response
		///
		/// Delagates transformation to the module's Overlay
		///
		///@param response Outgoing response
		///@return HTTPResponse Transformed response
		///
		virtual HTTPResponse	onResponse(HTTPResponse &&response) override;

		///
		///@brief Get the internal IOverlay object from the module
		///
		///
		IOverlay				&getHandle();

		///
		///@brief Get the internal IOverlay object from the module
		///
		///
		const IOverlay			&getHandle() const;

		///
		///@brief Get the module's Lib object
		///
		///
		Plug::DynLib			&getLib();

		///
		///@brief Get the module's Lib object
		///
		///
		const Plug::DynLib		&getLib() const;

	private:

		using OverlayHandle = std::unique_ptr<IOverlay, std::function<void(IOverlay *)>>;

		Plug::DynLib	_lib;
		OverlayHandle	_layer;

	};

} // namespace Zia


#endif /* !OVERLAY_HPP_ */

