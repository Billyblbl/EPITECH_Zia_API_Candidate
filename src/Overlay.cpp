/*
** EPITECH PROJECT, 2020
** EPITECH_Zia_API_Candidate
** File description:
** Layers
*/

#include "Overlay.hpp"
#include "DynLib.hpp"

namespace Zia
{

	Overlay::Overlay(const std::string &path):
		_lib(path),
		_layer(_lib.call<IOverlay *()>(CreateOverlaySymbol), [this](IOverlay *overlay){
			try {
				_lib.call<void(IOverlay *)>(DestroyOverlaySymbol, overlay);
			} catch(const std::exception& e) {
				std::cerr << e.what() << '\n';
			}
		})
	{
		if (!_layer)
			throw std::runtime_error(std::string(__func__) + " : Failed to create layer from " + path);
	}

	std::unique_ptr<HTTPRequest>	Overlay::onRequest(std::unique_ptr<HTTPRequest> &&request)
	{
		return _layer->onRequest(std::forward<std::unique_ptr<HTTPRequest>>(request));
	}

	std::unique_ptr<HTTPResponse>	Overlay::onResponse(std::unique_ptr<HTTPResponse> &&response)
	{
		return _layer->onResponse(std::forward<std::unique_ptr<HTTPResponse>>(response));
	}

	IOverlay		&Overlay::getHandle()
	{
		return *_layer;
	}

	const IOverlay	&Overlay::getHandle() const
	{
		return *_layer;
	}

	Plug::DynLib	&Overlay::getLib()
	{
		return _lib;
	}

	const Plug::DynLib	&Overlay::getLib() const
	{
		return _lib;
	}

} // namespace Zia
