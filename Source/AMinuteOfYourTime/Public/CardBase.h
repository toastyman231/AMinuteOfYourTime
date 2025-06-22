// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardType.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "CardBase.generated.h"

/**
 * 
 */
UCLASS(DisplayName="Card Data Base", Blueprintable, BlueprintType)
class AMINUTEOFYOURTIME_API UCardBase : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("CardDataBase", GetFName());
	}

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 ActionPointCost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText CardName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ECardType CardType;

	/*UPROPERTY(EditAnywhere)
	FGameplayTagContainer CardFlags;*/
};
