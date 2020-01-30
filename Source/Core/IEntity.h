#pragma once

#include "EntityLump.h"
#include "Vector.h"
#include "Matrix4x4.h"
#include "Quaternion.h"
#include "Material.h"

namespace Freeking
{
	class Map;
	class BrushModel;

	typedef std::shared_ptr<class IEntity> shared_ptr_entity;

	class IEntity
	{
	public:

		IEntity() {}
		virtual ~IEntity() {}

		virtual void PreInitialize(const EntityLump::EntityDef& def) {};
		virtual void Initialize() = 0;
		virtual void Tick(double dt) = 0;
		virtual void Spawn() = 0;

		static shared_ptr_entity Make(const std::string_view& classname);

	protected:

		virtual bool SetProperty(const EntityKeyValue& keyValue) = 0;
	};

	class BaseEntity : public IEntity
	{
	public:

		virtual void Spawn() override {}
	};

	class BaseWorldEntity : public BaseEntity
	{
	public:

		BaseWorldEntity();

		virtual void PreInitialize(const EntityLump::EntityDef& def) override;
		virtual void Tick(double dt) override;

		virtual void RenderOpaque(const Matrix4x4& viewProjection, const std::shared_ptr<Material>& material) = 0;
		virtual void RenderTranslucent(const Matrix4x4& viewProjection, const std::shared_ptr<Material>& material) = 0;

		inline void SetPosition(const Vector3f& position) { _position = position; }
		inline void SetRotation(const Quaternion& rotation) { _rotation = rotation; }

		inline const Vector3f& GetPosition() const { return _position; }
		inline const Quaternion& GetRotation() const { return _rotation; }
		inline const Matrix4x4& GetTransform() const { return _transform; }

	protected:

		Vector3f _position;
		Quaternion _rotation;
		Matrix4x4 _transform;
	};

	class BrushModelEntity : public BaseWorldEntity
	{
	public:

		BrushModelEntity();

		virtual void Initialize() override;
		virtual void Tick(double dt) override;

		virtual void RenderOpaque(const Matrix4x4& viewProjection, const std::shared_ptr<Material>& material) override;
		virtual void RenderTranslucent(const Matrix4x4& viewProjection, const std::shared_ptr<Material>& material) override;

	protected:

		virtual bool SetProperty(const EntityKeyValue& keyValue) override;

	protected:

		int _modelIndex;
		std::shared_ptr<BrushModel> _model;
	};

	class WorldSpawnEntity : public BrushModelEntity
	{
	public:

		virtual void Initialize() override;
	};

	class RotatingEntity : public BrushModelEntity
	{
	public:

		RotatingEntity();

		virtual void Tick(double dt) override;

	protected:

		virtual bool SetProperty(const EntityKeyValue& keyValue) override;

	private:

		float _speed;
	};

	class DoorRotatingEntity : public BrushModelEntity
	{
	public:

		DoorRotatingEntity();

		virtual void Tick(double dt) override;

	protected:

		virtual bool SetProperty(const EntityKeyValue& keyValue) override;

	private:

		float _speed;
		float _angle;
		float _distance;
		float _time;
	};

	class DoorEntity : public BrushModelEntity
	{
	public:

		DoorEntity();

		virtual void Initialize() override;
		virtual void Tick(double dt) override;

	protected:

		virtual bool SetProperty(const EntityKeyValue& keyValue) override;

	private:

		float _speed;
		float _angle;
		float _time;
		Vector3f _initialPosition;
	};
}
