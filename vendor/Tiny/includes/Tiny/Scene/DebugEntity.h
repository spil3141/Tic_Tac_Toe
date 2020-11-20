#pragma once

#include "glm/glm.hpp"

namespace Tiny {

	struct DebugEntity
	{
		DebugEntity(std::string name = "DefaultEntity")
			: m_Name(name)
		{
		};
		virtual ~DebugEntity() = default;

		virtual void Start() = 0;
		virtual void Update(float dt) = 0;

		glm::vec3 GetPosition() const { return m_Position; };
		float GetRotation() const { return m_Rotation; }
		glm::vec3 GetScale() const { return m_Scale; };
		
		void SetPosition(glm::vec3& new_pos ) { m_Position = new_pos; };
		float GetRotation(float& new_rotation) { m_Rotation = new_rotation; }
		void GetScale(glm::vec3& new_scale) { m_Scale = new_scale; };



		
	protected:
		//Transform
		glm::vec3 m_Position = glm::vec3(0.0f, 0.0f, 0.0f);
		float m_Rotation = 0.0f;
		glm::vec3 m_Scale = glm::vec3(1.0f, 1.0f, 1.0f);

		std::string m_Name;
	};
}


