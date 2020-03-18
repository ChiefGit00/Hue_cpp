#include "PlayerPawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "PlayerCtrl_level.h"
#include "PickUps.h"
#include "PickUp_Coins.h"
#include "GameFramework/Controller.h"
#include "Hue_GameInstance.h"
#include "PickUps.h"

APlayerPawn::APlayerPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	ArrowZ = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowZ"));
	ArrowY = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowY"));
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Laser = CreateDefaultSubobject<UBoxComponent>(TEXT("Laser"));
	CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("PawnMovement"));

	RootComponent = SkeletalMesh;
	SpringArm->SetupAttachment(SkeletalMesh);
	Camera->SetupAttachment(SpringArm);
	ArrowZ->SetupAttachment(SkeletalMesh);
	ArrowY->SetupAttachment(SkeletalMesh);
	Box->SetupAttachment(SkeletalMesh);
	Laser->SetupAttachment(SkeletalMesh);

	SpringArm->bDoCollisionTest = false;
	SpringArm->SetWorldRotation(FRotator(-30.0f,0.0f, 0.0f));
	ArrowZ->SetWorldRotation(FRotator(-90.0f, 0.0f, 0.0f));
	ArrowY->SetWorldLocation(FVector(0.0f, -130.0f, -10.0f));
	ArrowY->SetWorldRotation(FRotator(0.0f, 90.00f, 0.0f));
	Box->SetBoxExtent(FVector(24.0f, 24.0f, 24.0f), true);
	Box->SetWorldLocation(FVector(20.0f, 0.0f, 100.0f));
	Laser->SetWorldLocation(FVector(0.0f, 0.0f, 33.0f));
	Laser->SetWorldScale3D(FVector(0.1f, 3.0f, 0.1f));
	Laser->SetBoxExtent(FVector(32.0f, 32.0f, 32.0f));
	

}

void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	PlayerCtrl = Cast<APlayerCtrl_level>(GetController());
	PlayerCtrl->Health;

	LaserColourChange(EPickUpCoinTypes::VE_Red);
	Laser->OnComponentBeginOverlap.AddDynamic(this, &APlayerPawn::PickUpPicked);

	
	
}

void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddMovementInput(FVector(1.0f, 0.0f , Zaxis), Speed, false);

}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerPawn::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	PlayerCtrl = Cast <APlayerCtrl_level> (NewController);
}

void APlayerPawn::LaserColourChange(EPickUpCoinTypes LaserColourType)
{
	switch(LaserColourType)
	{
		case EPickUpCoinTypes::VE_None: SkeletalMesh->SetMaterial(3, LaserMat_none);
										 Laser->SetCollisionEnabled(ECollisionEnabled::NoCollision);
										 LaserColour = EPickUpCoinTypes::VE_None;
										 break;
		case EPickUpCoinTypes::VE_Yellow: SkeletalMesh->SetMaterial(3, LaserMat_yellow);
								Laser->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
								LaserColour = EPickUpCoinTypes::VE_Yellow;
								break;
		case EPickUpCoinTypes::VE_Red: SkeletalMesh->SetMaterial(3, LaserMat_red);
										Laser->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
										LaserColour = EPickUpCoinTypes::VE_Red;
										break;
		case EPickUpCoinTypes::VE_Green: SkeletalMesh->SetMaterial(3, LaserMat_green);
										  Laser->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
										  LaserColour = EPickUpCoinTypes::VE_Green;
										  break;
	}
}

void APlayerPawn::PickUpPicked(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* PrimitiveComponent, int32 OtherBodyIndex, bool bHit, const FHitResult& Hit)
{
	APickUps* PickUpPicked = Cast<APickUps>(OtherActor);
	
	if (PickUpPicked)
	{
		

		switch (PickUpPicked->PickUpType)
		{
			case EPickUpTypes::VE_Point: if(LaserColour == Cast<APickUp_Coins>(PickUpPicked)->Colour)
											{
												PlayerCtrl->UpdateScore(Cast<APickUp_Coins>(PickUpPicked)->Value);
												PickUpPicked->Picked();
											}
										 else
										 {

										 }
										 break;
			case EPickUpTypes::VE_Health: PlayerCtrl->UpdateHealth(PickUpPicked->Value);
										  PickUpPicked->Picked();
										  break;
		}
			   		 	  	
	}
	
}

