#pragma once

#include "BaseEntity.h"

namespace Freeking::Entity::Ai
{
    class APvFuseblown2 : public BaseEntity
    {
    public:

        APvFuseblown2();

		virtual void Initialize() override;
		virtual void Tick(double dt) override;

	protected:

		virtual bool SetProperty(const EntityProperty& property) override;

    private:

    };
}
