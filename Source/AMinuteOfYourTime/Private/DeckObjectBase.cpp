// Fill out your copyright notice in the Description page of Project Settings.


#include "DeckObjectBase.h"

#include "CardBase.h"

void UDeckObjectBase::Initialize(UDeckDataBase* DeckData, FName Name)
{
	DeckName = Name;

	for (UCardBase* card : DeckData->CardList)
	{
		Cards.Enqueue(std::move(card));
	}

	CardCount = DeckData->CardList.Num();

	DeckCountChangeEvent.Broadcast(DeckData->CardList.Num());
}

int UDeckObjectBase::DrawCards(int Count, TArray<UCardBase*>& OutCardList, bool BroadcastChange)
{
	int ReturnCount = 0;

	for (int i = 0; i < Count; ++i)
	{
		if (Cards.IsEmpty()) break;

		UCardBase* Card = nullptr;
		Cards.Peek(Card);
		Cards.Pop();
		OutCardList.Add(std::move(Card));
		ReturnCount++;

		CardCount--;

		if (BroadcastChange) DeckCountChangeEvent.Broadcast(1);
	}

	return ReturnCount;
}

void UDeckObjectBase::AddCard(UCardBase* Card)
{
	Cards.Enqueue(std::move(Card));

	CardCount++;
	DeckCountChangeEvent.Broadcast(1);
}

void UDeckObjectBase::AddCards(const TArray<UCardBase*>& CardList)
{
	for (UCardBase* card : CardList)
	{
		AddCard(card);
	}
}

void UDeckObjectBase::Shuffle()
{
	TArray<UCardBase*> CardList;

	while (!Cards.IsEmpty())
	{
		UCardBase* Card = nullptr;
		Cards.Dequeue(Card);
		CardList.Add(std::move(Card));
	}

	const int32 NumShuffles = CardList.Num() - 1;
	for (int32 i = 0; i < NumShuffles; ++i)
	{
		int32 SwapIndex = FMath::RandRange(i, NumShuffles);
		CardList.Swap(i, SwapIndex);
	}

	for (int i = 0; i < CardList.Num(); ++i)
	{
		Cards.Enqueue(std::move(CardList[i]));
	}
}
