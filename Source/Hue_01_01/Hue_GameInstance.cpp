// Fill out your copyright notice in the Description page of Project Settings.


#include "Hue_GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/DataTable.h"
#include "Hue_SaveGame.h"

UHue_GameInstance::UHue_GameInstance()
{
	static ConstructorHelpers::FObjectFinder<UDataTable>LevelsDataTableObj(TEXT("DataTable'/Game/Data/DT_LevelsData.DT_LevelsData'"));

	if (LevelsDataTableObj.Succeeded())
	{
		LevelsDataTable = LevelsDataTableObj.Object;
	}
}


void UHue_GameInstance::CreateSaveGameObject()
{
	if (!UGameplayStatics::DoesSaveGameExist("Slot02", 0))
	{
			UHue_SaveGame* SaveGameObj = Cast<UHue_SaveGame>(UGameplayStatics::CreateSaveGameObject(UHue_SaveGame::StaticClass()));
			SaveGameObj->PlayerName = 3.0f;
			SaveGameObj->LevelsData.Empty();

			for (auto it : LevelsDataTable->GetRowMap())
			{
				FString ContextString;
				SaveGameObj->LevelsData.Add(*((FLevelsData*)it.Value));
			}

			if(UGameplayStatics::SaveGameToSlot(SaveGameObj, "Slot02", 0))
				GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("Saved"));

	}
	else
	{

		//UHue_SaveGame* SaveGameObj = Cast<UHue_SaveGame>(UGameplayStatics::CreateSaveGameObject(UHue_SaveGame::StaticClass()));
		//SaveGameObj = Cast<UHue_SaveGame>(UGameplayStatics::LoadGameFromSlot("Slot02", 0));

	}
}

void UHue_GameInstance::SaveLevelScore(FName LevelName, int32 NewScore)
{
	if (UGameplayStatics::DoesSaveGameExist("Slot02", 0))
	{
		UHue_SaveGame* LoadGameObj = Cast<UHue_SaveGame>(UGameplayStatics::CreateSaveGameObject(UHue_SaveGame::StaticClass()));
		LoadGameObj = Cast<UHue_SaveGame>(UGameplayStatics::LoadGameFromSlot("Slot02", 0));
		

		for (auto& LevelData : LoadGameObj->LevelsData)
		{
			if (LevelData.MapName == LevelName)
			{
				if (LevelData.PlayerScore < NewScore)
				{
					LevelData.PlayerScore = NewScore;
				}
				break;
			}
		}
		UGameplayStatics::SaveGameToSlot(LoadGameObj, "Slot02", 0);

	}

}

FLevelsData UHue_GameInstance::GetLevelData(FName LevelName)
{
	FLevelsData LevelInfo;
	for (auto& LevelData : (Cast<UHue_SaveGame>(UGameplayStatics::LoadGameFromSlot("Slot02", 0)))->LevelsData)
	{
		if (LevelData.MapName == LevelName)
		{
			LevelInfo = LevelData;
			break;
		}
	}
	return LevelInfo;
}

void UHue_GameInstance::ResetSave()
{
	if (UGameplayStatics::DoesSaveGameExist("Slot02", 0))
	{
		UHue_SaveGame* LoadGameObj = Cast<UHue_SaveGame>(UGameplayStatics::CreateSaveGameObject(UHue_SaveGame::StaticClass()));
		LoadGameObj = Cast<UHue_SaveGame>(UGameplayStatics::LoadGameFromSlot("Slot02", 0));
		LoadGameObj->PlayerName = 1.0f;
		LoadGameObj->LevelsData.Empty();

		for (auto it : LevelsDataTable->GetRowMap())
		{
			FString ContextString;
			LoadGameObj->LevelsData.Add(*((FLevelsData*)it.Value));
		}

		UGameplayStatics::SaveGameToSlot(LoadGameObj, "Slot02", 0);
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, TEXT(" Reset " ));

	}
}

