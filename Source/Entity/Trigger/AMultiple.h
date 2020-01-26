#pragma once

#include "IEntity.h"

namespace Freeking::Entity::Trigger
{
    class AMultiple : public IEntity
    {
    public:

        AMultiple();

		virtual void Initialize() override;
		virtual void Tick(double dt) override;

	protected:

		virtual bool SetProperty(const EntityKeyValue& keyValue) override;

    private:

    };
}