
#pragma once
#include "CoreMinimal.h"

UENUM(BlueprintType)
	enum  class EPickUpCoinTypes : uint8
	{
		VE_None UMETA(DisplayName = "None"),
		VE_Yellow UMETA(DisplayName = "Yellow"),
		VE_Red UMETA(DisplayName = "Red"),
		VE_Green UMETA(DisplayName = "Green")
	};
