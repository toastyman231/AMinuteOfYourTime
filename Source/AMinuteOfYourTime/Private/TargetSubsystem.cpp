// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetSubsystem.h"

UTarget* UTargetSubsystem::AddTarget(UTargetData* TargetData)
{
	if (UTarget* Target = NewObject<UTarget>(UTarget::StaticClass()))
	{
		Target->Initialize(TargetData);
		Targets.Add(Target);
		return Target;
	}
	else return nullptr;
}

UTarget* UTargetSubsystem::GetTargetAtLocation(ELocation Location, bool& Success)
{
	for (auto target : Targets)
	{
		if (target->GetLocation() == Location) 
		{
			Success = true;
			return target;
		}
	}

	Success = false;
	return nullptr;
}
