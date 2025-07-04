// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Target.h"
#include "TargetData.h"
#include "Subsystems/EngineSubsystem.h"
#include "TargetSubsystem.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUpdateLocationSignature, ETimeslot, CurrentTime, int32, CurrentDay);

UCLASS()
class AMINUTEOFYOURTIME_API UTargetSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	UTarget* AddTarget(UTargetData* TargetData);

	UFUNCTION(BlueprintCallable)
	UTarget* GetTargetAtLocation(ELocation Location, bool& Success);

public:

	UPROPERTY(BlueprintAssignable)
	FUpdateLocationSignature UpdateLocationEvent;

private:

	UPROPERTY()
	TArray<UTarget*> Targets;
};
