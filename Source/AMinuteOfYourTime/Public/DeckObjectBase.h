// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DeckDataBase.h"
#include "UObject/NoExportTypes.h"
#include "DeckObjectBase.generated.h"

UDELEGATE(BlueprintCallable)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDeckCountChangeSignature, int32, NewCount);

UCLASS(BlueprintType, DisplayName="Deck Object")
class AMINUTEOFYOURTIME_API UDeckObjectBase : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly)
	FName DeckName = "Empty Deck";

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FDeckCountChangeSignature DeckCountChangeEvent;

public:

	UFUNCTION(BlueprintCallable)
	void Initialize(UDeckDataBase* DeckData, FName Name);

	UFUNCTION(BlueprintCallable)
	int32 GetCardCount() const { return CardCount; }

	// Returns actual number of cards drawn, in the case that the deck has less than Count
	int DrawCards(int Count, TArray<UCardBase*>& OutCardList, bool BroadcastChange = false);

	void AddCard(UCardBase* Card);

	void AddCards(const TArray<UCardBase*>& CardList);

	void Shuffle();

private:

	TQueue<UCardBase*> Cards;

	int32 CardCount = 0;
};
