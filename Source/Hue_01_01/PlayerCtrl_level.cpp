#include "PlayerCtrl_level.h"
#include "Hue_GameInstance.h"
#include  "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

void APlayerCtrl_level::BeginPlay()
{
	Super::BeginPlay();
	Score = 0;
	Health = 100;
	HealthPerc = 100;
}

void APlayerCtrl_level::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	HUD = CreateWidget<UUserWidget>(this, wHUD);
	if (HUD)
	{
		HUD->AddToViewport();
	}
	bShowMouseCursor = true;
}

void APlayerCtrl_level::UpdateHealth(float HealthToAdd)
{
	Health += HealthToAdd;
	HealthPerc = Health/100;
	if (Health <= 0)
		LifeFinish();
}

void APlayerCtrl_level::UpdateScore(int32 ScoreToAdd)
{
	Score += ScoreToAdd;
}

void APlayerCtrl_level::LevelFinish()
{
	SetPause(true);
	HUD->RemoveFromParent();
	GameInst = Cast<UHue_GameInstance>(GetGameInstance());
	if (GameInst)
	{
		GameInst->SaveLevelScore(FName(GetWorld()->GetName()), Score);
		UI_FinishLevel = CreateWidget<UUserWidget>(this, wFinishLevel);
		if (UI_FinishLevel)
		{
			UI_FinishLevel->AddToViewport();
		}
		bShowMouseCursor = true;
	}
}

void APlayerCtrl_level::LifeFinish()
{
	SetPause(true);
	HUD->RemoveFromParent();


	
	UI_FinishLife = CreateWidget<UUserWidget>(this, wFinishLife);
	if (UI_FinishLife)
	{
		UI_FinishLife->AddToViewport();
	}
	
}

