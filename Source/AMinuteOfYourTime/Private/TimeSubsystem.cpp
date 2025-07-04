// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeSubsystem.h"

#include "MathExtensions.h"
#include "TargetSubsystem.h"

void UTimeSubsystem::SetCurrentTime(ETimeslot NewTime)
{
	CurrentTime = NewTime;

	if (UTargetSubsystem* TargetSubsystem = GEngine->GetEngineSubsystem<UTargetSubsystem>())
		TargetSubsystem->UpdateLocationEvent.Broadcast(CurrentTime, CurrentDay);
	DateTimeChangedEvent.Broadcast(CurrentTime, CurrentDay);
}

void UTimeSubsystem::IncreaseTime(uint8 Amount)
{
	uint8 NewTime = (uint8)CurrentTime + Amount;

	uint8 MaxTime = (uint8)ETimeslot::Count;

	uint8 DaysPassed = FMath::Floor(NewTime / 3);
	if (DaysPassed > 0) 
		IncreaseDay(DaysPassed);

	NewTime = NewTime % MaxTime;

	SetCurrentTime((ETimeslot)NewTime);
}

void UTimeSubsystem::DecreaseTime(uint8 Amount)
{
	int32 NewTime = (int8)CurrentTime - Amount;

	uint8 MaxTime = (uint8)ETimeslot::Count;

	int32 AmountPassedOutsideDay = FMath::Clamp(Amount - (int8)CurrentTime, 0, INT32_MAX);

	int32 DaysPassed = FMath::CeilToInt32((float)AmountPassedOutsideDay / 3.f);
	if (DaysPassed > 0)
		DecreaseDay(DaysPassed);

	NewTime = PositiveMod(NewTime, (int32)MaxTime);
	// TODO: Figure out how to prevent wrapping past Day 1 Morning

	SetCurrentTime((ETimeslot)NewTime);
}

void UTimeSubsystem::SetCurrentDay(int32 Day)
{
	CurrentDay = FMath::Clamp(Day, 1, UINT8_MAX);

	if (UTargetSubsystem* TargetSubsystem = GEngine->GetEngineSubsystem<UTargetSubsystem>())
		TargetSubsystem->UpdateLocationEvent.Broadcast(CurrentTime, CurrentDay);
	DateTimeChangedEvent.Broadcast(CurrentTime, CurrentDay);
}

void UTimeSubsystem::IncreaseDay(int32 Amount)
{
	SetCurrentDay(CurrentDay + Amount);
}

void UTimeSubsystem::DecreaseDay(int32 Amount)
{
	SetCurrentDay(CurrentDay - Amount);
}

ETimeslot UTimeSubsystem::GetCurrentTime() const
{
	return CurrentTime;
}

int32 UTimeSubsystem::GetCurrentDay() const
{
	return CurrentDay;
}
