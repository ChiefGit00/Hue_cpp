// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "OurHeaders/Structs.h"
#include "Hue_SaveGame.generated.h"

UCLASS()
class HUE_01_01_API UHue_SaveGame : public USaveGame
{
	GENERATED_BODY()

	public:
		
		UPROPERTY(VisibleAnywhere, Category ="Default")
		int32 PlayerName;

		UPROPERTY(VisibleAnywhere, Category = "Default")
		TArray<FLevelsData> LevelsData;
					
};
