#pragma once

#include "SceneEntity.h"
#include "BspFlags.h"

namespace Freeking
{
	class PrimitiveEntity;

	struct TraceResult
	{
		TraceResult() :
			hit(false),
			fraction(1.0f),
			entity(nullptr),
			allSolid(false),
			startSolid(false),
			planeNormal(0),
			planeDistance(0),
			axisU(0),
			axisV(0),
			startPosition(0),
			endPosition(0)
		{
		}

		bool allSolid;
		bool startSolid;
		float fraction;
		bool hit;
		Vector3f planeNormal;
		float planeDistance;
		Vector3f axisU;
		Vector3f axisV;
		Vector3f startPosition;
		Vector3f endPosition;
		PrimitiveEntity* entity;
	};

	class PrimitiveEntity : public SceneEntity
	{
	public:

		PrimitiveEntity();

		virtual void Tick(double dt) override;
		virtual void PostTick() override;

		virtual void PreRender(bool translucent) {};
		virtual void RenderOpaque() {};
		virtual void RenderTranslucent() {};

		inline bool IsHidden() const { return _hidden; }
		inline bool IsCollisionEnabled() const { return _collisionEnabled; }

		virtual void Trace(const Vector3f& start, const Vector3f& end, const Vector3f& mins, const Vector3f& maxs, TraceResult& trace, const BspContentFlags& brushMask);

	protected:

		Shader* _shader;
		bool _hidden;
		bool _collisionEnabled;
	};
}
