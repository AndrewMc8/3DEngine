#pragma once

#define REGISTER_CLASS(class) nc::ObjectFactory::Instance().Register<class>(#class);

//systems
#include "Audio/AudioSystem.h"

//core
#include "Core/FileSystem.h"
#include "Core/Timer.h"
#include "Core/Utilities.h"
#include "Core/Json.h"
#include "Core/Serializable.h"

//input
#include "Input/InputSystem.h"

//math
#include "Math/MathTypes.h"
#include "Math/Random.h"
#include "Math/MathUtils.h"
#include "Math/Transform.h"

//graphics
#include "Graphics/Material.h"
#include "Graphics/Program.h"
#include "Graphics/Renderer.h"
#include "Graphics/Shader.h"
#include "Graphics/Texture.h"
#include "Graphics/VertexBuffer.h"
#include "Graphics/VertexIndexBuffer.h"

//objects
#include "Object/Actor.h"
#include "Object/Scene.h"

//components
#include "Components/PhysicsComponent.h"
#include "Components/AudioComponent.h"
#include "Components/GraphicsComponent.h"
#include "Components/CameraComponent.h"
#include "Components/MeshComponent.h"
#include "Components/FreeCameraController.h"

//Framework
#include "Framework/EventSystem.h"
#include "Framework/Singleton.h"
#include "Framework/Factory.h"

//resource
#include "Resource/ResourseSystem.h"

//files
#include "Files/File.h"

#include <vector>
#include <memory>
#include <algorithm>


namespace nc
{
	using ObjectFactory = Singleton<Factory<std::string, Object>>;

	class Engine
	{
	public:
		void Startup();
		void Shutdown();

		void Update();
		void Draw(Renderer* renderer);

		template<typename T>
		T* Get();

	public:
		FrameTimer time;

	private:
		std::vector<std::unique_ptr<System>> systems;
	};

	template<typename T>
	inline T* Engine::Get()
	{
		for (auto& system : systems)
		{
			if (dynamic_cast<T*>(system.get())) return dynamic_cast<T*>(system.get());
		}

		return nullptr;
	}
}