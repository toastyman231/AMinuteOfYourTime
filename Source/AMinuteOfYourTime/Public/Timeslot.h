#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ETimeslot : uint8
{
	Morning		UMETA(DisplayName = "Morning"),
	Noon		UMETA(DisplayName = "Noon"),
	Night		UMETA(DisplayName = "Night"),
	Count		UMETA(Hidden)
};