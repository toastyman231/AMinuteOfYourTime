// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Templates/SharedPointer.h"
#include "DeckDataBase.generated.h"

class UCardBase;
class UDeckDataBase;

UDELEGATE(BlueprintCallable)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDeckCountChangeSignature, UDeckDataBase*, DeckData);

UCLASS(DisplayName="Deck Data Base", Blueprintable, BlueprintType)
class AMINUTEOFYOURTIME_API UDeckDataBase : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("DeckDataBase", GetFName());
	}

public:

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FDeckCountChangeSignature DeckCountChangeEvent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UCardBase*> CardList;
};
