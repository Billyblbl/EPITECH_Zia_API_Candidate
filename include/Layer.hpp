/*
** EPITECH PROJECT, 2020
** layers loaders
** File description:
** Layers
*/

#ifndef LAYER_HPP_
#define LAYER_HPP_

#include <memory>
#include <string>
#include "ILayer.hpp"
#include "DynLib.hpp"

namespace Zia
{
	class Layer : public ILayer {
	public:
		Layer(const std::string &path);

		virtual std::optional<HTTPResponse>	onRequest(const HTTPRequest &request) override;

		ILayer				&getHandle();
		const ILayer		&getHandle() const;

		Plug::DynLib		&getLib();
		const Plug::DynLib	&getLib() const;

	private:

		Plug::DynLib				_lib;
		std::unique_ptr<ILayer>		_layer;
	};

} // namespace Zia

#endif /* !LAYER_HPP_ */
