
#pragma once

#include "CoreMinimal.h"
#include "PickUps.h"
#include "OurHeaders/Enums.h"
#include "PickUp_Coins.generated.h"

UCLASS()
class HUE_01_01_API APickUp_Coins : public APickUps
{
	GENERATED_BODY()

	public:
		
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
			EPickUpCoinTypes Colour;
};
