#pragma once

#include "IEntity.h"

namespace Freeking::Entity::Misc
{
    class ATeleporterDest : public IEntity
    {
    public:

        ATeleporterDest();

		virtual void Initialize() override;
		virtual void Tick(double dt) override;

	protected:

		virtual bool SetProperty(const EntityKeyValue& keyValue) override;

    private:

    };
}