#pragma once
#include "Tiny.h"

#include "GameEnums.h"


class Block : public Tiny::DebugEntity
{
public:
	Block();
	Block(BlockType type,int32_t index);
	Block(BlockType type, int32_t index, float zvalue);
	~Block();
	void Start();
	void Update(float dt);
	void OnRender();

	inline int32_t GetIndex() { return m_Index; }
	inline bool GetIndexChanged() const { return m_BlockIndexChanged; }
	inline BlockType GetType() const { return m_Type;  }

	inline void SetIndex(uint32_t value) { m_Index = value; m_BlockIndexChanged = true; }
	inline void SetIndexChanged(const bool value) { m_BlockIndexChanged = value;  }
	void SetType(BlockType type);

//protected:
//	static glm::vec3* GetValidBlockPOs();

protected:
	BlockType m_Type;
	int32_t m_Index; // TEMP 
	bool m_BlockIndexChanged = false;
	bool m_CanBeRender = false;
	Tiny::Ref<Tiny::Texture2D> m_Texture = nullptr;
};

