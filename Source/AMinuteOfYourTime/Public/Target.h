// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Location.h"
#include "Timeslot.h"
#include "UObject/NoExportTypes.h"
#include "Target.generated.h"

class UTargetData;

UCLASS()
class AMINUTEOFYOURTIME_API UTarget : public UObject
{
	GENERATED_BODY()

public:

	void Initialize(const UTargetData* TargetData);

	void SetLocation(ELocation Location);

	UFUNCTION(BlueprintCallable)
	ELocation GetLocation() const;
	UFUNCTION(BlueprintCallable)
	FName GetTargetName() const;

private:

	UFUNCTION()
	void OnDateTimeChanged(ETimeslot CurrentTime, int32 CurrentDay);

private:

	FName TargetName;
	ELocation CurrentLocation;

	UPROPERTY()
	UDataTable* Schedule;
};
