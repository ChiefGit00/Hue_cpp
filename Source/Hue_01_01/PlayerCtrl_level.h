#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerCtrl_level.generated.h"


UCLASS()
class HUE_01_01_API APlayerCtrl_level : public APlayerController
{
	GENERATED_BODY()

	protected:
		virtual void BeginPlay() override;
		virtual void OnPossess(APawn* aPawn) override;


	public:

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
			int32 Score;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
			float Health;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
			float HealthPerc;

		UFUNCTION(BlueprintCallable)
			void UpdateHealth(float HealthToAdd);

		UFUNCTION(BlueprintCallable)
			void UpdateScore(int32 ScoreToAdd);

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
			TSubclassOf<class UUserWidget> wHUD;
		
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
			TSubclassOf<class UUserWidget> wFinishLevel;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
			TSubclassOf<class UUserWidget> wFinishLife;
		
		class UUserWidget* HUD;

		class UUserWidget* UI_FinishLevel;

		class UUserWidget* UI_FinishLife;

		class UHue_GameInstance* GameInst;

		UFUNCTION(BlueprintCallable)
		void LevelFinish();

		UFUNCTION(BlueprintCallable)
		void LifeFinish();


	
};
