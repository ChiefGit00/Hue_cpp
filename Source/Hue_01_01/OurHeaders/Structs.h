#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Structs.generated.h"

USTRUCT(BlueprintType)
struct FTestStruct
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Default")
		int32 test1;

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, category = "Default")
		float power;

};

USTRUCT(BlueprintType)
struct FLevelsData : public FTableRowBase
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Stage;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Level;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName MapName;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 PlayerScore;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 GoldScore;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 BronzeScore;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 SilverScore;

		FLevelsData()
		{

		}

		FLevelsData(int32 S, int32 L, FName MN, int32 PS, int32 GS, int32 BS, int32 SC)
		{
			Stage = S; Level = L; MapName = MN; PlayerScore = PS; GoldScore = GS; BronzeScore = BS; SilverScore = SC;
		}
		
};