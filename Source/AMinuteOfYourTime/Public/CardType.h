// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ECardType : uint8
{
	Organ        UMETA(DisplayName = "Organ"),
	Appendage    UMETA(DisplayName = "Appendage"),
	Sense        UMETA(DisplayName = "Sense"),
	Information  UMETA(DisplayName = "Information"),
	Memory       UMETA(DisplayName = "Memory")
};
