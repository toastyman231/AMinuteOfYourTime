#pragma once

#include "CoreMinimal.h"
#include "Timeslot.generated.h"

UENUM(BlueprintType)
enum class ETimeslot : uint8
{
	Morning		UMETA(DisplayName = "Morning"),
	Noon		UMETA(DisplayName = "Noon"),
	Night		UMETA(DisplayName = "Night"),
	Count		UMETA(Hidden)
};

USTRUCT(BlueprintType)
struct FDateTimePair
{
	GENERATED_BODY()

	FDateTimePair()
	{
		Timeslot = ETimeslot::Morning;
		Day = 1;
	}

	FDateTimePair(ETimeslot InTimeslot, int32 InDay)
	{
		Timeslot = InTimeslot;
		Day = InDay;
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameData")
	ETimeslot Timeslot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameData")
	int32 Day;

	bool operator==(const FDateTimePair& other) const
	{
		return other.Timeslot == Timeslot && other.Day == Day;
	}
};