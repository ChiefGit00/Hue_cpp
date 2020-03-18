#include "PickUps.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "Components/AudioComponent.h"

APickUps::APickUps()
{
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	PickUpSound = CreateDefaultSubobject<UAudioComponent>(TEXT("PickUpSound"));

	RootComponent = Scene;
	StaticMesh->SetupAttachment(Scene);
	Box->SetupAttachment(StaticMesh);
	PickUpSound->SetupAttachment(Scene);

	StaticMesh->SetCollisionProfileName(TEXT("NoCollision"));
	StaticMesh->SetEnableGravity(false);
	StaticMesh->SetCastShadow(false);
	Box->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));
	Box->SetWorldScale3D(FVector(0.62f, 0.12f, 0.62f));
}

void APickUps::BeginPlay()
{
	Super::BeginPlay();
	
}

void APickUps::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	StaticMesh->AddRelativeRotation(FRotator(0.0f, 2.0f, 0.0f));
}

void APickUps::Picked()
{
	Box->SetCollisionProfileName(TEXT("NoCollision"));
	StaticMesh->SetVisibility(false);

	FTimerHandle handle;
	GetWorld()->GetTimerManager().SetTimer(handle, [this]() {this->Destroy(); }, 0.5f, 1);
}

void APickUps::SoundOnSuccess()
{
	PickUpSound->SetSound(SoundSuccess);
	PickUpSound->Play(0.0);
}
