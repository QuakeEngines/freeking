#pragma once

#include "IEntity.h"

namespace Freeking::Entity::Misc
{
    class ASkidrowRadioRepeater : public IEntity
    {
    public:

        ASkidrowRadioRepeater();

		virtual void Initialize() override;
		virtual void Tick(double dt) override;

	protected:

		virtual bool SetProperty(const EntityKeyValue& keyValue) override;

    private:

    };
}
