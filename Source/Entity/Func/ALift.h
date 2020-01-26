#pragma once

#include "IEntity.h"

namespace Freeking::Entity::Func
{
    class ALift : public IEntity
    {
    public:

        ALift();

		virtual void Initialize() override;
		virtual void Tick(double dt) override;

	protected:

		virtual bool SetProperty(const EntityKeyValue& keyValue) override;

    private:

    };
}