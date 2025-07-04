#pragma once

UENUM(BlueprintType)
enum class ELocation : uint8
{
	Limbo		UMETA(DisplayName = "Limbo"),
	Wrath		UMETA(DisplayName = "Wrath"),
	Gluttony	UMETA(DisplayName = "Gluttony"),
	Fraud		UMETA(DisplayName = "Fraud"),
	Violence	UMETA(DisplayName = "Violence"),
	Treachery	UMETA(DisplayName = "Treachery"),
};