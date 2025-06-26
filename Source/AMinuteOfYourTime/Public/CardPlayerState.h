// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardBase.h"
#include "CardInterface.h"
#include "GameFramework/PlayerState.h"
#include "CardPlayerState.generated.h"

UDELEGATE(BlueprintCallable)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FHandChangedSignature, const TArray<UCardBase*>&, Hand, FVector2D, DrawLocation, int32, HandDelta);

UDELEGATE(BlueprintCallable)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActionPointsChangedSignature, int32, ActionPoints);

UCLASS()
class AMINUTEOFYOURTIME_API ACardPlayerState : public APlayerState, public IPlayerHandInterface
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite)
	TArray<UCardBase*> PlayerHand;

	UPROPERTY(BlueprintReadWrite)
	int32 MaxHandSize = 999;

	UPROPERTY(BlueprintReadWrite)
	int32 ActionPoints = 3;

	UPROPERTY(BlueprintReadWrite)
	int32 MaxActionPoints = 3;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FHandChangedSignature HandChangedEvent;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FActionPointsChangedSignature ActionPointsChangedEvent;

public:

	UFUNCTION(BlueprintCallable)
	void AddActionPoints(int32 Amount);

	virtual void AddCard_Implementation(UCardBase* Card, FVector2D DrawLocation) override;
	virtual void RemoveCard_Implementation(UCardBase* Card) override;
	virtual void AddCards_Implementation(const TArray<UCardBase*>& Cards, FVector2D DrawLocation) override;
};
