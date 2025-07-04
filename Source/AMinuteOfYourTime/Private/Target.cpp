// Fill out your copyright notice in the Description page of Project Settings.


#include "Target.h"

#include <string>

#include "TargetData.h"
#include "TargetScheduleRow.h"
#include "TargetSubsystem.h"

void UTarget::Initialize(const UTargetData* TargetData)
{
	if (!TargetData)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid data pointer passed to Initialize Target!"));
		return;
	}

	TargetName = TargetData->TargetName;
	Schedule = TargetData->TargetSchedule;

	FTargetScheduleRow* DefaultSchedule = 
		TargetData->TargetSchedule->FindRow<FTargetScheduleRow>(FName("Default"), "Initial Load");

	if (DefaultSchedule)
	{
		CurrentLocation = DefaultSchedule->Timeslot1Location;
	}

	if (UTargetSubsystem* TargetSubsystem = GEngine->GetEngineSubsystem<UTargetSubsystem>())
		TargetSubsystem->UpdateLocationEvent.AddDynamic(this, &UTarget::OnDateTimeChanged);
}

void UTarget::SetLocation(ELocation Location)
{
	CurrentLocation = Location;
}

ELocation UTarget::GetLocation() const
{
	return CurrentLocation;
}

FName UTarget::GetTargetName() const
{
	return TargetName;
}

void UTarget::OnDateTimeChanged(ETimeslot CurrentTime, int32 CurrentDay)
{
	FString DayAsString = FString::FromInt(CurrentDay);

	FTargetScheduleRow* ScheduleRow =
		Schedule->FindRow<FTargetScheduleRow>(FName(DayAsString), "DateTime Changed");

	if (ScheduleRow)
	{
		switch (CurrentTime)
		{
		case ETimeslot::Morning:
			CurrentLocation = ScheduleRow->Timeslot1Location;
			break;
		case ETimeslot::Noon:
			CurrentLocation = ScheduleRow->Timeslot2Location;
			break;
		case ETimeslot::Night:
			CurrentLocation = ScheduleRow->Timeslot3Location;
			break;
		case ETimeslot::Count:
			break;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Target %s location: %s"), *TargetName.ToString(), *UEnum::GetDisplayValueAsText(CurrentLocation).ToString());
}
