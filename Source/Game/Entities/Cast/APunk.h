#pragma once

#include "IEntity.h"

namespace Freeking::Entity::Cast
{
    class APunk : public BaseEntity
    {
    public:

        APunk();

		virtual void Initialize() override;
		virtual void Tick(double dt) override;

	protected:

		virtual bool SetProperty(const EntityKeyValue& keyValue) override;

    private:

    };
}
