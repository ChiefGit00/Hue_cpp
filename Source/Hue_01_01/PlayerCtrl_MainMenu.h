// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerCtrl_MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class HUE_01_01_API APlayerCtrl_MainMenu : public APlayerController
{
	GENERATED_BODY()

		void BeginPlay() override;

	public:

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
		TSubclassOf<class UUserWidget> wMainMenu;

		UUserWidget* MainMenu;
	
	
};
