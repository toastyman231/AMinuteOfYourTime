#pragma once

#include "CoreMinimal.h"

template <typename T>
T PositiveMod(T k, T n)
{
	return ((k % n) + n) % n;
}