#pragma once

#include "ContextWorld.h"


class Level1 : public ContextWorld
{

public:

	Level1();

private:

	virtual void InitializeMap() override;

	virtual void InitializeCharacters() override;
};