#include "BaseTrack.h"
#include "Components/ChildActorComponent.h"

ABaseTrack::ABaseTrack()
{
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	ChildActor = CreateDefaultSubobject<UChildActorComponent>(TEXT("ChildActor"));
	RootComponent = StaticMesh;
	ChildActor->SetupAttachment(StaticMesh);

}

void ABaseTrack::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseTrack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

