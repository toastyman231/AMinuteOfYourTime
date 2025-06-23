// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DeckDataBase.h"
#include "UObject/NoExportTypes.h"
#include "DeckObjectBase.generated.h"

class UDeckObjectBase;

UDELEGATE(BlueprintCallable)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDeckChangedSignature, UDeckObjectBase*, Deck);

UCLASS(BlueprintType, DisplayName="Deck Object")
class AMINUTEOFYOURTIME_API UDeckObjectBase : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly)
	FName DeckName = "Empty Deck";

public:

	void Initialize(UDeckDataBase* DeckData, FName Name);

	// Returns actual number of cards drawn, in the case that the deck has less than Count
	int DrawCards(int Count, TArray<UCardBase*>& OutCardList);

	void AddCard(UCardBase* Card);

	void AddCards(const TArray<UCardBase*>& CardList);

	void Shuffle();

private:

	TQueue<UCardBase*> Cards;
};
