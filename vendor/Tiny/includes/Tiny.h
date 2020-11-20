// Copyright spil3141, Inc. All Rights Reserved.

#pragma once

/*----------------------------------------------------------------------------
	Tiny Engine Core includes.
----------------------------------------------------------------------------*/
#include "Tiny/Core/Application.h"
#include "Tiny/Core/Timestep.h"
#include "Tiny/Core/Log.h"
//#include "Tiny/Core/Core.h"

//ImGui
#include "Tiny/ImGui/ImGuiLayer.h"

//Renderer
#include "Tiny/Renderer/RenderCommand.h"
#include "Tiny/Renderer/Texture.h"
#include "Tiny/Renderer/Framebuffer.h"
#include "Tiny/Renderer/Shader.h"
#include "Tiny/Renderer/Camera/OrthoCameraController.h"
#include "Tiny/Renderer/Renderer2D.h"


//Events
#include "Tiny/Events/KeyEvent.h"
#include "Tiny/Events/Input.h"

// Utilities
#include "Tiny/Utils/Random.h"

/*----------------------------------------------------------------------------
	Temporary includes for Debugging
----------------------------------------------------------------------------*/

//TEMPORARY HACK FOR CUBE PROJECT
//#include "Platform/OpenGL/ShaderLoader.h"
//#include "Platform/OpenGL/OpenGLTexture.h"
//#include "Tiny/Renderer/Camera/PerspectiveCameraController.h"
#include "Tiny/Renderer/Renderer3D.h"
#include "Tiny/Renderer/Objects/Actor.h"
#include "Tiny/Renderer/Mesh.h"
#include "Tiny/Scene/DebugEntity.h"
#include "Tiny/Physics/DebugPhysics.h"
#include "Tiny/Network/DebugASIO.h"
#include "Tiny/Network/olc_net.h"

