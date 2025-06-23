// Fill out your copyright notice in the Description page of Project Settings.


#include "CardPlayerState.h"

void ACardPlayerState::AddCard_Implementation(UCardBase* Card, FVector2D DrawLocation)
{
	if (PlayerHand.Num() >= MaxHandSize) return;

	PlayerHand.Add(Card);

	HandChangedEvent.Broadcast(PlayerHand, DrawLocation);
}

void ACardPlayerState::RemoveCard_Implementation(UCardBase* Card)
{
	if (!PlayerHand.Contains(Card)) return;

	PlayerHand.Remove(Card);

	HandChangedEvent.Broadcast(PlayerHand, FVector2D(999, 999));
}
