#pragma once

#include "PrimitiveEntity.h"

namespace Freeking
{
	class BrushModel;

	class BrushModelEntity : public PrimitiveEntity
	{
	public:

		BrushModelEntity();

		virtual void Initialize() override;
		virtual void Tick(double dt) override;

		virtual void RenderOpaque(const Matrix4x4& viewProjection, const std::shared_ptr<Shader>& shader) override;
		virtual void RenderTranslucent(const Matrix4x4& viewProjection, const std::shared_ptr<Shader>& shader) override;

	protected:

		virtual bool SetProperty(const EntityProperty& property) override;

		virtual std::shared_ptr<BrushModel> GetModel();

		virtual bool HasSurf2Alpha() const { return false; }

	protected:

		int _modelIndex;
		std::shared_ptr<BrushModel> _model;
	};
}
