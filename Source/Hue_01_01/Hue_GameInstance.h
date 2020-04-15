#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "OurHeaders/Structs.h"
#include "Hue_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class HUE_01_01_API UHue_GameInstance : public UGameInstance
{
	GENERATED_BODY()

	public:

		UHue_GameInstance();

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UDataTable* LevelsDataTable;

		UFUNCTION(BlueprintCallable)
			void CreateSaveGameObject();

		UFUNCTION(BlueprintCallable)
			void SaveLevelScore(FName LevelName, int32 NewScore);

		UFUNCTION(BlueprintCallable)
			FLevelsData GetLevelData(FName LevelName);

		UFUNCTION(BlueprintCallable)
			void ResetSave();

	
};
