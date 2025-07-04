// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Location.h"
#include "TargetScheduleRow.generated.h"

USTRUCT(BlueprintType)
struct FTargetScheduleRow : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ELocation Timeslot1Location;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ELocation Timeslot2Location;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ELocation Timeslot3Location;
};
