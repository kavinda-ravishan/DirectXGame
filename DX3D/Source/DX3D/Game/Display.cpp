#include "DX3D/Game/Display.h"
#include "DX3D/Graphics/GraphicsDevice.h"

dx3d::Display::Display(const DisplayDesc& desc) : Window(desc.window) {

	DX3DLogInfo("Initializing Display");

	_swap_chain = desc.graphics_device.CreateSwapChain({ _win_handle, _win_size });
	
}
