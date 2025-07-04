// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TargetData.generated.h"

/**
 * 
 */
UCLASS(DisplayName = "Target Data", Blueprintable, BlueprintType)
class AMINUTEOFYOURTIME_API UTargetData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("TargetData", GetFName());
	}

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName TargetName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UDataTable* TargetSchedule;
};
