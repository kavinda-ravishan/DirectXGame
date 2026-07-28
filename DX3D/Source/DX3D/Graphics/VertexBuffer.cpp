#include <DX3D/Graphics/VertexBuffer.h>

dx3d::VertexBuffer::VertexBuffer(const VertexBufferDesc& desc, const GraphicsResourceDesc& g_desc) 
	: GraphicsResource(g_desc), _vertex_size(desc.vertex_size), _vertex_list_size(desc.vertex_list_size){

	if (!desc.vertex_list) DX3DLogThrowInvalidArg("No vertex list provided");
	if (!desc.vertex_list_size) DX3DLogThrowInvalidArg("Vertex list size must be non-zero");
	if (!desc.vertex_size) DX3DLogThrowInvalidArg("Vertex size must be non-zero");

	D3D11_BUFFER_DESC buffer_desc{};
	buffer_desc.ByteWidth = desc.vertex_list_size * desc.vertex_size;
	buffer_desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	D3D11_SUBRESOURCE_DATA init_data{};
	init_data.pSysMem = desc.vertex_list;

	DX3DGraphicsLogThrowOnFail(
		_device.CreateBuffer(&buffer_desc, &init_data, &_buffer),
		"Failed to create vertex buffer"
	);
}

dx3d::ui32 dx3d::VertexBuffer::GetVertexListSize() const noexcept {
	return _vertex_list_size;
}
