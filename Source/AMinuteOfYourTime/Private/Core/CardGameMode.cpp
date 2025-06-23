// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CardGameMode.h"

int32 ACardGameMode::DrawCardsToHand(
	UDeckObjectBase* Deck, TScriptInterface<IPlayerHandInterface> Hand,
	FVector2D DrawLocation, int32 Count)
{
	TArray<UCardBase*> Cards;

	int32 ReturnCount = Deck->DrawCards(Count, Cards);

	for (UCardBase* Card : Cards)
	{
		IPlayerHandInterface::Execute_AddCard(Hand.GetObject(), Card, DrawLocation);
	}

	return ReturnCount;
}
