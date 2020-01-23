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
	///
	///@brief Layer module handle abstraction
	///
	/// Delegates handling to the ILayer object of a module's Layer factory
	///
	class Layer : public ILayer {
	public:

		///
		///@brief Construct a new Layer object
		///
		///@param path Path to the module
		///
		Layer(const std::string &path);

		///
		///@brief Handes a request
		///
		/// Delagates handling to the module's Layer
		///
		///@param request Request to be handled
		///@return std::optional<HTTPResponse> Optional Response, stops layer traversal if returned
		///
		virtual std::optional<HTTPResponse>	onRequest(const HTTPRequest &request) override;

		///
		///@brief Get the internal ILayer object from the module
		///
		///
		ILayer				&getHandle();

		///
		///@brief Get the internal ILayer object from the module
		///
		///
		const ILayer		&getHandle() const;

		///
		///@brief Get the module's Lib object
		///
		///
		Plug::DynLib		&getLib();

		///
		///@brief Get the module's Lib object
		///
		///
		const Plug::DynLib	&getLib() const;

	private:

		Plug::DynLib				_lib;
		std::unique_ptr<ILayer>		_layer;
	};

} // namespace Zia

#endif /* !LAYER_HPP_ */
