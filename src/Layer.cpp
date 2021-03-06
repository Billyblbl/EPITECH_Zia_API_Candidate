/*
** EPITECH PROJECT, 2020
** EPITECH_Zia_API_Candidate
** File description:
** Layers
*/

#include "Layer.hpp"
#include "DynLib.hpp"

namespace Zia
{

	Layer::Layer(const std::string &path):
		_lib(path),
		_layer(_lib.call<ILayer *()>(CreateLayerSymbol), [this](ILayer *layer){
			try {
				_lib.call<void(ILayer *)>(DestroyLayerSymbol, layer);
			} catch(const std::exception& e) {
				std::cerr << e.what() << '\n';
			}
		})
	{
		if (!_layer)
			throw std::runtime_error(std::string(__func__) + " : Failed to create layer from " + path);
	}

	std::unique_ptr<HTTPResponse>		Layer::onRequest(const HTTPRequest &request)
	{
		return _layer->onRequest(std::forward<const HTTPRequest>(request));
	}

	ILayer				&Layer::getHandle()
	{
		return *_layer;
	}

	const ILayer		&Layer::getHandle() const
	{
		return *_layer;
	}

	Plug::DynLib		&Layer::getLib()
	{
		return _lib;
	}

	const Plug::DynLib	&Layer::getLib() const
	{
		return _lib;
	}

} // namespace Zia
