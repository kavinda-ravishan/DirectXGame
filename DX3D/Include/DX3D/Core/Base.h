#pragma once
#include "DX3D/Core/Common.h"

namespace dx3d {

	class Base {
	public:
		explicit Base(const BaseDesc& desc);
		virtual ~Base();

		virtual Logger& GetLogger() const noexcept final;

	protected:
		Base(const Base&) = delete; // delete copy constructor
		Base(Base&&) = delete; // delete move constructor
		Base& operator=(const Base&) = delete; // delete copy assignment operator
		Base& operator=(Base&&) = delete; // delete move assignment operator

	protected:
		Logger& _logger;
	};

} // namespace dx3d
