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
	class Overlay : public IOverlay {
	public:
		Overlay(const std::string &path);

		virtual HTTPRequest		onRequest(HTTPRequest &&request) override;
		virtual HTTPResponse	onResponse(HTTPResponse &&response) override;

		IOverlay				&getHandle();
		const IOverlay			&getHandle() const;

		Plug::DynLib			&getLib();
		const Plug::DynLib		&getLib() const;

	private:

		Plug::DynLib				_lib;
		std::unique_ptr<IOverlay>	_layer;

	};

} // namespace Zia


#endif /* !OVERLAY_HPP_ */

