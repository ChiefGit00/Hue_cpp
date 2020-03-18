#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "OurHeaders/Enums.h"
#include "OurHeaders/Structs.h"
#include "PlayerPawn.generated.h"

UENUM(BlueprintType)
enum class EHUDTypes : uint8
{
	VE_X_Yellow UMETA(DisplayName = "X_Yellow"),
	VE_XY_YellowRed UMETA(DisplayName = "XY_YellowRed"),
	VE_XY_YellowRedGreen UMETA(DisplayName = "XY_YellowRedGreen")
};

UCLASS()
class HUE_01_01_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	APlayerPawn();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PossessedBy(AController* NewController) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SkeletalMesh")
		class USkeletalMeshComponent* SkeletalMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SpringArm")
		class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UArrowComponent* ArrowZ;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UArrowComponent* ArrowY;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* Box;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* Laser;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
		float Zaxis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
		float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
		float HealthPerc;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
		class APlayerCtrl_level* PlayerCtrl;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Default")
		EPickUpCoinTypes LaserColour;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Default")
		EHUDTypes HUDType;

	UPROPERTY(EditAnywhere, BlueprintReadWRite, Category = "LaserMaterial")
		class UMaterial* LaserMat_none;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "LaserMaterial")
		class UMaterial* LaserMat_yellow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "LaserMaterial")
		class UMaterial* LaserMat_red;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "LaserMaterial")
		class UMaterial* LaserMat_green;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Default")
		FTestStruct structT;

	

	UFUNCTION(BlueprintCallable)
		void LaserColourChange(EPickUpCoinTypes LaserColourType);

	UFUNCTION()
	void PickUpPicked(UPrimitiveComponent* OverlappedComponentt, AActor* OtherActor, UPrimitiveComponent* PrimitiveComponent, int32 OtherBodyIndex, bool bHit, const FHitResult& Hit);

	
	
	
};
