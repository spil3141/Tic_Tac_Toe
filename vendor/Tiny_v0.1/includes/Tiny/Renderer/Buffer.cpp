#include "Tpch.h"
#include "Buffer.h"

#include "RendererAPI.h"

//OpenGL Renderer
#include "Tiny/Platform/OpenGL/OpenGLBuffer.h"

namespace Tiny {


	Ref<VertexBuffer> VertexBuffer::Create(const void* vertices, uint32_t size)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:   T_CORE_ASSERT(false, "RendererAPI::API::None is not implemented"); break;
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLVertexBuffer>(vertices,size); break;
		}

		T_CORE_ASSERT(false, "VertexBuffer: No Valid Renderer was selected!");
		return nullptr;
	}

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t count) 
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:   T_CORE_ASSERT(false, "RendererAPI::API::None is not implemented"); break;
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLIndexBuffer>(indices,count); break;
		}

		T_CORE_ASSERT(false, "VertexBuffer: No Valid Renderer was selected!");
		return nullptr;
	}

}