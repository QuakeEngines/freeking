#pragma once

#include "BaseEntity.h"

namespace Freeking::Entity::Props
{
    class AShelf : public BaseEntity
    {
    public:

        AShelf();

		virtual void Initialize() override;
		virtual void Tick(double dt) override;

	protected:

		virtual bool SetProperty(const EntityProperty& property) override;

    private:

    };
}
