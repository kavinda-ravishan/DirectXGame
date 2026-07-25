#include "DX3D/Core/Base.h"

using namespace dx3d;

dx3d::Base::Base(const BaseDesc& desc) : _logger(desc.logger) {}

dx3d::Base::~Base() {}

Logger& dx3d::Base::GetLogger() const noexcept { return _logger; }
