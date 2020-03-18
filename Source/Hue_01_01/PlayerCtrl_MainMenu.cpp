// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCtrl_MainMenu.h"
#include "Blueprint/UserWidget.h"

void APlayerCtrl_MainMenu::BeginPlay()
{
	Super::BeginPlay();

	MainMenu = CreateWidget<UUserWidget>(this, wMainMenu);
	if (MainMenu)
	{
		MainMenu->AddToViewport();
	}
	bShowMouseCursor = true;

}