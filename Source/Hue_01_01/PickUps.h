#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUps.generated.h"

UENUM(BlueprintType)
enum class EPickUpTypes : uint8
{
	VE_Point UMETA(DisplayName = "Point"),
	VE_Health UMETA(DisplayName = "Health")
};

UCLASS()
class HUE_01_01_API APickUps : public AActor
{
	GENERATED_BODY()
	
public:	
	APickUps();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* Box;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UAudioComponent* PickUpSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Default")
		class USoundBase* SoundSuccess;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
		int32 Value;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
		EPickUpTypes PickUpType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Default")
		class USoundBase* InvalidSound;

	UFUNCTION(BlueprintCallable)
		void Picked();
	
	UFUNCTION(BlueprintCallable)
		void SoundOnSuccess();

	
		
};
